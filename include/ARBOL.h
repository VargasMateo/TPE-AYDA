#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include "LISTA.h"
#include "CLIENTE.h"

using namespace std;
template<typename T>

class ARBOL
{
    public:
        ARBOL();
        virtual ~ARBOL();
        void agregar(const T & elemento);
        void mostrar();
        bool pertenece(const T & elemento);
        int cantidad();
        bool vacio();
        int profundidad();
        LISTA<T> listar_o();
        LISTA<T> listar_f();

    private:
        struct Nodo
        {
        T elemento;
        Nodo* izq;
        Nodo* der;
        };

        Nodo * raiz;

        void insertar_ordenado(Nodo *& raiz, const T & elemento);
        void mostrar_arbol(Nodo *& raiz);
        bool pertenece_al_arbol(Nodo *& raiz, const T & elemento);
        int cantidad_elementos(Nodo *& raiz, int & contador);
        bool es_vacio(Nodo *& raiz);
        int profundidad_arbol(Nodo *& raiz, int nivel);
        LISTA<T> listar_ordenado(Nodo *& raiz, LISTA<T> & lista);
        LISTA<T> listar_frontera(Nodo *& raiz, LISTA<T> & lista);

};

#endif // ARBOL_H
