PRÁCTICA: NRF24L01 - ENVÍO DE DATOS CON GENERADOR DE SEÑAL

Fecha: 16 de marzo del 2026

Participantes: - Gloria Torres Miranda - Laura Fernanda Arellano -
Carlos Adrián Salas - Estefania Salas Rodríguez

DESCRIPCIÓN DEL PROYECTO Este proyecto tiene como objetivo establecer
una comunicación inalámbrica entre dos dispositivos utilizando el módulo
NRF24L01. Un dispositivo funciona como transmisor (TX) y el otro como
receptor (RX). Los datos enviados provienen de un generador de señal y
se transmiten de forma inalámbrica hacia el dispositivo receptor.

El funcionamiento del sistema se verifica observando los datos recibidos
en el monitor serial del receptor.

OBJETIVO Implementar un sistema de comunicación inalámbrica que permita
enviar datos generados por una señal desde un dispositivo transmisor
hacia un dispositivo receptor utilizando módulos NRF24L01.

MATERIALES - 2 Módulos NRF24L01 - 2 Microcontroladores (ESP32 o 1
ESP32 + 1 Arduino) - 1 Sensor o generador de señal - Cables de
conexión - Protoboard - Computadora para monitoreo serial

INTRODUCCIÓN El módulo NRF24L01 permite establecer comunicación
inalámbrica entre microcontroladores utilizando radiofrecuencia en la
banda de 2.4 GHz. En esta práctica se implementa un sistema de
transmisión y recepción de datos donde un dispositivo envía la
información generada por una señal y el otro la recibe para mostrarla en
el monitor serial.

Este tipo de comunicación es común en aplicaciones de IoT, redes de
sensores y sistemas de control remoto.

DESARROLLO Durante la práctica se configuró un sistema de comunicación
entre dos dispositivos utilizando los módulos NRF24L01.

Se estableció la siguiente arquitectura: - Arduino como nodo transmisor
(TX) - ESP32 como nodo receptor (RX)

El transmisor se encarga de leer los datos provenientes del generador de
señal y enviarlos mediante el módulo NRF24L01.

El receptor recibe los datos transmitidos y los muestra en el monitor
serial de la computadora, permitiendo verificar que la comunicación se
estableció correctamente.

FUNCIONAMIENTO 1. El generador de señal produce los datos. 2. El
microcontrolador transmisor lee estos valores. 3. Los datos se envían de
forma inalámbrica mediante el módulo NRF24L01. 4. El receptor recibe los
datos. 5. Los valores se visualizan en el monitor serial.

RESULTADOS ESPERADOS - Establecimiento correcto de la comunicación
inalámbrica. - Recepción de los datos enviados desde el transmisor. -
Visualización continua de los valores en el monitor serial del receptor.

CONCLUSIÓN La práctica permitió comprender el funcionamiento del módulo
NRF24L01 y su implementación para la transmisión inalámbrica de datos
entre microcontroladores. Se logró establecer comunicación entre un
Arduino y un ESP32, demostrando que el sistema es capaz de enviar y
recibir información generada por una señal en tiempo real.

AUTOR Práctica académica de comunicación inalámbrica con NRF24L01.
