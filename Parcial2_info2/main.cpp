#include <iostream>
using namespace std;
#include <string>
#include <funciones.h>
#include <estacion.h>
#include <linea.h>
#include <globals.h>
// int main() {
//     MenuPrincipal();
//     return 0;
// }

void cambiarVariableGlobal(int nuevoValor) {
    variableGlobal = nuevoValor;
}
int main() {
    bool salir = false;
    linea miLinea = miLinea.crearLinea();
    miLinea.mostrarLinea();

    cambiarVariableGlobal(1);

    // Declaracion del arreglo lineas
//    linea Arreglo[variableGlobal + 1];
//    Arreglo[0] = miLinea;
//    Arreglo[0].mostrarLinea();
//    linea***arregloLineas[variableGlobal+1];

//    arregloLineas[variableGlobal]= miLinea;

    while (!salir) {
        int opcion;
        cout << "\nSeleccione una accion:" << endl;
        cout << "1. Agregar una estacion" << endl;
        cout << "2. Eliminar una estacion" << endl;
        cout << "3. Salir del programa" << endl;
        cin >> opcion;

        string nombreEstacion;
        int tiempoAnterior, tiempoSiguiente;
        Estacion nuevaEstacion(0, 0, "",false);
        switch (opcion) {
        case 1: {
            cout << "Ingrese el nombre de la nueva estacion: ";
            cin.ignore();
            getline(cin, nombreEstacion);
            cout << "Ingrese el tiempo anterior de la estacion " << nombreEstacion << ": ";
            cin >> tiempoAnterior;
            cout << "Ingrese el tiempo siguiente de la estacion " << nombreEstacion << ": ";
            cin >> tiempoSiguiente;

            nuevaEstacion = Estacion(tiempoAnterior, tiempoSiguiente, nombreEstacion,false);

            int posicion;
            cout << "Ingrese la posicion donde desea agregar la estacion: ";
            cin >> posicion;
            posicion--;

            miLinea.agregarEstacion(nuevaEstacion, posicion);
           break;
        }
        case 2: {
           cout << "Ingrese el nombre de la estacion que desea eliminar: ";
            cin >> nombreEstacion;

           miLinea.eliminarEstacion(nombreEstacion);
           break;
        }
       case 3: {
           salir = true;
            break;
        }
       default:
           cout << "Por favor, seleccione una opcion valida." << endl;
            break;
       }

        miLinea.mostrarLinea();
   }

    return 0;
}
