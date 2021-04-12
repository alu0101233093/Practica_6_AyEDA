/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 5
Archivo: FPseudoaleatoria.hpp
Descripción: Clase heredada de FuncionDispersion FPseudoaleatoria
*/
#pragma once

#include <abstractas/FuncionDispersion.hpp>
#include <cstdlib>

template <class Clave>
class FPseudoaleatoria : public FuncionDispersion<Clave> {
   private:
    int nDatos_;

   public:
    FPseudoaleatoria(int);
    ~FPseudoaleatoria(){};
    int operator()(Clave&);
};

template <class Clave>
FPseudoaleatoria<Clave>::FPseudoaleatoria(int nDatos) : nDatos_(nDatos) {}

template <class Clave>
int FPseudoaleatoria<Clave>::operator()(Clave& c) {
    srand(c);
    return rand() % nDatos_;
}
