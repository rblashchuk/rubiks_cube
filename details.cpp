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

Two_side::Two_side(const Two_side &c) = default;

Two_side &Two_side::operator=(const Two_side &c1) = default;

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

Two_side::Two_side(const Color &c1, const Color &c2, const Dir &d1, const Dir &d2){
    color[0] = c1;
    color[1] = c2;
    dir[0] = d1;
    dir[1] = d2;
}

void Two_side::L() {
    dir[0].L();
    dir[1].L();
}

void Two_side::R() {
    dir[0].R();
    dir[1].R();
}

void Two_side::F() {
    dir[0].F();
    dir[1].F();
}

void Two_side::B() {
    dir[0].B();
    dir[1].B();
}

void Two_side::U() {
    dir[0].U();
    dir[1].U();
}

void Two_side::D() {
    dir[0].D();
    dir[1].D();
}

bool Two_side::is_l() {
    return ((dir[0].dir == direction::l) || (dir[1].dir == direction::l));
}

bool Two_side::is_r() {
    return ((dir[0].dir == direction::r) || (dir[1].dir == direction::r));
}

bool Two_side::is_f() {
    return ((dir[0].dir == direction::f) || (dir[1].dir == direction::f));
}

bool Two_side::is_b() {
    return ((dir[0].dir == direction::b) || (dir[1].dir == direction::b));
}

bool Two_side::is_u() {
    return ((dir[0].dir == direction::u) || (dir[1].dir == direction::u));
}

bool Two_side::is_d() {
    return ((dir[0].dir == direction::d) || (dir[1].dir == direction::d));
}

const Dir *Two_side::get_dir() const{
    return dir;
}

const Color *Two_side::get_color() const{
    return color;
}

std::ostream &operator <<(std::ostream &out, Two_side a){
    switch (a.color[0]){
        case (Color::W):
            std::cout << "((" << a.dir[0] << ", W), ";
            break;

        case (Color::B):
            std::cout << "((" << a.dir[0] << ", B), ";
            break;

        case (Color::R):
            std::cout << "((" << a.dir[0] << ", R), ";
            break;

        case (Color::O):
            std::cout << "((" << a.dir[0] << ", O), ";
            break;

        case (Color::G):
            std::cout << "((" << a.dir[0] << ", G), ";
            break;

        case (Color::Y):
            std::cout << "((" << a.dir[0] << ", Y), ";
            break;
    }

    switch (a.color[1]){
        case (Color::W):
            std::cout << "(" << a.dir[1] << ", W))";
            break;

        case (Color::B):
            std::cout << "(" << a.dir[1] << ", B))";
            break;

        case (Color::R):
            std::cout << "(" << a.dir[1] << ", R))";
            break;

        case (Color::O):
            std::cout << "(" << a.dir[1] << ", O))";
            break;

        case (Color::G):
            std::cout << "(" << a.dir[1] << ", G))";
            break;

        case (Color::Y):
            std::cout << "(" << a.dir[1] << ", Y))";
            break;
    }
    return out;
}

Angle::Angle(const Angle &c) = default;

Angle &Angle::operator=(const Angle &c1) = default;

Angle::Angle(const Color &c1, const Color &c2, const Color &c3, const Dir &d1, const Dir &d2, const Dir &d3){
    color[0] = c1;
    color[1] = c2;
    color[2] = c3;

    dir[0] = d1;
    dir[1] = d2;
    dir[2] = d3;
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
            std::cout << "((" << a.dir[0] << ", W), ";
            break;

        case (Color::B):
            std::cout << "((" << a.dir[0] << ", B), ";
            break;

        case (Color::R):
            std::cout << "((" << a.dir[0] << ", R), ";
            break;

        case (Color::O):
            std::cout << "((" << a.dir[0] << ", O), ";
            break;

        case (Color::G):
            std::cout << "((" << a.dir[0] << ", G), ";
            break;

        case (Color::Y):
            std::cout << "((" << a.dir[0] << ", Y), ";
            break;
    }

    switch (a.color[1]){
        case (Color::W):
            std::cout << "(" << a.dir[1] << ", W), ";
            break;

        case (Color::B):
            std::cout << "(" << a.dir[1] << ", B), ";
            break;

        case (Color::R):
            std::cout << "(" << a.dir[1] << ", R), ";
            break;

        case (Color::O):
            std::cout << "(" << a.dir[1] << ", O), ";
            break;

        case (Color::G):
            std::cout << "(" << a.dir[1] << ", G), ";
            break;

        case (Color::Y):
            std::cout << "(" << a.dir[1] << ", Y), ";
            break;
    }

    switch (a.color[2]){
        case (Color::W):
            std::cout << "(" << a.dir[2] << ", W))";
            break;

        case (Color::B):
            std::cout << "(" << a.dir[2] << ", B))";
            break;

        case (Color::R):
            std::cout << "(" << a.dir[2] << ", R))";
            break;

        case (Color::O):
            std::cout << "(" << a.dir[2] << ", O))";
            break;

        case (Color::G):
            std::cout << "(" << a.dir[2] << ", G))";
            break;

        case (Color::Y):
            std::cout << "(" << a.dir[2] << ", Y))";
            break;
    }
    return out;
}