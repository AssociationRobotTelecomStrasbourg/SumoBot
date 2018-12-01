#include "IRsensor.h"
#include <Arduino.h>

IRsensor::IRsensor(int pin, int NBmesures) : _pin(pin), _NBmesures(NBmesures){
	pinMode(pin, INPUT);
}

int IRsensor::rawDistance(){
	return 13*pow(analogRead(_pin)*5./1024.,-1);
}

int IRsensor::rawData(){
	return analogRead(_pin);
}

int IRsensor::distanceMoy(){
	int moy=0;
		for(int i=0;i<_NBmesures;i++){
			moy+=rawDistance();
		}
	return moy/_NBmesures;
}
