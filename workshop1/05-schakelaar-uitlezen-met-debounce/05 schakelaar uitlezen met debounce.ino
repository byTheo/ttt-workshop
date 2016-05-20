#include <Bounce2.h>
#define BUTTON_PIN 2
#define LED_PIN 13
Bounce debouncer = Bounce(); // Instantiate a Bounce object

void setup() {
 pinMode(BUTTON_PIN,INPUT_PULLUP); // Setup the button with an internal pull-up :
 debouncer.attach( BUTTON_PIN );  // After setting up the button, setup the Bounce 
                                                     // instance :
  debouncer.interval( 5 ); // interval in ms
  pinMode(LED_PIN,OUTPUT);   //Setup the LED :
}

void loop() {
  boolean stateChanged = debouncer.update(); // Update the Bounce instance :
    int state = debouncer.read();
   if ( stateChanged && state == LOW ) { // Detect the falling edge
       if ( ledState == LOW ) {
         ledState = HIGH;
       } else {
         ledState = LOW;
       }
       digitalWrite(LED_PIN,ledState);     
   }
}