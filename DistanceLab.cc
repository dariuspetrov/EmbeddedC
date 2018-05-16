int ledRed = 11;
int ledGreen = 10;
int ledBlue = 9;
const int trigPin = 13;
const int echoPin = 12;
int val;
int tempPin = 1;
int tempLed = 4;


// the setup routine runs once when you press reset:
void setup() {               
  // initialize the digital pin as an output.
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
pinMode(ledBlue, OUTPUT); 
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication


/
}


// the loop routine runs over and over again forever:
void loop() {
  


long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 10) {  // This is where the LED On/Off happens
    digitalWrite(ledRed,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(ledGreen,LOW);
  digitalWrite(ledBlue,LOW);
}
  if (distance >= 11 && distance <20){
    digitalWrite(ledRed,LOW);
    digitalWrite(ledBlue,LOW);
    digitalWrite(ledGreen,HIGH);
  }
  if (distance > 20 && distance < 100) {
    digitalWrite(ledRed,LOW);
    digitalWrite(ledBlue,HIGH);
    digitalWrite(ledGreen,LOW);
    }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);

  
} 


