#include "linea.h"
#include <string>
#include <estacion.h>
#include <linea.h>
using namespace std;
#include <iostream>

linea::linea(Estacion** _estaciones, string NombreLin, Estacion EstTransferencia, int NumEstaciones, int MaxCapacidad)
    : Estaciones(_estaciones), NombreLinea(NombreLin), EstacionTransferencia(EstTransferencia), ContadorEstaciones(NumEstaciones), Capacidad(MaxCapacidad) {}


linea::~linea() {
    for (int i = 0; i < ContadorEstaciones; ++i) {
        delete Estaciones[i];
    }
    delete[] Estaciones;
}

void linea::mostrarLinea() const {
    cout << "Nombre de la linea: " << NombreLinea << endl;
    cout << "Estaciones:" << endl;
    for (int i = 0; i < ContadorEstaciones; ++i) {
        cout << "Nombre: " << Estaciones[i]->getNombre() << endl;
        cout << "Tiempo anterior: " << Estaciones[i]->getTiempoAnterior() << endl;
        cout << "Tiempo siguiente: " << Estaciones[i]->getTiempoSiguiente() << endl;
    }
}

void linea::agregarEstacion(const Estacion& nuevaEstacion, int indice) {
    if (ContadorEstaciones >= Capacidad) {
        int nuevaCapacidad = Capacidad * 2;
        Estacion** nuevaArray = new Estacion*[nuevaCapacidad];

        for (int i = 0; i < ContadorEstaciones; ++i) {
            nuevaArray[i] = Estaciones[i];
        }

        delete[] Estaciones;

        Estaciones = nuevaArray;
        Capacidad = nuevaCapacidad;
    }

    if (indice < 0 || indice > ContadorEstaciones) {
        cout << "Indice fuera de rango." << endl;
        return;
    }

    for (int i = ContadorEstaciones; i > indice; --i) {
        Estaciones[i] = Estaciones[i - 1];
    }

    Estaciones[indice] = new Estacion(nuevaEstacion);
    ContadorEstaciones++;
    cout << "Estacion agregada exitosamente en la posicion " << indice << "." << endl;

    if (indice > 0) {
        int tiempoAnterior;
        cout << "Ingrese el nuevo tiempo siguiente de la estacion anterior: ";
        cin >> tiempoAnterior;
        Estaciones[indice - 1]->setTiempoSiguiente(tiempoAnterior);
    }
    if (indice < ContadorEstaciones - 1) {
        int tiempoSiguiente;
        cout << "Ingrese el nuevo tiempo anterior de la estacion siguiente: ";
        cin >> tiempoSiguiente;
        Estaciones[indice + 1]->setTiempoAnterior(tiempoSiguiente);
    }
}

void linea::eliminarEstacion(const string& nombreEstacion) {
    int indice = -1;
    for (int i = 0; i < ContadorEstaciones; ++i) {
        if (Estaciones[i]->getNombre() == nombreEstacion) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        delete Estaciones[indice];
        for (int i = indice; i < ContadorEstaciones - 1; ++i) {
            Estaciones[i] = Estaciones[i + 1];
        }
        ContadorEstaciones--;
        cout << "Estacion eliminada exitosamente." << endl;

        if (indice < ContadorEstaciones) {
            int tiempoSiguiente;
            cout << "Ingrese el nuevo tiempo anterior de la siguiente estacion: ";
            cin >> tiempoSiguiente;
            Estaciones[indice]->setTiempoAnterior(tiempoSiguiente);
        }
        if (indice > 0) {
            int tiempoAnterior;
            cout << "Ingrese el nuevo tiempo siguiente de la estacion anterior: ";
            cin >> tiempoAnterior;
            Estaciones[indice - 1]->setTiempoSiguiente(tiempoAnterior);
        }
    } else {
        cout << "No se encontro la estacion con el nombre dado." << endl;
    }
}

linea linea::crearLinea() {
    int numEstaciones;
    cout << "Ingrese el numero de estaciones para la linea: ";
    cin >> numEstaciones;

    Estacion** estaciones = new Estacion*[numEstaciones];

    string nombreLinea;
    cout << "Ingrese el nombre de la linea: ";
    cin.ignore();
    getline(cin, nombreLinea);

    Estacion estacionTransferencia(0, 0, "");

    for (int i = 0; i < numEstaciones; ++i) {
        string nombreEstacion;
        int tiempoAnterior, tiempoSiguiente;
        if (i==0){
            cout << "Ingrese el nombre de la estacion " << i+1 << ": ";
            cin.ignore();
            getline(cin, nombreEstacion);

            tiempoAnterior = 0;

            cout << "Ingrese el tiempo siguiente de la estacion " << nombreEstacion << ": ";
            cin >> tiempoSiguiente;

            estaciones[i] = new Estacion(tiempoAnterior, tiempoSiguiente, nombreEstacion);

        }
        else if(i== numEstaciones -1){
            cout << "Ingrese el nombre de la estacion " << i+1 << ": ";
            cin.ignore();
            getline(cin, nombreEstacion);

            tiempoAnterior= tiempoSiguiente;

            tiempoSiguiente = 0;

            estaciones[i] = new Estacion(tiempoAnterior, tiempoSiguiente, nombreEstacion);

        }
        else{
            cout << "Ingrese el nombre de la estacion " << i+1 << ": ";
            cin.ignore();
            getline(cin, nombreEstacion);


            tiempoAnterior = tiempoSiguiente;

            cout << "Ingrese el tiempo siguiente de la estacion " << nombreEstacion << ": ";
            cin >> tiempoSiguiente;

            estaciones[i] = new Estacion(tiempoAnterior, tiempoSiguiente, nombreEstacion);
        }

    }

    linea nuevaLinea(estaciones, nombreLinea, estacionTransferencia, numEstaciones, numEstaciones);
    return nuevaLinea;
}

void linea::seleccionarEstacionTransferencia(const string& nombreEstacion) {
    for (int i = 0; i < ContadorEstaciones; ++i) {
        if (Estaciones[i]->getNombre() == nombreEstacion) {
            Estaciones[i]->setNombre(NombreLinea);
            EstacionTransferencia = *Estaciones[i];
            cout << "La estacion " << nombreEstacion << " ha sido marcada como estacion de transferencia de la linea " << NombreLinea << "." << endl;
            return;
        }
    }
    cout << "No se encontró ninguna estación con el nombre dado en la línea." << endl;
}


//int linea::getTiempoAnterior() const {
//    return tiempo_anterior;
//}

//void linea::setTiempoAnterior(int anterior) {
//    tiempo_anterior = anterior;
//}

//int Estacion::getTiempoSiguiente() const {
//    return tiempo_siguiente;
//}

//void Estacion::setTiempoSiguiente(int siguiente) {
//    tiempo_siguiente = siguiente;
//}

//string Estacion::getNombre() const {
//    return nombre;
//}

//void Estacion::setNombre(string nombre) {
//    this->nombre = nombre;
//}




