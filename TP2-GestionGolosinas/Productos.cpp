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

 while(precioProducto <= 0){
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

 while(tipoProducto <= 0){
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
    cout<<setw(16);
    cout<<getNombreTipo();
    cout<<setw(5);
    cout<<precio;
    cout<<setw(6);
    cout<<"$"<<stock;
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
            cout<<"MEN� PRODUCTOS"<<endl;
            gotoxy(47, 4);
            cout<<"------------------------"<<endl;
            gotoxy(50, 5);
            cout<<"1) LISTAR TODOS LOS PRODUCTOS "<<endl;
            gotoxy(50, 6);
            cout<<"2) LISTAR STOCK MENOR A VALOR INGRESADO  "<<endl;
            gotoxy(50, 7);
            cout<<"3) LISTAR STOCK MAYOR A VALOR INGRESADO "<<endl;
            gotoxy(50, 8);
            cout<<"4) PRODUCTOS ORDENADOS POR CANTIDAD DE STOCK "<<endl;
            gotoxy(50, 9);
            cout<<"5) LISTAR POR TIPO"<<endl;
            gotoxy(47, 11);
            cout<<"------------------------"<<endl;
            gotoxy(48, 13);
            cout<<"0) VOLVER AL MEN� "<<endl;
            gotoxy(50, 16);
            cout<<"INGRESE UNA OPCI�N: "<<endl;
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
                case 4:ordenarProductosStock();
                break;
                case 5:agruparTipo();
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


void ordenarProductosStock(){
  int cantidad = cantidadProductos();
  Articulo *vec;
  Articulo reg;
  int opc;
  int x=0;
  vec = new Articulo[cantidad];

  while(reg.leerDeDisco(x)){
         vec[x]=reg;
           x++;

      }
cout << "TIPOS DE ORDENAMIENTO: 1= mayor a menor.  2 = menor a mayor"<< endl;
cout << "INGRESE UNA OPCION: ";
cin >> opc;
system("cls");

if (opc==1){

ordenarMayor_Menor(vec, cantidad);
}
else{
      if(opc==2){
      ordenarMenor_Mayor(vec, cantidad);
      }
      else{
            mensajeError("OPCION INV�LIDA");
            system("color 0F");
            system("cls");
            return;
      }
}
setColor(rlutil:: LIGHTRED);
      cout<<"--------------------------------------------------------------------------"<<endl;
      setColor(rlutil:: CYAN);
      cout<<setw(7)<<"  ID PRODUCTO  | "<<setw(10)<<"    NOMBRE    | "<<setw(7)<<"      TIPO      |" <<setw(8)<<"  PRECIO  |"<<setw(8)<<"  CANTIDAD  |"<<endl;
      setColor(rlutil:: LIGHTRED);
      cout<<"--------------------------------------------------------------------------"<<endl;
      setColor(rlutil:: YELLOW);

for(x=0;x<cantidad;x++){
      vec[x].mostrarRegistro();
}

delete (vec);
setColor(rlutil:: WHITE);
system("pause");
system("cls");



}

int cantidadProductos(){

   int cantidad;
	FILE* pFile;

	pFile = fopen("ARCHIVOS/Productos.dat", "rb");

	if (pFile == NULL) {
            cantidad = 0;
            return cantidad;
	}

	fseek(pFile, 0, SEEK_END);
	cantidad = ftell(pFile) / sizeof(Articulo);
	fclose(pFile);
	return cantidad;

}

void ordenarMayor_Menor(Articulo *vec, int cant){
int i, j, posmin;
   Articulo aux;
  for(i=0;i<cant-1;i++){
      posmin=i;
      for(j=i+1;j<cant;j++){

        if(vec[posmin].getStock()<vec[j].getStock()) posmin=j;
      }
      aux=vec[i];
      vec[i]=vec[posmin];
      vec[posmin]=aux;
    }

}

void ordenarMenor_Mayor(Articulo *vec, int cant){
int i, j, posmin;
   Articulo aux;
  for(i=0;i<cant-1;i++){
      posmin=i;
      for(j=i+1;j<cant;j++){

        if(vec[posmin].getStock()>vec[j].getStock()) posmin=j;
      }
      aux=vec[i];
      vec[i]=vec[posmin];
      vec[posmin]=aux;
    }


}



