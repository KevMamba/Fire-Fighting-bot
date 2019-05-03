
#include <Servo.h>

#include<SoftwareSerial.h>

int sensorPin = A0; // select the input pin for the LDR

int sensorValue = 0; // variable to store the value coming from the sensor

int led = 9; // Output pin for LED

int buzzer = 12; // Output pin for Buzzer


Servo myservo;
 
int pos = 0; 

void setup() {

// declare the ledPin and buzzer as an OUTPUT:

pinMode(led, OUTPUT);

pinMode(3, OUTPUT);

pinMode(buzzer,OUTPUT);

myservo.attach(11);

myservo.write(90); 

Serial.begin(9600);

}

void loop()

{

Serial.println("Welcome to TechPonder Flame Sensor Tutorial");

sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);

if (sensorValue < 100)

{

Serial.println("Fire Detected");

Serial.println("LED on");

digitalWrite(led,HIGH);

digitalWrite(buzzer,HIGH);

digitalWrite(3, HIGH);

for (pos = 50; pos <= 130; pos += 1) { 

    myservo.write(pos); 
    
    delay(10);  
  }
  
for (pos = 130; pos >= 50; pos -= 1) { 

    myservo.write(pos); 
    
    delay(10);
  }  


delay(2000);  //wait for 5 seconds

myservo.write(90);

digitalWrite(3, LOW);

delay(1000);

}

digitalWrite(led,LOW);

digitalWrite(buzzer,LOW);

delay(sensorValue);

}
