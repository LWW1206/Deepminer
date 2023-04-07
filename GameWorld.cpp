#include "GameWorld.h"
#include "BaseRobot.h"
#include "Grid.h"
#include "BaseRobot.cpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>


BaseRobot* GameWorld::createRobot() {
    int input;
    while (1) {
        cout << "Please input a valid number (1, 2, or 3)/ don't choose a robot you have already chosen" << endl;
        cin >> input;
        if ((input == 1 || input == 2 || input == 3) && (chosen_robot != input)) {
            break;
        }
    }
    chosen_robot = input;
    if (input == 1) {
        return new robo_1(0, 0, 0); //base coordinates
    } else if (input == 2) {
        return new robo_2(4, 4, 0);
    } else {
        return new robo_3(2, 2, 0);
    }
}


void GameWorld::menu() {
        cout << endl << "Choose Robot 1 (1, 2 or 3)" << endl;
        player1 = createRobot();
        cout << endl << "Choose Robot 2 (1, 2 or 3)" << endl;
        player2 = createRobot();
        chosen_robot = 0;
        cout << "Do you want to play against the computer? (y/n)" << endl;
        string input;
        while(input[0] != 'y' && input[0] != 'n') {
            cout << "please input a valid character" << endl;
            cin >> input;
        }
        if(input[0] == 'y'){
            bot_on = true;
        }
        else
            bot_on = false;
    }

void GameWorld::Roundcheck(BaseRobot* robot) {
     if (robot->get_score() != 0 && robot->get_score() % 50 == 0) {
        std::cout << "The Roboters Score is a multiple of 50, the gamefield will be rearranged" << std::endl;
        rearrange();
     }
     else
        std::cout << "The Roboters Score isn't a multiple of 50, the game will continue normally" << std::endl;
}

void GameWorld::rearrange() {
    cout << "Grid is beeing rearranged" << endl;
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num = rand() % 3 + 1;
            switch (num) {
                case 1:
                    //cout << "in random shuffle" << endl;
                    field.randomShuffle(i, j);
                    break;
                case 2:
                    //cout << "in random sort_asc" << endl;
                    field.sort_asc(i, j);
                    break;
                case 3:
                    //cout << "in random sort_desc" << endl;
                    field.sort_desc(i, j);
                    break;
            }
        }
    }
}

void GameWorld::setTominValue(BaseRobot* robot) {
    int x = 0, min_x = 0;
    int y = 0, min_y = 0;
    int min = 9;
    for (; x < 5; x++){
        for (y = 0; y < 5 ; y++){ // reset y to 0 at the start of each x iteration
            if (field.getnotnull_v(x, y) <= min){
                min = field.getnotnull_v(x, y);
                min_x = x;
                min_y = y;
            }
        }
    }
    robot->set_x(min_x);
    robot->set_y(min_y);
}

void GameWorld::movePlayer(BaseRobot* robot, int x, int y) {
    //field.displayZColumn(robot->get_x() + x, robot->get_y() + y);
    //field.displayZColumn(robot->get_x(), robot->get_y());

    int new_x = robot->get_x() + x;
    int new_y = robot->get_y() + y;
    //cout << "newx:" << new_x << endl;
    //cout << "newy:" << new_y << endl;

    robot->set_x(new_x);
    robot->set_y(new_y);
}

char GameWorld::RandDirection(BaseRobot* robot) {
    cout << "The Bot will choose a random valid Direction for you" << endl;
    char movement;
    do{
        int r = rand() % 5;
        if (r == 0)
            movement = 'w';
        else if (r == 1)
            movement = 'a';
        else if (r == 2)
            movement = 's';
        else if (r == 3)
            movement = 'd';
        else
            movement = 'x';
    }while((movement == 'w' && robot->get_x() == 0) ||
             (movement == 'a' && robot->get_y() == 0) ||
             (movement == 'd' && robot->get_y() == 4) ||
             (movement == 's' && robot->get_x() == 4));
    cout << "movement = " << movement << endl;
    return movement;
}

char GameWorld::robotgetInput(BaseRobot* robot, int n) {
    char movement;
    cout << "Enter the direction for Player " << n << endl;
    do {
        cout << "Please enter a valid movement (w, a, s, d, x) x = stay on the current field and dig deeper down: ";
        cin >> movement;
        if ((movement == 'w' && robot->get_x() == 0) ||
            (movement == 'a' && robot->get_y() == 0) ||
            (movement == 'd' && robot->get_y() == 4) ||
            (movement == 's' && robot->get_x() == 4)) {
                cout << "You are moving out of the map, please choose another direction!" << endl;
                }
        else if (movement != 'w' && movement != 'a' && movement != 's' && movement != 'd' && movement != 'x') {
            cout << "Invalid input, please try again!" << endl;
        }
    } while ((movement != 'w' && movement != 'a' && movement != 's' && movement != 'd' && movement != 'x') ||
             (movement == 'w' && robot->get_x() == 0) ||
             (movement == 'a' && robot->get_y() == 0) ||
             (movement == 'd' && robot->get_y() == 4) ||
             (movement == 's' && robot->get_x() == 4));
    return movement;
}

void GameWorld::robotplay(BaseRobot* robot, char direction) {
    switch(direction) {
        case 'w':
            movePlayer(robot, -1, 0);
            break;
        case 'a':
            movePlayer(robot, 0, -1);
            break;
        case 's':
            movePlayer(robot, 1, 0);
            break;
        case 'd':
            movePlayer(robot, 0, 1);
            break;
        case 'x':
            movePlayer(robot, 0, 0);
            break;
    }
}

void GameWorld::displaystats() {
    cout << "*--------------------------------------------------------------------------------------*" << endl;
    cout << "Player1's Current position is: " << player1->get_x() << "/" << player1->get_y() << endl;
    cout << "Player1's Current Score is: " << player1->get_score() << endl;
    cout << "Player2's Current position is: " << player2->get_x() << "/" << player2->get_y() << endl;
    cout << "Player2's Current Score is: " << player2->get_score() << endl;
    cout << "*--------------------------------------------------------------------------------------*" << endl << endl;
}

int GameWorld::returnEffect_v(int x, int y){
    int num = field.getEffect_v(x, y);
    int z = field.getEffectz_Index(x, y);
    switch(num) {
        case 0 :
            cout << "effect value 0, nothing happens" << endl;
            return 0;
            break;
        case -1 :
            cout << "player will be forced to skip a round" << endl;
            field.SetEffectValue(x, y, z); //set back to 0;
            return -1;
            break;
        case -2 :
            cout << "player will be tped to the lowest value field currently accessible" << endl;
            field.SetEffectValue(x, y, z);
            return -2;
            break;
        case -3 :
            cout << "player will get a random score between (-3 to +3)" << endl;
            field.SetEffectValue(x, y, z);
            return -3;
            break;
    }
    return 1;
}

void GameWorld::mineWithAblity(BaseRobot* robot){
    int temp = robot->ability(field, robot->get_x(), robot->get_y());
    robot->set_score(robot->get_score() + temp);
}

void GameWorld::play(BaseRobot* robot, int n){
        int effect;
        field.DisplayNotNullGrid(); cout << endl;
        displaystats();

        /* uncomment this part for better visualization of the 3D Grid, same as below

        *Effect Grid Layer 9 - 8 - 7* str+c more Layers at will;
        field.DisplayEffectGrid(9); cout << endl;
        field.DisplayEffectGrid(8); cout << endl;
        field.DisplayEffectGrid(7); cout << endl;

        *Actual Grid Layer with 0 values 9 - 8 -7*
        field.DisplayGrid(9); cout << endl;
        field.DisplayGrid(8); cout << endl;
        field.DisplayGrid(7); cout << endl;
        */

        field.DisplayEffectGrid(9); cout << endl;
        field.DisplayEffectGrid(8); cout << endl;
        field.DisplayEffectGrid(7); cout << endl;
        field.DisplayGrid(9); cout << endl;
        field.DisplayGrid(8); cout << endl;
        field.DisplayGrid(7); cout << endl;

        cout << "Player" << n << "'s turn: " << endl;
        char movement;
        movement = bot_on ? RandDirection(robot) : robotgetInput(robot, n);
        robotplay(robot, movement); //move to new position

        //field.displayZColumn(player->get_x(), player->get_y()); shows vector at (x,y) 0-9 for z before mining;
        effect=returnEffect_v(robot->get_x(), robot->get_y());

        if(effect == 0){
            mineWithAblity(robot);
        }
        else if(effect == -1) { /*skips round*/ }
        else if (effect == -2){
            setTominValue(robot);
            cout << "Player" << n << "'s Current position is: " << robot->get_x() << "/" << robot->get_y() << endl;
            mineWithAblity(robot);
        }
        else if(effect == -3){
            int temp = (rand() % 7) - 3;
            cout << "You have rolled: " << temp << endl;
            robot->set_score(robot->get_score() + temp);
            mineWithAblity(robot);
        }
        cout << endl << "Player" << n << "-Score: " <<  robot->get_score() << endl;
        //field.displayZColumn(player->get_x(), player->get_y()); shows vector at (x,y) 0-9 for z after mining;

        Roundcheck(robot);
        game_status = checkGameStatus(robot, n);
}

void GameWorld::playGame(){
    do {
        play(player1, 1);
        if(game_status == false)
            break;
        play(player2, 2);
    }while(game_status != false);
}

bool GameWorld::checkGameStatus(BaseRobot* robot, int n){
    if(robot->get_score() >= 50){ //set to 50 for testing
        cout << endl << "Player " << n << " has won with a score of: " << robot->get_score() << endl;
        return false;
    }
    return true;
}

