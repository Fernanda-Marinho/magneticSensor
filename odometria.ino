#define SENSOR 2
#define PULSOS 24.0
#define PERIMETRO 386.0

int cont = 0;
float distancia = 0.0;

void contaPulso() {
  cont++;
}
void setup() {
  pinMode(SENSOR, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(SENSOR), contaPulso, RISING);  //pega a borda de subida 
}

void loop() {
  distancia = (PERIMETRO * cont) / PULSOS; 
  Serial.print(distancia);
  Serial.println(" mm");
  //Serial.println(cont);
  delay(100);
}
