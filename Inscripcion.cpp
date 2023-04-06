#include "Inscripcion.h"

Inscripcion::Inscripcion(){

};

Inscripcion::Inscripcion(Fecha f, Clase *c)
{
    this->f = f;
    this->cl[this->cantClases] = c;
    this->cantClases++;
};

Fecha Inscripcion::getFecha(){
    return this->f;
};
void Inscripcion::setFecha(Fecha f){
    this->f = f;
};

Inscripcion::~Inscripcion()
{
};


int Inscripcion::getCantClases(){
    return this->cantClases;
};


void Inscripcion::agregarInscripcion(Clase *c){
    this->cl[this->cantClases] = c;
    this->cantClases++;
};

//Se evalua si en la coleccion de las clases ya existe una clase con el id proporcionado para luego devolver el resultado a la clase socio
bool Inscripcion::isEquals(int id){
    int i = 0;
    while (i < this->cantClases && this->cl[i]->getId() != id)
    {
        i++;
    }

    if(i == this->cantClases){
        return false;
    }
    else {
        return true;
    }
}

void Inscripcion::imprimirClase(){
    //cout << this->getCantClases() << endl;
    for (int i = 0; i < this->cantClases; i++)
    {
        cout << "Id Clase: " << this->cl[i]->getId() << endl;
        cout << "Nombre de la Clase: " << this->cl[i]->getNombre() << endl;
        cout << endl;
    }
    
}

bool Inscripcion::eliminarInscripcion(int idClase){
    bool isDelete = false;
    for(int i = 0; i < this->cantClases; i++){
        if (this->cl[i]->getId() == idClase){
            this->cl[i]=this->cl[this->cantClases-1];
            this->cl[this->cantClases-1]=NULL;
            delete this->cl[this->cantClases-1];
            this->cantClases--;
            isDelete = true;
        }
    }
    return isDelete;
}
