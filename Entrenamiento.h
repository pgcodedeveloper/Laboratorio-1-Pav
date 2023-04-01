#include "Clase.h"

class Entrenamiento : public Clase
{
    private:
        /* data */
        bool enRambla;
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


