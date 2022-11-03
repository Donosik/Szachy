#ifndef PROJEKT_MOVESLIST_H
#define PROJEKT_MOVESLIST_H

#include <vector>
#include <string>

class MovesList
{
    int movesCount;
    std::vector<std::string> player1Moves;
    std::vector<std::string> player2Moves;
    bool player1Move;

public:
    MovesList();

    std::vector<std::string> getPlayer1Moves();

    std::vector<std::string> getPlayer2Moves();

    void Delete(bool first = false);

    void AddMove(std::string move);
};


#endif PROJEKT_MOVESLIST_H
