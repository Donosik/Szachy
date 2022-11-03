#ifndef PROJEKT_MODELMANAGER_H
#define PROJEKT_MODELMANAGER_H

#include "Chessboard.h"
#include "MovesList.h"
#include "MoveChecker.h"

class ModelManager
{
    std::string alphabet[8];
    bool player1Move;
    MovesList movesList;
    MoveChecker moveChecker;
public:
    Chessboard chessboard;

    ModelManager();

    void Reverse();

    bool CheckMove(std::string from, std::string to);

    bool WasCheckMate(std::string from, std::string to);

private:
    bool CheckFormat(std::string x);

    void UpdateBoard(std::string from,std::string to);
};

#endif PROJEKT_MODELMANAGER_H
