#include <Servo.h>
#define SENSOR 2
#define PERIMETRO 386.0
#define PULSOS 24.0

int cont = 0; 
int i = 0; 
float distancia = 0.0;

Servo myservo;  

void contaPulsoUp() {
  cont++;
}

void contaPulsoDown() {
  cont--;
}

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR, INPUT);
  myservo.attach(9); 

}

void loop() {
  for(i = 1300; i <= 1600; i += 1){
    myservo.writeMicroseconds(i); 
    //Serial.println(i);
    if(i > 1474){
      attachInterrupt(digitalPinToInterrupt(SENSOR), contaPulsoUp, RISING);
      delay(15);
    }
    if (i < 1474){
      attachInterrupt(digitalPinToInterrupt(SENSOR), contaPulsoDown, RISING);
      delay(15);
    }
  }
    myservo.writeMicroseconds(1474);
    distancia = (PERIMETRO * cont) / PULSOS; 
    Serial.print(distancia);
    Serial.println(" mm");
    delay(3000);
    //myservo.write(90); 
}
