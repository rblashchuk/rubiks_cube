#include "details.h"

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

std::ostream &operator<<(std::ostream &out, Color c){
    switch (c) {
        case(White):
            out << 'W';
            break;
        case(Blue):
            out << 'B';
            break;
        case(Red):
            out << 'R';
            break;
        case(Orange):
            out << 'O';
            break;
        case (Green):
            out << 'G';
            break;
        case (Yellow):
            out << 'Y';
            break;
        case (Color::X):
            out << 'X';
            break;
    }
    return out;
}

Dir::Dir(direction a){
    dir = a;
}

Dir::Dir() = default;

void Dir::L(){
    switch (dir) {
        case (b):
            dir = u;
            break;

        case (u):
            dir = f;
            break;

        case(f):
            dir = d;
            break;

        case(d):
            dir = b;
            break;

        case (l):
            dir = l;
            break;

        case (r):
            dir = r;
            break;
    }
}

void Dir::R(){
    switch (dir) {
        case (b):
            dir = d;
            break;

        case (d):
            dir = f;
            break;

        case(f):
            dir = u;
            break;

        case(u):
            dir = b;
            break;

        case (l):
            dir = l;
            break;

        case (r):
            dir = r;
            break;
    }
}

void Dir::F(){
    switch (dir) {
        case (l):
            dir = u;
            break;

        case (u):
            dir = r;
            break;

        case(r):
            dir = d;
            break;

        case(d):
            dir = l;
            break;

        case (b):
            dir = b;
            break;

        case (f):
            dir = f;
            break;
    }
}

void Dir::B(){
    switch (dir) {
        case (l):
            dir = d;
            break;

        case (d):
            dir = r;
            break;

        case(r):
            dir = u;
            break;

        case(u):
            dir = l;
            break;

        case (b):
            dir = b;
            break;

        case (f):
            dir = f;
            break;
    }
}

void Dir::U(){
    switch (dir) {
        case (l):
            dir = b;
            break;

        case (b):
            dir = r;
            break;

        case(r):
            dir = f;
            break;

        case(f):
            dir = l;
            break;

        case (u):
            dir = u;
            break;

        case (d):
            dir = d;
            break;
    }
}

void Dir::D(){
    switch (dir) {
        case (l):
            dir = f;
            break;

        case (f):
            dir = r;
            break;

        case(r):
            dir = b;
            break;

        case(b):
            dir = l;
            break;

        case (u):
            dir = u;
            break;

        case (d):
            dir = d;
            break;
    }
}

void Dir::rL(){
    switch (dir) {
        case (u):
            dir = b;
            break;

        case (f):
            dir = u;
            break;

        case(d):
            dir = f;
            break;

        case(b):
            dir = d;
            break;

        case (l):
            dir = l;
            break;

        case (r):
            dir = r;
            break;
    }
}

void Dir::rR(){
    switch (dir) {
        case (d):
            dir = b;
            break;

        case (f):
            dir = d;
            break;

        case(u):
            dir = f;
            break;

        case(b):
            dir = u;
            break;

        case (l):
            dir = l;
            break;

        case (r):
            dir = r;
            break;
    }
}

void Dir::rF(){
    switch (dir) {
        case (u):
            dir = l;
            break;

        case (r):
            dir = u;
            break;

        case(d):
            dir = r;
            break;

        case(l):
            dir = d;
            break;

        case (b):
            dir = b;
            break;

        case (f):
            dir = f;
            break;
    }
}

void Dir::rB(){
    switch (dir) {
        case (d):
            dir = l;
            break;

        case (r):
            dir = d;
            break;

        case(u):
            dir = r;
            break;

        case(l):
            dir = u;
            break;

        case (b):
            dir = b;
            break;

        case (f):
            dir = f;
            break;
    }
}

void Dir::rU(){
    switch (dir) {
        case (b):
            dir = l;
            break;

        case (r):
            dir = b;
            break;

        case(f):
            dir = r;
            break;

        case(l):
            dir = f;
            break;

        case (u):
            dir = u;
            break;

        case (d):
            dir = d;
            break;
    }
}

void Dir::rD(){
    switch (dir) {
        case (f):
            dir = l;
            break;

        case (r):
            dir = f;
            break;

        case(b):
            dir = r;
            break;

        case(l):
            dir = b;
            break;

        case (u):
            dir = u;
            break;

        case (d):
            dir = d;
            break;
    }
}

Twoside::Twoside() = default;

Twoside::Twoside(const Twoside &c) = default;

Twoside &Twoside::operator=(const Twoside &c1) = default;

std::ostream &operator <<(std::ostream &out, Dir &direction){
    switch (direction.dir) {
        case (l):
            out << 'l';
            break;

        case (f):
            out << 'f';
            break;

        case(r):
            out << 'r';
            break;

        case(b):
            out << 'b';
            break;

        case (u):
            out << 'u';
            break;

        case (d):
            out << 'd';
            break;
    }
    return out;
}

Twoside::Twoside(const Color &c1, const Color &c2, const direction &d1, const direction &d2){
    color[0] = c1;
    color[1] = c2;
    dir[0] = Dir(d1);
    dir[1] = Dir(d2);
}

void Twoside::L() {
    dir[0].L();
    dir[1].L();
}

void Twoside::R() {
    dir[0].R();
    dir[1].R();
}

void Twoside::F() {
    dir[0].F();
    dir[1].F();
}

void Twoside::B() {
    dir[0].B();
    dir[1].B();
}

void Twoside::U() {
    dir[0].U();
    dir[1].U();
}

void Twoside::D() {
    dir[0].D();
    dir[1].D();
}

void Twoside::rL() {
    dir[0].rL();
    dir[1].rL();
}

void Twoside::rR() {
    dir[0].rR();
    dir[1].rR();
}

void Twoside::rF() {
    dir[0].rF();
    dir[1].rF();
}

void Twoside::rB() {
    dir[0].rB();
    dir[1].rB();
}

void Twoside::rU() {
    dir[0].rU();
    dir[1].rU();
}

void Twoside::rD() {
    dir[0].rD();
    dir[1].rD();
}

bool Twoside::is_l() {
    return ((dir[0].dir == l) || (dir[1].dir == l));
}

bool Twoside::is_r() {
    return ((dir[0].dir == r) || (dir[1].dir == r));
}

bool Twoside::is_f() {
    return ((dir[0].dir == f) || (dir[1].dir == f));
}

bool Twoside::is_b() {
    return ((dir[0].dir == b) || (dir[1].dir == b));
}

bool Twoside::is_u() {
    return ((dir[0].dir == u) || (dir[1].dir == u));
}

bool Twoside::is_d() {
    return ((dir[0].dir == d) || (dir[1].dir == d));
}

Color Twoside::frontside(){
    if (this->is_f()){
        if (dir[0] == Dir(f)) return color[0];
        else return color[1];
    }
    else return Color::X;
}

Color Twoside::backside(){
    if (this->is_b()){
        if (dir[0] == Dir(b)) return color[0];
        else return color[1];
    }
    else return Color::X;
}

Color Twoside::leftside(){
    if (this->is_l()){
        if (dir[0] == Dir(l)) return color[0];
        else return color[1];
    }
    else return Color::X;
}

Color Twoside::rightside(){
    if (this->is_r()){
        if (dir[0] == Dir(r)) return color[0];
        else return color[1];
    }
    else return Color::X;
}

Color Twoside::upside(){
    if (this->is_u()){
        if (dir[0] == Dir(u)) return color[0];
        else return color[1];
    }
    else return Color::X;
}

Color Twoside::downside(){
    if (this->is_d()){
        if (dir[0] == Dir(d)) return color[0];
        else return color[1];
    }
    else return Color::X;
}

bool Twoside::placed() {
    return (((frontside() == White) && (upside() == Blue)) ||
            ((frontside() == White) && (leftside() == Orange))||
            ((frontside() == White) && (rightside() == Red))||
            ((frontside() == White) && (downside() == Green))||
            ((leftside() == Orange) && (upside() == Blue))||
            ((rightside() == Red) && (upside() == Blue))||
            ((leftside() == Orange) && (downside() == Green))||
            ((rightside() == Red) && (downside() == Green))||
            ((backside() == Yellow) && (upside() == Blue))||
            ((backside() == Yellow) && (leftside() == Orange))||
            ((backside() == Yellow) && (rightside() == Red))||
            ((backside() == Yellow) && (downside() == Green)));
}

const Dir *Twoside::get_dir() const{
    return dir;
}

const Color *Twoside::get_color() const{
    return color;
}

std::ostream &operator <<(std::ostream &out, Twoside a){
    switch (a.color[0]){
        case (White):
            std::cout << "((" << a.dir[0] << ", White), ";
            break;

        case (Blue):
            std::cout << "((" << a.dir[0] << ", Blue), ";
            break;

        case (Red):
            std::cout << "((" << a.dir[0] << ", Red), ";
            break;

        case (Orange):
            std::cout << "((" << a.dir[0] << ", Orange), ";
            break;

        case (Green):
            std::cout << "((" << a.dir[0] << ", Green), ";
            break;

        case (Yellow):
            std::cout << "((" << a.dir[0] << ", Yellow), ";
            break;
    }

    switch (a.color[1]){
        case (White):
            std::cout << "(" << a.dir[1] << ", White))";
            break;

        case (Blue):
            std::cout << "(" << a.dir[1] << ", Blue))";
            break;

        case (Red):
            std::cout << "(" << a.dir[1] << ", Red))";
            break;

        case (Orange):
            std::cout << "(" << a.dir[1] << ", Orange))";
            break;

        case (Green):
            std::cout << "(" << a.dir[1] << ", Green))";
            break;

        case (Yellow):
            std::cout << "(" << a.dir[1] << ", Yellow))";
            break;
    }
    return out;
}

Angle::Angle() = default;

Angle::Angle(const Angle &c) = default;

Angle &Angle::operator=(const Angle &c1) = default;

Angle::Angle(const Color &c1, const Color &c2, const Color &c3, const direction &d1, const direction &d2, const direction &d3){
    color[0] = c1;
    color[1] = c2;
    color[2] = c3;

    dir[0] = Dir(d1);
    dir[1] = Dir(d2);
    dir[2] = Dir(d3);
}


void Angle::L(){
    dir[0].L();
    dir[1].L();
    dir[2].L();
}

void Angle::R(){
    dir[0].R();
    dir[1].R();
    dir[2].R();
}

void Angle::F(){
    dir[0].F();
    dir[1].F();
    dir[2].F();
}

void Angle::B(){
    dir[0].B();
    dir[1].B();
    dir[2].B();
}

void Angle::U(){
    dir[0].U();
    dir[1].U();
    dir[2].U();
}

void Angle::D(){
    dir[0].D();
    dir[1].D();
    dir[2].D();
}


void Angle::rL(){
    dir[0].rL();
    dir[1].rL();
    dir[2].rL();
}

void Angle::rR(){
    dir[0].rR();
    dir[1].rR();
    dir[2].rR();
}

void Angle::rF(){
    dir[0].rF();
    dir[1].rF();
    dir[2].rF();
}

void Angle::rB(){
    dir[0].rB();
    dir[1].rB();
    dir[2].rB();
}

void Angle::rU(){
    dir[0].rU();
    dir[1].rU();
    dir[2].rU();
}

void Angle::rD(){
    dir[0].rD();
    dir[1].rD();
    dir[2].rD();
}

bool Angle::is_l() {
    return ((dir[0].dir == l) || (dir[1].dir == l) || (dir[2].dir == l));
}

bool Angle::is_r() {
    return ((dir[0].dir == r) || (dir[1].dir == r) || (dir[2].dir == r));
}

bool Angle::is_f() {
    return ((dir[0].dir == f) || (dir[1].dir == f) || (dir[2].dir == f));
}

bool Angle::is_b() {
    return ((dir[0].dir == b) || (dir[1].dir == b) || (dir[2].dir == b));
}

bool Angle::is_u() {
    return ((dir[0].dir == u) || (dir[1].dir == u) || (dir[2].dir == u));
}

bool Angle::is_d() {
    return ((dir[0].dir == d) || (dir[1].dir == d) || (dir[2].dir == d));
}

Color Angle::frontside(){
    if (this->is_f()) {
        if (dir[0] == Dir(f)) return color[0];
        else if (dir[1] == Dir(f)) return color[1];
        else return color[2];
    }
    else return Color::X;
}

Color Angle::backside(){
    if (this->is_b()) {
        if (dir[0] == Dir(b)) return color[0];
        else if (dir[1] == Dir(b)) return color[1];
        else return color[2];
    }
    else return Color::X;
}

Color Angle::leftside(){
    if (this->is_l()) {
        if (dir[0] == Dir(l)) return color[0];
        else if (dir[1] == Dir(l)) return color[1];
        else return color[2];
    }
    else return Color::X;
}

Color Angle::rightside(){
    if (this->is_r()) {
        if (dir[0] == Dir(r)) return color[0];
        else if (dir[1] == Dir(r)) return color[1];
        else return color[2];
    }
    else return Color::X;
}

Color Angle::upside(){
    if (this->is_u()) {
        if (dir[0] == Dir(u)) return color[0];
        else if (dir[1] == Dir(u)) return color[1];
        else return color[2];
    }
    else return Color::X;
}

Color Angle::downside(){
    if (this->is_d()) {
        if (dir[0] == Dir(d)) return color[0];
        else if (dir[1] == Dir(d)) return color[1];
        else return color[2];
    }
    else return Color::X;
}

bool Angle::placed(){
    return (((frontside() == White)&&(upside() == Blue)&&(leftside() == Orange))||
    ((frontside() == White)&&(upside() == Blue)&&(rightside() == Red))||
    ((frontside() == White)&&(upside() == Blue)&&(downside() == Green))||
    ((frontside() == White)&&(downside() == Green)&&(rightside() == Red))||
    ((backside() == Yellow)&&(upside() == Blue)&&(leftside() == Orange))||
    ((backside() == Yellow)&&(upside() == Blue)&&(rightside() == Red))||
    ((backside() == Yellow)&&(leftside() == Orange)&&(downside() == Green))||
    ((backside() == Yellow)&&(downside() == Green)&&(rightside() == Red)));
}

bool Angle::twisted(){
    if (placed()) return true;
    else return (((color[0] == Yellow) && (color[1] == Blue) && (color[2] == Orange) && (is_b()) && (is_u()) && (is_l())) ||
                 ((color[0] == Yellow) && (color[1] == Red) && (color[2] == Blue) && (is_b()) && (is_r()) && (is_u())) ||
                 ((color[0] == Yellow) && (color[1] == Green) && (color[2] == Red) && (is_b()) && (is_d()) && (is_r())) ||
                 ((color[0] == Yellow) && (color[1] == Orange) && (color[2] == Green) && (is_b()) && (is_l()) && (is_d())));

}

std::ostream &operator <<(std::ostream &out, Angle a){

    switch (a.color[0]){
        case (White):
            std::cout << "((" << a.dir[0] << ", White), ";
            break;

        case (Blue):
            std::cout << "((" << a.dir[0] << ", Blue), ";
            break;

        case (Red):
            std::cout << "((" << a.dir[0] << ", Red), ";
            break;

        case (Orange):
            std::cout << "((" << a.dir[0] << ", Orange), ";
            break;

        case (Green):
            std::cout << "((" << a.dir[0] << ", Green), ";
            break;

        case (Yellow):
            std::cout << "((" << a.dir[0] << ", Yellow), ";
            break;
    }

    switch (a.color[1]){
        case (White):
            std::cout << "(" << a.dir[1] << ", White), ";
            break;

        case (Blue):
            std::cout << "(" << a.dir[1] << ", Blue), ";
            break;

        case (Red):
            std::cout << "(" << a.dir[1] << ", Red), ";
            break;

        case (Orange):
            std::cout << "(" << a.dir[1] << ", Orange), ";
            break;

        case (Green):
            std::cout << "(" << a.dir[1] << ", Green), ";
            break;

        case (Yellow):
            std::cout << "(" << a.dir[1] << ", Yellow), ";
            break;
    }

    switch (a.color[2]){
        case (White):
            std::cout << "(" << a.dir[2] << ", White))";
            break;

        case (Blue):
            std::cout << "(" << a.dir[2] << ", Blue))";
            break;

        case (Red):
            std::cout << "(" << a.dir[2] << ", Red))";
            break;

        case (Orange):
            std::cout << "(" << a.dir[2] << ", Orange))";
            break;

        case (Green):
            std::cout << "(" << a.dir[2] << ", Green))";
            break;

        case (Yellow):
            std::cout << "(" << a.dir[2] << ", Yellow))";
            break;
    }
    return out;
}