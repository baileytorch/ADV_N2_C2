#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "../Entidades/NaveEnemiga.h"
#include "../Entidades/NaveJugador.h"

class Juego
{
private:
    NaveJugador jugador;

    vector<NaveEnemiga*> enemigos;
public:
    Juego(/* args */);
    ~Juego();

    void iniciar();
};

#endif