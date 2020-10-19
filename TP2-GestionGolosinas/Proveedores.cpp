#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

 #include"rlutil.h"
 #include"Proveedores.h"
 #include"Validaciones.h"



/*void Proveedor::setCodigo(){
   bool bandera=false;
   char cod[4];
   cout<<"INGRESE CODIGO "<<endl;
   cin>>cod;
   bandera= validarCadena(cod,4);
   while(bandera==false){

      cout<<"ERROR REINGRESE CODIGO"<<endl;
      cin>>cod;
      bandera=validarCadena(cod,4);


    }
    strcpy(codigo,cod);


}

/*void Proveedor::setNombre(char *name){

   strcpy(nombre,name);

}


void Proveedor::setEmail(char *mail){

   strcpy(email,mail);

}*/

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
 ///Proveedor reg;
 char coso [4];
 bool cadena;

cin.ignore();
cin>> coso;
cadena=validarCadena(coso,4);

if(cadena==false){
    cout<<"error";

}
else{cout<<"ta bien";}
cout<<cadena;


///reg.setCodigo();


}




