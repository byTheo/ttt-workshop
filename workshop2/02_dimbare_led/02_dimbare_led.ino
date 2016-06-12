#define sensorPin A0    // select the input pin for the potentiometer
#define ledPin 3      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  delay( 50 ); // analoge pin de tijd geven om te lezen
  sensorValue = map( analogRead( sensorPin ), 0, 1023, 0, 255 );
  digitalWrite( ledPin, sensorValue );
}
