#ifndef BARCO_H
#define BARCO_H
/*Clase Barco, esta es una clase padre para las clases
ferry, yate y crucero*/
#include <string>
using namespace std;

/*Inicio de la clase barco, utilize "protected" ya que quiero que
se pueda acceder a las variables desde otra clase*/
class Barco {      
protected: 
    string nombre;
    int capacidad;
    int precio_boleto;
    int costo_mantenimiento;

/* Coloque el constructor, seguido de los getters para obtener las
variables, omiti los setters ya que no quiero modificar mas adelante
estas variables*/
public:
    Barco(string nom, int cap, int prb, int cmant);
    string get_nombre() const;
    int get_capacidad() const;
    int get_p_boleto() const;
    int get_cst_mantenimiento() const;
};

Barco::Barco(string nom, int cap, int prb, int cmant){
nombre = nom; 
capacidad = cap; 
precio_boleto = prb;
costo_mantenimiento = cmant; {}
}
string Barco::get_nombre() const {
    return nombre;
}

int Barco::get_capacidad() const {
    return capacidad;
}

int Barco::get_p_boleto() const {
    return precio_boleto;
}

int Barco::get_cst_mantenimiento() const {
    return costo_mantenimiento;
}

#endif
