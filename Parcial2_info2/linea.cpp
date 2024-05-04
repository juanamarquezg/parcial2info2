#include "linea.h"
#include <string>
#include <estacion.h>
#include <linea.h>
using namespace std;

linea::linea(Estacion** _estaciones,string NombreLin,Estacion EstTransferencia,int MaxCapacidad)
:Estaciones(_estaciones), NombreLinea(NombreLin), EstacionTransferencia(EstTransferencia), ContadorEstaciones(0),Capacidad (MaxCapacidad) {
    Estaciones = new Estacion* [MaxCapacidad];
}


linea::~linea() {
    delete[] Estaciones;
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




