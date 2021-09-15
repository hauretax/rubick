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
    tab[0][6] = 'x';
    setCanva();

}

Cube::~Cube(void)
{

    Cube::Print();
        orangeA();
    std::cout << std::endl;
    Cube::Print();
        noirA();
    std::cout << std::endl;
    Cube::Print();
        noirA();
    std::cout << std::endl;
    Cube::Print();
        noirA();
    std::cout << std::endl;
    Cube::Print();
        noirA();
    std::cout << std::endl;
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


/****
****
****
a ranger  ?? 
****
****
****
****/

typedef enum e_couleur
{
    N,
    J,
    R,
    O,
    V,
    B,
}   t_couleur;

typedef enum e_position
{
    HD,
    MD,
    BD,
    HM,
    MM,
    BM,
    HG,
    MG,
    BG,
}   t_position;


void Cube::orangeH()
{
    char tmp[3];
    char tmpP[3];

    tmp[0] = tab[V][6];
    tmp[1] = tab[V][7];
    tmp[2] = tab[V][8];

    tab[V][6] = tab[N][6];
    tab[V][7] = tab[N][7];
    tab[V][8] = tab[N][8];

    tmpP[0] = tab[J][2];
    tmpP[1] = tab[J][1];
    tmpP[2] = tab[J][0];

    tab[J][0] = tmp[2];
    tab[J][1] = tmp[1];
    tab[J][2] = tmp[0];

    tmp[0] = tab[B][6];
    tmp[1] = tab[B][7];
    tmp[2] = tab[B][8];

    tab[B][6] = tmpP[0];
    tab[B][7] = tmpP[1];
    tab[B][8] = tmpP[2];

    tab[N][6] = tmp[0];
    tab[N][7] = tmp[1];
    tab[N][8] = tmp[2];
}

void Cube::orangeA()
{
    char tmp[3];
    char tmpP[3];

    tmp[0] = tab[B][6];
    tmp[1] = tab[B][7];
    tmp[2] = tab[B][8];

    tab[B][6] = tab[N][6];
    tab[B][7] = tab[N][7];
    tab[B][8] = tab[N][8];

    tmpP[0] = tab[J][2];
    tmpP[1] = tab[J][1];
    tmpP[2] = tab[J][0];

    tab[J][0] = tmp[2];
    tab[J][1] = tmp[1];
    tab[J][2] = tmp[0];

    tmp[0] = tab[V][6];
    tmp[1] = tab[V][7];
    tmp[2] = tab[V][8];

    tab[V][6] = tmpP[0];
    tab[V][7] = tmpP[1];
    tab[V][8] = tmpP[2];

    tab[N][6] = tmp[0];
    tab[N][7] = tmp[1];
    tab[N][8] = tmp[2];
}

void Cube::noirA()
{
    char tmp[3];
    char tmpP[3];

    tmp[0] = tab[B][HD];
    tmp[1] = tab[B][HM];
    tmp[2] = tab[B][HG];

    tab[B][HD] = tab[O][BD];
    tab[B][HM] = tab[O][MD];
    tab[B][HG] = tab[O][HD];

    tmpP[0] = tab[V][BD];
    tmpP[1] = tab[V][BM];
    tmpP[2] = tab[V][BG];

    tab[V][BD] = tmp[0];
    tab[V][BM] = tmp[1];
    tab[V][BG] = tmp[2];

    tmp[0] = tab[R][HG];
    tmp[1] = tab[V][MG];
    tmp[2] = tab[V][BG];

    tab[R][HG] = tmpP[0];
    tab[R][MG] = tmpP[1];
    tab[R][BG] = tmpP[2];

    tab[B][HD] = tmp[0];
    tab[B][HM] = tmp[1];
    tab[B][HG] = tmp[2];
}