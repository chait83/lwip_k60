/* ###################################################################
**     Filename    : Events.h
**     Project     : lwip
**     Processor   : MK60DN512VLQ10
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-12-01, 20:15, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "FRTOS1.h"
#include "UTIL1.h"
#include "ETH1.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MK60DN512LQ10]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


void FRTOS1_vApplicationStackOverflowHook(xTaskHandle pxTask, char *pcTaskName);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationStackOverflowHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         if enabled, this hook will be called in case of a stack
**         overflow.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pxTask          - Task handle
**       * pcTaskName      - Pointer to task name
**     Returns     : Nothing
** ===================================================================
*/

void FRTOS1_vApplicationTickHook(void);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationTickHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, this hook will be called by the RTOS for every
**         tick increment.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void FRTOS1_vApplicationIdleHook(void);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationIdleHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, this hook will be called when the RTOS is idle.
**         This might be a good place to go into low power mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void FRTOS1_vApplicationMallocFailedHook(void);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationMallocFailedHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, the RTOS will call this hook in case memory
**         allocation failed.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/*
** ===================================================================
**     Event       :  ETH1_OnFrameTransmitted (module Events)
**
**     Component   :  ETH1 [Ethernet_LDD]
*/
/*!
**     @brief
**         This event is called after the whole frame on the head of
**         the internal frame queue has been sent and removed from the
**         queue. The event is available only if IEEE 1588 is disabled.
**     @param
**         UserDataPtr     - Pointer to user data
**                           structure pointer.
*/
/* ===================================================================*/
void ETH1_OnFrameTransmitted(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Event       :  ETH1_OnFrameReceived (module Events)
**
**     Component   :  ETH1 [Ethernet_LDD]
*/
/*!
**     @brief
**         This event is called after the whole frame on the head of
**         the internal frame queue has been received and removed from
**         the queue. The event is available only if IEEE 1588 is
**         disabled.
**     @param
**         UserDataPtr     - Pointer to user data
**                           structure pointer.
**     @param
**         FragCount       - Received frame fragment count
**                           (the number of buffers used to store the
**                           frame data).
**     @param
**         Length          - Received frame length.
*/
/* ===================================================================*/
void ETH1_OnFrameReceived(LDD_TUserData *UserDataPtr, uint16_t FragCount, uint16_t Length);

/*
** ===================================================================
**     Event       :  ETH1_OnFatalError (module Events)
**
**     Component   :  ETH1 [Ethernet_LDD]
*/
/*!
**     @brief
**         This event is called when a fatal error has occurred (i.e.
**         ethernet bus error). The device should be reinitialized
**         during this event (Deinit and Init methods should be called).
**     @param
**         UserDataPtr     - Pointer to user data
**                           structure pointer.
*/
/* ===================================================================*/
void ETH1_OnFatalError(LDD_TUserData *UserDataPtr);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
