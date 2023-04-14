#include "iostream"
#include "DtSocio.h"
#include "Socio.h"
#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "DtClase.h"
#include "DtEntrenamiento.h"
#include "DtSpinning.h"
#include "Inscripcion.h"
#include <typeinfo>
#include <string.h>

//Constantes de los arreglos
#define MAX_SOCIOS 20
#define MAX_CLASES 20

using namespace std;

//Colecciones Globales
struct Socios
{
    Socio* s[MAX_SOCIOS];
    int tope = 0;
} colSocios;

struct Clases
{
    Clase* c[MAX_CLASES];
    int tope = 0;
} colClases;

int TSistema =  3;

void agregarSocio(string ci, string nombre);
void menuAgregarSocio();
void menuListarSocios();
void ListarSocios();
void agregarClase(DtClase & clase);
void menuAgregarClase();
void menuListarClases();
void ListadoClases();
void agregarInscripcion(string ciSocio, int idClase, Fecha fecha);
void menuAgregarInsc();
void menuListarInsc();
void ListadoInsc(string ci);
void borrarInscripcion(string ciSocio, int idClase);
void menuBorrarInscripcion();
void Pause();
void limpiar();

void limpiar(){
    if (TSistema == 0){ //linux
       system("clear");
    }else{
        system("cls");
    }
}
void menuAgregarSocio(){
    limpiar();
    cout << "+-----------------------+" << endl;
    cout << "|  1. Agregar un Socio  |" << endl;
    cout << "+-----------------------+" << endl;
    // Funcion para agregar el socio
    string ci, nombre;
    cout << "Ingrese el nombre del Socio: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese la Cedula del Socio: ";    
    cin >> ci;
    
    try
    {        
        agregarSocio(ci, nombre);
        cout << "Socio agregado correctamente!" << endl;
        Pause();
    }
    catch(invalid_argument& e)
    {
        cout << e.what() << endl;
        Pause();
    }
}

void menuListarSocios(){
   limpiar();
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
        Pause();
    }
    
}

void Pause(){
    if(TSistema == 0){
        string y;
        cout << endl;
        cout << "Presione una tecla para continuar . . . ";
        cin >> y;
    }else
        system("pause");
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
        Pause();
    }
    else{
        throw invalid_argument("No hay socios para listar!!\n");
    }
        
        
      
}

//Función para agregar un nuevo Socio al sistema, tomando como parametros el Nombre y CI
void agregarSocio(string ci, string nombre){
    int i = 0;
    //Recorro la estructura de socios para ver que no existan dos iguales
    while (i<colSocios.tope && colSocios.s[i]->getCI() != ci)
    {
        i++;
    }
    //Si llego al final de la estructura creo un nuevo Socio
    if(i == colSocios.tope){
        Socio * s = new Socio(ci,nombre);
        colSocios.s[colSocios.tope] = s;
        colSocios.tope++;
    }
    else{
        throw invalid_argument("Ya existe un Socio con ese nombre\n");
    }
    
}

void menuAgregarClase(){
   limpiar();
    cout << "+--------------------+" << endl;
    cout << "|  3. Agregar Clase  |" << endl;
    cout << "+--------------------+" << endl;
    // Funcion para agregar un nueva Clase
    try
    {
        string idC;
        int id, turno, tipo, cntB, enR;
        bool enRambla;
        string nombre;
        Turno t;
        /* code */
        cout << "Id de la Clase: ";
        cin >> idC;
        id = stoi(idC);
        cout << "Nombre de la Clase: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Turno?\n1.Manana\n2.Tarde\n3.Noche\nOPCION: ";
        cin >> turno;

        switch (turno)
        {
            case 1:
                t = MANANA;
                break;
        
            case 2:
                t = TARDE;
                break;
            case 3:
                t = NOCHE;
                break;
        }

        cout << "Tipo?\n1.Spinning\n2.Entrenamiento\nOPCION: ";
        cin >> tipo;
        DtSpinning sp;
        DtEntrenamiento en;
        switch (tipo)
        {
            case 1:
                cout << "Cantidad de Bicicletas: ";
                cin >> cntB;
                if(cntB > 50){
                    throw invalid_argument("La cantidad de bicicletas debe ser a lo sumo 50!\n");
                }
                sp = DtSpinning(id,nombre,t,cntB);
                agregarClase(sp);
                break;
            case 2:
                cout << "Es en Rambla? Si = 1 o No = 2: ";
                cin >> enR;
                if(enR == 1){
                    enRambla = true;
                }
                else if(enR == 2){
                    enRambla = false;
                }
                else{
                    throw invalid_argument("Opcion no valida!\n");
                }
                en = DtEntrenamiento(id,nombre,t,enRambla);
                agregarClase(en);
        }
        cout << "Clase agregada correctamente !!" << endl;
        cout << endl;
        Pause();
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        Pause();
    }
    catch(out_of_range& e){
        cout << "Fuera de rango" << endl;
        Pause();
    }
}

void agregarClase(DtClase& clase){
    try
    {
        int i = 0;
        DtSpinning& sp = dynamic_cast<DtSpinning&>(clase);
        while (i < colClases.tope && colClases.c[i]->getId() != sp.getId())
        {
            i++;
        }
        if(i == colClases.tope){

            Spinning* spinning = new Spinning(sp.getId(),sp.getNombre(),sp.getTurno(),sp.getCantBic());
            colClases.c[colClases.tope]=spinning;
            colClases.tope++;
        }
        else{
            throw invalid_argument("Ya existe una clase Spinning con ese ID!\n");
        }
    }
    catch(bad_cast)
    {
        try{
            int i = 0;
            DtEntrenamiento& en = dynamic_cast<DtEntrenamiento&>(clase);
            while (i < colClases.tope && colClases.c[i]->getId() != en.getId())
            {
                i++;
            }
            if(i == colClases.tope){
                Entrenamiento* entrenamiento= new Entrenamiento(en.getId(),en.getNombre(),en.getTurno(),en.getEnRambla());
                colClases.c[colClases.tope]=entrenamiento;
                colClases.tope++;
            }
            else{
                throw invalid_argument("Ya existe una clase Entrenamiento con ese ID!\n");
            }
        } catch(bad_cast){}
    }
    
}


void menuListarClases(){
   limpiar();
    cout << "+------------------------+" << endl;
    cout << "|  4. Listar las Clases  |" << endl;
    cout << "+------------------------+" << endl;
    // Funcion para listar
    try
    {
        ListadoClases();
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
        Pause();
    }
    
}

void ListadoClases(){
    if(colClases.tope != 0){
        for (int i = 0; i < colClases.tope; i++)
        {
            cout << "+---------Clase " << i << "--------+" << endl;
            if(Spinning* sp = dynamic_cast<Spinning*>(colClases.c[i])){
                cout << "Id Clase: " << sp->getId() << endl;
                cout << "Nombre Clase: " << sp->getNombre() << endl;
                if(sp->getTurno() == MANANA){
                    cout << "Turno Clase: MANANA" << endl; 
                } else if(sp->getTurno() == TARDE){
                    cout << "Turno Clase: TARDE" << endl;
                }
                else{
                    cout << "Turno Clase: NOCHE" << endl;
                }
                cout << "Tipo: Spinning" << endl;
                cout << "Cupo: " << sp->cupo() << endl;
            }
            else if(Entrenamiento* en = dynamic_cast<Entrenamiento*>(colClases.c[i])){
                cout << "Id Clase: " << en->getId() << endl;
                cout << "Nombre Clase: " << en->getNombre() << endl;
                if(en->getTurno() == MANANA){
                    cout << "Turno Clase: MANANA" << endl; 
                } else if(en->getTurno() == TARDE){
                    cout << "Turno Clase: TARDE" << endl;
                }
                else{
                    cout << "Turno Clase: NOCHE" << endl;
                }
                cout << "Tipo: Entrenamiento" << endl;
                cout << "Cupo: " << en->cupo() << endl;
            }
        }
        cout << endl;
        Pause();
        
    }
    else{
        throw invalid_argument("No hay Clases para listar!\n");
    }
}

void menuAgregarInsc(){
   limpiar();
    cout << "+--------------------------+" << endl;
    cout << "|  5. Agregar Inscripcion  |" << endl;
    cout << "+--------------------------+" << endl;
    // Funcion para agregar un nueva Inscripción
    string ci;
    string idC, diaC, mesC, anioC;
    int id, dia, mes, anio;
    Fecha f;
    cout << "Ingrese la cedula del socio: ";
    cin >> ci;
    cout << "Ingrese el Id de la clase: ";
    cin >> idC;
    cout << "Ingrese el dia de la inscipcion: ";
    cin >> diaC;
    cout << "Ingrese el mes de la inscipcion: ";
    cin >> mesC;
    cout << "Ingrese el anio de la inscipcion: ";
    cin >> anioC;
    try
    {
        id = stoi(idC);
        dia = stoi(diaC);
        mes = stoi(mesC);
        anio = stoi(anioC);
    }
    catch(invalid_argument& e)
    {
        cout << "Ingrese solo numeros" << endl;
        Pause();
    }
    catch(out_of_range& e)
    {
        cout << "Fuera de rango" << endl;
        Pause();
    }   
    try
    {
        f = Fecha(dia, mes, anio);
        agregarInscripcion(ci,id,f);
    }
    catch(invalid_argument& e)
    {
        cout << e.what() << endl;
        Pause();
    }

}

void agregarInscripcion(string ciSocio, int idClase, Fecha fecha){
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCI() != ciSocio)
    {
        i++;
    }
    int j = 0;
    while (j < colClases.tope && colClases.c[j]->getId() != idClase)
    {
        j++;
    }

    //Si i = al tope de la coleccion de socios, no existe ese socio
    if(i == colSocios.tope && j == colClases.tope){
        throw invalid_argument("No existen la clase ni el socio indicados!!\n");
    }
    else if(i == colSocios.tope){
        throw invalid_argument("No existe el socio con la cedula indicada!!\n");
    }
    else if(j == colClases.tope){
        throw invalid_argument("No existe la clase con el id indicado!!\n");
    }
    else if(colSocios.s[i]->existeInscripcion(idClase)){
        throw invalid_argument("Este socio ya esta inscripto en esa clase!!\n");
    }
    else{

        // Chequear si la clase tiene cupos 
        if(colClases.c[j]->cupo() > 0){
            colClases.c[j]->agregarSocio();
            Inscripcion * insc = new Inscripcion(fecha, colClases.c[j]);
            colSocios.s[i]->agregarInscripcion(insc);
            cout << "Inscripcion agregada correctamente" << endl;
            cout << "Fecha de la inscripcion: ";
            insc->getFecha().toString();
            cout << endl;
            Pause();
        }
        else{
            throw invalid_argument("No hay mas cupos disponibles para esta clase :(");
        }
    }
}

void menuListarInsc(){
   limpiar();
    cout << "+---------------------------+" << endl;
    cout << "|  6. Listar Inscripciones  |" << endl;
    cout << "+---------------------------+" << endl;
    
    string ci;
    cout << "Ingrese la Cedula de Socio: ";
    cin >> ci;
    cout << endl;
    try
    {
        ListadoInsc(ci);
    }
    catch(invalid_argument & e)
    {
        cout << e.what() << endl;
        Pause();
    }
    
    
}

void ListadoInsc(string ci){
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCI() != ci)
    {
        i++;
    }
    if(i == colSocios.tope){
        throw invalid_argument("El Socio indicado no existe!!\n");
    }
    else{

        colSocios.s[i]->imprimirInscr();
        cout << endl;
        Pause();
    }
    
    
}

void menuBorrarInscripcion(){
   limpiar();
    cout << "+---------------------------+" << endl;
    cout << "|  7. Eliminar Inscripcion  |" << endl;
    cout << "+---------------------------+" << endl;
    // Funcion para eliminar una Inscripción
    string op;
    cout << "Desea eliminar una inscripcion ? Si = 1 No = 2: ";
    cin >> op;

    if(op == "1"){
        string ci, idC;
        int id;
        cout << "Ingrese la CI del Socio: ";
        cin >> ci;
        cout << endl;
        cout << "Ingrese la ID de la Clase: ";
        cin >> idC;
        cout << endl;

        try
        {
            id = stoi(idC);
            borrarInscripcion(ci,id);
        }
        catch(invalid_argument& e)
        {
            cout << e.what() << endl;
            Pause();
        }
        catch(out_of_range & e){
            cout << e.what() << endl;
            Pause();
        }
    }
    else if(op == "2"){
        cout << "Entonces se equivoco de opcion :(" << endl;
        Pause();
    }
    else{
        cout << "Opciones validas: 1 o 2" << endl;
        Pause();
    }
    

}

void borrarInscripcion(string ciSocio, int idClase){
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCI() != ciSocio)
    {
        i++;
    }

    int j = 0;
    while (j < colClases.tope && colClases.c[j]->getId() != idClase)
    {
        j++;
    }
    
    if(i == colSocios.tope && j == colClases.tope){
        throw invalid_argument("No existen la clase ni el socio indicados!!\n");
    }
    else if(i == colSocios.tope){
        throw invalid_argument("No existe el socio con la cedula indicada!!\n");
    }
    else if(j == colClases.tope){
        throw invalid_argument("No existe la clase con el id indicado!!\n");
    }
    else if(!colSocios.s[i]->existeInscripcion(idClase)){
        throw invalid_argument("Este socio no esta inscripto en esa clase!!\n");
    }
    else{
        colClases.c[j]->eliminarSocio();
        colSocios.s[i]->eliminarInscripcion(idClase);
        cout << "Inscripcion eliminada correctamente" << endl;
        cout << endl;
        Pause();
    }
    
}

int main(){
    string t;
    cout << "+-----------------------+" << endl;
    cout << "| Bienvenido al sistema |" << endl;
    cout << "+-----------------------+" << endl;

    do{
        cout << "+-----------------------------+" << endl;
        cout << "| Dinos tu Sistema Operativo: |" << endl;
        cout << "|  1 - Linux     2 - Windows  |" << endl;
        cout << "+-----------------------------+" << endl;
        cout << "OPCION: ";
        cin >> t;
        try
        {
            int i = stoi(t);
            switch(i){
                case 1:
                    TSistema = 0;
                    break;
                case 2:
                    TSistema = 1;
                    break;

                default:
                    cout << "Opcion no valida!!" << endl;
                    break;
            }
        }
        catch(invalid_argument& e)
        {
            cout << "Solo se permiten numeros" << endl;
            
        }
        catch(out_of_range& e){
            cout << "Int fuera de rango" << endl;
            
        }
        

        
    }while(TSistema == 3);
    
    Pause();
    string opcion;
    int op = 0;
    do{

       limpiar();

        cout << "+--------------------------+" << endl;
        cout << "|   Opciones disponibles   |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "|          SOCIOS          |" << endl;
        cout << "| 1) Agregar un Socio.     |" << endl;
        cout << "| 2) Listar los Socios     |" << endl;
        cout << "|--------------------------|" << endl;
        cout << "|          CLASES          |" << endl;
        cout << "| 3) Agregar una Clase     |" << endl;
        cout << "| 4) Listar las Clases     |" << endl;
        cout << "|--------------------------|" << endl;
        cout << "|      INSCRIPCIONES       |" << endl;
        cout << "| 5) Agregar Inscripcion   |" << endl;
        cout << "| 6) Listar Inscripciones  |" << endl;
        cout << "| 7) Eliminar Inscripcion  |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "| 8) Salir                 |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "OPCION: ";
        cin >> opcion;

        try
        {
            op = stoi(opcion);
            switch (op)
            {
                case 1:
                    menuAgregarSocio();
                    break;
                
                case 2:
                    menuListarSocios();
                    break;
                case 3:
                    menuAgregarClase();
                    break;
                case 4: 
                    menuListarClases();
                    break;
                case 5:
                    menuAgregarInsc();
                    break;
                case 6:
                    menuListarInsc();
                    break;
                case 7:
                    menuBorrarInscripcion();
                    break;
                case 8:
                    limpiar();
                    cout << "+-------------------------+" << endl;
                    cout << "|  8. Programa Terminado  |" << endl;
                    cout << "+-------------------------+" << endl;
                    break;
                default:
                    limpiar();
                    cout << "+---------------------------------------+" << endl;
                    cout << "|           Opcion Incorrecta           |" << endl;
                    cout << "+---------------------------------------+" << endl;
                    op = 0;
                    Pause();
                    break;
            }

        }
        catch(invalid_argument& e)
        {
            limpiar();
            cout << "+------------------------------------+" << endl;
            cout << "|    Solamente se aceptan numeros    |" << endl;
            cout << "+------------------------------------+" << endl;
            op = 0;
            Pause();
        }
        catch(out_of_range& e){
            limpiar();
            cout << "+--------------------------------------+" << endl;
            cout << "|         Valor fuera de rango         |" << endl;
            cout << "+--------------------------------------+" << endl;
            op = 0;
            Pause();
        }

    } while(op != 8);


    return 1;
}

