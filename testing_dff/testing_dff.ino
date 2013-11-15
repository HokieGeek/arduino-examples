const int ledPin = 13;
const int clockPin = 4;
const int qPin = 7;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(qPin, INPUT);
}

void loop() {
    digitalWrite(clockPin, HIGH);
    delay(1);
    digitalWrite(clockPin, LOW);

    int qVal = digitalRead(qPin);
    Serial.print("Q = ");
    Serial.println((qVal == HIGH) ? "HIGH" : "LOW");
    digitalWrite(ledPin, qVal);
    delay(3000);
}

