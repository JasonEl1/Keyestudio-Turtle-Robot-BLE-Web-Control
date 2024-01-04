String message;

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    message = Serial.readStringUntil('\n');
    Serial.println(message);
  }
}
