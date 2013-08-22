/* 
   Example showing two ways to make an allocation from a function.
*/
#include <stdio.h>
#include <stdlib.h>

void bad_function(int *list, int n_points);
int * good_function(int n_points);

int main(void){
  int *lista;
  int n_points = 10;
  lista = NULL; 

  /*let's try the first function*/
  bad_function(lista, n_points);

  /*did it work?*/
  if(!lista){
    printf("the array is not allocated yet (address %p)\n", lista);
  }else{
    printf("the array has been allocated (address %p)\n", lista);
  }

  /*let's try the first function*/
  lista = good_function(n_points);

  /*did it work?*/
  if(!lista){
    printf("the array is not allocated yet (address %p)\n", lista);
  }else{
    printf("the array has been allocated (address %p)\n", lista);
  }

  return 0;
}

void bad_function(int *list, int n_points){
  list = malloc(n_points* sizeof(int));
}

int * good_function(int n_points){
  int *array;
  array = malloc(n_points * sizeof(int));
  return array;
}
