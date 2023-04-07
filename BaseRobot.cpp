#include "BaseRobot.h"
#include "Grid.h"
#include <iostream>

BaseRobot::BaseRobot(int x_, int y_, int score_) :
    x(x_), y(y_), score(score_) {}

int BaseRobot::ability(Grid& myGrid, int x, int y) {
    std::cout << "This robot doesn't have a specific ability." << std::endl;
    return 0;
}

BaseRobot::~BaseRobot() {}

robo_1::robo_1(int x, int y, int score) :
    BaseRobot(x, y, score) {}

int robo_1::ability(Grid& myGrid, int x, int y) {
    int sc = 0; //return score made by mining
    myGrid.sort_asc(x, y);
    sc = myGrid.getnotnull_v(x, y);
    myGrid.mineBlock(x, y);
    return sc;
}

robo_2::robo_2(int x, int y, int score) :
    BaseRobot(x, y, score) {}

int robo_2::ability(Grid& myGrid, int x, int y) {
    int sc = 0;
    for (int i = 0; i < 3; ++i) {
        if (myGrid.getnotnull_v(x, y) == 0)
            break;
        else {
            //std::cout << "in else" << endl;
            int temp = myGrid.getnotnull_v(x, y);
            sc += temp;
            myGrid.mineBlock(x, y);
        }
    }
    return sc;
}

robo_3::robo_3(int x, int y, int score) :
    BaseRobot(x, y, score) {}

int robo_3::ability(Grid& myGrid, int x, int y) {
    int sc = myGrid.getnotnull_v(x, y);
    myGrid.mineBlock(x, y);
    myGrid.sort_desc(x, y);
    return sc;
}
