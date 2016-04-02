#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include "command.h"
#include "commandwords.h"

class Parser
{
public:
    Parser();
    Command getCommand();
    void showCommands();

private:
    CommandWords *commands;

};

#endif // PARSER_H
