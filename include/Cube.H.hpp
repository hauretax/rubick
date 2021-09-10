#ifndef CUBE_H_HPP
#define CUBE_H_HPP

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
};

#endif