#ifndef SERVICIO_2_H_INCLUDED
#define SERVICIO_2_H_INCLUDED
#include "servicio_3.h"

void atender_cliente(info_arreglo arreglo_colas[], LISTA<CLIENTE> *& atendidos) {

    int valor = 0;

    if ((cola_abierta(arreglo_colas, 1) == true) || (cola_abierta(arreglo_colas, 2) == true)) {
        if (arreglo_colas[0].fila->cantidad_elementos() > 0) {
            cout << "que cola desea atender?" << endl;
            cout << "0 para fila default" << endl;
        }

    }

    if (cola_abierta(arreglo_colas, 1) == true)
        if (arreglo_colas[1].fila->cantidad_elementos() > 0)
            cout << "1 para el siguiente criterio: " << arreglo_colas[1].criterio1 << ", " << arreglo_colas[1].criterio2 << endl;

    if (cola_abierta(arreglo_colas, 2) == true)
        if (arreglo_colas[2].fila->cantidad_elementos() > 0)
            cout << "2 para el siguiente criterio: " << arreglo_colas[2].criterio1 << ", " << arreglo_colas[2].criterio2 << endl;

    if ((cola_abierta(arreglo_colas, 1) == true) || (cola_abierta(arreglo_colas, 2) == true)) {
         if ((arreglo_colas[1].fila->cantidad_elementos() > 0) || (arreglo_colas[2].fila->cantidad_elementos() > 0) || (arreglo_colas[0].fila->cantidad_elementos() > 0)) {
            cin >> valor;
            CLIENTE datos = arreglo_colas[valor].fila->consultar_proximo();
            cout << "nombre: " << datos.obtener_nombre() << endl;
            cout << "edad: " << datos.obtener_edad() << endl;
            cout << "operacion realizada: " << datos.obtener_operacion() << endl;
            cout << "destinatario: " << datos.obtener_destinatario() << endl;
            cout << "monto: " << datos.obtener_monto() << endl;
            arreglo_colas[valor].fila->retirar_proximo();
            atendidos->agregar_final(datos);
         }
          else {
            cout << "no hay clientes por atender" << endl;
          }
        } else {
            if (arreglo_colas[0].fila->cantidad_elementos() > 0) {
                CLIENTE datos = arreglo_colas[0].fila->consultar_proximo();
                cout << "nombre: " << datos.obtener_nombre() << endl;
                cout << "edad: " << datos.obtener_edad() << endl;
                cout << "operacion realizada: " << datos.obtener_operacion() << endl;
                cout << "destinatario: " << datos.obtener_destinatario() << endl;
                cout << "monto: " << datos.obtener_monto() << endl;
                arreglo_colas[valor].fila->retirar_proximo();
                atendidos->agregar_final(datos);
            } else {cout << "no hay clientes por atender" << endl;}

        }

}

#endif // SERVICIO_2_H_INCLUDED
