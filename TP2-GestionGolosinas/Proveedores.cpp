#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

 #include"rlutil.h"
 #include"Proveedores.h"
 #include"Validaciones.h"
 #include"funcionesGlobales.h"


void Proveedor::setCodigo(){
   bool bandera=false;
   bool bandera2 = false;
   char cod[4];
   cout<<"INGRESE CODIGO (3 LETRAS): ";
   cin.ignore();
   cin.getline(cod, 4);
   bandera= validarCadena(cod);
   bandera2 = validarCodProveedor(cod);
      while(bandera==false || bandera2 == false){

          mensajeError("ERROR, CODIGO INVALIDO O REPETIDO");
          cout<<"INGRESE CODIGO (3 LETRAS): ";
          system("color 0F");
           cin.getline(cod, 4);
           bandera=validarCadena(cod);
            bandera2 = validarCodProveedor(cod);
      }
    strcpy(codigo,cod);

}

void Proveedor::setNombre(){
    bool bandera=false;
   char name[50];
   cout<<"INGRESE NOMBRE ";
   cin.getline(name, 50);
   bandera= validarCadena(name);
      while(bandera==false){

          mensajeError("ERROR DE DATO");
            system("color 0F");
           cout<<"INGRESE NOMBRE:  ";
           cin.getline(name, 50);
           bandera=validarCadena(name);
      }
     strcpy(nombre, name);
}


void Proveedor::setEmail(){

    bool bandera=false;
   char mail[50];
   cout<<"INGRESE MAIL ";
   cin.getline(mail, 50);
   bandera= validarCadena(mail);
   while(bandera==false){

          mensajeError("ERROR REINGRESE EL MAIL");
            system("color 0F");
           cout<<"INGRESE MAIL ";
           cin.getline(mail, 50);
           bandera=validarCadena(mail);
      }
   strcpy(email, mail);
}


char * Proveedor:: getCodigo(){
      return codigo;
}
char * Proveedor :: getNombre(){
      return nombre;
}
char * Proveedor :: getEmail(){
      return email;
}

bool Proveedor:: grabarEnDisco(){

FILE *puntero;
bool bandera;

puntero = fopen("ARCHIVOS/Proveedores.dat", "ab");
if(puntero == NULL) {
      return false;
}
  bandera = fwrite(this, sizeof(Proveedor), 1, puntero);
  fclose(puntero);
      if (bandera == false) {
           return false;
      }
   return true;
}

bool Proveedor :: leerDeDisco( int pos ) {
      FILE *puntero;
      bool bandera;
      puntero = fopen("ARCHIVOS/Proveedores.dat", "rb");
      if(puntero == NULL) {
      return false;
}
      fseek(puntero, sizeof(Proveedor)*pos, SEEK_SET);
      bandera = fread(this, sizeof(Proveedor), 1, puntero);
    fclose(puntero);
    return bandera;
}

void Proveedor :: mostrarRegistro() {

      cout<<"NOMBRE: " << nombre <<endl;
      cout <<"ID : "<< codigo <<endl;
      cout<< "Email: "<<email <<endl;
      cout<<endl<<endl;
}

bool Proveedor :: validarCodProveedor( char * cod){
      FILE *puntero;
      int ban;

      puntero = fopen("ARCHIVOS/Proveedores.dat", "rb");
      if(puntero == NULL) {
      return false;
     }

      while (fread(this, sizeof(Proveedor), 1, puntero)){
         ban = strcmp(this->codigo, cod);
            if(ban == 0) {
                  return false;
                  fclose(puntero);
           }
      }
    fclose(puntero);
    return true;
}



void menuProveedores(){
    int opc;


      while(true){

            gotoxy (50, 3);
            cout<<"MEN� PROVEEDORES"<<endl;
            gotoxy(47, 4);
            cout<<"------------------------"<<endl;
            gotoxy(50, 5);
            cout<<"1) ALTA PROVEEDOR "<<endl;
            gotoxy(50, 6);
            cout<<"2) LISTAR PROVEEDORES  "<<endl;
            gotoxy(47, 8);
            cout<<"------------------------"<<endl;
            gotoxy(48, 9);
            cout<<"0) SALIR DEL PROGRAMA"<<endl;
            gotoxy(50, 12);
            cout<<"INGRESE UNA OPCI�N: "<<endl;
            gotoxy(70, 12);
            cin>>opc;
            system("cls");

            switch(opc){
               case 1: altaProveedor();


                break;
                case 2: listarProveedores();


                break;
                case 3:

                break;
                case 4:

                break;
                case 0: return ;
                break;
                default: cout<<"OPCION NO VALIDA."<<endl;
                break;
            }

      }
}


void altaProveedor(){
 Proveedor nuevoProveedor;

  nuevoProveedor.setCodigo();
  nuevoProveedor.setNombre();
  nuevoProveedor.setEmail();

      if (nuevoProveedor.grabarEnDisco() ){
           mensajeExito("Proveedor registrado");
            system("color 0F");
      }
      else{
          mensajeError("Error de archivo" );
            system("color 0F");
      }
}

void listarProveedores() {

      system("cls");
      Proveedor listado;
      int pos = 0;
      while(listado.leerDeDisco(pos)) {
            listado.mostrarRegistro();
            pos ++;
      }
      system("pause");
      system("cls");
}


