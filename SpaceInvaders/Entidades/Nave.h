#ifndef NAVE_H
#define NAVE_H

using namespace std;
#include <string>

class Nave
{
protected:
    string nombre;
    int vida;
    int ataque;
    
public:
    Nave(string nom, int vid, int atq);
    virtual ~Nave();

    virtual void disparar(
        Nave& objetivo
    )=0;

    string getNombre() const;
    int getVida() const;
    int getAtaque() const;
    bool estaDestruida() const;

    void recibirDanio(int cantidad);
    void mostrarEstado() const;
};

#endif