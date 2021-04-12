/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 3
Archivo: mfinito.hpp
Descripción: Clase FuncionDispersion
*/
#pragma once

template <class Clave>
class FuncionDispersion {
   public:
    FuncionDispersion(){};
    ~FuncionDispersion(){};
    virtual int operator()(Clave&) = 0;
};