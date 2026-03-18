#include <SPI.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);

const byte direccion[6] = "00001";


#pragma pack(push, 1)
struct Datos {
  int32_t valor;
  char clave[6];
  uint32_t contador;
};
#pragma pack(pop)

Datos data;

int ultimoContador = -1;
int recibidos = 0;
int perdidos = 0;

void setup() {

  Serial.begin(115200);
  delay(2000);

  Serial.println("=== RECEPTOR ESP32 NRF24L01 ===");

  SPI.begin(18, 19, 23, 5);

  if (!radio.begin()) {
    Serial.println("NRF24L01 NO detectado");
  } else {
    Serial.println("NRF24L01 detectado");
  }

  radio.setChannel(90);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_1MBPS);

  radio.openReadingPipe(0, direccion);
  radio.startListening();

  Serial.println("Comunicacion establecida. Esperando datos...");
}

void loop() {

  if (radio.available()) {

    radio.read(&data, sizeof(data));

    if (strcmp(data.clave, "12345") == 0) {

      recibidos++;

      if (ultimoContador != -1 && data.contador > ultimoContador + 1) {
        perdidos += (data.contador - ultimoContador - 1);
      }

      ultimoContador = data.contador;

      int total = recibidos + perdidos;
      float calidad = (recibidos * 100.0) / total;

      float distancia;

      if (calidad > 90) distancia = 1;
      else if (calidad > 80) distancia = 3;
      else if (calidad > 70) distancia = 5;
      else if (calidad > 60) distancia = 8;
      else if (calidad > 50) distancia = 10;
      else if (calidad > 40) distancia = 15;
      else distancia = 20;

      Serial.print("Paquete #");
      Serial.print(data.contador);
      Serial.print(" | Valor: ");
      Serial.print(data.valor);
      Serial.print(" | Calidad: ");
      Serial.print(calidad);
      Serial.print("% | Distancia: ");
      Serial.print(distancia);
      Serial.println(" m");

    } else {

      Serial.println("Paquete rechazado (clave incorrecta)");

    }

  } else {
    delay(200);
  }
}