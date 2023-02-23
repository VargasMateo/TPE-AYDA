#ifndef SERVICIO_5_H_INCLUDED
#define SERVICIO_5_H_INCLUDED


void listar_segun_rango(LISTA<CLIENTE> * atendidos, LISTA<CLIENTE> *& listado_rango, int piso, int techo) {

    int posicion = 1;
    int longitud = atendidos->longitud();
    int suma_edades = 0;

    while (posicion <= longitud) {
        CLIENTE datos = atendidos->consultar_arbitriario(posicion);
        if ((datos.obtener_monto() >= piso) && (datos.obtener_monto() <= techo))
            {
                listado_rango->agregar_inicio(datos);
                suma_edades = suma_edades + datos.obtener_edad();
            }
        posicion ++;
    }

    cout << "                                                                        " << endl;
    cout << "edad promedio de la lista: " << (suma_edades / listado_rango->longitud()) << endl;
    cout << "                                                                        " << endl;

}


#endif // SERVICIO_5_H_INCLUDED
