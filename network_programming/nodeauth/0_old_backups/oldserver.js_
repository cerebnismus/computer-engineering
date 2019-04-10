'use strict';

// const http = require('http');
const url = require('url');
const path = require('path');
const fs = require('fs');
// const detect = require('detect-port'); // https://www.npmjs.com/package/detect-port
const mimeTypes = {
  "html": "text/html",
  "jpeg": "image/jpeg",
  "jpg": "image/jpg",
  "png": "image/png",
  "js": "text/javascript",
  "css": "text/css"
};

// Setup basic express
var express = require('express');
var app = express();

//Dependencies
var ip = require('ip'); // https://github.com/indutny/node-ip
var os = require('os'); // https://www.npmjs.com/package/os
var ifaces = os.networkInterfaces(); // eth0 192.168.1.24
var colors = require('colors'); // https://www.npmjs.com/package/colors
var server = require('http').createServer(app); // https://www.w3schools.com/nodejs/met_http_createserver.asp
var io = require('socket.io')(server); // https://socket.io/docs/internals/
var port = process.env.PORT || 3000; // PORT=4444 node index.js ~> run with sudo for ports below 1024.
// The process.env property returns an object containing the user environment.
var session = require('express-session');  //"cookie-session" modülü tüm oturum bilgilerini istemcide saklar
var logger = require('morgan');  // isteklerle ilgili logları konsola yazmak için
var cookieParser = require('cookie-parser'); // https://www.npmjs.com/package/cookie-parser
var bodyParser = require('body-parser');  //  get parameters from a request
var nodemailer = require('nodemailer'); //  post parameters from a contact form
var passport = require('passport') // http://www.passportjs.org/docs/configure/

var uptime = process.uptime(); // fail!!!


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

console.log('Sakarya University'.trap); // OMG Rainbows !
console.log('Computer Engineering'.rainbow); // Drops the bass
console.log('Network Programming'.info);
console.log('oguzhan.ince@ogr.sakarya.edu.tr\n'.error);   

server.listen(port, () => {
  console.log(' ');
  console.log('you can change that from server.js');
  console.log('listening on *:' + port + ' \n');
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
 
app.get('/contact', function(req, res){
  res.render('contact');
});

app.post('/contact/send', function(req, res){
  var transporter = nodemailer.createTransport({
    service: 'Gmail',
    auth: {
      user: 'dev.ops.34.26@gmail.com',
      pass: 'Ybayv4jqs*'
    }
  });
  var mailOptions = {
    from: 'admin <dev.ops.34.26@gmail.com>',
    to: 'oguzhan.ince@ogr.sakarya.edu.tr',
    subject: 'Website Submission',
    text: 'You have a submission with the following details... Name: '+req.body.name+'Email: '+req.body.email+ 'Message: '+req.body.message,
    html: '<p>You have a submission with the following details...</p><ul><li>Name: '+req.body.name+'</li><li>Email: '+req.body.email+'</li><li>Message: '+req.body.message+'</li> </ul>'
  };
  transporter.sendMail(mailOptions, function(error, info){
    if (error){
      console.log(error);
      res.redirect('/');
    } else if(typeof res.body.name == 'undefined'){
      console.log(error);
      res.redirect('/');
    }
    else {
      console.log('Message Sent: '+info.response);
      res.redirect('/');
    }
  })
});

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
