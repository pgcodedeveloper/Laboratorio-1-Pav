#include "iostream"
#include "DtSocio.h"
#include "Clase.h"

//Constantes de los arreglos
#define MAX_SOCIOS 20
#define MAX_CLASES 20
using namespace std;

//Colecciones Globales
struct Socios
{
    DtSocio* s[MAX_SOCIOS];
    int tope = 0;
} colSocios;

struct Clases
{
    Clase* c[MAX_CLASES];
    int tope = 0;
} colClases;


void agregarSocio(string ci, string nombre);
void menuAgregarSocio();
void menuListarSocios();
void ListarSocios();
//No terminada
void agregarClase();

void menuAgregarSocio(){
    system("clear");
    cout << "+-----------------------+" << endl;
    cout << "|  1. Agregar un Socio  |" << endl;
    cout << "+-----------------------+" << endl;
    // Funcion para agregar el socio
    string ci, nombre;
    cout << "Ingrese el nombre del Socio: ";
    cin >> nombre;
    cout << "Ingrese la Cedula del Socio: ";
    cin >> ci;
    try
    {
        agregarSocio(ci, nombre);
        cout << "Socio agregado correctamente!" << endl;
        system("pause");
    }
    catch(invalid_argument& e)
    {
        cout << e.what() << endl;
        system("sleep 5");
    }
}

void menuListarSocios(){
    system("clear");
    cout << "+------------------------+" << endl;
    cout << "|  2. Listar los Socios  |" << endl;
    cout << "+------------------------+" << endl;
    try
    {
        ListarSocios();
    }
    catch(invalid_argument& e)
    {
        cout << e.what() << endl;
        system("pause");
    }
}

void ListarSocios(){
    if(colSocios.tope != 0){
        for (int i = 0; i < colSocios.tope; i++)
        {
            cout << "+---------Socio " << i << "--------+" << endl;
            cout << "Nombre: " << colSocios.s[i]->getNombre() << endl;
            cout << "CI: " << colSocios.s[i]->getCI() << endl;
        }
        cout << endl;
        system("pause");
    }
    else{
        throw invalid_argument("No hay socios para listar!!\n");
    }
}

//Función para agregar un nuevo Socio al sistema, tomando como parametros el Nombre y CI
void agregarSocio(string ci, string nombre){
    int i = 0;
    //Recorro la estructura de socios para ver que no existan dos iguales
    while (i<colSocios.tope && colSocios.s[i]->getNombre() != nombre)
    {
        i++;
    }
    //Si llego al final de la estructura creo un nuevo Socio
    if(i == colSocios.tope){
        DtSocio * s = new DtSocio(ci,nombre);
        colSocios.s[colSocios.tope] = s;
        colSocios.tope++;
    }
    else{
        throw invalid_argument("Ya existe un Socio con ese nombre\n");
    }
    
}

int main(){
    
    cout << "+-----------------------+" << endl;
    cout << "| Bienvenido al sistema |" << endl;
    cout << "+-----------------------+" << endl;
    system("pause");
    int opcion = 0;
    do{
        system("clear");
        cout << "+--------------------------+" << endl;
        cout << "|   Opciones disponibles   |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "| 1) Agregar un Socio.     |" << endl;
        cout << "| 2) Listar los Socios     |" << endl;
        cout << "| 3) Agregar una Clase     |" << endl;
        cout << "| 4) Agregar Inscripcion   |" << endl;
        cout << "| 5) Eliminar Inscripcion  |" << endl;
        cout << "| 6) Salir.                |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        
        switch (opcion)
        {
            case 1:
                menuAgregarSocio();
                break;
            
            case 2:
                menuListarSocios();
                break;
            case 3:
                system("clear");
                cout << "+--------------------------+" << endl;
                cout << "|  3. Agregar Inscripcion  |" << endl;
                cout << "+--------------------------+" << endl;
                // Funcion para agregar un nueva Inscripción
                system("sleep 5");
                break;
            case 4:
                system("clear");
                cout << "+--------------------------+" << endl;
                cout << "|  4. Agregar Inscripcion  |" << endl;
                cout << "+--------------------------+" << endl;
                // Funcion para agregar un nueva Inscripción
                system("sleep 5");
                break;
            case 5:
                system("clear");
                cout << "+---------------------------+" << endl;
                cout << "|  5. Eliminar Inscripcion  |" << endl;
                cout << "+---------------------------+" << endl;
                // Funcion para agregar un nueva Inscripción
                system("sleep 5");
                break;
            case 6:
                system("clear");
                cout << "+------------+" << endl;
                cout << "|  6. Salir  |" << endl;
                cout << "+------------+" << endl;
                break;
            default:
                cout << "+---------------------------------------+" << endl;
                cout << "|           Opcion Incorrecta           |" << endl;
                cout << "+---------------------------------------+" << endl;
                opcion = 0;
                system("pause");
                break;
        }

    } while(opcion != 6);
    return 1;
}

