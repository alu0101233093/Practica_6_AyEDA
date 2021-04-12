/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 3
Archivo: mfinito.hpp
Descripción: Clase FModulo
*/
#pragma once

#include <abstractas/FuncionDispersion.hpp>

template <class Clave>
class FModulo : public FuncionDispersion<Clave> {
   private:
    int nDatos_;

   public:
    FModulo(int);
    ~FModulo(){};
    int operator()(Clave&);
};

template <class Clave>
FModulo<Clave>::FModulo(int nDatos) : nDatos_(nDatos) {}

template <class Clave>
int FModulo<Clave>::operator()(Clave& c) {
    return c % nDatos_;
}
