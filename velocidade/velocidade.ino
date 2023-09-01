#define SENSOR_R 2
#define SENSOR_L 3

volatile unsigned long tempoAnteriorR = 0;
volatile unsigned long tempoAnteriorL = 0;
const float distanciaPorPulso = 0.008125; 

void contaPulsoR() {
  unsigned long tempoAtual = micros(); 
  unsigned long tempoDecorrido = tempoAtual - tempoAnteriorR;
  tempoAnteriorR = tempoAtual;
  float velocidadeR = distanciaPorPulso / (tempoDecorrido / 1000000.0); 
  Serial.print("Velocidade direita: ");
  Serial.print(velocidadeR);
  Serial.println(" m/s");
}

void contaPulsoL() {
  unsigned long tempoAtual = micros(); 
  unsigned long tempoDecorrido = tempoAtual - tempoAnteriorL;
  tempoAnteriorL = tempoAtual;
  float velocidadeL = distanciaPorPulso / (tempoDecorrido / 1000000.0); 
  Serial.print("Velocidade esquerda: ");
  Serial.print(velocidadeL);
  Serial.println(" m/s");
}

void setup() {
  pinMode(SENSOR_R, INPUT);
  pinMode(SENSOR_L, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(SENSOR_R), contaPulsoR, RISING);
  attachInterrupt(digitalPinToInterrupt(SENSOR_L), contaPulsoL, RISING);
}

void loop() {
  
}
