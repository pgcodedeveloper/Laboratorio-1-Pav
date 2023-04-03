#include "Entrenamiento.h"

Entrenamiento::Entrenamiento()
{

};

Entrenamiento::Entrenamiento(int id, string nom, Turno t, bool enR) : Clase(id, nom, t){
    this->enRambla = enR;
};

Entrenamiento::Entrenamiento(const Entrenamiento &e): Clase(e){
    this->enRambla = e.enRambla; 
};

bool Entrenamiento::getEnRambla(){
    return this->enRambla;
};
void Entrenamiento::setEnRambla(bool enR){
    this->enRambla = enR; 
};
int Entrenamiento::cupo(){
    if(this->enRambla){
        return 20;
    }
    else{
        return 10;
    }
};

Entrenamiento::~Entrenamiento()
{
    
};