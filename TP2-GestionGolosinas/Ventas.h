#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "Fecha.h"

class Venta{
private:

int idVenta;
char idProducto[7];
char nombreProducto[70];
int cantidad;
float precioParcial;

public:

void setIdVenta(int);
void setIdProducto(char [7]);
void setNombreProducto(char [70]);
bool setCantidad(int);
void setPrecio(int);


};


class datosVenta{
private:
int idVenta;
int idCliente;
Fecha Hoy;

public:

int setIdVenta();
void setIdCliente(int);
};


void menuVentas();
void realizarVenta();
void mostrarVentas();
void listarVentaID();

#endif // VENTAS_H_INCLUDED
