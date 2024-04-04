#pragma once
#include <iostream>
using namespace std;

class Evento {
protected:
    string nombre;
    string tipo;
    
public:
    Evento(string nombre,string tipo);
    virtual ~Evento();
    
    virtual void mostrarDetalles();
    
    // Getters
    string getNombre();
    string getTipo();
};
