#ifndef LFR_H
#define LFR_H

#include <ArduinoBLE.h>
// const int ledPin = LED_BUILTIN; 
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

// bool drive;

void speedControl();
void forward();
void slowed();
void speedUp();
void turnRight();
void Stop();
void turnLeft();
void lights_off();
void green_on();
void yellow_on();
void blue_on();
void red_on();

#endif
