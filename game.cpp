#include <QDebug>
#include "game.h"

Game::Game(Universe *uni, QObject *parent) : QObject(parent)
{
    this->gameOver = false;
    this->u = uni;
}
bool Game::toggleGameOver()
{
    return this->gameOver = !this->gameOver;
}
bool Game::isGameOver()
{
    return this->gameOver;
}
