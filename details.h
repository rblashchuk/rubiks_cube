//
// Created by rblas on 07.05.2022.
//

#ifndef CUBE_DETAILS_H
#define CUBE_DETAILS_H

enum class dir{f, b, r, l, u, d};

enum class Color {W, B, R, O, G, Y};

class Dir {
public:
    dir dir;
    void L();

    void R();

    void F();

    void B();

    void U();

    void D();
};


class Two_side {
protected:
    Color color[2];
    Dir dir[2];
public:
    Two_side(const Two_side &c);

    Two_side &operator=(const Two_side &c1);

    Two_side(const Color &c1, const Color &c2, const Dir &d1, const Dir &d2);

    const Dir *get_dir() const;

    const Color *get_color() const;


};

class Angle {
protected:

};

#endif //CUBE_DETAILS_H
