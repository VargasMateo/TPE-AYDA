#include "FILA.h"

template<typename T>
FILA<T>::FILA()
{
    primero = NULL; //ctor
}

template<typename T>
FILA<T>::~FILA()
{
    //dtor
}


template <typename T>
void FILA<T>::agregar_fila(const T & elemento)
{
    Nodo* nuevo = new Nodo;
    nuevo -> elemento = elemento;
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

template <typename T>
void FILA<T>::retirar_proximo()
{

    Nodo * borrar = primero;

    if (primero != NULL) {
        primero = primero->siguiente;
        delete(borrar);
    }
}


template <typename T>
T FILA<T>::consultar_proximo()
{
    if (primero != NULL){
        return primero->elemento;
    }
    else
        cout << "la fila no tiene elementos" << endl;
}


template <typename T>
int FILA<T>::cantidad_elementos()
{
    int contador = 0;
    Nodo * cursor = primero;

    while (cursor != NULL){
        cursor = cursor->siguiente;
        contador ++;
    }

    return contador;
}


template <typename T>
bool FILA<T>::es_vacia()
{
    bool resultado = true;

    if (primero != NULL)
    {
        resultado = false;
    }

    return resultado;
}

template <typename T>
void FILA<T>::mostrar_fila()
{
    int contador = 1;
    Nodo * cursor = primero;
    while(cursor != NULL)
    {
        cout << "cliente: "<< contador << endl;
        cout << cursor->elemento << endl;
        cursor = cursor->siguiente;
        contador ++;
    }
}


template <typename T>
T FILA<T>::consultar_arbitriario(int pos)
{
    int cont = 1;
    return consultar_en_pos(primero, pos, cont);
}



template <typename T>
T FILA<T>::consultar_en_pos(Nodo * primero, int pos, int cont)
{
    if (pos == cont)
        return primero->elemento;
    else
        return consultar_en_pos(primero->siguiente, pos, cont + 1);
}



template <typename T>
void FILA<T>::retirar_arbitriario(int pos)
{
    int cont = 1;

    if (primero != NULL) {
        Nodo * aux = primero;
        if (cont == pos) {
            primero = primero->siguiente;
            delete aux;
        }
        else {
            while (aux->siguiente != NULL && (cont + 1) != pos) {
                aux = aux->siguiente;
            }
            if (aux->siguiente != NULL && (cont + 1) == pos) {
                Nodo * aEliminar = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete aEliminar;
            }
        }
    }
}

template class FILA<std::string>;
template class FILA<int>;

#include "CLIENTE.h"
template class FILA<CLIENTE>;
