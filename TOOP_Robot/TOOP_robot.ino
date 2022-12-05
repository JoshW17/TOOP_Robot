/*
 TOOP Robot project
 3/c Josh West
 3/c Matt Sun
  */

#include "Arduino.h"
#include "string.h"

class CRobot{
	//These are the private variables with our names and forward values for servo 1 and servo zero
private:
	String name1;
	String name2;
	int fwd0;
	int fwd1;
public:
	//This is the constructor that sets the values of our names and sets the forward values of the servos
	CRobot(String vname1, String vname2, int vfwd0, int vfwd1){
		name1 = vname1;
		name2 = vname2;
		fwd0 = vfwd0;
		fwd1 = vfwd1;
	}
	//fwdUntil returns nothing and has no arguments. It moves forward until it hits the black line, Then it backs up and stops.
	void fwdUntil(){
		delay(100);
		EmoroServo.write(SERVO_0,fwd0);
		EmoroServo.write(SERVO_1,fwd1);
		while(digitalRead(IO_0) == 1 && digitalRead(IO_1) == 1)
			{
				delay(100);
			}
		delay(100);
		EmoroServo.write(SERVO_0,fwd1);
		EmoroServo.write(SERVO_1,fwd0);
		int i = 0;
		while(i <= 500){
			i = i + 1;
			delay(1);
		}
		delay(100);
		EmoroServo.write(SERVO_0, 1500);
		EmoroServo.write(SERVO_1, 1500);
	}
	//Turn the robot 90 degrees to the right. No arguments, returns void
	void turnRight(){
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1100);
		EmoroServo.write(SERVO_1,1100);
		while(Gyr.readDegreesZ() < 90)
		{
			Serial.println(Gyr.readDegreesZ());
			delay(100);
		}
		EmoroServo.write(SERVO_0,1500);
		EmoroServo.write(SERVO_1,1500);
	}
	//Turns the robot 90 degrees to the left. No arguments, returns void
	void turnLeft(){
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,2200);
		EmoroServo.write(SERVO_1,2200);
		while(Gyr.readDegreesZ() > 270 || Gyr.readDegreesZ() < 10)
		{
			Serial.println(Gyr.readDegreesZ());
			delay(100);
		}
		EmoroServo.write(SERVO_0,1500);
		EmoroServo.write(SERVO_1,1500);
	}
	//Turns the robot 180 degrees to the right. No arguments, returns void
	void aboutFace(){
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1100);
		EmoroServo.write(SERVO_1,1100);
		while(Gyr.readDegreesZ() < 180)
			{
				delay(100);
			}
		EmoroServo.write(SERVO_0,1500);
		EmoroServo.write(SERVO_1,1500);
	}
	//Moves forward until either it reaches the line or senses a robot within 15cm. No arguments, returns void
	void avoid(){
		EmoroServo.write(SERVO_0, fwd0);
		EmoroServo.write(SERVO_1, fwd1);
		while((Ultrasonic.read(GPP_0) > 15) && (digitalRead(IO_0) == 1 && digitalRead(IO_1) == 1))
		{
			delay(50);
		}
		delay(100);
		EmoroServo.write(SERVO_0,fwd1);
		EmoroServo.write(SERVO_1, fwd0);
		int i = 0;
		while(i <= 500){
			i = i + 1;
			delay(1);
		}
		delay(100);
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1000);
		EmoroServo.write(SERVO_1,1000);
		while(Gyr.readDegreesZ() < 90)
		{
			Serial.println(Gyr.readDegreesZ());
			delay(100);
		}
		EmoroServo.write(SERVO_0, 1500);
		EmoroServo.write(SERVO_1, 1500);
	}
	//Displays our names
	void display(){
		Lcd.locate(0,0);
		Lcd.print(name1);
		Lcd.locate(1,0);
		Lcd.print(name2);
	}
};

//creates object bot from class CRobot
CRobot bot("3/c West", "3/c Sun", 1935, 1045);

//initializes all the sensors and the servos
void setup()
{
	InitEmoro();
	Lcd.init();
	Gyr.init();
	Gyr.resetDegrees();
	Ultrasonic.attach(GPP_0);
	EmoroServo.attach(SERVO_0);
	EmoroServo.attach(SERVO_1);
	pinMode(IO_0, INPUT_PULLUP);
	pinMode(IO_1, INPUT_PULLUP);
}

void loop()
{
	bot.display();
	//if switch one is pressed the robot will start to move
	if (ReadSwitch(SW_1)==1)
	{
		delay(200);
		bot.fwdUntil();
		delay(200);
		bot.turnRight();
		delay(200);
		bot.turnLeft();
		delay(200);
		bot.aboutFace();
		delay(200);
		//after the robot has demonstrated the required capabilities it will go into avoid mode for infinity
		while (1 == 1)
		{
		bot.avoid();
		}
	}
}
