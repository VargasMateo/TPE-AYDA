#include "LISTA.h"
#include <string>


template <typename T>
LISTA<T>::LISTA()
{
    primero = NULL;
}

template <typename T>
void LISTA<T>::agregar_inicio(const T & elemento)
{
    Nodo* punteroAux = new Nodo;
    punteroAux -> elemento = elemento;
    punteroAux->siguiente = NULL;

    Nodo * aux1 = primero;

    if (primero == aux1){
        primero = punteroAux;
        punteroAux->siguiente = aux1;
    }

}

template <typename T>
void LISTA<T>::agregar_final(const T & elemento)
{
    Nodo* punteroAux = new Nodo;
    punteroAux -> elemento = elemento;
    punteroAux->siguiente = NULL;

    if (primero == NULL)
        primero = punteroAux;
    else
    {
        Nodo* siguienteAux = primero;
        while (siguienteAux->siguiente != NULL)
        {
            siguienteAux = siguienteAux->siguiente;
        }
        siguienteAux->siguiente = punteroAux;
    }

}


template <typename T>
void LISTA<T>::agregar_arbitriario(const T & elemento, int pos)
{
    int cont = 1;
    insertar_arbitrario(primero, pos, cont, elemento);

}


template <typename T>
void LISTA<T>::insertar_arbitrario(Nodo *&primero, int pos,int cont,const T & elemento)
{
if((primero==NULL)||(pos==cont))
    primero->elemento=elemento;
else
    insertar_arbitrario(primero->siguiente,pos,cont+1,elemento);
}

template <typename T>
int LISTA<T>::longitud()
{
    int contador = 0;
    Nodo * puntero = primero;
    while(puntero != NULL)
    {
        contador++;
        puntero = puntero->siguiente;
    }
    return contador;
}

/*
template <typename T>
bool LISTA<T>::pertenece(const T & elemento)
{
    bool resultado = false;
    Nodo * puntero = primero;

    while ((puntero != NULL) && (puntero->elemento != elemento))
    {
        puntero = puntero ->siguiente;
        resultado = false;
    }

    if (puntero != NULL) {
        resultado = true;
    }

    return resultado;
}
*/

template <typename T>
bool LISTA<T>::es_vacia()
{
    bool resultado = true;
    Nodo * puntero = primero;

    if (primero != NULL)
    {
        resultado = false;
    }

    return resultado;
}

/*
template <typename T>
void LISTA<T>::eliminar(const T & elemento)
{
    if (pertenece(elemento) == true)
        eliminar_elemento(primero, elemento);
}


template <typename T>
void LISTA<T>::eliminar_elemento(Nodo *& primero, const T & elemento)
{

    if (primero->elemento == elemento) {
            Nodo * borrar = primero;
            primero = primero->siguiente;
            delete(borrar);
        }
    else
        eliminar_elemento(primero->siguiente, elemento);
}
*/

template <typename T>
void LISTA<T>::mostrar_lista()
{
    Nodo * cursor = primero;

    while(cursor != NULL)
    {
        cout << cursor->elemento << endl;
        cursor = cursor->siguiente;
    }
}


template <typename T>
T LISTA<T>::consultar_proximo()
{
    if (primero != NULL){
        return primero->elemento;
    }
    else
        cout << "la fila no tiene elementos" << endl;
}

template <typename T>
T LISTA<T>::consultar_arbitriario(int pos)
{
    int cont = 1;
    return consultar_en_pos(primero, pos, cont);
}



template <typename T>
T LISTA<T>::consultar_en_pos(Nodo * primero, int pos, int cont)
{
    if (pos == cont)
        return primero->elemento;
    else
        return consultar_en_pos(primero->siguiente, pos, cont + 1);
}


template <typename T>
void LISTA<T>::vaciar()
{
    Nodo * borrar;
    while(primero!=NULL)
    {
        borrar = primero;
        primero = primero->siguiente;
        delete(borrar);
    }
}

template class LISTA<std::string>;
template class LISTA<int>;
template class LISTA<CLIENTE>;

