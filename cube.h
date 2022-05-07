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

    Angle FLU();

    Angle FUR();

    Angle FRD();

    Angle FDL();

    Angle BRU();

    Angle BDR();

    Angle BLD();

    Angle BUL();

    Twoside FU();

    Twoside FR();

    Twoside FD();

    Twoside FL();

    Twoside UR();

    Twoside RD();

    Twoside DL();

    Twoside LU();

    Twoside BU();

    Twoside BR();

    Twoside BD();

    Twoside BL();

    Color *frontside();

    Color *backside();

    Color *leftside();

    Color *rightside();

    Color *upside();

    Color *downside();
};

std::ostream &operator<<(std::ostream &out, Cube c);


#endif //CUBE_CUBE_H
