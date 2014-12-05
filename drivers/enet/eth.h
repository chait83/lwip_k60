/*! 
 * \file    eth.h
 * \brief   Definitinos for Ethernet Frames
 * \version $Revision: 1.1 $
 * \author  Michael Norman
 */

#ifndef _ETH_H
#define _ETH_H

/*b06862*/
#include "common.h"

/*******************************************************************/

/* Ethernet standard lengths in bytes*/
#define ETH_ADDR_LEN    (6)
#define ETH_TYPE_LEN    (2)
#define ETH_CRC_LEN     (4)
#define ETH_MAX_DATA    (1500)
#define ETH_MIN_DATA    (46)
#define ETH_HDR_LEN     (ETH_ADDR_LEN * 2 + ETH_TYPE_LEN)

/* Defined Ethernet Frame Types */
#define ETH_FRM_IP      (0x0800)
#define ETH_FRM_ARP     (0x0806)
#define ETH_FRM_RARP    (0x8035)
#define ETH_FRM_TEST    (0xA5A5)

/* Maximum and Minimum Ethernet Frame Sizes */
#define ETH_MAX_FRM     (ETH_HDR_LEN + ETH_MAX_DATA + ETH_CRC_LEN)
#define ETH_MIN_FRM     (ETH_HDR_LEN + ETH_MIN_DATA + ETH_CRC_LEN)
#define ETH_MTU         (ETH_HDR_LEN + ETH_MAX_DATA)

/* Ethernet Addresses */
typedef uint8_t ETH_ADDR[ETH_ADDR_LEN];

/* 16-bit Ethernet Frame Type, ie. Protocol */
typedef uint16_t ETH_FRM_TYPE;

/* Ethernet Frame Header definition */
typedef struct
{
    ETH_ADDR     dest;
    ETH_ADDR     src;
    ETH_FRM_TYPE type;
} ETH_HDR;

/* Ethernet Frame definition */
typedef struct
{
    ETH_HDR head;
    uint8_t*  data;
} ETH_FRAME;

/*******************************************************************/


#if configENET_RX_SINGLE_BUFFER
#define configENET_RX_BUFFER_SIZE	1520
#if (LWIP_PERF_SETTINGS==1)
#define configNUM_ENET_RX_BUFFERS	12
#else
#define configNUM_ENET_RX_BUFFERS	8
#endif
#else
#define configENET_RX_BUFFER_SIZE	256/*must be PBUF_POOL_BUFSIZE multiple*/
#if (LWIP_PERF_SETTINGS==1)
#define configNUM_ENET_RX_BUFFERS	72
#else
#define configNUM_ENET_RX_BUFFERS	48
#endif
//PBUF_POOL_BUFSIZE macro must be greater than ENET min pkt"
#endif


#define configNUM_ENET_TX_BUFFERS       3//more is useless for this specific driver: might try with lower
#define configENET_TX_BUFFER_SIZE	1520/*no need to reduce this number*/

#define configENET_MAX_PACKET_SIZE      1520
#define configUSE_PROMISCUOUS_MODE	0
#define configUSE_MII_MODE              0/*FSL: using RMII mode*/
#define configETHERNET_INPUT_TASK_STACK_SIZE ( 256 )
#define configETHERNET_INPUT_TASK_PRIORITY ( configMAX_PRIORITIES - 1 )

#ifndef TSIEVB
#define configPHY_ADDRESS	0
#else
#define configPHY_ADDRESS	1
#endif

#if ( configENET_MAX_PACKET_SIZE & 0x0F ) != 0
	#error configENET_BUFFER_SIZE must be a multiple of 16.
#endif


#endif  /* _ETH_H */
