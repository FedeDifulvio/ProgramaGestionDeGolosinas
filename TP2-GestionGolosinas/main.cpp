#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

 #include"rlutil.h"
 #include "Proveedores.h"
 #include "Validaciones.h"


int main(){
      setlocale(LC_ALL, "spanish");
      int opc;


      while(true){

            gotoxy (50, 3);
            cout<<"MENÚ PRNICIPAL"<<endl;
            gotoxy(47, 4);
            cout<<"------------------------"<<endl;
            gotoxy(50, 5);
            cout<<"1) PROVEEDORES "<<endl;
            gotoxy(50, 6);
            cout<<"2) COMPRAS "<<endl;
            gotoxy(50, 7);
            cout<<"3) CLIENTES "<<endl;
            gotoxy(50, 8);
            cout<<"4) PRODUCTOS "<<endl;
            gotoxy(50, 9);
            cout<<"5) VENTAS "<<endl;
            gotoxy(50, 10);
            cout<<"6) STOCK "<<endl;
            gotoxy(50, 11);
            cout<<"7) ESTADISTICAS "<<endl;
            gotoxy(47, 12);
            cout<<"------------------------"<<endl;
            gotoxy(48, 14);
            cout<<"0) SALIR DEL PROGRAMA"<<endl;
            gotoxy(50, 16);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 16);
            cin>>opc;
            system("cls");

            switch(opc){
                  case 1: menuProveedores();



                  break;
                  case 2:


                  break;
                  case 3:

                  break;
                  case 4:

                  break;
                  case 0: return 0;
                  break;
                  default: cout<<"OPCION NO VALIDA."<<endl;
                  break;
            }

      }

    return 0;
}
