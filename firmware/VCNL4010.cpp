#include "VCNL4010.h"
#include "spark_wiring_usbserial.h"


void VCNL4010::initialize(){
    Wire.begin();
	Wire.beginTransmission(address);
	Wire.write(0x80);
	Wire.write(231);
	byte status = Wire.endTransmission();
	if(status != 0){
		//failed
		Serial.println("initialize failed");
	}
}

int VCNL4010::ambientLight(){
	Wire.begin();
	Wire.beginTransmission(address);
	Wire.write(0x85);
	byte status = Wire.endTransmission();
	if(status != 0){
		//failed
		return 9000;
	}
	Wire.requestFrom(address, 1);
	byte msb = Wire.read();

	Wire.begin();
	Wire.beginTransmission(address);
	Wire.write(0x86);
	byte status1 = Wire.endTransmission();
	if(status1 != 0){
		//failed
		return 9000;
	}
	Wire.requestFrom(address, 1);
	byte lsb = Wire.read();

	int reading = (msb*256)+lsb;
	return reading;
}

