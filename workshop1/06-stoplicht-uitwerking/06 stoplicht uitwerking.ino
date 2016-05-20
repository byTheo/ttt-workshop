#include <Bounce2.h>

#define RED_LED 5
#define ORANGE_LED 4
#define GREEN_LED 3
#define SWITCH 2

#define RED_STATE 1
#define YELLOW_STATE 2
#define GREEN_STATE 3

#define GREENLIGHT_ACTIVE 5000
#define YELLOWLIGHT_ACTIVE 2000

int state = RED_STATE;
Bounce debouncer = Bounce(); // Instantiate a Bounce object

void setup() {
  Serial.begin( 115200 );
  pinMode( RED_LED, OUTPUT );
  pinMode( ORANGE_LED, OUTPUT );
  pinMode( GREEN_LED, OUTPUT );
  pinMode( SWITCH, INPUT );
  digitalWrite( SWITCH,HIGH );
  // After setting up the button, setup the Bounce instance :
  debouncer.attach( SWITCH );
  debouncer.interval( 5 ); // interval in ms
  adjustLights();
}

int state = RED_STATE;
Bounce debouncer = Bounce(); // Instantiate a Bounce object

void setup() {
  Serial.begin( 115200 );
  pinMode( RED_LED, OUTPUT );
  pinMode( ORANGE_LED, OUTPUT );
  pinMode( GREEN_LED, OUTPUT );
  pinMode( SWITCH, INPUT );
  digitalWrite( SWITCH,HIGH );
  // After setting up the button, setup the Bounce instance :
  debouncer.attach( SWITCH );
  debouncer.interval( 5 ); // interval in ms
  adjustLights();
}

void adjustLights() {
  digitalWrite( RED_LED, LOW );
  digitalWrite( ORANGE_LED, LOW );
  digitalWrite( GREEN_LED, LOW );
  switch ( state ) {
    case RED_STATE :    
      digitalWrite( RED_LED, HIGH );
      break;
    case YELLOW_STATE : 
      for ( int i = 0; i < 4; i++ ) {
        digitalWrite( ORANGE_LED, HIGH );
        delay( YELLOWLIGHT_ACTIVE  / 8 );
        digitalWrite( ORANGE_LED, LOW );
        delay( YELLOWLIGHT_ACTIVE  / 8 );
      }
      break;
    case GREEN_STATE : 
      digitalWrite( GREEN_LED, HIGH );
      delay( GREENLIGHT_ACTIVE );
      break; 
  }
}

void loop() {
  boolean stateChanged = debouncer.update(); // Update the Bounce instance :
  int value = debouncer.read(); // Get the updated value :
  if ( stateChanged && value == LOW ) { // remember pullup
    state = GREEN_STATE;
    adjustLights();
    state = YELLOW_STATE;
    adjustLights();
    state = RED_STATE;
    adjustLights();
  }
}

