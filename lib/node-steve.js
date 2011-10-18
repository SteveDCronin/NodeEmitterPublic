console.log('Start:'+__filename);
var EventEmitter = require('events').EventEmitter;
var NodeSteve = require('../build/default/node-steve').SteveNode;

NodeSteve.prototype.__proto__ = EventEmitter.prototype;

module.exports = NodeSteve;
