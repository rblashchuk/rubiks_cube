#include "details.h"
#include "cube.h"

Color White = Color::W;
Color Red = Color::R;
Color Blue = Color::B;
Color Orange = Color::O;
Color Green = Color::G;
Color Yellow = Color::Y;

direction f = direction::f;
direction b = direction::b;
direction l =direction::l;
direction r = direction::r;
direction u = direction::u;
direction d = direction::d;

Cube::Cube(const Cube &c) = default;

Cube &Cube::operator=(const Cube &c1) = default;

Cube::Cube(): angles{Angle()}, twosides{Twoside()}{

    angles[0] = Angle(White, Orange, Blue, f, l, u);
    angles[1] = Angle(White, Blue, Red, f, u, r);
    angles[2] = Angle(White, Red, Green, f, r, d);
    angles[3] = Angle(White, Green, Orange, f, d, l);
    angles[4] = Angle(Yellow, Blue, Orange, b, u, l);
    angles[5] = Angle(Yellow, Red, Blue, b, r, u);
    angles[6] = Angle(Yellow, Green, Red, b, d, r);
    angles[7] = Angle(White, Orange, Blue, f, l, u);

    twosides[0] = Twoside(White, Blue, f, u);
    twosides[1] = Twoside(White, Red, f, r);
    twosides[2] = Twoside(White, Green, f, d);
    twosides[3] = Twoside(White, Orange, f, l);
    twosides[4] = Twoside(Orange, Blue, l, u);
    twosides[5] = Twoside(Blue, Red, u, r);
    twosides[6] = Twoside(Red, Green, r, d);
    twosides[7] = Twoside(Green, Orange, d, l);
    twosides[8] = Twoside(Blue, Yellow, f, b);
    twosides[9] = Twoside(Red, Yellow, r, b);
    twosides[10] = Twoside(Green, Yellow, d, b);
    twosides[11] = Twoside(Orange, Yellow, l, b);

}

void Cube::L(){
    for (auto & angle : angles){
        if (angle.is_l()) angle.L();
    }

    for (auto & twoside : twosides){
        if (twoside.is_l()) twoside.L();
    }
}

void Cube::R(){
    for (auto & angle : angles){
        if (angle.is_r()) angle.R();
    }

    for (auto & twoside : twosides){
        if (twoside.is_r()) twoside.R();
    }
}

void Cube::F(){
    for (auto & angle : angles){
        if (angle.is_f()) angle.F();
    }

    for (auto & twoside : twosides){
        if (twoside.is_f()) twoside.F();
    }
}

void Cube::B(){
    for (auto & angle : angles){
        if (angle.is_b()) angle.B();
    }

    for (auto & twoside : twosides){
        if (twoside.is_b()) twoside.B();
    }
}

void Cube::U(){
    for (auto & angle : angles){
        if (angle.is_u()) angle.U();
    }

    for (auto & twoside : twosides){
        if (twoside.is_u()) twoside.U();
    }
}

void Cube::D(){
    for (auto & angle : angles){
        if (angle.is_d()) angle.D();
    }

    for (auto & twoside : twosides){
        if (twoside.is_d()) twoside.D();
    }
}


