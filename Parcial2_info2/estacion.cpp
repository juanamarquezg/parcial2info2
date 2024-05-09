#include "estacion.h"
#include <string>
#include <globals.h>
using namespace std;

Estacion:: Estacion() : tiempo_anterior(0), tiempo_siguiente(0),nombre("desconocido"), transferencia (NULL) {}
Estacion::Estacion(int anterior, int siguiente, string _nombre, bool esttransferencia)
    : tiempo_anterior(anterior), tiempo_siguiente(siguiente), nombre(_nombre), transferencia(esttransferencia) {}


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
bool Estacion::getTransferencia() const {
    return transferencia;
}
void Estacion::setTransferencia(bool esttransferencia){
    transferencia = esttransferencia;
}
