#include "DtSocio.h"

DtSocio::DtSocio(){

};

DtSocio::DtSocio(string ci, string nom)
{
    this->CI = ci;
    this->Nombre = nom;
};

DtSocio::DtSocio(const DtSocio & dt){
    this->CI = dt.CI;
    this->Nombre = dt.Nombre;
};

string DtSocio::getCI(){
    return this->CI;
};

string DtSocio::getNombre(){
    return this->Nombre;
};

void DtSocio::setCI(string ci){
    this->CI = ci;
};

void DtSocio::setNombre(string nom){
    this->Nombre = nom;
};

DtSocio::~DtSocio()
{
}