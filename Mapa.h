#ifndef MAPA_H
#define MAPA_H

class Mapa
{
private:
    int id;
    int nivel;
    int ancho;
    int alto;
    int* celdas;

public:
    Mapa();
    Mapa(int id, int nivel, int ancho, int alto);
    ~Mapa();
    int getId();
    void setId(int id);
    int getNivel();
    void setNivel(int nivel);
    int getAncho();
    void setAncho(int ancho);
    int getAlto();
    void setAlto(int alto);
    int* getCeldas();
    int getCelda(int x, int y);
    void setCelda(int x, int y, int valor);
    void inicializar(int id, int nivel, int ancho, int alto);
};

#endif
