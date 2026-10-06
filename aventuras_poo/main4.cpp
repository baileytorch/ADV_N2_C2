#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

class Item
{
protected:
    string nombre;
    string descripcion;
    int durabilidad;
    string categoria;
public:
    Item(string nombreItem, string descripcionItem, int durabilidadItem, string categoriaItem):
        nombre(nombreItem), descripcion(descripcionItem), durabilidad(durabilidadItem), categoria(categoriaItem){}
    
    string obtenerNombre() {
        return nombre;
    }
};

class Personaje
{
protected:
    string nombre;
    int vida;
    bool vivo;
    vector<Item> inventario;

public:
    Personaje(string nombrePersonaje, int vidaPersonaje, bool personajeVivo) : 
        nombre(nombrePersonaje), vida(vidaPersonaje), vivo(personajeVivo) {}

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
        vida -= danio;

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

    virtual void atacar(){};

    void agregarItem(Item& item){
        inventario.push_back(item);
        cout << "El item " << item.obtenerNombre() << " ha sido agregado al inventario." << endl;
    };
};

class Guerrero : public Personaje
{
    private:
        string arma;
    public:
        Guerrero(string nombrePersonaje, int vidaPersonaje, bool personajeVivo,string nombreArma):
            Personaje(nombrePersonaje,vidaPersonaje,personajeVivo), arma(nombreArma){}
        
        void atacar() override{
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
        
        void atacar() override{
            cout << "Lanza una bola de fuego con su " << arma << endl;
        }
};

class Arquero : public Personaje
{
    private:
        string arma;
    public:
        Arquero(string nombrePersonaje, int vidaPersonaje, bool personajeVivo,string nombreArma):
            Personaje(nombrePersonaje,vidaPersonaje,personajeVivo), arma(nombreArma){}
        
        void atacar() override{
            cout << "Dispara desde una gran distancia con su " << arma << endl;
        }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int opcion = 0;
    int tipoPersonaje = 0;
    int vida = 0;
    bool vivo = true;
    int danio = 0;
    string nombre = "";
    Personaje* jugador = nullptr;

    cout << "Vamos a crear nuestro PJ!" << endl;
    cout << "Nombre del personaje:" << endl;
    getline(cin, nombre);

    cout << "Cuanta vida tendrá " << nombre << "?" << endl;
    cin >> vida;

    cout << "Qué tipo de personaje será?..." << endl;
    cout << "[1] Guerrrero." << endl;
    cout << "[2] Mago." << endl;
    cout << "[3] Arquero." << endl;
    cin >> tipoPersonaje;

    switch(tipoPersonaje){
        case 1:
            jugador = new Guerrero(nombre,vida,vivo,"Espada de Colmillo de Basilisco!!");
            cout << nombre << " ahora es un Guerrero!" << endl;
            break;
        case 2:
            jugador = new Mago(nombre,vida,vivo,"Báculo del Poder Ilimitado!!");
            cout << nombre << " ahora es un Mago!" << endl;
            break;
        case 3:
            jugador = new Arquero(nombre,vida,vivo,"Arco de las Mil Flamas Demoniacas!!");
            cout << nombre << " ahora es un Arquero!" << endl;
            break;
    }

    while (opcion != 6 && vivo)
    {
        cout << "\nAventuras de "<< nombre << "\nSeleccione una opción [1-5]" << endl;
        cout << "[1] Avanzar." << endl;
        cout << "[2] Saltar." << endl;
        cout << "[3] Recibir Daño." << endl;
        cout << "[4] Ver Estado Personaje." << endl;
        cout << "[5] Atacar." << endl;
        cout << "[6] Salir." << endl;
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
            jugador->atacar();
            break;
        case 6:
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