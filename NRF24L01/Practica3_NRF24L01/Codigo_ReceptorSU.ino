#include <SPI.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);

const byte direccion[6] = "00001";

void setup() {

  Serial.begin(115200);

  Serial.println("Iniciando receptor...");

  SPI.begin(18,19,23,5);

  if (!radio.begin()) {
    Serial.println("NRF24L01 no detectado");
    while (1);
  }

  radio.setChannel(108);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);

  radio.openReadingPipe(0, direccion);
  radio.startListening();

  Serial.println("Comunicacion establecida. Esperando datos...");
}

void loop() {

  if (radio.available()) {

    long distancia;

    radio.read(&distancia, sizeof(distancia));

    Serial.print("Distancia recibida: ");
    Serial.print(distancia);
    Serial.println(" cm");
  }

}