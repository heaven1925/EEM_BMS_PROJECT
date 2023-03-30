/*******************************************************************************
  * @file    adcModule.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/


#ifndef ADCMODULE_INC_ADCMODULE_H_
#define ADCMODULE_INC_ADCMODULE_H_

/*
 * BMS Base Parameters Include
 */
#include "bmsConfig.h"

typedef enum
{
	ADC_EOK = 0,
	ADC_ERR = !ADC_EOK
}adc_err_t;

typedef enum
{
	ADC_TRUE = 0,
	ADC_FALSE = !ADC_TRUE
}adc_bool_t;

typedef		uint8_t				adc_uint8_t;
typedef		uint16_t			adc_uint16_t;
typedef		uint32_t			adc_uint32_t;
typedef		uint64_t			adc_uint64_t;

typedef		int8_t				adc_int8_t;
typedef		int16_t				adc_int16_t;
typedef		int32_t				adc_int32_t;
typedef		int64_t				adc_int64_t;

#define		adc_handleTypeDef				ADC_HandleTypeDef
#define		adc_channelConfigTypeDef		ADC_ChannelConfTypeDef

/*
 * ADC Handler Exclusion
 */
extern ADC_HandleTypeDef hadc1;

/*
 * GPIO Pin Mux Definitions
 */
#define M1_S0_Pin 			GPIO_PIN_13
#define M1_S0_GPIO_Port 	GPIOF
#define M1_S1_Pin 			GPIO_PIN_14
#define M1_S1_GPIO_Port 	GPIOF
#define M1_S2_Pin 			GPIO_PIN_15
#define M1_S2_GPIO_Port 	GPIOF
#define M2_S0_Pin 			GPIO_PIN_0
#define M2_S0_GPIO_Port 	GPIOG
#define M2_S1_Pin 			GPIO_PIN_1
#define M2_S1_GPIO_Port 	GPIOG
#define M2_S2_Pin 			GPIO_PIN_7
#define M2_S2_GPIO_Port 	GPIOE
#define M3_S0_Pin 			GPIO_PIN_10
#define M3_S0_GPIO_Port 	GPIOE
#define M3_S1_Pin 			GPIO_PIN_11
#define M3_S1_GPIO_Port 	GPIOE
#define M3_S2_Pin 			GPIO_PIN_12
#define M3_S2_GPIO_Port 	GPIOE
#define M0_S0_Pin 			GPIO_PIN_15
#define M0_S0_GPIO_Port 	GPIOA
#define M0_S1_Pin 			GPIO_PIN_10
#define M0_S1_GPIO_Port 	GPIOC
#define M0_S2_Pin 			GPIO_PIN_11
#define M0_S2_GPIO_Port 	GPIOC
#define D_SET_Pin 			GPIO_PIN_0
#define D_SET_GPIO_Port 	GPIOD

/*
 * Analog Mux Selection Macro Definition
 */
/* Mux-1 Select Pin Macro Function */
#define M1_S0_SET()     HAL_GPIO_WritePin(M1_S0_GPIO_Port, M1_S0_Pin, GPIO_PIN_SET	)
#define M1_S0_RESET()   HAL_GPIO_WritePin(M1_S0_GPIO_Port, M1_S0_Pin, GPIO_PIN_RESET)
#define M1_S1_SET()     HAL_GPIO_WritePin(M1_S1_GPIO_Port, M1_S1_Pin, GPIO_PIN_SET	)
#define M1_S1_RESET()   HAL_GPIO_WritePin(M1_S1_GPIO_Port, M1_S1_Pin, GPIO_PIN_RESET)
#define M1_S2_SET()     HAL_GPIO_WritePin(M1_S2_GPIO_Port, M1_S2_Pin, GPIO_PIN_SET	)
#define M1_S2_RESET()   HAL_GPIO_WritePin(M1_S2_GPIO_Port, M1_S2_Pin, GPIO_PIN_RESET)
/* Mux-1 Channel Select Macro Function */
#define M1_A0_SET()    	M1_S2_RESET(); M1_S1_RESET(); M1_S0_RESET(); /* 000 */
#define M1_A1_SET()     M1_S2_RESET(); M1_S1_RESET(); M1_S0_SET();   /* 001 */
#define M1_A2_SET()     M1_S2_RESET(); M1_S1_SET();   M1_S0_RESET(); /* 010 */
#define M1_A3_SET()     M1_S2_RESET(); M1_S1_SET();   M1_S0_SET();   /* 011 */
#define M1_A4_SET()     M1_S2_SET();   M1_S1_RESET(); M1_S0_RESET(); /* 100 */
#define M1_A5_SET()     M1_S2_SET();   M1_S1_RESET(); M1_S0_SET();   /* 101 */
#define M1_A6_SET()     M1_S2_SET();   M1_S1_SET();   M1_S0_RESET(); /* 110 */
#define M1_A7_SET()     M1_S2_RESET(); M1_S1_RESET(); M1_S0_RESET(); /* 111 */
/* Mux-2 Select Pin Macro Function */
#define M2_S0_SET()     HAL_GPIO_WritePin(M2_S0_GPIO_Port, M2_S0_Pin, GPIO_PIN_SET	)
#define M2_S0_RESET()   HAL_GPIO_WritePin(M2_S0_GPIO_Port, M2_S0_Pin, GPIO_PIN_RESET)
#define M2_S1_SET()     HAL_GPIO_WritePin(M2_S1_GPIO_Port, M2_S1_Pin, GPIO_PIN_SET	)
#define M2_S1_RESET()   HAL_GPIO_WritePin(M2_S1_GPIO_Port, M2_S1_Pin, GPIO_PIN_RESET)
#define M2_S2_SET()     HAL_GPIO_WritePin(M2_S2_GPIO_Port, M2_S2_Pin, GPIO_PIN_SET	)
#define M2_S2_RESET()   HAL_GPIO_WritePin(M2_S2_GPIO_Port, M2_S2_Pin, GPIO_PIN_RESET)
/* Mux-2 Channel Select Macro Function */
#define M2_A0_SET()    	M2_S2_RESET(); M2_S1_RESET(); M2_S0_RESET(); /* 000 */
#define M2_A1_SET()     M2_S2_RESET(); M2_S1_RESET(); M2_S0_SET();   /* 001 */
#define M2_A2_SET()     M2_S2_RESET(); M2_S1_SET();   M2_S0_RESET(); /* 010 */
#define M2_A3_SET()     M2_S2_RESET(); M2_S1_SET();   M2_S0_SET();   /* 011 */
#define M2_A4_SET()     M2_S2_SET();   M2_S1_RESET(); M2_S0_RESET(); /* 100 */
#define M2_A5_SET()     M2_S2_SET();   M2_S1_RESET(); M2_S0_SET();   /* 101 */
#define M2_A6_SET()     M2_S2_SET();   M2_S1_SET();   M2_S0_RESET(); /* 110 */
#define M2_A7_SET()     M2_S2_RESET(); M2_S1_RESET(); M2_S0_RESET(); /* 111 */
/* Mux-3 Select Pin Macro Function */
#define M3_S0_SET()     HAL_GPIO_WritePin(M3_S0_GPIO_Port, M3_S0_Pin, GPIO_PIN_SET	)
#define M3_S0_RESET()   HAL_GPIO_WritePin(M3_S0_GPIO_Port, M3_S0_Pin, GPIO_PIN_RESET)
#define M3_S1_SET()     HAL_GPIO_WritePin(M3_S1_GPIO_Port, M3_S1_Pin, GPIO_PIN_SET	)
#define M3_S1_RESET()   HAL_GPIO_WritePin(M3_S1_GPIO_Port, M3_S1_Pin, GPIO_PIN_RESET)
#define M3_S2_SET()     HAL_GPIO_WritePin(M3_S2_GPIO_Port, M3_S2_Pin, GPIO_PIN_SET	)
#define M3_S2_RESET()   HAL_GPIO_WritePin(M3_S2_GPIO_Port, M3_S2_Pin, GPIO_PIN_RESET)
/* Mux-3 Channel Select Macro Function */
#define M3_A0_SET()    	M3_S2_RESET(); M3_S1_RESET(); M3_S0_RESET(); /* 000 */
#define M3_A1_SET()     M3_S2_RESET(); M3_S1_RESET(); M3_S0_SET();   /* 001 */
#define M3_A2_SET()     M3_S2_RESET(); M3_S1_SET();   M3_S0_RESET(); /* 010 */
#define M3_A3_SET()     M3_S2_RESET(); M3_S1_SET();   M3_S0_SET();   /* 011 */
#define M3_A4_SET()     M3_S2_SET();   M3_S1_RESET(); M3_S0_RESET(); /* 100 */
#define M3_A5_SET()     M3_S2_SET();   M3_S1_RESET(); M3_S0_SET();   /* 101 */
#define M3_A6_SET()     M3_S2_SET();   M3_S1_SET();   M3_S0_RESET(); /* 110 */
#define M3_A7_SET()     M3_S2_RESET(); M3_S1_RESET(); M3_S0_RESET(); /* 111 */

/*
 *  Adc Main State Machine
 */
typedef enum
{
	AdcModule_MAINState_INIT = 0,
	AdcModule_MAINState_IDLE 	 ,
	AdcModule_MAINState_ROUTINE ,
	AdcModule_MAINState_PROCESS ,
	AdcModule_MAINState_SUSPEND ,
}AdcModule_MAINState_Type;

/*
 * Adc Process event flags
 */
typedef union
{
	adc_uint8_t processFlags;
	struct
	{
		adc_bool_t temperatureRead 	: 1 ;
		adc_bool_t currentRead	   	: 1 ;
		adc_bool_t vbat_voltageRead	: 1 ;
		//
		adc_uint8_t dummy:5;
	}Flag;
}AdcModule_ProcessFlag_Type;

/*
 * Adc Process State Machine
 */
typedef enum
{
	AdcModule_PROCEState_TempRead 	= 0	,
	AdcModule_PROCEState_CurrentRead 	,
	AdcModule_PROCEState_VbatRead	 	,
	AdcModule_PROCEState_SUSPEND 		,
}AdcModule_PROCState_Type;


/*
 * Adc Module Object Class
 */
typedef struct
{

	adc_handleTypeDef	hadc			;
	adc_uint32_t		channel			;
	adc_uint32_t		rank			;
	adc_uint32_t		samplingTime	;

	adc_uint8_t			mux_id   		;
	adc_uint8_t			mux_select		;

}AdcModule_ObjType;

/*
 * Adc Module Ops Class
 */
typedef struct
{
	/* Main Private Methods */
	adc_err_t			(*INIT			   )(AdcModule_ObjType* self);
	adc_err_t			(*IDLE			   )(AdcModule_ObjType* self);
	adc_err_t			(*ROUTINE		   )(AdcModule_ObjType* self);
	adc_err_t			(*PROCESS		   )(AdcModule_ObjType* self);
	adc_err_t			(*SUSPEND 		   )(AdcModule_ObjType* self);
	/* Public Methods */
	adc_err_t			(*SetParam		   )(AdcModule_ObjType* self,  adc_uint32_t _channel , adc_uint32_t _rank , adc_uint32_t _samplingTime , adc_uint8_t _mux_id , adc_uint8_t _mux_select );
	AdcModule_ObjType	(*GetParam		   )(AdcModule_ObjType* self );
	adc_err_t			(*SetMux		   )(AdcModule_ObjType* self );
	adc_uint32_t		(*ReadVoltage	   )(AdcModule_ObjType* self , Bms_Cell_Type* cellParam );
	adc_uint32_t		(*ReadCurrent	   )(void);
	adc_uint32_t		(*ReadTemperature  )(void);
	adc_uint32_t		(*ReadVBat		   )(void);
	adc_uint32_t		(*ReadVRef		   )(void);

}AdcModule_OpsType;

/*
 * Adc Module Base Class
 */
typedef struct
{
	AdcModule_ObjType Obj;
	AdcModule_OpsType Ops;
}AdcModule_Type;

/*
 * Adc Base Class Constructor
 */
bms_err_t AdcModule_CTOR(AdcModule_Type* self, adc_handleTypeDef _hadc);

/*
 * Adc Main Function Prototypes
 */
static adc_err_t	AdcModule_INIT	 (AdcModule_ObjType* self);
static adc_err_t	AdcModule_IDLE	 (AdcModule_ObjType* self);
static adc_err_t	AdcModule_ROUTINE(AdcModule_ObjType* self);
static adc_err_t	AdcModule_PROCESS(AdcModule_ObjType* self);
static adc_err_t	AdcModule_SUSPEND(AdcModule_ObjType* self);


/*
 * Adc Module Main Function
 */
void  MainADC		(void);

/*
 * Adc Module Application Function Prototypes
 */
adc_err_t			AdcModule_SetParam			(AdcModule_ObjType* self, adc_uint32_t _channel , adc_uint32_t _rank , adc_uint32_t _samplingTime , adc_uint8_t _mux_id , adc_uint8_t _mux_select );
AdcModule_ObjType	AdcModule_GetParam			(AdcModule_ObjType* self );
adc_err_t			AdcModule_SetMux			(AdcModule_ObjType* self );
adc_uint32_t		AdcModule_ReadVoltage		(AdcModule_ObjType* self , Bms_Cell_Type* cellParam );
adc_uint32_t		AdcModule_ReadCurrent		(void);
adc_uint32_t		AdcModule_ReadTemperature	(void);
adc_uint32_t		AdcModule_ReadVBat			(void);
adc_uint32_t		AdcModule_ReadVRef			(void);

#endif /* ADCMODULE_INC_ADCMODULE_H_ */
