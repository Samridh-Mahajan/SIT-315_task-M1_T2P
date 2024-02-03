// Define pin numbers
const int pir = 2;       // PIR sensor pin
const int ledPin = 11;   // LED pin

// Flag to indicate motion detection
volatile bool motionDetected = false;

void setup()
{
  // Initialize pin modes
  pinMode(pir, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);

  // Attach interrupt to PIR sensor pin for motion detection
  attachInterrupt(digitalPinToInterrupt(pir), motionDetectedISR, CHANGE);
}

void loop()
{
  // Empty loop as we're using interrupts for motion detection
}

// Interrupt Service Routine (ISR) for motion detection
void motionDetectedISR()
{
  // Check if PIR sensor is triggered
  if (digitalRead(pir) == HIGH)
  {
    // Motion detected
    Serial.println("Motion Detected!");
    digitalWrite(ledPin, HIGH); // Turn on LED
  }
  else
  {
    // Motion ended
    Serial.println("Motion Ended!");
    digitalWrite(ledPin, LOW);  // Turn off LED
  }
}
