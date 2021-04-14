/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 6
Archivo: TablaHash.hpp
Descripción: Clase genérica Tabla Hash
*/
#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <genericas/Lista.hpp>
#include <genericas/Vector.hpp>
#include <heredadas/EDobleDispersion.hpp>
#include <heredadas/ELineal.hpp>
#include <heredadas/ERedispersion.hpp>
#include <heredadas/Ecuadratica.hpp>
#include <heredadas/FModulo.hpp>
#include <heredadas/FPseudoaleatoria.hpp>
#include <iostream>
#include <vector>

template <class Clave>
class TablaHash {
   private:
    std::vector<Vector<Clave>*> vDatos_;
    int nDatos_;      // Tamaño de la tabla
    int nSinonimos_;  // Tamaño de la tabla
    int comparaciones_;
    FuncionDispersion<Clave>* fd_;
    FuncionExploracion<Clave>* fe_;

   public:
    TablaHash(int, int, FuncionDispersion<Clave>*, FuncionExploracion<Clave>*);
    ~TablaHash();
    bool Buscar(Clave&);
    bool Insertar(Clave&);
    void Imprimir();
};

template <class Clave>
TablaHash<Clave>::TablaHash(int nDatos, int nSinonimos, FuncionDispersion<Clave>* fd, FuncionExploracion<Clave>* fe) {
    comparaciones_ = 0;
    nDatos_ = nDatos;
    nSinonimos_ = nSinonimos;
    fd_ = fd;
    fe_ = fe;
    for (int i = 0; i < nDatos_; i++)
        vDatos_.push_back(new Vector<Clave>(nSinonimos));
}

template <class Clave>
TablaHash<Clave>::~TablaHash() {
}

template <class Clave>
bool TablaHash<Clave>::Buscar(Clave& c) {
    for (int i = 0; i < nDatos_; i++) {
        if (vDatos_[i]->Buscar(c))
            return true;
    }
    return false;
}

template <class Clave>
bool TablaHash<Clave>::Insertar(Clave& c) {
    int i = 0, indice;
    bool insertado = false;

    indice = (*fd_)(c);
    insertado = vDatos_[indice]->Insertar(c);
    if (insertado) {
        std::cout << "1" << std::endl;
        comparaciones_ = 0;
        return true;
    }

    comparaciones_ = 1;
    while (!insertado && i <= nDatos_) {
        indice = (((*fd_)(c)) + (*fe_)(c, i)) % nDatos_;
        insertado = vDatos_[indice]->Insertar(c);
        if (insertado) {
            std::cout << comparaciones_ << std::endl;
            comparaciones_ = 0;
            return true;
        }
        i++;
        comparaciones_++;
    }
    //std::cout << "No se ha podido introducir el valor indicado." << std::endl;
    std::cout << comparaciones_ << std::endl;
    comparaciones_ = 0;
    return false;
}

template <class Clave>
void TablaHash<Clave>::Imprimir() {
    for (int i = 0; i < nDatos_; i++) {
        std::cout << "[" << i << "]: ";
        vDatos_[i]->Imprimir();
        std::cout << std::endl;
    }
}