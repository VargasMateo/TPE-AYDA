#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

using namespace std;


class CLIENTE
{
    public:
        CLIENTE();
        CLIENTE(string nombre, unsigned int edad, string operacion, string destinatario, unsigned int monto, bool es_cliente);
        ~CLIENTE();


    string obtener_nombre() const;
    unsigned int obtener_edad() const;
    string obtener_operacion() const;
    string obtener_destinatario() const;
    unsigned int obtener_monto() const;
    bool obtener_es_cliente() const;

    private:
        string nombre;
        unsigned int edad;
        string operacion;
        string destinatario;
        unsigned int monto;
        bool es_cliente;

};

    ostream & operator<<(ostream & salida, const CLIENTE & cliente);



#endif // CLIENTE_H
