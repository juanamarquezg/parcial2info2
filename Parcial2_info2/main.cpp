#include <iostream>
using namespace std;
#include <string>
#include <funciones.h>
#include <estacion.h>
#include "linea.h"
// int main() {
//     MenuPrincipal();
//     return 0;
// }
int main() {
    linea miLinea = miLinea.crearLinea();

    miLinea.mostrarLinea();

//    bool salir = false;
//    while (!salir) {
//        int opcion;
//        cout << "\nSeleccione una accion:" << endl;
//        cout << "1. Agregar una estacion" << endl;
//        cout << "2. Eliminar una estacion" << endl;
//        cout << "3. Salir del programa" << endl;
//        cin >> opcion;

//        string nombreEstacion;
//        int tiempoAnterior, tiempoSiguiente;
//        Estacion nuevaEstacion(0, 0, "");

//        switch (opcion) {
//        case 1: {
//            cout << "Ingrese el nombre de la nueva estacion: ";
//            cin.ignore();
//            getline(cin, nombreEstacion);
//            cout << "Ingrese el tiempo anterior de la estacion " << nombreEstacion << ": ";
//            cin >> tiempoAnterior;
//            cout << "Ingrese el tiempo siguiente de la estacion " << nombreEstacion << ": ";
//            cin >> tiempoSiguiente;

//            nuevaEstacion = Estacion(tiempoAnterior, tiempoSiguiente, nombreEstacion);

//            int posicion;
//            cout << "Ingrese la posicion donde desea agregar la estacion: ";
//            cin >> posicion;
//            posicion--;

//            miLinea.agregarEstacion(nuevaEstacion, posicion);
//            break;
//        }
//        case 2: {
//            cout << "Ingrese el nombre de la estacion que desea eliminar: ";
//            cin >> nombreEstacion;

//            miLinea.eliminarEstacion(nombreEstacion);
//            break;
//        }
//        case 3: {
//            salir = true;
//            break;
//        }
//        default:
//            cout << "Por favor, seleccione una opcion valida." << endl;
//            break;
//        }

//        miLinea.mostrarLinea();
//    }

    return 0;
}
