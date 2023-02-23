#ifndef SERVICIO_4_H_INCLUDED
#define SERVICIO_4_H_INCLUDED
#include "servicio_3.h"

void cerrar_cola_especial(info_arreglo arreglo_colas[]) {

    if (cola_abierta(arreglo_colas, 1) == true) {
        if (arreglo_colas[1].fila->es_vacia() == true) {
            cout << "1 para cerrar la fila con el siguiente criterio: " << arreglo_colas[1].criterio1 << ", " << arreglo_colas[1].criterio2 << endl;
        }
    }

    if (cola_abierta(arreglo_colas, 2) == true) {
        if (arreglo_colas[2].fila->es_vacia() == true) {
            cout << "2 para cerrar la fila con el siguiente criterio: " << arreglo_colas[2].criterio1 << ", " << arreglo_colas[2].criterio2 << endl;
        }
    }

    if ((cola_abierta(arreglo_colas, 1) == true) || (cola_abierta(arreglo_colas, 2) == true)) {
        if ((arreglo_colas[1].fila->es_vacia() == true) || (arreglo_colas[2].fila->es_vacia() == true)) {
            int valor;
            cin >> valor;
            arreglo_colas[valor].fila = NULL;
            arreglo_colas[valor].criterio1 = "CERRADA";
            cout << "se cerro con exito la cola especial " << valor << "." << endl;
    }
    }
}
#endif // SERVICIO_4_H_INCLUDED
