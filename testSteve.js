console.log('Node Version: ' + process.version);
console.log('Start:'+__filename);
var successFunction = function() {
   console.log('Event "success" received in JavaScript');
};
var nodeSteve = require('./lib/node-steve');

var _sNode = new nodeSteve; 

_sNode.on('success', successFunction);
console.log('_sNode "success" listeners: '+_sNode.listeners('success').length);

_sNode.Start(3);
