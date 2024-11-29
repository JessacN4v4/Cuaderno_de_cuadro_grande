#include <iostream>
#include "puerto.h"
using namespace std;

/*Iniciamos funcion principal*/
int main() {
    /*Declaramos nuestras variables*/
    Puerto puerto;
    int turistas_ferry;
    int turistas_yate;
    int turistas_crucero;

    /*Pedimos las entradas de datos a un usuario y las guardamos en su 
    respectiva variable*/
    cout<<"¿Cuantos turistas quieren abordar un Ferry?: ";
    cin>>turistas_ferry;
    cout<<"¿Cuantos turistas quieren abordar un Yate?: ";
    cin>>turistas_yate; 
    cout<<"¿Cuantos turistas quieren abordar un Crucero?: ";
    cin>>turistas_crucero;

    /*LLamamos a nuestra funcion de calcular ganancias y le damos los datos 
    ingresados por el usuario para que comienze la ejecucion del programa.*/
    string texto_f = puerto.calculo_ganancias(turistas_ferry, turistas_yate, 
    turistas_crucero);
    /*Imprimimos textos finales*/
    cout << texto_f;

    return 0;
}
