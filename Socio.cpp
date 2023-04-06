
#include <iostream>
#include "Socio.h"
#include "Inscripcion.h"


Socio::Socio(){

};

Socio::Socio(string ci, string nom)
{
    this->CI = ci;
    this->Nombre = nom;
    this->cantInsc = 0;
};

Socio::Socio(const Socio & dt){
    this->CI = dt.CI;
    this->Nombre = dt.Nombre;
};

string Socio::getCI(){
    return this->CI;
};

string Socio::getNombre(){
    return this->Nombre;
};

void Socio::setCI(string ci){
    this->CI = ci;
};

void Socio::setNombre(string nom){
    this->Nombre = nom;
};

Socio::~Socio()
{
};

int Socio::getCantInsct(){
    return this->cantInsc;
};

void Socio::agregarInscripcion(Inscripcion * ins){
    this->ins[this->cantInsc] = ins;
    this->cantInsc++;
};

//Se evalua si existe ya una inscripcion del socio al id proporcionado
bool Socio::existeInscripcion(int id){
    int i = 0;
    while (i < this->cantInsc && !this->ins[i]->isEquals(id))
    {
        i++;
    }

    if(i == this->cantInsc){
        return false;
    }
    else{
        return true;
    }
    
}

void Socio::imprimirInscr(){
    
    if(this->cantInsc == 0){
        throw invalid_argument("No tienes inscripciones aun!!\n");
    }
    else{
        for (int i = 0; i < this->cantInsc; i++){
            cout << "+-------Inscripcion " << i << "-------+" << endl;
            cout << "Fecha: ";
            this->ins[i]->getFecha().toString();
            cout << "+---------------------------+" << endl;
            cout << "+-----------Datos-----------+" << endl;
            cout << "Nombre del Socio: " << this->getNombre() << endl;
            this->ins[i]->imprimirClase();
        }
    }
}

void Socio::eliminarInscripcion(int idClase){
    for (int i = 0; i < this->cantInsc; i++){
        bool isDelete = this->ins[i]->eliminarInscripcion(idClase);
        //Si la clase se eliminó entonces tambien elimino la inscripción
        if(isDelete){
            this->ins[i]=this->ins[this->cantInsc-1];
            this->ins[this->cantInsc-1]=NULL;
            delete this->ins[this->cantInsc-1];
            this->cantInsc--;
        }
    }
    
};