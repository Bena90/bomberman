#ifndef POSICION_H
#define POSICION_H

class Posicion
{
private:
    int x;
    int y;

public:
    Posicion();
    Posicion(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
};

#endif
