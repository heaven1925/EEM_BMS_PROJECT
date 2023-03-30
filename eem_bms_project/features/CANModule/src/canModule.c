/*******************************************************************************
  * @file    canModule.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/

#include "app.h"
#include "canModule.h"

#define MAIN_CAN

/*
 * Main State Machine Exclusion
 */
extern  State_Type 		 MAINstate;
extern	uint32_t 		 Clock;

/*
 * Cell Main Class
 */
extern 	Bms_Cell_Type Cell[BMS_CELL_SIZE];
extern	Bms_Main_Type Base;

/*
 * Can Module Main State
 */
CanModule_MAINState_Type CanModule_MAINState = CanModule_MAINState_INIT;

/*
 * Can Module Main Class
 */
CanModule_Type CanModule;







#ifdef MAIN_CAN

bms_err_t CanModule_CTOR(CanModule_Type* param)
{
	bms_err_t 	 result 		= BMS_EOK;
	bms_uint32_t addrHandle		= 0;

	/* Virtual pointer Assignment */
	static CanModule_OpsType Vptr =
	{
			CanModule_INIT    ,
			CanModule_IDLE 	  ,
			CanModule_ROUTINE ,
			CanModule_PROCESS ,
			CanModule_SUSPEND
	};
	param->Ops = Vptr ;

	/* Check functions has on flash addr space */
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&param->Ops.CanModule_INIT);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&param->Ops.CanModule_IDLE);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&param->Ops.CanModule_ROUTINE);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&param->Ops.CanModule_PROCESS);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&param->Ops.CanModule_SUSPEND);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;

	return result;
}

static can_err_t	CanModule_INIT(CanModule_ObjType* param)
{
	can_err_t result = CAN_EOK;



	return result;
}

static can_err_t	CanModule_IDLE(CanModule_ObjType* param)
{
	can_err_t result = CAN_EOK;



	return result;
}

static can_err_t	CanModule_ROUTINE(CanModule_ObjType* param)
{
	can_err_t result = CAN_EOK;



	return result;
}

static can_err_t	CanModule_PROCESS(CanModule_ObjType* param)
{
	can_err_t result = CAN_EOK;



	return result;
}

static can_err_t	CanModule_SUSPEND(CanModule_ObjType* param)
{
	can_err_t result = CAN_EOK;



	return result;
}

void MainCAN(void)
{
	can_err_t result = CAN_EOK;

	switch(CanModule_MAINState)
	{
		/* Init State Operations */
		case CanModule_MAINState_INIT	 	: result = CanModule.Ops.CanModule_INIT		(&CanModule.Obj);
			break;
		/* Idle State Operations */
		case CanModule_MAINState_IDLE	 	: result = CanModule.Ops.CanModule_IDLE		(&CanModule.Obj);
			break;
		/* Routine State Operations */
		case CanModule_MAINState_ROUTINE	: result = CanModule.Ops.CanModule_ROUTINE	(&CanModule.Obj);
			break;
		/* Process State Operations */
		case CanModule_MAINState_PROCESS	: result = CanModule.Ops.CanModule_PROCESS	(&CanModule.Obj);
			break;
		/* Suspend State Operations */
		case CanModule_MAINState_SUSPEND	: result = CanModule.Ops.CanModule_SUSPEND	(&CanModule.Obj);
			break;

		/* Error State Operations */
		default: break;
	}

	if( result != CAN_EOK) for(;;); /* Infinite Loop until WDT Reset */

}
#endif
