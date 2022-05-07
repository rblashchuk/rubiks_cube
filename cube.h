#include "details.h"

#ifndef CUBE_CUBE_H
#define CUBE_CUBE_H


class Cube {
public:
    Twoside twosides[12];
    Angle angles[8];

    Cube(const Cube &c);

    Cube &operator=(const Cube &c1);

    Cube();
    void L();

    void R();

    void F();

    void B();

    void U();

    void D();
};


#endif //CUBE_CUBE_H
