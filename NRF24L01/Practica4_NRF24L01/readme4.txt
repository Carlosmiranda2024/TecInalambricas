
---

Comunicación Inalámbrica con NRF24L01 (ESP32 + Arduino)

Descripción del proyecto

Este proyecto implementa una comunicación inalámbrica entre dispositivos utilizando módulos **NRF24L01**, configurando un sistema de transmisión (TX) y recepción (RX).

Se emplea un **Arduino como transmisor** y un **ESP32 como receptor**, donde se envían datos simulados de manera continua y se analizan aspectos como:

* Alcance de la señal
* Seguridad de la comunicación
* Calidad de transmisión

---

Descripción de la ESP32

La **ESP32** es un microcontrolador desarrollado por Espressif, ampliamente utilizado en proyectos de IoT.

Características principales:

* Conectividad **WiFi y Bluetooth integrada**
* Procesador **dual-core**
* Bajo consumo energético
* Múltiples pines GPIO
* Soporte para comunicación:

  * SPI
  * I2C
  * UART

Uso en este proyecto:

En esta práctica, la ESP32 funciona como **receptor**, encargándose de:

* Recibir datos enviados por el Arduino
* Validar la información mediante una clave
* Analizar la calidad de la señal
* Mostrar resultados en el monitor serial

---

Descripción del NRF24L01

El **NRF24L01** es un módulo de comunicación inalámbrica que opera en la banda de **2.4 GHz**.

Características principales:

* Comunicación inalámbrica de corto y medio alcance
* Bajo consumo de energía
* Comunicación mediante protocolo **SPI**
* Velocidades de transmisión configurables
* Soporte para múltiples canales

Funcionamiento:

* Un módulo actúa como **transmisor (TX)** y otro como **receptor (RX)**
* Se comunican usando una **dirección común**
* Los datos se envían en paquetes estructurados

---

Tipos de NRF24L01

| Característica | Estándar        | PA + LNA      |
| -------------- | --------------- | ------------- |
| Antena         | Integrada (PCB) | Externa (SMA) |
| Alcance        | 10–30 m         | Hasta 1000 m  |
| Consumo        | Bajo            | Alto          |
| Sensibilidad   | Normal          | Alta          |

Notas importantes:

* La versión **PA+LNA requiere antena externa**
* Sin antena, el módulo puede dañarse
* La antena externa mejora significativamente el alcance

---

Desarrollo de la práctica

 Funcionamiento:

* Arduino envía datos simulados (valores aleatorios)
* ESP32 recibe y procesa la información
* Se implementan mecanismos de control:

 Seguridad:

* Se incluye una **clave ("12345")** en cada mensaje
* El receptor valida la autenticidad

Control de paquetes:

* Cada envío incluye un **contador**
* Permite detectar pérdida de datos

 Evaluación de señal:

* Se calcula la calidad de comunicación:

```
Calidad (%) = (Paquetes recibidos / Total de paquetes) * 100
```

* Se estima la distancia según la calidad

---

Materiales utilizados

* 2 × Módulo NRF24L01
* 1 × ESP32
* 1 × Arduino
* 1 × Sensor (no utilizado en esta práctica)

---

Código

 Emisor (Arduino)

* Genera datos aleatorios
* Agrega clave de seguridad
* Incluye contador de paquetes
* Envía datos por NRF24L01

Receptor (ESP32)

* Recibe datos
* Verifica clave
* Calcula:

  * Paquetes recibidos
  * Paquetes perdidos
  * Calidad de señal
  * Distancia estimada

---

Resultados esperados

En el monitor serial del receptor se observa:

* Número de paquete
* Valor recibido
* Calidad de señal (%)
* Distancia estimada

---

 Conclusiones

### 👩 Gloria Estefania Salas Arellano

Aprendió a establecer comunicación inalámbrica y verificar datos mediante el monitor serial.

### 👨 Carlos Adrián Torres Miranda

Comprendió la configuración del NRF24L01 y el análisis de calidad de transmisión.

### 👩 Laura Fernanda Salas Rodríguez

Destacó la importancia de la seguridad (clave) y control (contador) en la comunicación.

---

Recursos

 GitHub:
  [https://github.com/Carlosmiranda2024/TecInalambricas](https://github.com/Carlosmiranda2024/TecInalambricas)

 Video:
  [https://youtube.com/shorts/FN1uM9AhQnM?feature=share](https://youtube.com/shorts/FN1uM9AhQnM?feature=share)

---

 Notas finales

Este proyecto demuestra cómo implementar una comunicación inalámbrica confiable, incorporando:

* Seguridad básica
* Control de integridad
* Evaluación de alcance

Ideal como base para proyectos de **IoT y sistemas embebidos**.

---


