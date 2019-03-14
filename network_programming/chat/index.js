'use strict';

// Setup basic express
var express = require('express');
var ip = require('ip'); // https://github.com/indutny/node-ip
var os = require('os');
var colors = require('colors');
var ifaces = os.networkInterfaces();
var app = express();
var path = require('path');
var server = require('http').createServer(app);
var io = require('../..')(server);
var port = process.env.PORT || 3000;

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

console.log('OMG Rainbows!'.rainbow); // rainbow
console.log('COMPUTER ENGINEERING'.trap); // Drops the bass
console.log('### Network Programming Homework'.info);
console.log('### Author: oguzhan.ince@ogr.sakarya.edu.tr\n'.info);   

server.listen(port, () => {
  console.log(' ');
  console.log('you can change that from index.js');
  console.log('listening on *:' + port + ' \n');
  // console.log('Server listening at port %d', port);
});

console.log('--established inet status--'.warn);

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

// Routing
// Let’s refactor our route handler
app.use(express.static(path.join(__dirname, 'public')));

// Chatroom
var numUsers = 0;

// note, io(<port>) will create a http server for you
io.on('connection', (socket) => {
  var addedUser = false;
  // when the client emits 'new message', this listens and executes
  socket.on('new message', (data) => {
    // we tell the client to execute 'new message'
    socket.broadcast.emit('new message', {
      username: socket.username,
      message: data
    });
  });
  // when the client emits 'add user', this listens and executes
  socket.on('add user', (username) => {
    if (addedUser) return;
    // we store the username in the socket session for this client
    socket.username = username;
    ++numUsers;
    addedUser = true;
    socket.emit('login', {
      numUsers: numUsers
    });
    console.log(socket.username + ' is connected'.data + ' :) '.info);
    // echo globally (all clients) that a person has connected
    socket.broadcast.emit('user joined', {
      username: socket.username,
      numUsers: numUsers
    });
  });
  // when the client emits 'typing', we broadcast it to others
  socket.on('typing', () => {
    console.log(socket.username + ' is typing'.data + '...'.debug);
    socket.broadcast.emit('typing', {
      username: socket.username
    });
  });
  // when the client emits 'stop typing', we broadcast it to others
  socket.on('stop typing', () => {
    console.log(socket.username + ' is stop typing'.data + '!'.debug);
    socket.broadcast.emit('stop typing', {
      username: socket.username
    });
  });
  // when the user disconnects.. perform this
  socket.on('disconnect', () => {
    if (addedUser) {
      --numUsers;
      console.log(socket.username + ' is disconnected'.data + ' :( '.error);
      // echo globally that this client has left
      socket.broadcast.emit('user left', {
        username: socket.username,
        numUsers: numUsers
      });
    }
  });
});
