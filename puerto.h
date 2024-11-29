#ifndef PUERTO_H
#define PUERTO_H
#include "ferry.h"
#include "yate.h"
#include "crucero.h"
#include <string>
using namespace std;


/*Creacion de la clase puerto*/
class Puerto {
/*Asigne arreglos de la cantidad de barcos de cada subclase que el puerto
va a gestionar, asi como funciones que gestionan cada arreglo y devuelven 
cadenas de texto*/
private:
    Ferry ferrys[5];
    Yate yates[3];
    Crucero cruceros[2];
    string gestion_ferrys(int& turistas_ferry, int& ganancias, int& gastos,
                          int& turistas_abordaron);
    string gestion_yates(int& turistas_yate, int& ganancias, int& gastos,
                         int& turistas_abordaron);
    string gestion_crucero(int& turistas_crucero, int& ganancias, int& gastos,
                            int& turistas_abordaron);
/*En la seccion public, solo agregamos el constructor de puerto y una funcion
que calcula las ganancias del dia a dia*/
public:
    Puerto();
    string calculo_ganancias(int turistas_ferry, int turistas_yate,
                             int turistas_crucero);
};

/*Aqui generamos la lista con cada instancia de ferry, yate y crucero*/
Puerto::Puerto(): 
    ferrys{
        Ferry("Ferry: El Nemo"),
        Ferry("Ferry: Casco Azul"),
        Ferry("Ferry: La Sirena"),
        Ferry("Ferry: Galera Antigua"),
        Ferry("Ferry: El Pinto")},
    yates{
        Yate("Yate: Eclipse"),
        Yate("Yate: Rayo del Sol"),
        Yate("Yate: Buque Dorado")},
    cruceros{
        Crucero("Crucero: Oasis Marino"),
        Crucero("Crucero: Flecha Atlantica")} 
{}

/*Funcion que gestiona los ferrys del puerto*/
string Puerto::gestion_ferrys(int& turistas_ferry, int& ganancias, int& gastos,
                              int& turistas_abordaron) {
    string resultado; /*Variable resultado de tipo string*/
    /*Este ciclo itera sobre la cantidad de ferrys en el arreglo y 
    no comienza si no hay turistas*/
    for (int i = 0; i < 5 && turistas_ferry > 0; i++) { 
        /*El condicional verifica que la cantidad de turistas cubre al menos la mitad
        de la capacidad del navio*/
        if (turistas_ferry >= ferrys[i].get_capacidad() / 2) {
            /*Aqui se determina la cantidad de turistas que pueden abordar,
            "min" evalua que cantidad es menor, comparando la capacidad y 
            los turistas en ferry para que no se exceda el limite de capacidad*/
            int abordan = min(turistas_ferry, ferrys[i].get_capacidad());
            /*Actualizacion de ganancias, esto se hace multiplicando la cantidad
            de turistas que abordaron por el precio del boleto*/
            ganancias = ganancias + abordan * ferrys[i].get_p_boleto();
            /*Calculo de los gastos del mantenimiento del barco*/
            gastos = gastos + ferrys[i].get_cst_mantenimiento();
            /*Incrementa el contador de turistas que abordaron el navio*/
            turistas_abordaron = turistas_abordaron + abordan;
            /*Disminuye la cantidad total de turistas que quieren abordar*/
            turistas_ferry = turistas_ferry - abordan;
            /*Agregamos texto de exito mediante la edicion de la variable resultado si el
            navio logra salir del puerto y realizar el viaje*/
            resultado = resultado + ferrys[i].get_nombre() + ": SALIDA EXITOSA con " +
                         to_string(abordan) + " pasajeros.\n";
            /*Agrega texto de fracaso editando la variable resultado si el navio no 
            cumple con las condiciones para salir*/
        } else {
            resultado = resultado + ferrys[i].get_nombre() +
            ": NO LOGRO SALIR debido a que no se cumplio el cupo minimo.\n";
        }
    }/*Regresamos la variable resultado ya modificada con su respectivo mensaje*/
    return resultado;
}

/*Funcion que gestiona los yates del puerto*/
string Puerto::gestion_yates(int& turistas_yate, int& ganancias, int& gastos,
                             int& turistas_abordaron) {
    string resultado;/*Variable resultado de tipo string*/
    /*Este ciclo itera sobre la cantidad de yates en el arreglo y 
    no comienza si no hay turistas*/
    for (int i = 0; i < 3 && turistas_yate > 0; i++) {
        /*Aqui se determina la cantidad de turistas que pueden abordar,
            "min" evalua que cantidad es menor, comparando la capacidad y 
            los turistas en yate para que no se exceda el limite de capacidad*/
        if (turistas_yate >= yates[i].get_capacidad() / 2) {
            int abordan = min(turistas_yate, yates[i].get_capacidad());
            /*Actualizacion de ganancias, esto se hace multiplicando la cantidad
            de turistas que abordaron por el precio del boleto*/
            ganancias = ganancias + abordan * yates[i].get_p_boleto();
            /*Calculo de los gastos del mantenimiento del barco*/
            gastos = gastos + yates[i].get_cst_mantenimiento();
            /*Incrementa el contador de turistas que abordaron el navio*/
            turistas_abordaron = turistas_abordaron + abordan;
            /*Disminuye la cantidad total de turistas que quieren abordar*/
            turistas_yate = turistas_yate - abordan;
            /*Agregamos texto de exito mediante la edicion de la variable resultado si el
            navio logra salir del puerto y realizar el viaje*/
            resultado = resultado + yates[i].get_nombre() + ": SALIDA EXITOSA con " +
                         to_string(abordan) + " pasajeros.\n";
            /*Agrega texto de fracaso editando la variable resultado si el navio no 
            cumple con las condiciones para salir*/
        }else {
            resultado = resultado + yates[i].get_nombre() +
            ": NO LOGRO SALIR debido a que no se cumplio el cupo minimo.\n";
        }
    }/*Regresamos la variable resultado ya modificada con su respectivo mensaje*/
    return resultado;
}


/*Funcion que gestiona los cruceros del puerto*/
string Puerto::gestion_crucero(int& turistas_crucero, int& ganancias,
                                int& gastos, int& turistas_abordaron) {
    string resultado;/*Variable resultado de tipo string*/
    /*Este ciclo itera sobre la cantidad de cruceros en el arreglo y 
    no comienza si no hay turistas*/
    for (int i = 0; i < 2 && turistas_crucero > 0; i++) {
        /*Aqui se determina la cantidad de turistas que pueden abordar,
            "min" evalua que cantidad es menor, comparando la capacidad y 
            los turistas en crucero para que no se exceda el limite de capacidad*/
        if (turistas_crucero >= cruceros[i].get_capacidad() / 2) {
            int abordan = min(turistas_crucero, cruceros[i].get_capacidad());
            /*Actualizacion de ganancias, esto se hace multiplicando la cantidad
            de turistas que abordaron por el precio del boleto*/
            ganancias = ganancias + abordan * cruceros[i].get_p_boleto();
            /*Calculo de los gastos del mantenimiento del barco*/
            gastos =gastos + cruceros[i].get_cst_mantenimiento();
            /*Incrementa el contador de turistas que abordaron el navio*/
            turistas_abordaron =turistas_abordaron + abordan;
            /*Disminuye la cantidad total de turistas que quieren abordar*/
            turistas_crucero = turistas_crucero - abordan;
            /*Agregamos texto de exito mediante la edicion de la variable resultado si el
            navio logra salir del puerto y realizar el viaje*/
            resultado = resultado + cruceros[i].get_nombre() + ": SALIDA EXITOSA con " +
                         to_string(abordan) + " pasajeros.\n";
            /*Agrega texto de fracaso editando la variable resultado si el navio no 
            cumple con las condiciones para salir*/
        }else {
            resultado = resultado + cruceros[i].get_nombre() +
            ": NO LOGRO SALIR debido a que no se cumplio el cupo minimo.\n";
        }
    }/*Regresamos la variable resultado ya modificada con su respectivo mensaje*/
    return resultado;
}

/*Funcion para calcular las ganancias finales*/
string Puerto::calculo_ganancias(int turistas_ferry, int turistas_yate,
                                 int turistas_crucero) {
    int ganancias = 0;
    int gastos = 0;
    int turistas_abordaron = 0;
    int turistas_sobrantes = 0;

    string texto_i; /*Creamos la variable de texto_i que va a contener los
    textos para la impresion final*/

    /*Resultados de gestion de ferrys*/
    texto_i = texto_i + gestion_ferrys(turistas_ferry, ganancias, gastos,
                                turistas_abordaron);
    turistas_sobrantes = turistas_sobrantes + turistas_ferry;

    /*Resultados de gestion de yates*/
    texto_i =texto_i + gestion_yates(turistas_yate, ganancias, gastos,
                               turistas_abordaron);
    turistas_sobrantes = turistas_sobrantes + turistas_yate;

    /*Resultados de gestion de cruceros*/
    texto_i = texto_i + gestion_crucero(turistas_crucero, ganancias, gastos,
                                  turistas_abordaron);
    turistas_sobrantes = turistas_sobrantes + turistas_crucero;

    /*Textos finales*/
    texto_i = texto_i + "Ganancias del día: $" + to_string(ganancias) + "\n";
    texto_i = texto_i + "Gastos del día: $" + to_string(gastos) + "\n";
    texto_i = texto_i + "Turistas que abordaron: " + to_string(turistas_abordaron) +
                 "\n";
    texto_i = texto_i + "Hubo " + to_string(turistas_sobrantes) +
                 " turistas que no pudieron abordar debido a la falta de "
                 "capacidad.\n";
    /*Regresa los textos finales para imprimir*/
    return texto_i;
}

#endif
