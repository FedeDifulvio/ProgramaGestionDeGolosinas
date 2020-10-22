#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

class Proveedor {
    private:
    char codigo[4];
    char nombre[50];
    char email [50];

    public:
    void setCodigo();
    void setNombre();
    void setEmail ();
    char * getCodigo();
    char * getNombre();
    char * getEmail ();
    bool grabarEnDisco();
    bool leerDeDisco(int);
    void mostrarRegistro();
    bool validarCodProveedor(char*);
};





void menuProveedores();
void altaProveedor();
void listarProveedores();


#endif // PROVEEDORES_H_INCLUDED
