#line 1 "C:\\dev\\arduino\\servo_controller\\SerialCommand.cpp"
#include "SerialCommand.h"

SerialCommand parseSerialCommand(String input) {
    SerialCommand cmd = {'\0', 0, false};

    if (input.length() < 4 || input[0] != 'S' || input[2] != ':') {
        return cmd;
    }

    char servoId = input[1];
    if (servoId != 'A' && servoId != 'B') {
        return cmd;
    }

    String angleStr = input.substring(3);
    int angle = angleStr.toInt();

    cmd.servo = servoId;
    cmd.angle = angle;
    cmd.isValid = true;

    return cmd;
}