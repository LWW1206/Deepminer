#ifndef GRID_H
#define GRID_H
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Grid
{
    public:
        Grid(int x, int y, int z) : x(x), y(y), z(z), myvector(x, vector<vector<int> >(y, vector<int>(z))),
        effectvector(x, vector<vector<int> >(y, vector<int>(z))) {
        GenGrid();
        GenEffectGrid();
        }

        void GenGrid();
        void GenEffectGrid();
        void DisplayEffectGrid(int z);
        void DisplayGrid(int z);
        void SetEffectValue(int x, int y, int z);
        void DisplayNotNullGrid();
        int getnotnull_v(int x, int y);
        int getEffect_v(int x, int y);
        int getEffectz_Index(int x, int y);
        void sort_asc(int x, int y);
        void sort_desc(int x, int y);
        void randomShuffle(int x, int y);
        void mineBlock(int x, int y);
        int getzValue(int x, int y, int z);
        int getzIndex(int x, int y);
        void displayZColumn(int x, int y);

        ~Grid();

    protected:

    private:
        int x;
        int y;
        int z;
        vector<vector<vector<int> > > myvector;   // 3d vector - store actual playfield
        vector<vector<vector<int> > > effectvector;   // 3d vector - store effect fields

};

#endif // GRID_H
