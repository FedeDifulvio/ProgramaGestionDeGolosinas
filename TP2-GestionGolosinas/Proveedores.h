#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED
#include "Validaciones.h"
class Proveedor {
    private:
    char codigo[4];
    char nombre[50];
    char email [50];

    public:
    void setCodigo();
    void setNombre(char *);
    void setEmail (char[]);
    char * getCodigo();
    char * getNombre();
    char * getEmail ();
};





void menuProveedores();
void altaProveedor();


#endif // PROVEEDORES_H_INCLUDED
