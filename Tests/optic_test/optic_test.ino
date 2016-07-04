#include <NewPing.h>


#include <SoftwareSerial.h>


NewPing Sensor_LV(41, 40, 20), Sensor_RV(45, 44, 20), Sensor_C(43, 42, 20), Sensor_LS(47, 46, 20), Sensor_RS(49, 48, 20);
int dist_left, dist_right, dist_center, dist_LeftSide, dist_RightSide;

SoftwareSerial bluetooth(10, 11);


void setup() {//initialiseer in auto mode
	Serial.begin(9600);
	bluetooth.begin(9600);
}

void loop() {
	getDistance();
	bluetooth.println(dist_center);
	Serial.println(dist_left);
	delay(1000);
}


void getDistance() { //deze code bepaald de afstanden die iedere sensor meet.

	dist_center = Sensor_C.ping_cm();
  delay(5);
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

		dist_center += Sensor_C.ping_cm();
    delay(5);
		dist_left += Sensor_LV.ping_cm();
   delay(5);
		dist_right += Sensor_RV.ping_cm();
    delay(5);
		dist_LeftSide += Sensor_LS.ping_cm();
   delay(5);
		dist_RightSide += Sensor_RS.ping_cm();

		dist_center = dist_center / 2;
		dist_left = dist_left / 2;
		dist_right = dist_right / 2;
		dist_LeftSide = dist_LeftSide / 2;
		dist_RightSide = dist_RightSide / 2;
		delay(5);
	}



}
