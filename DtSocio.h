#ifndef DTSOCIO_H
#define DTSOCIO_H

#include "string"

using namespace std;

class DtSocio
{
    private:
        /* data */
        string CI;
        string Nombre;
    public:
        DtSocio();
        /// @brief Constructor común
        /// @param ci Cédula de identidad
        /// @param nom Nombre
        DtSocio(string ci, string nom);
        /// @brief Constructor de copia
        /// @param  const Copia de la Clase
        DtSocio(const DtSocio &);
        string getCI();
        string getNombre();
        void setCI(string ci);
        void setNombre(string nom);
        ~DtSocio();
};



#endif