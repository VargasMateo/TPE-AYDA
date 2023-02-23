#include "ARBOL.h"

template <typename T>
ARBOL<T>::ARBOL()
{
    raiz = NULL;//ctor
}

template <typename T>
ARBOL<T>::~ARBOL()
{
    //dtor
}

/*
template <typename T>
void ARBOL<T>::agregar(const T & elemento)
{
    insertar_ordenado(raiz, elemento);
}


template <typename T>
void ARBOL<T>::insertar_ordenado(Nodo *& raiz, const T & elemento)
{
    if (raiz == NULL)
    {
        Nodo * aux = new Nodo();
        aux->elemento = elemento;
        aux->izq = NULL;
        aux->der = NULL;
        raiz = aux;
    }
    else
        if (raiz->elemento.obtener_monto() > elemento.obtener_monto())
            insertar_ordenado(raiz->izq, elemento);
        else
            insertar_ordenado(raiz->der, elemento);

}
*/

template <typename T>
void ARBOL<T>::mostrar()
{
    mostrar_arbol(raiz);
}

template <typename T>
void ARBOL<T>::mostrar_arbol(Nodo *& raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    else{
        cout << "elemento: " << raiz->elemento << endl;
        mostrar_arbol(raiz->izq);
        mostrar_arbol(raiz->der);
    }

}

/*
template <typename T>
bool ARBOL<T>::pertenece(const T & elemento)
{
    return pertenece_al_arbol(raiz, elemento);
}


template <typename T>
bool ARBOL<T>::pertenece_al_arbol(Nodo *& raiz, const T & elemento)
{
    if (raiz == NULL)
    {
        return false;
    }
    else{
        if (raiz->elemento == elemento)
            return true;
        else {
         if (raiz->elemento > elemento)
            pertenece_al_arbol(raiz->izq, elemento);
         else
            pertenece_al_arbol(raiz->der, elemento);
        }
    }
}
*/

template <typename T>
int ARBOL<T>::cantidad()
{
    int contador = 0;
    cantidad_elementos(raiz, contador);
    return contador;
}

template <typename T>
int ARBOL<T>::cantidad_elementos(Nodo *& raiz, int & contador)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else{
        contador ++;
        cantidad_elementos(raiz->izq, contador);
        cantidad_elementos(raiz->der, contador);
        }
}

template <typename T>
bool ARBOL<T>::vacio()
{
    return es_vacio(raiz);
}


template <typename T>
bool ARBOL<T>::es_vacio(Nodo *& raiz)
{
    bool resultado = false;

    if (raiz == NULL)
    {
        resultado = true;
        return resultado;
    }
    else
        return resultado;
}


template <typename T>
int ARBOL<T>::profundidad()
{
    int nivel = 0;
    profundidad_arbol(raiz, nivel);
}


template <typename T>
int ARBOL<T>::profundidad_arbol(Nodo *& raiz, int nivel)
{
    if (raiz == NULL)
    {
        return nivel;
    }
    else
        {
        profundidad_arbol(raiz->izq, nivel + 1);
        profundidad_arbol(raiz->der, nivel + 1);
        }
}

/*
template <typename T>
LISTA<T> ARBOL<T>::listar_o()
{
    LISTA<T> lista;
    return listar_ordenado(raiz, lista);
}


template <typename T>
LISTA<T> ARBOL<T>::listar_ordenado(Nodo *& raiz, LISTA<T> & lista)
{
    if (raiz == NULL)
    {
        return lista;
    }
    else{
        listar_ordenado(raiz->izq, lista);
        lista.agregar_final(raiz->elemento);
        listar_ordenado(raiz->der, lista);
        }
}


template <typename T>
LISTA<T> ARBOL<T>::listar_f()
{
    LISTA<T> lista;
    return listar_frontera(raiz, lista);
}


template <typename T>
LISTA<T> ARBOL<T>::listar_frontera(Nodo *& raiz, LISTA<T> & lista)
{
    if (raiz == NULL)
    {
        return lista;
    }
    else{
        if ((raiz->izq == NULL) && (raiz->der == NULL))
            lista.agregar_final(raiz->elemento);
        listar_frontera(raiz->izq, lista);
        listar_frontera(raiz->der, lista);
        }
}
*/

template class ARBOL<std::string>;
template class ARBOL<int>;
//template class ARBOL<CLIENTE>;

