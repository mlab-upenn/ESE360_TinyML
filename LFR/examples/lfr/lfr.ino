// Arduino Line Follower Robot Code
#include <ArduinoBLE.h>
#include "lfr.h"

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
  lights_off();  
  // in 1 and in2 are a pair
  // in 3 and in4 are a pair
  main_lfr();
  
}