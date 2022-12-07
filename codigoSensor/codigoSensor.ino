#define SENSOR 5
int resp = 0;

void setup() {
  pinMode(SENSOR, INPUT);
  
}

void loop() {
  resp = digitalRead(SENSOR);
  if (resp == HIGH){
    digitalWrite(LED_BUILTIN, HIGH); 
    cont++; 
    Serial.println(cont);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW); 
  }

}
