#include <iostream>
using namespace std;

string personajeVivo(int vida)
{
    string respuesta = "";
    if (vida <= 0)
    {
        respuesta = "No";
    }
    else
    {
        respuesta = "Si";
    }
    return respuesta;
}

string mostrarFicha(string nombre, int vida, int nivel, int coins, float speed, bool llave)
{
    cout << "" << endl;
    cout << "Ficha Tecnica" << endl;
    cout << "=============" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Monedas: " << coins << endl;
    cout << "Velocidad: " << speed << endl;
    cout << "Esta Vivo?: " << personajeVivo(vida) << endl;
    cout << "Tiene llave?: " << llave << endl;
    cout << "" << endl;
}

string accesoArea51(int nivel, bool llave)
{
    if (nivel >= 5 && llave == true)
    {
        cout << "Ha ingresado al Area 51!" << endl;
    }
    else
    {
        cout << "Los secretos del Area 51 siguen ocultos para Ud." << endl;
    }
}

int main()
{
    string nombrePersonaje = "Aquiles Baeza";
    int vida = 500;
    int monedas = 0;
    float velocidad = 4.5f;
    bool estaVivo = true;
    bool tieneLlave = false;
    int nivel = 1;

    mostrarFicha(nombrePersonaje, vida, nivel, monedas, velocidad, tieneLlave);

    cout << "Tratando de ingresar al Area 51..." << endl;
    cout << "El nivel requerido es 5 y necesita una llave..." << endl;
    accesoArea51(nivel,tieneLlave);

    cout << "" << endl;
    cout << "Atacamos a nuestro personaje con 100 de danio!" << endl;
    vida = vida - 100;
    tieneLlave = true;
    
    cout << "" << endl;
    cout << "Por haber encontrado la llave, has subido 4 niveles!" << endl;
    nivel = nivel + 4;

    mostrarFicha(nombrePersonaje, vida, nivel, monedas, velocidad, tieneLlave);
    accesoArea51(nivel,tieneLlave);

    return 0;
}