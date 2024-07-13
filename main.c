// Pin definitions
const int mq2Pin = A0; // Digital pin for MQ-2 sensor
const int buzzerPin = 8; // Digital pin for buzzer
const int relayPin = 4; // Digital pin for relay module
const int servoPin = 9; // Digital pin for servo motor
#include <Servo.h>
Servo myservo; // Create servo object
void setup() {
pinMode(mq2Pin, INPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(relayPin, OUTPUT);
pinMode(servoPin, OUTPUT);
myservo.attach(servoPin); // Attaching the servo motor
}
void loop() {
// Reading from MQ-2 sensor
int gasValue = digitalRead(mq2Pin);
// If gas is detected
if (gasValue == LOW) {
activateAlarm(); // Activate alarm
activateRelay(); // Activate relay module
turnOnServo(); // Turn on servo motor
} else {
deactivateAlarm(); // Deactivate alarm
deactivateRelay(); // Deactivate relay module
turnOffServo(); // Turn off servo motor
}
}
void activateAlarm() {
digitalWrite(buzzerPin, LOW); // Turn on buzzer
}
void deactivateAlarm() {
digitalWrite(buzzerPin, HIGH); // Turn off buzzer
}
void activateRelay() {
digitalWrite(relayPin, LOW); // Activate relay module
}
void deactivateRelay() {
digitalWrite(relayPin, HIGH); // Deactivate relay module
}
void turnOnServo() {
myservo.write(0); // Rotate servo motor to 90 degrees
}
void turnOffServo() {
myservo.write(90); // Rotate servo motor to 0 degrees
}