#include "melody.h"


// Имперский марш
void Melody(){
  int freq[39] =       {392, 392, 392, 311, 466, 392, 311, 466, 392,
                      587, 587, 587, 622, 466, 369, 311, 466, 392,
                      784, 392, 392, 784, 739, 698, 659, 622, 659,
                      415, 554, 523, 493, 466, 440, 466,
                      311, 369, 311, 466, 392
                      }; // частота нот                     

  int durations[39] =  {350, 350, 350, 250, 100, 350, 250, 100, 700, 
                      350, 350, 350, 250, 100, 350, 250, 100, 700,
                      350, 250, 100, 350, 250, 100, 100, 100, 450,
                      150, 350, 250, 100, 100, 100, 450,
                      150, 350, 250, 100, 750
                      };  // длительность нот

  // Имперский марш
  for (int thisNote = 0; thisNote < 39; thisNote++){
    int noteDuration = durations[thisNote]; //1000 / noteDurations[thisNote];  //durations[thisNote];
    tone(pinTone, freq[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(pinTone);
  }
}

// Wah-Wah-Wah-Wah sound
void MelodyGameOver() {
  tone(pinTone, NOTE_DS5);
  delay(300);
  tone(pinTone, NOTE_D5);
  delay(300);
  tone(pinTone, NOTE_CS5);
  delay(300);
  for (byte i = 0; i < 10; i++) {
    for (int pitch = -10; pitch <= 10; pitch++) {
      tone(pinTone, NOTE_C5 + pitch);
      delay(5);
    }
  }
  noTone(pinTone);
  delay(500);
}


void MelodyLevelUp() {
  tone(pinTone, NOTE_E4);
  delay(150);
  tone(pinTone, NOTE_G4);
  delay(150);
  tone(pinTone, NOTE_E5);
  delay(150);
  tone(pinTone, NOTE_C5);
  delay(150);
  tone(pinTone, NOTE_D5);
  delay(150);
  tone(pinTone, NOTE_G5);
  delay(150);
  noTone(pinTone);
}


void playUSSR() {
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 174, 374.999625);
    delay(416.66625);
    tone(tonePin, 195, 124.999875);
    delay(138.88875);
    tone(tonePin, 220, 499.9995);
    delay(555.555);
    tone(tonePin, 146, 249.99975);
    delay(277.7775);
    tone(tonePin, 146, 249.99975);
    delay(277.7775);
    tone(tonePin, 195, 499.9995);
    delay(555.555);
    tone(tonePin, 174, 374.999625);
    delay(416.66625);
    tone(tonePin, 155, 124.999875);
    delay(138.88875);
    tone(tonePin, 174, 499.9995);
    delay(555.555);
    tone(tonePin, 116, 249.99975);
    delay(277.7775);
    tone(tonePin, 116, 249.99975);
    delay(277.7775);
    tone(tonePin, 130, 499.9995);
    delay(555.555);
    tone(tonePin, 130, 374.999625);
    delay(416.66625);
    tone(tonePin, 146, 124.999875);
    delay(138.88875);
    tone(tonePin, 155, 499.9995);
    delay(555.555);
    tone(tonePin, 155, 374.999625);
    delay(416.66625);
    tone(tonePin, 174, 124.999875);
    delay(138.88875);
    tone(tonePin, 195, 499.9995);
    delay(555.555);
    tone(tonePin, 220, 374.999625);
    delay(416.66625);
    tone(tonePin, 233, 124.999875);
    delay(138.88875);
    tone(tonePin, 261, 749.99925);
    delay(833.3325);
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 293, 499.9995);
    delay(555.555);
    tone(tonePin, 261, 374.999625);
    delay(416.66625);
    tone(tonePin, 233, 124.999875);
    delay(138.88875);
    tone(tonePin, 261, 499.9995);
    delay(555.555);
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 220, 374.999625);
    delay(416.66625);
    tone(tonePin, 195, 124.999875);
    delay(138.88875);
    tone(tonePin, 220, 499.9995);
    delay(555.555);
    tone(tonePin, 146, 374.999625);
    delay(416.66625);
    tone(tonePin, 146, 124.999875);
    delay(138.88875);
    tone(tonePin, 195, 499.9995);
    delay(555.555);
    tone(tonePin, 174, 374.999625);
    delay(416.66625);
    tone(tonePin, 155, 124.999875);
    delay(138.88875);
    tone(tonePin, 174, 499.9995);
    delay(555.555);
    tone(tonePin, 116, 374.999625);
    delay(416.66625);
    tone(tonePin, 116, 124.999875);
    delay(138.88875);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 220, 374.999625);
    delay(416.66625);
    tone(tonePin, 195, 124.999875);
    delay(138.88875);
    tone(tonePin, 174, 999.999);
    delay(1111.11);
    tone(tonePin, 293, 999.999);
    delay(1111.11);
    tone(tonePin, 261, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 249.99975);
    delay(277.7775);
    tone(tonePin, 220, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 249.99975);
    delay(277.7775);
    tone(tonePin, 261, 749.99925);
    delay(833.3325);
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 174, 999.999);
    delay(1111.11);
    tone(tonePin, 233, 999.999);
    delay(1111.11);
    tone(tonePin, 220, 249.99975);
    delay(277.7775);
    tone(tonePin, 195, 249.99975);
    delay(277.7775);
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 195, 249.99975);
    delay(277.7775);
    tone(tonePin, 220, 749.99925);
    delay(833.3325);
    tone(tonePin, 146, 249.99975);
    delay(277.7775);
    tone(tonePin, 146, 999.999);
    delay(1111.11);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 195, 374.999625);
    delay(416.66625);
    tone(tonePin, 220, 124.999875);
    delay(138.88875);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 195, 374.999625);
    delay(416.66625);
    tone(tonePin, 220, 124.999875);
    delay(138.88875);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 195, 374.999625);
    delay(416.66625);
    tone(tonePin, 233, 124.999875);
    delay(138.88875);
    tone(tonePin, 311, 999.999);
    delay(1111.11);
    tone(tonePin, 311, 999.999);
    delay(1111.11);
    tone(tonePin, 293, 249.99975);
    delay(277.7775);
    tone(tonePin, 261, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 249.99975);
    delay(277.7775);
    tone(tonePin, 261, 249.99975);
    delay(277.7775);
    tone(tonePin, 293, 749.99925);
    delay(833.3325);
    tone(tonePin, 233, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 999.999);
    delay(1111.11);
    tone(tonePin, 261, 999.999);
    delay(1111.11);
    tone(tonePin, 233, 249.99975);
    delay(277.7775);
    tone(tonePin, 220, 249.99975);
    delay(277.7775);
    tone(tonePin, 195, 249.99975);
    delay(277.7775);
    tone(tonePin, 220, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 749.99925);
    delay(833.3325);
    tone(tonePin, 195, 249.99975);
    delay(277.7775);
    tone(tonePin, 195, 999.999);
    delay(1111.11);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 220, 374.999625);
    delay(416.66625);
    tone(tonePin, 195, 124.999875);
    delay(138.88875);
    tone(tonePin, 174, 499.9995);
    delay(555.555);
    tone(tonePin, 116, 374.999625);
    delay(416.66625);
    tone(tonePin, 116, 124.999875);
    delay(138.88875);
    tone(tonePin, 174, 999.999);
    delay(1111.11);
    tone(tonePin, 195, 499.9995);
    delay(555.555);
    tone(tonePin, 220, 499.9995);
    delay(555.555);
    tone(tonePin, 233, 1999.998);
    delay(2222.22);
}