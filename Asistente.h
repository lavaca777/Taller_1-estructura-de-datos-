#pragma once
#include <iostream>
using namespace std;

class Asistente {
    private:
        string nombre;
        int edad;
        
    public:
        Asistente(string nombre, int edad);
        virtual ~Asistente();
        
        // Metodo virtual puro para mostrar detalles del asistente
        virtual void mostrarDetalles();
        
        // Getters
        string getNombre();
        int getEdad();
};
