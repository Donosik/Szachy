#include "ViewConsole.h"

ViewConsole::ViewConsole(Chessboard chessboard)
{
    this->board = chessboard;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    alphabet[0] = "a";
    alphabet[1] = "b";
    alphabet[2] = "c";
    alphabet[3] = "d";
    alphabet[4] = "e";
    alphabet[5] = "f";
    alphabet[6] = "g";
    alphabet[7] = "h";
    firstPlayer = true;
}

void ViewConsole::UpdateView(Chessboard &board)
{
    this->board=board;
    if (firstPlayer)
    {
        DrawWhiteSide();
        firstPlayer = !firstPlayer;
    }
    else
    {
        DrawBlackSide();
        firstPlayer = !firstPlayer;
    }
}

void ViewConsole::ShowInstructions()
{
    std::cout << "Instrukcja:" << std::endl;
    std::cout << "Aby sie poddac nalezy wpisac: resign" << std::endl;
    std::cout << "Aby przemiescic figure nalezy podac koordynaty" << std::endl;
    std::cout << "Format to np. a4 lub c6" << std::endl;
    std::cout << "a-h oraz 1-8" << std::endl;
    std::cout << "Najpierw sa podawane koordynaty ktora figure przemiescic" << std::endl;
    std::cout << "Nastepnie sa podawane koordynaty gdzie przemiescic figure" << std::endl;
    std::cout << "W przypadku podania nieprawidlowego ruchu " << std::endl;
    std::cout << "Bedzie ponowiona proba wybrania ruchu" << std::endl;
    std::cout << "Aby zaakceptowac i przejsc do gry nalezy wcisnac enter" << std::endl;
}

void ViewConsole::EndGame()
{
    std::cout<<"Ta epicka walka w krolewskiej grze zostala zakonczona"<<std::endl;
    std::cout<<"Zwyciezca zostal gracz grajacy bierkami ";
    if(firstPlayer)
    {
        std::cout<<"bialymi."<<std::endl;
    }
    else
    {
        std::cout<<"czarnymi."<<std::endl;
    }
    std::cout<<"Gratulacje!"<<std::endl;
}

void ViewConsole::UpdateBoard(std::string from, std::string to)
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
    if((board.board[x1][y1].color==Chessboard::Color::White)||(board.board[x1][y1].color==Chessboard::Color::Black))
    {
        if(board.board[x2][y2].color==Chessboard::Color::None)
        {
            Chessboard::Board x;
            x = board.board[x1][y1];
            board.board[x1][y1] = board.board[x2][y2];
            board.board[x2][y2] = x;
        }
        else
        {
            Chessboard::Board x;
            board.board[x2][y2]=board.board[x1][y1];
            board.board[x1][y1]=x;
        }
    }
}

void ViewConsole::DrawWhiteSide()
{
    int colorNumber = 2;
    for (int i = 8; i >= -1; i--)
    {
        SetConsoleTextAttribute(hConsole, colorNumber);
        if (i == 8)
        {
            std::cout << " X ";
            for (int j = 0; j < 8; j++)
            {
                std::cout << " " << alphabet[j] << " ";
            }
            SetConsoleTextAttribute(hConsole, colorNumber);
            std::cout << " X ";
            std::cout << std::endl;
            continue;
        }
        else if ((i <= 7) && (i >= 0))
        {
            std::cout << " " << i + 1 << " ";
            for (int j = 7; j >= 0; j--)
            {
                DrawChessboard(i, j);
            }
            SetConsoleTextAttribute(hConsole, colorNumber);
            std::cout << " " << i + 1 << " ";
            std::cout << std::endl;
            continue;
        }
        else if (i == -1)
        {
            std::cout << " X ";
            for (int j = 0; j < 8; j++)
            {
                std::cout << " " << alphabet[j] << " ";
            }
            SetConsoleTextAttribute(hConsole, colorNumber);
            std::cout << " X ";
            std::cout << std::endl;
            continue;
        }
    }
}

void ViewConsole::DrawBlackSide()
{
    int colorNumber = 2;
    for (int i = -1; i <= 8; i++)
    {
        SetConsoleTextAttribute(hConsole, colorNumber);
        if (i == 8)
        {
            std::cout << " X ";
            for (int j = 7; j >= 0; j--)
            {
                std::cout << " " << alphabet[j] << " ";
            }
            SetConsoleTextAttribute(hConsole, colorNumber);
            std::cout << " X ";
            std::cout << std::endl;
            continue;
        }
        else if ((i <= 7) && (i >= 0))
        {
            std::cout << " " << i + 1 << " ";
            for (int j = 0; j < 8; j++)
            {
                DrawChessboard(i, j);
            }
            SetConsoleTextAttribute(hConsole, colorNumber);
            std::cout << " " << i + 1 << " ";
            std::cout << std::endl;
            continue;
        }
        else if (i == -1)
        {
            std::cout << " X ";
            for (int j = 7; j >= 0; j--)
            {
                std::cout << " " << alphabet[j] << " ";
            }
            SetConsoleTextAttribute(hConsole, colorNumber);
            std::cout << " X ";
            std::cout << std::endl;
            continue;
        }
    }
}

void ViewConsole::DrawChessboard(int i, int j)
{
    std::cout << " ";
    if (board.board[i][j].color == Chessboard::Color::White)
    {
        SetConsoleTextAttribute(hConsole, 7);
    }
    else if (board.board[i][j].color == Chessboard::Color::Black)
    {
        SetConsoleTextAttribute(hConsole, 4);
    }
    switch (board.board[i][j].piece)
    {
        case Chessboard::Piece::King:
        {
            std::cout << "K";
        }
            break;
        case Chessboard::Piece::Queen:
        {
            std::cout << "Q";
        }
            break;
        case Chessboard::Piece::Bishop:
        {
            std::cout << "B";
        }
            break;
        case Chessboard::Piece::Knight:
        {
            std::cout << "k";
        }
            break;
        case Chessboard::Piece::Rook:
        {
            std::cout << "R";
        }
            break;
        case Chessboard::Piece::Pawn:
        {
            std::cout << "P";
        }
            break;
        case Chessboard::Piece::None:
        {
            std::cout << " ";
        }
            break;
    }
    std::cout << " ";


}