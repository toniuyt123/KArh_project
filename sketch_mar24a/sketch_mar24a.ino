#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 2
#define greenLed 13
#define redLed 12
#define blueLed 11

int red = 0, green = 0, blue = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
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
  Serial.print("B= ")
  Serial.print(blue);
  Serial.print("  \n");
  

  if(red < 90 && blue > 100 && green > 100) {
    Serial.print("red color\n");
    digitalWrite(redLed, HIGH);
  } else if(blue < 90 && red > 100 && green > 100) {
    Serial.print("blue color\n");
    digitalWrite(blueLed, HIGH);
  } else if(green < 90 && red > 100 && blue > 100) {
    Serial.print("green color\n");
    digitalWrite(greenLed, HIGH);
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, LOW);
  }

  delay(300);
}
