/*******************************************************************************
  * @file    balanceModule.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/

#include "app.h"
#include "balanceModule.h"

#define MAIN_BALANCE

/*
 * Main State Machine Exclusion
 */
extern State_Type 		 MAINstate;
extern	uint32_t 		 Clock;

/*
 * Cell Main Class
 */
extern 	Bms_Cell_Type Cell[BMS_CELL_SIZE];
extern	Bms_Main_Type Base;

/*
 * Balance Module Main State
 */
BalanceModule_MAINState_Type BalanceModule_MAINState = BalanceModule_MAINState_INIT;

/*
 * Balance Module Main Class
 */
BalanceModule_Type BalanceModule;







#ifdef MAIN_BALANCE

bms_err_t BalanceModule_CTOR(BalanceModule_Type* param)
{
	bms_err_t 	 result 		= BMS_EOK;
	bms_uint32_t addrHandle		= 0;

	/* Virtual pointer Assignment */
	static BalanceModule_OpsType Vptr =
	{
			BalanceModule_INIT    ,
			BalanceModule_IDLE 	  ,
			BalanceModule_ROUTINE ,
			BalanceModule_PROCESS ,
			BalanceModule_SUSPEND
	};
	param->Ops = Vptr ;

	/* Check functions has on flash addr space */
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&param->Ops.BalanceModule_INIT);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&param->Ops.BalanceModule_IDLE);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&param->Ops.BalanceModule_ROUTINE);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&param->Ops.BalanceModule_PROCESS);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&param->Ops.BalanceModule_SUSPEND);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;

	return result;
}

static balance_err_t	BalanceModule_INIT(BalanceModule_ObjType* param)
{
	balance_err_t result = BALANCE_EOK;



	return result;
}

static balance_err_t	BalanceModule_IDLE(BalanceModule_ObjType* param)
{
	balance_err_t result = BALANCE_EOK;



	return result;
}

static balance_err_t	BalanceModule_ROUTINE(BalanceModule_ObjType* param)
{
	balance_err_t result = BALANCE_EOK;



	return result;
}

static balance_err_t	BalanceModule_PROCESS(BalanceModule_ObjType* param)
{
	balance_err_t result = BALANCE_EOK;



	return result;
}

static balance_err_t	BalanceModule_SUSPEND(BalanceModule_ObjType* param)
{
	balance_err_t result = BALANCE_EOK;



	return result;
}

void MainBALANCE(void)
{
	balance_err_t result = BALANCE_EOK;

	switch(BalanceModule_MAINState)
	{
		/* Init State Operations */
		case BalanceModule_MAINState_INIT	 : result = BalanceModule.Ops.BalanceModule_INIT(&BalanceModule.Obj);
			break;
		/* Idle State Operations */
		case BalanceModule_MAINState_IDLE	 : result = BalanceModule.Ops.BalanceModule_IDLE(&BalanceModule.Obj);
			break;
		/* Routine State Operations */
		case BalanceModule_MAINState_ROUTINE : result = BalanceModule.Ops.BalanceModule_ROUTINE(&BalanceModule.Obj);
			break;
		/* Process State Operations */
		case BalanceModule_MAINState_PROCESS : result = BalanceModule.Ops.BalanceModule_PROCESS(&BalanceModule.Obj);
			break;
		/* Suspend State Operations */
		case BalanceModule_MAINState_SUSPEND : result = BalanceModule.Ops.BalanceModule_SUSPEND(&BalanceModule.Obj);
			break;

		/* Error State Operations */
		default: break;
	}

	if( result != BALANCE_EOK) for(;;); /* Infinite Loop until WDT Reset */

}
#endif
