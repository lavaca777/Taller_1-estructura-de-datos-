#include <iostream>
#include "Evento.h"
#include "Asistente.h"
#include "GestorEvento.h"


using namespace std;

void mostrarMenu(GestorEvento* gestorEventos){

    int opcion;
    do {
        cout << "\nMenu de opciones:" << endl;
        cout << "1) Crear evento" << endl;
        cout << "2) Registrar asistente" << endl;
        cout << "3) Lista de asistentes" << endl;
        cout << "4) Generar informe" << endl;
        cout << "5) Salir" << endl;
        cout << "\nIngrese la opcion > ";
        
        cin >> opcion;

        switch(opcion) {
            case 1: gestorEventos->crearEvento();
                break;
                
            case 2: gestorEventos->registrarAsistente();
                break;
                
            case 3:
                gestorEventos->mostrarListaAsistentes();
                break;
                
            case 4:
                cout << "Generando informe, esto puede llevar un tiempo..." << endl;
                break;
                
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
                
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
}

int main (){
    
    GestorEvento* gestorEventos= new GestorEvento;

    gestorEventos->cargarEventosDesdeArchivo("Eventos.txt");
    gestorEventos->cargarAsistentesDesdeArchivo("Asistentes.txt");
    
    mostrarMenu(gestorEventos);
    return 0;

}

