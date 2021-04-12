/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 6
Archivo: FExploracion.hpp
Descripción: Clase abstracta Funcion Exploracion
*/
#pragma once

template <class Clave>
class FuncionExploracion {
   public:
    FuncionExploracion(){};
    ~FuncionExploracion(){};
    virtual int operator()(Clave&, unsigned) const = 0;
};