#include "Spinning.h"

Spinning::Spinning(){

};

Spinning::Spinning(int id, string nom, Turno t, int cantB) : Clase(id,nom,t){
    this->cantBicicletas = cantB;
};

Spinning::Spinning(const Spinning &sp) : Clase(sp){
    this->cantBicicletas = sp.cantBicicletas;
};

int Spinning::getCantBic(){
    return this->cantBicicletas;
};

void Spinning::setCantBic(int cnt){
    this->cantBicicletas = cnt;
};

Spinning::~Spinning(){
    
};


//Cada nuevo soscio agregado se le decrementa uno a la cantBiciletas
void Spinning::agregarSocio(){
    this->cantBicicletas--;
};

//Cada soscio eliminado se le agrega uno a la cantBiciletas
void Spinning::eliminarSocio(){
    this->cantBicicletas++;
}

int Spinning::cupo(){
    return this->cantBicicletas;
};

