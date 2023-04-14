#include "Fecha.h"  
#include "iostream"

using namespace std;

Fecha::Fecha(){

};

Fecha::Fecha(int d, int m, int a)
{
    if(d < 1 || d > 31 || m < 1 || m > 12 || a < 1900){
        throw invalid_argument("Fecha invalida");
    }
    this->dia = d;
    this->mes = m;
    this->anio = a;
};

int Fecha::getDia(){
    return this->dia;
};

int Fecha::getMes(){
    return this->mes;
};

int Fecha::getAnio(){
    return this->anio;
};

void Fecha::setDia(int d){
    if (d < 1 || d > 31) {
        throw invalid_argument("Dia invalido");
    }
    this->dia = d;
};

void Fecha::setMes(int m){
    if (m < 1 || m > 12) {
        throw invalid_argument("Mes invalido");
    }
    this->mes = m;
};

void Fecha::setAnio(int a){
    if (a < 1900) {
        throw invalid_argument("Anio invalido");
    }
    this->anio = a;
};

void Fecha::toString(){
    cout << this->dia << "/" << this->mes << "/" << this->anio << endl;
}

Fecha::~Fecha()
{
}