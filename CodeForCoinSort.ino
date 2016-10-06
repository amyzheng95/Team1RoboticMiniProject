#include <Servo.h>
#include "HX711.h"
//Load cell --------------
#define DOUT  3
#define CLK  2
HX711 scale(DOUT, CLK);
float calibration_factor = -7050; //-7050 worked for my 440lb max scale setup
//---------------------

Servo servoBig;  // create servo object to control a servo
Servo servoSmall;

// variable to store the servo position
int servoBigPos = 0;    
int servoSmallPos = 0;

const int loadCellVolt = 3;

void setup() {
  //load cell reading
  scale.set_scale();
  scale.tare();  //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
  //-----------------------
  
  servoBig.attach(A0);  // attaches the servo on pin 9 to the servo object
  servoSmall.attach(A1); 
}

void loop() {
  
  int posBig = 0;
  int posSmall = 0;
  servoBig.write(posBig);
  servoSmall.wrote(posSmall);
  
  if(loadCellVolt < )
  {
    posBig = 35;
    servoBig.write(posBig);
    delay(3000);
    posSmall = 180;
    servoSmall.write(posSmall);
  }
  
  else if (loadCellVolt < )
  {
    posBig = 70;
    servoBig.write(posBig);
    delay(3000);
    posSmall = 180;
    servoSmall.write(posSmall);    
  }
  
  else if (loadCellVolt < )
  {
    posBig = 105;
    servoBig.write(posBig);
    delay(3000);
    posSmall = 180;
    servoSmall.write(posSmall);    
  }
  
  else if (loadCellVolt < )
  {
    posBig = 140;
    servoBig.write(posBig);
    delay(3000);
    posSmall = 180;
    servoSmall.write(posSmall);    
  }
  
    else (loadCellVolt < )
  {
    posBig = 175;
    servoBig.write(posBig);
    delay(3000);
    posSmall = 180;
    servoSmall.write(posSmall);    
  }
  //for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    //servo1.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position
  //}
  //Goes back to postion 0
  //for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    //servo1.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position
  //}
}
