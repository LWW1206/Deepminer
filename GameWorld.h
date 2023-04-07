#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include "Grid.h"
#include "BaseRobot.h"

class GameWorld
{
    public:
        BaseRobot* player1;
        BaseRobot* player2;
        Grid field;
        bool bot_on;
        bool game_status;
        int chosen_robot;

        GameWorld(int x, int y, int z): field(x, y, z), game_status(true), chosen_robot(0){
        menu();
        };

        void menu();
        BaseRobot* createRobot();
        void movePlayer(BaseRobot* robot, int x, int y);
        void Roundcheck(BaseRobot* robot);
        void setTominValue(BaseRobot* robot);
        int returnEffect_v(int x, int y);
        char RandDirection(BaseRobot* robot);
        char robotgetInput(BaseRobot* robot, int n);
        void mineWithAblity(BaseRobot* robot);
        void rearrange();
        void displaystats();
        void robotplay(BaseRobot* robot, char dir);
        bool checkGameStatus(BaseRobot* robot, int n);
        void play(BaseRobot* robot, int n);
        void playGame();

        ~GameWorld(){
            delete player1;
            delete player2;
        }

    protected:

    private:
};

#endif // GAMEWORLD_H
