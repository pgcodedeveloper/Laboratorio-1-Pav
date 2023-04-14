#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#define MAX_CLASES_INSC 50
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
        /// @brief Constructor común
        /// @param f Fecha de la Inscripción
        /// @param c Clase de la Inscripción
        Inscripcion(Fecha f, Clase *c);
        Fecha getFecha();
        void setFecha(Fecha f);
        void imprimirClase();
        ~Inscripcion();

        int getCantClases();
        bool isEquals(int id);
        bool eliminarInscripcion(int idClase);
};

#endif