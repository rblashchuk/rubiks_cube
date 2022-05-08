#include "details.h"
#include "cube.h"

const Color White = Color::W;
const Color Red = Color::R;
const Color Blue = Color::B;
const Color Orange = Color::O;
const Color Green = Color::G;
const Color Yellow = Color::Y;

const direction f = direction::f;
const direction b = direction::b;
const direction l = direction::l;
const direction r = direction::r;
const direction u = direction::u;
const direction d = direction::d;

Cube::Cube(const Cube &c) = default;

Cube &Cube::operator=(const Cube &c1) = default;

Cube::Cube() : angles{Angle()}, twosides{Twoside()} {

    angles[0] = Angle(White, Green, Orange, f, d, l);
    angles[1] = Angle(White, Blue, Red, f, u, r);
    angles[2] = Angle(White, Red, Green, f, r, d);
    angles[3] = Angle(White, Orange, Blue, f, l, u);
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

void Cube::L() {
    for (auto &angle: angles) {
        if (angle.is_l()) angle.L();
    }

    for (auto &twoside: twosides) {
        if (twoside.is_l()) twoside.L();
    }
}

void Cube::R() {
    for (auto &angle: angles) {
        if (angle.is_r()) angle.R();
    }

    for (auto &twoside: twosides) {
        if (twoside.is_r()) twoside.R();
    }
}

void Cube::F() {
    for (auto &angle: angles) {
        if (angle.is_f()) angle.F();
    }

    for (auto &twoside: twosides) {
        if (twoside.is_f()) twoside.F();
    }
}

void Cube::B() {
    for (auto &angle: angles) {
        if (angle.is_b()) angle.B();
    }

    for (auto &twoside: twosides) {
        if (twoside.is_b()) twoside.B();
    }
}

void Cube::U() {
    for (auto &angle: angles) {
        if (angle.is_u()) angle.U();
    }

    for (auto &twoside: twosides) {
        if (twoside.is_u()) twoside.U();
    }
}

void Cube::D() {
    for (auto &angle: angles) {
        if (angle.is_d()) angle.D();
    }

    for (auto &twoside: twosides) {
        if (twoside.is_d()) twoside.D();
    }
}

void Cube::rL(){
    L();
    L();
    L();
}

void Cube::rR(){
    R();
    R();
    R();
}

void Cube::rF(){
    F();
    F();
    F();
}

void Cube::rB(){
    B();
    B();
    B();
}

void Cube::rU(){
    U();
    U();
    U();
}

void Cube::rD(){
    D();
    D();
    D();
}

Angle Cube::FLU() {
    for (auto &angle: angles) {
        if ((angle.is_f()) && (angle.is_l()) && (angle.is_u())) return angle;
    }
}

Angle Cube::FUR() {
    for (auto &angle: angles) {
        if ((angle.is_f()) && (angle.is_u()) && (angle.is_r())) return angle;
    }
}

Angle Cube::FRD() {
    for (auto &angle: angles) {
        if ((angle.is_f()) && (angle.is_r()) && (angle.is_d())) return angle;
    }
}

Angle Cube::FDL() {
    for (auto &angle: angles) {
        if ((angle.is_f()) && (angle.is_d()) && (angle.is_l())) return angle;
    }
}

Angle Cube::BRU() {
    for (auto &angle: angles) {
        if ((angle.is_b()) && (angle.is_r()) && (angle.is_u())) return angle;
    }
}

Angle Cube::BDR() {
    for (auto &angle: angles) {
        if ((angle.is_b()) && (angle.is_d()) && (angle.is_r())) return angle;
    }
}

Angle Cube::BLD() {
    for (auto &angle: angles) {
        if ((angle.is_b()) && (angle.is_l()) && (angle.is_d())) return angle;
    }
}

Angle Cube::BUL() {
    for (auto &angle: angles) {
        if ((angle.is_b()) && (angle.is_u()) && (angle.is_l())) return angle;
    }
}

Twoside Cube::FU() {
    for (auto &twoside: twosides) {
        if ((twoside.is_f()) && (twoside.is_u())) return twoside;
    }
}

Twoside Cube::FR() {
    for (auto &twoside: twosides) {
        if ((twoside.is_f()) && (twoside.is_r())) return twoside;
    }
}

Twoside Cube::FD() {
    for (auto &twoside: twosides) {
        if ((twoside.is_f()) && (twoside.is_d())) return twoside;
    }
}

Twoside Cube::FL() {
    for (auto &twoside: twosides) {
        if ((twoside.is_f()) && (twoside.is_l())) return twoside;
    }
}

Twoside Cube::UR() {
    for (auto &twoside: twosides) {
        if ((twoside.is_u()) && (twoside.is_r())) return twoside;
    }
}

Twoside Cube::RD() {
    for (auto &twoside: twosides) {
        if ((twoside.is_r()) && (twoside.is_d())) return twoside;
    }
}

Twoside Cube::DL() {
    for (auto &twoside: twosides) {
        if ((twoside.is_d()) && (twoside.is_l())) return twoside;
    }
}

Twoside Cube::LU() {
    for (auto &twoside: twosides) {
        if ((twoside.is_l()) && (twoside.is_u())) return twoside;
    }
}

Twoside Cube::BU() {
    for (auto &twoside: twosides) {
        if ((twoside.is_b()) && (twoside.is_u())) return twoside;
    }
}

Twoside Cube::BR() {
    for (auto &twoside: twosides) {
        if ((twoside.is_b()) && (twoside.is_r())) return twoside;
    }
}

Twoside Cube::BD() {
    for (auto &twoside: twosides) {
        if ((twoside.is_b()) && (twoside.is_d())) return twoside;
    }
}

Twoside Cube::BL() {
    for (auto &twoside: twosides) {
        if ((twoside.is_b()) && (twoside.is_l())) return twoside;
    }
}

Color *Cube::frontside() {
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

Color *Cube::backside() {
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

Color *Cube::leftside() {
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

Color *Cube::rightside() {
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

Color *Cube::upside() {
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

Color *Cube::downside() {
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

void Cube::cross() {
    for (int i = 0; i < 12; i++) {
        if (twosides[i].color[0] == White) {
            if (twosides[i].is_f()) {
                if (twosides[i].placed()) {
                    continue;
                } else {
                    if (twosides[i].is_u()) {
                        U();
                        i--;
                        continue;
                    }
                    if (twosides[i].is_l()) {
                        L();
                        i--;
                        continue;
                    }
                    if (twosides[i].is_r()) {
                        R();
                        i--;
                        continue;
                    }
                    if (twosides[i].is_d()) {
                        D();
                        i--;
                        continue;
                    }
                }
            }
            else if(twosides[i].is_b()){
                if(twosides[i].backside() != White){

                    while (!twosides[i].is_u()){
                        B();
                    }

                    switch (twosides[i].backside()){
                        case(Red):
                            U();
                            rR();
                            break;

                        case(Blue):
                            B();
                            L();
                            rU();
                            rL();
                            break;

                        case (Orange):
                            rU();
                            L();
                            break;

                        case (Green):
                            B();
                            rL();
                            D();
                            L();
                            break;
                    }
                }

                else{
                    while (!twosides[i].is_u()){
                        B();
                    }
                    switch (twosides[i].upside()){
                        case(Red):
                            rB();
                            R();
                            R();
                            break;

                        case(Blue):
                            U();
                            U();
                            break;

                        case (Orange):
                            B();
                            L();
                            L();
                            break;

                        case (Green):
                            B();
                            B();
                            D();
                            D();
                            break;
                    }
                }
            }
            else {
                if ((twosides[i].is_u()) && (twosides[i].is_l())){
                    rL();
                    rB();
                    L();
                    i--;
                    continue;
                }

                if ((twosides[i].is_u()) && (twosides[i].is_r())){
                    R();
                    rB();
                    rR();
                    i--;
                    continue;
                }

                if ((twosides[i].is_d()) && (twosides[i].is_l())){
                    L();
                    rB();
                    rL();
                    i--;
                    continue;
                }

                if ((twosides[i].is_d()) && (twosides[i].is_r())){
                    rR();
                    B();
                    R();
                    i--;
                    continue;
                }
            }
        }
        else continue;
    }
}

void Cube::front_angles() {
    for (int i = 0; i < 8; i++){
        if (angles[i].color[0] != White) continue;
        else{
            if (angles[i].placed()) continue;
            else{
                if (angles[i].is_f()){
                    if  ((angles[i].is_u()) && (angles[i].is_l())){
                        rL();
                        rB();
                        L();
                        i--;
                        continue;
                    }
                    if  ((angles[i].is_u()) && (angles[i].is_r())){
                        R();
                        B();
                        rR();
                        i--;
                        continue;
                    }
                    if  ((angles[i].is_d()) && (angles[i].is_l())){
                        L();
                        rB();
                        rL();
                        i--;
                        continue;
                    }
                    if  ((angles[i].is_d()) && (angles[i].is_r())){
                        rR();
                        B();
                        R();
                        i--;
                        continue;
                    }
                }
                else{
                    if (angles[i].backside() == White){
                        while (!((angles[i].is_l()) && (angles[i].is_u()))) B();
                        rL();
                        B();
                        B();
                        L();
                        i--;
                        continue;
                    }
                    else{
                        while (!((angles[i].is_l()) && (angles[i].is_u()))) B();
                        if(angles[i].upside() == White){
                            if((angles[i].leftside() == Blue) && (angles[i].backside() == Red)) {
                                B();
                                B();
                                rU();
                                B();
                                U();
                                continue;
                            }

                            if((angles[i].leftside() == Orange) && (angles[i].backside() == Blue)) {
                                rB();
                                rL();
                                B();
                                L();
                                continue;
                            }

                            if((angles[i].leftside() == Red) && (angles[i].backside() == Green)) {
                                B();
                                B();
                                D();
                                B();
                                rD();
                                continue;
                            }

                            if((angles[i].leftside() == Green) && (angles[i].backside() == Orange)) {
                                rD();
                                B();
                                D();
                                continue;
                            }
                        }
                        else {
                            rL();
                            rB();
                            L();
                            B();
                            rL();
                            rB();
                            L();
                            B();
                            i--;
                            continue;
                        }
                    }
                }
            }
        }
    }
}

void Cube::mid_twosides() {
    for (int i = 0; i < 12; i++){
        if (twosides[i].is_f()) continue;
        if ((!twosides[i].is_b()) && (twosides[i].placed())) continue;
        if (twosides[i].color[1] == Yellow) continue;

        if (twosides[i].is_b()){
            while(!twosides[i].is_u()) B();

            if((twosides[i].upside() == Blue) && (twosides[i].backside() == Orange)){
                rB();
                rL();
                B();
                L();
                B();
                U();
                rB();
                rU();
                continue;
            }

            if((twosides[i].upside() == Orange) && (twosides[i].backside() == Blue)){
                B();
                B();
                U();
                rB();
                rU();
                rB();
                rL();
                B();
                L();
                continue;
            }

            if((twosides[i].upside() == Blue) && (twosides[i].backside() == Red)){
                B();
                R();
                rB();
                rR();
                rB();
                rU();
                B();
                U();
                continue;
            }

            if((twosides[i].upside() == Red) && (twosides[i].backside() == Blue)){
                B();
                B();
                rU();
                B();
                U();
                B();
                R();
                rB();
                rR();
                continue;
            }

            if((twosides[i].upside() == Green) && (twosides[i].backside() == Red)){
                B();
                rR();
                B();
                R();
                B();
                D();
                rB();
                rD();
                continue;
            }

            if((twosides[i].upside() == Red) && (twosides[i].backside() == Green)){
                D();
                rB();
                rD();
                rB();
                rR();
                B();
                R();
                continue;
            }

            if((twosides[i].upside() == Green) && (twosides[i].backside() == Orange)){
                rB();
                L();
                rB();
                rL();
                rB();
                rD();
                B();
                D();
                continue;
            }

            if((twosides[i].upside() == Orange) && (twosides[i].backside() == Green)){
                rD();
                B();
                D();
                B();
                L();
                rB();
                rL();
                continue;
            }
        }
        else {
            if ((twosides[i].is_u()) && (twosides[i].is_l())){
                rB();
                rL();
                B();
                L();
                B();
                U();
                rB();
                rU();
                i--;
                continue;
            }

            if ((twosides[i].is_u()) && (twosides[i].is_r())){
                B();
                R();
                rB();
                rR();
                rB();
                rU();
                B();
                U();
                i--;
                continue;
            }

            if ((twosides[i].is_d()) && (twosides[i].is_r())){
                B();
                D();
                rB();
                rD();
                rB();
                rR();
                B();
                R();
                i--;
                continue;
            }

            if ((twosides[i].is_d()) && (twosides[i].is_l())){
                rB();
                rD();
                B();
                D();
                B();
                L();
                rB();
                rL();
                i--;
                continue;
            }
        }
    }
}

std::ostream &operator<<(std::ostream &out, Cube c) {
    Color *f = c.frontside();
    Color *b = c.backside();
    Color *l = c.leftside();
    Color *r = c.rightside();
    Color *u = c.upside();
    Color *d = c.downside();

    out << "        +-------+        \n";
    out << "        |" << " " << u[0] << " " << u[1] << " " << u[2] << " " << "|        \n";
    out << "        |" << " " << u[3] << " " << u[4] << " " << u[5] << " " << "|        \n";
    out << "        |" << " " << u[6] << " " << u[7] << " " << u[8] << " " << "|        \n";
    out << "+-------+-------+-------+-------+\n";
    out << "|" << " " << l[0] << " " << l[1] << " " << l[2] << " " << "|" << " " << f[0] << " " << f[1] << " " << f[2] << " " << "|" << " " << r[0] << " " << r[1] << " " << r[2] << " " << "|" << " " << b[0] << " " << b[1] << " " << b[2] << " " << "|\n";
    out << "|" << " " << l[3] << " " << l[4] << " " << l[5] << " " << "|" << " " << f[3] << " " << f[4] << " " << f[5] << " " << "|" << " " << r[3] << " " << r[4] << " " << r[5] << " " << "|" << " " << b[3] << " " << b[4] << " " << b[5] << " " << "|\n";
    out << "|" << " " << l[6] << " " << l[7] << " " << l[8] << " " << "|" << " " << f[6] << " " << f[7] << " " << f[8] << " " << "|" << " " << r[6] << " " << r[7] << " " << r[8] << " " << "|" << " " << b[6] << " " << b[7] << " " << b[8] << " " << "|\n";
    out << "+-------+-------+-------+-------+\n";
    out << "        |" << " " << d[0] << " " << d[1] << " " << d[2] << " " << "|        \n";
    out << "        |" << " " << d[3] << " " << d[4] << " " << d[5] << " " << "|        \n";
    out << "        |" << " " << d[6] << " " << d[7] << " " << d[8] << " " << "|        \n";
    out << "        +-------+        \n";
    return out;
}