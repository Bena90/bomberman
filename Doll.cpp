#include "Doll.h"
#include <cstdlib>

Doll::Doll() : Enemigo()
{
    setPuntos(300);
}

Doll::Doll(Posicion posicion, int nivel) : Enemigo(1, nivel, 300, posicion)
{
}

void Doll::mover(int anchoMapa, int altoMapa, int* celdas, Posicion posJugador)
{
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    if (rand() % 100 < 30)
    {
        int dir = rand() % 4;
        int nuevoX = getPosicion().getX() + dx[dir];
        int nuevoY = getPosicion().getY() + dy[dir];

        if (nuevoX >= 0 && nuevoX < anchoMapa && nuevoY >= 0 && nuevoY < altoMapa
            && celdas[nuevoY * anchoMapa + nuevoX] == 0)
        {
            setPosicion(Posicion(nuevoX, nuevoY));
        }
    }
    else
    {
        int mejorDir = 0;
        int menorDist = 99999;

        for (int i = 0; i < 4; i++)
        {
            int nuevoX = getPosicion().getX() + dx[i];
            int nuevoY = getPosicion().getY() + dy[i];

            if (nuevoX >= 0 && nuevoX < anchoMapa && nuevoY >= 0 && nuevoY < altoMapa
                && celdas[nuevoY * anchoMapa + nuevoX] == 0)
            {
                int distX = nuevoX - posJugador.getX();
                int distY = nuevoY - posJugador.getY();
                int dist = distX * distX + distY * distY;

                if (dist < menorDist)
                {
                    menorDist = dist;
                    mejorDir = i;
                }
            }
        }

        int nuevoX = getPosicion().getX() + dx[mejorDir];
        int nuevoY = getPosicion().getY() + dy[mejorDir];

        if (nuevoX >= 0 && nuevoX < anchoMapa && nuevoY >= 0 && nuevoY < altoMapa
            && celdas[nuevoY * anchoMapa + nuevoX] == 0)
        {
            setPosicion(Posicion(nuevoX, nuevoY));
        }
    }
}
