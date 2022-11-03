#include "Chessboard.h"

Chessboard::Chessboard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j].color = Color::None;
            board[i][j].piece = Piece::None;
        }
    }
    // White Pieces
    //board[0][0].piece =
     board[0][7].piece = Piece::Rook;
    //board[0][0].color =
     board[0][7].color = Color::White;

    board[0][1].piece = board[0][6].piece = Piece::Knight;
    board[0][1].color = board[0][6].color = Color::White;

    board[0][2].piece = board[0][5].piece = Piece::Bishop;
    board[0][2].color = board[0][5].color = Color::White;

    board[0][3].piece = Piece::King;
    board[0][3].color = Color::White;

    board[0][4].piece = Piece::Queen;
    board[0][4].color = Color::White;

    for (int i = 0; i < 8; i++)
    {
        board[1][i].piece = Piece::Pawn;
        board[1][i].color = Color::White;
    }

    // Black Pieces
    board[7][0].piece = board[7][7].piece = Piece::Rook;
    board[7][0].color = board[7][7].color = Color::Black;

    board[7][1].piece = board[7][6].piece = Piece::Knight;
    board[7][1].color = board[7][6].color = Color::Black;

    board[7][2].piece = board[7][5].piece = Piece::Bishop;
    board[7][2].color = board[7][5].color = Color::Black;

    board[7][3].piece = Piece::King;
    board[7][3].color = Color::Black;

    board[7][4].piece = Piece::Queen;
    board[7][4].color = Color::Black;

    for (int i = 0; i < 8; i++)
    {
        board[6][i].piece = Piece::Pawn;
        board[6][i].color = Color::Black;
    }
}
