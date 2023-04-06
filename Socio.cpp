
#include <iostream>
#include "Socio.h"
#include "Inscripcion.h"


Socio::Socio(){

};

Socio::Socio(string ci, string nom)
{
    this->CI = ci;
    this->Nombre = nom;
    this->cantInsc = 0;
};

Socio::Socio(const Socio & dt){
    this->CI = dt.CI;
    this->Nombre = dt.Nombre;
};

string Socio::getCI(){
    return this->CI;
};

string Socio::getNombre(){
    return this->Nombre;
};

void Socio::setCI(string ci){
    this->CI = ci;
};

void Socio::setNombre(string nom){
    this->Nombre = nom;
};

Socio::~Socio()
{
};

int Socio::getCantInsct(){
    return this->cantInsc;
};

void Socio::agregarInscripcion(Inscripcion * ins){
    this->ins[this->cantInsc] = ins;
    this->cantInsc++;
};

//Se evalua si existe ya una inscripcion del socio al id proporcionado
bool Socio::existeInscripcion(int id){
    int i = 0;
    cout << this->cantInsc << endl;
    while (i < this->cantInsc && !this->ins[i]->isEquals(id))
    {
        i++;
    }
    cout << "i: " << i << "cant: " << this->cantInsc << endl;

    if(i == this->cantInsc){
        return false;
    }
    else{
        return true;
    }
    
}