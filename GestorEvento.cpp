#include <iostream>
#include "GestorEvento.h"

using namespace std;

GestorEvento::GestorEvento(){}

GestorEvento::~GestorEvento(){}

void GestorEvento::crearEvento() {
    
    string nombre, fecha, lugar, duracion, tipo;
    int costo, capMax;

    cout << "\nIngrese el nombre del evento: ";
    cin.ignore(); // Ignora el carácter de nueva línea pendiente
    getline(cin, nombre);

    cout << "Ingrese el tipo de evento: ";
    getline(cin, tipo);

    cout << "Ingrese la fecha del evento: ";
    getline(cin, fecha);

    cout << "Ingrese el lugar del evento: ";
    getline(cin, lugar);

    cout << "Ingrese la duración del evento: ";
    getline(cin, duracion);

    cout << "Ingrese el costo del evento: ";
    cin >> costo;

    cout << "Ingrese la capacidad máxima del evento: ";
    cin >> capMax;

    Evento* nuevoEvento = new Evento(nombre, tipo, fecha, lugar, duracion, costo, capMax);
    eventos.push_back(nuevoEvento);

    nuevoEvento->guardarEnArchivo("Eventos.txt");

}

void GestorEvento::registrarAsistente() {
    // Mostrar lista de eventos disponibles
    cout << "Lista de eventos disponibles:" << endl;
    for (int i = 0; i < eventos.size(); ++i) {
        cout << i + 1 << ") " << eventos[i]->getNombre() << endl;
    }

    // Solicitar al usuario que seleccione un evento
    int opcionEvento;
    cout << "Seleccione un evento (ingrese el número correspondiente): ";
    cin >> opcionEvento;

    // Verificar si la opción ingresada es válida
    if (opcionEvento < 1 || opcionEvento > eventos.size()) {
        cout << "Opción inválida." << endl;
        return;
    }

    // Obtener el evento seleccionado
    Evento* evento = eventos[opcionEvento - 1];

    // Solicitar información del asistente
    string nombre;
    int edad, dinero;
    string universidad;
    bool esAlumno, esProfesor;

    cout << "Ingrese el nombre del asistente: ";
    cin.ignore(); 
    getline(cin, nombre);
    cout << "Ingrese la edad del asistente: ";
    cin >> edad;
    cout << "Ingrese el dinero disponible del asistente: ";
    cin >> dinero;

    cout << "El asistente es alumno? (1 para Si, 0 para No): ";
    cin >> esAlumno;
    cout << "El asistente es profesor? (1 para Si, 0 para No): ";
    cin >> esProfesor;

    if (esAlumno || esProfesor) {
        cout << "Ingrese la universidad del asistente: ";
        cin.ignore(); 
        getline(cin, universidad);
    }

    if (evento->getCapacidadMaxima() <= evento->getAsistentes().size()) {
    cout << "El evento ha alcanzado su capacidad máxima de asistentes." << endl;
    return;
    }

    if (dinero < evento->getCosto()) {
        cout << "El asistente no tiene suficiente dinero para pagar la entrada al evento." << endl;
        return;
    }

    string tipoEvento = evento->getTipo();
    if (tipoEvento == "Fiesta" || tipoEvento == "Carrete" || tipoEvento == "fiesta" ||tipoEvento == "carrete") {
        
        if (edad < 18) {
            cout << "Lo sentimos, este evento es solo para mayores de 18 años." << endl;
            return;
        }
    }

    // Crear un nuevo asistente
    Asistente* nuevoAsistente = new Asistente(nombre, edad, dinero, universidad, esAlumno, esProfesor);

    // Agregar el asistente al evento seleccionado
    evento->agregarAsistente(nuevoAsistente);

    nuevoAsistente->guardarEnArchivo("Asistentes.txt");

    cout << "Asistente registrado correctamente en el evento." << endl;
}

void GestorEvento::mostrarEventos(){
    
}
void GestorEvento::mostrarAsistentes(Evento* evento){
    
}
