#include "Clase.h"
//de vuelta
Clase::Clase(int id, string nom, Turno t)
{
    this->Id = id;
    this->Nombre = nom;
    this->turno = t;
};

Clase::Clase(const Clase & c){
    this->Id = c.Id;
    this->Nombre = c.Nombre;
    this->turno = c.turno;
}

Clase::~Clase()
{
};

int Clase::getId(){
    return this->Id;
};

string Clase::getNombre(){
    return this->Nombre;
};

Turno Clase::getTurno(){
    return this->turno;
};

void Clase::setId(int id){
    this->Id = id;
};
void Clase::setNombre(string nom){
    this->Nombre = nom;
};
void Clase::setTurno(Turno t){
    this->turno = t;
};
