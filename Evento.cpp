#include "Evento.h"
#include <iostream>
using namespace std;

Evento::Evento(string nombre, string tipo){
    this -> nombre = nombre;
    this -> tipo = tipo;
}

Evento::~Evento() {}

// Implementacion de mostrarDetalles
void Evento::mostrarDetalles(){
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
}

string Evento::getNombre(){ return nombre;}
string Evento::getTipo(){ return tipo;}