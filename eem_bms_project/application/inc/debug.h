/*******************************************************************************
  * @file    debug.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/

#ifndef INC_DEBUG_H_
#define INC_DEBUG_H_

#include "stm32f4xx_hal_uart.h"

/*
 * Enable/Disable Debug Configurations
 */
#define BSP_DEBUG_MSG
//#undef BSP_DEBUG_MSG

#define	DEBUG_MSG_SIZE 50

/*
 * Length of Tags
 */
#define DEBUG_TAG_LENGTH 5

/*
 * Size of Tags
 */
#define	DEBUG_TAG_SIZE 8

#define		MSG_RUN	 					((int)( 0x00UL ))
#define		MSG_IDLE	 				((int)( 0x01UL ))
#define		MSG_ROUTINE					((int)( 0x02UL ))
#define		MSG_PROCESS					((int)( 0x03UL ))
#define		MSG_SUSPEND					((int)( 0x04UL ))
#define		MSG_ERR	 					((int)( 0x05UL ))
#define		MSG_EOK	 					((int)( 0x06UL ))
#define		MSG_END    					((int)( 0x07UL ))

/*
 * Debug Status Type
 */
typedef enum
{
	DEBUG_EOK 	= 0,
	DEBUG_ERROR = !DEBUG_EOK
}DEBUG_Status;

/*
 * Debug Status Type
 */
typedef enum
{
	DEBUG_MSG_RUN	 	= 0,
	DEBUG_MSG_IDLE	   ,
	DEBUG_MSG_ROUTINE  ,
	DEBUG_MSG_PROCESS  ,
	DEBUG_MSG_SUSPEND  ,
	DEBUG_MSG_ERR	   ,
	DEBUG_MSG_EOK	   ,
	DEBUG_MSG_END
}DEBUG_Status_Type;

/*
 * Debug Object Class
 */
typedef struct
{
	UART_HandleTypeDef huart;
	DEBUG_Status_Type  status;
	char* stateMsgHandle;
	char* statusMsgHandle;

	const char DEBUG_CONSTS[DEBUG_TAG_SIZE][DEBUG_TAG_LENGTH];

}DEBUG_Obj_Type;

/*
 * Debug Method Class
 */
typedef struct
{
	int 				(*System_StateDEBUG_MSG )	(DEBUG_Obj_Type* param , char* msg , int state);
	void				(*System_SetDEBUG_Status)	(DEBUG_Obj_Type* param, DEBUG_Status_Type status);
	DEBUG_Status_Type	(*System_GetDEBUG_Status)	(DEBUG_Obj_Type* param);
}DEBUG_Ops_Type;


/*
 * Debug Base Class
 */
typedef struct
{
	DEBUG_Obj_Type obj;
	DEBUG_Ops_Type ops;
}DEBUG_Type;

/*
 * Debug Constructor
 */
extern void System_StateDEBUG_CTOR(DEBUG_Type* param, UART_HandleTypeDef _huart );

/*
 * Debug Functions Definitions
 */
int 				System_StateDEBUG_MSG		(DEBUG_Obj_Type* param , char* msg , int state);
void				System_SetDEBUG_Status		(DEBUG_Obj_Type* param, DEBUG_Status_Type status);
DEBUG_Status_Type	System_GetDEBUG_Status		(DEBUG_Obj_Type* param);

#endif /* INC_DEBUG_H_ */
