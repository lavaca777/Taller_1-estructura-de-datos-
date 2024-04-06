#include "Asistente.h"
#include <iostream>
using namespace std;

Asistente::Asistente(string nombre, int edad, int dinero, string universidad, bool esAlumno, bool esProfesor) {
    this->nombre = nombre;
    this->edad = edad;
    this->dinero = dinero;
    this->universidad = universidad;
    this->esAlumno = esAlumno;
    this->esProfesor = esProfesor;
}

Asistente::~Asistente() {}

void Asistente::mostrarDetalles() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Dinero: " << dinero << endl;
    cout << "Universidad: " << universidad << endl;
    cout << "Es alumno: " << (esAlumno ? "Si" : "No") << endl;
    cout << "Es profesor: " << (esProfesor ? "Si" : "No") << endl;
}

void Asistente::guardarEnArchivo(const string& nombreArchivo, const string& nombreEvento) {
    ofstream archivo(nombreArchivo, ios::app);
    if (archivo.is_open()) {
        archivo << nombreEvento << "," << nombre << "," << edad << "," << dinero << "," << universidad << "," << esAlumno << "," << esProfesor << "\n";
        archivo.close();
    } else {
        cerr << "Error: No se pudo abrir el archivo para guardar el asistente." << endl;
    }
}

// Getters
string Asistente::getNombre() { return nombre; }
int Asistente::getEdad() { return edad; }
int Asistente::getDinero() { return dinero; }
string Asistente::getUniversidad() { return universidad; }
bool Asistente::esEstudiante() { return esAlumno; }
bool Asistente::esDocente() { return esProfesor; }