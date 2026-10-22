#include "NaveEnemiga.h"
#include <iostream>

using namespace std;

NaveEnemiga::NaveEnemiga(string nombre, int vida, int ataque) : Nave(nombre, vida, ataque) {}

void NaveEnemiga::disparar(Nave &objetivo)
{
    cout << nombre << " le dispara a " << objetivo.getNombre() << endl;

    objetivo.recibirDanio(ataque);
}