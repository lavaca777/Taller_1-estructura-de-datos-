#include <iostream>
#include <fstream>
#include "Evento.h"
#include "Asistente.h"
#include "GestorEvento.h"

using namespace std;

void mostrarMenu(GestorEvento gestorEventos){

    int opcion;
    do {
        cout << "Menu de opciones:" << endl;
        cout << "1) Crear evento" << endl;
        cout << "2) Registrar nueva persona" << endl;
        cout << "3) Registrar asistente" << endl;
        cout << "4) Lista de asistentes" << endl;
        cout << "5) Generar informe" << endl;
        cout << "6) Salir" << endl;
        cout << "\nIngrese la opcion > ";
        
        cin >> opcion;

        switch(opcion) {
            case 1: {
                string nombre, tipo;
                cout << "Ingrese el nombre del evento: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el tipo de evento: ";
                getline(cin, tipo);
                gestorEventos.crearEvento(nombre, tipo);
                break;
            }
            case 2:{gestorEventos.registrarPersonaNueva();}
                
            case 3:
                
                break;
            case 4:
                gestorEventos.mostrarEventos();
                break;
            case 5:
                cout << "generando informe, quedan 100 años para terminar" << endl;
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);
}

int main (){

    GestorEvento gestorEventos;
    mostrarMenu(gestorEventos);
    return 0;

}

