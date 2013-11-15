#include "pitches.h"

int shaveAndAHaircut[][2] = { {NOTE_C4, 4}, {NOTE_G3, 8}, {NOTE_G3, 8}, {NOTE_A3, 4}, 
                              {NOTE_G3, 4}, {0, 4}, {NOTE_B3, 4}, {NOTE_C4, 4} };
int beethovenFifth[][2] = { {NOTE_G3, 8}, {NOTE_G3, 8}, {NOTE_G3, 8}, {NOTE_E3, 1},
                            {NOTE_F3, 8}, {NOTE_F3, 8}, {NOTE_F3, 8}, {NOTE_D3, 1} };

const int speakerPin = 8;
const int buttonPin = 2;
const int ledPin = 9;

boolean playing = false;
void playMelody(int melody[][2], int numNotes) {
  playing = true;
  for (int thisNote = 0; thisNote < numNotes; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    int noteDuration = 1000/melody[thisNote][1];
    tone(speakerPin, melody[thisNote][0], noteDuration);

    // to distinguish the notes, set a minimum time between them. the note's duration + 30% seems to work well:
    delay(noteDuration * 1.30);
    noTone(speakerPin);
  }
  playing = false;
}

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonVal = digitalRead(buttonPin);
  digitalWrite(ledPin, buttonVal);
  if (buttonVal == HIGH && !playing) {
    playMelody(shaveAndAHaircut, 8);
    delay(1000);
    playMelody(beethovenFifth, 8);
  }
}
