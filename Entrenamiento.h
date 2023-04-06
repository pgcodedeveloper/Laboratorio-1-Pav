#ifndef ENTRENAMIENTO_H
#define ENTRENAMIENTO_H
#define MAX_SOCIOS_CLASE 20
#include "Clase.h"
#include "Socio.h"

class Entrenamiento : public Clase
{
    private:
        /* data */
        bool enRambla;
        /* pseudoatributos */
        Socio * so[MAX_SOCIOS_CLASE];
        int cantSocios = 0;
    public:
        Entrenamiento();
        /// @brief Constructor común
        /// @param id Id de la Clase
        /// @param nom Nombre
        /// @param t Turno
        /// @param enR Si es en Rambla o no
        Entrenamiento(int id, string nom, Turno t, bool enR);
        /// @brief Constructor de copia
        /// @param  const Clase Entrenamiento
        Entrenamiento (const Entrenamiento &);
        bool getEnRambla();
        void setEnRambla(bool enR);
        int cupo();
        ~Entrenamiento();
};


#endif

