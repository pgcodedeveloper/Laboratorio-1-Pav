#include "DtSpinning.h"

DtSpinning::DtSpinning(){

}

DtSpinning::DtSpinning(int id, string nom, Turno t, int cant):DtClase(id, nom,t){
    this->cantBicicletas = cant;
}

int DtSpinning::getCantBic(){
    return this->cantBicicletas;
};

void DtSpinning::setCantBic(int cnt){
    this->cantBicicletas = cnt;
};

DtSpinning::~DtSpinning(){
    
};
