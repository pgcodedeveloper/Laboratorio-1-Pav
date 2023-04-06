#include "Entrenamiento.h"

Entrenamiento::Entrenamiento()
{

};

Entrenamiento::Entrenamiento(int id, string nom, Turno t, bool enR) : Clase(id, nom, t){
    this->enRambla = enR;
    if(this->enRambla){
        this->cantPersonas = 20;
    }
    else {
        this->cantPersonas = 10;
    }
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

int Entrenamiento::getCantPersonas(){
    return this->cantPersonas;
}
Entrenamiento::~Entrenamiento()
{  
};

//Cada nuevo soscio agregado se le decrementa uno a la cantPersonas
void Entrenamiento::agregarSocio(){
    this->cantPersonas--;
}
//Cada socio eliminado se le agrega uno a la cantPersonas
void Entrenamiento::eliminarSocio(){
    this-cantPersonas++;
}

int Entrenamiento::cupo(){
    return this->cantPersonas;
};

