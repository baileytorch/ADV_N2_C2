#include "Juego.h"
#include <iostream>
using namespace std;

Juego::Juego() : jugador("Surcadora Justiciera")
{
}

void Juego::iniciar()
{
    cout << "Space Defenders" << endl;

    for (int i = 1; i <= 11; ++i)
    {
        enemigos.emplace_back(new NaveEnemiga(to_string(i), 20, 10));
    }

    enemigos.push_back(
        new JefeFinal());

    for (auto enemigo : enemigos)
    {
        cout << "Enemigo " << enemigo->getNombre() << " a la vista!" << endl;
        while (!enemigo->estaDestruida() && !jugador.estaDestruida())
        {
            jugador.disparar(*enemigo);
            enemigo->mostrarEstado();

            if (!enemigo->estaDestruida())
            {
                enemigo->disparar(jugador);
                jugador.mostrarEstado();
            }
            
        }
        
        if (jugador.estaDestruida())
        {
            cout << "Game Over!" << endl;
        }
        
        if (enemigo->estaDestruida())
        {
            cout << "Enemigo" << enemigo->getNombre() << " destruido..." << endl;
        }
    }

    cout << jugador.getNombre() << " se alza con la victoria!" << endl;
}