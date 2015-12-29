// This #include statement was automatically added by the Particle IDE.
#include "VCNL4010/VCNL4010.h"

VCNL4010 controller;

void setup()
{
	Serial.begin(115200);
	controller.initialize();
}

/* This function loops forever --------------------------------------------*/
void loop()
{
	Serial.print("Light: ");
	Serial.println(controller.ambientLight());
	delay(1000);
}