#include "iostream"

using namespace std;

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
        cout << "| 2) Agregar una Clase     |" << endl;
        cout << "| 3) Agregar Inscripcion   |" << endl;
        cout << "| 4) Eliminar Inscripcion  |" << endl;
        cout << "| 5) Salir.                |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        
        switch (opcion)
        {
            case 1:
                system("clear");
                cout << "+-----------------------+" << endl;
                cout << "|  1. Agregar un Socio  |" << endl;
                cout << "+-----------------------+" << endl;
                // Funcion para agregar el socio
                system("sleep 5");
                break;
            
            case 2:
                system("clear");
                cout << "+------------------------+" << endl;
                cout << "|  2. Agregar una Clase  |" << endl;
                cout << "+------------------------+" << endl;
                // Funcion para agregar una Clase
                system("sleep 5");
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
                cout << "+---------------------------+" << endl;
                cout << "|  4. Eliminar Inscripcion  |" << endl;
                cout << "+---------------------------+" << endl;
                // Funcion para agregar un nueva Inscripción
                system("sleep 5");
                break;
            case 5:
                system("clear");
                cout << "+------------+" << endl;
                cout << "|  5. Salir  |" << endl;
                cout << "+------------+" << endl;
                break;
            default:
                cout << "+---------------------------------------+" << endl;
                cout << "|           Opcion Incorrecta           |" << endl;
                cout << "+---------------------------------------+" << endl;
                system("pause");
                break;
        }

    } while(opcion != 5);
    return 1;
}