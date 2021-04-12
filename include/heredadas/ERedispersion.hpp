/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 3
Archivo: mfinito.hpp
Descripción: Clase ERedispersion
*/
#pragma once

#include <abstractas/FExploracion.hpp>

template <class Clave>
class ERedispersion : public FuncionExploracion<Clave> {
   private:
    int nDatos_;

   public:
    ERedispersion(int);
    ~ERedispersion(){};
    int operator()(Clave&, unsigned) const;
};

template <class Clave>
ERedispersion<Clave>::ERedispersion(int nDatos) : nDatos_(nDatos) {}

template <class Clave>
int ERedispersion<Clave>::operator()(Clave& c, unsigned i) const {
    int valor;
    srand(c);
    for (int x = 0; x < int(i); x++)
        valor = rand();
    return valor;
}
