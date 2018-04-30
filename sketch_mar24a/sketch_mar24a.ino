#include <SimpleTimer.h>
#define S0 3
#define S1 2
#define S2 5
#define S3 4
#define sensorOut 6
#define in1 7
#define in2 8
#define in3 9
#define in4 10
#define speedPin 11

int red = 0, green = 0, blue = 0;
SimpleTimer timer;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  analogWrite(speedPin, 130);
  
  Serial.begin(9600);
}
void loop() {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  red = pulseIn(sensorOut, LOW);
  //red = map(red, 40, 100, 255, 0); 
  Serial.print("R= ");
  Serial.print(red);
  Serial.print("  ");
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  green = pulseIn(sensorOut, LOW);
  //green = map(green, 115, 50, 255, 0); 
  Serial.print("G= ");
  Serial.print(green);
  Serial.print("  ");
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blue = pulseIn(sensorOut, LOW);
  //blue = map(blue, 120, 77, 255, 0); 
  Serial.print("B= ");
  Serial.print(blue);
  Serial.print("  \n");
  

  if(red < 90 && blue > 100 && green > 100) {
    Serial.print("red color\n");
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(3000);
  } else if(blue < 90 && red > 100 && green > 100) {
    Serial.print("blue color\n");
    analogWrite(speedPin, 240);
    int timerId = timer.setTimeout(3000, slowDown);
  } else if(green < 90 && red > 100 && blue > 100) {
    Serial.print("green color\n");
  } else {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }

  delay(300);
}

void slowDown() {
  analogWrite(speedPin, 140);
}
