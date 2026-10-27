#include "Juego.h"
#include <iostream>
using namespace std;

Juego::Juego():
jugador("Surcadora Justiciera")
{
    enemigos.push_back(
        new JefeFinal()
    );
}

void Juego::iniciar()
{
    cout << "Space Defenders" << endl;

    for (int i = 1; i <= 11; ++i) {
        enemigos.emplace_back(new NaveEnemiga(to_string(i),20,10));
    }

    for(auto enemigo : enemigos)
    {
        cout << "Enemigo " << enemigo->getNombre() << " a la vista!" << endl;
    }
}