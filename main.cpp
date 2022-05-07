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

    c.L();
    c.U();
    c.U();
    c.R();
    c.D();
    c.B();
    c.B();

    std::cout << c;

}


