//
// Created by rblas on 07.05.2022.
//
#include <iostream>

#ifndef CUBE_DETAILS_H
#define CUBE_DETAILS_H

enum class direction {f, b, r, l, u, d};

enum class Color {W, B, R, O, G, Y};

class Dir {
public:
    direction dir;

    Dir(direction a);

    Dir();

    void L();

    void R();

    void F();

    void B();

    void U();

    void D();

};

std::ostream &operator <<(std::ostream &out, Dir &d);

class Two_side {

public:
    Dir dir[2];
    Color color[2];

    Two_side(const Two_side &c);

    Two_side &operator=(const Two_side &c1);

    Two_side(const Color &c1, const Color &c2, const Dir &d1, const Dir &d2);

    const Dir *get_dir() const;

    const Color *get_color() const;

    void L();

    void R();

    void F();

    void B();

    void U();

    void D();

    bool is_l();

    bool is_r();

    bool is_f();

    bool is_b();

    bool is_u();

    bool is_d();

};

std::ostream &operator <<(std::ostream &out, Two_side a);

class Angle {

public:

    Dir dir[3];
    Color color[3];

    Angle(const Angle &c);

    Angle &operator=(const Angle &c1);

    Angle(const Color &c1, const Color &c2, const Color &c3, const Dir &d1, const Dir &d2, const Dir &d3);

    const Dir *get_dir() const;

    const Color *get_color() const;

    void L();

    void R();

    void F();

    void B();

    void U();

    void D();

    bool is_l();

    bool is_r();

    bool is_f();

    bool is_b();

    bool is_u();

    bool is_d();

};

std::ostream &operator <<(std::ostream &out, Angle a);

#endif //CUBE_DETAILS_H
