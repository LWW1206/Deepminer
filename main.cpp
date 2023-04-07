#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grid.h"
#include "BaseRobot.h"
#include "GameWorld.h"
#include "GameWorld.cpp"
#include "Grid.cpp"
#include "BaseRobot.h"


using namespace std;

int main()
{
    cout << "You will be able to choose between 3 different roboter with different abilities, " << endl <<
    "don't choose one again you have already choosen " << endl;
    cout << "Decide if you want the Bot to play or play yourself" << endl;
    srand(time(NULL));
    GameWorld* game_ptr = new GameWorld(5, 5, 10);
    game_ptr->playGame();
    delete game_ptr;
    return 0;
}

/*  shuffle check since score % 50 == 0 is hard to trigger

    GameWorld* game_ptr = new GameWorld(5, 5, 10);
    game_ptr->field.DisplayGrid(9);
    cout << endl;
    game_ptr->field.DisplayGrid(8);
    cout << endl;
    game_ptr->field.displayZColumn(0, 0); cout << endl;
    game_ptr->field.displayZColumn(1, 1); cout << endl;
    game_ptr->field.displayZColumn(4, 4); cout << endl;

    game_ptr->rearrange();

    game_ptr->field.displayZColumn(0, 0); cout << endl;
    game_ptr->field.displayZColumn(1, 1); cout << endl;
    game_ptr->field.displayZColumn(4, 4); cout << endl;
    */
