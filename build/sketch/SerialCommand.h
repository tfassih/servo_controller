#line 1 "C:\\dev\\arduino\\servo_controller\\SerialCommand.h"
#ifndef SERIAL_COMMAND_H
#define SERIAL_COMMAND_H

struct SerialCommand {
    char servo;
    int angle;
    bool isValid;
};

SerialCommand parseSerialCommand(String input);

#endif

