@mainpage Doxygen Example Project

# DOXYGEN EXAMPLE
## Summary
Doxygen is a convienent way to document a plethora of languages of code. This example is for a simple embedded project in C. Some have the opinion that doxygen itself is not sufficient as it only spits out descriptions of files and functions which is not abstracted enough to get the big picture. However, markdown files can be integrated into the doxygen output so it's really more down to the individual approach and needs. My projects are geared toward the needs of EE's, not software dev's, so this style and method is flexible and convienent enough for my end goal. 

## Doxygen References
   - Installer: [Doxygen Download Page](https://www.doxygen.nl/download.html)
   - User Manual: [Doxygen User Manual](https://www.doxygen.nl/manual/index.html)
   - Reference Link: [Guide On Using Doxygen To Document C Source Code](https://embeddedinventor.com/guide-to-configure-doxygen-to-document-c-source-code-for-beginners/)

## Dependencies
- Hardware: [SAM D21 Xplained Pro](https://www.microchip.com/en-us/development-tool/atsamd21-xpro)
- IDE: [Microchip Studio v7.0.2594](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio#Downloads)

## General Firmware Functionality
- The firmware starts a hardware timer on the microcontroller to throw an IRQ every 10ms.
- A single analog reading is taken in the timer callback. Then the ADC mux is changed to read the next channel. 
- A total of 6 analog channels are read round-robin style and stored in global array. 

### Global ADC Results Array
`extern volatile uint16_t g_adc_mux_results[NUM_ADC_MUX_POS];`

### Round-Robin ADC Sampling in Timer Callback
```
static void adc_timer_cb(const struct timer_task *const timer_task)
{
	static adc_ch_t adc_input = E_ADC_AIN_2;
	uint16_t adc_value = 0;
	
	switch(adc_input){
		case E_ADC_AIN_2:
			adc_value = adc_convert_raw_data(adc_api_read(E_ADC_AIN_2), E_ADC_AIN_2);
			g_adc_mux_results[0] = adc_value;
			adc_input = E_ADC_AIN_3;
			break;
		case E_ADC_AIN_3:
			adc_value = adc_convert_raw_data(adc_api_read(E_ADC_AIN_3), E_ADC_AIN_3);
			g_adc_mux_results[1] = adc_value;
			adc_input = E_ADC_AIN_4;
			break;
		case E_ADC_AIN_4:
			adc_value = adc_convert_raw_data(adc_api_read(E_ADC_AIN_4), E_ADC_AIN_4);
			g_adc_mux_results[2] = adc_value;
			adc_input = E_ADC_AIN_5;
			break;
		case E_ADC_AIN_5:
			adc_value = adc_convert_raw_data(adc_api_read(E_ADC_AIN_5), E_ADC_AIN_5);
			g_adc_mux_results[3] = adc_value;
			adc_input = E_ADC_AIN_6;
			break;
		case E_ADC_AIN_6:
			adc_value = adc_convert_raw_data(adc_api_read(E_ADC_AIN_6), E_ADC_AIN_6);
			g_adc_mux_results[4] = adc_value;
			adc_input = E_ADC_AIN_7;
			break;
		case E_ADC_AIN_7:
			adc_value = adc_convert_raw_data(adc_api_read(E_ADC_AIN_7), E_ADC_AIN_7);
			g_adc_mux_results[5] = adc_value;
			adc_input = E_ADC_AIN_2;
			break;
		default:
			adc_input = E_ADC_AIN_2;
			break;		
	}
}
```

