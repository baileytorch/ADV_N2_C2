#include "NaveJugador.h"
#include <iostream>

using namespace std;

NaveJugador::NaveJugador(string nombre) : Nave(nombre, 100, 20)
{
    escudo = 50;
}

void NaveJugador::disparar(Nave &objetivo)
{
    cout << nombre << " le dispara a " << objetivo.getNombre() << endl;

    objetivo.recibirDanio(ataque);
}

void NaveJugador::reparar()
{
    vida += 20;

    if (vida > 100)
    {
        vida = 100;
    }
};