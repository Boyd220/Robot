// 
// 
// 

#include "Rijden.h"

void Rijden::stop() {
	//alle pinnen false = stop. ander optie is alle pinnen 1 =stop. (is elektrisch beveiligd in shield)
	digitalWrite(Motor_L_V, false);
	digitalWrite(Motor_L_A, false);
	digitalWrite(Motor_R_V, false);
	digitalWrite(Motor_R_A, false);
}

void Rijden::vooruit(int snelheid) {
	//pinnen voor achteruitrijden uit zetten
	digitalWrite(Motor_L_A, false);
	digitalWrite(Motor_R_A, false);
	//snelheid begrenzen voor pwm
	if (snelheid > 255)
	{
		snelheid = 255;
	}
	else if (snelheid < Rijden::minspeed )
	{
		snelheid = Rijden::minspeed;
	}
	//kleine delay voor weg werken mogelijke elektrische lading overgebleven in de motoren.
	delay(5);
	analogWrite(Motor_L_V, snelheid);
	analogWrite(Motor_R_V, snelheid);
}

void Rijden::achteruit(int snelheid ) {
	//zelfde als vooruit.
	digitalWrite(Motor_L_V, false);
	digitalWrite(Motor_R_V, false);
	if (snelheid > 255)
	{
		snelheid = 255;
	}
	else if (snelheid < Rijden::minspeed)
	{
		snelheid = Rijden::minspeed;
	}
	delay(5);
	analogWrite(Motor_L_A, snelheid);
	analogWrite(Motor_R_A, snelheid);
}

void Rijden::links(int snelheid, int scherpte) {
	digitalWrite(Motor_L_A, false);
	digitalWrite(Motor_R_A, false);
	if (snelheid > 255)
	{
		snelheid = 255;
	}
	else if (snelheid < Rijden::minspeed)
	{
		snelheid = Rijden::minspeed;
	}
	//scherpte begrenzen zodat bocht gegarandeerd is. onafhankelijk van de snelheid.
	if (scherpte > snelheid)
	{
		scherpte = snelheid;
	}
	else if (scherpte < 50) {
		scherpte = 50;
	}

	delay(5);

	analogWrite(Motor_L_V, snelheid -scherpte );
	analogWrite(Motor_R_V, snelheid);
}

void Rijden::rechts(int snelheid, int scherpte) {
	digitalWrite(Motor_L_A, false);
	digitalWrite(Motor_R_A, false);
	if (snelheid > 255)
	{
		snelheid = 255;
	}
	else if (snelheid < Rijden::minspeed)
	{
		snelheid = Rijden::minspeed;
	}
	if (scherpte > snelheid)
	{
		scherpte = snelheid;
	}
	else if (scherpte < 50) {
		scherpte = 50;
	}

	delay(5);

	analogWrite(Motor_R_V, snelheid - scherpte);
	analogWrite(Motor_L_V, snelheid);
}

void Rijden::links_achter(int snelheid, int scherpte) {
	digitalWrite(Motor_L_V, false);
	digitalWrite(Motor_R_V, false);
	if (snelheid > 255)
	{
		snelheid = 255;
	}
	else if (snelheid < Rijden::minspeed)
	{
		snelheid = Rijden::minspeed;
	}
	if (scherpte > snelheid)
	{
		scherpte = snelheid;
	}
	else if (scherpte < 50) {
		scherpte = 50;
	}

	delay(5);

	analogWrite(Motor_L_A, snelheid - scherpte);
	analogWrite(Motor_R_A, snelheid);
}

void Rijden::rechts_achter(int snelheid, int scherpte) {
	digitalWrite(Motor_L_V, false);
	digitalWrite(Motor_R_V, false);
	if (snelheid > 255)
	{
		snelheid = 255;
	}
	else if (snelheid < Rijden::minspeed)
	{
		snelheid = Rijden::minspeed;
	}
	if (scherpte > snelheid)
	{
		scherpte = snelheid;
	}
	else if (scherpte < 50) {
		scherpte = 50;
	}

	delay(5);

	analogWrite(Motor_R_A, snelheid - scherpte);
	analogWrite(Motor_L_A, snelheid);
}

void Rijden::links_eigenas(int snelheid) {
	digitalWrite(Motor_L_V, false);
	digitalWrite(Motor_R_A, false);
	if (snelheid > 255)
	{
		snelheid = 255;
	}
	else if (snelheid < Rijden::minspeed)
	{
		snelheid = Rijden::minspeed;
	}
	analogWrite(Motor_L_A, snelheid);
	analogWrite(Motor_R_V, snelheid);
}

void Rijden::rechts_eigenas(int snelheid) {
	digitalWrite(Motor_L_A, false);
	digitalWrite(Motor_R_V, false);
	if (snelheid > 255)
	{
		snelheid = 255;
	}
	else if (snelheid < Rijden::minspeed)
	{
		snelheid = Rijden::minspeed;
	}
	analogWrite(Motor_L_V, snelheid);
	analogWrite(Motor_R_A, snelheid);
}