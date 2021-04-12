/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 5
Archivo: Lista.hpp
Descripción: Clase genérica Lista
*/
#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

template <class Clave>
class Lista {
   private:
    std::vector<Clave*> lista_;
    int nDatos_;

   public:
    Lista(int nDatos = 0) { nDatos_ = nDatos; };
    ~Lista();
    bool Buscar(Clave&) const;
    bool Insertar(Clave&);
    void Imprimir();
};

template <class Clave>
Lista<Clave>::~Lista() {
    for (int i = 0; i < int(lista_.size()); i++) {
        delete lista_[i];
    }
}

template <class Clave>
bool Lista<Clave>::Buscar(Clave& X) const {
    for (int i = 0; i < int(lista_.size()); i++)
        if (*lista_.at(i) == X)
            return true;
    return false;
}

template <class Clave>
bool Lista<Clave>::Insertar(Clave& X) {
    lista_.push_back(new Clave(X));
    nDatos_++;

    if (Buscar(X)) {
        return true;
    } else
        return false;
}

template <class Clave>
void Lista<Clave>::Imprimir() {
    for (int i = 0; i < int(lista_.size()); i++)
        std::cout << *lista_.at(i) << " | ";
}