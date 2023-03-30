/*******************************************************************************
  * @file    app.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/

#ifndef __APP_H__
#define	__APP_H__

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "stm32f4xx.h"


/*
 * Main State Names
 */
#define 	ADC_STATE_NAME 				"ADC_STATE_NAME"
#define 	BALANCE_STATE_NAME 			"BALANCE_STATE_NAME"
#define 	CAN_STATE_NAME 				"CAN_STATE_NAME"

/*
 * Main State Tick Time
 */
#define		TOTAL_TICKTIME				( 0x0AUL ) /* State Machine Works 10 Tick */

#define		ADC_STATE_TICKTIME			( 0x00UL ) /* Works 4 Tick */
#define		BALANCE_STATE_TICKTIME		( 0X04UL ) /* Works 4 Tick */
#define		CAN_STATE_TICKTIME			( 0X08UL ) /* Works 2 Tick */

/*
 * Main State Process Communcation Flags
 */
typedef union
{
	uint8_t state;
	struct
	{
		bool adc 	 : 1 ;
		bool balance : 1 ;
		bool can 	 : 1 ;
		// Dummy Definition
		uint8_t dummy: 5 ;
	}Flag;
}StatusFlag_Type;


/*
* Main State Machine Main Types
*/
typedef enum
{
	STATE_ADC 		,
	STATE_BALANCE 	,
	STATE_CAN
}State_Type;

/*
* State Machine Virtual Function Queues
*/
enum
{
		STATE_ADC_MAIN = 0,
	 /* Other sub states can be added here */
};

enum
{
		STATE_BALANCE_MAIN = 0,
	 /* Other sub states can be added here */
};

enum
{
		STATE_CAN_MAIN = 0,
	 /* Other sub states can be added here */
};


/*
* State Machine Time Parameters
*/
typedef struct
{
	uint32_t 	prevTime;
	uint32_t 	nowTime;
	float		deltaTime;
}StateTime_Type;



/*
* State Machine Main Class
*/
typedef struct
{
	struct OpsVTable const* vptr;
}MainState_Type;

/*
* State Machine Ops
*/
struct OpsVTable {

	void (*StateADC_MAIN	) (MainState_Type const * const param);
	void (*StateBALANCE_MAIN) (MainState_Type const * const param);
	void (*StateCAN_MAIN	) (MainState_Type const * const param);

};

/*
* Ops Definitions
*/
//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
static inline void MainState_RunA_Vcall(MainState_Type const * const param)
{
	(*param->vptr->StateADC_MAIN)(param);
}

static inline void MainState_RunB_Vcall(MainState_Type const * const param)
{
	(*param->vptr->StateBALANCE_MAIN)(param);
}

static inline void MainState_RunC_Vcall(MainState_Type const * const param)
{
	(*param->vptr->StateCAN_MAIN)(param);
}
//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]


/*
* Main State Machine Constructor Function
*/
void MainState_CTOR( MainState_Type* const param );


/*
* Polymorphism Function Decleration
*/
void	System_StateADC_MAIN	( MainState_Type* const modules[] );
void	System_StateBALANCE_MAIN( MainState_Type* const modules[] );
void	System_StateCAN_MAIN	( MainState_Type* const modules[] );



/*
 * Main Function Block
 */
void 	App_MAIN(void);

/*
 * Module Function Prototypes
 */
extern void  MainADC		(void);
extern void  MainBALANCE	(void);
extern void  MainCAN		(void);

#endif /* __APP_H__ */

