# Robot Autónomo con Detección de Obstáculos y Giros Inteligentes

Este proyecto es un **robot autónomo basado en Arduino**, controlado con motores DC y un **sensor ultrasónico** para detectar obstáculos. El robot puede **avanzar, retroceder y girar automáticamente** para esquivar obstáculos sin necesidad de conexión serial.

## Características principales
- Avance automático hasta detectar un obstáculo a ≤20 cm.  
- Giro a la derecha al detectar un obstáculo y, si persiste, giro a la izquierda **doble del tiempo del giro inicial** para rodearlo.  
- LED integrado (`LED_BUILTIN`) que indica la detección de obstáculos.  
- Mensajes por consola (`Serial`) opcionales para depuración y seguimiento de estado.  
- Código escrito completamente en **Arduino puro**, sin librerías externas.  
- Fácil de adaptar para distintos motores o distancias de detección.

## Componentes usados
- Arduino Nano o similar.  
- 2 motores DC controlados por driver tipo L298N o L293D.  
- Sensor ultrasónico HC-SR04 (o equivalente).  
- LED integrado de la placa (LED_BUILTIN).

## Conexiones de pines
| Componente       | Pin en Arduino |
|-----------------|----------------|
| TRIG sensor      | A0             |
| ECHO sensor      | A1             |
| Motor A IN1      | 5              |
| Motor A IN2      | 4              |
| Motor B IN1      | 7              |
| Motor B IN2      | 6              |
| LED integrado    | LED_BUILTIN    |

> Nota: Ajusta los pines según tu driver de motores o placa Arduino.

## Funcionamiento
1. El robot avanza mientras no detecta obstáculos.  
2. Si hay un obstáculo cercano:  
   - Detiene los motores y enciende el LED.  
   - Gira a la derecha un tiempo definido (`TURN_DELAY`).  
   - Si el obstáculo persiste, gira a la izquierda el **doble del tiempo del giro anterior** (`TURN_DELAY * TURN_MULTIPLIER`).  
3. Luego continúa avanzando automáticamente.

## Código
Todo el código está en **Arduino puro** usando `pulseIn()` para medir la distancia, sin librerías externas.  
El LED y los mensajes Serial son opcionales y sirven para depuración y monitoreo.

## Uso
1. Conecta los motores y el sensor según la tabla de pines.  
2. Sube el código a tu placa Arduino Nano.  
3. Conecta la alimentación de los motores y la placa Arduino.  
4. Observa cómo el robot avanza y esquiva obstáculos de manera autónoma.

## Licencia
Este proyecto es de **uso libre**. Puedes adaptarlo y modificarlo según tus necesidades.
