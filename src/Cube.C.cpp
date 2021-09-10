#include "Cube.H.hpp"
#include <iostream>

Cube::Cube(void)
{
    Cube::setFace(0,'N');
    Cube::setFace(1,'J');
    Cube::setFace(2,'R');
    Cube::setFace(3,'O');
    Cube::setFace(4,'V');
    Cube::setFace(5,'B');
    setCanva();

}

Cube::~Cube(void)
{
    Cube::Print();
    return ;
}

void Cube::setFace(int i,char color){
    int y = 0;
    while(y < 9){
        tab[i][y] = color;
        y++;
    }
}

void Cube::setCanva(){
    int i = 0;
    int y = 0;

    while (i < 9){
        while (y < 12){
            canva[i][y] = '.';
            y++;
        }
        y=0;
        i++;
    }
}


void Cube::showCanva(){
    int i = 0;
    int y = 0;

    while (i < 9){
        while (y < 12){
            std::cout << canva[i][y];
            y++;
        }
        std::cout << std::endl;
        y=0;
        i++;
    }
}

void Cube::PrintFace(int i,int x, int y){
    int dx = 0;
    int dy = 0;

    if ( x > 6 || y > 12)
    {
        std::cout << "placer la face au centre" << std::endl;
        return ;
    }
    while (dx < 9)
    {
            canva[x + (dx % 3)][dy + y] =  tab[i][dx];
            dx++;
            if (dx  % 3 == 0){
                dy++;
            }
    }
}

void Cube::Print(){
    Cube::PrintFace(2, 3, 0);
    Cube::PrintFace(0, 3, 3);
    Cube::PrintFace(3, 3, 6);
    Cube::PrintFace(1, 3, 9);
    Cube::PrintFace(4, 0, 3);
    Cube::PrintFace(5, 6, 3);
    Cube::showCanva();
    return ;
}