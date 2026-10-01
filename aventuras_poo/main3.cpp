#include <iostream>
using namespace std;

class Personaje
{
protected:
    // Atributos de la clase, Cómo es la clase/objeto?
    string nombre;
    int vida;
    bool vivo;

public:
    // La siguiente función se llama CONSTRUCTOR, se encargará de crear objetos de la clase PERSONAJE
    Personaje(string nombrePersonaje, int vidaPersonaje, bool personajeVivo) : 
        nombre(nombrePersonaje), vida(vidaPersonaje), vivo(personajeVivo) {}

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

class Guerrero : public Personaje
{
    private:
        string arma;
    public:
        Guerrero(string nombrePersonaje, int vidaPersonaje, bool personajeVivo,string nombreArma):
            Personaje(nombrePersonaje,vidaPersonaje,personajeVivo), arma(nombreArma){}
        
        void atacar(){
            cout << "Ataca con " << arma << endl;
        }
};

class Mago : public Personaje
{
    private:
        string arma;
    public:
        Mago(string nombrePersonaje, int vidaPersonaje, bool personajeVivo,string nombreArma):
            Personaje(nombrePersonaje,vidaPersonaje,personajeVivo), arma(nombreArma){}
        
        void atacar(){
            cout << "Ataca con " << arma << endl;
        }
};

class Arquero : public Personaje
{
    private:
        string arma;
    public:
        Arquero(string nombrePersonaje, int vidaPersonaje, bool personajeVivo,string nombreArma):
            Personaje(nombrePersonaje,vidaPersonaje,personajeVivo), arma(nombreArma){}
        
        void atacar(){
            cout << "Ataca con " << arma << endl;
        }
};

int main()
{
    int opcion = 0;
    int tipoPersonaje = 0;
    int vida = 0;
    bool vivo = true;
    int danio = 0;
    string nombre = "";
    Personaje* jugador = nullptr;

    cout << "Vamos a crear nuestro PJ!" << endl;
    cout << "Nombre del personaje:" << endl;
    cin >> nombre;

    cout << "Cuanta vida tendrá " << nombre << "?" << endl;
    cin >> vida;

    cout << "Qué tipo de personaje será?..." << endl;
    cout << "[1] Guerrrero." << endl;
    cout << "[2] Mago." << endl;
    cout << "[3] Arquero." << endl;
    cin >> tipoPersonaje;

    switch(tipoPersonaje){
        case 1:
            jugador = new Guerrero(nombre,vida,vivo,"Espada");
        case 2:
            jugador = new Mago(nombre,vida,vivo,"Báculo");
        case 3:
            jugador = new Arquero(nombre,vida,vivo,"Arco de las Mil Flamas Demoniacas!!");
    }

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
            jugador->avanzar(nombre);
            break;
        case 2:
            jugador->saltar(nombre);
            break;
        case 3:
            cout << "Ingrese daño del personaje: \n"
                 << endl;
            cin >> danio;
            jugador->recibirDanio(nombre, danio);
            break;
        case 4:
            jugador->verEstado(nombre);
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