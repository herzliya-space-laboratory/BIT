#include <hal/boolean.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "EPS.h"
#include <satellite-subsystems/isismepsv2_ivid7_piu.h>
#include <hal/Utility/util.h>


void print(const char *text, char color ) {
	//yellow
	switch (color){
	//yellow
		case 'y':
		case 'Y':
			printf("\033[1;33m");
			break;
	// red
		case 'r':
		case 'R':
			printf("\033[1;31m");
			break;
	//green
		case 'g':
		case 'G':
			printf("\033[1;32m");
			break;
	    // blue
	    case 'B':
	        printf("\e[0;34m");
	    break;
        case 'n':
        break;
    }
    printf("%s\033[0m\n\r", text); // Print the text with the color, then reset
}


void EPS_Test()
{
	print("sorry for the spelling mistakes",'B');
	print("green is good",'g');
	print("yellow says user error",'y');
	print("red is bad",'r');
	print("gray says haven't decided ",'n');
	print("blue says read user\n\r\n\r\n\r",'b');

	char temp_str[100];
	isismepsv2_ivid7_piu__gethousekeepingeng__from_t house;
	isismepsv2_ivid7_piu__gethousekeepingeng(0,&house);

    // Add EPS-specific testing logic here
	print("please enter 0 if there is no battery and 1 if there is a battery connected",'B');
	int battery;
	while (1){
		UTIL_DbguGetInteger(&battery);
		if (battery == 1 || battery == 0){
			break;
		}
	print("value isn't possible enter enter 0 if there is no battery and 1 if there is a battery",'y');
	}
	print("please enter 0 if not charging and 1 if charging",'B');
	int charging;
	while (1){
		UTIL_DbguGetInteger(&charging );
		if (charging == 1 || charging == 0){
			break;
		}
	print("value isn't possible enter enter 0 if the battery is charging and 1 if the battery isn't charging",'y');
	}

	if (battery == 1){
		int last_charge = house.fields.batt_input.fields.volt;
	}

	print((battery == 1)? "you chose that there is a battery":"you chose that there is no battery",'B');
	if (battery == 1){
		printf("the temperature of the front of the battery is %d \n\r the temperature in between the battery cells is: %d\n\r",house.fields.temp2,house.fields.temp3);
	}


	//check's MCU temp
	sprintf(temp_str,"the MCU temp is %d",house.fields.temp);
	if (battery == 1 && charging == 1){
		print(temp_str,(45 > house.fields.temp|| house.fields.temp >10) ? 'G ':'R');
	}
	else if (battery == 1 ) {
		print(temp_str , (45 > house.fields.temp|| house.fields.temp >0) ? 'G ':'R');
	}
	else {
		print(temp_str,(80 > house.fields.temp|| house.fields.temp >-45) ? 'G ':'R');
	}



}
