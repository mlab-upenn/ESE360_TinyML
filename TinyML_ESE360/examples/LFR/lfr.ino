// Arduino Line Follower Robot Code
#include <ArduinoBLE.h>
const int ledPin = LED_BUILTIN; 
#define enA 3//Enable1 L293 Pin enA 
#define in1 2 //Motor1  L293 Pin in1 
#define in2 4 //Motor1  L293 Pin in1 
#define in3 6 //Motor2  L293 Pin in1 
#define in4 7 //Motor2  L293 Pin in1 
#define enB 5 //Enable2 L293 Pin enB 
#define R_S 8//ir sensor Right
#define L_S 9 //ir sensor Left

#define LEDR 22     
#define LEDB 24     
#define LEDG 23

void setup(){ 

Serial.begin(9600);

//setting pinModes for each of the above defined pins
pinMode(R_S, INPUT); 
pinMode(L_S, INPUT); 
pinMode(enA, OUTPUT); 
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT); 
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT);


//for the Motor driver to be able to send commands we need to ENABLE it
digitalWrite(enA, HIGH); 
digitalWrite(enB, HIGH); 
delay(1000);

//defining pinmodes for LEDs
pinMode(LED_BUILTIN, OUTPUT);  
pinMode(LEDR, OUTPUT); 
pinMode(LEDB, OUTPUT); 
pinMode(LEDG, OUTPUT); 


//setting all inputs to the motor to zero
digitalWrite(in1, LOW); //Right Motor forward Pin 
digitalWrite(in2, LOW);  //Right Motor backward Pin 
digitalWrite(in3, LOW);  //Left Motor backward Pin 
digitalWrite(in4, LOW); //Left Motor forward Pin 
}

void loop(){  

//LEDs initialization for each run
digitalWrite(LED_BUILTIN, LOW);
digitalWrite(LEDR,HIGH);
digitalWrite(LEDG,HIGH);
digitalWrite(LEDB,HIGH);

// in 1 and in2 are a pair
// in 3 and in4 are a pair

//LFR logic

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){
    forward();
} //if right and left sensors are white we call the forward function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){
  turnLeft();
} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){
  turnRight();
}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
  Stop();
} //if Right Sensor and Left Sensor are at Black color then it will call Stop function

}

void forward(){  //forward

digitalWrite(in1, HIGH); //left motor forward
digitalWrite(in2, LOW);  //left motor forward 
digitalWrite(in3, LOW);  //right motor forward
digitalWrite(in4, HIGH); //right motor forward

digitalWrite(LEDG, LOW); // if the robot gets the command FORWARD then the GREEN LED should be ON

}

void turnRight(){ //turnRight

digitalWrite(in1, HIGH);  //Right Motor forward Pin 
digitalWrite(in2, LOW); //Right Motor backward Pin  
digitalWrite(in3, HIGH);  //Left Motor backward Pin 
digitalWrite(in4, LOW); //Left Motor forward Pin 
 

digitalWrite(LEDB, LOW); // if the robot gets the command RIGHT then the BLUE LED should be ON
}

void turnLeft(){ //turnLeft

digitalWrite(in1, LOW); //Right Motor forward Pin 
digitalWrite(in2, HIGH);  //Right Motor backward Pin 
digitalWrite(in3, LOW); //Left Motor backward Pin 
digitalWrite(in4, HIGH);  //Left Motor forward Pin
 

digitalWrite(LED_BUILTIN, HIGH); // if the robot gets the command LEFT then the YELLOW BUILT IN LED should be ON
}

void Stop(){ //stop

digitalWrite(in1, LOW); //Right Motor forward Pin 
digitalWrite(in2, LOW); //Right Motor backward Pin 
digitalWrite(in3, LOW); //Left Motor backward Pin 
digitalWrite(in4, LOW); //Left Motor forward Pin 

digitalWrite(LEDR, LOW);// if the robot gets the command STOP then the RED LED should be ON 
}
