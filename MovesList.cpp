#include "MovesList.h"

MovesList::MovesList()
{
    player1Move = true;
    movesCount = 0;
}

std::vector<std::string> MovesList::getPlayer1Moves()
{
    return player1Moves;
}

std::vector<std::string> MovesList::getPlayer2Moves()
{
    return player2Moves;
}

void MovesList::Delete(bool first)
{
        movesCount--;
        player1Moves.erase(player1Moves.begin() + (player1Moves.size() - 1));
        player2Moves.erase(player2Moves.begin() + (player2Moves.size() - 1));
}

void MovesList::AddMove(std::string move)
{
    if (player1Move)
    {
        player1Moves.push_back(move);
        player1Move = false;
        movesCount++;
        return;
    }
    else
    {
        player2Moves.push_back(move);
        player1Move = true;
        return;
    }

}