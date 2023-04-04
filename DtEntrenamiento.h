#ifndef DTENTRENAMIENTO_H
#define DTENTRENAMIENTO_H

#include "string"
#include "Turno.h"
#include "DtClase.h"

using namespace std;

class DtEntrenamiento : public DtClase
{
private:
    /* data */
    bool enRambla;
public:
    DtEntrenamiento(); 
    DtEntrenamiento(int id,string nombre, Turno t, bool enR);
    DtEntrenamiento(const DtEntrenamiento &);
    bool getEnRambla();
    void setEnRambla(bool enR);
    ~DtEntrenamiento();
};


#endif