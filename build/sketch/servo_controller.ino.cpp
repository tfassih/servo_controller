#include <Arduino.h>
#line 1 "C:\\dev\\arduino\\servo_controller\\servo_controller.ino"
#include "ServoController.h"
#include "SerialCommand.h"

const int SERVO_A_PIN = 9;
const int SERVO_B_PIN = 10;

ServoController servoA(SERVO_A_PIN);
ServoController servoB(SERVO_B_PIN);

#line 10 "C:\\dev\\arduino\\servo_controller\\servo_controller.ino"
void setup();
#line 20 "C:\\dev\\arduino\\servo_controller\\servo_controller.ino"
void loop();
#line 10 "C:\\dev\\arduino\\servo_controller\\servo_controller.ino"
void setup()
{
    Serial.begin(9600);

    servoA.attach();
    servoB.attach();

    Serial.println("ENTER COMMAND");
}

void loop()
{
	if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n');
        input.trim();

        SerialCommand cmd = parseSerialCommand(input);

        if (cmd.isValid) {
            if (cmd.servo == 'A') {
                servoA.setAngle(cmd.angle);
                Serial.print("Servo A set to: ");
                Serial.println(cmd.angle);
            } else if (cmd.servo == 'B') {
                servoB.setAngle(cmd.angle);
                Serial.print("Servo B set to: ");
                Serial.println(cmd.angle);
            }
        } else {
            Serial.println("ERROR");
        }
    }
}

