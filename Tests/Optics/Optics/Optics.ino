/*
 Name:		Optics.ino
 Created:	3/9/2016 3:30:23 PM
 Author:	rival
*/

// the setup function runs once when you press reset or power the board
#include <NewPing.h>
NewPing Sensor_L(7, 6, 20);
int dist_left;
void setup() {
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	dist_left = Sensor_L.ping_cm();

	Serial.print("L: ");
	Serial.println(dist_left);
	delay(20);


	delay(1000);
}
