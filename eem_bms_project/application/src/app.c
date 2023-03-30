/*******************************************************************************
  * @file    app.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/

#include "app.h"
#include "main.h"

/*
 * PCA Led Driver Init
 */
#include "_Pca9552_Led_Driver.h"


/*
 * EEM CAN Stack Init
 */
#include "EEMProtocol.h"
#include "EEMProtocol_Config.h"

#include "debug.h"
#if defined(BSP_DEBUG_MSG)
DEBUG_Type _DEBUG =
{	/* Const Variable Definition */
	.obj.DEBUG_CONSTS = { "RUN" , "IDLE" , "ROUT" , "PROC", "SUSP" , "ERR" , "EOK" , "END" }
};
#endif

#include "bmsConfig.h"
Bms_Cell_Type Cell[BMS_CELL_SIZE] =
{
		/* Cell-1 Default Configurations */
		[BMS_CELL_01].can_pgn				  = CELL01_CAN_PGN                  ,
		[BMS_CELL_01].can_spn				  = CELL01_CAN_SPN                  ,
		[BMS_CELL_01].led_driver_id			  = CELL01_LED_DRIVER_ID 	        ,
		[BMS_CELL_01].led_id                  = CELL01_LED_ID                   ,
		[BMS_CELL_01].adc_channel		      = CELL01_ADC_CHANNEL		        ,
		[BMS_CELL_01].adc_rank	              = CELL01_ADC_RANK		            ,
		[BMS_CELL_01].adc_samplingTime	      = CELL01_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_01].mux_id                  = CELL01_MUX_ID                   ,
		[BMS_CELL_01].mux_select			  = CELL01_MUX_SELECT_ID	        ,
		[BMS_CELL_01].balance_port_id		  = CELL01_BALANCE_PORT		        ,
		[BMS_CELL_01].balance_pin_id          = CELL01_BALANCE_PIN		        ,
		[BMS_CELL_01].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_01].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_01].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-2 Default Configurations */
		[BMS_CELL_02].can_pgn				  = CELL02_CAN_PGN                  ,
		[BMS_CELL_02].can_spn				  = CELL02_CAN_SPN                  ,
		[BMS_CELL_02].led_driver_id			  = CELL02_LED_DRIVER_ID 	        ,
		[BMS_CELL_02].led_id                  = CELL02_LED_ID                   ,
		[BMS_CELL_02].adc_channel		      = CELL02_ADC_CHANNEL		        ,
		[BMS_CELL_02].adc_rank	              = CELL02_ADC_RANK		            ,
		[BMS_CELL_02].adc_samplingTime	      = CELL02_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_02].mux_id                  = CELL02_MUX_ID                   ,
		[BMS_CELL_02].mux_select			  = CELL02_MUX_SELECT_ID	        ,
		[BMS_CELL_02].balance_port_id		  = CELL02_BALANCE_PORT		        ,
		[BMS_CELL_02].balance_pin_id          = CELL02_BALANCE_PIN		        ,
		[BMS_CELL_02].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_02].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_02].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-3 Default Configurations */
		[BMS_CELL_03].can_pgn				  = CELL03_CAN_PGN               	,
		[BMS_CELL_03].can_spn				  = CELL03_CAN_SPN               	,
		[BMS_CELL_03].led_driver_id			  = CELL03_LED_DRIVER_ID 	     	,
		[BMS_CELL_03].led_id                  = CELL03_LED_ID                	,
		[BMS_CELL_03].adc_channel		      = CELL03_ADC_CHANNEL		        ,
		[BMS_CELL_03].adc_rank	              = CELL03_ADC_RANK		            ,
		[BMS_CELL_03].adc_samplingTime	      = CELL03_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_03].mux_id                  = CELL03_MUX_ID                	,
		[BMS_CELL_03].mux_select			  = CELL03_MUX_SELECT_ID	     	,
		[BMS_CELL_03].balance_port_id		  = CELL03_BALANCE_PORT		     	,
		[BMS_CELL_03].balance_pin_id          = CELL03_BALANCE_PIN		     	,
		[BMS_CELL_03].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_03].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_03].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-4 Default Configurations */
		[BMS_CELL_04].can_pgn				  = CELL04_CAN_PGN              	,
		[BMS_CELL_04].can_spn				  = CELL04_CAN_SPN              	,
		[BMS_CELL_04].led_driver_id			  = CELL04_LED_DRIVER_ID 	    	,
		[BMS_CELL_04].led_id                  = CELL04_LED_ID               	,
		[BMS_CELL_04].adc_channel		      = CELL04_ADC_CHANNEL		        ,
		[BMS_CELL_04].adc_rank	              = CELL04_ADC_RANK		            ,
		[BMS_CELL_04].adc_samplingTime	      = CELL04_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_04].mux_id                  = CELL04_MUX_ID               	,
		[BMS_CELL_04].mux_select			  = CELL04_MUX_SELECT_ID	    	,
		[BMS_CELL_04].balance_port_id		  = CELL04_BALANCE_PORT		    	,
		[BMS_CELL_04].balance_pin_id          = CELL04_BALANCE_PIN		    	,
		[BMS_CELL_04].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_04].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_04].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-5 Default Configurations */
		[BMS_CELL_05].can_pgn				  = CELL05_CAN_PGN               	,
		[BMS_CELL_05].can_spn				  = CELL05_CAN_SPN               	,
		[BMS_CELL_05].led_driver_id			  = CELL05_LED_DRIVER_ID 	     	,
		[BMS_CELL_05].led_id                  = CELL05_LED_ID                	,
		[BMS_CELL_05].adc_channel		      = CELL05_ADC_CHANNEL		        ,
		[BMS_CELL_05].adc_rank	              = CELL05_ADC_RANK		            ,
		[BMS_CELL_05].adc_samplingTime	      = CELL05_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_05].mux_id                  = CELL05_MUX_ID                	,
		[BMS_CELL_05].mux_select			  = CELL05_MUX_SELECT_ID	     	,
		[BMS_CELL_05].balance_port_id		  = CELL05_BALANCE_PORT		     	,
		[BMS_CELL_05].balance_pin_id          = CELL05_BALANCE_PIN		     	,
		[BMS_CELL_05].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_05].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_05].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-6 Default Configurations */
		[BMS_CELL_06].can_pgn				  = CELL06_CAN_PGN              	,
		[BMS_CELL_06].can_spn				  = CELL06_CAN_SPN              	,
		[BMS_CELL_06].led_driver_id			  = CELL06_LED_DRIVER_ID 	    	,
		[BMS_CELL_06].led_id                  = CELL06_LED_ID               	,
		[BMS_CELL_06].adc_channel		      = CELL06_ADC_CHANNEL		        ,
		[BMS_CELL_06].adc_rank	              = CELL06_ADC_RANK		            ,
		[BMS_CELL_06].adc_samplingTime	      = CELL06_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_06].mux_id                  = CELL06_MUX_ID               	,
		[BMS_CELL_06].mux_select			  = CELL06_MUX_SELECT_ID	    	,
		[BMS_CELL_06].balance_port_id		  = CELL06_BALANCE_PORT		    	,
		[BMS_CELL_06].balance_pin_id          = CELL06_BALANCE_PIN		    	,
		[BMS_CELL_06].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_06].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_06].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-7 Default Configurations */
		[BMS_CELL_07].can_pgn				  = CELL07_CAN_PGN              	,
		[BMS_CELL_07].can_spn				  = CELL07_CAN_SPN              	,
		[BMS_CELL_07].led_driver_id			  = CELL07_LED_DRIVER_ID 			,
		[BMS_CELL_07].led_id                  = CELL07_LED_ID               	,
		[BMS_CELL_07].adc_channel		      = CELL07_ADC_CHANNEL		        ,
		[BMS_CELL_07].adc_rank	              = CELL07_ADC_RANK		            ,
		[BMS_CELL_07].adc_samplingTime	      = CELL07_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_07].mux_id                  = CELL07_MUX_ID               	,
		[BMS_CELL_07].mux_select			  = CELL07_MUX_SELECT_ID			,
		[BMS_CELL_07].balance_port_id		  = CELL07_BALANCE_PORT				,
		[BMS_CELL_07].balance_pin_id          = CELL07_BALANCE_PIN				,
		[BMS_CELL_07].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_07].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_07].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-8 Default Configurations */
		[BMS_CELL_08].can_pgn				  = CELL08_CAN_PGN              	,
		[BMS_CELL_08].can_spn				  = CELL08_CAN_SPN              	,
		[BMS_CELL_08].led_driver_id			  = CELL08_LED_DRIVER_ID 	    	,
		[BMS_CELL_08].led_id                  = CELL08_LED_ID               	,
		[BMS_CELL_08].adc_channel		      = CELL08_ADC_CHANNEL		        ,
		[BMS_CELL_08].adc_rank	              = CELL08_ADC_RANK		            ,
		[BMS_CELL_08].adc_samplingTime	      = CELL08_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_08].mux_id                  = CELL08_MUX_ID               	,
		[BMS_CELL_08].mux_select			  = CELL08_MUX_SELECT_ID	    	,
		[BMS_CELL_08].balance_port_id		  = CELL08_BALANCE_PORT		    	,
		[BMS_CELL_08].balance_pin_id          = CELL08_BALANCE_PIN		    	,
		[BMS_CELL_08].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_08].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_08].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-9 Default Configurations */
		[BMS_CELL_09].can_pgn				  = CELL09_CAN_PGN          	    ,
		[BMS_CELL_09].can_spn				  = CELL09_CAN_SPN          	    ,
		[BMS_CELL_09].led_driver_id			  = CELL09_LED_DRIVER_ID 		    ,
		[BMS_CELL_09].led_id                  = CELL09_LED_ID           	    ,
		[BMS_CELL_09].adc_channel		      = CELL09_ADC_CHANNEL		        ,
		[BMS_CELL_09].adc_rank	              = CELL09_ADC_RANK		            ,
		[BMS_CELL_09].adc_samplingTime	      = CELL09_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_09].mux_id                  = CELL09_MUX_ID           	    ,
		[BMS_CELL_09].mux_select			  = CELL09_MUX_SELECT_ID		    ,
		[BMS_CELL_09].balance_port_id		  = CELL09_BALANCE_PORT			    ,
		[BMS_CELL_09].balance_pin_id          = CELL09_BALANCE_PIN			    ,
		[BMS_CELL_09].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_09].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_09].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-10 Default Configurations */
		[BMS_CELL_10].can_pgn				  = CELL10_CAN_PGN              	,
		[BMS_CELL_10].can_spn				  = CELL10_CAN_SPN              	,
		[BMS_CELL_10].led_driver_id			  = CELL10_LED_DRIVER_ID 	    	,
		[BMS_CELL_10].led_id                  = CELL10_LED_ID               	,
		[BMS_CELL_10].adc_channel		      = CELL10_ADC_CHANNEL		        ,
		[BMS_CELL_10].adc_rank	              = CELL10_ADC_RANK		            ,
		[BMS_CELL_10].adc_samplingTime	      = CELL10_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_10].mux_id                  = CELL10_MUX_ID               	,
		[BMS_CELL_10].mux_select			  = CELL10_MUX_SELECT_ID	    	,
		[BMS_CELL_10].balance_port_id		  = CELL10_BALANCE_PORT		    	,
		[BMS_CELL_10].balance_pin_id          = CELL10_BALANCE_PIN		    	,
		[BMS_CELL_10].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_10].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_10].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-11 Default Configurations */
		[BMS_CELL_11].can_pgn				  = CELL11_CAN_PGN              	,
		[BMS_CELL_11].can_spn				  = CELL11_CAN_SPN              	,
		[BMS_CELL_11].led_driver_id			  = CELL11_LED_DRIVER_ID 	    	,
		[BMS_CELL_11].led_id                  = CELL11_LED_ID               	,
		[BMS_CELL_11].adc_channel		      = CELL11_ADC_CHANNEL		        ,
		[BMS_CELL_11].adc_rank	              = CELL11_ADC_RANK		            ,
		[BMS_CELL_11].adc_samplingTime	      = CELL11_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_11].mux_id                  = CELL11_MUX_ID               	,
		[BMS_CELL_11].mux_select			  = CELL11_MUX_SELECT_ID	    	,
		[BMS_CELL_11].balance_port_id		  = CELL11_BALANCE_PORT		    	,
		[BMS_CELL_11].balance_pin_id          = CELL11_BALANCE_PIN		    	,
		[BMS_CELL_11].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_11].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_11].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-12 Default Configurations */
		[BMS_CELL_12].can_pgn				  = CELL12_CAN_PGN              	,
		[BMS_CELL_12].can_spn				  = CELL12_CAN_SPN              	,
		[BMS_CELL_12].led_driver_id			  = CELL12_LED_DRIVER_ID 			,
		[BMS_CELL_12].led_id                  = CELL12_LED_ID               	,
		[BMS_CELL_12].adc_channel		      = CELL12_ADC_CHANNEL		        ,
		[BMS_CELL_12].adc_rank	              = CELL12_ADC_RANK		            ,
		[BMS_CELL_12].adc_samplingTime	      = CELL12_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_12].mux_id                  = CELL12_MUX_ID               	,
		[BMS_CELL_12].mux_select			  = CELL12_MUX_SELECT_ID			,
		[BMS_CELL_12].balance_port_id		  = CELL12_BALANCE_PORT				,
		[BMS_CELL_12].balance_pin_id          = CELL12_BALANCE_PIN				,
		[BMS_CELL_12].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_12].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_12].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-13 Default Configurations */
		[BMS_CELL_13].can_pgn				  = CELL13_CAN_PGN              	,
		[BMS_CELL_13].can_spn				  = CELL13_CAN_SPN              	,
		[BMS_CELL_13].led_driver_id			  = CELL13_LED_DRIVER_ID 	    	,
		[BMS_CELL_13].led_id                  = CELL13_LED_ID               	,
		[BMS_CELL_13].adc_channel		      = CELL13_ADC_CHANNEL		        ,
		[BMS_CELL_13].adc_rank	              = CELL13_ADC_RANK		            ,
		[BMS_CELL_13].adc_samplingTime	      = CELL13_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_13].mux_id                  = CELL13_MUX_ID               	,
		[BMS_CELL_13].mux_select			  = CELL13_MUX_SELECT_ID	    	,
		[BMS_CELL_13].balance_port_id		  = CELL13_BALANCE_PORT		    	,
		[BMS_CELL_13].balance_pin_id          = CELL13_BALANCE_PIN		    	,
		[BMS_CELL_13].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_13].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_13].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-14 Default Configurations */
		[BMS_CELL_14].can_pgn				  = CELL14_CAN_PGN              	,
		[BMS_CELL_14].can_spn				  = CELL14_CAN_SPN              	,
		[BMS_CELL_14].led_driver_id			  = CELL14_LED_DRIVER_ID 	    	,
		[BMS_CELL_14].led_id                  = CELL14_LED_ID               	,
		[BMS_CELL_14].adc_channel		      = CELL14_ADC_CHANNEL		        ,
		[BMS_CELL_14].adc_rank	              = CELL14_ADC_RANK		            ,
		[BMS_CELL_14].adc_samplingTime	      = CELL14_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_14].mux_id                  = CELL14_MUX_ID               	,
		[BMS_CELL_14].mux_select			  = CELL14_MUX_SELECT_ID	    	,
		[BMS_CELL_14].balance_port_id		  = CELL14_BALANCE_PORT		    	,
		[BMS_CELL_14].balance_pin_id          = CELL14_BALANCE_PIN		     	,
		[BMS_CELL_14].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_14].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_14].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-15 Default Configurations */
		[BMS_CELL_15].can_pgn				  = CELL15_CAN_PGN          		,
		[BMS_CELL_15].can_spn				  = CELL15_CAN_SPN          		,
		[BMS_CELL_15].led_driver_id			  = CELL15_LED_DRIVER_ID 			,
		[BMS_CELL_15].led_id                  = CELL15_LED_ID           		,
		[BMS_CELL_15].adc_channel		      = CELL15_ADC_CHANNEL		        ,
		[BMS_CELL_15].adc_rank	              = CELL15_ADC_RANK		            ,
		[BMS_CELL_15].adc_samplingTime	      = CELL15_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_15].mux_id                  = CELL15_MUX_ID           		,
		[BMS_CELL_15].mux_select			  = CELL15_MUX_SELECT_ID			,
		[BMS_CELL_15].balance_port_id		  = CELL15_BALANCE_PORT				,
		[BMS_CELL_15].balance_pin_id          = CELL15_BALANCE_PIN				,
		[BMS_CELL_15].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_15].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_15].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-16 Default Configurations */
		[BMS_CELL_16].can_pgn				  = CELL16_CAN_PGN              	,
		[BMS_CELL_16].can_spn				  = CELL16_CAN_SPN              	,
		[BMS_CELL_16].led_driver_id			  = CELL16_LED_DRIVER_ID 	    	,
		[BMS_CELL_16].led_id                  = CELL16_LED_ID               	,
		[BMS_CELL_16].adc_channel		      = CELL16_ADC_CHANNEL		        ,
		[BMS_CELL_16].adc_rank	              = CELL16_ADC_RANK		            ,
		[BMS_CELL_16].adc_samplingTime	      = CELL16_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_16].mux_id                  = CELL16_MUX_ID               	,
		[BMS_CELL_16].mux_select			  = CELL16_MUX_SELECT_ID	    	,
		[BMS_CELL_16].balance_port_id		  = CELL16_BALANCE_PORT		    	,
		[BMS_CELL_16].balance_pin_id          = CELL16_BALANCE_PIN		    	,
		[BMS_CELL_16].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_16].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_16].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-17 Default Configurations */
		[BMS_CELL_17].can_pgn				  = CELL17_CAN_PGN              	,
		[BMS_CELL_17].can_spn				  = CELL17_CAN_SPN              	,
		[BMS_CELL_17].led_driver_id			  = CELL17_LED_DRIVER_ID 	    	,
		[BMS_CELL_17].led_id                  = CELL17_LED_ID               	,
		[BMS_CELL_17].adc_channel		      = CELL17_ADC_CHANNEL		        ,
		[BMS_CELL_17].adc_rank	              = CELL17_ADC_RANK		            ,
		[BMS_CELL_17].adc_samplingTime	      = CELL17_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_17].mux_id                  = CELL17_MUX_ID               	,
		[BMS_CELL_17].mux_select			  = CELL17_MUX_SELECT_ID	    	,
		[BMS_CELL_17].balance_port_id		  = CELL17_BALANCE_PORT		    	,
		[BMS_CELL_17].balance_pin_id          = CELL17_BALANCE_PIN		    	,
		[BMS_CELL_17].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_17].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_17].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE      	,
		/* Cell-18 Default Configurations */
		[BMS_CELL_18].can_pgn				  = CELL18_CAN_PGN              	,
		[BMS_CELL_18].can_spn				  = CELL18_CAN_SPN              	,
		[BMS_CELL_18].led_driver_id			  = CELL18_LED_DRIVER_ID        	,
		[BMS_CELL_18].led_id                  = CELL18_LED_ID               	,
		[BMS_CELL_18].adc_channel		      = CELL18_ADC_CHANNEL		        ,
		[BMS_CELL_18].adc_rank	              = CELL18_ADC_RANK		            ,
		[BMS_CELL_18].adc_samplingTime	      = CELL18_ADC_SAMPLINGTIME	        ,
		[BMS_CELL_18].mux_id                  = CELL18_MUX_ID               	,
		[BMS_CELL_18].mux_select			  = CELL18_MUX_SELECT_ID        	,
		[BMS_CELL_18].balance_port_id		  = CELL18_BALANCE_PORT	        	,
		[BMS_CELL_18].balance_pin_id          = CELL18_BALANCE_PIN	        	,
		[BMS_CELL_18].raw_cell_voltage        = DEFAULT_RAW_CELL_VOLTAGE		,
		[BMS_CELL_18].voltage                 = DEFAULT_CELL_VOLTAGE           	,
		[BMS_CELL_18].balance_pin_state       = DEFAULT_BALANCE_PIN_STATE
};

Bms_Main_Type Base =
{
		.raw_cell_temperature 	= DEFAULT_RAW_TEMPERATURE		,
		.temperature			= DEFAULT_TEMPERATURE			,
		.raw_line_current		= DEFAULT_RAW_LINE_CURRENT		,
		.current				= DEFAULT_LINE_CURRENT			,
		.raw_vbat_voltage		= DEFAULT_RAW_VBAT_VOLTAGE		,
		.vbat_voltage			= DEFAULT_VBAT_VOLTAGE			,
		.raw_vref_voltage		= DEFAULT_RAW_VREF_VOLTAGE		,
		.vref_voltage			= DEFAULT_VREF_VOLTAGE
};


uint32_t Clock; /* Or RTC etc. */

static StateTime_Type 	 time_adc;
static StateTime_Type 	 time_balance;
static StateTime_Type 	 time_can;

State_Type 		 MAINstate;

StatusFlag_Type  MAINstatus;

/*
* Local Function Definitions
*/
static void 	StateADC_MAIN	 ( MainState_Type const * const param );
static void 	StateBALANCE_MAIN( MainState_Type const * const param );
static void 	StateCAN_MAIN	 ( MainState_Type const * const param );

/*
* Main State Machine Object
*/
MainState_Type MAIN_StateMachine;

/*
* State Table Virtual Pointer Initialize
*/
static void (*stateTable[])(MainState_Type* const modules[]) =
{
	System_StateADC_MAIN 	 ,
	System_StateBALANCE_MAIN ,
	System_StateCAN_MAIN
};

/*
* State Functions from different modules
*/
MainState_Type* const sys_modules[] =
{
	 &MAIN_StateMachine
};


void MainState_CTOR( MainState_Type* const param )
{

	/* Initial Virtual Table */
	static const struct OpsVTable vTable =
	{
		&StateADC_MAIN,
		&StateBALANCE_MAIN,
		&StateCAN_MAIN
	};

	param->vptr = &vTable;

#if defined(BSP_DEBUG_MSG)
	System_StateDEBUG_CTOR(&_DEBUG, huart5);
#endif

}


void	System_StateADC_MAIN( MainState_Type* const modules[] )
{
	MainState_RunA_Vcall( modules[ STATE_ADC_MAIN ] );

	/*

	If any child added State-A

	for( uint8_t loopVal = 0 ; modules[ loopVal ] != (MainState_Type*)0 ; loopVal++ )
	{
		MainState_RunA_Vcall( modules[ loopVal ] );
	}

	*/

}

void	System_StateBALANCE_MAIN( MainState_Type* const modules[] )
{
	MainState_RunB_Vcall( modules[ STATE_BALANCE_MAIN ] );

	/*

	If any child added State-A

	for( uint8_t loopVal = 0 ; modules[ loopVal ] != (MainState_Type*)0 ; loopVal++ )
	{
		MainState_RunA_Vcall( modules[ loopVal ] );
	}

	*/

}

void	System_StateCAN_MAIN( MainState_Type* const modules[] )
{
	MainState_RunC_Vcall( modules[ STATE_CAN_MAIN ] );

	/*

	If any child added State-A

	for( uint8_t loopVal = 0 ; modules[ loopVal ] != (MainState_Type*)0 ; loopVal++ )
	{
		MainState_RunA_Vcall( modules[ loopVal ] );
	}

	*/

}


void 	App_MAIN(void)
{

	MainState_CTOR(&MAIN_StateMachine);

	while(1)
	{
		stateTable[MAINstate](sys_modules);

		/* TIM Base 1ms'de 1 artacaktır. */
		Clock++;

		/* @LATER: Uyku moduna gecip 100ms sonra uyanacak */
		HAL_Delay(100);
	}

}


static void 	StateADC_MAIN( MainState_Type const * const param )
{
	if( Clock == BALANCE_STATE_TICKTIME )
	{
		 MAINstate = STATE_BALANCE;
	}

	time_adc.nowTime = HAL_GetTick();
	time_adc.deltaTime = time_adc.nowTime - time_adc.prevTime ;

	/* Debug Msg Before Running */
	_DEBUG.ops.System_StateDEBUG_MSG(&_DEBUG.obj, ADC_STATE_NAME, MSG_RUN);

	//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
	// WDT_CLR(); /* Watchdog Clear Before State Processing */
	MAINstatus.Flag.adc = true ;
	/* JUMP INTO ADC MODULE */

	MainADC();

	/* BACK FROM ADC MODULE */
	MAINstatus.Flag.adc = false ;
	// WDT_CLR(); /* Watchdog Clear After State Processing */
	//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

	/* Debug Msg Before Running */
	_DEBUG.ops.System_StateDEBUG_MSG(&_DEBUG.obj, ADC_STATE_NAME, MSG_END);

	time_adc.deltaTime /= 100;
	time_adc.prevTime = time_adc.nowTime;


}

static void 	StateBALANCE_MAIN( MainState_Type const * const param )
{
	if( Clock == CAN_STATE_TICKTIME )
	{
		  MAINstate = STATE_CAN;
	}

	time_balance.nowTime = HAL_GetTick();
	time_balance.deltaTime = time_balance.nowTime - time_balance.prevTime ;

	/* Debug Msg Before Running */
	_DEBUG.ops.System_StateDEBUG_MSG(&_DEBUG.obj, BALANCE_STATE_NAME, MSG_RUN);

	//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
	// WDT_CLR(); /* Watchdog Clear Before State Processing */
	MAINstatus.Flag.balance = true ;
	/* JUMP INTO BALANCE MODULE */

	MainBALANCE();

	/* BACK FROM BALANCE MODULE */
	// WDT_CLR(); /* Watchdog Clear After State Processing */
	MAINstatus.Flag.balance = false ;
	//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

	/* Debug Msg After Running */
	_DEBUG.ops.System_StateDEBUG_MSG(&_DEBUG.obj, BALANCE_STATE_NAME, MSG_END);

	time_balance.deltaTime /= 100;
	time_balance.prevTime = time_balance.nowTime;

}

static void 	StateCAN_MAIN( MainState_Type const * const param )
{
	if( Clock == TOTAL_TICKTIME )
	{
		Clock = ADC_STATE_TICKTIME;
		MAINstate = STATE_ADC;
	}

	time_can.nowTime = HAL_GetTick();
	time_can.deltaTime = time_can.nowTime - time_can.prevTime ;

	/* Debug Msg Before Running */
	_DEBUG.ops.System_StateDEBUG_MSG(&_DEBUG.obj, CAN_STATE_NAME, MSG_RUN);

	//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
	MAINstatus.Flag.can = true ;
	// WDT_CLR(); /* Watchdog Clear Before State Processing */
	/* JUMP INTO CAN MODULE */

	MainCAN();

	/* BACK FROM CAN MODULE */
	MAINstatus.Flag.can = false ;
	// WDT_CLR(); /* Watchdog Clear After State Processing */
	//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

	/* Debug Msg After Running */
	_DEBUG.ops.System_StateDEBUG_MSG(&_DEBUG.obj, CAN_STATE_NAME, MSG_END);

	time_can.deltaTime /= 100;
	time_can.prevTime = time_can.nowTime;
}
