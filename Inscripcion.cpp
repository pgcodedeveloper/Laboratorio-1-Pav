#include "Inscripcion.h"

Inscripcion::Inscripcion(){

};

Inscripcion::Inscripcion(Fecha f)
{
    this->f = f;
    this->cantClases = 0;
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

void Inscripcion::getClase(int i){
    cout << "Id Clase: " << this-cl[i]->getId() << endl;
    cout << "Nombre: " << this->cl[i]->getNombre() << endl;
}

