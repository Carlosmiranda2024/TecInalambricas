#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

#define TRIG 9
#define ECHO 4
#define SERVO_PIN 6

RF24 radio(7, 8); // CE, CSN
const byte direccion[6] = "00001";

Servo servo;

// ESTRUCTURA COMPATIBLE
#pragma pack(push, 1)
struct Datos {
  int32_t valor;
  char clave[6];
  uint32_t contador;
};
#pragma pack(pop)

Datos data;
uint32_t contador = 0;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  servo.attach(SERVO_PIN);

  if (!radio.begin()) {
    Serial.println("NRF NO detectado");
  } else {
    Serial.println("NRF listo");
  }

  radio.setChannel(90);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_1MBPS);

  radio.openWritingPipe(direccion);
  radio.stopListening();
}

float medir() {
  radio.powerDown();

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long d = pulseIn(ECHO, HIGH, 30000);

  radio.powerUp();

  if (d == 0) return -1;
  return d * 0.034 / 2;
}

void loop() {
  for (int ang = 30; ang <= 150; ang++) {

    servo.write(ang);
    delay(100);

    float dist = medir();

    Serial.print("Angulo: ");
    Serial.print(ang);
    Serial.print(" | ");

    if (dist == -1) {
      Serial.println("ERROR");
    } else {
      Serial.print(dist);

      // Llenar datos
      data.valor = (int)dist;
      strcpy(data.clave, "12345");
      data.contador = contador++;

      // 📡 Enviar y verificar
      bool ok = radio.write(&data, sizeof(data));

      if (ok) {
        Serial.println(" | ENVIADO");
      } else {
        Serial.println(" | ERROR AL ENVIAR");
      }
    }
  }
}