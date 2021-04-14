/*
Autor: Leonardo Alfonso Cruz Rodríguez
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Práctica: 6
Archivo: main.cpp
Descripción: Archivo ejecutable principal
*/

#include <../include/genericas/TablaHash.hpp>

void menuDispersion(FuncionDispersion<int>*);

int main() {
    int nTabla = -1, nSinonimos = -1, funcion = -1, exploracion = -1, opcion = 0, valor = 0, num = 1;
    ;
    do {
        std::cout << "Introduce el tamaño de la tabla: ";
        std::cin >> nTabla;
    } while (nTabla <= 0);

    do {
        std::cout << "Introduce el tamaño de los vectores: ";
        std::cin >> nSinonimos;
    } while (nSinonimos <= 0);

    do {
        std::cout << "Introduce el tipo de funcion (0 = Modulo, 1 = pseudoaleatoria) ";
        std::cin >> funcion;
    } while (funcion != 0 && funcion != 1);

    FuncionDispersion<int>* D;
    switch (funcion) {
        case 0:
            D = new FModulo<int>(nTabla);
            break;
        case 1:
            D = new FPseudoaleatoria<int>(nTabla);
            break;
        default:
            break;
    }

    do {
        std::cout << "Introduce el tipo de exploracion (0 = Lineal, 1 = Cuadratica, 2 = Dispersion doble, 3 = Redispersion) ";
        std::cin >> exploracion;
    } while (exploracion < 0 || exploracion > 3);
    /*
    FuncionExploracion<int>* E;
    FuncionDispersion<int>* ED;
    switch (exploracion) {
        case 0:
            E = new ELineal<int>(nTabla);
            break;
        case 1:
            E = new ECuadratica<int>(nTabla);
            break;
        case 2:
            do {
                std::cout << "Introduce el tipo de dispersion para la exploracion (0 = Modulo, 1 = pseudoaleatoria) ";
                std::cin >> funcion;
            } while (funcion != 0 && funcion != 1);
            if (funcion == 0)
                ED = new FModulo<int>(nTabla);
            else
                ED = new FPseudoaleatoria<int>(nTabla);
            E = new EDobleDispersion<int>(nTabla, ED);
            break;
        case 3:
            E = new ERedispersion<int>(nTabla);
            break;
        default:
            break;
    }*/

    FuncionExploracion<int>* EL = new ELineal<int>(nTabla);
    FuncionExploracion<int>* EC = new ECuadratica<int>(nTabla);
    FuncionExploracion<int>* ED = new EDobleDispersion<int>(nTabla, D);
    FuncionExploracion<int>* ER = new ERedispersion<int>(nTabla);

    TablaHash<int> HEL(nTabla, nSinonimos, D, EL);
    TablaHash<int> HEC(nTabla, nSinonimos, D, EC);
    TablaHash<int> HED(nTabla, nSinonimos, D, ED);
    TablaHash<int> HER(nTabla, nSinonimos, D, ER);

    do {
        std::cout << std::endl;
        std::cout << "--------------- Menu ---------------" << std::endl;
        std::cout << "1. Insertar valor" << std::endl;
        std::cout << "2. Buscar valor" << std::endl;
        std::cout << "3. Imprimir" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "¿Cuantos valores desea insertar?: ";
                std::cin >> num;
                for (int i = 0; i < num; i++) {
                    std::cout << "Introduce el valor: ";
                    std::cin >> valor;
                    std::cout << "--------- Comparaciones ---------" << std::endl;
                    std::cout << "Exploracion Lineal: ";
                    HEL.Insertar(valor);
                    std::cout << "Exploracion Cuadrática: ";
                    HEC.Insertar(valor);
                    std::cout << "Exploracion Dispersion Doble: ";
                    HED.Insertar(valor);
                    std::cout << "Exploracion Redispersion: ";
                    HER.Insertar(valor);
                    std::cout << std::endl;
                }
                break;
            case 2:
                std::cout << "Introduce el valor que desea buscar: ";
                std::cin >> valor;
                switch (exploracion) {
                    case 0:
                        if (HEL.Buscar(valor))
                            std::cout << "El valor " << valor << " está en la tabla." << std::endl;
                        else
                            std::cout << "El valor " << valor << " NO está en la tabla." << std::endl;
                        break;
                    case 2:
                        if (HEC.Buscar(valor))
                            std::cout << "El valor " << valor << " está en la tabla." << std::endl;
                        else
                            std::cout << "El valor " << valor << " NO está en la tabla." << std::endl;
                        break;
                    case 3:
                        if (HED.Buscar(valor))
                            std::cout << "El valor " << valor << " está en la tabla." << std::endl;
                        else
                            std::cout << "El valor " << valor << " NO está en la tabla." << std::endl;
                        break;
                    case 4:
                        if (HER.Buscar(valor))
                            std::cout << "El valor " << valor << " está en la tabla." << std::endl;
                        else
                            std::cout << "El valor " << valor << " NO está en la tabla." << std::endl;
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                switch (exploracion) {
                    case 0:
                        HEL.Imprimir();
                        break;
                    case 1:
                        HEC.Imprimir();
                        break;
                    case 2:
                        HED.Imprimir();
                        break;
                    case 3:
                        HER.Imprimir();
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
        std::cout << std::endl;
    } while (opcion != 4);

    return 0;
}