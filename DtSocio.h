#ifndef DTSOCIO_H
#define DTSOCIO_H

#include "string"

using namespace std;

class DtSocio
{
    private:
        /* data */
        int CI;
        string Nombre;
    public:
        DtSocio();
        /// @brief Constructor común
        /// @param ci Cédula de identidad
        /// @param nom Nombre
        DtSocio(int ci, string nom);
        /// @brief Constructor de copia
        /// @param  const Copia de la Clase
        DtSocio(const DtSocio &);
        int getCI();
        string getNombre();
        void setCI(int ci);
        void setNombre(string nom);
        ~DtSocio();
};



#endif