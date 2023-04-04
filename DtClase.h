#ifndef DTCLASE_H
#define DTCLASE_H

#include "string"
#include "Turno.h"

using namespace std;

class DtClase
{
    private:
        /* data */
        int Id;
        string Nombre;
        Turno turno;
    public:
        DtClase();
        /// @brief Constructor común
        /// @param id ID de la Clase
        /// @param nom Nombre de la Clase
        /// @param t Turno de la Clase
        DtClase(int id, string nom, Turno t);
        int getId();
        string getNombre();
        Turno getTurno();
        void setId(int id);
        void setNombre(string nom);
        void setTurno(Turno t);
        ~DtClase();
};




#endif