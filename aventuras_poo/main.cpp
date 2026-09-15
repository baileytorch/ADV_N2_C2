#include <iostream>
using namespace std;

int vida = 100;
bool vivo = true;

// Una función VOID, no retorna nada, solo ejecuta una acción
void avanzar(){
    cout << "Poo avanza..." << endl;
}

void saltar(){
    cout << "Poo salta!" << endl;
}

void recibirDanio(int danio){
    // vida = vida - danio;
    vida -= danio;

    // if (vida < 0) {
    //     vida = 0;
    // }
    if (vida < 0) vida = 0;

    cout << "Poo recibe " << danio << " de daño." << endl;
    cout << "Poo tiene " << vida << " de vida restante." << endl;

    if (vida == 0){
        vivo = false;
        cout << "Game Over!!" << endl;
    }
}

void verEstado(){
    cout << "Estado de Poo" << endl;
    cout << "Vida: " << vida << endl;
    cout << "Está vivo? " << (vivo ? "Si": "No") << endl;
}

int main(){
    int opcion = 0;

    while (opcion != 5 && vivo )
    {
        cout << "Aventuras de Poo\nSeleccione una opción [1-5]" << endl;
        cout << "[1] Avanzar." << endl;
        cout << "[2] Saltar." << endl;
        cout << "[3] Recibir Daño." << endl;
        cout << "[4] Ver Estado Personaje." << endl;
        cout << "[5] Salir." << endl;
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                avanzar();
                break;
            case 2:
                saltar();
                break;
            case 3:
                int danioJugador = 0;
                cout << "Ingrese daño del personaje: \n" << endl;
                cin >> danioJugador;
                recibirDanio(danioJugador);
                break;
            case 4:
                verEstado();
                break;
            case 5:
                cout << "Apagando motores..." << endl;
                break;            
            default:
                cout << "Opción inválida, intente nuevamente..." << endl;
                break;
        }
    }

    return 0;
}