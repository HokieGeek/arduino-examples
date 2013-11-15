/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  int bit0 = digitalRead(2);
  int bit1 = digitalRead(3);
  int bit2 = digitalRead(4);
  int bit3 = digitalRead(5);
  int bit4 = digitalRead(6);
  int bit5 = digitalRead(7);
  int bit6 = digitalRead(8);
  int bit7 = digitalRead(9);

  Serial.print("0b");
  // Serial.print("0000");
  Serial.print(bit7);
  Serial.print(bit6);
  Serial.print(bit5);
  Serial.print(bit4);
  Serial.print(bit3);
  Serial.print(bit2);
  Serial.print(bit1);
  Serial.print(bit0);
  Serial.println("");

  delay(1000);
}



