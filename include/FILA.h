#ifndef FILA_H
#define FILA_H
#include <iostream>

using namespace std;
template<typename T>
class FILA
{
    public:
        FILA();
        ~FILA();
        void agregar_fila(const T & elemento);
        void retirar_proximo();
        T consultar_proximo();
        int cantidad_elementos();
        bool es_vacia();
        void mostrar_fila();
        T consultar_arbitriario(int pos);
        void retirar_arbitriario(int pos);


    private:
        struct Nodo
    {
        T elemento;
        Nodo* siguiente;
    };

    Nodo* primero;

    T consultar_en_pos(Nodo * primero, int pos, int cont);

};

#endif // FILA_H
