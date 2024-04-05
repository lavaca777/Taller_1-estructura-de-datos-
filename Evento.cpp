#include "Evento.h"
#include <iostream>

using namespace std;

Evento::Evento(const string& nombre, const string& tipo, const string& fecha, const string& lugar, const string& duracion, int costo, int capMax) {
    this->nombre = nombre;
    this->tipo = tipo;
    this->fecha = fecha;
    this->lugar = lugar;
    this->duracion = duracion;
    this->costo = costo;
    this->capMax = capMax;
}

Evento::~Evento() {}

void Evento::mostrarDetalles() {
    cout << "\nNombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Lugar: " << lugar << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Costo: " << costo << endl;
    cout << "Capacidad maxima: " << capMax << endl;

    cout << "Asistentes:" << endl;
    for (const auto& asistente : asistentes) {
        cout << "- " << asistente->getNombre() << endl;
    }
}

void Evento::agregarAsistente(Asistente* asistente) {
    asistentes.push_back(asistente);
}

void Evento::guardarEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::app);
    if (archivo.is_open()) {
        archivo << nombre << "," << tipo << "," << fecha << "," << lugar << "," << duracion << "," << costo << "," << capMax << "\n";
        archivo.close();
    } else {
        cerr << "Error: No se pudo abrir el archivo para guardar el evento.\n";
    }
}

void Evento::mostrarListaAsistentes() {
    cout << "Asistentes al evento " << nombre << ":" << endl;
    for (Asistente* asistente : asistentes) {
        cout << asistente->getNombre() << endl;;
    }
}

string Evento::getNombre(){ return nombre;}
string Evento::getTipo(){ return tipo;}
string Evento::getFecha(){ return fecha;}
string Evento::getLugar(){ return lugar;}
string Evento::getDuracion(){ return duracion;}
int Evento::getCosto(){ return costo;}
int Evento::getCapacidadMaxima(){ return capMax;}
vector<Asistente*>& Evento::getAsistentes() { return asistentes; }