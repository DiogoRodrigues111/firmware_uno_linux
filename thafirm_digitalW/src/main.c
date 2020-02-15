/* =======================================
 * led_digital_c.c
 *
 * Created: 2/7/2020 1:21:54 PM
 * Author : Diogo Rodrigues Roessler
 * ====================================== */ 

#include <avr/io.h>
#include <stdlib.h>

#include "digital_w.h"

int main(VOID)
{
	//PHAVE_FUN have = malloc(sizeof(PHAVE_FUN));
	//UINT _i,_j;
	
	//ddr = 0xFF;
	//have->HardwareFlags = ddr;
	
    while(TRUE) {
		//---------------------------------------
		//port = 0xFF;
		//_digital_w(port, 0xFF);
		//delay_ms_linux_(1000);
		//---------------------------------------
		//_digital_w(PORT_TX, 0x00);
		//delay_ms(10000);
		//delay_ms(1000);
		//_delay_ms(10000);
		//---------------------------------------   
		//port = 0x00;
		//_digital_w(port, 0x00);
		//delay_ms_linux_(1000);
		//_digital_w(PORT_TX, 0xFF);
		//delay_ms(10000);
		//delay_ms(1000);
		//_delay_ms(10000);
		//---------------------------------------
		/*
		FOR(_i=0; _i < have->HardwareFlags; _i++) {
			_digital_w(port, 0xFF);
			delay_ms(1000);
			
			FOR(_j=0; _j < 3; _j++) {
				_digital_w(port, 0x00);
				delay_ms(10000);
				
				_digital_w(PORT_TX, 0xFF);
				delay_ms(100);
			}
			
			_digital_w(port, 0xFF);
			_digital_w(PORT_TX, 0x00);
			delay_ms(100);
		} */ /* End For */
    }
	//free(have);
}

