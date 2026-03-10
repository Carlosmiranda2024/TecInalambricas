REPORTE DE PRÁCTICA: COMUNICACIÓN INALÁMBRICA PUNTO A PUNTO
Materia: Tecnologías Inalámbricas
 Fecha: 11 de marzo de 2026

1. Participantes
Gloria Estefanía Salas Arellano

Laura Fernanda Salas Rodríguez

Carlos Adrián Torres Miranda

2. Introducción
En el desarrollo de sistemas embebidos, la comunicación inalámbrica es un pilar fundamental para el intercambio de datos en tiempo real. Este proyecto se centra en la implementación de un enlace de radiofrecuencia (RF) utilizando el módulo NRF24L01 , un transceptor de baja potencia que opera en la banda de 2.4GHz, ideal para aplicaciones de telemetría y control remoto.

3. Materiales y Equipo
Módulos: 2x NRF24L01 (Versiones estándar y PA+LNA).

Controladores: 1x ESP32 (Transmisor) y 1x Arduino Uno (Receptor).

Componentes Discretos:

1x Pulsador.

1x LED (o uso de LED integrado).

Resistencias de 220Ω y 1kΩ.

Software: Arduino IDE, Librería RF24.h.

4. Marco Teórico: El Módulo NRF24L01
Una de las claves del éxito en esta práctica es entender la diferencia entre las versiones del módulo:
Característica,NRF24L01 Estándar,NRF24L01 + PA + LNA
Componentes,Antena trazada en PCB,Antena Externa + Amplificadores
Alcance,10 - 30 metros,Hasta 1000 metros (línea de vista)
Consumo,Bajo (~12-15 mA),Alto (Picos de 115 mA)
Sensibilidad,Estándar,Alta (gracias al LNA)

5. Desarrollo de la Práctica
5.1 Configuración del Hardware
Para el Transmisor (ESP32) , se utilizó un pulsador configurado con la resistencia interna INPUT_PULLUP. La comunicación SPI se definió en los pines 18, 19, 23 y 5. Para el Receptor (Arduino) , se configuró para escuchar en la dirección "00001"y reaccionar ante la llegada del carácter '1'encendiendo el LED integrado ( LED_BUILTIN).

5.2 Implementación de Código
Se establecen parámetros críticos para asegurar la estabilidad del enlace:

Canal: 108 (fuera del rango común de WiFi para evitar interferencias).

Velocidad: 250 KBPS (mayor sensibilidad de recepción).

Potencia: RF24_PA_LOW (para pruebas de escritorio de corto alcance).

6. Conclusiones Personales
Gloria Estefania Salas Arellano: "Observé que es posible utilizar el LED integrado del microcontrolador para realizar pruebas básicas. Esto simplifica el circuito y facilita la comprobación del funcionamiento del sistema sin necesidad de cableado externo adicional."

Carlos Adrián Torres Miranda: "Comprendí que la configuración técnica (pines, canal y bitrate) es tan importante como el cableado físico. Un error en la inicialización del módulo impide totalmente el intercambio de datos."

Laura Fernanda Salas Rodríguez: "La práctica me permitió entender cómo el uso de componentes integrados agiliza el proceso de depuración en sistemas inalámbricos, asegurando que la comunicación sea estable antes de añadir más periféricos."

7. Evidencias
Repositorio: GitHub - TecInalambricas

Demostración: Vídeo en YouTube Shorts