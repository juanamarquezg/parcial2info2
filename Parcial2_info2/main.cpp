#include <iostream>
using namespace std;
#include <string>
#include "estacion.h"



int main() {
    int tiempo_anterior, tiempo_siguiente;
    string nombre_estacion;

    cout << "Ingrese el tiempo hacia la estacion anterior: ";
    cin >> tiempo_anterior;

    cout << "Ingrese el tiempo hacia la estacion siguiente: ";
    cin >> tiempo_siguiente;

    cout << "Ingrese el nombre de la estacion: ";
    cin.ignore();
    getline(cin, nombre_estacion);

    Estacion estacion(tiempo_anterior, tiempo_siguiente, nombre_estacion);

    cout << "Nombre de la estacion: " << estacion.getNombre() << endl;
    cout << "Tiempo anterior: " << estacion.getTiempoAnterior() << endl;
    cout << "Tiempo siguiente: " << estacion.getTiempoSiguiente() << endl;

    return 0;
}
