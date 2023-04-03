#include "Fecha.h"
#include <stdexcept>   

using namespace std;

Fecha::Fecha(){

};

Fecha::Fecha(int d, int m, int a)
{
    if(d < 1 || d > 31 || m < 1 || m > 12 || a < 1900){
        throw invalid_argument("Fecha inválida");
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
        throw invalid_argument("Día inválido");
    }
    this->dia = d;
};

void Fecha::setMes(int m){
    if (m < 1 || m > 12) {
        throw invalid_argument("Mes inválido");
    }
    this->mes = m;
};

void Fecha::setAnio(int a){
    if (a < 1900) {
        throw invalid_argument("Año inválido");
    }
    this->anio = a;
};

Fecha::~Fecha()
{
}