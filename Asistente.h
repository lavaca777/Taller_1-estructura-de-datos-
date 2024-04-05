#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Asistente {
private:
    string nombre;
    int edad;
    int dinero;
    string universidad;
    bool esAlumno;
    bool esProfesor;

public:
    // Constructor
    Asistente(string nombre, int edad, int dinero, string universidad, bool esAlumno, bool esProfesor);

    // Destructor virtual
    ~Asistente();

    // Método para mostrar los detalles del asistente
    void mostrarDetalles();
    void guardarEnArchivo(const string& nombreArchivo);

    // Getters
    string getNombre();
    int getEdad();
    int getDinero();
    string getUniversidad();
    bool esEstudiante();
    bool esDocente();
};