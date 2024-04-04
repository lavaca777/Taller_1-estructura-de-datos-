#include "Asistente.h"
#include <iostream>
using namespace std;

Asistente::Asistente(string nombre, int edad){
    this -> nombre = nombre;
    this -> edad = edad;
}

Asistente::~Asistente() {}

void Asistente::mostrarDetalles(){
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

string Asistente::getNombre(){ return nombre;}
int Asistente::getEdad(){ return edad;}