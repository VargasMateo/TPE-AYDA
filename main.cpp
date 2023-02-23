#include <iostream>
#include "LISTA.h"
#include "ARBOL.h"
#include "FILA.h"
#include "CLIENTE.h"

#include "servicio_1.h"
#include "servicio_2.h"
#include "servicio_3.h"
#include "servicio_4.h"
#include "servicio_5.h"

using namespace std;


int main()

{

    info_arreglo arreglo_colas[3];
    FILA<CLIENTE> * cola_principal = new FILA<CLIENTE>;
    FILA<CLIENTE> * cola_1_criterio = new FILA<CLIENTE>;
    FILA<CLIENTE> * cola_2_criterio = new FILA<CLIENTE>;
    LISTA<CLIENTE> * atendidos = new LISTA<CLIENTE>;
    LISTA<CLIENTE> * listado_rango = new LISTA<CLIENTE>;
    arreglo_colas[0].fila = cola_principal;
    arreglo_colas[1].fila = cola_1_criterio;
    arreglo_colas[2].fila = cola_2_criterio;


    int valor;


    cout << "BIENVENIDO AL BANCO V&B.inc" << endl;
    cout << "                           " << endl;
    cout << "ingrese segun lo operacion que desea realizar" << endl;
    cout << "1 ingresar nuevo cliente" << endl;
    cout << "2 atender proximo cliente" << endl;
    cout << "3 abrir nueva cola con orden especial" << endl;
    cout << "4 cerrar cola especial" << endl;
    cout << "5 Listar operaciones atendidas según rango de montos" << endl;
    cout << "0 para salir" << endl;
    cin >> valor;
    system("cls");   //borra todo lo de la consola para que quede mas limpio el menu


    while (valor != 0) {
        if (valor == 1) {
            ingresar_nuevo_cliente(arreglo_colas);
        }

        if (valor == 2) {
            atender_cliente(arreglo_colas, atendidos);
        }

        if (valor == 3) {
            if ((cola_abierta(arreglo_colas, 1) == false) || (cola_abierta(arreglo_colas, 2) == false)) {
                nueva_cola_especial(arreglo_colas, cola_1_criterio, cola_2_criterio);
            } else cout << "numero maximo de colas especiales alcanzado." << endl;
        }

        if (valor == 4) {
            cerrar_cola_especial(arreglo_colas);
        }

        if (valor == 5) {
            int piso;
            int techo;
            cout << "ingrese minimo: "; cin >> piso;
            cout << "ingrese maximo: "; cin >> techo;
            if (piso <= techo) {
                 if (atendidos->longitud() > 0) {
                    listar_segun_rango(atendidos, listado_rango, piso, techo);
                    cout << "LISTADO POR RANGO: " << endl;
                    listado_rango->mostrar_lista();
                 }
            } else {
                cout << "ingrese valores apropiados." << endl;
            }
        }

        if (valor > 5) {
            cout << "ingrese una opcion valida" << endl;
        }
        cout << "ingrese segun lo operacion que desea realizar" << endl;
        cout << "1 ingresar nuevo cliente" << endl;
        cout << "2 atender proximo cliente" << endl;
        cout << "3 abrir nueva cola con orden especial" << endl;
        cout << "4 cerrar cola especial" << endl;
        cout << "5 Listar operaciones atendidas según rango de montos" << endl;
        cout << "0 para salir" << endl;
        cin >> valor;
        system("cls");   //borra todo lo de la consola para que quede mas limpio el menu

    }


    delete cola_principal;
    delete cola_1_criterio;
    delete cola_2_criterio;             //LIBERAR MEMORIA
    delete atendidos;
    delete listado_rango;

    return 0;
}
