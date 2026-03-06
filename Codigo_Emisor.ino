#include <SPI.h>
#include <RF24.h>

// CODIGO PARA ESP32
#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);

const byte identificacion[6] = "00001";

void setup()
{
  Serial.begin(115200);

  // Inicializar SPI del ESP32
  SPI.begin(18, 19, 23, 5); // SCK, MISO, MOSI, SS

  if (!radio.begin()) {
    Serial.println("No se detecta el NRF24L01");
    while (1);
  }

  radio.openWritingPipe(identificacion);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();

  Serial.println("Transmisor listo...");
}

void loop()
{
  const char texto[] = "Kiubo";

  bool enviado = radio.write(&texto, sizeof(texto));

  if (enviado) {
    Serial.println("Mensaje enviado");
  } else {
    Serial.println("Error al enviar");
  }

  delay(1000);
}