#pragma once
#include <iostream>
#include <vector>
#include "Asistente.h"
#include <fstream>

using namespace std;

class Evento {
protected:
    string nombre;
    string tipo;
    string fecha;
    string lugar;
    string duracion;
    int costo;
    int capMax; //capacidad maxima

    vector<Asistente*> asistentes;
    
public:
    Evento(const string& nombre, const string& tipo, const string& fecha, const string& lugar, const string& duracion, int costo, int capMax);
    ~Evento();
    
    void mostrarDetalles();
    void agregarAsistente(Asistente* asistente);

    void guardarEnArchivo(const string& nombreArchivo);

    
    // Getters
    string getNombre();
    string getTipo();
    string getFecha();
    string getLugar();
    string getDuracion();
    int getCosto();
    int getCapacidadMaxima();
    vector<Asistente*>& getAsistentes();

};