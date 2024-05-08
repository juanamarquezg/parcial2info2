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
void MenuPrincipal (){
//    cout << "Elija la opcion que quiere desarrollar:"<<endl<<"1: Agregar una linea"<< endl <<"2: eliminar una linea"<< endl<<"3: Agregar estaciones a una linea"<<endl<<"4: eliminar estaciones de una linea"<<endl<<"5: saber cuantas estaciones tiene la red metro"<<endl<<"6: saber cuantas lineas tiene la red metro"<<endl<<"7: averiguar si una estación pertenece a una linea"<<endl<<"8: saber cuantas estaciones tiene una linea"<<endl<<"9: para salirse"<<endl;SSS
    linea miLinea;
    miLinea = miLinea.crearLinea();
    // delcaracion de arreglos
    linea Arreglo[variableGlobal + 1];
    Arreglo[0] = miLinea;
    Arreglo[0].mostrarLinea();

    // Declaracion del arreglo lineas
//    linea **ArregloLineas = new linea*[variableGlobal];
//    ArregloLineas[0]= new linea(miLinea.crearLinea(nullptr));
//    ArregloLineas[0]->mostrarLinea();
    cambiarVariableGlobal(1);
    int decision,actualizador;
    actualizador = 1;
//    cout << "Elija la opcion que quiere desarrollar:"<<endl<<"1: Agregar una linea"<< endl <<"2: eliminar una linea"<< endl<<"3: Agregar estaciones a una linea"<<endl<<"4: eliminar estaciones de una linea"<<endl<<"5: saber cuantas estaciones tiene la red metro"<<endl<<"6: saber cuantas lineas tiene la red metro"<<endl<<"7: averiguar si una estación pertenece a una linea"<<endl<<"8: saber cuantas estaciones tiene una linea"<<endl<<"9: para salirse"<<endl;
//    cin >> decision ;
    bool flag = false; ;
    while (flag == false){
        cout << "Elija la opcion que quiere desarrollar:"<<endl<<"1: Agregar una linea"<< endl <<"2: eliminar una linea"<< endl<<"3: Agregar estaciones a una linea"<<endl<<"4: eliminar estaciones de una linea"<<endl<<"5: saber cuantas estaciones tiene la red metro"<<endl<<"6: saber cuantas lineas tiene la red metro"<<endl<<"7: averiguar si una estación pertenece a una linea"<<endl<<"8: saber cuantas estaciones tiene una linea"<<endl<<"9: para salirse"<<endl;
        cin >> decision ;
        switch(decision){
            case 1:/*{*/
//                linea Temporal1;
//                linea **ArregloLineasTemporal = new linea*[variableGlobal+1];
//                Temporal1 = Temporal1.crearLinea(ArregloLineasTemporal);
//                for (int i=0 ; i < variableGlobal+1; i++){
//                    ArregloLineasTemporal[i] = ArregloLineas[1];
//                }
//                ArregloLineasTemporal[variableGlobal]= new linea(Temporal1.crearLinea(ArregloLineas));
//                for (int i=0 ; i < variableGlobal+1; i++){
//                    delete ArregloLineas[1];
//                }
//            }

            break;

            case 2:


            break;
            case 3:

            break;

            case 4:

            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            break;

            case 8:
            break;

            case 9:
            flag = true;
            break;

            default:
            cout << endl << "ingreso un valor incorrecto " <<endl ;

        }


    }
}
    // borrado de memoria
//    for(int i=0;i<variableGlobal;i++){
//        delete ArregloLineas[i];
//    }
//    delete [] ArregloLineas;
//}
//     bool verificador, flag = false;
//     int decision ;
//     while (flag == false){
//         cout << "Elija la opcion que quiere desarrollar:"<<endl<<"1: Agregar una linea"<< endl <<"2: eliminar una linea"<< endl<<"3: Agregar estaciones a una linea"<<endl<<"4: eliminar estaciones de una linea"<<endl<<"5: saber cuantas estaciones tiene la red metro"<<endl<<"6: saber cuantas lineas tiene la red metro"<<endl<<"7: averiguar si una estación pertenece a una linea"<<endl<<"8: saber cuantas estaciones tiene una linea"<<endl<<"9: para salirse"<<endl;
//         cin >> decision ;
//         switch(decision){
//             case 1:
//             // agregar linea tiene consigo la funcion de agregar estaciones, en caso de ser primera linea
//             // no tiene estacion de transferencia

//             break;
//             case 2:

//             break;
//             case 3:

//             break;

//             case 4:

//             break;

//             case 5:
//             break;

//             case 6:
//             break;

//             case 7:
//             break;

//             case 8:
//             break;

//             case 9:
//             flag = true;
//             break;

//         default:
//             cout << endl << "ingreso un valor incorrecto " <<endl ;

//         }

//     int tiempo_anterior, tiempo_siguiente;
//     string nombre_estacion;

//     cout << "Ingrese el tiempo hacia la estacion anterior: ";
//     cin >> tiempo_anterior;

//     cout << "Ingrese el tiempo hacia la estacion siguiente: ";
//     cin >> tiempo_siguiente;

//     cout << "Ingrese el nombre de la estacion: ";
//     cin.ignore();
//     getline(cin, nombre_estacion);

//     Estacion estacion(tiempo_anterior, tiempo_siguiente, nombre_estacion);

//     cout << "Nombre de la estacion: " << estacion.getNombre() << endl;
//     cout << "Tiempo anterior: " << estacion.getTiempoAnterior() << endl;
//     cout << "Tiempo siguiente: " << estacion.getTiempoSiguiente() << endl;
//     }

// }
