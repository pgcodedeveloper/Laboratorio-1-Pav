#include "DtClase.h"
#include "DtEntrenamiento.h"
#include "DtSpinning.h"
#include "iostream"
#include <typeinfo>

using namespace std;

DtClase::DtClase()
{
}

DtClase::DtClase(int id, string nom, Turno t){
    this->Id = id;
    this->Nombre = nom;
    this->turno = t;
};

int DtClase::getId(){
    return this->Id;
};

string DtClase::getNombre(){
    return this->Nombre;
};

Turno DtClase::getTurno(){
    return this->turno;
};

void DtClase::setId(int id){
    this->Id = id;
};
void DtClase::setNombre(string nom){
    this->Nombre = nom;
};
void DtClase::setTurno(Turno t){
    this->turno = t;
};

DtClase::~DtClase()
{
};


ostream& operator << (ostream& salida,DtClase& clase){
	
    try
    {
        DtEntrenamiento& en = dynamic_cast<DtEntrenamiento&>(clase);
        cout << "Id Clase: " << en.getId() << endl;
        cout << "Nombre: " << en.getNombre() << endl;
        if(en.getTurno() == MANANA){
            cout << "Turno: Manana" << endl;
        } else if(en.getTurno() == TARDE){
            cout << "Turno: Tarde" << endl;
        } else if(en.getTurno() == NOCHE){
            cout << "Turno: Noche" << endl;
        }
        if(en.getEnRambla()){
            cout << "Es en Rambla: SI" << endl; 
        }
        else{
            cout << "Es en Rambla: NO" << endl;
        }
        
    }
    catch(bad_cast)
    {
        DtSpinning& sp = dynamic_cast<DtSpinning&>(clase);
        cout << "Id Clase: " << sp.getId() << endl;
        cout << "Nombre: " << sp.getNombre() << endl;
        if(sp.getTurno() == MANANA){
            cout << "Turno: Manana" << endl;
        } else if(sp.getTurno() == TARDE){
            cout << "Turno: Tarde" << endl;
        } else if(sp.getTurno() == NOCHE){
            cout << "Turno: Noche" << endl;
        }
        cout << "Cantidad de Bicicletas: " << sp.getCantBic() << endl;
    }
    
	return salida;
};