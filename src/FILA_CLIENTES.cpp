#include "FILA_CLIENTES.h"

FILA_CLIENTES::FILA_CLIENTES()
{
    primero = NULL; //ctor
}

FILA_CLIENTES::~FILA_CLIENTES()
{
    //dtor
}

void FILA_CLIENTES::agregar_fila(CLIENTE & datos)
{
    Nodo * nuevo = new Nodo;
    nuevo-> datos = datos;
    nuevo->siguiente = NULL;

    if (primero == NULL)
        primero = nuevo;
    else
    {
        Nodo* siguienteAux = primero;
        while (siguienteAux->siguiente != NULL)
        {
            siguienteAux = siguienteAux->siguiente;
        }
        siguienteAux->siguiente = nuevo;
    }

}

void FILA_CLIENTES::retirar_proximo()
{

    Nodo * borrar = primero;

    if (primero != NULL) {
        primero = primero->siguiente;
        delete(borrar);
    }
}

void FILA_CLIENTES::consultar_proximo()
{
    if (primero != NULL){
        cout << "el proximo elemento a retirar es: " << primero->datos.obtener_nombre() << endl;
    }
    else
        cout << "la fila no tiene elementos" << endl;
}

int FILA_CLIENTES::cantidad_elementos()
{
    int contador = 0;
    Nodo * cursor = primero;

    while (cursor != NULL){
        cursor = cursor->siguiente;
        contador ++;
    }

    return contador;
}

bool FILA_CLIENTES::es_vacia()
{
    bool resultado = true;
    Nodo * puntero = primero;

    if (primero != NULL)
    {
        resultado = false;
    }

    return resultado;
}

void FILA_CLIENTES::mostrar_fila()
{
    int contador = 1;
    Nodo * cursor = primero;
    while(cursor != NULL)
    {
        cout << "cliente " << contador << ": " << endl;
        cout << cursor->datos.obtener_nombre() << endl;
        cout << cursor->datos.obtener_edad() << endl;
        cout << cursor->datos.obtener_operacion() << endl;
        cout << cursor->datos.obtener_destinatario() << endl;
        cout << cursor->datos.obtener_monto() << endl;
        cout << cursor->datos.obtener_es_cliente() << endl;
        contador ++;
        cursor = cursor ->siguiente;
    }
}
