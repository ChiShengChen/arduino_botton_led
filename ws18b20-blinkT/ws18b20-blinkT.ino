
#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 11

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

 // int led = 3;
  int sw = 4;//digital button
  int m = 0;//state
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(DATA_PIN, OUTPUT);
 FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
//  pinMode(led, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

     Serial.print("sw1=");
     Serial.println(digitalRead(sw));
     Serial.println("--------------------");
  
  if(digitalRead(sw)==1 && m!=2){
   m=1;  
    }    

   if(digitalRead(sw)==1 && m==2){
   m=2;  
    }    
    
  if(digitalRead(sw)== 0 && m!=4 ){
   m=3; }
  
  if(digitalRead(sw)== 0 && m==4 ){
   m=4; }

    if(digitalRead(sw)== 0 ){
   m=4; }
   
  switch(m){
    case 1:
        for(int blightness = 0; blightness < 100; ++blightness){
        for(int i = 0; i < NUM_LEDS; ++i){
          leds[i].setHSV( 0, 0, blightness );
        }
        FastLED.show();
      }
      m++;
      break;
      
    case 2:
     // analogWrite(DATA_PIN, 255);
        for(int i = 0; i < NUM_LEDS; ++i){
      leds[i].setHSV( 0, 0, 100 );
     }
    FastLED.show();
      break;
      
    case 3:
        for(int blightness = 0; blightness <= 100; blightness-- ){
        for(int i = 0; i < NUM_LEDS; ++i){
          leds[i].setHSV( 0, 0, blightness );
        }
        FastLED.show();
      }
      m++;
      break;
      
    case 4:
      for(int i = 0; i < NUM_LEDS; ++i){
          leds[i].setHSV( 0, 0, 0 );
        }
        FastLED.show();
     break;
      }
     Serial.print("m=");
     Serial.println(m);
     Serial.print("sw=");
     Serial.println(digitalRead(sw));
 }
