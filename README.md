# carro-robot-evasor-de-obstaculos-Arduino

Este proyecto es un robot autónomo basado en Arduino, controlado con motores DC y un sensor ultrasónico para detectar obstáculos. El robot puede avanzar, retroceder y girar automáticamente para esquivar obstáculos sin necesidad de conexión serial.

Características principales:

Avance automático hasta detectar un obstáculo a ≤20 cm.

Giro a la derecha al detectar un obstáculo y, si persiste, giro a la izquierda doble del tiempo del giro inicial para rodearlo.

LED integrado (LED_BUILTIN) que indica la detección de obstáculos.

Mensajes por consola (Serial) opcionales para depuración y seguimiento de estado.

Código escrito completamente en Arduino puro; no requiere librerías externas.

Fácil de adaptar para distintos motores o distancias de detección.

Componentes usados:

Arduino Nano o similar.

2 motores DC controlados por driver tipo L298N o L293D.

Sensor ultrasónico HC-SR04 (o equivalente).

LED integrado de la placa (LED_BUILTIN).

Funcionamiento:

El robot avanza mientras no detecta obstáculos.

Si hay un obstáculo cercano:

Detiene los motores y enciende el LED.

Gira a la derecha un tiempo definido.

Si el obstáculo persiste, gira a la izquierda el doble del tiempo anterior.

Luego continúa avanzando automáticamente.
