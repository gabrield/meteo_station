#ifndef  _TS_HTTP_H_
# define _TS_HTTP_


#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netdb.h>
#include <unistd.h>

#include <thingspeak.h>

#define SA      struct sockaddr
#define MAXLINE 4096
#define MAXSUB  1024


#define LISTENQ         1024
#define HOST_API        "api.thingspeak.com"

extern int h_errno;


ssize_t ts_http_post(ts_context_t *, char *, char *, char *);


#endif /*_TS_HTTP_*/