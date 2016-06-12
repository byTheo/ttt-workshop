/*
   This program reads the temperature from a LM35 when a serial command "s" is received
   and sends back the result.
*/

int LM35Pin = 0;            // select the (analog) input pin for the LM35
int ledPin = 13;            // select the (digital) pin for the LED
float temperature = 0;      // variable to store the temperature after a recalculation
int val = 0;                // variable to store the value coming from the sensor

void setup()
{
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  Serial.begin(115200);
  Serial.println("Ready");
  digitalWrite(ledPin, HIGH);
}

void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == 's')
    {
      val = analogRead(LM35Pin);    // read the value from the sensor
      temperature = (5.0 * val * 100.0)/1024.0;
      Serial.println((long)temperature);
    }
  }
}
/*
   Pretty easy isn't it? The only weird thingy is the conversion formula. Let's explain it a little bit:
   The analogRead function returns values from 0 to 1023 where 0 means 0V and 1024 means 5V.
   Bearing in mind that each 10mV is 1Â°C we have to multiply 1V by 100 to get the Â°C.
   And that's it!
*/

