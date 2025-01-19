#ifndef SERIAL_COMMAND_H
#define SERIAL_COMMAND_H

struct SerialCommand {
    char servo;
    int angle;
    bool isValid;
};

SerialCommand parseSerialCommand(String input);

#endif

