/** 
 * @file adc_api.c
 * @author John Petrilli
 * @date 29.July.2024
 * @brief Provides access to the on-chip ADC peripheral.
*/
#include <atmel_start.h>
#include "adc.h"
#include "adc_api.h"

/// @todo sufficiently document all functions
/// @todo setup doxyfile
/// @todo make video notes on how to setup and generate documentation

// Example of how to use a group in doxygen
/** @defgroup Global_Variables Global Variables
 *  @{
 */
extern volatile uint16_t g_adc_mux_results[NUM_ADC_MUX_POS];
/** @} */ // end of Global_Variables


/// @brief  Main function. Calls the init function generated from atmel start,
/// calls the adc_api_init, and timer init functions. This application runs on
/// interrupts, so we enter the endless while loop here. There is a nop operation
/// in the while loop for debugging purposes. 
/// @param  void
/// @return int - code will never return
int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	adc_api_init();
	adc_timer_init();
	
	/* Replace with your application code */
	while (1) {
		asm("nop");
	}
}
