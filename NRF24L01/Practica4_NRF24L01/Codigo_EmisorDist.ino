#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte direccion[6] = "00001";


#pragma pack(push, 1)
struct Datos {
  int32_t valor;
  char clave[6];
  uint32_t contador;
};
#pragma pack(pop)

Datos data;
uint32_t contadorEnvio = 0;

void setup() {

  Serial.begin(9600);
  delay(1000);

  Serial.println("=== TRANSMISOR NRF24L01 ===");

  if (!radio.begin()) {
    Serial.println("NRF24L01 NO detectado");
    while (1);
  }

  Serial.println("NRF24L01 detectado");

  radio.setChannel(90);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_1MBPS);

  radio.openWritingPipe(direccion);
  radio.stopListening();

  Serial.println("Enviando datos...");
}

void loop() {

  data.valor = random(0, 1023);
  strcpy(data.clave, "12345");

  data.contador = contadorEnvio++;

  bool ok = radio.write(&data, sizeof(data));

  Serial.print("Paquete #");
  Serial.print(data.contador);
  Serial.print(" | Valor: ");
  Serial.print(data.valor);

  if (ok) {
    Serial.println(" | Enviado");
  } else {
    Serial.println(" | Error");
  }

  delay(500);
}