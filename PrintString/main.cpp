#include <appdef.hpp>
#include <sdk/calc/calc.hpp>
#include <sdk/os/lcd.hpp>
#include <sdk/os/debug.hpp>
#include "debug_refresh.h"

/*
 * Fill this section in with some information about your app.
 * All fields are optional - so if you don't need one, take it out.
 */
APP_NAME("PrintStringRefreshTemplate")
APP_DESCRIPTION("Prints \"Hello World\" to X:10, Y:10 with close to no RAM usage.")
APP_AUTHOR("Felix")
APP_VERSION("1.0.0")

extern "C"
void main() {
	calcInit(); //backup screen and init some variables

	PrintStringCustomRefresh("Hello World", 10, 10);

	while(true){
		uint32_t key1, key2;	
		getKey(&key1, &key2);	
		if(testKey(key1, key2, KEY_CLEAR)){
			break;
		}
	}

	calcEnd(); //restore screen and do stuff
}
