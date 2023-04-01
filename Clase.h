#include "string"
#include "Turno.h"

using namespace std;

class Clase
{
private:
    /* data */
    int Id;
    string Nombre;
    Turno turno;
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
    virtual int cupo() = 0;
    ~Clase();
};


