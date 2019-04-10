// GNU General Public License v3.0
// 'use strict';
// const http = require('http');
// const url = require('url');
// const path = require('path');
// const fs = require('fs');
// const detect = require('detect-port'); // https://www.npmjs.com/package/detect-port

// Dependencies & Setup basic express server
var createError = require('http-errors');
var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var expressValidator = require('express-validator');
var multer = require('multer');
var upload = multer({dest:'./uploads'});
var flash = require('connect-flash');
var bcrypt = require('bcryptjs');
var mongodb = require('mongodb');
var mongoose = require('mongoose');
var db = mongoose.connection;
var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var app = express();
var ip = require('ip'); // https://github.com/indutny/node-ip
var os = require('os'); // https://www.npmjs.com/package/os
var ifaces = os.networkInterfaces(); // eth0 192.168.1.24
var colors = require('colors'); // https://www.npmjs.com/package/colors
var server = require('http').createServer(app); // https://www.w3schools.com/nodejs/met_http_createserver.asp
var io = require('socket.io')(server); // https://socket.io/docs/internals/
var port = process.env.PORT || 4444; // PORT=3000 node index.js ~> run with sudo for ports below 1024.
// The process.env property returns an object containing the user environment.
var session = require('express-session');  //"cookie-session" modülü tüm oturum bilgilerini istemcide saklar
var logger = require('morgan');  // isteklerle ilgili logları konsola yazmak için
var cookieParser = require('cookie-parser'); // https://www.npmjs.com/package/cookie-parser
var bodyParser = require('body-parser');  //  get parameters from a request
var nodemailer = require('nodemailer'); //  post parameters from a contact form
var passport = require('passport') // http://www.passportjs.org/docs/configure/
var LocalStrategy = require('passport-local').Strategy;
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

const mimeTypes = {
  "html": "text/html",
  "jpeg": "image/jpeg",
  "jpg": "image/jpg",
  "png": "image/png",
  "js": "text/javascript",
  "css": "text/css"
};

console.log('Sakarya University - Computer Engineering'.verbose); // OMG Rainbows !
console.log('Author: '.verbose + 'oguzhan.ince@ogr.sakarya.edu.tr\n'.info);   

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

// Mongoose Database Connetion
mongoose.connect("mongodb://localhost:27017/test", { useNewUrlParser: true }, function(err, db){
  if (err) {
    console.log(err);
  }else {
    console.log('Mongoose is running\n');
    db.close(); // if it goes wrong, comment this line
  }
});

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');

// Handle Uploads
// app.use(multer({dest:'./uploads'}));

app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

// Handle Sessions
app.use(session({
				secret:'secret',
				saveUninitialized: true,
				resave: true
}));

// Passport
app.use(passport.initialize());
app.use(passport.session());

// Validator
app.use(expressValidator({
						 errorFormatter: function(param, msg, value) {
						 var namespace = param.split('.')
						 , root    = namespace.shift()
						 , formParam = root;
						 
						 while(namespace.length) {
						 formParam += '[' + namespace.shift() + ']';
						 }
						 return {
						   param : formParam,
						   msg   : msg,
						   value : value
						 };
						 }
}));

// Express Messages to Connect Flash
app.use(require('connect-flash')());
app.use(function (req, res, next) {
		res.locals.messages = require('express-messages')(req, res);
		next();
});

app.get('*', function(req, res, next){
  res.locals.user = req.user || null;
  next();
});

app.use('/', indexRouter);
app.use('/users', usersRouter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
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

module.exports = app;
