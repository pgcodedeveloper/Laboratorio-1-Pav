#include "Clase.h"

class Spinning : public Clase
{
    private:
        /* data */
        int cantBicicletas;
    public:
        Spinning();
        /// @brief Constructor común
        /// @param id Id de la Clase
        /// @param nom Nombre de la Clase
        /// @param t El turno de la Clase (Mañana, Tarde, Noche)
        /// @param cantB Cantidad de Bicis
        Spinning(int id, string nom, Turno t, int cantB);
        /// @brief Constructo de copia
        /// @param  const Clase de copia
        Spinning(const Spinning &);
        int getCantBic();
        void setCantBic(int cnt);
        int cupo();
        ~Spinning();
};

