const int analogOutPin = 11; // Analog output pin that the LED is attached to

int outputValue = 0;        // value output to the PWM (analog out)
int dir = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);   // set the LED on
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(500);     
  
  analogWrite(analogOutPin, outputValue);
  
  if (dir == 0) 
    outputValue++;
  else
    outputValue--;
    
  if (outputValue == 0)
     dir = 0;
  else if (outputValue == 255)
     dir = 1;  
     
  Serial.print("output = ");
  Serial.println(outputValue);   

  delay(1000);                     
}
