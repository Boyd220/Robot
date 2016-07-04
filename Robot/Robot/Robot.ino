/*
 Name:		Robot.ino
 Created:	3/9/2016 9:51:47 AM
 Author:	Rival
*/

// the setup function runs once when you press reset or power the board
#include "Rijden.h"
#include <SoftwareSerial\SoftwareSerial.h>

//variables
Rijden robot;
SoftwareSerial bluetooth(10, 11);

//enums
enum Mode{Auto,Manueel};

//sensors
#include <NewPing.h> //externe librarie voor ultrasone sensors
NewPing Sensor_LV(41, 40, 20), Sensor_RV(45, 44, 20), Sensor_C(43, 42, 20), Sensor_LS(47, 46, 20), Sensor_RS(49, 48, 20);
int dist_left, dist_right, dist_center, dist_LeftSide, dist_RightSide;

//command variables
int command_part1;
int command_part2;
int command_part3;
char communicationCommand;

//inplementation of enum
Mode mode;

void setup() {
	robot = Rijden();	//gebruik van eigen libarie voor het aansturen van de motoren.
	delay(5000);
	mode = Manueel;		//initialiseer in auto mode
	Serial.begin(9600);
	bluetooth.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
		if (bluetooth.available() > 0) //bluetoothdata beschikbaar
		{
			/*command_part1 = bluetooth.parseInt();
			command_part2 = bluetooth.parseInt();
			command_part3 = bluetooth.parseInt();*/
			communicationCommand = bluetooth.read();
			Serial.println(communicationCommand);

			//todo: millis();
		}
		else
		{
			communicationCommand = '-999';
			command_part1 = -999;
			command_part2 = -999;
			command_part3 = -999;
		}
	
	
	
	if (mode == Manueel) //voer de juiste code uit voor de mode waarin de robot zich nu bevind.
	{
		CommunicationMode();
	}
	else if (mode == Auto)
	{
		if (communicationCommand == ('8') ) //switch naar manueel mode bij ontvangen van deze code.
		{
			mode = Manueel;
			robot.stop();
			bluetooth.println("Switching to ManualMode");
		}
		AIMODE_v7();
	}
}

void getDistance() { //meet de afstand meermaals en bereken het gemiddelde voor accuratie
	
	dist_center = Sensor_C.ping_cm(); //meeting per sensor
	delay(5); //voldoende tijd zodat er geen interferrentie is van de vorige meting.
	dist_left = Sensor_LV.ping_cm();
	delay(5);
	dist_right = Sensor_RV.ping_cm();
	delay(5);
	dist_LeftSide = Sensor_LS.ping_cm();
	delay(5);
	dist_RightSide = Sensor_RS.ping_cm();
	delay(5);
	for (size_t i = 0; i < 2; i++)
	{
		//loop metingen
		dist_center += Sensor_C.ping_cm();
		delay(5);
		dist_left += Sensor_LV.ping_cm();
		delay(5);
		dist_right += Sensor_RV.ping_cm();
		delay(5);
		dist_LeftSide += Sensor_LS.ping_cm();
		delay(5);
		dist_RightSide += Sensor_RS.ping_cm();

		//berekening gemiddelde onafhankelijk lengte loop.
		dist_center = dist_center / 2;
		dist_left = dist_left / 2;
		dist_right = dist_right / 2;
		dist_LeftSide = dist_LeftSide / 2;
		dist_RightSide = dist_RightSide / 2;
		delay(5);
	}

	

}

void ManualMode() { //manuele code zie voor uitleg code serial command lijst (is uitgeschakeld voor communicatie)
	if (command_part1 != -999 && command_part2 != -999)
	{
		bluetooth.println("New Command Received:");
		switch (command_part1)
		{
		case -1:
			mode = Auto;
			robot.stop();
			bluetooth.println("Switching to AiMode");
			break;

		case 0:
			robot.stop();
			bluetooth.println("Stop");
			break;
		case 1:
			robot.vooruit(command_part2);
			bluetooth.println("Forwards with speed " + command_part2);
			break;
		case 2:
			robot.achteruit(command_part2);
			bluetooth.println("Backwards with speed " + command_part2);
			break;
		case 3:
			robot.links(command_part2, command_part3);
			bluetooth.println("Left with speed " + command_part2);
			bluetooth.println("and sharpness " + command_part3);
			break;
		case 4:
			robot.rechts(command_part2, command_part3);
			bluetooth.println("Right with speed " + command_part2);
			bluetooth.println("and sharpness " + command_part3);
			break;
		case 5:
			robot.links_eigenas(command_part2);
			bluetooth.println("Left rotate with speed " + command_part2);
			break;
		case 6:
			robot.rechts_eigenas(command_part2);
			bluetooth.println("Right rotate with speed " + command_part2);
			break;
		default:
			robot.stop();
			bluetooth.println("Unknown --> Stop");
			break;
		}
	}
	delay(500);
	getDistance();
	if (dist_center < 2 || dist_left < 2 || dist_right <2) //komt iets te dicht. stop
	{
		robot.stop();
		bluetooth.println("object in way --> STOP");
	}
}

void CommunicationMode() { //deze modus vervangt manueel coor de communicatie mogelijk te maken tussen arduino's
	switch (communicationCommand)
	{
	case '8': //mode switching
		mode = Auto;

	case '0': //stoppen
		robot.stop();
		Serial.println("stop");
		break;
	case '1': //voooruit
		robot.vooruit(200);
		Serial.println("Vooruit");
		break;
	case '2': //links (schuin)
		robot.links(200, 200);
		break;
	case '3': //links eigenas
		robot.links_eigenas(200);
		break;
	case '4': //rechts (schuin)
		robot.rechts(200, 200);
		break;
	case '5': //rechts eigenas
		robot.rechts_eigenas(200);
		break;
	case '6': //achteruit
		robot.achteruit(200);
		break;

	default: //ongekend doe niets
		break;
	}
}

void AIMODE_v7() { //automatische code (7de itteratie)
	getDistance(); //krijg nieuwe metingen sensoren

	int maat1 = 15; //verste rekening mee te houden afstand in ai
	int maat2 = 10; //matige rekening mee te houden afstand in ai
	int maat3 = 5;	//korste rekening mee te houden afstand in ai

	if (dist_center > maat1 && dist_left > maat1 && dist_right > maat1  && dist_LeftSide > maat1 && dist_RightSide > maat1) //ziet niks
	{
		robot.vooruit(255);
	}
	else {
		if (dist_center > maat1) //ziet niets vooraan op een afstand van maat1
		{
			if (dist_left < maat1 && dist_right > maat1 && dist_LeftSide > maat1 && dist_RightSide > maat1) //links vooraan
			{
				robot.rechts(255,255);
			}
			else if (dist_left > maat1 && dist_right < maat1 && dist_LeftSide > maat1 && dist_RightSide > maat1) //rechts vooraan
			{
				robot.links(255, 255);
			}
			else if (dist_left > maat1 && dist_right > maat1 && dist_LeftSide < maat1 && dist_RightSide > maat1) //linker zijkant
			{
				int scherpte = (maat1 - dist_LeftSide) * 255; // afhankelijk van de afstand gemeten scherpte aanpassen
				robot.rechts(255, scherpte);
			}
			else if (dist_left > maat1 && dist_right > maat1 && dist_LeftSide > maat1 && dist_RightSide < maat1) //rechter zijkant
			{
				int scherpte = (maat1 - dist_RightSide) * 255; // afhankelijk van de afstand gemeten scherpte aanpassen
				robot.links(255, scherpte);
			}
			else if (dist_left < maat1 && dist_right < maat1 && dist_LeftSide > maat1 && dist_RightSide > maat1) //links & rechts op een afstand van maat1 = nog genoeg plaats (probeer ertussen te rijden)
			{
				if (dist_left > dist_right) //welke kant heeft het meeste ruiumte 
				{
					robot.links(255, 100);
				}
				else
				{
					robot.rechts(255, 100);
				}
			}
			else if (dist_left > maat1 && dist_right > maat1 && dist_LeftSide < maat1 && dist_RightSide < maat1) // linker en rechter zijkant iets in de weg op maat 1 = zeker genoeg ruimte om voort te rijden
			{
				robot.vooruit(200); //rijd voor uit

				if (dist_LeftSide < maat3 || dist_RightSide < maat3) // als afstand kort wordt aan 1 zijde en andere niet probeer centraal te positioneren
				{
					if (dist_LeftSide > dist_RightSide) //welke kant heeft het meeste ruiumte 
					{
						robot.links(255, 100);
					}
					else
					{
						robot.rechts(255, 100);
					}
				}
				
			}
			else if(dist_left < maat1 && dist_right > maat1 && dist_LeftSide < maat1 && dist_RightSide < maat1)
			{
				robot.rechts(255, 100);
			}
			else if (dist_left > maat1 && dist_right < maat1 && dist_LeftSide < maat1 && dist_RightSide < maat1)
			{
				robot.links(255, 100);
			}
			else if (dist_left < maat3 && dist_right < maat3 && dist_LeftSide < maat3 && dist_RightSide < maat3) // ruinte te nouw rijd achteruit en keer 180° om
			{
				robot.achteruit(255);
				delay(500);
				robot.rechts_eigenas(255);
				delay(750);
				//robot.stop();
			}
		}
		else // object zichtbaar voorste sensor
		{
			if (dist_left > maat1 && dist_right > maat1 && dist_LeftSide > maat1 && dist_RightSide > maat1) { //enkel vooruit ontwijk object 
				if (dist_left > dist_right) //meeste ruimte om te ontwijken?
				{
					robot.links(255, 255);
					/*
					robot.achteruit(255);
					delay(500);
					robot.links_eigenas(255);
					delay(500);
					robot.vooruit(255);
					delay(1000);
					robot.rechts_eigenas(255);
					delay(500);
					robot.vooruit(255);*/
				}
				else
				{
					robot.rechts(255,255);
					/*
					robot.achteruit(255);
					delay(500);
					robot.rechts_eigenas(255);
					delay(500);
					robot.vooruit(255);
					delay(1000);
					robot.links_eigenas(255);
					delay(500);
					robot.vooruit(255);*/
				}
			}
			else if ((dist_left < maat1 || dist_LeftSide < maat2) && dist_right > maat1 && dist_RightSide > maat3) //object langs links en vooraan naar rechts gaan.
			{
				robot.rechts_eigenas(255);
				delay(100);
				
				//robot.stop();
			}
			else if ((dist_right < maat1 || dist_RightSide < maat2) && dist_left > maat1 && dist_LeftSide > maat3) //object langs rechts en vooraan naar links gaan.
			{
				robot.links_eigenas(255);
				delay(100);
			}
			else //geen ander uitweg? rijd achteruit en keer om.
			{
				robot.achteruit(255);
				delay(200);
				robot.rechts_eigenas(255);
				delay(750);
				robot.vooruit(255);
			}
		}
	}
}