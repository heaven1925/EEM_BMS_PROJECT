/*******************************************************************************
  * @file    bmsConfig.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 28.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil - Battery Management System
********************************************************************************/

#ifndef INC_BMSCONFIG_H_
#define INC_BMSCONFIG_H_

/*
 * PCA Led Driver Init
 */
#include "_Pca9552_Led_Driver.h"

#define	 LED_DRIVER_01	PCA9552_ADDR_4
#define	 LED_DRIVER_02	PCA9552_ADDR_1

/*
 * EEM CAN Stack Init
 */
#include "EEMProtocol.h"
#include "EEMProtocol_Config.h"



#define		BMS_RUN	 					((int)( 0x00UL ))
#define		BMS_IDLE	 				((int)( 0x01UL ))
#define		BMS_ROUTINE					((int)( 0x02UL ))
#define		BMS_PROCESS					((int)( 0x03UL ))
#define		BMS_SUSPEND					((int)( 0x04UL ))
#define		BMS_ERR	 					((int)( 0x05UL ))
#define		BMS_EOK	 					((int)( 0x06UL ))
#define		BMS_END    					((int)( 0x07UL ))

#define 	BMS_NULL					NULL

typedef		uint8_t						bms_err_t;
typedef		bool						bms_bool_t;

typedef		uint8_t			            bms_uint8_t;
typedef		uint16_t		            bms_uint16_t;
typedef		uint32_t		            bms_uint32_t;
typedef		uint64_t		            bms_uint64_t;

typedef		int8_t			            bms_int8_t;
typedef		int16_t			            bms_int16_t;
typedef		int32_t			            bms_int32_t;
typedef		int64_t			            bms_int64_t;

typedef		float						bms_float;

typedef		char						bms_char;

typedef 	GPIO_TypeDef				bms_gpioTypedef;

typedef		GPIO_PinState				bms_pinState;
#define 	BMS_PIN_RESET				GPIO_PIN_RESET
#define 	BMS_PIN_SET					GPIO_PIN_SET

typedef		ADC_HandleTypeDef			bms_adcHandleTypeDef;

/*
 * BMS Main Class
 */
typedef struct
{
	const uint8_t			 	cell_id;
	const bms_char*				cell_name;

	/* Constant Values */
	const bms_uint8_t  			can_pgn;			/* Such as message id EEM_Procotol 		*/
	const bms_uint8_t  			can_spn;			/* Such as location at 8 byte payload 	*/
	const bms_uint8_t  			led_driver_id;
	const bms_uint8_t  			led_id;
	const bms_uint32_t			adc_channel;
	const bms_uint32_t			adc_rank;
	const bms_uint32_t			adc_samplingTime;
	const bms_uint8_t  			mux_id;
	const bms_uint8_t      		mux_select;
	const bms_gpioTypedef* 		balance_port_id;
	const bms_uint32_t 			balance_pin_id;

	/* Static Variables */
	bms_uint32_t 				raw_cell_voltage;
	bms_float 	 				voltage;
	bms_pinState 				balance_pin_state;

}Bms_Cell_Type;

typedef struct
{
	bms_uint32_t 				raw_cell_temperature;
	bms_float 	 				temperature;

	bms_uint32_t				raw_line_current;
	bms_float					current;

	bms_uint32_t				raw_vbat_voltage;
	bms_float					vbat_voltage;

	bms_uint32_t				raw_vref_voltage;
	bms_float					vref_voltage;

}Bms_Main_Type;

/*
 * BMS Total Cell Size
 */
#define 	BMS_CELL_SIZE			18

/*
 * BMS Cell Size Enum
 */
typedef enum
{
	BMS_CELL_01 = 0,
	BMS_CELL_02    ,
	BMS_CELL_03    ,
	BMS_CELL_04    ,
	BMS_CELL_05    ,
	BMS_CELL_06    ,
	BMS_CELL_07    ,
	BMS_CELL_08    ,
	BMS_CELL_09    ,
	BMS_CELL_10    ,
	BMS_CELL_11    ,
	BMS_CELL_12    ,
	BMS_CELL_13    ,
	BMS_CELL_14    ,
	BMS_CELL_15    ,
	BMS_CELL_16    ,
	BMS_CELL_17    ,
	BMS_CELL_18    ,
}Bms_CellNumber_Type;

#define	BMS_LAST_CELL		BMS_CELL_18

/*
 * BMS Mux Name
 */
#define		BMS_MUX_ID1				(0x00UL)
#define		BMS_MUX_ID2				(0x01UL)
#define		BMS_MUX_ID3				(0x02UL)

/*
 * BMS Mux Pin Selection
 */
#define		BMS_MUXSELECT_ANALOG0	((bms_uint8_t)(0b00000000))
#define		BMS_MUXSELECT_ANALOG1	((bms_uint8_t)(0b00000001))
#define		BMS_MUXSELECT_ANALOG2   ((bms_uint8_t)(0b00000010))
#define		BMS_MUXSELECT_ANALOG3   ((bms_uint8_t)(0b00000011))
#define		BMS_MUXSELECT_ANALOG4   ((bms_uint8_t)(0b00000100))
#define		BMS_MUXSELECT_ANALOG5   ((bms_uint8_t)(0b00000101))
#define		BMS_MUXSELECT_ANALOG6   ((bms_uint8_t)(0b00000110))
#define		BMS_MUXSELECT_ANALOG7   ((bms_uint8_t)(0b00000111))


/*
 * Static Variables Default Values
 */
#define		DEFAULT_RAW_CELL_VOLTAGE			((bms_uint32_t)	(0x0UL)			)
#define		DEFAULT_RAW_TEMPERATURE				((bms_uint32_t)	(0x0UL)			)
#define		DEFAULT_RAW_LINE_CURRENT			((bms_uint32_t)	(0x0UL)			)
#define		DEFAULT_RAW_VBAT_VOLTAGE			((bms_uint32_t)	(0x0UL)			)
#define		DEFAULT_RAW_VREF_VOLTAGE            ((bms_float)	(0.0)			)

#define		DEFAULT_CELL_VOLTAGE                ((bms_float)	(0.0)			)
#define		DEFAULT_TEMPERATURE                 ((bms_float)	(0.0)			)
#define		DEFAULT_LINE_CURRENT                ((bms_float)	(0.0)			)
#define		DEFAULT_VBAT_VOLTAGE                ((bms_float)	(0.0)			)
#define		DEFAULT_VREF_VOLTAGE                ((bms_float)	(0.0)			)

#define		DEFAULT_BALANCE_PIN_STATE           ((bms_pinState)	(BMS_PIN_RESET)	)

/*
 * Const Variable Definitions
 */

/* Cell-01 Constant Parameters */
#define		CELL01_CELL_ID  					((bms_uint8_t		)(1     				))
#define		CELL01_CELL_NAME					((bms_char *		)("CELL_01"				))
#define		CELL01_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE06 			))
#define		CELL01_CAN_SPN                      ((bms_uint8_t  		)(SPN00 				))
#define		CELL01_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_02 		))
#define		CELL01_LED_ID                       ((bms_uint8_t  		)(PCA_LED1 				))
#define		CELL01_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_0			))
#define		CELL01_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL01_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL01_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID1 			))
#define		CELL01_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG0 ))
#define		CELL01_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOF 				))
#define		CELL01_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_2 			))

/* Cell-02 Constant Parameters */
#define		CELL02_CELL_ID  					((bms_uint8_t		)(2       				))
#define		CELL02_CELL_NAME					((bms_char *		)("CELL_02"				))
#define		CELL02_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE06 			))
#define		CELL02_CAN_SPN                      ((bms_uint8_t  		)(SPN16 				))
#define		CELL02_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_02 		))
#define		CELL02_LED_ID                       ((bms_uint8_t  		)(PCA_LED0 				))
#define		CELL02_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_0		    ))
#define		CELL02_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL02_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL02_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID1 			))
#define		CELL02_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG1 ))
#define		CELL02_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOF 				))
#define		CELL02_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_3 			))

/* Cell-03 Constant Parameters */
#define		CELL03_CELL_ID  					((bms_uint8_t		)(3      				))
#define		CELL03_CELL_NAME					((bms_char *		)("CELL_03"				))
#define		CELL03_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE06 			))
#define		CELL03_CAN_SPN                      ((bms_uint8_t  		)(SPN32 				))
#define		CELL03_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL03_LED_ID                       ((bms_uint8_t  		)(PCA_LED15 			))
#define		CELL03_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_0		    ))
#define		CELL03_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL03_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL03_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID1 			))
#define		CELL03_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG2 ))
#define		CELL03_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOF 				))
#define		CELL03_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_4 			))

/* Cell-04 Constant Parameters */
#define		CELL04_CELL_ID  					((bms_uint8_t		)(4      				))
#define		CELL04_CELL_NAME					((bms_char *		)("CELL_04"				))
#define		CELL04_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE06 			))
#define		CELL04_CAN_SPN                      ((bms_uint8_t  		)(SPN48 				))
#define		CELL04_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL04_LED_ID                       ((bms_uint8_t  		)(PCA_LED14 			))
#define		CELL04_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_0		    ))
#define		CELL04_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL04_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL04_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID1 			))
#define		CELL04_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG3 ))
#define		CELL04_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOF 				))
#define		CELL04_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_5 			))

/* Cell-05 Constant Parameters */
#define		CELL05_CELL_ID  					((bms_uint8_t		)(5      				))
#define		CELL05_CELL_NAME					((bms_char *		)("CELL_05"				))
#define		CELL05_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE07 			))
#define		CELL05_CAN_SPN                      ((bms_uint8_t  		)(SPN00 				))
#define		CELL05_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL05_LED_ID                       ((bms_uint8_t  		)(PCA_LED13 			))
#define		CELL05_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_0		    ))
#define		CELL05_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL05_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL05_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID1 			))
#define		CELL05_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG4 ))
#define		CELL05_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOF 				))
#define		CELL05_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_6 			))

/* Cell-06 Constant Parameters */
#define		CELL06_CELL_ID  					((bms_uint8_t		)(6     				))
#define		CELL06_CELL_NAME					((bms_char *		)("CELL_06"				))
#define		CELL06_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE07 			))
#define		CELL06_CAN_SPN                      ((bms_uint8_t  		)(SPN16 				))
#define		CELL06_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL06_LED_ID                       ((bms_uint8_t  		)(PCA_LED12 			))
#define		CELL06_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_0		    ))
#define		CELL06_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL06_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL06_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID1 			))
#define		CELL06_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG6 ))
#define		CELL06_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOF 				))
#define		CELL06_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_7 			))

/* Cell-07 Constant Parameters */
#define		CELL07_CELL_ID  					((bms_uint8_t		)(7				        ))
#define		CELL07_CELL_NAME					((bms_char *		)("CELL_07"				))
#define		CELL07_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE07 			))
#define		CELL07_CAN_SPN                      ((bms_uint8_t  		)(SPN32 				))
#define		CELL07_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL07_LED_ID                       ((bms_uint8_t  		)(PCA_LED11 			))
#define		CELL07_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID1 			))
#define		CELL07_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_0		    ))
#define		CELL07_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL07_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL07_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG7 ))
#define		CELL07_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOF 				))
#define		CELL07_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_8			))

/* Cell-08 Constant Parameters */
#define		CELL08_CELL_ID  					((bms_uint8_t		)(8     				))
#define		CELL08_CELL_NAME					((bms_char *		)("CELL_08"				))
#define		CELL08_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE07 			))
#define		CELL08_CAN_SPN                      ((bms_uint8_t  		)(SPN48 				))
#define		CELL08_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL08_LED_ID                       ((bms_uint8_t  		)(PCA_LED10 			))
#define		CELL08_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_1		    ))
#define		CELL08_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL08_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL08_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID1 			))
#define		CELL08_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG5 ))
#define		CELL08_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOF 				))
#define		CELL08_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_9 			))

/* Cell-09 Constant Parameters */
#define		CELL09_CELL_ID  					((bms_uint8_t		)(9		        		))
#define		CELL09_CELL_NAME					((bms_char *		)("CELL_09"				))
#define		CELL09_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE08 			))
#define		CELL09_CAN_SPN                      ((bms_uint8_t  		)(SPN00 				))
#define		CELL09_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL09_LED_ID                       ((bms_uint8_t  		)(PCA_LED9 				))
#define		CELL09_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_1		    ))
#define		CELL09_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL09_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL09_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID2 			))
#define		CELL09_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG4 ))
#define		CELL09_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOF 				))
#define		CELL09_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_10 			))

/* Cell-10 Constant Parameters */
#define		CELL10_CELL_ID  					((bms_uint8_t		)(10    				))
#define		CELL10_CELL_NAME					((bms_char *		)("CELL_10"				))
#define		CELL10_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE08 			))
#define		CELL10_CAN_SPN                      ((bms_uint8_t  		)(SPN16 				))
#define		CELL10_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL10_LED_ID                       ((bms_uint8_t  		)(PCA_LED8 				))
#define		CELL10_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_1		    ))
#define		CELL10_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL10_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL10_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID2 			))
#define		CELL10_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG6 ))
#define		CELL10_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOC 				))
#define		CELL10_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_0 			))

/* Cell-11 Constant Parameters */
#define		CELL11_CELL_ID  					((bms_uint8_t		)(11    				))
#define		CELL11_CELL_NAME					((bms_char *		)("CELL_11"				))
#define		CELL11_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE08 			))
#define		CELL11_CAN_SPN                      ((bms_uint8_t  		)(SPN32 				))
#define		CELL11_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL11_LED_ID                       ((bms_uint8_t  		)(PCA_LED7 				))
#define		CELL11_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_1		    ))
#define		CELL11_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL11_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL11_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID2 			))
#define		CELL11_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG7 ))
#define		CELL11_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOC 				))
#define		CELL11_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_1 			))

/* Cell-12 Constant Parameters */
#define		CELL12_CELL_ID  					((bms_uint8_t		)(12    				))
#define		CELL12_CELL_NAME					((bms_char *		)("CELL_12"				))
#define		CELL12_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE08 			))
#define		CELL12_CAN_SPN                      ((bms_uint8_t  		)(SPN48 				))
#define		CELL12_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL12_LED_ID                       ((bms_uint8_t  		)(PCA_LED6 				))
#define		CELL12_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_1		    ))
#define		CELL12_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL12_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL12_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID2 			))
#define		CELL12_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG5 ))
#define		CELL12_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOC 				))
#define		CELL12_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_2 			))

/* Cell-13 Constant Parameters */
#define		CELL13_CELL_ID  					((bms_uint8_t		)(13    				))
#define		CELL13_CELL_NAME					((bms_char *		)("CELL_13"				))
#define		CELL13_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE09 			))
#define		CELL13_CAN_SPN                      ((bms_uint8_t  		)(SPN00 				))
#define		CELL13_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL13_LED_ID                       ((bms_uint8_t  		)(PCA_LED5 				))
#define		CELL13_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_1		    ))
#define		CELL13_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL13_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL13_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID2 			))
#define		CELL13_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG3 ))
#define		CELL13_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOC 				))
#define		CELL13_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_3 			))

/* Cell-14 Constant Parameters */
#define		CELL14_CELL_ID  					((bms_uint8_t		)(14    				))
#define		CELL14_CELL_NAME					((bms_char *		)("CELL_14"				))
#define		CELL14_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE09 			))
#define		CELL14_CAN_SPN                      ((bms_uint8_t  		)(SPN16 				))
#define		CELL14_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL14_LED_ID                       ((bms_uint8_t  		)(PCA_LED4 				))
#define		CELL14_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_1		))
#define		CELL14_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL14_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL14_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID2 			))
#define		CELL14_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG0 ))
#define		CELL14_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOA 				))
#define		CELL14_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_4			))

/* Cell-15 Constant Parameters */
#define		CELL15_CELL_ID  					((bms_uint8_t		)(15     				))
#define		CELL15_CELL_NAME					((bms_char *		)("CELL_15"				))
#define		CELL15_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE09 			))
#define		CELL15_CAN_SPN                      ((bms_uint8_t  		)(SPN32 				))
#define		CELL15_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL15_LED_ID                       ((bms_uint8_t  		)(PCA_LED3 				))
#define		CELL15_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_1		    ))
#define		CELL15_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL15_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL15_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID2 			))
#define		CELL15_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG1 ))
#define		CELL15_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOA 				))
#define		CELL15_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_5 			))

/* Cell-16 Constant Parameters */
#define		CELL16_CELL_ID  					((bms_uint8_t		)(16     				))
#define		CELL16_CELL_NAME					((bms_char *		)("CELL_16"				))
#define		CELL16_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE09 			))
#define		CELL16_CAN_SPN                      ((bms_uint8_t  		)(SPN48 				))
#define		CELL16_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL16_LED_ID                       ((bms_uint8_t  		)(PCA_LED2 				))
#define		CELL16_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_1		    ))
#define		CELL16_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL16_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL16_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID2 			))
#define		CELL16_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG2 ))
#define		CELL16_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOA 				))
#define		CELL16_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_6 			))

/* Cell-17 Constant Parameters */
#define		CELL17_CELL_ID  					((bms_uint8_t		)(17				    ))
#define		CELL17_CELL_NAME					((bms_char *		)("CELL_17"				))
#define		CELL17_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE10 			))
#define		CELL17_CAN_SPN                      ((bms_uint8_t  		)(SPN00 				))
#define		CELL17_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL17_LED_ID                       ((bms_uint8_t  		)(PCA_LED1 				))
#define		CELL17_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_2		    ))
#define		CELL17_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL17_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL17_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID3 			))
#define		CELL17_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG0 ))
#define		CELL17_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOA 				))
#define		CELL17_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_7 			))

/* Cell-18 Constant Parameters */
#define		CELL18_CELL_ID  					((bms_uint8_t		)(18				    ))
#define		CELL18_CELL_NAME					((bms_char *		)("CELL_18"				))
#define		CELL18_CAN_PGN                      ((bms_uint8_t  		)(MESSAGE10 			))
#define		CELL18_CAN_SPN                      ((bms_uint8_t  		)(SPN16 				))
#define		CELL18_LED_DRIVER_ID 				((bms_uint8_t  		)(LED_DRIVER_01 		))
#define		CELL18_LED_ID                       ((bms_uint8_t  		)(PCA_LED0 				))
#define		CELL18_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_2		    ))
#define		CELL18_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		CELL18_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CELL18_MUX_ID                       ((bms_uint8_t  		)(BMS_MUX_ID3 			))
#define		CELL18_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG1 ))
#define		CELL18_BALANCE_PORT					((bms_gpioTypedef* 	)(GPIOC 				))
#define		CELL18_BALANCE_PIN					((bms_uint32_t 		)(GPIO_PIN_4 			))

/* Temperature Sense Parameters */
#define		TEMPERATURE_ADC_CHANNEL		        ((bms_uint32_t		)(ADC_CHANNEL_2			))
#define		TEMPERATURE_ADC_RANK		        ((bms_uint32_t		)(0x1					))
#define		TEMPERATURE_ADC_SAMPLINGTIME		((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		TEMPERATURE_MUX_ID                  ((bms_uint8_t  		)(BMS_MUX_ID3 			))
#define		TEMPERATURE_MUX_SELECT_ID			((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG2 ))

/* Current Sense Parameters */
#define		CURRENT_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_2			))
#define		CURRENT_ADC_RANK		            ((bms_uint32_t		)(0x1					))
#define		CURRENT_ADC_SAMPLINGTIME		    ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))
#define		CURRENT_MUX_ID                      ((bms_uint8_t  		)(BMS_MUX_ID3 			))
#define		CURRENT_MUX_SELECT_ID				((bms_uint8_t      	)(BMS_MUXSELECT_ANALOG3 ))

/* Vbat Sense Parameters */
#define		VBAT_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_5			))
#define		VBAT_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		VBAT_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))

/* Vref Sense Parameters */
#define		VREF_ADC_CHANNEL		            ((bms_uint32_t		)(ADC_CHANNEL_6			))
#define		VREF_ADC_RANK		                ((bms_uint32_t		)(0x1					))
#define		VREF_ADC_SAMPLINGTIME		        ((bms_uint32_t		)(ADC_SAMPLETIME_28CYCLES))

inline     float 	BMS_Calculate_CellVoltage(uint16_t raw_value)
{
	//@LATER
}

inline     float 	BMS_Calculate_LineCurrent(uint16_t raw_value)
{
	//@LATER
}

inline     float 	BMS_Calculate_Temperature(uint16_t raw_value)
{
	//@LATER
}

inline     float 	BMS_Calculate_VBatVoltage(uint16_t raw_value)
{
	//@LATER
}

inline     float 	BMS_Calculate_VRefVoltage(uint16_t raw_value)
{
	//@LATER
}




#endif /* INC_BMSCONFIG_H_ */
