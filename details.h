//
// Created by rblas on 07.05.2022.
//
#include <iostream>

#ifndef CUBE_DETAILS_H
#define CUBE_DETAILS_H

enum class direction {
    f, b, r, l, u, d
};

enum class Color {
    W, B, R, O, G, Y, X
};

std::ostream &operator<<(std::ostream &out, Color c);

std::istream &operator>>(std::istream &in, direction &a);

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

    bool operator==(const Dir &d1) const = default;

    void rL();

    void rR();

    void rF();

    void rB();

    void rU();

    void rD();
};

std::ostream &operator<<(std::ostream &out, Dir &a);

std::istream &operator>>(std::istream &in, Dir &a);

class Twoside {

public:
    Dir dir[2];
    Color color[2]{};

    Twoside();

    bool operator==(const Twoside &c1) const = default;

    Twoside(const Twoside &c);

    Twoside &operator=(const Twoside &c1);

    Twoside(const Color &c1, const Color &c2, const direction &d1, const direction &d2);

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

    Color frontside();

    Color backside();

    Color leftside();

    Color rightside();

    Color upside();

    Color downside();

    bool placed();

    void rL();

    void rR();

    void rF();

    void rB();

    void rU();

    void rD();
};

std::ostream &operator<<(std::ostream &out, Twoside a);

class Angle {

public:

    Dir dir[3];
    Color color[3];

    Angle();

    Angle(const Angle &c);

    Angle &operator=(const Angle &c1);

    bool operator==(const Angle &c1) const = default;

    Angle(const Color &c1, const Color &c2, const Color &c3, const direction &d1, const direction &d2,
          const direction &d3);

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

    Color frontside();

    Color backside();

    Color leftside();

    Color rightside();

    Color upside();

    Color downside();

    bool placed();

    bool twisted();

    void rL();

    void rR();

    void rF();

    void rB();

    void rU();

    void rD();
};


std::ostream &operator<<(std::ostream &out, Angle a);

#endif //CUBE_DETAILS_H
