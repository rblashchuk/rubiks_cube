#include "details.h"

Dir::Dir(direction a){
    dir = a;
}

Dir::Dir() = default;

void Dir::L(){
    switch (dir) {
        case (direction::b):
            dir = direction::u;
            break;

        case (direction::u):
            dir = direction::f;
            break;

        case(direction::f):
            dir = direction::d;
            break;

        case(direction::d):
            dir = direction::b;
            break;

        case (direction::l):
            dir = direction::l;
            break;

        case (direction::r):
            dir = direction::r;
            break;
    }
}

void Dir::R(){
    switch (dir) {
        case (direction::b):
            dir = direction::d;
            break;

        case (direction::d):
            dir = direction::f;
            break;

        case(direction::f):
            dir = direction::u;
            break;

        case(direction::u):
            dir = direction::b;
            break;

        case (direction::l):
            dir = direction::l;
            break;

        case (direction::r):
            dir = direction::r;
            break;
    }
}

void Dir::F(){
    switch (dir) {
        case (direction::l):
            dir = direction::u;
            break;

        case (direction::u):
            dir = direction::r;
            break;

        case(direction::r):
            dir = direction::d;
            break;

        case(direction::d):
            dir = direction::l;
            break;

        case (direction::b):
            dir = direction::b;
            break;

        case (direction::f):
            dir = direction::f;
            break;
    }
}

void Dir::B(){
    switch (dir) {
        case (direction::l):
            dir = direction::d;
            break;

        case (direction::d):
            dir = direction::r;
            break;

        case(direction::r):
            dir = direction::u;
            break;

        case(direction::u):
            dir = direction::l;
            break;

        case (direction::b):
            dir = direction::b;
            break;

        case (direction::f):
            dir = direction::f;
            break;
    }
}

void Dir::U(){
    switch (dir) {
        case (direction::l):
            dir = direction::b;
            break;

        case (direction::b):
            dir = direction::r;
            break;

        case(direction::r):
            dir = direction::f;
            break;

        case(direction::f):
            dir = direction::l;
            break;

        case (direction::u):
            dir = direction::u;
            break;

        case (direction::d):
            dir = direction::d;
            break;
    }
}

void Dir::D(){
    switch (dir) {
        case (direction::l):
            dir = direction::f;
            break;

        case (direction::f):
            dir = direction::r;
            break;

        case(direction::r):
            dir = direction::b;
            break;

        case(direction::b):
            dir = direction::l;
            break;

        case (direction::u):
            dir = direction::u;
            break;

        case (direction::d):
            dir = direction::d;
            break;
    }
}

Twoside::Twoside() = default;

Twoside::Twoside(const Twoside &c) = default;

Twoside &Twoside::operator=(const Twoside &c1) = default;

std::ostream &operator <<(std::ostream &out, Dir &d){
    switch (d.dir) {
        case (direction::l):
            out << 'l';
            break;

        case (direction::f):
            out << 'f';
            break;

        case(direction::r):
            out << 'r';
            break;

        case(direction::b):
            out << 'b';
            break;

        case (direction::u):
            out << 'u';
            break;

        case (direction::d):
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

bool Twoside::is_l() {
    return ((dir[0].dir == direction::l) || (dir[1].dir == direction::l));
}

bool Twoside::is_r() {
    return ((dir[0].dir == direction::r) || (dir[1].dir == direction::r));
}

bool Twoside::is_f() {
    return ((dir[0].dir == direction::f) || (dir[1].dir == direction::f));
}

bool Twoside::is_b() {
    return ((dir[0].dir == direction::b) || (dir[1].dir == direction::b));
}

bool Twoside::is_u() {
    return ((dir[0].dir == direction::u) || (dir[1].dir == direction::u));
}

bool Twoside::is_d() {
    return ((dir[0].dir == direction::d) || (dir[1].dir == direction::d));
}

const Dir *Twoside::get_dir() const{
    return dir;
}

const Color *Twoside::get_color() const{
    return color;
}

std::ostream &operator <<(std::ostream &out, Twoside a){
    switch (a.color[0]){
        case (Color::W):
            std::cout << "((" << a.dir[0] << ", White), ";
            break;

        case (Color::B):
            std::cout << "((" << a.dir[0] << ", Blue), ";
            break;

        case (Color::R):
            std::cout << "((" << a.dir[0] << ", Red), ";
            break;

        case (Color::O):
            std::cout << "((" << a.dir[0] << ", Orange), ";
            break;

        case (Color::G):
            std::cout << "((" << a.dir[0] << ", Green), ";
            break;

        case (Color::Y):
            std::cout << "((" << a.dir[0] << ", Yellow), ";
            break;
    }

    switch (a.color[1]){
        case (Color::W):
            std::cout << "(" << a.dir[1] << ", White))";
            break;

        case (Color::B):
            std::cout << "(" << a.dir[1] << ", Blue))";
            break;

        case (Color::R):
            std::cout << "(" << a.dir[1] << ", Red))";
            break;

        case (Color::O):
            std::cout << "(" << a.dir[1] << ", Orange))";
            break;

        case (Color::G):
            std::cout << "(" << a.dir[1] << ", Green))";
            break;

        case (Color::Y):
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

const Dir *Angle::get_dir() const{
    return dir;
}

const Color *Angle::get_color() const{
    return color;
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

bool Angle::is_l() {
    return ((dir[0].dir == direction::l) || (dir[1].dir == direction::l) || (dir[2].dir == direction::l));
}

bool Angle::is_r() {
    return ((dir[0].dir == direction::r) || (dir[1].dir == direction::r) || (dir[2].dir == direction::r));
}

bool Angle::is_f() {
    return ((dir[0].dir == direction::f) || (dir[1].dir == direction::f) || (dir[2].dir == direction::f));
}

bool Angle::is_b() {
    return ((dir[0].dir == direction::b) || (dir[1].dir == direction::b) || (dir[2].dir == direction::b));
}

bool Angle::is_u() {
    return ((dir[0].dir == direction::u) || (dir[1].dir == direction::u) || (dir[2].dir == direction::u));
}

bool Angle::is_d() {
    return ((dir[0].dir == direction::d) || (dir[1].dir == direction::d) || (dir[2].dir == direction::d));
}

std::ostream &operator <<(std::ostream &out, Angle a){

    switch (a.color[0]){
        case (Color::W):
            std::cout << "((" << a.dir[0] << ", White), ";
            break;

        case (Color::B):
            std::cout << "((" << a.dir[0] << ", Blue), ";
            break;

        case (Color::R):
            std::cout << "((" << a.dir[0] << ", Red), ";
            break;

        case (Color::O):
            std::cout << "((" << a.dir[0] << ", Orange), ";
            break;

        case (Color::G):
            std::cout << "((" << a.dir[0] << ", Green), ";
            break;

        case (Color::Y):
            std::cout << "((" << a.dir[0] << ", Yellow), ";
            break;
    }

    switch (a.color[1]){
        case (Color::W):
            std::cout << "(" << a.dir[1] << ", White), ";
            break;

        case (Color::B):
            std::cout << "(" << a.dir[1] << ", Blue), ";
            break;

        case (Color::R):
            std::cout << "(" << a.dir[1] << ", Red), ";
            break;

        case (Color::O):
            std::cout << "(" << a.dir[1] << ", Orange), ";
            break;

        case (Color::G):
            std::cout << "(" << a.dir[1] << ", Green), ";
            break;

        case (Color::Y):
            std::cout << "(" << a.dir[1] << ", Yellow), ";
            break;
    }

    switch (a.color[2]){
        case (Color::W):
            std::cout << "(" << a.dir[2] << ", White))";
            break;

        case (Color::B):
            std::cout << "(" << a.dir[2] << ", Blue))";
            break;

        case (Color::R):
            std::cout << "(" << a.dir[2] << ", Red))";
            break;

        case (Color::O):
            std::cout << "(" << a.dir[2] << ", Orange))";
            break;

        case (Color::G):
            std::cout << "(" << a.dir[2] << ", Green))";
            break;

        case (Color::Y):
            std::cout << "(" << a.dir[2] << ", Yellow))";
            break;
    }
    return out;
}