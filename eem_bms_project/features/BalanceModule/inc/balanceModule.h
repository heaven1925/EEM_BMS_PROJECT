/*******************************************************************************
  * @file    balanceModule.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/


#ifndef BALANCEMODULE_INC_ADCMODULE_H_
#define BALANCEMODULE_INC_ADCMODULE_H_

/*
 * BMS Base Parameters Include
 */
#include "bmsConfig.h"

typedef enum
{
	BALANCE_EOK = 0,
	BALANCE_ERR = !BALANCE_EOK
}balance_err_t;

typedef enum
{
	BALANCE_TRUE 	= 0,
	BALANCE_FALSE 	= !BALANCE_TRUE
}balance_bool_t;

typedef		uint8_t			balance_uint8_t;
typedef		uint16_t		balance_uint16_t;
typedef		uint32_t		balance_uint32_t;
typedef		uint64_t		balance_uint64_t;

typedef		int8_t			balance_int8_t;
typedef		int16_t			balance_int16_t;
typedef		int32_t			balance_int32_t;
typedef		int64_t			balance_int64_t;

typedef enum
{
	BalanceModule_MAINState_INIT = 0,
	BalanceModule_MAINState_IDLE 	 ,
	BalanceModule_MAINState_ROUTINE ,
	BalanceModule_MAINState_PROCESS ,
	BalanceModule_MAINState_SUSPEND ,
}BalanceModule_MAINState_Type;

/*
 * Balance Module Object Class
 */
typedef struct
{

}BalanceModule_ObjType;

/*
 * Balance Module Ops Class
 */
typedef struct
{
	/* Main Private Methods */
	balance_err_t	(*BalanceModule_INIT	)(BalanceModule_ObjType* param);
	balance_err_t	(*BalanceModule_IDLE	)(BalanceModule_ObjType* param);
	balance_err_t	(*BalanceModule_ROUTINE	)(BalanceModule_ObjType* param);
	balance_err_t	(*BalanceModule_PROCESS	)(BalanceModule_ObjType* param);
	balance_err_t	(*BalanceModule_SUSPEND )(BalanceModule_ObjType* param);
	/* Public Methods */
}BalanceModule_OpsType;

/*
 * Balance Module Base Class
 */
typedef struct
{
	BalanceModule_ObjType Obj;
	BalanceModule_OpsType Ops;
}BalanceModule_Type;

/*
 * Balance Base Class Constructor
 */
bms_err_t BalanceModule_CTOR(BalanceModule_Type* param);

/*
 * Balance Main Function Prototypes
 */
static balance_err_t	BalanceModule_INIT		(BalanceModule_ObjType* param);
static balance_err_t	BalanceModule_IDLE		(BalanceModule_ObjType* param);
static balance_err_t	BalanceModule_ROUTINE	(BalanceModule_ObjType* param);
static balance_err_t	BalanceModule_PROCESS	(BalanceModule_ObjType* param);
static balance_err_t	BalanceModule_SUSPEND	(BalanceModule_ObjType* param);


/*
 * Balance Module Main Function
 */
void  MainBALANCE		(void);

#endif /* BALANCEMODULE_INC_ADCMODULE_H_ */
