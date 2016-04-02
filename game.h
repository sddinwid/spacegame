#ifndef GAMECLASS_H
#define GAMECLASS_H

#include <QObject>
#include "universe.h"

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(Universe *uni, QObject *parent = 0);
    bool toggleGameOver();
    bool isGameOver();

private:
    Universe *u;
    bool gameOver;

signals:

public slots:
};

#endif // GAME_H
