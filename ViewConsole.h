#ifndef PROJEKT_VIEWCONSOLE_H
#define PROJEKT_VIEWCONSOLE_H

#include <iostream>
#include <windows.h>
#include "ViewManager.h"
#include "ModelManager.h"

class ViewConsole : public ViewManager
{
    Chessboard board;
    HANDLE hConsole;
    std::string alphabet[8];
    bool firstPlayer;
public:
    explicit ViewConsole(Chessboard chessboard);

    void UpdateView(Chessboard &board) override;

    void ShowInstructions() override;

    void EndGame() override;

private:
    void UpdateBoard(std::string from, std::string to);

    void DrawWhiteSide();

    void DrawBlackSide();

    void DrawChessboard(int i, int j);
};

#endif PROJEKT_VIEWCONSOLE_H
