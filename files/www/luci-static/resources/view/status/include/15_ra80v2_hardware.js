'use strict';
'require baseclass';
'require rpc';

/* Hardware status view for Xiaomi AX3000 (RA80v2) with Qualcomm NSS offload.
 * The rpcd plugin lives at /usr/libexec/rpcd/luci.ra80v2.
 */
var callHardware = rpc.declare({
	object: 'luci.ra80v2',
	method: 'status'
});

var RADIO_NODE = {
	'c000000.wifi': '2.4 GHz',
	'b00a040.wifi': '5 GHz'
};

function celsius(mdeg) {
	var v = parseInt(mdeg, 10);
	return isNaN(v) ? '-' : (v / 1000).toFixed(1) + ' °C';
}

function rate(deltaBytes, deltaMs) {
	if (deltaBytes == null || deltaBytes < 0 || !(deltaMs > 0))
		return null;

	return deltaBytes * 8000 / deltaMs;
}

function bits(v) {
	if (v == null)
		return '-';
	if (v >= 1e9)
		return (v / 1e9).toFixed(2) + ' Gbit/s';
	if (v >= 1e6)
		return (v / 1e6).toFixed(1) + ' Mbit/s';
	if (v >= 1e3)
		return (v / 1e3).toFixed(1) + ' kbit/s';

	return Math.round(v) + ' bit/s';
}

function parseStat(line) {
	if (typeof line != 'string')
		return null;

	var f = line.replace(/^cpu\s+/, '').trim().split(/\s+/).map(function(n) {
		return parseInt(n, 10);
	});

	for (var i = 0; i < f.length; i++)
		if (isNaN(f[i]))
			return null;

	return f.length >= 7 ? f : null;
}

function busyPercent(prev, cur) {
	if (!prev || !cur)
		return null;

	var d = [];
	for (var i = 0; i < 7; i++)
		d.push((cur[i] || 0) - (prev[i] || 0));

	var busy = d[0] + d[1] + d[2] + d[5] + d[6],
	    total = busy + d[3] + d[4];

	if (total <= 0)
		return null;

	return Math.round(busy * 100 / total);
}

return baseclass.extend({
	title: _('Hardware'),

	load: function() {
		return L.resolveDefault(callHardware(), {});
	},

	render: function(data) {
		if (!data || !data.cpu)
			return null;

		var cur = parseStat(data.stat),
		    load = busyPercent(this.prevStat, cur);

		this.prevStat = cur;

		var cpu = data.cpu,
		    desc = cpu.model || '?';

		if (cpu.cores)
			desc += ' × ' + cpu.cores;

		var qual = [];
		if (cpu.freq)
			qual.push(Math.round(cpu.freq / 1000) + ' MHz');
		if (cpu.governor)
			qual.push(cpu.governor);
		if (qual.length)
			desc += ' (' + qual.join(', ') + ')';

		var rows = [ _('Processor'), desc ];

		rows.push(_('CPU load'),
			load != null ? load + ' %' : _('Collecting data...'));

		var temp = data.temp || {};

		if (temp.cpu != null)
			rows.push(_('CPU temperature'), celsius(temp.cpu));

		(temp.wifi || []).forEach(function(radio) {
			var name = RADIO_NODE[radio.node] || radio.phy || '?';
			rows.push(_('Wi-Fi temperature') + ' (' + name + ')',
				celsius(radio.temp));
		});

		if (data.nss)
			rows.push(_('NSS utilisation (average / peak)'),
				data.nss.avg + ' % / ' + data.nss.max + ' %');

		if (data.ecm != null)
			rows.push(_('Accelerated connections'), String(data.ecm));

		var now = Date.now(),
		    prevNet = this.prevNet,
		    nowNet = {};

		(data.net || []).forEach(function(iface) {
			nowNet[iface.dev] = iface;
		});

		this.prevNet = { t: now, dev: nowNet };

		(data.net || []).forEach(function(iface) {
			var was = prevNet ? prevNet.dev[iface.dev] : null,
			    ms = prevNet ? now - prevNet.t : 0,
			    rx = was ? rate(iface.rx - was.rx, ms) : null,
			    tx = was ? rate(iface.tx - was.tx, ms) : null;

			var tag = iface.iface ? iface.iface + ' / ' + iface.dev : iface.dev;

			rows.push(_('Port throughput') + ' (' + tag + ')',
				(rx == null && tx == null)
					? _('Collecting data...')
					: '↓ ' + bits(rx) + ' ↑ ' + bits(tx));
		});

		var table = E('table', { 'class': 'table' });

		for (var i = 0; i < rows.length; i += 2)
			table.appendChild(E('tr', { 'class': 'tr' }, [
				E('td', { 'class': 'td left', 'width': '33%' }, [ rows[i] ]),
				E('td', { 'class': 'td left' }, [ rows[i + 1] ])
			]));

		return table;
	}
});
