
## Very Simple Web Server

```
$ mkdir simpleserver
$ cd simpleserver
$ npm init
```

# Socket.IO Chat

A simple chat demo for socket.io

## How to use

```
$ cd socket.io
$ npm install
$ cd examples/chat
$ npm install
$ npm start
```

And point your browser to `http://localhost:3000`. Optionally, specify
a port by supplying the `PORT` env variable.

## Features

- Multiple users can join a chat room by each entering a unique username
on website load.
- Users can type chat messages to the chat room.
- A notification is sent to all users when a user joins or leaves
the chatroom.

## Example

This is the source code for a very simple chat example used for
the [Getting Started](http://socket.io/get-started/chat/) guide
of the Socket.IO website.

Please refer to it to learn how to run this application.

You can also spin up a free Heroku dyno to test it out:

[![Deploy](https://www.herokucdn.com/deploy/button.png)](https://heroku.com/deploy?template=https://github.com/socketio/chat-example)

Besides, the application is deployed on [Now](https://zeit.co/now): https://socketio-chat-example.now.sh/

## RestAPI Testing

node server.js

http://localhost:8080/RestAPI/Ogrenciler

curl --request GET http://localhost:8080/RestAPI/Ogrenciler
curl --request GET http://localhost:8080/RestAPI/Ogrenciler/00000000003
curl --request POST http://localhost:8080/RestAPI/Ogrenciler --data 'ogrenciNo=00000002222&adi=Sena'


# phpstorm rest client - for post vars

- in request headers 
Content-Type : application/x-www-form-urlencoded

- in Request Body
ogrenciNo=6&adi=Mehmet


## Resources

https://github.com/celalceken/
https://github.com/celalceken/WaspmoteProject

Ağ Programlama Dersi Notları sürekli güncellenmektedir...
