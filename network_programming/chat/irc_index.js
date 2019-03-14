'use strict';

var ip = require('ip'); // https://github.com/indutny/node-ip
var os = require('os');
var colors = require('colors');
var ifaces = os.networkInterfaces();
var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var port = process.env.PORT || 2324;

colors.setTheme({
  custom: ['red', 'underline'],
  input: 'grey',
  verbose: 'cyan',
  info: 'green',
  data: 'grey',
  help: 'cyan',
  warn: 'yellow',
  debug: 'blue',
  error: 'red'
});

console.log('\nOMG Rainbows!'.rainbow); // rainbow
console.log('COMPUTER ENGINEERING'.trap); // Drops the bass
console.log('### Network Programming Homework'.info);
console.log('### Author: oguzhan.ince@ogr.sakarya.edu.tr\n'.info);
// console.log("this is an error text color".error);

// Let’s refactor our route handler to use sendFile instead:
app.get('/', function(req, res){
  res.sendFile(__dirname + '/index.html');
});

// note, io(<port>) will create a http server for you
io.on('connection', function(socket){
  socket.broadcast.emit('broadcast: AG PROGRAMLAMA DERSI ODEVI');
  socket.broadcast.emit('user connected');
  io.emit('this', { will: 'be received by everyone'});
  socket.on('private message', function (from, msg) {
    console.log('I received a private message by ', from, ' saying ', msg);
  });
  socket.on('chat message', function(msg){
    io.emit('chat message', msg);
  });
  console.log('user connected :) '.warn);
  socket.on('disconnect', function(){
    console.log('user disconnected :( \n'.error);
  });

});

http.listen(port, function(){
  console.log(' ');
  console.log('you can change that from index.js');
  console.log('listening on *:' + port + ' \n');
});

console.log('--established status--'.warn);

Object.keys(ifaces).forEach(function (ifname) {
  var alias = 0;

  ifaces[ifname].forEach(function (iface) {
    if ('IPv4' !== iface.family || iface.internal !== false) {
      // skip over internal (i.e. 127.0.0.1) and non-ipv4 addresses
      return;
    }
    if (alias >= 1) {
      // this single interface has multiple ipv4 addresses
      // console.log(ifname + ':' + alias, iface.address);
      console.log('### ' + 'http://localhost:' + port + '/');
      console.log('### ' + 'http://' + iface.address + ':' + port + '/');
    }else {
      // this interface has only one ipv4 adress
      // console.log(ifname, iface.address);
      console.log('### ' + 'http://localhost:' + port + '/');
      console.log('### ' + 'http://' + iface.address + ':' + port + '/');
    }
    ++alias;
  });
});
