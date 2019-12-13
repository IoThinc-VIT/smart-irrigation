#define mos A2
int mot = 3;
int m;
int ms;
int trigPin = 3; 
int echoPin = 4;
long duration;
int level;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(mos, INPUT);
  pinMode(mot, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  level= duration*0.034/2;
  
  m = analogRead(mos);
  ms = map(m, 1024, 0, 0, 100);
  if (ms < 50)
  {
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    analogWrite(11,255);

    Serial.print("moisture level =");
    Serial.println(ms);

    Serial.print("water level = ");
    Serial.println(level);
    delay(800);
  }
  
  if (ms > 50)
  {
    
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    analogWrite(11,0);
    
    Serial.print("moisture level = ");
    Serial.println(ms);

    Serial.print("water level = ");
    Serial.println(level);
    delay(800);
  }
}
