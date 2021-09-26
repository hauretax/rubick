#include <iostream>
#include "Cube.H.hpp"


int main( int argc , char ** argv){
    Cube cube;
    std::string signal;

    while (signal != "EXIT")
    {
        if (signal == "U")
            cube.Up();
        if (signal == "D")
            cube.Down();
        if (signal == "R")
            cube.Right();
        if (signal == "L")
            cube.Left();
        if (signal == "F")
            cube.Front();
        if (signal == "B")
            cube.Back();
        cube.Print();
        std::cin >> signal;
    }
    return 0;
}
