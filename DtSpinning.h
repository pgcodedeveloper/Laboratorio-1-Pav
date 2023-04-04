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
        /// @param id Id
        /// @param nom 
        /// @param t 
        /// @param cant 
        DtSpinning(int id, string nom, Turno t, int cant);
        int getCantBic();
        void setCantBic(int cnt);
        ~DtSpinning();
};

#endif