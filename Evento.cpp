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

void Evento::mostrarDetalles(){

    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
}

void Evento::agregarAsistente(Asistente* asistente) {
    asistentes.push_back(asistente);
}

void Evento::guardarEnArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (archivo.is_open()) {
        archivo << nombre << "," << tipo << "," << fecha << "," << lugar << "," << duracion << "," << costo << "," << capMax << "\n";
        archivo.close();
    } else {
        std::cerr << "Error: No se pudo abrir el archivo para guardar el evento.\n";
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