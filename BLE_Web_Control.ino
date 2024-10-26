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
  servo.attach(ultrasonicServoPin);
  servo.write(30);
}

void servoRight(){
    servo.write(-servo.read())
}

void forward(){
  digitalWrite(motorA_direction,HIGH);
  analogWrite(motorA_PWM,220);
  digitalWrite(motorB_direction,HIGH);
  analogWrite(motorB_PWM,220);

  delay(2000);

  analogWrite(motorA_PWM,0);
  analogWrite(motorB_PWM,0);
}

void right(){}

void backward(){}

void left(){}

void loop(){
  if(Serial.available()){
    message = Serial.readStringUntil('\n');
    Serial.println(message);

    switch(message)
    {
    case "forward": forward(); break;
    case "right": servoRight(); break;
    }
  }
}
