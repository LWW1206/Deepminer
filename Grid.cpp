#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


void Grid::GenGrid(){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                myvector[i][j][k] = rand()%9+1;
            }
        }
    }
}

void Grid::GenEffectGrid(){
    for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                for (int k = 0; k < z; k++){
                    effectvector[i][j][k] = 0 - (rand()%4);
                }
        }
    }
}

void Grid::DisplayEffectGrid(int z_value){
     for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << effectvector[i][j][z_value] << " ";
        }
        std::cout <<std::endl;
    }
}


void Grid::DisplayGrid(int z_value){ //displayGrid for a certain z value
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << myvector[i][j][z_value] << " ";
        }
        std::cout <<std::endl;
    }
}

void Grid::DisplayNotNullGrid(){ //displayGrid with mixed z dimensions, depending on value ( != 0 )
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int z = getzIndex(i, j);
            if (z == 0 && myvector[i][j][z] == 0) {
                std::cout << "0 ";
            } else {
                std::cout << myvector[i][j][z] << " ";
            }
        }
        std::cout <<std::endl;
    }
}

void Grid::SetEffectValue(int x, int y, int z) {
    effectvector[x][y][z] = 0;
}

int Grid::getEffect_v(int x, int y){
    for(int z = 9; z >= 0; z--){
        int temp = effectvector[x][y][z];
        if(temp != 0)
            return temp;
    }
    return 0;
}

int Grid::getEffectz_Index(int x, int y) {
    for(int z = 9; z >= 0; z--){
        int temp = effectvector[x][y][z];
        if(temp != 0)
            return z;
    }
    return 0;  // Return 0 to indicate that no non-zero value was found
}


int Grid::getnotnull_v(int x, int y){
    int z = getzIndex(x, y);
    if (z == 0 && myvector[x][y][z] == 0){
        std::cout << "You have already reached the bottom, you can't dig further" << std::endl;
        return 0;
    }
    else
    return myvector[x][y][z];
}

int Grid::getzValue(int x, int y, int z){
    return this->myvector[x][y][z];
}

void Grid::sort_asc(int x, int y){ //above >= lower
    std::sort(myvector[x][y].begin(), myvector[x][y].end());
}

void Grid::sort_desc(int x, int y){ // above <= lower
    std::sort(myvector[x][y].rbegin(), myvector[x][y].rend());
}

void Grid::randomShuffle(int x, int y) {
    std::random_shuffle(myvector[x][y].begin(), myvector[x][y].end());
}


int Grid::getzIndex(int x, int y){
    int z = 9;
    for(; z >= 0; z--){
        int temp = getzValue(x, y, z);
        if(temp != 0)
            return z;
    }
    return 0;
}

void Grid::mineBlock(int x, int y){
    int z = getzIndex(x, y);
    myvector[x][y][z] = 0;
}

void Grid::displayZColumn(int x, int y){
    for(int i = 9; i >= 0; i--){
        std::cout << myvector[x][y][i]<<std::endl;
    }
    /*for (auto& value : myvector[x][y]) {
    std::cout << value << " ";
  }*/
}

Grid::~Grid()
{
    //dtor
}

