define buttonPin 2     // the number of the pushbutton pin
define ledPin 13      // the number of the LED pin
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);  // initialize the LED 
                                            // pin as an output
  pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input
}

void loop() {
 buttonState = digitalRead(buttonPin);   // read the state of the pushbutton value:
  // check if the pushbutton is pressed.
 if (buttonState == HIGH) {   // if it is, the buttonState is HIGH:
    digitalWrite(ledPin, HIGH);  // turn LED on:
  } else {
  digitalWrite(ledPin, LOW); // turn LED off:
  }
}