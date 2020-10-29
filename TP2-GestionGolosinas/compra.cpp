#include <iostream>
#include <cstdlib>

 using namespace std;

#include"rlutil.h"
 #include"funcionesGlobales.h"
 #include "Clientes.h"
#include"funcionesGlobales.h"
#include "compra.h"
#include "Fecha.h"
#include "Proveedores.h"
#include"Productos.h"
#include"IDgenerator.h"

Fecha compra::getHoy(){
      return hoy;

}

void compra :: setCodigo(int id){
    codCompra = id;
}

void compra:: setCodProducto( char cod [7]){
   strcpy(codProducto, cod);
}

void compra:: setCodProveedor(){
      bool bandera;
      Proveedor aVerificar;
      cout<<"Ingrese codigo de proveedor: ";
      cin.ignore();
      cin.getline(codProveedor, 30);
      bandera = aVerificar.validarCodProveedor(codProveedor);
      while (bandera == true) {
            mensajeError("ERROR, NO ENCONTRADO");
            system("color 0F");
            cout<<"Ingrese codigo de proveedor: ";
            cin.getline(codProveedor, 30);
            bandera = aVerificar.validarCodProveedor(codProveedor);
      }

}


void compra:: setCantidad(int valor){
      cantidad =  valor;
}

void compra :: setNombreProducto( char nombre[70]){
      strcpy(nombreProducto, nombre);

}

/*void compra :: setTipoProducto(){
      cout<<"Ingrese tipo de producto: ";
      cin.getline(tipoProducto, 50);
}*/

 int  compra:: getCodigo(){
      return codCompra;
 }
char *   compra:: getCodProducto(){
      return codProducto;


}
int   compra:: getCantidad(){
      return cantidad;
}

char *  compra :: getCodigoProveedor(){
      return codProveedor;
}

char *  compra:: getNombreProducto(){
      return nombreProducto;
}

/*int   compra:: getTipoProducto(){
      return tipoProducto;
}*/


bool compra:: grabarEnDisco(){

FILE *puntero;

puntero = fopen("ARCHIVOS/Compras.dat", "ab");
 fwrite(this, sizeof(compra), 1, puntero);
fclose(puntero);
return true;
}






void menuCompras() {

      int opc;
      while(true){

            gotoxy (50, 3);
            cout<<"MENÚ COMPRAS"<<endl;
            gotoxy(47, 4);
            cout<<"------------------------"<<endl;
            gotoxy(50, 5);
            cout<<"1)  REALIZAR COMPRA "<<endl;
            gotoxy(50, 6);
            cout<<"2) LISTAR COMPRAS  "<<endl;
            gotoxy(50, 7);
            cout<<"3) LISTAR POR ID "<<endl;
            gotoxy(47, 8);
            cout<<"------------------------"<<endl;
            gotoxy(48, 9);
            cout<<"0) VOLVER AL MENÚ "<<endl;
            gotoxy(50, 12);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 12);
            cin>>opc;
            system("cls");

            switch(opc){
               case 1:  realizarCompra();


                break;
                case 2: mostrarCompras();
                break;
                case 3:


                break;
                case 0: return ;
                break;
                default: cout<<"OPCION NO VALIDA."<<endl;
                break;
            }

      }



 }


void realizarCompra(){

      int ID, pos, cantidad;
      char seguir;
      bool bandera;
      char codProducto[7];
      Articulo nuevoProducto(1);
      Articulo productoExistente;
      compra nuevaCompra;
    IDGenerator identificador;


    char * nombre;

    ID =  identificador.generateID();  /// Clase para generar el ID que va a linkear todos los registros de la compra.
    identificador.generatePos();
    identificador.grabarEnDisco();

    do{
            cout<<"Ingrese código de producto a comprar: "<<endl;
            cin>>codProducto;
            pos = productoExistente.getPosicion(codProducto);
            if(pos == -1) {
                  cout<<" REGISTRO DE PRODUCTO NUEVO"<<endl;
                  nuevoProducto.setCodigo();
                  nuevoProducto.setNombre();
                  nuevoProducto.setTipo();
                  nuevoProducto.setPrecio();
                  strcpy(nombre, nuevoProducto.getNombre());
                  cout<<"Ingrese cantidad a comprar:  ";
                  cin>> cantidad;
                  nuevoProducto.actualizarStock(cantidad);


                  if(nuevoProducto.grabarEnDisco()){
                        mensajeExito("registrado con exito");
                        system("color 0F");
                  }
                  else{
                        mensajeError("No es posible registrar nuevo producto");
                        system("color 0F");
                        system("pause");
                        system("cls");
                        return;
                  }

            }
            else{
                  productoExistente.leerDeDisco(pos);
                  productoExistente.mostrarRegistro();
                  strcpy(nombre, productoExistente.getNombre());
                  cout<<" INGRESE LA CANTIDAD A COMPRAR: ";
                  cin>> cantidad;
                  productoExistente.actualizarStock(cantidad);
                  productoExistente.grabarEnDisco(pos);

            }


            nuevaCompra.setCodigo(ID);
            nuevaCompra.setCodProducto(codProducto);
            nuevaCompra.setCantidad(cantidad);
            nuevaCompra.setNombreProducto(nombre);
            nuevaCompra.setCodProveedor();
            bandera = nuevaCompra.grabarEnDisco();
            if(bandera) {
                  mensajeExito("Producto agregado.");
                  system("color 0F");
            }
            else{
                  mensajeError("No se puede continuar");
                  system("color 0F");
                  system("pause");
                  system("cls");
                  return;
            }



          cout<<"¿Desea seguir comprando? S/N "<<endl;
          cin>>seguir;
      } while(seguir== 's'|| seguir == 'S' );

}


void mostrarCompras() {

      system("cls");
      IDGenerator reg;
      int x = 0;
     while(reg.leerDisco(x) ) {
            leerArchivoCompras(reg.getID(), reg.getPos());
            x++;
      }
      system("pause");
      system("cls");
}


void  leerArchivoCompras( int id, int pos){
      FILE *puntero;
      compra reg ;
      bool bandera = true;
      puntero = fopen("ARCHIVOS/Compras.dat", "rb");
      if(puntero == NULL) {

            cout<<"error"<<endl;
            system("pause");
      }


      cout<<"------------------------------------------------"<<endl;
      fseek(puntero, sizeof(compra)* pos, SEEK_SET);
      while (fread(&reg, sizeof(compra), 1 , puntero)) {
            if(reg.getCodigo()==id){
                  if(bandera) {
                        cout<<"ID COMPRA: "<<reg.getCodigo()<<endl;
                        cout<<"PROVEEDOR: "<<reg.getCodigoProveedor()<<endl;
                        cout<<"FECHA ";
                        reg.getHoy().mostrarFecha();
                        bandera = false;
                  }
                  cout<<"*****************************"<<endl;
                  cout<<"ID PRODUCTO: "<<reg.getCodProducto()<<endl;
                  cout<<"NOMBRE PRODUCTO: "<<reg.getNombreProducto()<<endl;
                  cout<<"CANTIDAD : "<<reg.getCantidad()<<endl;

            }

            else {
                  return;

            }

      }

      system("pause");
      system("cls");
}







