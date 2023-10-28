#include "main.h"

void Serial_In(){
	while(Serial.available()>0){
		char VAL=(char)Serial.read();
		}
	}