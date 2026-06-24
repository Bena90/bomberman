#include "Balloom.h"
#include <cstdlib>

Balloom::Balloom() : Enemigo()
{
    setPuntos(100);
    direccion = rand() % 4;
}

Balloom::Balloom(Posicion posicion, int nivel) : Enemigo(1, nivel, 100, posicion)
{
    direccion = rand() % 4;
}

void Balloom::mover(int anchoMapa, int altoMapa, int* celdas, Posicion posJugador)
{
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    int nuevoX = getPosicion().getX() + dx[direccion];
    int nuevoY = getPosicion().getY() + dy[direccion];

    if (nuevoX >= 0 && nuevoX < anchoMapa && nuevoY >= 0 && nuevoY < altoMapa
        && celdas[nuevoY * anchoMapa + nuevoX] == 0)
    {
        setPosicion(Posicion(nuevoX, nuevoY));
    }
    else
    {
        direccion = rand() % 4;
    }
}
