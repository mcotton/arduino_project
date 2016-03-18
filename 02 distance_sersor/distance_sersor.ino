/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 4
 
 This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 on 10 Nov 2012.
 */


#define echoPin 4 // Echo Pin
#define trigPin 7 // Trigger Pin
#define LEDPin 13 // Onboard LED



int maximumRange = 120; // Maximum range needed
int mediumRange = 60; // Middle value
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

int redLED = 8;
int yellowLED = 9;
int greenLED = 10;


void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 pinMode(redLED, OUTPUT);
 pinMode(yellowLED, OUTPUT);
 pinMode(greenLED, OUTPUT);
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 //distance = duration/58.2;
 distance = duration/148;
 
if (distance < 360) {
// ignore anything more than 30 feet away

   if (distance > maximumRange){
   /* Send a negative number to computer and Turn LED ON 
   to indicate "out of range" */
   Serial.println(distance);
   digitalWrite(redLED, LOW); 
   digitalWrite(yellowLED, HIGH); 
   digitalWrite(greenLED, HIGH); 
   }
   
   if(distance <= maximumRange && distance > mediumRange) 
   {
     Serial.println(distance);
     digitalWrite(redLED, HIGH); 
     digitalWrite(yellowLED, LOW); 
     digitalWrite(greenLED, HIGH); 
   }
     
   if(distance <= mediumRange && distance > minimumRange) 
   {
     Serial.println(distance);
     digitalWrite(redLED, HIGH); 
     digitalWrite(yellowLED, HIGH); 
     digitalWrite(greenLED, LOW); 
   }
 } else {
     Serial.println(distance);
     digitalWrite(redLED, HIGH); 
     digitalWrite(yellowLED, HIGH); 
     digitalWrite(greenLED, HIGH);
 }
 //Delay 50ms before next reading.
 delay(50);
}
