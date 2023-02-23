#ifndef SERVICIO_1_H_INCLUDED
#define SERVICIO_1_H_INCLUDED

struct info_arreglo{
    FILA<CLIENTE> * fila;
    string criterio1;
    bool criterio2;
};

void ingresar_nuevo_cliente(info_arreglo arreglo_colas[]) {

    string nombre;
    unsigned int edad;
    string operacion;
    string destinatario;
    unsigned int monto;
    bool es_cliente;
    string sn_cliente;;

    cout << "nombre: "; cin >> nombre;
    cout << "edad: "; cin >> edad;
    cout << "operacion (retiro, deposito, transferencia o pago): "; cin >> operacion;
    cout << "destinatario (persona, banco o impuesto): "; cin >> destinatario;
    cout << "monto: "; cin >> monto;
    cout << "es_cliente (si/no): "; cin >> sn_cliente;
    if ((sn_cliente == "si") || (sn_cliente == "SI")) {
        es_cliente = true;
    }
    if ((sn_cliente == "no") || (sn_cliente == "NO")) {
        es_cliente = false;
    }

    CLIENTE cliente = CLIENTE(nombre, edad, operacion, destinatario, monto, es_cliente);

    if ((arreglo_colas[1].criterio1 == cliente.obtener_operacion()) && (arreglo_colas[1].criterio2 == cliente.obtener_es_cliente())) {
            arreglo_colas[1].fila->agregar_fila(cliente);
            cout << "cola por criterio 1: " << endl;
            arreglo_colas[1].fila->mostrar_fila();
    } else {
        if ((arreglo_colas[2].criterio1 == cliente.obtener_operacion()) && (arreglo_colas[2].criterio2 == cliente.obtener_es_cliente())) {
            arreglo_colas[2].fila->agregar_fila(cliente);
            cout << "cola por criterio 2: " << endl;
            arreglo_colas[2].fila->mostrar_fila();
        } else {
        arreglo_colas[0].fila->agregar_fila(cliente);
        arreglo_colas[0].fila->mostrar_fila();
        }
    }
}

#endif // SERVICIO_1_H_INCLUDED
