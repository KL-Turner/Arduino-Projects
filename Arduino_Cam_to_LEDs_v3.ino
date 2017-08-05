//        Author:         Gar Waterman (Drew Lab, Pennsylvania State University, Engineering Sciences Dept.)
//        Modified by:    Aaron Winder (Drew Lab, Pennsylvania State University, Engineering Sciences Dept.)
//        Last Updated:   04/18/13
//        Purpose:        Drive camera exposure states and dual LED lighting states given input counter and (modification) switch between ttl pulses 
//                        originating from a NI BNC 2059 and a BK Precision 4017a Frequency Generator so that lights are flashing between
//                        trials and subject is not informed about when stimuli will probably occur.

//initializes pins to be represented by a variable (int <variable name> = <pin #>)
int cam = 9;  //cam output pin
int LED1 = 3;  //LED1 output pin
int LED2 = 12;  //LED2 output pin
int inp_source = 0; //Waveform Generator input for times between trials
int trial_on = 1; //Input from BNC 2059 to indicate when labview code is running
int monitor = 13;

//state variables -- could possibly rework code to work purely on reading the physical HI or LO states of pins, but easier to understand and work with by modifying state variables
int counterstate = 0;
int lastcounterstate = 0;
int lastLED1state = 0;
int lastLED2state = 0;
int trialstate = 0; // Indicates whether the trial is running or not. A state of 0 means that the labview VI is not running.
int lasttrialstate = 0;
//the setup routine runs once when sketch is uploaded to board
void setup()
{
  pinMode(cam,OUTPUT);  //sets cam pin as an output
  pinMode(LED1,OUTPUT);  //sets LED1 pin as an output
  pinMode(LED2,OUTPUT);  //sets LED2 pin as an output
  pinMode(trial_on,INPUT);
  pinMode(inp_source,INPUT);
  pinMode(monitor,OUTPUT);
}

//the loop routine runs continuously in a loop, i.e. functions NOT simultaneous, they run in order
void loop()
{
  trialstate=digitalRead(trial_on);  //looks at the state of the trial, so that it knows where to acquire its input
  digitalWrite(monitor,trialstate); //for testing purposes
  if (trialstate == HIGH)
  {
    inp_source = 5;
    if (lasttrialstate == 0)
    {
      lastLED1state = 1; // ensure that the first flash of every new trial is from LED2
      lastLED2state = 0;
    }
    lasttrialstate = 1;
  }
  else
  {
    inp_source = 0;
    lasttrialstate = 0;
  }
  counterstate=digitalRead(inp_source);  //reads state of counter pin and stores it in the 'counterstate' variable (remember this check happens at almost the clockspeed of the board, 16 MHz)
  if (counterstate != lastcounterstate)  //checks if the counter state that was just read ('counterstate') is different (from 'lastcounterstate'), i.e. if the counter has gone HI-->LO or LO-->HI
  {
    if (counterstate == HIGH)  //if the counter is HI (just went LO-->HI), then... (counter HI-->LO case under the 'else', line 46)
    {
      if (lastLED1state == 0)  //if the last state of LED1 was LO, then... (last LED 1 state LO case under 'else', line 38)
      {
        if (trialstate == HIGH) //only send pulse to camera if the trial is running
        {
          digitalWrite(cam,HIGH);
        }
        else // If trial is not running ensure only lows are sent to the camera
        {
          digitalWrite(cam,LOW);
        }
        digitalWrite(LED1,HIGH); // sending HI signal to LED1 regardless of trialstate
        lastLED1state = 1;  //conforms the state variable of LED1 to what its state is (LED1 is HI, so state variable changed to 1)
        lastLED2state = 0;  //conforms the state variable of LED2 to what its state is (LED2 is LO, so state variable changed to 0)
      }
      else  //if the last state of LED1 was HI, then...
      {
        if (trialstate == HIGH)
        {
          digitalWrite(cam,HIGH);  //now sending HI signal to cam
        }
        else
        {
          digitalWrite(cam,LOW);
        }
        digitalWrite(LED2,HIGH);  //now sending HI signal to LED2
        lastLED1state = 0;  //conforms the state variable of LED1 to what its state is (LED1 is LO, so state variable changed to 0)
        lastLED2state = 1;  //conforms the state variable of LED2 to what its state is (LED1 is HI, so state variable changed to 1)
      }      
    }
    else  //if the counter is LO (just went HI-->LO), then... (when the counter goes LO, *all* outputs should be set to LO, but no state variables change because the state variables store what each output was last time the counter was HI)
    {
      if (trialstate == HIGH)
      {
        digitalWrite(cam,LOW);  //now sending LO signal to cam
      }
      else
      {
        digitalWrite(cam,LOW); 
      }
      digitalWrite(LED1,LOW);  //now sending LO signal to LED1
      digitalWrite(LED2,LOW);  //now sending LO signal to LED2
    }
    lastcounterstate = counterstate;  //stores the current state of the counter to the last counter state variable
  }
}
