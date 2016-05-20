// Constante voor de led pin
#define LED_PIN 3
// constante voor de duur van het interval
#define interval 1000

void setup() {
  // Laat de Arduino weten dat we 
  // de ledpin gebruiken.
  pinMode( LED_PIN, OUTPUT );
}

void loop() {
  // Zet de led aan
  digitalWrite( LED_PIN, HIGH );
  // wacht interval milliseconden
  delay( interval );
  // zet de led uit
  digitalWrite( LED_PIN, LOW ); 
  // wacht interval milliseconden
  delay( interval );          
}