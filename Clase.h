#ifndef CLASE_H
#define CLASE_H
#define MAX_SOCIOS_INSC 20
#include "string"
#include "Socio.h"
#include "Turno.h"

using namespace std;

class Clase
{
private:
    /* data */
    int Id;
    string Nombre;
    Turno turno;    
    /* pseudoatributos */
    Socio * so[MAX_SOCIOS_INSC];
    int cantSocios = 0;
public:
    Clase();
    /// @brief Constructor común
    /// @param id ID de la Clase
    /// @param nom Nombre de la Clase
    /// @param t Turno de la Clase
    Clase(int id, string nom, Turno t);
    /// @brief Constructor de copia
    /// @param  const Clase de copia
    Clase(const Clase & );
    int getId();
    string getNombre();
    Turno getTurno();
    void setId(int id);
    void setNombre(string nom);
    void setTurno(Turno t);
    void agregarSocioClase(Socio * s);
    int getCantSociosClase();
    virtual int cupo() = 0;
    ~Clase();
};


#endif