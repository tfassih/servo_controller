#include "ServoController.h"

ServoController::ServoController(int servoPin, int minServoAngle, int maxServoAngle) {
    pin = servoPin;
    minAngle = minServoAngle;
    maxAngle = maxServoAngle;
    currentAngle = 90;
}

void ServoController::attach() {
    servo.attach(pin);
    servo.write(currentAngle);
}

void ServoController::setAngle(int angle) {
    if (isValidAngle(angle)) {
        currentAngle = angle;
        servo.write(angle);
    }
}

int ServoController::getCurrentAngle() {
    return currentAngle;
}

bool ServoController::isValidAngle(int angle) {
    return angle >= minAngle && angle <= maxAngle;
}