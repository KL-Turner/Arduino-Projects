//____________________________________________________________________________________________________________________________________________
// Written by Kevin L. Turner, previous contributions from Gar Waterman & Aaron Winder
// The Pennsylvania State University, Dept. of Biomedical Engineering
// https://github.com/KL-Turner
//____________________________________________________________________________________________________________________________________________
//
//   Purpose: Drive IOS IOSIOScamera exposure and dual color LED lighting given the input counter and modification switch between TTL pulses 
//            originating from LabIEW. The IOS IOSIOScamera trigger will serve as the switch for the Arduino. When the trial is over and there's a
//            temporary save-delay, a BK Precision 4017a Frequency Generator will immediately pick-up the 60 Hz flashing so that there is no
//            noticeable gap in stimuli to the animal.
//
//   Last Updated: 07/03/19
//____________________________________________________________________________________________________________________________________________

#include <Wire.h>
#include <Adafruit_MotorShield.h>
int withdraw = 2;
int dispense = 4;   
int withdrawState = LOW;
int dispenseState = LOW;
      
// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  myMotor->setSpeed(1);  // 10 rpm   
  pinMode(withdraw,INPUT);            // inputSource (pin 0) is an Input via the Waveform Generator.
  pinMode(dispense,INPUT);            // inputSource (pin 0) is an Input via the Waveform Generator.
}

void loop() 
{
  withdrawState = digitalRead(withdraw);
  dispenseState = digitalRead(dispense);
  Serial.print(withdrawState);
  Serial.println(dispenseState);
  if ((withdrawState == HIGH)&&(dispenseState == LOW)) 
  {
    myMotor->step(10,FORWARD,DOUBLE); 
  }
  else if ((withdrawState == LOW)&&(dispenseState == HIGH)) 
  {
    myMotor->step(10,BACKWARD,DOUBLE); 
  }
  else
  {
  // keep motor off
  }
}
