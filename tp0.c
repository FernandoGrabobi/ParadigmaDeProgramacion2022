#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task {
  char descripcion[100];
  int complejidad;
} typedef task;

struct trabajo {
  long DNI;
  char Poder[100];
  task tarea;
  char partidoPolitico[100];
} typedef trabajo;

task listaDeTareas[5];
trabajo listaDeTrabajo[5];

void calcularEstres(task listaDeTareas[]) {
 
  for(int i = 0; i < 5; i++){
    if (listaDeTareas[i].complejidad > 5) {
      printf("\n La tarea Numero %d es estresante porque tiene una complejidad de %d \n", i+1, listaDeTareas[i].complejidad);
    } else {
      printf("\n La tarea Numero %d se la considera no estresante \n", i+1);
    }
  }
  
}

void personasEstresadas(trabajo listaDeTrabajo[],int tamanio){
  for(int i = 0; i < 5; i++){
    if ((listaDeTrabajo[i].tarea.complejidad > 5)||(listaDeTrabajo[i].Poder == "PJ")) {
      printf("\n El trabajador Numero %d esta estresado \n", i+1);
    } else {
      printf("");
    }
  }
}

void Inicializar(task listaDeTareas[] , int tamanio) {
  for (int i = 0; i < tamanio; i++) {
    for (int f = 0; f < 100; f++) {
      listaDeTareas[i].descripcion[f] = '\0';
      listaDeTareas[i].complejidad = 0;
    }
  }
}

void Inicializar2(trabajo listaDeTrabajo[] , int tamanio) {
  for (int i = 0; i < tamanio; i++) {
    for (int f = 0; f < 100; f++) {
      listaDeTrabajo[i].DNI = 0;
      listaDeTrabajo[i].Poder[f] = '\0';
      listaDeTrabajo[i].tarea.complejidad=0;
      listaDeTrabajo[i].tarea.descripcion[f]='\0';
      listaDeTrabajo[i].partidoPolitico[f]='\0';
    }
  }
}
////////////////////////////////////////

int main(void) {

  int menu, opcionDeTarea;
  bool bandera;
  

  menu = 0;
  opcionDeTarea = 0;
  bandera = false;

  /*Fin Inicializar variables*/

  while (menu != -1) {

    printf("\n---Opcion 1 para ingresar todos los datos ---\n");
    printf("\n---Opcion 2 para conocer las tareas estresantes\n");
    printf("\n---Opcion 3 para conocer las personas estresadas\n");
    printf("\n---Opcion 4 para conocer las personas que estan en peligro\n");
    printf("\n---Opcion 5 para mostrar \n");
    scanf("%d", &menu);

    /*Control de errores menu*/

    while ((menu > 4) || (menu < 0)) {
      system("clear");
      printf("\n---ERROR---\n");
      printf("\n---Opcion 1 para ingresar todos los datos ---\n");
      printf("\n---Opcion 2 para conocer las tareas estresantes\n");
      printf("\n---Opcion 3 para conocer las personas estresadas\n");
      printf("\n---Opcion 4 para conocer las personas que estan en peligro\n");
      printf("\n---Opcion 5 para mostrar p\n");
      scanf("%d", &menu);
    }

    /*fin Control de errores menu*/

    switch (menu) {
    case 1:
      system("clear");
      printf("\n --- A seleccionado la opcion 1 --- \n");
      Inicializar(listaDeTareas, 5);
      
      for (int i = 0; i < 5; i++) {
        printf("Ingrese la Descripcion de la tarea N %d \n", i+1);
        fflush(stdin);
        scanf("%s", &listaDeTareas[i].descripcion);
        printf("Ingrese la complejidad de la tarea N %d \n", i+1);
        scanf("%d", &listaDeTareas[i].complejidad);
        while((listaDeTareas[i].complejidad > 10)||(listaDeTareas[i].complejidad < 0)){
          system("clear");
          printf("\n---ERROR ingresar valor entre 0 y 10 ---\n");
          printf("Ingrese la complejidad de la tarea N %d \n", i+1);
          scanf("%d", &listaDeTareas[i].complejidad);
        }
      }
      
      Inicializar2(listaDeTrabajo, 5);
      
      for (int i = 0; i < 5; i++){
        printf("Ingrese el DNI del trabajador N %d \n", i+1);
        scanf("%ld", &listaDeTrabajo[i].DNI);
        
        while ((listaDeTrabajo[i].DNI > 00000001) || (listaDeTrabajo[i].DNI < 99999999)) {
          system("clear");
          printf("\n---ERROR---\n");
          printf("Ingrese el DNI del trabajador N %d \n", i+1);
          scanf("%ld", &listaDeTrabajo[i].DNI);
        }
        
        printf("\n Ingrese el poder en el que trabaja el trabajador N %d \n", i+1);
        fflush(stdin);
        scanf("%s",listaDeTrabajo[i].Poder);
        printf("\n Ingrese el partido politico que milita el trabajador N %d \n", i+1);
        fflush(stdin);
        scanf("%s",listaDeTrabajo[i].partidoPolitico);
        printf("\n Que tarea desarrolla el trabajador N %d elegir entre la tarea 1 a la 5 \n", i+1);
        scanf("%d", &opcionDeTarea);
        
        switch(opcionDeTarea){
          case1:
            printf(" Selecciono la tarea N 1: %s con complejidad %d \n", listaDeTareas[opcionDeTarea-1].descripcion,listaDeTareas[opcionDeTarea-1].complejidad);
            listaDeTrabajo[i].tarea.complejidad = listaDeTareas[opcionDeTarea-1].complejidad;
            strcpy(listaDeTrabajo[i].tarea.descripcion,listaDeTareas[opcionDeTarea-1].descripcion); 
          
          break;
          case2:
            ///printf(" Selecciono la tarea N 2: %s con complejidad %d \n", listaDeTareas[opcionDeTarea-1].descripcion,listaDeTareas[opcionDeTarea-1].complejidad);
            listaDeTrabajo[i].tarea.complejidad = listaDeTareas[opcionDeTarea-1].complejidad;
            strcpy(listaDeTrabajo[i].tarea.descripcion,listaDeTareas[opcionDeTarea-1].descripcion); 
          
          break;
          case3:
            ///printf(" Selecciono la tarea N 3: %s con complejidad %d \n", listaDeTareas[opcionDeTarea-1].descripcion,listaDeTareas[opcionDeTarea-1].complejidad);
            listaDeTrabajo[i].tarea.complejidad = listaDeTareas[opcionDeTarea-1].complejidad;
            strcpy(listaDeTrabajo[i].tarea.descripcion,listaDeTareas[opcionDeTarea-1].descripcion); 

          break;
          case4:
            ///printf(" Selecciono la tarea N 4: %s con complejidad %d \n", listaDeTareas[opcionDeTarea-1].descripcion,listaDeTareas[opcionDeTarea-1].complejidad);
            listaDeTrabajo[i].tarea.complejidad = listaDeTareas[opcionDeTarea-1].complejidad;
            strcpy(listaDeTrabajo[i].tarea.descripcion,listaDeTareas[opcionDeTarea-1].descripcion); 
          
          break;
          case5:
            ///printf(" Selecciono la tarea N 5: %s con complejidad %d \n", listaDeTareas[opcionDeTarea-1].descripcion,listaDeTareas[opcionDeTarea-1].complejidad);
            listaDeTrabajo[i].tarea.complejidad = listaDeTareas[opcionDeTarea-1].complejidad;
            strcpy(listaDeTrabajo[i].tarea.descripcion,listaDeTareas[opcionDeTarea-1].descripcion); 
          
          break;
        }
        
      }
     
      printf("\n \n");
      bandera = true;
      break;
    case 2:
      system("clear");
      printf("\n --- A seleccionado la opcion 2 --- \n");
      if (bandera == true) {
        calcularEstres(listaDeTareas);
        printf("\n \n");

      } else {
        printf("\n Debe ingresar primero la opcion 1 para poder usar esta "
               "opcion \n");
      }
      break;
    case 3:
      system("clear");
      printf("\n --- A seleccionado la opcion 3 --- \n");
      personasEstresadas(listaDeTrabajo, 5);
      



      
      if (bandera == true) {

      } else {
        printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");
      }
      break;
    case 4:
      system("clear");
      printf("\n --- A seleccionado la opcion 4 ---\n");
      printf("\n \n");
      if (bandera == true) {

      } else {
        printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");
      }
      break;
    case 5:
      system("clear");
      printf("\n --- A seleccionado la opcion 4 ---\n");
      printf("\n \n");
      if (bandera == true) {

      } else {
        printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");
      }
      break;
    default:
      printf("\n---Opcion incorrecta---\n");
      break;
    }
  }
  return 0;
}
