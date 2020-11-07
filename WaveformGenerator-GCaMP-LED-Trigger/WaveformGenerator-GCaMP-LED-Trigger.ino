//____________________________________________________________________________________________________________________________________________
// Written by Kevin L. Turner, previous contributions from Gar Waterman & Aaron Winder
// The Pennsylvania State University, Dept. of Biomedical Engineering
// https://github.com/KL-Turner
//____________________________________________________________________________________________________________________________________________
//
//   Purpose: Trigger 8 ThorLabs LEDD1B T-Cube LED Drivers using a square wave TTL pulse originating from a BK Precision 4017a Frequency 
//            Generator to alternatingly flash between blue and green LEDs.
//
//   Last Updated: 07/03/19
//____________________________________________________________________________________________________________________________________________

// Initializes pins to be represented by a variable (int <variable name> = <pin #>).
int blueLEDs = 3;           // blue LEDs output pin (4 T-Cube LED drivers attached to a BNC breakout board).
int greenLEDs = 12;         // green LEDs output pin (4 T-Cube LED drivers attached to a BNC breakout board).
int inputSource = 0;        // Waveform Generator - Square wave with adjustable frequency. Serves as the Input for times between trials.

// State variables.  See the void loop() function for a detailed explanation of each variable state's function.
int counterState = 0;
int prevCounterState = 0;

// The setup routine runs only once when the Arduino is turned on, sketch is uploaded to the board, or is reset.
void setup()
{
  pinMode(blueLEDs, OUTPUT);          // blue LEDs (pin 3) is an Output.
  pinMode(greenLEDs, OUTPUT);         // green LEDs (pin 12) is an Output.
  pinMode(inputSource, INPUT);        // inputSource (pin 0) is an Input via the Waveform Generator.
}

// The loop routine runs continuously, i.e. functions are not simultaneous, they run in order.
void loop()
{
  counterState = digitalRead(inputSource);   // Reads state of the inputSource pin and stores it in the 'counterState' variable
  if (counterState != prevCounterState)      // Checks if the counter state that was just read is different from previous
  {
    if (counterState == HIGH)                // If the counter is HIGH
    {
        digitalWrite(blueLEDs, HIGH);        // Sending HIGH signal to blue LEDs 
        digitalWrite(greenLEDs, LOW);        // LOW signal to green LEDs
    }
    else                                     // If the last state of blue LEDs was HIGH
    {
        digitalWrite(blueLEDs, LOW);         // Sending LOW signal to blue LEDs 
        digitalWrite(greenLEDs, HIGH);       // HIGH signal to green LEDs
    }
    prevCounterState = counterState;         // Stores the current state of the counter to the last counter state variable
  }
}
