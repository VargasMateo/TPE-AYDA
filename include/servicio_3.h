#ifndef SERVICIO_3_H_INCLUDED
#define SERVICIO_3_H_INCLUDED

bool cola_abierta(info_arreglo arreglo_colas[], int i) {

    bool resultado = false;

    if ((arreglo_colas[i].criterio1 == "retiro") || (arreglo_colas[i].criterio1 == "deposito") || (arreglo_colas[i].criterio1 == "transferencia") || (arreglo_colas[i].criterio1 == "pago")) {
        resultado = true;
    }

    return resultado;

}


void re_ordenar(info_arreglo arreglo_colas[], string criterio1, bool criterio2, int i) {

        int posicion = 1;
        int longitud = arreglo_colas[0].fila->cantidad_elementos();

        while (posicion <= longitud) {
            CLIENTE datos = arreglo_colas[0].fila->consultar_arbitriario(posicion);
            if ((datos.obtener_operacion() == criterio1) && (datos.obtener_es_cliente() == criterio2)) {
                arreglo_colas[i].fila->agregar_fila(datos);
                arreglo_colas[0].fila->retirar_arbitriario(posicion);
                posicion = 0;
                longitud = arreglo_colas[0].fila->cantidad_elementos();
            }
            posicion ++;
    }
}


void nueva_cola_especial(info_arreglo arreglo_colas[], FILA<CLIENTE> * cola_1_criterio, FILA<CLIENTE> * cola_2_criterio) {

    string criterio1, sn_cliente;
    bool criterio2;
    cout << "ingrese el criterio que desea para la nueva cola" << endl;
    cout << "criterios disponibles..." << endl;
    cout << "para criterio 1 (retiro, deposito, transferencia, pago)" << endl;
    cout << "criterio 1: "; cin >> criterio1;
    cout << "para criterio 2 (si, no) cliente del banco" << endl;
    cout << "criterio 2: "; cin >> sn_cliente;
    if ((sn_cliente == "si") || (sn_cliente == "SI")) {
        criterio2 = true;
    }
    if ((sn_cliente == "no") || (sn_cliente == "NO")) {
        criterio2 = false;
    }

    if (cola_abierta(arreglo_colas, 1) == false) {
        arreglo_colas[1].fila = cola_1_criterio;
        arreglo_colas[1].criterio1 = criterio1;
        arreglo_colas[1].criterio2 = criterio2;
        re_ordenar(arreglo_colas, criterio1, criterio2, 1);
        }
        else {
            arreglo_colas[2].fila = cola_2_criterio;
            arreglo_colas[2].criterio1 = criterio1;
            arreglo_colas[2].criterio2 = criterio2;
            re_ordenar(arreglo_colas, criterio1, criterio2, 2);
            }

}

#endif // SERVICIO_3_H_INCLUDED
