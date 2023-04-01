#include "Turno.h"

Turno::Turno(){

}

Turno::Turno(int opcion)
{
    switch (opcion)
    {
        case 0:
            this->Mañana;
            break;
        case 1:
            this->Tarde;
            break;
        case 2: 
            this->Noche;
            break;
        default:
            break;
    }
}

string Turno::getTurno(int opcion){
    
    switch (opcion)
    {
        case 0:
            return "Mañana";
            break;
        case 1:
            return "Tarde";
            break;
        case 2: 
            return "Noche";
            break;
        default:
            break;
    }
}

void Turno::setTurno(int opcion){
    
    switch (opcion)
    {
        case 0:
            this->Mañana;
            break;
        case 1:
            this->Tarde;
            break;
        case 2: 
            this->Noche;
            break;
        default:
            break;
    }
}


Turno::~Turno()
{
}