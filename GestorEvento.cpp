#include <iostream>
#include "GestorEvento.h"

using namespace std;

GestorEvento::GestorEvento(){}

GestorEvento::~GestorEvento(){}

void GestorEvento::cargarAsistentesDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << " para lectura." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream iss(linea);
        string nombreEvento, nombreAsistente, universidad;
        int edad, dinero;
        bool esAlumno, esProfesor;

        // Parsear la linea para obtener los datos del asistente
        string edadStr, dineroStr, esAlumnoStr, esProfesorStr;
        if (getline(iss, nombreEvento, ',') &&
            getline(iss, nombreAsistente, ',') &&
            getline(iss, edadStr, ',') &&
            getline(iss, dineroStr, ',') &&
            getline(iss, universidad, ',') &&
            getline(iss, esAlumnoStr, ',') &&
            getline(iss, esProfesorStr)) {
            edad = stoi(edadStr);
            dinero = stoi(dineroStr);
            esAlumno = stoi(esAlumnoStr);
            esProfesor = stoi(esProfesorStr);
            
            // Buscar el evento correspondiente
            for (Evento* evento : eventos) {
                
                if (evento->getNombre() == nombreEvento) {
                    // Crear y agregar el asistente al evento
                    Asistente* nuevoAsistente = new Asistente(nombreAsistente, edad, dinero, universidad, esAlumno, esProfesor);
                    evento->agregarAsistente(nuevoAsistente);

                    break; // No es necesario seguir buscando eventos
                }
            }
        } else {
            cerr << "Error: Formato incorrecto en la linea del archivo." << endl;
        }
    }

    archivo.close();
}


void GestorEvento::cargarEventosDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << " para lectura." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream iss(linea);
        string nombre, tipo, fecha, lugar, duracion;
        int costo, capMax;

        // Parsear la linea para obtener los datos del evento
        string costoStr, capMaxStr;
        if (getline(iss, nombre, ',') &&
            getline(iss, tipo, ',') &&
            getline(iss, fecha, ',') &&
            getline(iss, lugar, ',') &&
            getline(iss, duracion, ',') &&
            getline(iss, costoStr, ',') &&
            getline(iss, capMaxStr)) {
            costo = stoi(costoStr);
            capMax = stoi(capMaxStr);

            Evento* nuevoEvento = new Evento(nombre, tipo, fecha, lugar, duracion, costo, capMax);
            eventos.push_back(nuevoEvento);

        } else {
            cerr << "Error: Formato incorrecto en la linea del archivo." << endl;
        }
    }

    archivo.close();
}


void GestorEvento::crearEvento() {
    
    string nombre, fecha, lugar, duracion, tipo;
    int costo, capMax;

    cout << "\nIngrese el nombre del evento: ";
    cin.ignore(); // Ignora el carácter de nueva linea pendiente
    getline(cin, nombre);

    cout << "Ingrese el tipo de evento: ";
    getline(cin, tipo);

    cout << "Ingrese la fecha del evento: ";
    getline(cin, fecha);

    cout << "Ingrese el lugar del evento: ";
    getline(cin, lugar);

    cout << "Ingrese la duracion del evento: ";
    getline(cin, duracion);

    cout << "Ingrese el costo del evento: ";
    cin >> costo;

    cout << "Ingrese la capacidad maxima del evento: ";
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
    cout << "Seleccione un evento (ingrese el numero correspondiente): ";
    cin >> opcionEvento;

    // Verificar si la opcion ingresada es valida
    if (opcionEvento < 1 || opcionEvento > eventos.size()) {
        cout << "Opción invalida." << endl;
        return;
    }

    // Obtener el evento seleccionado
    Evento* evento = eventos[opcionEvento - 1];

    // Solicitar informacion del asistente
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
    cout << "El evento ha alcanzado su capacidad maxima de asistentes." << endl;
    return;
    }

    if (dinero < evento->getCosto()) {
        cout << "El asistente no tiene suficiente dinero para pagar la entrada al evento." << endl;
        return;
    }

    string tipoEvento = evento->getTipo();
    if (tipoEvento == "Fiesta" || tipoEvento == "Carrete" || tipoEvento == "fiesta" ||tipoEvento == "carrete") {
        
        if (edad < 18) {
            cout << "Lo sentimos, este evento es solo para mayores de edad." << endl;
            return;
        }
    }

    // Crear un nuevo asistente
    Asistente* nuevoAsistente = new Asistente(nombre, edad, dinero, universidad, esAlumno, esProfesor);

    // Agregar el asistente al evento seleccionado
    evento->agregarAsistente(nuevoAsistente);

    nuevoAsistente->guardarEnArchivo("Asistentes.txt", evento->getNombre());

    

    cout << "Asistente registrado correctamente en el evento." << endl;
}

void GestorEvento::mostrarListaAsistentes(){
    
    for (Evento* evento : eventos){

        evento->mostrarListaAsistentes();
        cout<<endl;
    }

}

void GestorEvento::generarInforme() {
    // Información general
    cout << "=== Informe de Eventos ===" << endl;
    cout << "Total de eventos programados: " << eventos.size() << endl;

    // Lista de eventos programados
    cout << "\nLista de eventos programados:" << endl;
    for (const auto& evento : eventos) {
        evento->mostrarDetalles();
    }

    // Estadisticas sobre asistencia a los eventos
    int totalAsistentes = 0;
    double asistenciaPromedio = 0.0;
    for (const auto& evento : eventos) {
        totalAsistentes += evento->getAsistentes().size();
    }
    if (!eventos.empty()) {
        asistenciaPromedio = static_cast<double>(totalAsistentes) / eventos.size();
    }
    cout << "\nEstadisticas de asistencia:" << endl;
    cout << "Numero total de asistentes: " << totalAsistentes << endl;
    cout << "Asistencia promedio por evento: " << asistenciaPromedio << endl;

    // Detalles sobre los asistentes
    int edadTotal = 0;
    int totalAsistentesConEdad = 0;
    int totalAsistentesProfesor = 0;
    int totalAsistentesAlumno = 0;
    int totalAsistentesOtros = 0; // Para contar los asistentes que no son profesores ni estudiantes

    for (const auto& evento : eventos) {
        for (const auto& asistente : evento->getAsistentes()) {
            edadTotal += asistente->getEdad();
            totalAsistentesConEdad++;

            // Contar el numero de asistentes por tipo
            if (asistente->esDocente()) {
                totalAsistentesProfesor++;
            } else if (asistente->esEstudiante()) {
                totalAsistentesAlumno++;
            } else {
                totalAsistentesOtros++;
            }
        }
    }

    double edadPromedio = 0.0;
    double promedioAlumnos = 0.0;
    double promedioProfesores = 0.0;
    double promedioOtros = 0.0; // Para el promedio de otros asistentes
    if (totalAsistentesConEdad != 0) {
        edadPromedio = static_cast<double>(edadTotal) / totalAsistentesConEdad;
        promedioAlumnos = static_cast<double>(totalAsistentesAlumno) / totalAsistentesConEdad;
        promedioProfesores = static_cast<double>(totalAsistentesProfesor) / totalAsistentesConEdad;
        promedioOtros = static_cast<double>(totalAsistentesOtros) / totalAsistentesConEdad;
    }

    cout << "\nDetalles sobre los asistentes:" << endl;
    cout << "Edad promedio de los asistentes: " << edadPromedio << endl;
    cout << "Total de asistentes profesores: " << totalAsistentesProfesor << endl;
    cout << "Total de asistentes alumnos: " << totalAsistentesAlumno << endl;
    cout << "Promedio de alumnos que asisten a los eventos: " << promedioAlumnos << endl;
    cout << "Promedio de profesores que asisten a los eventos: " << promedioProfesores << endl;
    cout << "Promedio de otros asistentes: " << promedioOtros << endl;
}
