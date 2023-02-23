#ifndef LISTA_COLAS_H
#define LISTA_COLAS_H
#include "FILA_CLIENTES.h"
#include <iostream>

using namespace std;
class LISTA_COLAS
{
private:
    struct Nodo
    {
        FILA_CLIENTES * fila;
        string criterio1;
        string criterio2;
        Nodo * siguiente;
    };

    Nodo * primero;
    void insertar_arbitrario(Nodo *& primero, int pos, int cont, const T & elemento);
    void eliminar_elemento(Nodo *& primero, const T & elemento);


public:
    LISTA();
    void agregar_inicio(const T & elemento);
    void agregar_final(const T & elemento);
    void agregar_arbitriario(const T & elemento, int pos);
    int longitud();
    bool pertenece(const T & elemento);
    bool es_vacia();
    void eliminar(const T & elemento);
    //void copia_lista();

    void mostrar_lista();
    void vaciar();

};

#endif // LISTA_COLAS_H
