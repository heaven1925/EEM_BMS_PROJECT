/*******************************************************************************
  * @file    canModule.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/

#ifndef CANMODULE_INC_CANMODULE_H_
#define CANMODULE_INC_CANMODULE_H_

/*
 * BMS Base Parameters Include
 */
#include "bmsConfig.h"

typedef enum
{
	CAN_EOK = 0,
	CAN_ERR = !CAN_EOK
}can_err_t;

typedef enum
{
	CAN_TRUE 	= 0,
	CAN_FALSE 	= !CAN_TRUE
}can_bool_t;

typedef		uint8_t			can_uint8_t;
typedef		uint16_t		can_uint16_t;
typedef		uint32_t		can_uint32_t;
typedef		uint64_t		can_uint64_t;

typedef		int8_t			can_int8_t;
typedef		int16_t			can_int16_t;
typedef		int32_t			can_int32_t;
typedef		int64_t			can_int64_t;

typedef enum
{
	CanModule_MAINState_INIT = 0,
	CanModule_MAINState_IDLE 	 ,
	CanModule_MAINState_ROUTINE ,
	CanModule_MAINState_PROCESS ,
	CanModule_MAINState_SUSPEND ,
}CanModule_MAINState_Type;

/*
 * Can Module Object Class
 */
typedef struct
{

}CanModule_ObjType;

/*
 * Can Module Ops Class
 */
typedef struct
{
	/* Main Private Methods */
	can_err_t	(*CanModule_INIT	)(CanModule_ObjType* param);
	can_err_t	(*CanModule_IDLE	)(CanModule_ObjType* param);
	can_err_t	(*CanModule_ROUTINE	)(CanModule_ObjType* param);
	can_err_t	(*CanModule_PROCESS	)(CanModule_ObjType* param);
	can_err_t	(*CanModule_SUSPEND )(CanModule_ObjType* param);
	/* Public Methods */
}CanModule_OpsType;

/*
 * Can Module Base Class
 */
typedef struct
{
	CanModule_ObjType Obj;
	CanModule_OpsType Ops;
}CanModule_Type;

/*
 * Can Base Class Constructor
 */
bms_err_t CanModule_CTOR(CanModule_Type* param);

/*
 * Can Main Function Prototypes
 */
static can_err_t	CanModule_INIT		(CanModule_ObjType* param);
static can_err_t	CanModule_IDLE		(CanModule_ObjType* param);
static can_err_t	CanModule_ROUTINE	(CanModule_ObjType* param);
static can_err_t	CanModule_PROCESS	(CanModule_ObjType* param);
static can_err_t	CanModule_SUSPEND	(CanModule_ObjType* param);


/*
 * Can Module Main Function
 */
void  MainCAN		(void);



#endif /* CANMODULE_INC_CANMODULE_H_ */
