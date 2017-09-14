#ifndef HTTPD_PLATFORM_H
#define HTTPD_PLATFORM_H

#include "libesphttpd/platform.h"

int httpdPlatSendData(ConnTypePtr conn, char *buff, int len);
void httpdPlatDisconnect(ConnTypePtr conn);
void httpdPlatDisableTimeout(ConnTypePtr conn);

/* NOTE: listenAddress is in network byte order */
void httpdPlatInit(int port, int maxConnCt, uint32_t listenAddress);

void httpdPlatLock();
void httpdPlatUnlock();

HttpdPlatTimerHandle httpdPlatTimerCreate(const char *name, int periodMs, int autoreload, void (*callback)(void *arg), void *ctx);
void httpdPlatTimerStart(HttpdPlatTimerHandle timer);
void httpdPlatTimerStop(HttpdPlatTimerHandle timer);
void httpdPlatTimerDelete(HttpdPlatTimerHandle timer);


#endif
