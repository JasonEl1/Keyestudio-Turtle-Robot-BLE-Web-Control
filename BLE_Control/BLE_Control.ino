String message;

#define motorA_direction 9     //direction control pin of A motor / L
#define motorA_PWM 2   //PWM control pin of A motor

#define motorB_direction 4    //direction control pin of B motor
#define motorB_PWM 5   //PWM control pin of B motor / R

#include <Servo.h>
Servo servo;

#define ultrasonicServoPin A3

void setup(){
  Serial.begin(9600);
  pinMode(ultrasonicServoPin, OUTPUT);
  pinMode(motorA_direction, OUTPUT);
  pinMode(motorA_PWM,OUTPUT);
  pinMode(motorB_direction,OUTPUT);
  pinMode(motorB_PWM,OUTPUT);
  servo.attach(ultrasonicServoPin);
  servo.write(180);
}

void servoRight(){
    servo.write(30);
}

void forward(){
  digitalWrite(motorA_direction,HIGH);
  analogWrite(motorA_PWM,10);
  digitalWrite(motorB_direction,LOW);
  analogWrite(motorB_PWM,200);
}

void stopMotors(){
  digitalWrite(motorA_direction,LOW);
  analogWrite(motorA_PWM,0);
  digitalWrite(motorB_direction,LOW);
  analogWrite(motorB_PWM,0);
  }



/*void right(){}

void backward(){}

void left(){}*/

void loop(){
  if(Serial.available()){
    message = Serial.readStringUntil('\n');


    if(message == "forward"){
      forward();
    }
    else if(message == "right"){
      servo.write(200);
      }
    else if(message == "left"){
      servo.write(160);
      }
     else if(message == "backward"){
      stopMotors();
     }
     else{
      Serial.println(message);
     }


  }
}
