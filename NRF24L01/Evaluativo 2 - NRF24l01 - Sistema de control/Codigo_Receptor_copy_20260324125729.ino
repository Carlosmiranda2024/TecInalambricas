#include <SPI.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);

const byte direccion[6] = "00001";

// MISMA ESTRUCTURA
#pragma pack(push, 1)
struct Datos {
  int32_t valor;
  char clave[6];
  uint32_t contador;
};
#pragma pack(pop)

Datos data;

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("=== RECEPTOR ESP32 NRF24L01 ===");

  
  SPI.begin(18, 19, 23, 5); // SCK, MISO, MOSI, CSN

  if (!radio.begin()) {
    Serial.println("NRF24L01 NO detectado");
    while (1);
  }

  Serial.println("NRF24L01 detectado");

  radio.setChannel(90);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_MAX);

  radio.openReadingPipe(0, direccion);

  radio.startListening();

  Serial.println("Esperando datos...");
}

void loop() {

  if (radio.available()) {

    radio.read(&data, sizeof(data));

    Serial.print("Recibido -> ");

    Serial.print("Distancia: ");
    Serial.print(data.valor);
    Serial.print(" cm | ");

    Serial.print("Contador: ");
    Serial.print(data.contador);

    if (strcmp(data.clave, "12345") == 0) {
      Serial.println(" | OBJETIVO LOCALIZADO");
    } else {
      Serial.println(" | CLAVE ERROR");
    }

  } else {
    delay(10);
  }
}