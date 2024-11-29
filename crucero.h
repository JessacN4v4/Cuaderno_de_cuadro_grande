#ifndef CRUCERO_H
#define CRUCERO_H
#include "barco.h"

/*Creacion de la subclase crucero, que hereda los atributos de la clase barco*/
class Crucero : public Barco {
public:
    Crucero(string nombre); /*Constructor de crucero*/
};
/*Se llama al constructor de la clase barco y se le asignan valores
especificos a la clase hija crucero*/
Crucero::Crucero(string nombre) : Barco(nombre, 400, 450, 65000) {}

#endif
