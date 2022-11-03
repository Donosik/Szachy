#include "ModelManager.h"

ModelManager::ModelManager()
{
    alphabet[0] = "a";
    alphabet[1] = "b";
    alphabet[2] = "c";
    alphabet[3] = "d";
    alphabet[4] = "e";
    alphabet[5] = "f";
    alphabet[6] = "g";
    alphabet[7] = "h";
    chessboard = Chessboard();
    player1Move = true;
}

//TODO: Cofanie nie dziala
void ModelManager::Reverse()
{
    if (player1Move)
    {
        std::string move = movesList.getPlayer2Moves()[movesList.getPlayer2Moves().size() - 1];
        std::stringstream ss(move);
        std::string from;
        std::string to;
        std::string figure;
        ss >> from;
        ss >> to;

        int a1;
        int b1;
        for (int i = 0; i < 8; i++)
        {
            if (from[0] == alphabet[i][0])
            {
                b1 = i;
            }
        }
        a1 = from[1] - '0' - 1;
        b1 = 8 - b1;
        b1 -= 1;

        int a2;
        int b2;
        for (int i = 0; i < 8; i++)
        {
            if (to[0] == alphabet[i][0])
            {
                b2 = i;
            }
        }
        a2 = to[1] - '0' - 1;
        b2 = 8 - b2;
        b2 -= 1;
        Chessboard::Board x;
        x = chessboard.board[a1][b1];
        chessboard.board[a1][b1] = chessboard.board[a2][b2];
        chessboard.board[a2][b2] = x;
        if (ss >> figure)
        {
            if (figure == "K")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::King;
                chessboard.board[a2][b2].color = Chessboard::Color::Black;
            }
            else if (figure == "Q")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::Queen;
                chessboard.board[a2][b2].color = Chessboard::Color::Black;
            }
            else if (figure == "R")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::Rook;
                chessboard.board[a2][b2].color = Chessboard::Color::Black;
            }
            else if (figure == "B")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::Bishop;
                chessboard.board[a2][b2].color = Chessboard::Color::Black;
            }
            else if (figure == "k")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::Knight;
                chessboard.board[a2][b2].color = Chessboard::Color::Black;
            }
            else if (figure == "P")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::Pawn;
                chessboard.board[a2][b2].color = Chessboard::Color::Black;
            }
        }
        movesList.Delete();
        player1Move = false;
    }
    else
    {
        std::string move = movesList.getPlayer1Moves()[movesList.getPlayer1Moves().size() - 1];
        std::stringstream ss(move);
        std::string from;
        std::string to;
        std::string figure;
        ss >> from;
        ss >> to;

        int a1;
        int b1;
        for (int i = 0; i < 8; i++)
        {
            if (from[0] == alphabet[i][0])
            {
                b1 = i;
            }
        }
        a1 = from[1] - '0' - 1;
        b1 = 8 - b1;
        b1 -= 1;

        int a2;
        int b2;
        for (int i = 0; i < 8; i++)
        {
            if (to[0] == alphabet[i][0])
            {
                b2 = i;
            }
        }
        a2 = to[1] - '0' - 1;
        b2 = 8 - b2;
        b2 -= 1;
        Chessboard::Board x;
        x = chessboard.board[a1][b1];
        chessboard.board[a1][b1] = chessboard.board[a2][b2];
        chessboard.board[a2][b2] = x;
        if (ss >> figure)
        {
            if (figure == "K")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::King;
                chessboard.board[a2][b2].color = Chessboard::Color::White;
            }
            else if (figure == "Q")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::Queen;
                chessboard.board[a2][b2].color = Chessboard::Color::White;
            }
            else if (figure == "R")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::Rook;
                chessboard.board[a2][b2].color = Chessboard::Color::White;
            }
            else if (figure == "B")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::Bishop;
                chessboard.board[a2][b2].color = Chessboard::Color::White;
            }
            else if (figure == "k")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::Knight;
                chessboard.board[a2][b2].color = Chessboard::Color::White;
            }
            else if (figure == "P")
            {
                chessboard.board[a2][b2].piece = Chessboard::Piece::Pawn;
                chessboard.board[a2][b2].color = Chessboard::Color::White;
            }
        }
        movesList.Delete(true);
        player1Move = true;
    }
}

bool ModelManager::CheckMove(std::string from, std::string to)
{
    if ((CheckFormat(from)) && (CheckFormat(to)))
    {
        int x = from[1] - '0' - 1;
        int y = from[0] - 'a';
        y = 8 - y - 1;
        if (chessboard.board[x][y].piece != Chessboard::Piece::None)
        {
            if (player1Move)
            {
                if (chessboard.board[x][y].color == Chessboard::Color::White)
                {
                    if (moveChecker.CheckMove(from, to, chessboard, movesList))
                    {
                        UpdateBoard(from, to);
                        player1Move = false;
                        return true;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (chessboard.board[x][y].color == Chessboard::Color::Black)
                {
                    if (moveChecker.CheckMove(from, to, chessboard, movesList))
                    {
                        UpdateBoard(from, to);
                        player1Move = true;
                        return true;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

bool ModelManager::WasCheckMate(std::string from, std::string to)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessboard.board[i][j].piece == Chessboard::Piece::King)
            {
                if (chessboard.board[i][j].color == Chessboard::Color::White)
                {
                    if (player1Move)
                    {
                        return false;
                    }
                }
                if (chessboard.board[i][j].color == Chessboard::Color::Black)
                {
                    if (!player1Move)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool ModelManager::CheckFormat(std::string x)
{
    if (x.size() != 2)
    {
        return false;
    }
    if (!((x[0] == 'a') || (x[0] == 'b') || (x[0] == 'c') || (x[0] == 'd') || (x[0] == 'e') || (x[0] == 'f') || (x[0] == 'g') || (x[0] == 'h')))
    {
        return false;
    }
    if ((x[1] - '0') > 8 || (x[1] - '0') < 1)
    {
        return false;
    }
    return true;
}

void ModelManager::UpdateBoard(std::string from, std::string to)
{
    int x1, y1;
    int x2, y2;
    for (int i = 0; i < 8; i++)
    {
        if (from[0] == alphabet[i][0])
        {
            y1 = i;
        }
    }
    x1 = from[1] - '0' - 1;
    y1 = 8 - y1;
    y1 -= 1;
    for (int i = 0; i < 8; i++)
    {
        if (to[0] == alphabet[i][0])
        {
            y2 = i;
        }
    }
    x2 = to[1] - '0' - 1;
    y2 = 8 - y2;
    y2 -= 1;
    if ((chessboard.board[x1][y1].color == Chessboard::Color::White) || (chessboard.board[x1][y1].color == Chessboard::Color::Black))
    {
        if (chessboard.board[x2][y2].color == Chessboard::Color::None)
        {
            Chessboard::Board x;
            x = chessboard.board[x1][y1];
            chessboard.board[x1][y1] = chessboard.board[x2][y2];
            chessboard.board[x2][y2] = x;
            movesList.AddMove(from + " " + to);
        }
        else
        {
            std::string figure;
            switch (chessboard.board[x2][y2].piece)
            {
                case Chessboard::Piece::King:
                {
                    figure = "K";
                }
                    break;
                case Chessboard::Piece::Queen:
                {
                    figure = "Q";
                }
                    break;
                case Chessboard::Piece::Rook:
                {
                    figure = "R";
                }
                    break;
                case Chessboard::Piece::Bishop:
                {
                    figure = "B";
                }
                    break;
                case Chessboard::Piece::Knight:
                {
                    figure = "k";
                }
                    break;
                case Chessboard::Piece::Pawn:
                {
                    figure = "P";
                }
                    break;
            }
            Chessboard::Board x;

            chessboard.board[x2][y2] = chessboard.board[x1][y1];
            chessboard.board[x1][y1] = x;
            movesList.AddMove(from + " " + to + " " + figure);
        }
    }
}