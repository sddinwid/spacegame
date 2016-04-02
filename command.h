#ifndef COMMAND_H
#define COMMAND_H

#include <QString>

class Command
{
public:
    Command(QString firstword, QString secondword);
    QString getCommandWord();
    QString getSecondWord();
    void setCommandWord(QString word);
    void setSecondWord(QString word);
    bool isUnknown();
    bool hasSecondaryWord();

private:
    QString commandWord;
    QString secondWord;
};

#endif // COMMAND_H
