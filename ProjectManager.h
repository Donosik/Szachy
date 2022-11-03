#ifndef PROJEKT_PROJECTMANAGER_H
#define PROJEKT_PROJECTMANAGER_H

#include "ViewConsole.h"
#include "ModelManager.h"
#include "InputManager.h"

class ProjectManager
{
    ViewManager *view;
    InputManager *input;
    ModelManager *model;

public:
    ProjectManager();
    void Game();
};


#endif PROJEKT_PROJECTMANAGER_H
