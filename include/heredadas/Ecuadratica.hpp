/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 3
Archivo: mfinito.hpp
Descripción: Clase ECuadratica
*/
#pragma once

#include <abstractas/FExploracion.hpp>

template <class Clave>
class ECuadratica : public FuncionExploracion<Clave> {
   private:
    int nDatos_;

   public:
    ECuadratica(int);
    ~ECuadratica(){};
    int operator()(Clave&, unsigned) const;
};

template <class Clave>
ECuadratica<Clave>::ECuadratica(int nDatos) : nDatos_(nDatos) {}

template <class Clave>
int ECuadratica<Clave>::operator()(Clave& c, unsigned i) const {
    return (i * i);
}
