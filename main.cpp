#include <iostream>
#include "details.h"


int main() {
    Dir d1 = Dir(direction::u);
    Dir d2 = Dir(direction::f);
    Dir d3 = Dir(direction::r);

    Two_side a = Two_side(Color::B, Color::W, d1, d2);
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

    std::cout << b;
}


