#include "Arduino.h"
#include "string.h"

class CRobot{
private:
	String name1;
	String name2;
	int fwd0;
	int fwd1;
public:
	CRobot(String vname1, String vname2, int vfwd0, int vfwd1){
		name1 = vname1;
		name2 = vname2;
		fwd0 = vfwd0;
		fwd1 = vfwd1;
	}
	void fwdUntil(){
		EmoroServo.write(SERVO_0, 1645);
		EmoroServo.write(SERVO_1, 1320);
		if(digitalRead(IO_0) == 0 && digitalRead(IO_1) == 0)
			{
				EmoroServo.write(SERVO_0,1500);
				EmoroServo.write(SERVO_1,1500);
			}
	}
	void turnRight(){
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1400);
		EmoroServo.write(SERVO_0,1400);
		while(Gyr.readDegreesZ() < 90)
		{
			Serial.println(Gyr.readDegreesZ());
			delay(100);
		}
		EmoroServo.write(SERVO_0,1500);
		EmoroServo.write(SERVO_0,1500);
	}
	void turnLeft(){
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1600);
		EmoroServo.write(SERVO_0,1600);
		while(Gyr.readDegreesZ() > 270 || Gyr.readDegreesZ() < 10)
		{
			Serial.println(Gyr.readDegreesZ());
			delay(100);
		}
		EmoroServo.write(SERVO_0,1500);
		EmoroServo.write(SERVO_0,1500);
	}
	void aboutFace(){
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1400);
		EmoroServo.write(SERVO_0,1400);
		while(Gyr.readDegreesZ() < 180)
		{
			Serial.println(Gyr.readDegreesZ());
			delay(100);
		}
		EmoroServo.write(SERVO_0,1500);
		EmoroServo.write(SERVO_0,1500);
	}
};

CRobot RohanIyer("3/c West", "3/c Sun", 1500, 1500);

void setup()
{
	InitEmoro();
	Lcd.init();
	Ultrasonic.attach(GPP_0);
	EmoroServo.attach(SERVO_0);
	EmoroServo.attach(SERVO_1);
	pinMode(IO_0, INPUT_PULLUP);
	pinMode(IO_1, INPUT_PULLUP);
}

void loop()
{

}
