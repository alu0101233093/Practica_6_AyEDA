/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 6
Archivo: EDobleDispersion.hpp
Descripción: Clase heredada de FExploracion EDobleDispersion
*/
#pragma once

#include <abstractas/FExploracion.hpp>
#include <heredadas/FModulo.hpp>
#include <heredadas/FPseudoaleatoria.hpp>

template <class Clave>
class EDobleDispersion : public FuncionExploracion<Clave> {
   private:
    int nDatos_;
    FuncionDispersion<Clave>* fd_;

   public:
    EDobleDispersion(int, FuncionDispersion<Clave>*);
    ~EDobleDispersion(){};
    int operator()(Clave&, unsigned) const;
};

template <class Clave>
EDobleDispersion<Clave>::EDobleDispersion(int nDatos, FuncionDispersion<Clave>* fd) : nDatos_(nDatos), fd_(fd) {}

template <class Clave>
int EDobleDispersion<Clave>::operator()(Clave& c, unsigned i) const {
    return (i * (*fd_)(c));
}
