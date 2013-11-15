int blinkLedPin = 13;
int blinkLedDelay = 500;
int blinkTimes = 20;
int blinkCount = 0;

int fadePin = 9;
int brightness = 0;
int fadeAmount = 5;

int buttonPin = 2;

int potPin = A0;

void setup() {
  Serial.begin(9600);
  
  pinMode(blinkLedPin, OUTPUT);
  pinMode(fadePin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Blink
  digitalWrite(blinkLedPin, ((digitalRead(blinkLedPin) == LOW) ? HIGH : LOW));
  delay(blinkLedDelay);
    
  // Fade
  analogWrite(fadePin, brightness);
  brightness = brightness + fadeAmount;
  if (brightness == 0 || brightness == 255) {
     fadeAmount = -fadeAmount;
  }
  delay(30);
  
  // Button
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    Serial.println("Button pressed");
  }
  
  // Pot
  int potVal = analogRead(potPin);
  Serial.print("Pot value: ");
  Serial.println(potVal);
}
