const int blinkPin = 13;
const int buttonLedPin = 9;
const int buttonPin = 2;

long previousMillis = 0;
long blinkInterval = 800;

void setup() {
  pinMode(blinkPin, OUTPUT);
  pinMode(buttonLedPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Blink without delay using the obvious method
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > blinkInterval) {
    previousMillis = currentMillis;
    digitalWrite(blinkPin, !digitalRead(blinkPin));
  }
  
  // Button LED
  digitalWrite(buttonLedPin, digitalRead(buttonPin));
}
