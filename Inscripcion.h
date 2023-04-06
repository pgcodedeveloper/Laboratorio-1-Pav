#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#define MAX_SOCIOS_INSC 20
#define MAX_CLASES_INSC 20
#include "iostream"
#include "Fecha.h"
#include "Clase.h"


using namespace std;

class Inscripcion
{
    private:
        /* atributos */
        Fecha f;
        //pseudoatributos
        Clase * cl[MAX_CLASES_INSC];
        int cantClases = 0;        

    public:
        Inscripcion();
        Inscripcion(Fecha f, Clase *c);
        Fecha getFecha();
        void setFecha(Fecha f);
        ~Inscripcion();

        int getCantClases();
        bool isEquals(int id);
        void agregarInscripcion(Clase *c);
};

#endif