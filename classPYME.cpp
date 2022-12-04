#include <iostream>
using namespace std;

class PYME{
    private:
        string nombreDirector;
        int numeroTrabajadores;
        float gananciaAnual;

    public:
        string nombrePYME;
        string razonSocialPYME;
        string direccionPYME;
        buildPYME();
        printPYME();
};

PYME::buildPYME(){
    cout << "Ingresa el nombre de la PYME: " << endl;
    cin >> nombrePYME; 
    cout << "Ingresa la razon social de la PYME: " << endl;
    cin >> razonSocialPYME; 
    cout << "Ingresa la direccion de la PYME: " << endl;
    cin >> direccionPYME; 
    cout << "Ingresa el nombre del director de la PYME " << endl;
    cin >> nombreDirector; 
    cout << "Ingresa el numero de trabajadores de la PYME: " << endl;
    cin >> numeroTrabajadores; 
    cout << "Ingresa la ganancia anual de la PYME: " << endl;
    cin >> gananciaAnual;
    cout << "PYME agregada exitosamente! Presiona una tecla para continuar.";
}

PYME::printPYME(){
    cout << "Nombre de la PYME: " << nombrePYME << endl; 
    cout << "Razon social de la PYME: " << razonSocialPYME << endl;
    cout << "Direccion de la PYME: " << direccionPYME << endl; 
    cout << "Director de la PYME: " << nombreDirector << endl; 
    cout << "Numero de trabajadores de la PYME: " << numeroTrabajadores << endl; 
    cout << "Ganancia anual de la PYME: " << gananciaAnual << endl;
}
