/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 6
Archivo: ELineal.hpp
Descripción: Clase heredada de FExploracion ELineal
*/
#pragma once

#include <abstractas/FExploracion.hpp>

template <class Clave>
class ELineal : public FuncionExploracion<Clave> {
   private:
    int nDatos_;

   public:
    ELineal(int);
    ~ELineal(){};
    int operator()(Clave&, unsigned) const;
};

template <class Clave>
ELineal<Clave>::ELineal(int nDatos) : nDatos_(nDatos) {}

template <class Clave>
int ELineal<Clave>::operator()(Clave& c, unsigned i) const {
    return i;
}
