#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

class Articulo{
private:
      char codigo[7];  ///Código alfanumerico compuesto por 3 numeros y 3 letras.
      char nombre[70];
      float precio;
      int codTipo;    /// 1- bombon 2- chocolate 3- alfajor 4 - caramelos.
      int stock;

public:
      void setCodigo();
      void setNombre();
      void setPrecio();
      void setTipo();
      void setStock();
      char *getCodigo();
      char *getNombreTipo();
      int getTipo();
      float getPrecio();
      int getStock();
      int getTipo();
      bool grabarEnDisco(int = -1);
      bool leerDeDisco(int);
      void mostrarRegistro();
};

#endif // PRODUCTOS_H_INCLUDED
