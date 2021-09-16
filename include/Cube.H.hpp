#ifndef CUBE_H_HPP
#define CUBE_H_HPP

#include "Cube.H.hpp"

class Cube
{
    private:
        char tab[6][9];
        char canva[9][12];
        void setFace(int, char);
        void setCanva();
        void showCanva();
    
    public:
        Cube();
        ~Cube();
        void Print();
        void PrintFace(int, int, int );
        void Right();
        void Rightp();
        void Up();
        void Down();
        void Left();
        void Front();
        void Back();

};

#endif