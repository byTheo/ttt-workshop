void setup() {
  pinMode( 3, OUTPUT ); // Laat de Arduino weten 
                        // dat we pin 3 gebruiken.
}

void loop() {
  digitalWrite( 3, HIGH ); // Zet de led aan
  delay( 1000 );           // wacht 1 seconde
  digitalWrite( 3, LOW );  // zet de led uit
  delay( 1000 );           // wacht 1 seconde
}