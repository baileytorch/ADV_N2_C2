#include <iostream>
using namespace std;

class Personaje
{
private:
    // Atributos de la clase, Cómo es la clase/objeto?
    string nombre;
    int vida;
    bool vivo;
    int danioJugador;

public:
    // La siguiente función se llama CONSTRUCTOR, se encargará de crear objetos de la clase PERSONAJE
    Personaje(string nombrePersonaje, int vidaPersonaje, bool personajeVivo, int danioPersonaje) : 
    nombre(nombrePersonaje), vida(vidaPersonaje), vivo(personajeVivo), danioJugador(danioPersonaje) {}

    // Una función VOID, no retorna nada, solo ejecuta una acción
    // Métodos de la clase, Qué puede hacer la clase/objeto?
    void avanzar(string nombrePersonaje)
    {
        cout << nombrePersonaje << " avanza..." << endl;
    }

    void saltar(string nombrePersonaje)
    {
        cout << nombrePersonaje << " salta!" << endl;
    }

    void recibirDanio(string nombrePersonaje, int danio)
    {
        // vida = vida - danio;
        vida -= danio;

        // if (vida < 0) {
        //     vida = 0;
        // }
        if (vida < 0)
            vida = 0;

        cout << nombrePersonaje << " recibe " << danio << " de daño." << endl;
        cout << nombrePersonaje << " tiene " << vida << " de vida restante." << endl;

        if (vida == 0)
        {
            vivo = false;
            cout << "Game Over!!" << endl;
        }
    }

    void verEstado(string nombrePersonaje)
    {
        cout << "Estado de " << nombrePersonaje << endl;
        cout << "Vida: " << vida << endl;
        cout << "Está vivo " << nombrePersonaje << "?" << (vivo ? "Si" : "No") << endl;
    }
};

int main()
{
    int opcion = 0;
    int vida = 0;
    bool vivo = true;
    int danio = 0;
    string nombre = "";

    cout << "Vamos a crear nuestro PJ!" << endl;
    cout << "Nombre del personaje:" << endl;
    cin >> nombre;

    cout << "Cuanta vida tendrá " << nombre << "?" << endl;
    cin >> vida;

    Personaje jugador(nombre, vida, vivo, danio);

    while (opcion != 5 && vivo)
    {
        cout << "Aventuras de "<< nombre << "\nSeleccione una opción [1-5]" << endl;
        cout << "[1] Avanzar." << endl;
        cout << "[2] Saltar." << endl;
        cout << "[3] Recibir Daño." << endl;
        cout << "[4] Ver Estado Personaje." << endl;
        cout << "[5] Salir." << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            jugador.avanzar(nombre);
            break;
        case 2:
            jugador.saltar(nombre);
            break;
        case 3:
            cout << "Ingrese daño del personaje: \n"
                 << endl;
            cin >> danio;
            jugador.recibirDanio(nombre, danio);
            break;
        case 4:
            jugador.verEstado(nombre);
            break;
        case 5:
            cout << "Apagando motores..." << endl;
            break;
        default:
            cout << "Opción inválida, intente nuevamente..." << endl;
            opcion = 0;
            break;
        }
    }

    return 0;
}