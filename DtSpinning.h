#ifndef DTSPINNING_H
#define DTSPINNING_H

#include "DtClase.h"

class DtSpinning : public DtClase
{
    private:
        /* data */
        int cantBicicletas;
    public:
        DtSpinning();
        /// @brief Constructor común
        /// @param id Id de la Clase
        /// @param nom Nombre de la Clase
        /// @param t Turno de la Clase
        /// @param cant Cantidad de Bicicletas
        DtSpinning(int id, string nom, Turno t, int cant);
        int getCantBic();
        void setCantBic(int cnt);
        ~DtSpinning();
};

#endif