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
    std::cout << c;
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

    std::cout << c;

    c.cross();
    std::cout << c;

    c.front_angles();
    std::cout << c;

    c.mid_twosides();
    std::cout << c;

    c.back_cross_placing();
    std::cout << c;
}


