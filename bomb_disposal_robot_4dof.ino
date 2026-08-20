#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// =========================
// L298N Motor Driver Pins
// =========================
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

// =========================
// Additional Outputs
// =========================
#define FRONT_LIGHT_PIN 8
#define BACK_LIGHT_PIN 9
#define HORN_PIN 10

// PCA9685 Servo Driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// =========================
// 4-DOF Robotic Arm
// =========================
// Servo channels on PCA9685
enum ServoID {
  BASE = 0,
  SHOULDER = 1,
  ELBOW = 2,
  GRIPPER = 3
};

// Gripper positions
const int servoOpen = 250;
const int servoClose = 500;


// =========================
// Setup
// =========================
void setup() {

  Serial.begin(9600);

  // Start PCA9685
  pwm.begin();
  pwm.setPWMFreq(50);

  // Motor control pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Lights and horn
  pinMode(FRONT_LIGHT_PIN, OUTPUT);
  pinMode(BACK_LIGHT_PIN, OUTPUT);
  pinMode(HORN_PIN, OUTPUT);

  // Default servo positions
  moveServo(BASE, 350);
  moveServo(SHOULDER, 350);
  moveServo(ELBOW, 350);
  moveServo(GRIPPER, servoOpen);

  // Stop robot initially
  stopMovement();
}


// =========================
// Main Loop
// =========================
void loop() {

  if (Serial.available()) {
    char command = Serial.read();
    handleCommand(command);
  }

}


// =========================
// Command Handler
// =========================
void handleCommand(char cmd) {

  switch (cmd) {

    // Robot movement
    case 'F':
      moveForward();
      break;

    case 'B':
      moveBackward();
      break;

    case 'L':
      turnLeft();
      break;

    case 'R':
      turnRight();
      break;

    case 'S':
      stopMovement();
      break;


    // 4-DOF robotic arm movement
    case '1':
      moveServo(BASE, 300);
      break;

    case '2':
      moveServo(SHOULDER, 340);
      break;

    case '3':
      moveServo(ELBOW, 380);
      break;

    case '4':
      moveServo(GRIPPER, 300);
      break;


    // Gripper control
    case 'O':
      moveServo(GRIPPER, servoOpen);
      break;

    case 'C':
      moveServo(GRIPPER, servoClose);
      break;


    // Simulated wire-cutting action
    case 'X':
      simulateWireCut();
      break;


    // Front light
    case 'W':
      digitalWrite(FRONT_LIGHT_PIN, HIGH);
      break;

    case 'w':
      digitalWrite(FRONT_LIGHT_PIN, LOW);
      break;


    // Back light
    case 'U':
      digitalWrite(BACK_LIGHT_PIN, HIGH);
      break;

    case 'u':
      digitalWrite(BACK_LIGHT_PIN, LOW);
      break;


    // Horn
    case 'H':
      digitalWrite(HORN_PIN, HIGH);
      break;

    case 'h':
      digitalWrite(HORN_PIN, LOW);
      break;
  }
}


// =========================
// Robot Movement Functions
// =========================

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void stopMovement() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


// =========================
// Servo Control
// =========================

void moveServo(int servoNum, int position) {
  pwm.setPWM(servoNum, 0, position);
}


// =========================
// Simulated Wire Cutting
// =========================

void simulateWireCut() {

  moveServo(GRIPPER, servoClose);
  delay(500);

  moveServo(GRIPPER, servoOpen);
}
