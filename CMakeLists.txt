cmake_minimum_required(VERSION 3.16)
project(Projekt)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt main.cpp ModelManager.cpp ModelManager.h ViewManager.cpp ViewManager.h ViewConsole.cpp ViewConsole.h InputManager.cpp InputManager.h ProjectManager.cpp ProjectManager.h Chessboard.cpp Chessboard.h MovesList.cpp MovesList.h MoveChecker.cpp MoveChecker.h Data.cpp Data.h)