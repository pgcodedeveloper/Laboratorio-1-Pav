#include "Inscripcion.h"

Inscripcion::Inscripcion(){

};

Inscripcion::Inscripcion(Fecha f, Clase *c)
{
    this->f = f;
    this->cl[this->cantClases] = c;
    this->cantClases++;
};

Fecha Inscripcion::getFecha(){
    return this->f;
};
void Inscripcion::setFecha(Fecha f){
    this->f = f;
};

Inscripcion::~Inscripcion()
{
};


int Inscripcion::getCantClases(){
    return this->cantClases;
};


void Inscripcion::agregarInscripcion(Clase *c){
    this->cl[this->cantClases] = c;
    this->cantClases++;
};

//Se evalua si en la coleccion de las clases ya existe una clase con el id proporcionado para luego devolver el resultado a la clase socio
bool Inscripcion::isEquals(int id){
    int i = 0;
    while (i < this->cantClases && this->cl[i]->getId() != id)
    {
        i++;
    }

    if(i == this->cantClases){
        return false;
    }
    else {
        return true;
    }
}

