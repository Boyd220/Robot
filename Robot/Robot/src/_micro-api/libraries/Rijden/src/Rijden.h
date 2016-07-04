// Rijden.h

#ifndef _RIJDEN_h
#define _RIJDEN_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
// pinnen voor hbrug/shield definieren
#define Motor_L_V	5
#define Motor_L_A	4
#define Motor_R_V	7
#define Motor_R_A	6

class Rijden
{
public:
	//declaratie methoden & minimale snelheid
	int minspeed = 75;
	void stop();
	void vooruit(int snelheid);
	void achteruit(int snelheid);
	void links(int snelheid, int scherpte);
	void rechts(int snelheid, int scherpte);
	void links_achter(int snelheid, int scherpte);
	void rechts_achter(int snelheid, int scherpte);
	void links_eigenas(int snelheid);
	void rechts_eigenas(int snelheid);
private:

};


#endif

