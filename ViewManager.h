#ifndef PROJEKT_VIEWMANAGER_H
#define PROJEKT_VIEWMANAGER_H

#include "ModelManager.h"
#include <string>

class ViewManager
{
public:

    virtual void UpdateView(Chessboard &board) = 0;

    virtual void ShowInstructions() = 0;

    virtual void EndGame()=0;
};

#endif PROJEKT_VIEWMANAGER_H
