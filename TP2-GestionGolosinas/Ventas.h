#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "Fecha.h"

class Venta{
private:

int idVenta;
char idProducto[7];
int cantidad;
float precioParcial;

public:

void setIdVenta(int);
void setIdProducto(char [7]);
bool setCantidad(int);
void setPrecio(int);
bool leerEnDisco();
bool grabarEnDisco();

};


class datosVenta{
private:
int idVenta;
int idCliente;
Fecha Hoy;

public:

int setIdVenta();
void setIdCliente(int);
bool leerEnDisco(int);
bool grabarEnDisco();
};


void menuVentas();
void realizarVenta();
void mostrarVentas();
void listarVentaID();

#endif // VENTAS_H_INCLUDED
