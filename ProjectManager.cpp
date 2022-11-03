#include "ProjectManager.h"

ProjectManager::ProjectManager()
{
    input = new InputManager();
    model = new ModelManager();
    view = new ViewConsole(model->chessboard);
    Game();
}

void ProjectManager::Game()
{
    std::string from = "";
    std::string to = "";
    bool surrender = false;
    view->ShowInstructions();
    getchar();
    while (!surrender)
    {
        //system("cls");
        view->UpdateView(model->chessboard);
        while (true)
        {
            input->TakeInput(from, to);
            if (from=="resign")
            {
                surrender = true;
                view->EndGame();
                break;
            }
            else if(from=="back")
            {
                model->Reverse();
                view->UpdateView(model->chessboard);
                //system("cls");
                view->UpdateView(model->chessboard);

                break;
            }
            if (model->CheckMove(from, to))
            {
                if(from=="e1"&&to=="c1")
                {
                    view->UpdateView(model->chessboard);
                    //system("cls");
                    view->UpdateView(model->chessboard);
                }
                else if(from=="e1"&&to=="g1")
                {
                    view->UpdateView(model->chessboard);
                    //system("cls");
                    view->UpdateView(model->chessboard);
                }
                break;
            }
            std::cout << "Ruch byl niepoprawny, podaj ponownie!" << std::endl;
        }
        if (model->WasCheckMate(from, to))
        {
            view->UpdateView(model->chessboard);
            view->EndGame();
            break;
        }
    }
}
