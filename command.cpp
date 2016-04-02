#include "command.h"

Command::Command(QString firstword, QString secondword)
{
    this->setCommandWord(firstword);
    this->setSecondWord(secondword);
}

QString Command::getCommandWord()
{
    return this->commandWord;
}

QString Command::getSecondWord()
{
    return this->secondWord;
}

void Command::setCommandWord(QString word)
{
    this->commandWord = word;
}

void Command::setSecondWord(QString word)
{
    this->secondWord = word;
}

bool Command::isUnknown()
{
    return (this->commandWord.isNull());
}

bool Command::hasSecondaryWord()
{
    return !(this->secondWord.isNull());
}
