/*
 * TRXVU.c
 *
 *  Created on: Dec 16, 2024
 *      Author: Owner
 */


#include <hal/boolean.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TRXVU.h"
#include <satellite-subsystems/isis_vu_e.h>


void testPAtemp(){

}
void TRXVU_Test()
{
	unsigned short telemetryValue;
		float eng_value = 0.0;
		isis_vu_e__get_rx_telemetry__from_t telemetry;
		uint32_t uptime = 0;
		int rv;

		// Telemetry values are presented as raw values
		printf("\r\nGet all Telemetry at once in raw values \r\n\r\n");
		rv = isis_vu_e__get_rx_telemetry(0, &telemetry);
		if(rv)
		{
			printf("Subsystem call failed. rv = %d", rv);
			return TRUE;
		}

		rv = isis_vu_e__rx_uptime(0, &uptime);
		if(rv)
		{
			printf("Subsystem call failed. rv = %d", rv);
			return TRUE;
		}

		printf("Receiver uptime = %lu s\r\n", uptime);

		telemetryValue = telemetry.fields.temp_pa;
		eng_value = ((float)telemetryValue) * -0.07669 + 195.6037;
		printf("PA temperature = %f deg. C\r\n", eng_value);
		if (telemetryValue >= 40 || telemetryValue <=60 ){
					printf("")
				}else{
					printf("")
				}

		telemetryValue = telemetry.fields.temp_board;
		eng_value = ((float)telemetryValue) * -0.07669 + 195.6037;
		if (telemetryValue >= 40 || telemetryValue <=60 ){
			printf("right tpm")
		}else{
			printf("bad tmp")
		}
		printf("Board temperature = %f deg. C\r\n", eng_value);


		return TRUE;
	}


    printf("Running TRxVU tests...\n\r");
    printf("TRxVU test completed.\n\r");
}
