#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#define MAX_SOCIOS_INSC 20
#define MAX_CLASES_INSC 20
#include "Fecha.h"
#include "Clase.h"
#include "iostream"

using namespace std;

class Inscripcion
{
    private:
        /* atributos */
        Fecha f;
        //pseudoatributos
        Clase * cl[MAX_CLASES_INSC];
        int cantClases;
    public:
        Inscripcion();
        Inscripcion(Fecha f);
        Fecha getFecha();
        void setFecha(Fecha f);
        ~Inscripcion();

        int getCantClases();
        void getClase(int i);
        void agregarInscripcion(Clase *c);
};

#endif