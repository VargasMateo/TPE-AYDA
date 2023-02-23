#ifndef FILA_CLIENTES_H
#define FILA_CLIENTES_H
#include "CLIENTE.h"


class FILA_CLIENTES
{
    public:
        FILA_CLIENTES();
        ~FILA_CLIENTES();

        void agregar_fila(CLIENTE & datos);
        void retirar_proximo();
        void consultar_proximo();
        int cantidad_elementos();
        bool es_vacia();
        void mostrar_fila();


    private:
        struct Nodo
    {
        CLIENTE datos;
        Nodo * siguiente;
    };

    Nodo * primero;
};

#endif // FILA_CLIENTES_H
