/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 6
Archivo: Vector.hpp
Descripción: Clase genérica Vector
*/
#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

template <class Clave>
class Vector {
   private:
    std::vector<Clave*> Vector_;
    int nDatos_;

   public:
    Vector(int nDatos = 0) { nDatos_ = nDatos; };
    ~Vector();
    bool Buscar(Clave&) const;
    bool Insertar(Clave&);
    bool Lleno();
    void Imprimir();
};

template <class Clave>
Vector<Clave>::~Vector() {
    for (int i = 0; i < int(Vector_.size()); i++) {
        delete Vector_[i];
    }
}

template <class Clave>
bool Vector<Clave>::Buscar(Clave& X) const {
    for (int i = 0; i < int(Vector_.size()); i++)
        if (*Vector_.at(i) == X)
            return true;
    return false;
}

template <class Clave>
bool Vector<Clave>::Insertar(Clave& X) {
    if (!Lleno()) {
        Vector_.push_back(new Clave(X));
        return true;
    } else
        return false;
}

template <class Clave>
bool Vector<Clave>::Lleno() {
    if (int(Vector_.size()) >= nDatos_) {
        return true;
    } else
        return false;
}

template <class Clave>
void Vector<Clave>::Imprimir() {
    for (int i = 0; i < int(Vector_.size()); i++)
        std::cout << *Vector_.at(i) << " | ";
}