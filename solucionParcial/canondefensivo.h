#ifndef CANONDEFENSIVO_H
#define CANONDEFENSIVO_H
#include <canon.h>

class CanonDefensivo : public Canon
{
public:
    CanonDefensivo(short int posx, short int posy);
    void disparoLibre();

};

#endif // CANONDEFENSIVO_H
