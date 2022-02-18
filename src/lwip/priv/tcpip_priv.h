/**
 * @file
 * TCPIP API internal implementations (do not use in application code)
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef LWIP_HDR_TCPIP_PRIV_H
#define LWIP_HDR_TCPIP_PRIV_H

#include "lwip/opt.h"

#if !NO_SYS /* don't build if not configured for use in lwipopts.h */

#include "lwip/tcpip.h"
// #include "lwip/sys.h"
// #include "lwip/timeouts.h"

#ifdef __cplusplus
extern "C" {
#endif

struct tcpip_api_call_data
{
#if !LWIP_TCPIP_CORE_LOCKING
  err_t err;
#if !LWIP_NETCONN_SEM_PER_THREAD
  sys_sem_t sem;
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#else /* !LWIP_TCPIP_CORE_LOCKING */
  u8_t dummy; /* avoid empty struct :-( */
#endif /* !LWIP_TCPIP_CORE_LOCKING */
};
typedef err_t (*tcpip_api_call_fn)(struct tcpip_api_call_data* call);
err_t tcpip_api_call(tcpip_api_call_fn fn, struct tcpip_api_call_data *call);

// enum tcpip_msg_type {
//   TCPIP_MSG_API,
//   TCPIP_MSG_API_CALL,
//   TCPIP_MSG_INPKT,
// #if LWIP_TCPIP_TIMEOUT && LWIP_TIMERS
//   TCPIP_MSG_TIMEOUT,
//   TCPIP_MSG_UNTIMEOUT,
// #endif /* LWIP_TCPIP_TIMEOUT && LWIP_TIMERS */
//   TCPIP_MSG_CALLBACK,
//   TCPIP_MSG_CALLBACK_STATIC
// };

// struct tcpip_msg {
//   enum tcpip_msg_type type;
//   union {
//     struct {
//       tcpip_callback_fn function;
//       void* msg;
//     } api_msg;
//     struct {
//       tcpip_api_call_fn function;
//       struct tcpip_api_call_data *arg;
//       sys_sem_t *sem;
//     } api_call;
//     struct {
//       struct pbuf *p;
//       struct netif *netif;
//       netif_input_fn input_fn;
//     } inp;
//     struct {
//       tcpip_callback_fn function;
//       void *ctx;
//     } cb;
// #if LWIP_TCPIP_TIMEOUT && LWIP_TIMERS
//     struct {
//       u32_t msecs;
//       sys_timeout_handler h;
//       void *arg;
//     } tmo;
// #endif /* LWIP_TCPIP_TIMEOUT && LWIP_TIMERS */
//   } msg;
// };

#ifdef __cplusplus
}
#endif

#endif /* !NO_SYS */

#endif /* LWIP_HDR_TCPIP_PRIV_H */
