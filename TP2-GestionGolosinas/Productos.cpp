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
    const char* vacio=" ";
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
          default: return vacio;
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

if (stock<10){setColor(rlutil:: RED);}
else{setColor(rlutil:: GREEN);}

    cout<<left;
    cout<<"    ";
    cout<<setw(15);
    cout<< codigo;
    cout<<setw(17);
    cout <<nombre;
    cout<<setw(18);
    cout<<getNombreTipo();
    cout<<setw(9);
    cout<<precio;
    cout<<setw(8);
    cout<<stock;
    cout<<setw(5);
    cout<<endl;
    setColor(rlutil:: BLUE);
    cout<<".........................................................................."<<endl;

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




void menuProductos() {

      int opc;
      while(true){

            gotoxy (50, 3);
            cout<<"MENÚ PRODUCTOS"<<endl;
            gotoxy(47, 4);
            cout<<"------------------------"<<endl;
            gotoxy(50, 5);
            cout<<"1) LISTAR TODOS LOS PRODUCTOS "<<endl;
            gotoxy(50, 6);
            cout<<"2) LISTAR STOCK MENOR A VALOR INGRESADO  "<<endl;
            gotoxy(50, 7);
            cout<<"3) LISTAR STOCK MAYOR A VALOR INGRESADO "<<endl;
            gotoxy(50, 8);
            cout<<"4) LISTAR STOCK DE MAYOR A MENOR "<<endl;
            gotoxy(50, 9);
            cout<<"5) LISTAR STOCK DE MENOR A MAYOR "<<endl;
            gotoxy(50, 10);
            cout<<"6) LISTAR POR TIPO "<<endl;
            gotoxy(47, 11);
            cout<<"------------------------"<<endl;
            gotoxy(48, 13);
            cout<<"0) VOLVER AL MENÚ "<<endl;
            gotoxy(50, 16);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 16);
            cin>>opc;
            system("cls");

            switch(opc){
               case 1:listarTodosProductos();


                break;
                case 2:stockMenorValor();
                break;
                case 3:stockMayorValor();
                break;
                case 4://ordenarMayorMenor();
                break;
                case 5://ordenarMenorMayor();
                break;
                case 6:agruparTipo();


                break;
                case 0: return ;
                break;
                default: cout<<"OPCION NO VALIDA."<<endl;
                break;
            }

      }



 }




void listarTodosProductos(){

      system("cls");
      Articulo reg;
      int x = 0;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: CYAN);
            cout<<setw(7)<<"  ID PRODUCTO  | "<<setw(10)<<"    NOMBRE    | "<<setw(7)<<"      TIPO      |" <<setw(8)<<"  PRECIO  |"<<setw(8)<<"  CANTIDAD  |"<<endl;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: YELLOW);

      while(reg.leerDeDisco(x) ) {
      reg.mostrarRegistro();
      x++;
      }
      setColor(rlutil:: WHITE);
      system("pause");
      system("cls");
}


void stockMenorValor(){
int valor;
Articulo reg;

system("cls");

cout<<"INGRESAR VALOR A FILTRAR (MENOR A): ";
cin>>valor;

      int x = 0;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: CYAN);
            cout<<setw(7)<<"  ID PRODUCTO  | "<<setw(10)<<"    NOMBRE    | "<<setw(7)<<"      TIPO      |" <<setw(8)<<"  PRECIO  |"<<setw(8)<<"  CANTIDAD  |"<<endl;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: YELLOW);

      while(reg.leerDeDisco(x) ) {
            if(reg.getStock()<valor){

             reg.mostrarRegistro();

            }

       x++;
      }
      setColor(rlutil:: WHITE);
      system("pause");
      system("cls");
}

void stockMayorValor(){
int valor;
Articulo reg;

system("cls");

cout<<"INGRESAR VALOR A FILTRAR (MAYOR A): ";
cin>>valor;

      int x = 0;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: CYAN);
            cout<<setw(7)<<"  ID PRODUCTO  | "<<setw(10)<<"    NOMBRE    | "<<setw(7)<<"      TIPO      |" <<setw(8)<<"  PRECIO  |"<<setw(8)<<"  CANTIDAD  |"<<endl;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: YELLOW);

      while(reg.leerDeDisco(x) ) {
            if(reg.getStock()>valor){

             reg.mostrarRegistro();

            }

       x++;
      }
      setColor(rlutil:: WHITE);
      system("pause");
      system("cls");


}

void agruparTipo(){
int tipo;
Articulo reg;

system("cls");
cout<<"CATEGORIAS";
cout<<endl;
cout<<"1)Bombon";
cout<<endl;
cout<<"2)Chocolate";
cout<<endl;
cout<<"3)Alfajor";
cout<<endl;
cout<<"4)Caramelo";
cout<<endl;
cout<<"INGRESE NRO TIPO A BUSCAR: ";
cin>>tipo;
system("cls");


      int x = 0;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: CYAN);
            cout<<setw(7)<<"  ID PRODUCTO  | "<<setw(10)<<"    NOMBRE    | "<<setw(7)<<"      TIPO      |" <<setw(8)<<"  PRECIO  |"<<setw(8)<<"  CANTIDAD  |"<<endl;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: YELLOW);

      while(reg.leerDeDisco(x) ) {
            if(reg.getTipo()==tipo){

             reg.mostrarRegistro();

            }


       x++;
      }
      setColor(rlutil:: WHITE);
      system("pause");
      system("cls");








}
