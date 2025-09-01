#define TRIG_PIN A0
#define ECHO_PIN A1

#define MAX_DISTANCE 200
#define OBSTACLE_DIST 20

// Pines de motores
int IN1 = 7; // motor B
int IN2 = 6; // motor B
int IN3 = 5; // motor A
int IN4 = 4; // motor A

boolean goesForward = false;
int distance = 100;

// --- Configuración de giros ---
const int TURN_DELAY = 200; // tiempo base para girar derecha
const int TURN_MULTIPLIER = 2; // multiplicador para giro izquierda si sigue obstáculo

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  Serial.println("Robot autónomo iniciado");

  for (int i = 0; i < 4; i++) {
    distance = readPing();
    delay(100);
  }
}

void loop() {
  distance = readPing();

  if (distance <= OBSTACLE_DIST) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Obstáculo detectado! Distancia: ");
    Serial.println(distance);

    moveStop();
    Serial.println("Motor detenido");
    delay(50);

    // Giro a la derecha
    turnRight(TURN_DELAY);
    distance = readPing();

    if (distance <= OBSTACLE_DIST) {
      // Obstáculo aún presente → giro a la izquierda doble
      turnLeft(TURN_DELAY * TURN_MULTIPLIER);
    }

    moveStop();
    delay(50);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    moveForward();
  }

  delay(50); // pequeño delay para estabilidad
}

// --- Lectura de distancia ---
int readPing() {
  long duration;
  int cm;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000); 
  cm = duration * 0.0343 / 2;

  if (cm == 0) cm = 250;
  return cm;
}

// --- Movimiento ---
void moveStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveForward() {
  if (!goesForward) {
    goesForward = true;
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, LOW);
    delay(5);
  }
}

void moveBackward() {
  goesForward = false;
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
  delay(5);
}

// --- Giros simples ---
void turnRight(int durationMs) {
  Serial.println("Girando a la derecha");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, HIGH);
  delay(durationMs);
  moveStop();
}

void turnLeft(int durationMs) {
  Serial.println("Girando a la izquierda");
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, LOW);
  delay(durationMs);
  moveStop();
}
