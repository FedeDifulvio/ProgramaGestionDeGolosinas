#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>
#include <iomanip>

using namespace std;

 #include"rlutil.h"
 #include"funcionesGlobales.h"
 #include"Productos.h"


Articulo :: Articulo(int indicador){
      if(indicador == 1) {
            stock = 0;
      }
 }

void Articulo::setCodigo(){

 bool bandera=false;
 char cod[7];
   cout<<"INGRESE CODIGO DEL PRODUCTO: ";
   cin.ignore();
   cin.getline(cod, 7);
   bandera= validarCadena(cod);

    while(bandera==false ){

        mensajeError("ERROR, CODIGO INVALIDO ");
         cout<<"NGRESE CODIGO DEL PRODUCTO NUEVAMENTE: ";
         system("color 0F");
         cin.getline(cod, 7);
          bandera=validarCadena(cod);

      }
    strcpy(codigo,cod);

}
void Articulo::setNombre(){
bool bandera=false;
char name[70];
   cout<<"INGRESE NOMBRE DEL PRODUCTO: ";
   cin.getline(name, 70);
   bandera= validarCadena(name);
      while(bandera==false){

      mensajeError("ERROR DE DATO");
        system("color 0F");
       cout<<"INGRESE NOMBRE DEL PRODUCTO:  ";
       cin.getline(name, 70);
       bandera=validarCadena(name);
      }
     strcpy(nombre, name);
}
void Articulo::setPrecio(){
    float precioProducto;
 cout << "INGRESE PRECIO DEL PRODUCTO: ";
 cin >> precioProducto;

 while(precio <= 0){
    mensajeError("ERROR DE DATO");
    system("color 0F");
    cout << "REINGRESE PRECIO DEL PRODUCTO: ";
    cin >> precioProducto;
 }
precio = precioProducto;

}
void Articulo::setTipo(){
 int tipoProducto;
 cout << "INGRESE NRO DEL TIPO DE PRODUCTO: ";
 cin >> tipoProducto;

 while(precio <= 0){
    mensajeError("ERROR DE DATO");
    system("color 0F");
    cout << "INGRESE NRO DEL TIPO DE PRODUCTO: ";
    cin >> tipoProducto;
 }
codTipo = tipoProducto;
}
void Articulo::actualizarStock( int cant){

      stock += cant;
}
char *Articulo::getCodigo(){
return codigo;
}
char *Articulo::getNombre(){

return nombre;
}
float Articulo::getPrecio(){

return precio;
}
int Articulo::getStock(){

return stock;
}
const char * Articulo::getNombreTipo(){

    const char* bombon = "bombon";
    const char* chocolate = "chocolate";
    const char* alfajor = "alfajor";
    const char* caramelos = "caramelos";

    switch(this->codTipo){

          case 1: return bombon;

          break;
          case 2:return chocolate;

          break;
          case 3:return alfajor;

          break;
          case 4:return caramelos;

          break;


      }

}
 int Articulo::getTipo(){
      return codTipo;
 }


bool Articulo::grabarEnDisco(int pos){
 FILE *puntero;
bool bandera;
    if (pos == -1){
        puntero = fopen("ARCHIVOS/Productos.dat", "ab");
            if(puntero == NULL) {
                  return false;
            }
      }

   else{
        puntero = fopen("ARCHIVOS/Productos.dat", "rb+");
        if(puntero == NULL) {
          return false;
        }
        fseek(puntero,pos* sizeof(Articulo),0);
    }

  bandera = fwrite(this, sizeof(Articulo), 1, puntero);
  fclose(puntero);
      if (bandera == false) {
           return false;
      }
   return true;

 }
bool Articulo::leerDeDisco(int pos){
FILE *puntero;
      bool bandera;
      puntero = fopen("ARCHIVOS/Productos.dat", "rb");
      if(puntero == NULL) {
      return false;
}
      fseek(puntero, sizeof(Articulo)*pos, SEEK_SET);
      bandera = fread(this, sizeof(Articulo), 1, puntero);
    fclose(puntero);
    return bandera;

}
void Articulo::mostrarRegistro(){

setColor(rlutil:: GREEN);
    cout<<left;
    cout<<setw(15);
    cout<< codigo;
    cout<<setw(15);
    cout << nombre;
    cout<<setw(5);
    cout<<precio;
    cout<<setw(5);
    cout<<stock;
    cout<<setw(5);
    cout<<codTipo;
    cout<<endl;
    setColor(rlutil:: BLUE);
    cout<<"........................................................."<<endl;

}

int Articulo:: getPosicion (char cod [6]){
int pos = 0;

     while(leerDeDisco(pos)) {
            if(strcmp(this->codigo,cod)== 0){
               return pos;
            }
        pos ++;
      }
    return -1;
}
