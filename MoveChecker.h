#ifndef PROJEKT_MOVECHECKER_H
#define PROJEKT_MOVECHECKER_H

#include <string>
#include "Chessboard.h"
#include "MovesList.h"
#include <sstream>
#include <iostream>

class MoveChecker
{
    std::string alphabet[8];
    Chessboard::Color myColor;
    Chessboard::Color enemyColor;
public:
    MoveChecker();

    bool CheckMove(std::string from, std::string to, Chessboard &chessboard, MovesList &moves);

private:
    bool CheckKing(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves);

    bool CheckQueen(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves);

    bool CheckRook(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves);

    bool CheckBishop(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves);

    bool CheckKnight(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves);

    bool CheckPawn(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves);

    void CalculateCoordinates(std::string coordinate, int &a, int &b);
};


#endif PROJEKT_MOVECHECKER_H
