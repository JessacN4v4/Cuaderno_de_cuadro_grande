#ifndef YATE_H
#define YATE_H
#include "barco.h"

/*Creacion de la subclase yate, que hereda los atributos de la clase barco*/
class Yate : public Barco {
public:
    Yate(string nombre);/*Constructor de yate*/
};
/*Se llama al constructor de la clase barco y se le asignan valores
especificos a la clase hija yate*/
Yate::Yate(string nombre) : Barco(nombre, 15, 1700, 10000) {}

#endif
