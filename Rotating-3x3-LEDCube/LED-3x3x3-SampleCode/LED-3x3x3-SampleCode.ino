// Written by Onions https://forum.arduino.cc/index.php?topic=51190.0

int Abrightness = 0;
int Bbrightness = 0;
int Cbrightness = 0;
int brightness = 0;

int LED;
int layer;
int pin;
int func;


//pin declerations:
//verticle coloumbs:
#define axay 53
#define axby 52
#define axcy 51
#define bxay 46
#define bxby 47
#define bxcy 45
#define cxay 41
#define cxby 40
#define cxcy 39
//horisontal layers:
const int layerA = 9;
const int layerB = 8;
const int layerC = 10;

/* A note for pin names:
All the pins use the XY graphing formation, hence the second letter being
an x and the last being a y. Having numbers in the pin decleration confuses 
it though, so the number 1 has been replaced with the letter A, the number 2
has been replaced with the letter B and the number 3 has been replaced with the
letter C. The bottom layer is layer a, the middle is bottom b and the top layer is 
layer c. (The LEDs in each layer are arranged like this:

axcy    bxcy    cxcy

axby    bxby    cxby

axay    bxay    cxay

)

*/

void funcA();
void funcB();
void funcC();
void funcD();
void funcE();
void funcF();


void setup(){
 randomSeed(analogRead(A0));
 pinMode(axay, OUTPUT);
 pinMode(bxay, OUTPUT);
 pinMode(cxay, OUTPUT);
 pinMode(axby, OUTPUT);
 pinMode(bxby, OUTPUT);
 pinMode(cxby, OUTPUT);
 pinMode(axcy, OUTPUT);
 pinMode(bxcy, OUTPUT);
 pinMode(cxcy, OUTPUT);
}


void loop(){

 //TURN ALL PINS OFF
 digitalWrite(axay, LOW);
 digitalWrite(bxay, LOW);
 digitalWrite(cxay, LOW);
 digitalWrite(axby, LOW);
 digitalWrite(bxby, LOW);
 digitalWrite(cxby, LOW);
 digitalWrite(axcy, LOW);
 digitalWrite(bxcy, LOW);
 digitalWrite(cxcy, LOW); 
 analogWrite(layerA, 0);
 analogWrite(layerB, 0);
 analogWrite(layerC, 0);

 Abrightness = 0;
 Bbrightness = 0;
 Cbrightness = 0;

 delay(50);

 func = random(1,5);

 switch(func){
 case 1:
   funcA();
   break;

 case 2:
   funcB();
   break;

 case 3:
   funcC();

 case 4:
   funcD();
   break;

 case 5:
   funcE();
   break;
 }
}






void funcA(){

 digitalWrite(axay, HIGH);
 digitalWrite(bxay, HIGH);
 digitalWrite(cxay, HIGH);
 digitalWrite(axby, HIGH);
 digitalWrite(bxby, HIGH);
 digitalWrite(cxby, HIGH);
 digitalWrite(axcy, HIGH);
 digitalWrite(bxcy, HIGH);
 digitalWrite(cxcy, HIGH);

 for(int i = 0; i != 255; i++){
   analogWrite(layerA, Abrightness);
   Abrightness++;
   delay(1);
 }
 for(int i = 0; i != 255; i++){
   analogWrite(layerB, Bbrightness);
   Bbrightness++;
   analogWrite(layerA, Abrightness);
   Abrightness--;
   delay(1);
 }
 for(int i = 0; i != 255; i++){
   analogWrite(layerC, Cbrightness);
   Cbrightness++;
   analogWrite(layerB, Bbrightness);
   Bbrightness--;
   delay(1);
 }
 for(int i = 0; i != 255; i++){
   analogWrite(layerC, Cbrightness);
   Cbrightness--;
   delay(1);
 }
}


void funcB(){
 digitalWrite(axay, HIGH);
 digitalWrite(bxay, HIGH);
 digitalWrite(cxay, HIGH);
 digitalWrite(axby, HIGH);
 digitalWrite(bxby, HIGH);
 digitalWrite(cxby, HIGH);
 digitalWrite(axcy, HIGH);
 digitalWrite(bxcy, HIGH);
 digitalWrite(cxcy, HIGH); 

 for(int i = 0; i != 255; i++){
   analogWrite(layerA, Abrightness);
   Abrightness++;
   delayMicroseconds(500);
 }
 for(int i = 0; i < 4; i++){
   analogWrite(layerA, 255);
   delay(250);
   analogWrite(layerA, 0);
   analogWrite(layerB, 255);
   delay(250);
   analogWrite(layerB, 0);
   analogWrite(layerC, 255);
 }
}

void funcC(){
 analogWrite(layerA, 255);
 analogWrite(layerB, 255);
 analogWrite(layerC, 255);
 digitalWrite(bxby, HIGH);

 for(int i = 0; i < 2; i++){

   digitalWrite(axby, HIGH);
   digitalWrite(cxby, HIGH);

   delay(100);

   digitalWrite(axby, LOW);
   digitalWrite(cxby, LOW);
   digitalWrite(cxay, HIGH);
   digitalWrite(axcy, HIGH);

   delay(100);

   digitalWrite(cxay, LOW);
   digitalWrite(axcy, LOW);
   digitalWrite(bxcy, HIGH);
   digitalWrite(bxay, HIGH);

   delay(100);

   digitalWrite(bxcy, LOW);
   digitalWrite(bxay, LOW);
   digitalWrite(axay, HIGH);
   digitalWrite(cxcy, HIGH);

   delay(100);

   digitalWrite(axay, LOW);
   digitalWrite(cxcy, LOW);
   digitalWrite(axcy, HIGH);
   digitalWrite(cxby, HIGH);

   delay(100);

   digitalWrite(axcy, LOW);
   digitalWrite(cxby, LOW);
   digitalWrite(axcy, HIGH);
   digitalWrite(cxby, HIGH);

   delay(100);

   digitalWrite(axcy, LOW);
   digitalWrite(cxby, LOW);
   digitalWrite(bxcy, HIGH);
   digitalWrite(bxay, HIGH);

   delay(100);

   digitalWrite(bxcy, LOW);
   digitalWrite(bxay, LOW);
   digitalWrite(axay, HIGH);
   digitalWrite(cxcy, HIGH);

   delay(100);

   digitalWrite(axay, LOW);
   digitalWrite(cxcy, LOW);    
 }
}

void funcD(){
 int delayTime = 200;
 for(int i = 0; i != 10; i++){
   delayTime = delayTime - 10;
   LED = random(1,9);
   layer = random(1,3);

   switch(LED){
   case 1:
     digitalWrite(axay, HIGH);
     pin = axay;
     break;

   case 2:
     digitalWrite(axby, HIGH);
     pin = axby;
     break;

   case 3:
     digitalWrite(axcy, HIGH);
     pin = axcy;
     break;

   case 4:
     digitalWrite(bxay, HIGH);
     pin = bxay;
     break;

   case 5:
     digitalWrite(bxby, HIGH);
     pin = bxby;
     break;

   case 6:
     digitalWrite(bxcy, HIGH);
     pin = bxcy;
     break;

   case 7:
     digitalWrite(cxay, HIGH);
     pin = cxay;
     break;

   case 8:
     digitalWrite(cxby, HIGH);
     pin = cxby;
     break;

   case 9:
     digitalWrite(cxcy, HIGH);
     pin = cxcy;
     break;
   }

   switch(layer){
   case 1:
     analogWrite(layerA, 255);
     delay(delayTime);
     digitalWrite(pin, LOW);
     analogWrite(layerA, 0);
     break;

   case 2:
     analogWrite(layerB, 255);
     delay(delayTime);
     digitalWrite(pin, LOW);
     analogWrite(layerB, 0);
     break;

   case 3:
     analogWrite(layerC, 255);
     delay(delayTime);
     digitalWrite(pin, LOW);
     analogWrite(layerC, 0);
     break;
   }
 }
}

void funcE(){

 digitalWrite(axay, HIGH);
 digitalWrite(bxay, HIGH);
 digitalWrite(cxay, HIGH);
 digitalWrite(axby, HIGH);
 digitalWrite(bxby, HIGH);
 digitalWrite(cxby, HIGH);
 digitalWrite(axcy, HIGH);
 digitalWrite(bxcy, HIGH);
 digitalWrite(cxcy, HIGH); 
 for(int i = 0; 0 != 256; i++){
   analogWrite(layerA, brightness);
   analogWrite(layerB, brightness);
   analogWrite(layerC, brightness);
   brightness++;
   delay(2);
 }

 delay(250);

 for(int i = 0; 0 != 256; i++){
   analogWrite(layerA, brightness);
   analogWrite(layerB, brightness);
   analogWrite(layerC, brightness);
   brightness--;
   delay(1);
 }
}
