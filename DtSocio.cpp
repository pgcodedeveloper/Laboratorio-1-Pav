#include "DtSocio.h"

DtSocio::DtSocio(){

};

DtSocio::DtSocio(int ci, string nom)
{
    this->CI = ci;
    this->Nombre = nom;
};

DtSocio::DtSocio(const DtSocio & dt){
    this->CI = dt.CI;
    this->Nombre = dt.Nombre;
};

int DtSocio::getCI(){
    return this->CI;
};

string DtSocio::getNombre(){
    return this->Nombre;
};

void DtSocio::setCI(int ci){
    this->CI = ci;
};

void DtSocio::setNombre(string nom){
    this->Nombre = nom;
};

DtSocio::~DtSocio()
{
}