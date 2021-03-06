
#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <libwebsockets.h>

#define WEBSOCKET_SUCCESS 0
#define WEBSOCKET_FAIL 1

int websocket_init(struct lws_context **context, struct lws **wsi_dumb, 
                   char *host, char *path, int port, void *handle);
int websocket_close(struct lws_context *context);

#endif
