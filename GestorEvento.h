#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Evento.h"
#include "Asistente.h"

using namespace std;

class GestorEvento {
private:
    vector<Evento*> eventos;
    vector<Asistente*> asistentes;

public:
    GestorEvento();
    ~GestorEvento();

    void cargarAsistentesDesdeArchivo(const string& nombreArchivo);
    void cargarEventosDesdeArchivo(const string& nombreArchivo);


    void crearEvento();
    void registrarAsistente();
    void mostrarListaAsistentes();
    void generarInforme();

    // Métodos getter para acceder a los eventos y asistentes
    const vector<Evento*>& getEventos();
    const vector<Asistente*>& getAsistentes();
};
