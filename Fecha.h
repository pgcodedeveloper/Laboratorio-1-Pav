

class Fecha
{
    private:
        /* data */
        int dia;
        int mes;
        int anio;
    public:
        Fecha();
        /// @brief Constructor común
        /// @param d Día
        /// @param m Mes
        /// @param a Año
        Fecha(int d, int m, int a);
        int getDia();
        int getMes();
        int getAnio();
        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);
        ~Fecha();
};


