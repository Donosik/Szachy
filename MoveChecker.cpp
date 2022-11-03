#include "MoveChecker.h"

MoveChecker::MoveChecker()
{
    alphabet[0] = "a";
    alphabet[1] = "b";
    alphabet[2] = "c";
    alphabet[3] = "d";
    alphabet[4] = "e";
    alphabet[5] = "f";
    alphabet[6] = "g";
    alphabet[7] = "h";
}

bool MoveChecker::CheckMove(std::string from, std::string to, Chessboard &chessboard, MovesList &moves)
{
    int x1, y1;
    int x2, y2;
    CalculateCoordinates(from, x1, y1);
    CalculateCoordinates(to, x2, y2);
    if ((x1 == x2) && (y1 == y2))
    {
        return false;
    }
    if (chessboard.board[x1][y1].color == Chessboard::Color::White)
    {
        myColor = Chessboard::Color::White;
        enemyColor = Chessboard::Color::Black;
    }
    else
    {
        enemyColor = Chessboard::Color::White;
        myColor = Chessboard::Color::Black;
    }

    switch (chessboard.board[x1][y1].piece)
    {
        case Chessboard::Piece::King:
        {
            return CheckKing(x1, y1, x2, y2, chessboard, moves);
        }
            break;
        case Chessboard::Piece::Queen:
        {
            return CheckQueen(x1, y1, x2, y2, chessboard, moves);
        }
            break;
        case Chessboard::Piece::Bishop:
        {
            return CheckBishop(x1, y1, x2, y2, chessboard, moves);
        }
            break;
        case Chessboard::Piece::Knight:
        {
            return CheckKnight(x1, y1, x2, y2, chessboard, moves);
        }
            break;
        case Chessboard::Piece::Rook:
        {
            if (CheckRook(x1, y1, x2, y2, chessboard, moves))
            {
                return true;
            }
        }
            break;
        case Chessboard::Piece::Pawn:
        {
            return CheckPawn(x1, y1, x2, y2, chessboard, moves);
        }
            break;
    }
    return false;
}

bool MoveChecker::CheckKing(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves)
{
    if (myColor == Chessboard::Color::White)
    {
        if ((x1 == 0) && (y1 == 3))
        {
            if ((x2 == 0) && (y2 == 5))
            {
                for (auto move:moves.getPlayer1Moves())
                {
                    int a;
                    int b;
                    std::string line;
                    std::stringstream ss(move);
                    ss >> line;
                    CalculateCoordinates(line, a, b);
                    if ((a == 0) && (b == 3))
                    {
                        return false;
                    }
                }
                for (auto move:moves.getPlayer1Moves())
                {
                    int a;
                    int b;
                    std::string line;
                    std::stringstream ss(move);
                    ss >> line;
                    CalculateCoordinates(line, a, b);
                    if ((a == 0) && (b == 7))
                    {
                        return false;
                    }
                }
                for (int i = 4; i < 7; i++)
                {
                    if (chessboard.board[0][i].piece != Chessboard::Piece::None)
                    {
                        return false;
                    }
                }
                Chessboard::Board x;
                x = chessboard.board[0][7];
                chessboard.board[0][7] = chessboard.board[0][4];
                chessboard.board[0][4] = x;

                return true;
            }
            else if ((x2 == 0) && (y2 == 1))
            {
                for (auto move:moves.getPlayer1Moves())
                {
                    int a;
                    int b;
                    std::string line;
                    std::stringstream ss(move);
                    ss >> line;
                    CalculateCoordinates(line, a, b);
                    if ((a == 0) && (b == 3))
                    {
                        return false;
                    }
                }
                for (auto move:moves.getPlayer1Moves())
                {
                    int a;
                    int b;
                    std::string line;
                    std::stringstream ss(move);
                    ss >> line;
                    CalculateCoordinates(line, a, b);
                    if ((a == 0) && (b == 0))
                    {
                        return false;
                    }
                }
                if (chessboard.board[0][1].piece != Chessboard::Piece::None)
                {
                    return false;
                }
                if (chessboard.board[0][2].piece != Chessboard::Piece::None)
                {
                    return false;
                }
                Chessboard::Board x;
                x = chessboard.board[0][0];
                chessboard.board[0][0] = chessboard.board[0][2];
                chessboard.board[0][2] = x;
                std::cout << "XXX" << std::endl;
                return true;
            }
        }
    }
    if ((x1 == x2) && (y1 == y2))
    {
        return false;
    }
    if ((x1 - x2 > 1) || (x1 - x2 < (-1)))
    {
        return false;
    }
    if ((y1 - y2 > 1) || (y1 - y2 < (-1)))
    {
        return false;
    }
    if (chessboard.board[x2][y2].color == myColor)
    {
        return false;
    }
    return true;
}

bool MoveChecker::CheckQueen(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves)
{
    if (x1 == x2)
    {
        if (y2 > y1)
        {
            for (int i = y1 + 1; i <= y2; i++)
            {
                if ((chessboard.board[x2][y2].color == enemyColor) && (i == y2))
                {
                    return true;
                }
                if (chessboard.board[x1][i].piece != Chessboard::Piece::None)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            for (int i = y1 - 1; i >= y2; i--)
            {
                if ((chessboard.board[x2][y2].color == enemyColor) && (i == y1))
                {
                    return true;
                }
                if (chessboard.board[x1][i].piece != Chessboard::Piece::None)
                {
                    return false;
                }
            }
            return true;
        }
    }
    else if (y1 == y2)
    {
        if (x2 > x1)
        {
            for (int i = x1 + 1; i <= x2; i++)
            {
                if ((chessboard.board[x2][y2].color == enemyColor) && (i == x2))
                {
                    return true;
                }
                if (chessboard.board[i][y1].piece != Chessboard::Piece::None)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            for (int i = x1 - 1; i >= x2; i--)
            {
                if ((chessboard.board[x2][y2].color == enemyColor) && (i == x1))
                {
                    return true;
                }
                if (chessboard.board[i][y1].piece != Chessboard::Piece::None)
                {
                    return false;
                }
            }
            return true;
        }
    }
    if ((x2 > x1) && (y2 > y1))
    {
        int i = x1 + 1;
        int j = y1 + 1;
        while ((x2 != i) && (y2 != j))
        {
            if ((chessboard.board[x2][y2].color == enemyColor) && (j == y2) && (i == x2))
            {
                return true;
            }
            if (chessboard.board[i][j].piece != Chessboard::Piece::None)
            {
                return false;
            }
            i++;
            j++;
        }
        if ((i == x2) && (j == y2))
        {
            return true;
        }
        return false;
    }
    else if ((x2 > x1) && (y1 > y2))
    {
        int i = x1 + 1;
        int j = y1 - 1;
        while ((x2 != i) && (y2 != j))
        {
            if ((chessboard.board[x2][y2].color == enemyColor) && (j == y2) && (i == x2))
            {
                return true;
            }
            if (chessboard.board[i][j].piece != Chessboard::Piece::None)
            {
                return false;
            }
            i++;
            j--;
        }
        if ((i == x2) && (j == y2))
        {
            return true;
        }
        return false;
    }
    else if ((x1 > x2) && (y2 > y1))
    {
        int i = x1 - 1;
        int j = y1 + 1;
        while ((x2 != i) && (y2 != j))
        {
            if ((chessboard.board[x2][y2].color == enemyColor) && (j == y2) && (i == x2))
            {
                return true;
            }
            if (chessboard.board[i][j].piece != Chessboard::Piece::None)
            {
                return false;
            }
            i--;
            j++;
        }
        if ((i == x2) && (j == y2))
        {
            return true;
        }
        return false;
    }
    else if ((x1 > x2) && (y1 > y2))
    {
        int i = x1 - 1;
        int j = y1 - 1;
        while ((x2 != i) && (y2 != j))
        {
            if ((chessboard.board[x2][y2].color == enemyColor) && (j == y2) && (i == x2))
            {
                return true;
            }
            if (chessboard.board[i][j].piece != Chessboard::Piece::None)
            {
                return false;
            }
            i--;
            j--;
        }
        if ((i == x2) && (j == y2))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool MoveChecker::CheckRook(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves)
{
    if (x1 == x2)
    {
        if (y2 > y1)
        {
            for (int i = y1 + 1; i <= y2; i++)
            {
                if ((chessboard.board[x2][y2].color == enemyColor) && (i == y2))
                {
                    return true;
                }
                if (chessboard.board[x1][i].piece != Chessboard::Piece::None)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            for (int i = y1 - 1; i >= y2; i--)
            {
                if ((chessboard.board[x2][y2].color == enemyColor) && (i == y1))
                {
                    return true;
                }
                if (chessboard.board[x1][i].piece != Chessboard::Piece::None)
                {
                    return false;
                }
            }
            return true;
        }
    }
    else if (y1 == y2)
    {
        if (x2 > x1)
        {
            for (int i = x1 + 1; i <= x2; i++)
            {
                if ((chessboard.board[x2][y2].color == enemyColor) && (i == x2))
                {
                    return true;
                }
                if (chessboard.board[i][y1].piece != Chessboard::Piece::None)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            for (int i = x1 - 1; i >= x2; i--)
            {
                if ((chessboard.board[x2][y2].color == enemyColor) && (i == x1))
                {
                    return true;
                }
                if (chessboard.board[i][y1].piece != Chessboard::Piece::None)
                {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

bool MoveChecker::CheckBishop(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves)
{
    if ((x2 > x1) && (y2 > y1))
    {
        int i = x1 + 1;
        int j = y1 + 1;
        while ((x2 != i) && (y2 != j))
        {
            if ((chessboard.board[x2][y2].color == enemyColor) && (j == y2) && (i == x2))
            {
                return true;
            }
            if (chessboard.board[i][j].piece != Chessboard::Piece::None)
            {
                return false;
            }
            i++;
            j++;
        }
        if ((i == x2) && (j == y2))
        {
            return true;
        }
        return false;
    }
    else if ((x2 > x1) && (y1 > y2))
    {
        int i = x1 + 1;
        int j = y1 - 1;
        while ((x2 != i) && (y2 != j))
        {
            if ((chessboard.board[x2][y2].color == enemyColor) && (j == y2) && (i == x2))
            {
                return true;
            }
            if (chessboard.board[i][j].piece != Chessboard::Piece::None)
            {
                return false;
            }
            i++;
            j--;
        }
        if ((i == x2) && (j == y2))
        {
            return true;
        }
        return false;
    }
    else if ((x1 > x2) && (y2 > y1))
    {
        int i = x1 - 1;
        int j = y1 + 1;
        while ((x2 != i) && (y2 != j))
        {
            if ((chessboard.board[x2][y2].color == enemyColor) && (j == y2) && (i == x2))
            {
                return true;
            }
            if (chessboard.board[i][j].piece != Chessboard::Piece::None)
            {
                return false;
            }
            i--;
            j++;
        }
        if ((i == x2) && (j == y2))
        {
            return true;
        }
        return false;
    }
    else if ((x1 > x2) && (y1 > y2))
    {
        int i = x1 - 1;
        int j = y1 - 1;
        while ((x2 != i) && (y2 != j))
        {
            if ((chessboard.board[x2][y2].color == enemyColor) && (j == y2) && (i == x2))
            {
                return true;
            }
            if (chessboard.board[i][j].piece != Chessboard::Piece::None)
            {
                return false;
            }
            i--;
            j--;
        }
        if ((i == x2) && (j == y2))
        {
            return true;
        }
        return false;
    }

    return false;
}

bool MoveChecker::CheckKnight(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves)
{
    if ((x1 + 2 == x2) && (y1 + 1 == y2))
    {
        return true;
    }
    else if ((x1 + 2 == x2) && (y1 - 1 == y2))
    {
        return true;
    }
    else if ((x1 + 1 == x2) && (y1 + 2 == y2))
    {
        return true;
    }
    else if ((x1 + 1 == x2) && (y1 - 2 == y2))
    {
        return true;
    }
    else if ((x1 - 1 == x2) && (y1 + 2 == y2))
    {
        return true;
    }
    else if ((x1 - 1 == x2) && (y1 - 2 == y2))
    {
        return true;
    }
    else if ((x1 - 2 == x2) && (y1 + 1 == y2))
    {
        return true;
    }
    else if ((x1 - 2 == x2) && (y1 - 1 == y2))
    {
        return true;
    }
    return false;

}

bool MoveChecker::CheckPawn(int x1, int y1, int x2, int y2, Chessboard &chessboard, MovesList &moves)
{
    if (myColor == Chessboard::Color::White)
    {
        if ((y1 == y2) && (x1 + 2 == x2) && (chessboard.board[x2][y2].color == Chessboard::Color::None))
        {
            for (auto move:moves.getPlayer1Moves())
            {
                int a;
                int b;
                std::string line;
                std::stringstream ss(move);
                ss >> line;
                CalculateCoordinates(line, a, b);
                if ((a == 1) && (b == y1))
                {
                    return false;
                }
            }
            return true;
        }
        else if ((y1 == y2) && (x1 + 1 == x2) && (chessboard.board[x2][y2].color == Chessboard::Color::None))
        {
            return true;
        }
        // bicie w przelocie
        else if ((x1 == 4) && (x2 == 5))
        {
            if ((y1 - 1 == y2) || (y1 + 1 == y2))
            {
                if ((chessboard.board[x1][y2].piece == Chessboard::Piece::Pawn) && (chessboard.board[x1][y2].color == Chessboard::Color::Black))
                {
                    for (auto move:moves.getPlayer2Moves())
                    {
                        int a;
                        int b;
                        std::string line;
                        std::stringstream ss(move);
                        ss >> line;
                        CalculateCoordinates(line, a, b);
                        if ((a == 6) && (b == y2))
                        {
                            ss >> line;
                            CalculateCoordinates(line, a, b);
                            if ((a == 4) && (b == y2))
                            {
                                Chessboard::Board x;
                                chessboard.board[4][y2] = x;
                                return true;
                            }
                        }
                    }
                }
            }
            else if (y1 + 1 == y2)
            {
                if ((chessboard.board[x2][y1].piece == Chessboard::Piece::Pawn) && (chessboard.board[x2][y1].color == Chessboard::Color::Black))
                {
                    for (auto move:moves.getPlayer1Moves())
                    {
                        int a;
                        int b;
                        std::string line;
                        std::stringstream ss(move);
                        ss >> line;
                        CalculateCoordinates(line, a, b);
                        if ((a == x2) && (b == 7))
                        {
                            std::string line;
                            std::stringstream ss(move);
                            ss >> line;
                            CalculateCoordinates(line, a, b);
                            if ((a == x2) && (b == 5))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        else if ((y1 - 1 == y2) && (x1 + 1 == x2))
        {
            if (chessboard.board[x2][y2].color == enemyColor)
            {
                return true;
            }
        }
        else if ((y1 + 1 == y2) && (x1 + 1 == x2))
        {
            if (chessboard.board[x2][y2].color == enemyColor)
            {
                return true;
            }
        }
    }
    else if (myColor == Chessboard::Color::Black)
    {
        if ((y1 == y2) && (x1 - 2 == x2) && (chessboard.board[x2][y2].color == Chessboard::Color::None))
        {
            for (auto move:moves.getPlayer1Moves())
            {
                int a;
                int b;
                std::string line;
                std::stringstream ss(move);
                ss >> line;
                CalculateCoordinates(line, a, b);
                if ((a == 6) && (b == y1))
                {
                    return false;
                }
            }
            return true;
        }
        else if ((y1 == y2) && (x1 - 1 == x2) && (chessboard.board[x2][y2].color == Chessboard::Color::None))
        {
            return true;
        }
        else if ((y1 - 1 == y2) && (x1 - 1 == x2))
        {
            if (chessboard.board[x2][y2].color == enemyColor)
            {
                return true;
            }
        }
        else if ((y1 + 1 == y2) && (x1 - 1 == x2))
        {
            if (chessboard.board[x2][y2].color == enemyColor)
            {
                return true;
            }
        }
    }
    return false;
}

void MoveChecker::CalculateCoordinates(std::string coordinate, int &a, int &b)
{
    for (int i = 0; i < 8; i++)
    {
        if (coordinate[0] == alphabet[i][0])
        {
            b = i;
        }
    }
    a = coordinate[1] - '0' - 1;
    b = 8 - b;
    b -= 1;


}