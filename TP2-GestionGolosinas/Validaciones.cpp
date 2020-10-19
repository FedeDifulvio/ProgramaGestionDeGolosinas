#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

 #include"rlutil.h"


bool validarCadena(char *cadena,int tam) {
      int contador;
      int x;



        contador = 0;

        for (x= 0; x<tam; x++){
          if (cadena[x]== ' ' ) {
                contador++;
            }
        }
        if (contador == tam) {
          return false;
        }
       return true;

    }
