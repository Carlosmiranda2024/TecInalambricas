#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte direccion[6] = "00001";

void setup() {

  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("Iniciando receptor...");

  if (!radio.begin()) {
    Serial.println("NRF24L01 no detectado");
    while (1);
  }

  radio.setChannel(108);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);

  radio.openReadingPipe(0, direccion);
  radio.startListening();

  Serial.println("Receptor listo...");
}

void loop() {

  if (radio.available()) {

    char dato;

    radio.read(&dato, sizeof(dato));

    Serial.print("Mensaje recibido: ");
    Serial.println(dato);

    if (dato == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
    }

  }
}