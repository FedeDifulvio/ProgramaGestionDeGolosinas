#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>
#include <iomanip>

using namespace std;

 #include"rlutil.h"
 #include"funcionesGlobales.h"
 #include"Ventas.h"
 #include"Productos.h"
 #include"Clientes.h"


void Venta::setIdVenta(int id){
idVenta=id;
}

void Venta::setIdProducto(char cod [7]){
strcpy(idProducto, cod);


}
void Venta::setNombreProducto(char name[70]){

strcpy(nombreProducto, name);

}
bool Venta::setCantidad(int cant){
cantidad= cant;

}
void Venta::setPrecio(int precio){

precioParcial = precio;

}
      //METÓDOS DE LA CLASE "datosVentas"
int datosVenta::setIdVenta(){
int autonumerico;
	FILE* pFile;

	pFile = fopen("ARCHIVOS/datosVenta.dat", "rb");

	if (pFile == NULL) {
            idCliente = 1;
            return idCliente;
	}

	fseek(pFile, 0, SEEK_END);
	autonumerico = ftell(pFile) / sizeof(datosVenta);
	fclose(pFile);
      idCliente = autonumerico+1;
	return idCliente;
}
void datosVenta::setIdCliente(int cod){
idCliente=cod;

}
void menuVentas() {

      int opc;
      while(true){
            setColor(rlutil:: GREY);
            gotoxy(43, 2);
            cout<<" -----------------------------  ";
            gotoxy(43, 3);
            cout<<"|";
            gotoxy(43+ 30, 3);
            cout<<"|";
            setColor(rlutil:: LIGHTCYAN);
            gotoxy(43, 4);
            cout<<"|";
            gotoxy(54, 4);
            cout<<" VENTAS "<<endl;
            gotoxy(43+30, 4);
            cout<<"|";
            setColor(rlutil:: RED);
            gotoxy(43, 5);
            cout<<"|";
            gotoxy(43+ 30, 5);
            cout<<"|";
            gotoxy(43, 6);
            cout<<" -----------------------------  ";
            setColor(rlutil:: WHITE);
            gotoxy(50, 5+3);
            cout<<"1) REALIZAR VENTA "<<endl;
            gotoxy(50, 6+3);
            cout<<"2) LISTAR VENTAS  "<<endl;
            gotoxy(50, 7+3);
            cout<<"3) LISTAR POR ID "<<endl;
            gotoxy(47, 8+3);
            cout<<"------------------------"<<endl;
            gotoxy(48, 9+3);
            cout<<"0) VOLVER AL MENÚ "<<endl;
            gotoxy(50, 12+3);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 12+3);
            cin>>opc;
            system("cls");

            switch(opc){
               case 1:  realizarVenta();


                break;
                case 2: //mostrarVentas();

                break;
                case 3: //listarVentaID();


                break;
                case 0: return ;
                break;
                default: cout<<"OPCION NO VALIDA."<<endl;
                break;
            }

      }



 }

void realizarVenta(){
      datosVenta datos;
      Venta nuevaVenta;
      Cliente aVerificar;
      Articulo aVender;
      int ID,cliente, pos, cantidad;
      bool bandera;
      char codProducto[7];
      char opc;


      ID =  datos.setIdVenta();
      cout<<"INGRESE CODIGO DE CLIENTE: ";
      cin>> cliente;
      bandera=aVerificar.validarIdCliente(cliente);
      while (bandera==false){
            mensajeError("ERROR, NO ENCONTRADO");
            system("color 0F");
            cout<<"REINGRESE CODIGO DE CLIENTE: ";
            cin>> cliente;
            bandera=aVerificar.validarIdCliente(cliente);
      }
      datos.setIdCliente(cliente);

      do{
            cout<<"INGRESE CODIGO DE PRODUCTO A VENDER: "<<endl;
            cin>>codProducto;
            pos = aVender.getPosicion(codProducto);

            while(pos == -1) {
                cout<<"El PRODUCTO NO EXISTE, REINGRESE EL CODIGO: ";
                cin>>codProducto;
                pos = aVender.getPosicion(codProducto);
            }
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: CYAN);
            cout<<setw(7)<<"  ID PRODUCTO  | "<<setw(10)<<"    NOMBRE    | "<<setw(7)<<"      TIPO      |" <<setw(8)<<"  PRECIO  |"<<setw(8)<<"  CANTIDAD  |"<<endl;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: YELLOW);

            aVender.leerDeDisco(pos);
            aVender.mostrarRegistroVenta();
            setColor(rlutil:: WHITE);
            cout << "DESEA AGREGAR ESTE PRODUCTO A LA VENTA? (S/N)";
            cin >> opc;
      } while(opc =='n'||opc =='N');


      do{
            cout<<" INGRESE LA CANTIDAD A VENDER: ";
            cin>> cantidad;
           bandera = aVender.descontarStock(cantidad,pos);

      }while(bandera==false);









system("pause");
system("cls");
setColor(rlutil:: WHITE);

 }




