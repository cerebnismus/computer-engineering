extern int serve_socket(char *hn, int port);
		/* This serves a socket at the given host name and port
		   number.  It returns an fd for that socket.  Hn should
                   be the name of the server's machine. */

extern int accept_connection(int s);
		/* This accepts a connection on the given socket (i.e.
                   it should only be called on by the server.  It returns
                   the fd for the connection.  This fd is of course r/w */

extern int request_connection(char *hn, int port);
		/* This is what the client calls to connect to a server's
                   port.  It returns the fd for the connection. */
