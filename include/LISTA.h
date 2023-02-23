#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "CLIENTE.h"

using namespace std;
template<typename T>
class LISTA
{

    public:
    LISTA();
    void agregar_inicio(const T & elemento);
    void agregar_final(const T & elemento);
    void agregar_arbitriario(const T & elemento, int pos);
    int longitud();
    bool pertenece(const T & elemento);
    bool es_vacia();
    void eliminar(const T & elemento);
    T consultar_proximo();
    T consultar_arbitriario(int pos);
    void mostrar_lista();
    void vaciar();

    private:
    struct Nodo
    {
        T elemento;
        Nodo* siguiente;
    };

    Nodo* primero;

    void insertar_arbitrario(Nodo *& primero, int pos, int cont, const T & elemento);
    void eliminar_elemento(Nodo *& primero, const T & elemento);
    T consultar_en_pos(Nodo * primero, int pos, int cont);

};

#endif // LISTA_H

