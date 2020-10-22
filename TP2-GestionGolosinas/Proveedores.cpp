#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

 #include"rlutil.h"
 #include"Proveedores.h"
 #include"Validaciones.h"


void Proveedor::setCodigo(){
   bool bandera=false;
   char cod[4];
   cout<<"INGRESE CODIGO "<<endl;
   cin.ignore();
   cin.getline(cod, 4);
   bandera= validarCadena(cod);
      while(bandera==false){

          cout<<"ERROR REINGRESE CODIGO"<<endl;
           cin.getline(cod, 4);
           bandera=validarCadena(cod);
      }
    strcpy(codigo,cod);

}

void Proveedor::setNombre(){
    bool bandera=false;
   char name[50];
   cout<<"INGRESE NOMBRE "<<endl;
   cin.getline(name, 50);
   bandera= validarCadena(name);
      while(bandera==false){

          cout<<"ERROR REINGRESE NOMBRE"<<endl;
           cin.getline(name, 50);
           bandera=validarCadena(name);
      }
     strcpy(nombre, name);
}


void Proveedor::setEmail(){

    bool bandera=false;
   char mail[50];
   cout<<"INGRESE MAIL "<<endl;
   cin.getline(mail, 50);
   bandera= validarCadena(mail);
   while(bandera==false){

          cout<<"ERROR REINGRESE EL MAIL"<<endl;
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



void menuProveedores(){
    int opc;


      while(true){

            gotoxy (50, 3);
            cout<<"MENÚ PROVEEDORES"<<endl;
            gotoxy(47, 4);
            cout<<"------------------------"<<endl;
            gotoxy(50, 5);
            cout<<"1) ALTA PROVEEDOR "<<endl;
            gotoxy(50, 6);
            cout<<"2) BAJA PROVEEDOR "<<endl;
            gotoxy(50, 7);
            cout<<"3) LISTAR TODOS LOS PROVEEDORES "<<endl;
            gotoxy(47, 8);
            cout<<"------------------------"<<endl;
            gotoxy(48, 9);
            cout<<"0) SALIR DEL PROGRAMA"<<endl;
            gotoxy(50, 12);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 12);
            cin>>opc;
            system("cls");

            switch(opc){
               case 1: altaProveedor();


                break;
                case 2:


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
            cout<<"guardado correctamente"<<endl;
      }
      else{
          cout<< "Error de archivo" <<endl;
      }
      system("pause");
      system("cls");
}




