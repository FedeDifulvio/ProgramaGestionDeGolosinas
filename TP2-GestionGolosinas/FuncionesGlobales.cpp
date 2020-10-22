#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

#include "funcionesGlobales.h"

void mensajeError( char mensaje[70]){
      system("cls");
      system("color 4F");
      cout<<mensaje<<endl;
      system("pause");
      system("cls");

 }

void mensajeExito(char mensaje[70]){
      system("cls");
      system("color 2F");
      cout<<mensaje<<endl;
      system("pause");
      system("cls");
 }
