#include <SPI.h>
#include <RF24.h>

#define TRIG 6
#define ECHO 5

RF24 radio(7,8);

const byte direccion[6] = "00001";

void setup() {

  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.println("Iniciando transmisor...");

  if (!radio.begin()) {
    Serial.println("NRF24L01 no detectado");
    while (1);
  }

  radio.setChannel(108);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);

  radio.openWritingPipe(direccion);
  radio.stopListening();

  Serial.println("Transmisor listo...");
}

long medirDistancia() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duracion = pulseIn(ECHO, HIGH);
  long distancia = duracion * 0.034 / 2;

  return distancia;
}

void loop() {

  long distancia = medirDistancia();

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  bool enviado = radio.write(&distancia, sizeof(distancia));

  if (enviado) {
    Serial.println("Dato enviado");
  } else {
    Serial.println("Error al enviar");
  }

  delay(1000);
}