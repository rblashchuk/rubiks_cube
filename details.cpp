#include "details.h"

void Dir::L(){
    switch (dir) {
        case (dir::b):
            dir = dir::u;

        case (dir::u):
            dir = dir::f;

        case(dir::f):
            dir = dir::d;

        case(dir::d):
            dir = dir::b;

        case (dir::l):
            dir = dir::l;

        case (dir::r):
            dir = dir::r;
    }
}

void Dir::R(){
    switch (dir) {
        case (dir::b):
            dir = dir::d;

        case (dir::d):
            dir = dir::f;

        case(dir::f):
            dir = dir::u;

        case(dir::u):
            dir = dir::b;

        case (dir::l):
            dir = dir::l;

        case (dir::r):
            dir = dir::r;
    }
}

void Dir::F(){
    switch (dir) {
        case (dir::l):
            dir = dir::u;

        case (dir::u):
            dir = dir::r;

        case(dir::r):
            dir = dir::d;

        case(dir::d):
            dir = dir::l;

        case (dir::b):
            dir = dir::b;

        case (dir::f):
            dir = dir::f;
    }
}

void Dir::B(){
    switch (dir) {
        case (dir::l):
            dir = dir::d;

        case (dir::d):
            dir = dir::r;

        case(dir::r):
            dir = dir::u;

        case(dir::u):
            dir = dir::l;

        case (dir::b):
            dir = dir::b;

        case (dir::f):
            dir = dir::f;
    }
}

void Dir::U(){
    switch (dir) {
        case (dir::l):
            dir = dir::b;

        case (dir::b):
            dir = dir::r;

        case(dir::r):
            dir = dir::f;

        case(dir::f):
            dir = dir::l;

        case (dir::u):
            dir = dir::u;

        case (dir::d):
            dir = dir::d;
    }
}

void Dir::D(){
    switch (dir) {
        case (dir::l):
            dir = dir::f;

        case (dir::f):
            dir = dir::r;

        case(dir::r):
            dir = dir::b;

        case(dir::b):
            dir = dir::l;

        case (dir::u):
            dir = dir::u;

        case (dir::d):
            dir = dir::d;
    }
}
Two_side::Two_side(const Two_side &c) = default;

Two_side &Two_side::operator=(const Two_side &c1) = default;

Two_side::Two_side(const Color &c1, const Color &c2, const Dir &d1, const Dir &d2){
    color[0] = c1;
    color[1] = c2;
    dir[0] = d1;
    dir[1] = d2;
}

const Dir *Two_side::get_dir() const{
    return dir;
}

const Color *Two_side::get_color() const{
    return color;
}
