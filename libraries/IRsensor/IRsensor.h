#ifndef IRSENSOR_H
#define IRSENSOR_H

class IRsensor{    
	public :
		IRsensor(int pin, int NBmesures = 10);
		int rawDistance(void);
		int rawData(void);
		int distanceMoy(void);

	private :
		int _pin;
		int _NBmesures;
};

#endif
