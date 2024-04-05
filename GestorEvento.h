#pragma once
#include <iostream>
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

    void crearEvento();
    void registrarAsistente();
    void mostrarEventos();
    void mostrarAsistentes(Evento* evento);

    // Métodos getter para acceder a los eventos y asistentes
    const vector<Evento*>& getEventos();
    const vector<Asistente*>& getAsistentes();
};
