#include <iostream>
#include "details.h"
#include "cube.h"

int main() {
    direction d1 = direction::u;
    direction d2 = direction::f;
    direction d3 = direction::r;

    Twoside a = Twoside(Color::B, Color::W, d1, d2);
    Angle b = Angle(Color::B, Color::W, Color::R, d1, d2, d3);

    std::cout << a << "\n";
    a.U();
    a.L();
    a.F();
    a.F();
    a.rR();
    std::cout << a << "\n";

    std::cout << b << "\n";

    b.U();
    b.F();
    b.R();
    b.R();

    std::cout << b << "\n";

    Cube c = Cube();
    std::cout << "INIT CUBE:\n" << c << "_____\n";
    c.R();
    c.rU();
    c.B();
    c.U();
    c.F();
    c.rR();
    c.R();
    c.L();
    c.F();
    c.L();
    c.U();
    c.rR();


    c.dump("test.txt");

    Cube x = Cube();
    x.load("test.txt");

    std::cout << "UNSOLVED:\n" << c << "_____\n";

    std::cout << "LOADED FROM FILE:\n" << x << "_____\n";

    c.set_logging(true);
    c.cross();
    std::cout << "CROSS:\n" << c << "_____\n";

    c.front_angles();
    std::cout << "FRONT ANGLES:\n" << c << "_____\n";

    c.mid_twosides();
    std::cout << "MID TWOSIDES:\n" << c << "_____\n";

    c.back_cross();
    std::cout << "BACK CROSS:\n" << c << "_____\n";

    c.back_angles();
    std::cout << "SOLVED:\n" << c << "_____\n";

    std::cout << c.log;
}


