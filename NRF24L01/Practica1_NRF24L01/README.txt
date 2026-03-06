README - Comunicación Inalámbrica Arduino y ESP32 con NRF24L01

1. Descripción del proyecto

Este proyecto consiste en establecer comunicación inalámbrica entre una
placa ESP32 y una placa Arduino utilizando módulos NRF24L01. La ESP32
funciona como transmisor y envía un mensaje de texto, mientras que el
Arduino actúa como receptor y muestra el mensaje recibido en el monitor
serial.

2. Objetivo

Comprender el funcionamiento de la comunicación inalámbrica entre
microcontroladores utilizando módulos NRF24L01, así como realizar
correctamente las conexiones físicas y la programación necesaria para
transmitir datos entre dispositivos.

3. Integrantes

-   Gloria Estefania Salas Arellano
-   Carlos Adrián Torres Miranda
-   Laura Fernanda Salas Rodríguez

4. Materiales utilizados

-   1 Placa ESP32
-   1 Placa Arduino
-   Módulos NRF24L01
-   Jumpers hembra-macho
-   Jumpers hembra-hembra
-   Cable USB tipo A
-   Cable USB tipo B o USB-C

5. Funcionamiento del sistema

La comunicación se realiza mediante módulos NRF24L01 conectados a cada
microcontrolador. La ESP32 envía un mensaje utilizando comunicación SPI
hacia el módulo NRF24L01. El Arduino recibe la señal mediante su módulo
NRF24L01 y muestra el mensaje en el monitor serial.

6. Procedimiento

1.  Conectar los módulos NRF24L01 a la ESP32 y al Arduino utilizando
    jumpers.
2.  Verificar que cada pin esté conectado correctamente según el
    diagrama.
3.  Conectar ambas placas a la computadora mediante cables USB.
4.  Cargar el código transmisor en la ESP32.
5.  Cargar el código receptor en el Arduino.
6.  Abrir el monitor serial para verificar la recepción del mensaje.
7.  Comprobar que el mensaje enviado por la ESP32 aparezca en el
    Arduino.

7. Diagrama de conexión

Aquí se debe incluir el diagrama de conexión entre Arduino, ESP32 y los
módulos NRF24L01 mostrando cómo se conectan los pines CE, CSN, MOSI,
MISO, SCK, VCC y GND.

8. Código ESP32 (Transmisor)

#include <SPI.h> #include <RF24.h>

#define CE_PIN 4 #define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN); const byte identificacion[6] = “00001”;

void setup() { Serial.begin(115200); SPI.begin(18, 19, 23, 5);

if (!radio.begin()) { Serial.println(“No se detecta el NRF24L01”); while
(1); }

radio.openWritingPipe(identificacion); radio.setPALevel(RF24_PA_LOW);
radio.stopListening();

Serial.println(“Transmisor listo…”); }

void loop() { const char texto[] = “Kiubo”; bool enviado =
radio.write(&texto, sizeof(texto));

if (enviado) { Serial.println(“Mensaje enviado”); } else {
Serial.println(“Error al enviar”); }

delay(1000); }

9. Código Arduino (Receptor)

#include <SPI.h> #include <RF24.h>

RF24 radio(7, 8); const byte identificacion[6] = “00001”;

void setup() { Serial.begin(9600); radio.begin();
radio.openReadingPipe(0, identificacion); radio.setPALevel(RF24_PA_MIN);
radio.startListening(); }

void loop() { if (radio.available()) { char texto[32] = ““;
radio.read(&texto, sizeof(texto)); Serial.println(texto); } }

10. Repositorio GitHub

https://github.com/Carlosmiranda2024/TecInalambricas

11. Resultado

Se logró establecer correctamente la comunicación inalámbrica entre la
ESP32 y el Arduino mediante los módulos NRF24L01.

12. Conclusión

La práctica permitió comprender el funcionamiento de la comunicación
inalámbrica entre microcontroladores y reforzar conocimientos sobre
conexiones electrónicas, uso del protocolo SPI y programación de
dispositivos embebidos.
