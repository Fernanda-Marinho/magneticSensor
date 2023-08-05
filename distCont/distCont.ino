#include <Servo.h>
#define SENSOR 2
#define PERIMETRO 386.0
#define PULSOS 24.0

int cont = 0; 
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
  myservo.attach(9); 
  //myservo.write(80); 
  myservo.writeMicroseconds(1530); //1568 (-38)
  pinMode(SENSOR, INPUT);
  attachInterrupt(digitalPinToInterrupt(SENSOR), contaPulsoUp, RISING);

}

void loop() {
  if (cont == 48){
    myservo.writeMicroseconds(1399); //1354 
    while (cont > 24){
      attachInterrupt(digitalPinToInterrupt(SENSOR), contaPulsoDown, RISING); 
    }
    distancia = (PERIMETRO * cont) / PULSOS; 
    Serial.print(distancia);
    Serial.println(" mm");
    myservo.writeMicroseconds(1474);
    delay(3000);
    //myservo.write(90); 
    
    }
}
