#include <Servo.h>
#include "HX711.h"
//Load cell --------------Copied from the load cell file
#define DOUT  3
#define CLK  2
HX711 scale(DOUT, CLK);
float calibration_factor = -7050; //-7050 worked for my 440lb max scale setup
//---------------------------------------------

Servo servoBig;  // create servo object to control a servo
Servo servoSmall;

// variable to store the servo position
int posBig = 0;    
int posSmall = 0;
double loadCellMass;

void setup() {
  //load cell reading---------------------Copied from the load cell file
  scale.set_scale();
  scale.tare();  //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
  //-----------------------------------------------------------
  
  servoBig.attach(A0);  // attaches the servo on pin 9 to the servo object
  servoSmall.attach(A1); 
}

void loop() {
  //Reading the scale----Copied from the load cell file
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  
  if(Serial.available())// not too sure what this does, have to test it out
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
  }
  //-----------------------------------------------
  
  posBig = 0;
  posSmall = 0;
  servoBig.write(posBig);
  servoSmall.wrote(posSmall);
  
  //GET LOAD CELL MASS, STORE IN loadCellMass:
  //loadCellMass = ();
  
  if(loadCellMass < 2.5)//dime (mass = 1.75g)
  {
    posBig = 35;//positon for gear
    servoBig.write(posBig);
    delay(3000);
    posSmall = 180;//position for coin holder
    servoSmall.write(posSmall);
  }
  
  else if (loadCellMass < 4.1) //nickle (mass = 3.95g)
  {
    posBig = 70;
    servoBig.write(posBig);
    delay(3000);
    posSmall = 180;
    servoSmall.write(posSmall);    
  }
  
  else if (loadCellMass < 5.0) //quarter (mass = 4.4g)
  {
    posBig = 105;
    servoBig.write(posBig);
    delay(3000);
    posSmall = 180;
    servoSmall.write(posSmall);    
  }
  
  else if (loadCellMass < 6.5)//loonie (mass = 6.27g)
  {
    posBig = 140;
    servoBig.write(posBig);
    delay(3000);
    posSmall = 180;
    servoSmall.write(posSmall);    
  }
  
    else (loadCellMass < 7) //toonie (mass = 6.92g)
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
