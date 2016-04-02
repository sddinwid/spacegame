#ifndef COMMANDWORDS_H
#define COMMANDWORDS_H

#include <QString>
#include <QStringList>


class CommandWords
{
public:
    CommandWords();
    bool isCommand(QString text);
    void showAll();

private:
    QStringList validCommands;
};

#endif // COMMANDWORDS_H
