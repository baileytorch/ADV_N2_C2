#include <iostream>
using namespace std;

class Personaje{
    public:
        // Atributos de la clase, Cómo es la clase/objeto?
        int vida;
        bool vivo;
        int danioJugador;

        // La siguiente función se llama CONSTRUCTOR, se encargará de crear objetos de la clase PERSONAJE
        Personaje(int vidaPersonaje, bool personajeVivo, int danioPersonaje):
            vida(vidaPersonaje),vivo(personajeVivo),danioJugador(danioPersonaje){}

        // Una función VOID, no retorna nada, solo ejecuta una acción
        // Métodos de la clase, Qué puede hacer la clase/objeto?
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
};

int main(){
    int opcion = 0;
    int vida = 0;
    bool vivo = true;
    int danio = 0;

    cout << "Vamos a crear nuestro PJ!" << endl;
    cout << "Cuante vida tendrá Poo?" << endl;
    cin >> vida;

    Personaje jugador(vida,vivo,danio);

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
                jugador.avanzar();
                break;
            case 2:
                jugador.saltar();
                break;
            case 3:
                cout << "Ingrese daño del personaje: \n" << endl;
                cin >> danio;
                jugador.recibirDanio(danio);
                break;
            case 4:
                jugador.verEstado();
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