// C++ code
//
const int pir = 2;
const int ledPin = 11;
volatile bool motionDetected = false;

void setup()
{
  pinMode(pir, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(pir), motionDetectedISR, CHANGE);
}

void loop()
{
}

void motionDetectedISR()
{
  if (digitalRead(pir) == HIGH)
  {
    Serial.println("Motion Detected!");
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    Serial.println("Motion Ended!");
    digitalWrite(ledPin, LOW);
  }
}
