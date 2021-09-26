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
    tab[4][0] = 'x';
    tab[4][2] = 'a';
    tab[4][6] = 'g';
    tab[4][8] = 'd';
    tab[0][0] = 'y';
    setCanva();

}

Cube::~Cube(void)
{

    Cube::Print();
        Back();
    std::cout << std::endl;
    Cube::Print();
        Back();
    std::cout << std::endl;
    Cube::Print();
        Back();
    std::cout << std::endl;
    Cube::Print();
        Back();
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
    HG,
    MG,
    BG,
    HM,
    MM,
    BM,
    HD,
    MD,
    BD,
}   t_position;


void Cube::Right()
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
    TurnFace(O);
}

\

void Cube::TurnFace(int f)
{

    char tmp;
    char tmp2;

    tmp = tab[f][BM];
    tmp2 = tab[f][BG];

    tab[f][BG] = tab[f][BD];
    tab[f][BM] = tab[f][MD];
    tab[f][BD] = tab[f][HD];
    tab[f][MD] = tab[f][HM];
    tab[f][HD] = tab[f][HG];
    tab[f][HM] = tab[f][MG];
    tab[f][HG] = tmp2;
    tab[f][MG] = tmp;

}

void Cube::Up()
{
    char tmp[3];
    char tmpP[3];
    tmp[0] = tab[B][HG];
    tmp[1] = tab[B][HM];
    tmp[2] = tab[B][HD];

    tab[B][HG] = tab[O][BG];
    tab[B][HM] = tab[O][MG];
    tab[B][HD] = tab[O][HG];

    tmpP[0] = tab[R][HD];
    tmpP[1] = tab[R][MD];
    tmpP[2] = tab[R][BD];

    tab[R][HD] = tmp[0];
    tab[R][MD] = tmp[1];
    tab[R][BD] = tmp[2];

    tmp[0] = tab[V][BD];
    tmp[1] = tab[V][BM];
    tmp[2] = tab[V][BG];

    tab[V][BD] = tmpP[0];
    tab[V][BM] = tmpP[1];
    tab[V][BG] = tmpP[2];

    tab[O][BG] = tmp[0];
    tab[O][MG] = tmp[1];
    tab[O][HG] = tmp[2];


    TurnFace(N);

}

void Cube::Down()
{
    char tmp[3];
    char tmpP[3];

    tmp[0] = tab[O][HD];
    tmp[1] = tab[O][MD];
    tmp[2] = tab[O][BD];

    tab[O][BD] = tab[B][BG];
    tab[O][MD] = tab[B][BM];
    tab[O][HD] = tab[B][BD];

    tmpP[0] = tab[V][HG];
    tmpP[1] = tab[V][HM];
    tmpP[2] = tab[V][HD];

    tab[V][HG] = tmp[0];
    tab[V][HM] = tmp[1];
    tab[V][HD] = tmp[2];

    tmp[0] = tab[R][BG];
    tmp[1] = tab[R][MG];
    tmp[2] = tab[R][HG];

    tab[R][BG] = tmpP[0];
    tab[R][MG] = tmpP[1];
    tab[R][HG] = tmpP[2];

    tab[B][BD] = tmp[0];
    tab[B][BM] = tmp[1];
    tab[B][BG] = tmp[2];

    TurnFace(J);
}

void Cube::Left()
{
    char tmp[3];
    char tmpP[3];

    tmp[0] = tab[N][HG];
    tmp[1] = tab[N][MG];
    tmp[2] = tab[N][BG];

    tab[N][HG] = tab[B][HG];
    tab[N][MG] = tab[B][MG];
    tab[N][BG] = tab[B][BG];

    tmpP[0] = tab[V][HG];
    tmpP[1] = tab[V][MG];
    tmpP[2] = tab[V][BG];

    tab[V][HG] = tmp[0];
    tab[V][MG] = tmp[1];
    tab[V][BG] = tmp[2];

    tmp[0] = tab[J][BD];
    tmp[1] = tab[J][MD];
    tmp[2] = tab[J][HD];

    tab[J][BD] = tmpP[0];
    tab[J][MD] = tmpP[1];
    tab[J][HD] = tmpP[2];

    tab[B][HG] = tmp[0];
    tab[B][MG] = tmp[1];
    tab[B][BG] = tmp[2];

    for(int i = 0; i < 3; i++)
        TurnFace(R);
}

void Cube::Front()
{
    char tmp[3];
    char tmpP[3];

    tmp[0] = tab[N][BG];
    tmp[1] = tab[N][BM];
    tmp[2] = tab[N][BD];

    tab[N][BG] = tab[R][BG];
    tab[N][BM] = tab[R][BM];
    tab[N][BD] = tab[R][BD];

    tmpP[0] = tab[O][BG];
    tmpP[1] = tab[O][BM];
    tmpP[2] = tab[O][BD];

    tab[O][BG] = tmp[0];
    tab[O][BM] = tmp[1];
    tab[O][BD] = tmp[2];

    tmp[0] = tab[J][BG];
    tmp[1] = tab[J][BM];
    tmp[2] = tab[J][BD];

    tab[J][BG] = tmpP[0];
    tab[J][BM] = tmpP[1];
    tab[J][BD] = tmpP[2];

    tab[R][BG] = tmp[0];
    tab[R][BM] = tmp[1];
    tab[R][BD] = tmp[2];

    TurnFace(B);
}


void Cube::Back()
{
    char tmp[3];
    char tmpP[3];

    tmp[0] = tab[N][HG];
    tmp[1] = tab[N][HM];
    tmp[2] = tab[N][HD];

    tab[N][HG] = tab[R][HG];
    tab[N][HM] = tab[R][HM];
    tab[N][HD] = tab[R][HD];

    tmpP[0] = tab[O][HG];
    tmpP[1] = tab[O][HM];
    tmpP[2] = tab[O][HD];

    tab[O][HG] = tmp[0];
    tab[O][HM] = tmp[1];
    tab[O][HD] = tmp[2];

    tmp[0] = tab[J][HG];
    tmp[1] = tab[J][HM];
    tmp[2] = tab[J][HD];

    tab[J][HG] = tmpP[0];
    tab[J][HM] = tmpP[1];
    tab[J][HD] = tmpP[2];

    tab[R][HG] = tmp[0];
    tab[R][HM] = tmp[1];
    tab[R][HD] = tmp[2];

    for(int i = 0; i < 3; i++)
        TurnFace(V);
}