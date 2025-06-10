#include "pitches.h"

unsigned long lastFire = 0;

//int notes[] = {NOTE_FS1, NOTE_E2, NOTE_C3, NOTE_GS4, NOTE_DS5, NOTE_A6, NOTE_B7, NOTE_CS8};
int notes[] = {NOTE_A7, NOTE_AS7, NOTE_B7, NOTE_C8, NOTE_CS8, NOTE_D8, NOTE_DS8, NOTE_GS7};

volatile int melody[100];
volatile int index;
volatile bool recording_started = false;
volatile bool play_record = false;

void setup() {
  //Grup 2
  pinMode(4, INPUT_PULLUP); //PCINT20
  pinMode(5, INPUT_PULLUP); //PCINT21
  pinMode(6, INPUT_PULLUP); //PCINT22
  pinMode(7, INPUT_PULLUP); //PCINT23

  //Grup 0
  pinMode(9, INPUT_PULLUP); //PCINT1
  pinMode(10, INPUT_PULLUP); //PCINT2
  pinMode(11, INPUT_PULLUP); //PCINT3
  pinMode(12, INPUT_PULLUP); //PCINT4

  //intreruperea pentru inregistrare va fi pe pinul 2: intreruperea - INT0
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), record, FALLING);

  //intreruperea pentru redarea melodiei inregistrate va fi pe pinul 3: intreruperea - INT1
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), play, FALLING);
  
  
  PCICR |= B00000101; //activez Grup 0: PCINT0 ... PCINT5 si Grup 2: PCINT16 ... PCINT23
  PCMSK2 |= B11110000; //pinii 7, 6, 5, 4 vor declansa intreruperi
  PCMSK0 |= B00011110; //pinii 9, 10, 11, 12 vor declansa intreruperi

}

void loop() {
  // put your main code here, to run repeatedly:

    if(play_record == true){
    for(int i = 0; i < sizeof(melody) / sizeof(int); i++){
      tone(8, melody[i], 500);
      delay(1000);    
    }
    play_record = false;    
  }

}


ISR (PCINT2_vect){

  int nota_curenta = 0;

  if(millis() - lastFire < 200){  //debounce
      return;
  }
  lastFire = millis();

  if(!digitalRead(4)){
    nota_curenta = notes[0];
  }
  if(!digitalRead(5)){
    nota_curenta = notes[1];
  }
  if(!digitalRead(6)){
    nota_curenta = notes[2];
  }
  if(!digitalRead(7)){
    nota_curenta = notes[3];
  }

  tone(8, nota_curenta, 500);

  if(recording_started == true){      
    melody[index] = nota_curenta;
    index++;
  }
}


ISR (PCINT0_vect){

  int nota_curenta = 0;

  if(millis() - lastFire < 200){  //debounce
      return;
  }
  lastFire = millis();

  if(!digitalRead(9)){
    nota_curenta = notes[4];
  }
  if(!digitalRead(10)){
    nota_curenta = notes[5];
  }
  if(!digitalRead(11)){
    nota_curenta = notes[6];
  }
  if(!digitalRead(12)){
    nota_curenta = notes[7];
  }

  tone(8, nota_curenta, 500);

  if(recording_started == true){      
    melody[index] = nota_curenta;
    index++;
  }

}

void record(){
  if(recording_started == false){
      recording_started = true;
      index = 0;
  }else{
      recording_started = false;
  }
}

void play(){
  play_record = true;
}
