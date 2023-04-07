#ifndef BASEROBOT_H
#define BASEROBOT_H

#include "Grid.h"

class BaseRobot
{
    public:
        BaseRobot(int x_, int y_, int score_);
        virtual ~BaseRobot();
        virtual int ability(Grid& myGrid, int x, int y);

        int get_x() { return this -> x;};
        int get_y() { return this -> y;};
        void set_x(int x) {this -> x = x;};
        void set_y(int y) {this -> y = y;};
        int get_score(){return this -> score;};
        void set_score(int value) {this -> score = value;};

    protected:
        int x;
        int y;
        int score;

};

class robo_1 : public BaseRobot
{
    public:
        robo_1(int x, int y, int score);

        int ability(Grid& myGrid, int x, int y);

    protected:

    private:
};

class robo_2 : public BaseRobot
{
    public:
        robo_2(int x, int y, int score);

        int ability(Grid& myGrid, int x, int y);

    protected:

    private:
};

class robo_3 : public BaseRobot
{
    public:
        robo_3(int x, int y, int score);

        int ability(Grid& myGrid, int x, int y);

    protected:

    private:
};

#endif // BASEROBOT_H
