#include <iostream>
using namespace std;

string personajeVivo(int vida){
    string respuesta = "";
    if(vida <= 0){
        respuesta = "No";
    }else{
        respuesta = "Si";
    }
    return respuesta;
}

string mostrarFicha(string nombre, int vida, int coins, float speed, bool llave){
    cout << "" << endl;
    cout << "Ficha Tecnica" << endl;
    cout << "=============" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Monedas: " << coins << endl;
    cout << "Velocidad: " << speed << endl;
    cout << "Esta Vivo?: " << personajeVivo(vida) << endl;
    cout << "Tiene llave?: " << llave << endl;
    cout << "" << endl;
}

int main(){
    string nombrePersonaje = "Aquiles Baeza";
    int vida = 500;
    int monedas = 0;
    float velocidad = 4.5f;
    bool estaVivo = true;
    bool tieneLlave = false;

    mostrarFicha(nombrePersonaje,vida,monedas,velocidad,tieneLlave);

    cout << "Atacamos a nuestro personaje con 500 de danio!" << endl;
    vida = vida - 500;

    mostrarFicha(nombrePersonaje,vida,monedas,velocidad,tieneLlave);
    return 0;
}