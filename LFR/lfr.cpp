
#include "lfr.h"
// drive = true;

void main_lfr()
{
//LFR logic
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
   //slowed();
    //delay(1000);
   forward();
} //if right and left sensors are white we call the forward function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){
  turnRight();
} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){
  turnLeft();
}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){
  Stop();
} //if Right Sensor and Left Sensor are at Black color then it will call Stop function
}

//speed control using PWM
void speedControl(int speed){
  analogWrite(enA,speed);
  analogWrite(enB,speed);
}
void forward(){  //forward
  // green_on();
  // if(!drive){return;}
  speedControl(170);//full speed
  digitalWrite(in1, HIGH); //left motor forward
  digitalWrite(in2, LOW);  //left motor forward 
  digitalWrite(in3, LOW);  //right motor forward
  digitalWrite(in4, HIGH); //right motor forward
}
void slowed(){  //slowed
  // green_on();
  // if(!drive){return;}
  speedControl(150);//slow speed
  digitalWrite(in1, HIGH); //left motor forward
  digitalWrite(in2, LOW);  //left motor forward 
  digitalWrite(in3, LOW);  //right motor forward
  digitalWrite(in4, HIGH); //right motor forward
}

void speedUp(){  //slowed
//  green_on();
  // if(!drive){return;}
  speedControl(240);//slow speed
  digitalWrite(in1, HIGH); //left motor forward
  digitalWrite(in2, LOW);  //left motor forward 
  digitalWrite(in3, LOW);  //right motor forward
  digitalWrite(in4, HIGH); //right motor forward
}
void turnRight(){ //turnRight
  // blue_on();
  // if(!drive){return;}
  speedControl(190);
  digitalWrite(in1, HIGH);  //Right Motor forward Pin 
  digitalWrite(in2, LOW); //Right Motor backward Pin  
  digitalWrite(in3, HIGH);  //Left Motor backward Pin 
  digitalWrite(in4, LOW); //Left Motor forward Pin 
}

void turnLeft(){ //turnLeft
  // yellow_on();
  // if(!drive){return;}
  speedControl(190);
  digitalWrite(in1, LOW); //Right Motor forward Pin 
  digitalWrite(in2, HIGH);  //Right Motor backward Pin 
  digitalWrite(in3, LOW); //Left Motor backward Pin 
  digitalWrite(in4, HIGH);  //Left Motor forward Pin
}

void Stop(){ //stop
  // red_on();
  // if(!drive){return;}
  digitalWrite(in1, LOW); //Right Motor forward Pin 
  digitalWrite(in2, LOW); //Right Motor backward Pin 
  digitalWrite(in3, LOW); //Left Motor backward Pin 
  digitalWrite(in4, LOW); //Left Motor forward Pin 
}

void lights_off(){
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LEDR,HIGH);
  digitalWrite(LEDG,HIGH);
  digitalWrite(LEDB,HIGH);  
}

void yellow_on(){
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LEDR,HIGH);
  digitalWrite(LEDG,HIGH);
  digitalWrite(LEDB,HIGH);  
}

void green_on(){
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LEDR,HIGH);
  digitalWrite(LEDG,LOW);
  digitalWrite(LEDB,HIGH);  
}

void blue_on(){
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LEDR,HIGH);
  digitalWrite(LEDG,HIGH);
  digitalWrite(LEDB,LOW);  
}

void red_on(){
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LEDR,LOW);
  digitalWrite(LEDG,HIGH);
  digitalWrite(LEDB,HIGH);  
}
