#include <stdio.h>
#include <stdlib.h>

double make_walk(int *acer);
int main(int argc, char **argv){
  double last_value=0;
  int n_points=100;
  int n_walk = 3;
  int i;
  int semilla;
  int *l;
  semilla = atoi(argv[1]);
  l = &semilla;
 
  printf("la direccion donde vive semilla: %p\n", l);

  srand48(semilla);
  for(i=0;i<n_walk;i++){
    last_value = make_walk(&n_points);
    printf("%f\n", last_value);
  }
  printf("el nuevo valor de n_points %d\n",n_points);
  return 0;
}

double make_walk(int *acer){
  double x=0.0;
  int i;  
  for(i=0;i< *acer;i++){
    x = x + 2.0*(drand48()-0.5);
  } 
  *acer = 321;
  return x;
}

