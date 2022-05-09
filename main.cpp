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
    c.B();
    c.U();
    c.L();
    c.D();
    c.B();
    c.R();
    c.rD();
    c.B();
    c.rR();
    c.rL();
    c.D();
    c.B();

    std::cout << "UNSOLVED:\n" << c << "_____\n";

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
}


