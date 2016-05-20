#define LED_PIN 3
#define interval 1000
int i = 0;

void setup() {
  pinMode( LED_PIN, OUTPUT ); // Laat de Arduino weten dat we pin 3 gebruiken.
}
void loop() {
  for ( ; i <= 255; i++ ) {
    analogWrite( LED_PIN, i );
    delay( interval );
  }
  for ( ; i >= 0; i-- ) {
    analogWrite( LED_PIN, i );
    delay( interval );
  }
}