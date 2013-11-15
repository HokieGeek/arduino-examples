const int blinkPin = 13;
const int ledPin = 9;
const int buttonPin = 2;
const int potPin = A0;
const int photoResistPin = A1;

long previousMillis = 0;
long blinkInterval = 800;

int photoResistValue = 0;         // the sensor value
int photoResistMin = 1023;        // minimum sensor value
int photoResistMax = 0;           // maximum sensor value
const int pr_numReadings = 20;

int pr_readings[pr_numReadings];      // the readings from the analog input
int pr_index = 0;                  // the index of the current reading
int pr_total = 0;                  // the running total
int pr_average = 0;                // the average

int smoothOutPhotoResistor(int val) {
  // subtract the last reading:
  pr_total = pr_total - pr_readings[pr_index];
  // read from the sensor:
  pr_readings[pr_index] = val;
  // add the reading to the total:
  pr_total= pr_total + pr_readings[pr_index];
  // advance to the next position in the array:
  pr_index++;

  // if we're at the end of the array...wrap around to the beginning:
  if (pr_index >= pr_numReadings)
    pr_index = 0;

  // calculate the average:
  return (pr_total / pr_numReadings);
}

void setup() {
  Serial.begin(9600);
  
  pinMode(blinkPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
 
  // initialize all the readings to 0:
  for (int pr_thisReading = 0; pr_thisReading < pr_numReadings; pr_thisReading++)
    pr_readings[pr_thisReading] = 0;
  
  // Calibrate the photo resistor during the first five seconds
  digitalWrite(13, HIGH); // Signal calibration
  while (millis() < 5000) {
    photoResistValue = analogRead(photoResistPin);
    if (photoResistValue > photoResistMax) photoResistMax = photoResistValue;
    if (photoResistValue < photoResistMin) photoResistMin = photoResistValue;
  }
  digitalWrite(13, LOW);
}

void loop() {
  // Blink without delay using the obvious method
  /*unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > blinkInterval) {
    previousMillis = currentMillis;
    digitalWrite(blinkPin, !digitalRead(blinkPin));
  }*/
  
  // Button LED
  digitalWrite(ledPin, digitalRead(buttonPin));
  
  // Fade LED
  /*
  int ledVal = analogRead(potPin)/4;
  Serial.println(ledVal);
  analogWrite(buttonLedPin, ledVal);
  delay(10);
  */
  
  /*
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  }*/
  
  photoResistValue = analogRead(photoResistPin);
  // apply the calibration to the sensor reading
  photoResistValue = map(smoothOutPhotoResistor(photoResistValue), photoResistMin, photoResistMax, 255, 0);
  // in case the sensor value is outside the range seen during calibration
  photoResistValue = constrain(photoResistValue, 0, 255);
  analogWrite(ledPin, photoResistValue);
}
