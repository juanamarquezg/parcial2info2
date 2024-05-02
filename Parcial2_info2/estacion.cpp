#include "estacion.h"
#include <string>
using namespace std;


Estacion::Estacion(int anterior, int siguiente, string nombre)
    : tiempo_anterior(anterior), tiempo_siguiente(siguiente), nombre(nombre) {}


Estacion::~Estacion() {}

int Estacion::getTiempoAnterior() const {
    return tiempo_anterior;
}

void Estacion::setTiempoAnterior(int anterior) {
    tiempo_anterior = anterior;
}

int Estacion::getTiempoSiguiente() const {
    return tiempo_siguiente;
}

void Estacion::setTiempoSiguiente(int siguiente) {
    tiempo_siguiente = siguiente;
}

string Estacion::getNombre() const {
    return nombre;
}

void Estacion::setNombre(string nombre) {
    this->nombre = nombre;
}
