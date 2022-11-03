#ifndef PROJEKT_CHESSBOARD_H
#define PROJEKT_CHESSBOARD_H

#include <utility>

class Chessboard
{
public:
    enum class Piece
    {
        King,
        Queen,
        Bishop,
        Knight,
        Rook,
        Pawn,
        None
    };

    enum class Color
    {
        White,
        Black,
        None
    };

    struct Board
    {
        Piece piece;
        Color color;

        Board()
        {
            piece=Piece::None;
            color=Color::None;
        }

        Board &operator=(const Board &other)
        {
            piece = other.piece;
            color = other.color;
            return *this;
        }
    };

    Board board[8][8];

    Chessboard();
};


#endif PROJEKT_CHESSBOARD_H
