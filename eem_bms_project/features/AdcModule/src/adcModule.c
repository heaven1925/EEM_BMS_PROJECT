/*******************************************************************************
  * @file    adcModule.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/

#include "app.h"
#include "adcModule.h"

#define MAIN_ADC

/*
 * Main State Machine Exclusion
 */
extern 	State_Type 		 MAINstate;
extern	uint32_t 		 Clock;
/*
 * Cell Main Class
 */
extern 	Bms_Cell_Type Cell[BMS_CELL_SIZE];
extern	Bms_Main_Type Base;

/*
 * Adc Module Main State
 */
AdcModule_MAINState_Type 	AdcModule_MAINState = AdcModule_MAINState_INIT;

/*
 * Adc Module Process State
 */
AdcModule_PROCState_Type 	AdcModule_PROCState = AdcModule_PROCEState_SUSPEND;

/*
 * Adc Process State Flag
 */
AdcModule_ProcessFlag_Type  AdcProcess = {0} ;

/*
 * AdcModule Main Class
 */
AdcModule_Type AdcModule;

#if 1 /* Adc Module Application Function Definitions */

adc_err_t			AdcModule_SetParam		(AdcModule_ObjType* self,  adc_uint32_t _channel , adc_uint32_t _rank , adc_uint32_t _samplingTime , adc_uint8_t _mux_id , adc_uint8_t _mux_select )
{
	adc_err_t result = ADC_EOK;


	self->channel			= _channel		;
	if( self->channel != (  (ADC_CHANNEL_0)  || (ADC_CHANNEL_1)  || (ADC_CHANNEL_2) 	|| (ADC_CHANNEL_3) 	||
							(ADC_CHANNEL_4)  || (ADC_CHANNEL_5)  || (ADC_CHANNEL_6) 	|| (ADC_CHANNEL_7) 	||
							(ADC_CHANNEL_8)  || (ADC_CHANNEL_9)  || (ADC_CHANNEL_10) 	|| (ADC_CHANNEL_11) ||
							(ADC_CHANNEL_12) || (ADC_CHANNEL_13) || (ADC_CHANNEL_14) 	|| (ADC_CHANNEL_15) ||
							(ADC_CHANNEL_16) || (ADC_CHANNEL_17) || (ADC_CHANNEL_18) 	|| (ADC_CHANNEL_VREFINT) || (ADC_CHANNEL_VBAT) ) )
	{
		/* Check channel is valid channel */
		result = ADC_ERR ;
		return result;
	}

	self->rank				= _rank			;
	if( self->rank < 0 || self->rank > 18 )
	{
		/* Check rank is valid */
		result = ADC_ERR ;
		return result;
	}

	self->samplingTime		= _samplingTime	;
	if( self->samplingTime != (  (ADC_SAMPLETIME_3CYCLES) 	|| (ADC_SAMPLETIME_15CYCLES) || (ADC_SAMPLETIME_28CYCLES)  ||
			 	 	 	 	 	 (ADC_SAMPLETIME_56CYCLES) 	|| (ADC_SAMPLETIME_84CYCLES) || (ADC_SAMPLETIME_112CYCLES) ||
								 (ADC_SAMPLETIME_144CYCLES) || (ADC_SAMPLETIME_480CYCLES) ) )
	{
		/* Check sampling time is valid */
		result = ADC_ERR ;
		return result;
	}

	self->mux_id			= _mux_id		;
	if( self->mux_id != ( (BMS_MUX_ID1) || (BMS_MUX_ID2) || (BMS_MUX_ID3) ) )
	{
		/* Check mux select is valid */
		result = ADC_ERR ;
		return result;
	}

	self->mux_select		= _mux_select	;
	if( self->mux_select != (  (BMS_MUXSELECT_ANALOG0) || (BMS_MUXSELECT_ANALOG1) || (BMS_MUXSELECT_ANALOG2) ||
							   (BMS_MUXSELECT_ANALOG3) || (BMS_MUXSELECT_ANALOG4) || (BMS_MUXSELECT_ANALOG5) ||
							   (BMS_MUXSELECT_ANALOG6) || (BMS_MUXSELECT_ANALOG7) ) )
	{
		/* Check mux select is valid */
		result = ADC_ERR ;
		return result;
	}

	return result;
}

AdcModule_ObjType	AdcModule_GetParam		(AdcModule_ObjType* self )
{
	return *self;
}

adc_err_t			AdcModule_SetMux		(AdcModule_ObjType* self )
{
	adc_err_t result = ADC_EOK;

	switch(self->mux_id)
	{
	case BMS_MUX_ID1 :

		if		( ( self->mux_select & 0b00000000 ) == self->mux_select )
		{
			M1_A0_SET();
		}
		else if	( ( self->mux_select & 0b00000001 ) == self->mux_select)
		{
			M1_A1_SET();
		}
		else if	( ( self->mux_select & 0b00000010 ) == self->mux_select)
		{
			M1_A2_SET();
		}
		else if	( ( self->mux_select & 0b00000011 ) == self->mux_select)
		{
			M1_A3_SET();
		}
		else if	( ( self->mux_select & 0b00000100 ) == self->mux_select)
		{
			M1_A4_SET();
		}
		else if	( ( self->mux_select & 0b00000101 ) == self->mux_select)
		{
			M1_A5_SET();
		}
		else if	( ( self->mux_select & 0b00000110 ) == self->mux_select)
		{
			M1_A6_SET();
		}
		else if	( ( self->mux_select & 0b00000111 ) == self->mux_select)
		{
			M1_A7_SET();
		}
		else
		{
			return ADC_ERR;
		}

	break;
	case BMS_MUX_ID2 :

		if		( ( self->mux_select & 0b00000000 ) == self->mux_select )
		{
			M2_A0_SET();
		}
		else if	( ( self->mux_select & 0b00000001 ) == self->mux_select)
		{
			M2_A1_SET();
		}
		else if	( ( self->mux_select & 0b00000010 ) == self->mux_select)
		{
			M2_A2_SET();
		}
		else if	( ( self->mux_select & 0b00000011 ) == self->mux_select)
		{
			M2_A3_SET();
		}
		else if	( ( self->mux_select & 0b00000100 ) == self->mux_select)
		{
			M2_A4_SET();
		}
		else if	( ( self->mux_select & 0b00000101 ) == self->mux_select)
		{
			M2_A5_SET();
		}
		else if	( ( self->mux_select & 0b00000110 ) == self->mux_select)
		{
			M2_A6_SET();
		}
		else if	( ( self->mux_select & 0b00000111 ) == self->mux_select)
		{
			M2_A7_SET();
		}
		else
		{
			return ADC_ERR;
		}

	break;
	case BMS_MUX_ID3 :

		if		( ( self->mux_select & 0b00000000 ) == self->mux_select )
		{
			M3_A0_SET();
		}
		else if	( ( self->mux_select & 0b00000001 ) == self->mux_select)
		{
			M3_A1_SET();
		}
		else if	( ( self->mux_select & 0b00000010 ) == self->mux_select)
		{
			M3_A2_SET();
		}
		else if	( ( self->mux_select & 0b00000011 ) == self->mux_select)
		{
			M3_A3_SET();
		}
		else if	( ( self->mux_select & 0b00000100 ) == self->mux_select)
		{
			M3_A4_SET();
		}
		else if	( ( self->mux_select & 0b00000101 ) == self->mux_select)
		{
			M3_A5_SET();
		}
		else if	( ( self->mux_select & 0b00000110 ) == self->mux_select)
		{
			M3_A6_SET();
		}
		else if	( ( self->mux_select & 0b00000111 ) == self->mux_select)
		{
			M3_A7_SET();
		}
		else
		{
			return ADC_ERR;
		}

	break;

	default: result = ADC_ERR; break;
	}


	return result;
}

adc_uint32_t		AdcModule_ReadVoltage	(AdcModule_ObjType* self , Bms_Cell_Type* cellParam )
{
	adc_err_t 					result 			= ADC_EOK;
	adc_uint32_t 				rawDataHandle 	= 0;
	adc_channelConfigTypeDef	sConfig;

	/* Clear AdcModule Object before new read */
	memset( self , 0x00 , sizeof(AdcModule_ObjType) );

	result = AdcModule.Ops.SetParam( /* AdcModule_ObjType* self,     */ self 							,
			                         /* adc_uint32_t _channel ,      */ cellParam->adc_channel          ,
			                         /* adc_uint32_t _rank ,         */ cellParam->adc_rank             ,
			                         /* adc_uint32_t _samplingTime , */ cellParam->adc_samplingTime     ,
			                         /* adc_uint8_t _mux_id ,        */ cellParam->mux_id           	,
			                         /* adc_uint8_t _mux_select );   */ cellParam->mux_select       	);
	if(result != ADC_EOK) return -1;

	/* Seperate Channel */
	sConfig.Channel 	 = self->channel;
	sConfig.Rank		 = self->rank;
	sConfig.SamplingTime = self->samplingTime;
	if (HAL_ADC_ConfigChannel( &self->hadc , &sConfig) != HAL_OK)
	{
		return -1;
	}

	/* Set Multiplexer */
	result = AdcModule.Ops.SetMux(self);
	if(result != ADC_EOK) return -1;

	/* 74HC4051 Enable-Pin Always ground */

	/* 74HC4051 Select-Pin Maximum response time 90ns overcondutions            */
	HAL_Delay(1); //@BACK: ASM(NOP) ile 90ns ayarlanacak !

	HAL_ADC_Start(&self->hadc);
	HAL_ADC_PollForConversion(&self->hadc, 100);
	rawDataHandle = HAL_ADC_GetValue(&self->hadc);
	HAL_ADC_Stop(&self->hadc);

	return rawDataHandle;
}

adc_uint32_t		AdcModule_ReadCurrent	(void)
{
	adc_uint32_t 	rawCurrentHandle;

	adc_channelConfigTypeDef	sConfig;
	AdcModule_ObjType AdcModule_CurrentHandle =
	{
			.hadc 			= hadc1 							,
			.channel		= CURRENT_ADC_CHANNEL				,
			.rank			= CURRENT_ADC_RANK		            ,
			.samplingTime   = CURRENT_ADC_SAMPLINGTIME          ,
			.mux_id         = CURRENT_MUX_ID                    ,
			.mux_select     = CURRENT_MUX_SELECT_ID	            ,
	};

	/* Seperate Channel */
	sConfig.Channel 	 = AdcModule_CurrentHandle.channel;
	sConfig.Rank		 = AdcModule_CurrentHandle.rank;
	sConfig.SamplingTime = AdcModule_CurrentHandle.samplingTime;
	if (HAL_ADC_ConfigChannel( &AdcModule_CurrentHandle.hadc , &sConfig) != HAL_OK)
	{
		return -1;
	}

	/* Set Multiplexer */

	/* 74HC4051 Select-Pin Maximum response time 90ns overcondutions            */
	HAL_Delay(1); //@BACK: ASM(NOP) ile 90ns ayarlanacak !

	/* 74HC4051 Enable-Pin Always ground */

	/* Read Analog Value */
    HAL_ADC_Start(&AdcModule_CurrentHandle.hadc);
    HAL_ADC_PollForConversion(&AdcModule_CurrentHandle.hadc, 100);
    rawCurrentHandle = HAL_ADC_GetValue(&AdcModule_CurrentHandle.hadc);
    HAL_ADC_Stop(&AdcModule_CurrentHandle.hadc);

    return rawCurrentHandle;

}

adc_uint32_t		AdcModule_ReadTemperature(void)
{
	adc_uint32_t 	rawTempHandle;

	adc_channelConfigTypeDef	sConfig;
	AdcModule_ObjType AdcModule_TemperatureHandle =
	{
			.hadc 			= hadc1 							,
			.channel		= TEMPERATURE_ADC_CHANNEL			,
			.rank			= TEMPERATURE_ADC_RANK		        ,
			.samplingTime   = TEMPERATURE_ADC_SAMPLINGTIME      ,
			.mux_id         = TEMPERATURE_MUX_ID                ,
			.mux_select     = TEMPERATURE_MUX_SELECT_ID	        ,

	};

	/* Seperate Channel */
	sConfig.Channel 	 = AdcModule_TemperatureHandle.channel;
	sConfig.Rank		 = AdcModule_TemperatureHandle.rank;
	sConfig.SamplingTime = AdcModule_TemperatureHandle.samplingTime;
	if (HAL_ADC_ConfigChannel( &AdcModule_TemperatureHandle.hadc , &sConfig) != HAL_OK)
	{
		return -1;
	}

	/* Set Multiplexer */

	/* 74HC4051 Select-Pin Maximum response time 90ns overcondutions            */
	HAL_Delay(1); //@BACK: ASM(NOP) ile 90ns ayarlanacak !

	/* 74HC4051 Enable-Pin Always ground */

	/* Read Analog Value */
    HAL_ADC_Start(&AdcModule_TemperatureHandle.hadc);
    HAL_ADC_PollForConversion(&AdcModule_TemperatureHandle.hadc, 100);
    rawTempHandle = HAL_ADC_GetValue(&AdcModule_TemperatureHandle.hadc);
    HAL_ADC_Stop(&AdcModule_TemperatureHandle.hadc);

    return rawTempHandle;
}

adc_uint32_t		AdcModule_ReadVBat		(void)
{
	adc_uint32_t 	rawVBatHandle;

	adc_channelConfigTypeDef	sConfig;
	AdcModule_ObjType AdcModule_VbatHandle =
	{
			.hadc 			= hadc1 							,
			.channel		= VBAT_ADC_CHANNEL			        ,
			.rank			= VBAT_ADC_RANK		                ,
			.samplingTime   = VBAT_ADC_SAMPLINGTIME
	};

	/* Seperate Channel */
	sConfig.Channel 	 = AdcModule_VbatHandle.channel;
	sConfig.Rank		 = AdcModule_VbatHandle.rank;
	sConfig.SamplingTime = AdcModule_VbatHandle.samplingTime;
	if (HAL_ADC_ConfigChannel( &AdcModule_VbatHandle.hadc , &sConfig) != HAL_OK)
	{
		return -1;
	}

	/* No multiplexer for Vbat Voltage */

	/* 74HC4051 Select-Pin Maximum response time 90ns overcondutions            */
	HAL_Delay(1); //@BACK: ASM(NOP) ile 90ns ayarlanacak !

	/* 74HC4051 Enable-Pin Always ground */

	/* Read Analog Value */
    HAL_ADC_Start(&AdcModule_VbatHandle.hadc);
    HAL_ADC_PollForConversion(&AdcModule_VbatHandle.hadc, 100);
    rawVBatHandle = HAL_ADC_GetValue(&AdcModule_VbatHandle.hadc);
    HAL_ADC_Stop(&AdcModule_VbatHandle.hadc);

    return rawVBatHandle;
}

adc_uint32_t		AdcModule_ReadVRef		(void)
{
	adc_uint32_t 	rawVRefHandle;

	adc_channelConfigTypeDef	sConfig;
	AdcModule_ObjType AdcModule_VrefHandle =
	{
			.hadc 			= hadc1 							,
			.channel		= VREF_ADC_CHANNEL			        ,
			.rank			= VREF_ADC_RANK		                ,
			.samplingTime   = VREF_ADC_SAMPLINGTIME
	};

	/* Seperate Channel */
	sConfig.Channel 	 = AdcModule_VrefHandle.channel;
	sConfig.Rank		 = AdcModule_VrefHandle.rank;
	sConfig.SamplingTime = AdcModule_VrefHandle.samplingTime;
	if (HAL_ADC_ConfigChannel( &AdcModule_VrefHandle.hadc , &sConfig) != HAL_OK)
	{
		return -1;
	}

	/* No multiplexer for Vbat Voltage */

	/* 74HC4051 Select-Pin Maximum response time 90ns overcondutions            */
	HAL_Delay(1); //@BACK: ASM(NOP) ile 90ns ayarlanacak !

	/* 74HC4051 Enable-Pin Always ground */

	/* Read Analog Value */
    HAL_ADC_Start(&AdcModule_VrefHandle.hadc);
    HAL_ADC_PollForConversion(&AdcModule_VrefHandle.hadc, 100);
    rawVRefHandle = HAL_ADC_GetValue(&AdcModule_VrefHandle.hadc);
    HAL_ADC_Stop(&AdcModule_VrefHandle.hadc);

    return rawVRefHandle;
}


#endif



#ifdef MAIN_ADC

bms_err_t AdcModule_CTOR(AdcModule_Type* self , adc_handleTypeDef _hadc )
{
	bms_err_t 	 result 		= BMS_EOK;
	bms_uint32_t addrHandle		= 0;

	assert(self != NULL);

	/* Virtual pointer Assignment */
	static AdcModule_OpsType Vptr =
	{
			/* Private Function Indication */
			AdcModule_INIT    	,
			AdcModule_IDLE 	  	,
			AdcModule_ROUTINE 	,
			AdcModule_PROCESS 	,
			AdcModule_SUSPEND 	,
			/* Private Method Indication */
			AdcModule_SetParam			,
			AdcModule_GetParam			,
			AdcModule_SetMux			,
			AdcModule_ReadVoltage		,
			AdcModule_ReadCurrent		,
			AdcModule_ReadTemperature	,
			AdcModule_ReadVBat			,
			AdcModule_ReadVRef
	};
	self->Ops = Vptr ;

	/* Check functions has on flash addr space */
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&self->Ops.INIT);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&self->Ops.IDLE);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&self->Ops.ROUTINE);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&self->Ops.PROCESS);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&self->Ops.SUSPEND);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;

	/* Check Adc handle avaible in RAM Section */
	self->Obj.hadc = _hadc;
	addrHandle = (bms_uint32_t)((bms_uint32_t*)&self->Obj.hadc);
	if( (addrHandle & 0x80000000) == 0 ) return BMS_ERR;


	return result;
}

static adc_err_t	AdcModule_INIT(AdcModule_ObjType* param)
{
	adc_err_t result = ADC_EOK;

	assert(param != NULL);

	/* Adc Module Construct */
	if( AdcModule_CTOR(&AdcModule, hadc1) != BMS_EOK )
	{
		result = ADC_ERR;
	}

	/* Go to balance state for init and reset time base*/
	MAINstate = STATE_BALANCE;
	Clock	  = 0;

	/* Set Adc State Machine to IDLE */
	AdcModule_MAINState = AdcModule_MAINState_IDLE;


	return result;
}

static adc_err_t	AdcModule_IDLE(AdcModule_ObjType* param)
{
	adc_err_t result = ADC_EOK;

	assert(param != NULL);

	//@LATER: Kalman filtresi ile ilgili ayar gelebilir.

	/* Set Adc State Machine to Routine */
	AdcModule_MAINState = AdcModule_MAINState_ROUTINE;

	return result;
}

static adc_err_t	AdcModule_ROUTINE(AdcModule_ObjType* param)
{
	adc_err_t result = ADC_EOK;

	assert(param != NULL);

	/* Adc Routine Always Read Vref Voltage in order built real forms */
	Base.raw_vref_voltage = AdcModule.Ops.ReadVRef();
	//@LATER: read real form of referance voltage

	/* Adc Routine Always Read Cell Voltages */
	for( adc_uint8_t cell_loop = BMS_CELL_01 ; cell_loop != BMS_LAST_CELL ; cell_loop++ )
	{
		Cell[cell_loop].raw_cell_voltage = AdcModule.Ops.ReadVoltage( &AdcModule.Obj , &Cell[cell_loop]);
		//@LATER: read real form of cell voltage
	}

	/* Adc Routine sense Current each 10ms */
	if( ADC_TRUE == AdcProcess.Flag.currentRead )
	{
		AdcModule_MAINState = AdcModule_MAINState_PROCESS;
		AdcModule_PROCState = AdcModule_PROCEState_CurrentRead;
	}
	/* Adc Routine sense Vbat each 100ms 	 	*/
	else if( ADC_TRUE == AdcProcess.Flag.vbat_voltageRead )
	{
		AdcModule_MAINState = AdcModule_MAINState_PROCESS;
		AdcModule_PROCState = AdcModule_PROCEState_VbatRead;
	}
	/* Adc Routine sense Temperature each 200ms */
	else if( ADC_TRUE == AdcProcess.Flag.temperatureRead )
	{
		AdcModule_MAINState = AdcModule_MAINState_PROCESS;
		AdcModule_PROCState = AdcModule_PROCEState_TempRead;
	}
	else
	{
		AdcModule_MAINState = AdcModule_MAINState_ROUTINE;  /* Keep Routine */
		AdcModule_PROCState = AdcModule_PROCEState_SUSPEND; /* Keep Suspend */
	}

	return result;
}

static adc_err_t	AdcModule_PROCESS(AdcModule_ObjType* param)
{
	adc_err_t result = ADC_EOK;

	assert(param != NULL);

	switch(AdcModule_PROCState)
	{
		case AdcModule_PROCEState_TempRead :

			Base.raw_cell_temperature = AdcModule.Ops.ReadTemperature();
			//@LATER: read real form of temperature
			AdcModule_PROCState = AdcModule_PROCEState_SUSPEND;

		break;

		case AdcModule_PROCEState_CurrentRead :

			Base.raw_line_current = AdcModule.Ops.ReadCurrent();
			//@LATER: read real form of current
			AdcModule_PROCState = AdcModule_PROCEState_SUSPEND;

		break;

		case AdcModule_PROCEState_VbatRead :

			Base.raw_vbat_voltage = AdcModule.Ops.ReadVBat();
			//@LATER: read real form of vbat
			AdcModule_PROCState = AdcModule_PROCEState_SUSPEND;

		break;

		case AdcModule_PROCEState_SUSPEND :

			/* Process done return routine */
			AdcModule_MAINState = AdcModule_MAINState_IDLE;

		break;

		/* Error State Operations */
		default: result = ADC_ERR; break;

	}

	return result;
}

static adc_err_t	AdcModule_SUSPEND(AdcModule_ObjType* param)
{
	adc_err_t result = ADC_EOK;

	assert(param != NULL);

	/* Clear Adc Instance */
	memset( &AdcModule.Obj , 0x00 , sizeof(AdcModule_ObjType) );

	AdcModule_MAINState = AdcModule_MAINState_IDLE;

	return result;
}

void MainADC(void)
{
	adc_err_t result = ADC_EOK;

	switch(AdcModule_MAINState)
	{
		/* Init State Operations */
		case AdcModule_MAINState_INIT	 : result = AdcModule.Ops.INIT(&AdcModule.Obj);
			break;
		/* Idle State Operations */
		case AdcModule_MAINState_IDLE	 : result = AdcModule.Ops.IDLE(&AdcModule.Obj);
			break;
		/* Routine State Operations */
		case AdcModule_MAINState_ROUTINE: result = AdcModule.Ops.ROUTINE(&AdcModule.Obj);
			break;
		/* Process State Operations */
		case AdcModule_MAINState_PROCESS: result = AdcModule.Ops.PROCESS(&AdcModule.Obj);
			break;
		/* Suspend State Operations */
		case AdcModule_MAINState_SUSPEND: result = AdcModule.Ops.SUSPEND(&AdcModule.Obj);
			break;

		/* Error State Operations */
		default: result = ADC_ERR; break;
	}

	if( result != ADC_EOK) for(;;); /* Infinite Loop until WDT Reset */

}
#endif
