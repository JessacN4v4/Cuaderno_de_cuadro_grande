#ifndef FERRY_H
#define FERRY_H
#include "barco.h"

/*Creacion de la subclase ferry, que hereda los atributos de la clase barco*/
class Ferry : public Barco {
public:
    Ferry(string nombre); /*Constructor de ferry*/
};
/*Se llama al constructor de la clase barco y se le asignan valores
especificos a la clase hija ferry*/
Ferry::Ferry(string nombre) : Barco(nombre, 80, 700, 15000) {}

#endif
