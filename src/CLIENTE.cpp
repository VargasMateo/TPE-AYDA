#include "CLIENTE.h"

CLIENTE::CLIENTE()
{
    //ctor
}

CLIENTE::CLIENTE(string nombre, unsigned int edad, string operacion, string destinatario, unsigned int monto, bool es_cliente)
{
    this->nombre = nombre;
    this->edad = edad;
    this->operacion = operacion;
    this->destinatario = destinatario;
    this->monto = monto;
    this->es_cliente = es_cliente;
}

CLIENTE::~CLIENTE()
{
    //dtor
}


string CLIENTE::obtener_nombre() const
{
    return nombre;
}

unsigned int CLIENTE::obtener_edad() const
{
    return edad;
}

string CLIENTE::obtener_operacion() const
{
    return operacion;
}

string CLIENTE::obtener_destinatario() const
{
    return destinatario;
}

unsigned int CLIENTE::obtener_monto() const
{
    return monto;
}

bool CLIENTE::obtener_es_cliente() const
{
    return es_cliente;
}


ostream & operator<<(ostream & salida, const CLIENTE & cliente)
{
    salida << "nombre: " << cliente.obtener_nombre() << endl;
    salida << "edad: " << cliente.obtener_edad() << endl;
    salida << "operacion: " << cliente.obtener_operacion() << endl;
    salida << "destinatario: " << cliente.obtener_destinatario() << endl;
    salida << "monto: " << cliente.obtener_monto() << endl;
    if (cliente.obtener_es_cliente() == true) {
        salida << "es cliente?: si" << endl;
    } else salida << "es cliente?: no" << endl;

    return salida;
}


