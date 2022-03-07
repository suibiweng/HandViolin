#include "Notes.h"

/*UltraSonic*/
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


/*FingersInput*/
int stringsPin[4]={4,5,6,7};//Four fingers pin
int Tone[4]={NOTE_G4,NOTE_D4,NOTE_A4,NOTE_E4};//Four Strings tones
int BuzzPin=8;
float NoteDuration=10;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600);
  for(int i=0;i<4;i++){
    pinMode(stringsPin[i],INPUT);
    }
    pinMode(BuzzPin,OUTPUT);
}


void loop() {

int playToneIndex=-1;

digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)



//PlayStrings
  for(int i=0;i<4;i++){  
  if(digitalRead(stringsPin[i])==HIGH){
       playToneIndex=i;
       break;
    }
  }



  if(playToneIndex==-1){
    
    noTone(BuzzPin);
    
    }
  else{
    
   tone(BuzzPin,Tone[playToneIndex]+(distance*10));
    }

}
