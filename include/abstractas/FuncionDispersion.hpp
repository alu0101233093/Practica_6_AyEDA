/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 6
Archivo: FuncionDispersion.hpp
Descripción: Clase abstracta Funcion Dispersion
*/
#pragma once

template <class Clave>
class FuncionDispersion {
   public:
    FuncionDispersion(){};
    ~FuncionDispersion(){};
    virtual int operator()(Clave&) = 0;
};