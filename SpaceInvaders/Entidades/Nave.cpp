#include "Nave.h"
#include <iostream>
using namespace std;

Nave::Nave(string nombreNave, int vidaNave, int ataqueNave)
{
    this->nombre = nombreNave;
    this->vida = vidaNave;
    this->ataque = ataqueNave;
};

void Nave::recibirDanio(int cantidadDanio)
{
    vida -= cantidadDanio;

    if (vida < 0)
    {
        vida = 0;
    }    
}

void Nave::mostrarEstado() const
{
    cout << nombre << " Vida Restante:" << vida << endl;
}

string Nave::getNombre() const
{
    return nombre;
};

int Nave::getVida() const
{
    return vida;
};

int Nave::getAtaque() const
{
    return ataque;
};

bool Nave::estaDestruida() const
{
    if(vida <= 0){
        return false;
    }else{
        return true;
    };
};