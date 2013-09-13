/* 

AABTank - Arduino Tank Project - Android Bluetooth Controlled 

Project Information
-------------------
http://github.com/petersonlindo/AABTank
http://petersonlindo.kinja.com/AABTank-arduino-tank-project-android-bluetooth-controlled

Contact Information
-------------------
Peterson Lindo
peterson_lindo@hotmail.com

*/

#include <AFMotor.h> // Adafruit Motor Shield Library (http://github.com/adafruit/Adafruit-Motor-Shield-library)

AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

int state;		//value from bluetooth serial comm	
int flag=0;	//makes sure that the serial only prints once the state

void setup() 
{
  Serial.begin(9600);           // set up Serial library at 9600 bps  
  motor1.setSpeed(200);     // set the speed of motor 1 to 200 of 255
  motor2.setSpeed(200);     // set the speed of motor 2 to 200 of 255
}

void loop() 
{

//if some date is sent, reads it and saves in state
if(Serial.available() > 0)
{     
state = Serial.read();   
flag=0;
}   

// if the state is '0' the DC motors will turn off
if (state == '0')
{
motor1.run(RELEASE); // stopped
motor2.run(RELEASE); // stopped
	if(flag == 0)
	{
	Serial.println("Motor: off");
	flag=1;
	}
}

// if the state is '1' the DC motors will RUN FORWARD
if (state == '1') 
{
motor1.run(FORWARD); // FORWARD
motor2.run(FORWARD); // FORWARD
	if(flag == 0)
	{
	Serial.println("Motor: forward");
	flag=1;
	}
}
    
// if the state is '2' the DC motors will RUN BACKWARD
if (state == '2') 
{
motor1.run(BACKWARD); // BACKWARD
motor2.run(BACKWARD); // BACKWARD
	if(flag == 0)
	{
	Serial.println("Motor: backward");
	flag=1;
	}
}
    
// if the state is '3' the motor will turn left
if (state == '3') 
{
motor1.run(FORWARD); // FORWARD
motor2.run(BACKWARD); // BACKWARD
	if(flag == 0){
	Serial.println("Motor: left");
	flag=1;
	}
} 
    
// if the state is '4' the motor will turn right
if (state == '4') {
motor1.run(BACKWARD); // BACKWARD
motor2.run(FORWARD); // FORWARD
	if(flag == 0){
	Serial.println("Motor: right");
	flag=1;
	}
}

}//END
