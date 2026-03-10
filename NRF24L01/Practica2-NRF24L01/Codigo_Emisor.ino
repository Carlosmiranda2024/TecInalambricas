#include <SPI.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5
#define BOTON 25

RF24 radio(CE_PIN, CSN_PIN);

const byte direccion[6] = "00001";

void setup() {

  Serial.begin(115200);
  delay(2000);

  pinMode(BOTON, INPUT_PULLUP);

  Serial.println("Iniciando transmisor...");

  SPI.begin(18,19,23,5);

  if (!radio.begin()) {
    Serial.println("NRF24L01 no detectado");
    while (1);
  }

  radio.setChannel(108);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);

  radio.openWritingPipe(direccion);
  radio.stopListening();

  Serial.println("Transmisor listo");
}

void loop() {

  if (digitalRead(BOTON) == LOW) {

    char dato = '1';

    bool enviado = radio.write(&dato, sizeof(dato));

    if (enviado) {
      Serial.println("Mensaje enviado");
    } else {
      Serial.println("Error al enviar");
    }

    delay(300);
  }
}