#pragma once
#include <iostream>
#include "Evento.h"
#include "Asistente.h"
#include <vector>
#include <string>
using namespace std;

class GestorEvento{

    private:
        vector<Evento*> eventos;
        vector<Asistente *> Asistentes;

    public:
        GestorEvento();
        ~GestorEvento();

        void crearEvento(string nombre, string tipo);
        void registrarPersonaNueva();
        void registrarAsistente();
        void mostrarEventos();
        void mostrarAsistente(Evento* evento);  
        
        // Metodos getter para acceder a los eventos y Asistente
        const vector<Evento*>& getEventos();
        const vector<Asistente*>& getAsistente();

        

};