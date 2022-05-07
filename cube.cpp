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
    angles[7] = Angle(Yellow, Orange, Green, b, l, d);

    twosides[0] = Twoside(White, Blue, f, u);
    twosides[1] = Twoside(White, Red, f, r);
    twosides[2] = Twoside(White, Green, f, d);
    twosides[3] = Twoside(White, Orange, f, l);
    twosides[4] = Twoside(Orange, Blue, l, u);
    twosides[5] = Twoside(Blue, Red, u, r);
    twosides[6] = Twoside(Red, Green, r, d);
    twosides[7] = Twoside(Green, Orange, d, l);
    twosides[8] = Twoside(Blue, Yellow, u, b);
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

Angle Cube::FLU(){
    for (auto & angle : angles){
        if ((angle.is_f()) && (angle.is_l()) && (angle.is_u())) return angle;
    }
}

Angle Cube::FUR(){
    for (auto & angle : angles){
        if ((angle.is_f()) && (angle.is_u()) && (angle.is_r())) return angle;
    }
}

Angle Cube::FRD(){
    for (auto & angle : angles){
        if ((angle.is_f()) && (angle.is_r()) && (angle.is_d())) return angle;
    }
}

Angle Cube::FDL(){
    for (auto & angle : angles){
        if ((angle.is_f()) && (angle.is_d()) && (angle.is_l())) return angle;
    }
}

Angle Cube::BRU(){
    for (auto & angle : angles){
        if ((angle.is_b()) && (angle.is_r()) && (angle.is_u())) return angle;
    }
}

Angle Cube::BDR(){
    for (auto & angle : angles){
        if ((angle.is_b()) && (angle.is_d()) && (angle.is_r())) return angle;
    }
}

Angle Cube::BLD(){
    for (auto & angle : angles){
        if ((angle.is_b()) && (angle.is_l()) && (angle.is_d())) return angle;
    }
}

Angle Cube::BUL(){
    for (auto & angle : angles){
        if ((angle.is_b()) && (angle.is_u()) && (angle.is_l())) return angle;
    }
}

Twoside Cube::FU(){
    for (auto & twoside : twosides){
        if ((twoside.is_f()) && (twoside.is_u())) return twoside;
    }
}

Twoside Cube::FR(){
    for (auto & twoside : twosides){
        if ((twoside.is_f()) && (twoside.is_r())) return twoside;
    }
}

Twoside Cube::FD(){
    for (auto & twoside : twosides){
        if ((twoside.is_f()) && (twoside.is_d())) return twoside;
    }
}

Twoside Cube::FL(){
    for (auto & twoside : twosides){
        if ((twoside.is_f()) && (twoside.is_l())) return twoside;
    }
}

Twoside Cube::UR(){
    for (auto & twoside : twosides){
        if ((twoside.is_u()) && (twoside.is_r())) return twoside;
    }
}

Twoside Cube::RD(){
    for (auto & twoside : twosides){
        if ((twoside.is_r()) && (twoside.is_d())) return twoside;
    }
}

Twoside Cube::DL(){
    for (auto & twoside : twosides){
        if ((twoside.is_d()) && (twoside.is_l())) return twoside;
    }
}

Twoside Cube::LU(){
    for (auto & twoside : twosides){
        if ((twoside.is_l()) && (twoside.is_u())) return twoside;
    }
}

Twoside Cube::BU(){
    for (auto & twoside : twosides){
        if ((twoside.is_b()) && (twoside.is_u())) return twoside;
    }
}

Twoside Cube::BR(){
    for (auto & twoside : twosides){
        if ((twoside.is_b()) && (twoside.is_r())) return twoside;
    }
}

Twoside Cube::BD(){
    for (auto & twoside : twosides){
        if ((twoside.is_b()) && (twoside.is_d())) return twoside;
    }
}

Twoside Cube::BL(){
    for (auto & twoside : twosides){
        if ((twoside.is_b()) && (twoside.is_l())) return twoside;
    }
}

Color *Cube::frontside(){
    static Color ans[9];
    ans[0] = this->FLU().frontside();
    ans[1] = this->FU().frontside();
    ans[2] = this->FUR().frontside();
    ans[3] = this->FL().frontside();
    ans[4] = White;
    ans[5] = this->FR().frontside();
    ans[6] = this->FDL().frontside();
    ans[7] = this->FD().frontside();
    ans[8] = this->FRD().frontside();
    return ans;
}

Color *Cube::backside(){
    static Color ans[9];
    ans[0] = this->BRU().backside();
    ans[1] = this->BU().backside();
    ans[2] = this->BUL().backside();
    ans[3] = this->BR().backside();
    ans[4] = Yellow;
    ans[5] = this->BL().backside();
    ans[6] = this->BDR().backside();
    ans[7] = this->BD().backside();
    ans[8] = this->BLD().backside();
    return ans;
}

Color *Cube::leftside(){
    static Color ans[9];
    ans[0] = this->BUL().leftside();
    ans[1] = this->LU().leftside();
    ans[2] = this->FLU().leftside();
    ans[3] = this->BL().leftside();
    ans[4] = Orange;
    ans[5] = this->FL().leftside();
    ans[6] = this->BLD().leftside();
    ans[7] = this->DL().leftside();
    ans[8] = this->FDL().leftside();
    return ans;
}

Color *Cube::rightside(){
    static Color ans[9];
    ans[0] = this->FUR().rightside();
    ans[1] = this->UR().rightside();
    ans[2] = this->BRU().rightside();
    ans[3] = this->FR().rightside();
    ans[4] = Red;
    ans[5] = this->BR().rightside();
    ans[6] = this->FRD().rightside();
    ans[7] = this->RD().rightside();
    ans[8] = this->BDR().rightside();
    return ans;
}

Color *Cube::upside(){
    static Color ans[9];
    ans[0] = this->BUL().upside();
    ans[1] = this->BU().upside();
    ans[2] = this->BRU().upside();
    ans[3] = this->LU().upside();
    ans[4] = Blue;
    ans[5] = this->UR().upside();
    ans[6] = this->FLU().upside();
    ans[7] = this->FU().upside();
    ans[8] = this->FUR().upside();
    return ans;
}

Color *Cube::downside(){
    static Color ans[9];
    ans[0] = this->FDL().downside();
    ans[1] = this->FD().downside();
    ans[2] = this->FRD().downside();
    ans[3] = this->DL().downside();
    ans[4] = Green;
    ans[5] = this->RD().downside();
    ans[6] = this->BLD().downside();
    ans[7] = this->BD().downside();
    ans[8] = this->BDR().downside();
    return ans;
}

std::ostream &operator<<(std::ostream &out, Cube c){
    Color *f = c.frontside();
    Color *b = c.backside();
    Color *l = c.leftside();
    Color *r = c.rightside();
    Color *u = c.upside();
    Color *d = c.downside();

    out << "    +---+        \n";
    out << "    |" << u[0] << u[1] << u[2] << "|        \n";
    out << "    |" << u[3] << u[4] << u[5] << "|        \n";
    out << "    |" << u[6] << u[7] << u[8] << "|        \n";
    out << "+---+---+---+---+\n";
    out << "|" << l[0] << l[1] << l[2] << "|" << f[0] << f[1] << f[2] << "|" << r[0] << r[1] << r[2] << "|" << b[0] << b[1] << b[2] << "|\n";
    out << "|" << l[3] << l[4] << l[5] << "|" << f[3] << f[4] << f[5] << "|" << r[3] << r[4] << r[5] << "|" << b[3] << b[4] << b[5] << "|\n";
    out << "|" << l[6] << l[7] << l[8] << "|" << f[6] << f[7] << f[8] << "|" << r[6] << r[7] << r[8] << "|" << b[6] << b[7] << b[8] << "|\n";
    out << "+---+---+---+---+\n";
    out << "    |" << d[0] << d[1] << d[2] << "|        \n";
    out << "    |" << d[3] << d[4] << d[5] << "|        \n";
    out << "    |" << d[6] << d[7] << d[8] << "|        \n";
    out << "    +---+        \n";
    return out;
}