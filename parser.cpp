#include "QTextStream"
#include <QDebug>
#include "parser.h"
#include "commandwords.h"


Parser::Parser()
{
    commands = new CommandWords();
}

Command Parser::getCommand()
{
    QTextStream cin(stdin);

    QString userStr, word1, word2;

    qDebug() << "Enter a command: ";
    userStr = cin.readLine();
    QStringList userWords = userStr.split(" ");

    if(userWords.length() > 0 && userWords.length() < 3)
    {

        word1 = userWords[0].trimmed();
        if(userWords.length() == 2)
        {
            word2 = userWords[1].trimmed();
        }
    }
    if(commands->isCommand(word1))
    {
        return Command(word1, word2);
    }
    else
    {
        return Command(nullptr, word2);
    }

}

void Parser::showCommands()
{
    commands->showAll();
}
