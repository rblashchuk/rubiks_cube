#include "details.h"

#ifndef CUBE_CUBE_H
#define CUBE_CUBE_H


class Cube {
public:
    Twoside twosides[12];
    Angle angles[8];
    std::string log;
    bool log_flag;

    Cube(const Cube &c);

    Cube &operator=(const Cube &c1);

    bool operator==(const Cube &c1) const;

    Cube();

    void L();

    void R();

    void F();

    void B();

    void U();

    void D();

    void rL();

    void rR();

    void rF();

    void rB();

    void rU();

    void rD();

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


    void cross();

    void front_angles();

    void mid_twosides();

    void back_cross_placing();

    void back_cross_rotating();

    void windmill();

    void back_cross();

    void back_angles_placing();

    void g_twist();

    void back_angles_rotating();

    void rotate();

    void back_angles();

    void set_logging(bool flag);

    void reset_log();

    void load(const std::string& filename);

    void dump(const std::string &filename);

    void solve();

    std::string solve_sequence();

    void apply(const std::string& s);
};

bool is_correct(Cube &a);

void set_current(const std::string& filename);

std::string get_current();

std::ostream &operator<<(std::ostream &out, Cube c);


#endif //CUBE_CUBE_H
