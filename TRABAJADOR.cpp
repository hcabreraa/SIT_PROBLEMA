#include <iostream>
using namespace std;

class Trabajador : public PYME { 
    private:
        int edad;
        string puesto;
        float sueldo;
    public:
        string nombreTrabajador;
        buildTrabajador();
        printTrabajador();
}; 

Trabajador::buildTrabajador(){
    cout << "Ingresa el nombre del Trabajador: " << endl;
    cin >> nombreTrabajador; 
    cout << "Ingresa la edad del Trabajador: " << endl;
    cin >> edad; 
    cout << "Ingresa el puesto del Trabajador: " << endl;
    cin >> puesto; 
    cout << "Ingresa el sueldo del Trabajador: " << endl;
    cin >> sueldo; 

    search_break = 0;
    while (search_break == 0) {
        gotoxy(0,17); cout << "Ingresa el nombre de la PYME relacionada con el Trabajador: ";
        cin >> search;
        int i = verpyme();
        if (i >= 0){
            nombrePYME = pyme_arr[i].nombrePYME;
            razonSocialPYME = pyme_arr[i].razonSocialPYME;
            direccionPYME = pyme_arr[i].direccionPYME;
            search_break = 1;
        }
        else {
            gotoxy(0,19);cout << "PYME no encontrada. Presione una tecla para continuar.";
        }
    }
    gotoxy(0,19); cout << "Trabajador agregado con exito! Presiona una tecla para continuar.";
}

Trabajador::printTrabajador(){
    cout << "Nombre del Trabajador: " << nombreTrabajador << endl; 
    cout << "Edad del Trabajador: " << edad << endl; 
    cout << "Puesto del Trabajador: " << puesto << endl; 
    cout << "Sueldo del Trabajador: " << sueldo << endl; 
    cout << "Nombre de la empresa donde trabaja: " << nombrePYME << endl;
    cout << "Razon social de donde trabaja: " << razonSocialPYME << endl;
    cout << "Direccion de donde trabaja: " << direccionPYME << endl;
}
