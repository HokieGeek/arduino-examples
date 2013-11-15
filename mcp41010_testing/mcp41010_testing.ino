void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  int pb0 = analogRead(A0);
  int pw0 = analogRead(A2);
  int pa0 = analogRead(A1);

  Serial.print("A: ");
  Serial.print(pa0);
  Serial.print(", B: ");
  Serial.print(pb0);
  Serial.print(", W: ");
  Serial.print(pw0);
  
  Serial.println("");

  delay(1000);
}



