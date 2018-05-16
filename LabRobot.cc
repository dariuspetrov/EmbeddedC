/*  
  L298N Motor Demonstration
  L298N-Motor-Demo.ino
  Demonstrates functions of L298N Motor Controller
  
  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/
  

// Motor A

int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B

int enB = 3;
int in3 = 5;
int in4 = 4;

const int trigPin = 13;
const int echoPin = 12;

const int trigPinS = 11;
const int echoPinS = 10;

void setup()

{

  // Set all the motor control pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//Serial.begin(9600); // Starts the serial communication
pinMode(trigPinS, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPinS, INPUT); // Sets the echoPin as an Input
//Serial.begin(9600); // Starts the serial communication


}

void demoOne()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 200 out of possible range 0~255

  analogWrite(enA, 200);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 200 out of possible range 0~255

  analogWrite(enB, 200);

  delay(2000);

  // Now change motor directions

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 

  //delay(200);

  // Now turn off motors

  

}

void demoTwo()

{

  // This function will run the motors across the range of possible speeds
  // Note that maximum speed is determined by the motor itself and the operating voltage

  // Turn on motors

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 

  // Accelerate from zero to maximum speed

  /*for (int i = 0; i < 256; i++)

  {

    

    delay(20);

  } */

  analogWrite(enA, 120);
    analogWrite(enB, 120);

   

}

void loop()

{
  long duration, distance, duration2,distance2;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  digitalWrite(trigPinS, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPinS, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPinS, LOW);
  duration2 = pulseIn(echoPinS, HIGH);
  distance2 = (duration2/2) / 29.1;
  
  if (distance < 10) {  

    digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
  demoOne();

  
}
if(distance2 <10){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
   demoTwo();

  
}

  


 

}
