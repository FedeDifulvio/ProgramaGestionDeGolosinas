#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

 #include"rlutil.h"


bool validarCadena(char *cadena) {
      int contador;
      int x, cant;

      contador = 0;
     cant =  strlen(cadena);

      for (x= 0; x<cant; x++){
          if (cadena[x]== ' ' ) {
                contador++;
            }
      }
      if (contador == cant) {
          return false;
      }
      else {
            return true;
      }
}



