#include <iostream>
#include "GestorEvento.h"

using namespace std;

GestorEvento::GestorEvento(){}

GestorEvento::~GestorEvento(){}

void GestorEvento::crearEvento(string nombre, string tipo){

}
void GestorEvento::registrarPersonaNueva(){

    string existe, nombre, lEstudio, lTrabajo;
    int tipo, edad;

    cout<< "persona existente: ";
    cin >> existe;

    cout<<"\n"<<"Tipo de persona\n"
                "1) Profesor\n"
                "2) Alumno\n"
                "3) Otro\n"
                "opcion > ";
    cin>>tipo;

    switch (tipo)
    {
    case 1://profesor
        cout<<"\nNombre: ";
        cin>>nombre;

        cout<<"Edad: ";
        cin>>edad;

        cout<<"Lugar de trabajo: ";
        cin>>lTrabajo;
        break;

    case 2://alumno
        cout<<"\nNombre: ";
        cin>>nombre;

        cout<<"Edad: ";
        cin>>edad;

        cout<<"Lugar de estudio: ";
        cin>>lEstudio;
        break;
        
    case 3://otro
        cout<<"\nNombre: ";
        cin>>nombre;

        cout<<"Edad: ";
        cin>>edad;
        break;
    
    default:
        break;
    }
    
    
}

void GestorEvento::registrarAsistente(){
    
}

void GestorEvento::mostrarEventos(){
    
}
void GestorEvento::mostrarAsistente(Evento* evento){
    
}
