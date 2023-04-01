#include "string"

using namespace std;

class Turno
{
private:
    /* data */
    enum dato {
        Mañana = 0,
        Tarde = 1,
        Noche = 2
    };
public:
    Turno();
    /// @brief Constructor común
    /// @param opcion = Las diferentes opciones para el turno
    Turno(int opcion);
    /// @brief Constructor por copia
    /// @param  Turno se pasa la copia del mismo 
    Turno(const Turno &);
    string getTurno(int opcion);
    void setTurno(int opcion);
    ~Turno();
};


