//============================================================================================================================================================       
//        Author:         Gar Waterman (Drew Lab, Pennsylvania State University, ESM)
//        Modified by:    Aaron Winder (Drew Lab, Pennsylvania State University, ESM)
//
//        Last Updated:   04/18/2013
//
//        This version was modified from the original file: "Arduino_Cam_to_LEDs_v3"
//
//        Modified by:    Kevin Turner (Drew Lab, Pennsylvania State University, Bioengineering)   
//                        Ravi Teja (Drew Lab, Pennsylvania State University, ESM)
//
//        Last Updated:   08/05/2017

//        Purpose:        Trigger 8 Thor Labs LEDD1B T-Cube LED Drivers using a square wave (TTL input) pulse originating from a BK Precision 4017a Frequency 
//                        Generator so that lights are flashing between blue and green LEDs.
//============================================================================================================================================================

// Initializes pins to be represented by a variable (int <variable name> = <pin #>).

int LED1 = 3;             // LED1 output pin (GREEN - 4 T-Cube LED drivers attached to a BNC breakout board).
int LED2 = 12;            // LED2 output pin (BLUE - 4 T-Cube LED drivers attached to a BNC breakout board).
int inp_source = 0;       // Waveform Generator - Square wave with adjustable frequency. Serves as the Input for times between trials.

// State variables.  See the void loop() function for a detailed explanation of each variable state's function.

int counterstate = 0;
int lastcounterstate = 0;

// The setup routine runs only once when the Arduino is turned on, sketch is uploaded to the board, or is reset.

void setup()
{
  pinMode(LED1, OUTPUT);          // LED1 (pin 3) is an Output.
  pinMode(LED2, OUTPUT);          // LED2 (pin 12) is an Output.
  pinMode(inp_source, INPUT);     // inp_source (pin 0) is an Input via the Waveform Generator.
}

// The loop routine runs continuously, i.e. functions are NOT simultaneous, they run in order.

void loop()
{
  counterstate = digitalRead(inp_source);    // Reads state of the inp_source pin and stores it in the 'counterstate' variable 
                                             // (remember this check happens at almost the clockspeed of the board, 16 MHz)
  if (counterstate != lastcounterstate)      // Checks if the counter state that was just read ('counterstate') is different (from 'lastcounterstate'), 
                                             // i.e. if the counter has gone HI-->LO or LO-->HI
  {
    if (counterstate == HIGH)                // If the counter is HI (just went LO-->HI), then... 
    {
        digitalWrite(LED1, HIGH);            // Sending HI signal to LED1 
        digitalWrite(LED2, LOW);             // Low signal to LED2
     }
      else                                   // If the last state of LED1 was HI, then...
    {
        digitalWrite(LED1, LOW);             // Sending LO signal to LED1 
        digitalWrite(LED2, HIGH);            // HI signal to LED2
    }
    lastcounterstate = counterstate;         // Stores the current state of the counter to the last counter state variable
  }
}
