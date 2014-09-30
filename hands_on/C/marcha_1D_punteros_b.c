#include <stdio.h>
#include <stdlib.h>

void make_walk(double *walk, int npoints);
void print_walk(double *walk, int npoints);

void print_walk(double *walk, int npoints){  
  FILE *fileout;
  int i;  
  fileout = fopen("my_walk.dat", "w");
  for(i=0;i< npoints;i++){
    fprintf(fileout, "%f\n", walk[i]);
  } 
  fclose(fileout);
}

int main(int argc, char **argv){
  double *walk;
  int n_points=100;
  int semilla;

  semilla = atoi(argv[1]);  
  srand48(semilla);

  walk = malloc(n_points * sizeof(double));

  make_walk(walk, n_points);

  print_walk(walk, n_points);

  return 0;
}
void make_walk(double *walk, int npoints){
  double x=0.0;
  int i;  
  for(i=0;i< npoints;i++){
    x = x + 2.0*(drand48()-0.5);
    walk[i] = x;
  } 
}

