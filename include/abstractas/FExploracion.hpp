/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 3
Archivo: mfinito.hpp
Descripción: Clase FuncionExploracion
*/
#pragma once

template <class Clave>
class FuncionExploracion {
   public:
    FuncionExploracion(){};
    ~FuncionExploracion(){};
    virtual int operator()(Clave&, unsigned) const = 0;
};