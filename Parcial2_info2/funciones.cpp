#include <iostream>
using namespace std;
#include <string>
#include <funciones.h>
#include <estacion.h>
#include <linea.h>
#include <globals.h>

void cambiarVariableGlobal(int nuevoValor) {
    variableGlobal = nuevoValor;
}
void cambiarContadorGlobal(int nuevoValor) {
    contadorGlobal = nuevoValor;
}
bool buscarEstacionEnLinea(const linea& unaLinea, const string& nombreEstacion) {
    Estacion** estaciones = unaLinea.getEstaciones();
    int numEstaciones = unaLinea.getContadorEstaciones();

    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i]->getNombre() == nombreEstacion) {
            return true;
        }
    }

    cout << "La estacion " << nombreEstacion << " no pertenece a la linea " << unaLinea.getNombreLinea() << "." << endl;
    return false;
}
void MenuPrincipal (){
    linea miLinea;
    miLinea = miLinea.crearLinea();
    // delcaracion de arreglos
    linea Arreglo[100];
    int numLineas = 1; // Contador para el número actual de líneas en el arreglo
    Arreglo[0] = miLinea;
    Arreglo[0].mostrarLinea();


    int decision;
    bool flag = false;
    while (!flag){
        cout << "Elija la opcion que quiere desarrollar:"<<endl;
        cout << "1: Agregar una linea"<< endl;
        cout << "2: eliminar una linea"<< endl;
        cout << "3: Agregar estaciones a una linea"<<endl;
        cout << "4: eliminar estaciones de una linea"<<endl;
        cout << "5: saber cuantas estaciones tiene la red metro"<<endl;
        cout << "6: saber cuantas lineas tiene la red metro"<<endl;
        cout << "7: averiguar si una estacion pertenece a una linea"<<endl;
        cout << "8: saber cuantas estaciones tiene una linea"<<endl;
        cout << "9: para calcular el tiempo entre estaciones" << endl;
        cout << "10: para mostrar todas las lineas" <<endl;
        cout << "11: para salirse"<<endl;
        cin >> decision ;

        switch(decision){
        case 1: {

            linea nuevaLinea = miLinea.crearLinea();
            int k ;

            // Mostrar las líneas existentes y sus estaciones
            cout << "Lineas existentes y sus estaciones:" << endl;
            for (int j = 0; j < numLineas; j++) {
                cout << "Linea " << j + 1 << ":" << endl;
                Arreglo[j].mostrarLinea();
            }

            // El usuario elige una línea existente para seleccionar una estación como estación de transferencia
            int seleccionLineaTransferencia;
            cout << "Seleccione la linea de la cual desea seleccionar una estacion como estacion de transferencia (1-" << numLineas << "): ";
            cin >> seleccionLineaTransferencia;

            if (seleccionLineaTransferencia >= 1 && seleccionLineaTransferencia <= numLineas) {
            string estacionTransferencia;
            cout << "Ingrese el nombre de la estacion que desea agregar como primera estacion de la nueva linea: ";
            cin.ignore();
            getline(cin, estacionTransferencia);

            // Verificar si la estación seleccionada existe en la línea seleccionada
            bool encontrada = false;
            for (int i = 0; i < Arreglo[seleccionLineaTransferencia - 1].getContadorEstaciones(); ++i) {
                if (Arreglo[seleccionLineaTransferencia - 1].getEstaciones()[i]->getNombre() == estacionTransferencia) {
                    encontrada = true;
                    k = i ;
               break;
            }
            }

            if (encontrada) {
            // Agregar la estación seleccionada como primera estación en la nueva línea
            nuevaLinea.agregarEstacion(*Arreglo[seleccionLineaTransferencia - 1].getEstaciones()[k], 0);

            cout << "Estacion agregada como primera estacion de la nueva linea." << endl;
            } else {
            cout << "La estacion seleccionada no existe en la linea seleccionada." << endl;
            }
            } else {
            cout << "Numero de linea no valido." << endl;
            }

            // Agregar la nueva línea al arreglo de líneas
            Arreglo[numLineas] = nuevaLinea;

            // Incrementar el contador de líneas
            numLineas++;

            // Mostrar la nueva línea
            cout << "Nueva linea agregada:" << endl;
            nuevaLinea.mostrarLinea();
            }
        break;
        case 2: { // Opción para eliminar una línea
            if (numLineas == 1) {
                cout << "La linea " << Arreglo[0].getNombreLinea() << " ha sido eliminada." << endl;
                numLineas = 0; // Establecer el contador de líneas en cero
                cambiarContadorGlobal(0);
                break; // Salir del bucle principal
            } else {
                cout << "No se puede eliminar mas lineas. Debe haber al menos una linea en la red de metro." << endl;
            }
        }
        break;
        case 4: {
        // Eliminar una estación de una línea existente
        cambiarContadorGlobal(contadorGlobal -1);
        if (numLineas == 0) {
            cout << "No hay lineas disponibles para eliminar una estacion." << endl;
        } else {
            for (int j = 0; j < numLineas; j++) {
                cout << "Linea " << j + 1 << ":" << endl;
                Arreglo[j].mostrarLinea();
            }
            int seleccionLinea;
            cout << "Seleccione la linea de la cual desea eliminar una estacion (1-" << numLineas << "): ";
            cin >> seleccionLinea;


            if (seleccionLinea >= 1 && seleccionLinea <= numLineas) {

                string nombreEstacion;
                cout << "Ingrese el nombre de la estacion que desea eliminar: ";
                cin.ignore();
                getline(cin, nombreEstacion);

                Arreglo[seleccionLinea - 1].eliminarEstacion(nombreEstacion);
            } else {
                cout << "Numero de linea no valido." << endl;
                }
            }
        }
        break;

        case 3: {
        // Agregar una estación a una línea existente

            if (numLineas == 0) {
                cout << "No hay lineas disponibles para agregar una estacion." << endl;
            }
            else {
                int seleccionLinea;
                cout << "Seleccione la linea a la cual desea agregar una estacion (1-" << numLineas << "): ";
                cin >> seleccionLinea;

                    if (seleccionLinea >= 1 && seleccionLinea <= numLineas) {
                        Estacion nuevaEstacion;
                        int tiempoAnterior,tiempoSiguiente;
                        string nombreEstacion;
                        cout << "Ingrese el nombre de la nueva estacion: ";
                        cin.ignore();
                        getline(cin, nombreEstacion);
                        cout << "Ingrese el tiempo anterior de la estacion " << nombreEstacion << ": ";
                        cin >> tiempoAnterior;
                        cout << "Ingrese el tiempo siguiente de la estacion " << nombreEstacion << ": ";
                        cin >> tiempoSiguiente;
                        nuevaEstacion = Estacion(tiempoAnterior, tiempoSiguiente, nombreEstacion, false);
                        Arreglo[seleccionLinea-1].mostrarLinea();

                        int posicion;
                        cout << "Ingrese la posicion donde desea agregar la estacion: ";
                        cin >> posicion;
                        posicion--;

                        // Aquí podrías solicitar al usuario los detalles de la nueva estación
                        // Luego llamar a la función agregarEstacion
                        Arreglo[seleccionLinea - 1].agregarEstacion(nuevaEstacion,posicion);
                        cambiarContadorGlobal(contadorGlobal+1);
                    }
                    else {
                    cout << "Numero de linea no valido." << endl;
                    }
                }
            }

        break;


        case 5:{
            cout << endl << "El numero de estaciones en la red metro es:"<< contadorGlobal << endl ;

        }
        break;
        case 6:{
            cout << endl << "El numero de lineas en la red metro es:"<< numLineas << endl ;
        }
        break;
        case 7: { // Opción para averiguar si una estación pertenece a una línea
            string nombreEstacion;
            cout << "Ingrese el nombre de la estacion que desea buscar: ";
            cin.ignore();
            getline(cin, nombreEstacion);

            bool encontrada = false;
            for (int i = 0; i < numLineas; ++i) {
                if (buscarEstacionEnLinea(Arreglo[i], nombreEstacion)) {
                    encontrada = true;
                    cout << "La estacion " << nombreEstacion << " pertenece a la linea " << i+1 << "." << endl;
                }
            }
            if (!encontrada) {
                cout << "La estacion " << nombreEstacion << " no pertenece a ninguna linea." << endl;
            }
        }
        break;

        case 8: { // Opción para saber cuántas estaciones tiene una línea
                if (numLineas == 0) {
                    cout << "No hay lineas disponibles para mostrar." << endl;
                } else {
                    int seleccionLinea;
                    cout << "Seleccione la linea para saber cuantas estaciones tiene (1-" << numLineas << "): ";
                    cin >> seleccionLinea;

                    if (seleccionLinea >= 1 && seleccionLinea <= numLineas) {
                        cout << "La linea " << seleccionLinea << " tiene " << Arreglo[seleccionLinea - 1].getContadorEstaciones() << " estaciones." << endl;
                    } else {
                        cout << "Numero de linea no valido." << endl;
                    }
                }
            }
        break;

        case 9: {
            if (numLineas == 0) {
                cout << "No hay lineas disponibles para calcular el tiempo entre estaciones." << endl;
            } else {
                int seleccionLinea;
                cout << "Seleccione la línea para calcular el tiempo entre estaciones (1-" << numLineas << "): ";
                cin >> seleccionLinea;

                if (seleccionLinea >= 1 && seleccionLinea <= numLineas) {
                    string estacionInicio, estacionFin;
                    cout << "Ingrese el nombre de la estacion de inicio: ";
                    cin.ignore();
                    getline(cin, estacionInicio);
                    cout << "Ingrese el nombre de la estacion de fin: ";
                    getline(cin, estacionFin);

                    // Calcular tiempo entre estaciones utilizando la línea seleccionada
                    int tiempo = Arreglo[seleccionLinea - 1].calcularTiempoEntreEstaciones(estacionInicio, estacionFin);
                    if (tiempo != -1) {
                        cout << "El tiempo entre " << estacionInicio << " y " << estacionFin << " en la linea " << seleccionLinea << " es: " << tiempo << " segundos." << endl;
                    }
                } else {
                    cout << "Numero de linea no valido." << endl;
                }
            }
        }
        break;

        case 10: { // Opción para mostrar todas las líneas
            cout << "Mostrando todas las lineas guardadas:" << endl;
            for (int i = 0; i < numLineas; ++i) {
                cout << "Linea " << i+1 << ":" << endl;
                Arreglo[i].mostrarLinea();
            }
        }
        break;

        case 11:
            flag = true;
            break;

        default:
            cout << "Opcion no valida. Intentalo de nuevo." << endl;
            break;
        }
    }
}
