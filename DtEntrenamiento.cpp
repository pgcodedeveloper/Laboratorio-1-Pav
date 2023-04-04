#include "DtEntrenamiento.h"

DtEntrenamiento::DtEntrenamiento(){

}

DtEntrenamiento::DtEntrenamiento(int id,string nombre, Turno t, bool enR) : DtClase(id,nombre,t){
    this->enRambla = enR;
}

bool DtEntrenamiento::getEnRambla(){
    return this->enRambla;
};
void DtEntrenamiento::setEnRambla(bool enR){
    this->enRambla = enR; 
};

DtEntrenamiento::~DtEntrenamiento(){
    
};