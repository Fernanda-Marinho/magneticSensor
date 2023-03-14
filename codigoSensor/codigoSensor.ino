#define SENSOR 5 //DO do sensor
int resp = 0;
int cont = 0; 
void setup() {
  Serial.begin(9600);
  pinMode(SENSOR, INPUT);
  
}

void loop() {
  resp = digitalRead(SENSOR);
  if (resp == HIGH){
    Serial.println("If1"); 
    digitalWrite(LED_BUILTIN, HIGH); 
    cont++; 
    Serial.println(cont);
  }
  else{
    Serial.println("If2");
    digitalWrite(LED_BUILTIN, LOW); 
  }

}
