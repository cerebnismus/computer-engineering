const http = require('http');
const url = require('url');
const path = require('path');
const fs = require('fs');

//Dependencies
var express = require('express');
var session = require('express-session');  //"cookie-session" modülü tüm oturum bilgilerini istemcide saklar
var logger = require('morgan');  // isteklerle ilgili logları konsola yazmak için
//var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');  //  get parameters from a request
var app = express();
const mimeTypes = {
    "html": "text/html",
    "jpeg": "image/jpeg",
    "jpg": "image/jpg",
    "png": "image/png",
    "js": "text/javascript",
    "css": "text/css"
};

http.createServer(function(req, res){
  var uri = url.parse(req.url).pathname;  // Parse the request containing file name
  var filename = path.join(process.cwd(), unescape(uri));
  console.log('Loading ' + uri);  // Print the name of the file for which request is made.
  var stats = fs.lstatSync(fileName);

  // Read the requested file content from file system
  if (stats.isFile()) {
    var mimeType = mimeTypes[path.extname(fileName).split(".").reverse()[0]];
    res.writeHead(200, {'Content-type':mimeType});
    // Page found: HTTP Status: 200 : OK
    var fileStream = fs.createReadStream(fileName);
    fileStream.pipe(res);
  }else if (stats.isDirectory()) {
    // console.log(req.headers);
    res.writeHead(302, {
      'Location': 'index.html'
    });
    res.end(); // Send the response body
  }else {
    console.log(req.headers); 
    res.writeHead(404, {'Content-type':'text/plain'});
    res.write('404 Not Found\n'); 
    res.end(); // Send the response body
    return;
  }
    // console.log(req.headers);
    // res.writeHead(500, {'Content-type':'text/plain'});
    // res.write('500 Internal Error\n');
    // res.end(); /
  
}).listen(8080);

console.log('Listening Port 8080');


