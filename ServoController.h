#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <Servo.h>

class ServoController {
    private:
        Servo servo;
        int currentAngle;
        int pin;
        int minAngle;
        int maxAngle;

    public:
        ServoController(int servoPin, int minServoAngle = 0, 
                                        int maxServoAngle = 180);
        void attach();
        void setAngle(int angle);
        int getCurrentAngle();
        bool isValidAngle(int angle);
};

#endif