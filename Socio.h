#ifndef SOCIO_H
#define SOCIO_H
#define MAX_INSC 20
#include "string"
#include "Inscripcion.h"

using namespace std;

class Socio
{
    private:
        /* data */
        string CI;
        string Nombre;
        //pseudoatributo
        Inscripcion* ins[MAX_INSC];
        int cantInsc;
    public:
        Socio();
        /// @brief Constructor común
        /// @param ci Cédula de identidad
        /// @param nom Nombre
        Socio(string ci, string nom);
        /// @brief Constructor de copia
        /// @param  const Copia de la Clase
        Socio(const Socio &);
        string getCI();
        string getNombre();
        void setCI(string ci);
        void setNombre(string nom);
        ~Socio();

        int getCantInsct();
        void agregarInscripcion(Inscripcion * ins);
        bool existeInscripcion(int id);
};



#endif