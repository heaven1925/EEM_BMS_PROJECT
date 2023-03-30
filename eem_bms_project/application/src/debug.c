/*******************************************************************************
  * @file    debug.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/

#include "main.h"

#include "app.h"
#include "debug.h"

void System_StateDEBUG_CTOR(DEBUG_Type* param, UART_HandleTypeDef _huart )
{
	static const DEBUG_Ops_Type Vptr = {
			System_StateDEBUG_MSG 	,
			System_SetDEBUG_Status	,
			System_GetDEBUG_Status
	};
	param->ops = Vptr;

	param->obj.huart = _huart;
}



int  System_StateDEBUG_MSG (DEBUG_Obj_Type* param , char* msg , int state)
{


	HAL_StatusTypeDef result = HAL_OK;

	if( sizeof(msg) > DEBUG_MSG_SIZE)
	{
		result = HAL_UART_Transmit(&param->huart , (uint8_t*)&param->DEBUG_CONSTS[DEBUG_MSG_ERR][0] , DEBUG_TAG_SIZE, 10);
		if( result != HAL_OK ) return -1;
		return -2;
	}
	else
	{
		param->stateMsgHandle  = (char*)malloc( sizeof(DEBUG_MSG_SIZE) );
		param->statusMsgHandle = (char*)malloc( sizeof(DEBUG_TAG_SIZE) );

		switch(state)
		{
			case DEBUG_MSG_RUN		: sprintf(param->statusMsgHandle, "%s" , &param->DEBUG_CONSTS[DEBUG_MSG_RUN	 	][0]); break;
			case DEBUG_MSG_IDLE		: sprintf(param->statusMsgHandle, "%s" , &param->DEBUG_CONSTS[DEBUG_MSG_IDLE	][0]); break;
			case DEBUG_MSG_ROUTINE	: sprintf(param->statusMsgHandle, "%s" , &param->DEBUG_CONSTS[DEBUG_MSG_ROUTINE	][0]); break;
			case DEBUG_MSG_PROCESS	: sprintf(param->statusMsgHandle, "%s" , &param->DEBUG_CONSTS[DEBUG_MSG_PROCESS	][0]); break;
			case DEBUG_MSG_SUSPEND	: sprintf(param->statusMsgHandle, "%s" , &param->DEBUG_CONSTS[DEBUG_MSG_SUSPEND	][0]); break;
			case DEBUG_MSG_ERR		: sprintf(param->statusMsgHandle, "%s" , &param->DEBUG_CONSTS[DEBUG_MSG_ERR	 	][0]); break;
			case DEBUG_MSG_EOK		: sprintf(param->statusMsgHandle, "%s" , &param->DEBUG_CONSTS[DEBUG_MSG_EOK	 	][0]); break;
			case DEBUG_MSG_END		: sprintf(param->statusMsgHandle, "%s" , &param->DEBUG_CONSTS[DEBUG_MSG_END    	][0]); break;

			default: break;
		}

		sprintf( param->stateMsgHandle, "DBG: %s %s \n\r" , msg , param->statusMsgHandle );

		result = HAL_UART_Transmit(&huart5, (uint8_t*)param->stateMsgHandle, DEBUG_MSG_SIZE, 10);
		/* Free first */

		free(param->statusMsgHandle);
		free(param->stateMsgHandle);

		if( result != HAL_OK ) return -1;
	}

	return 0;
}


void				System_SetDEBUG_Status		(DEBUG_Obj_Type* param, DEBUG_Status_Type status)
{
	param->status = status;
}

DEBUG_Status_Type	System_GetDEBUG_Status		(DEBUG_Obj_Type* param)
{
	return param->status;
}
