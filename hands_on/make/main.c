/*
  Prints a table of values corresponding to 
  the radius of a sphere, its surface and volume.

  The function doing the printing is defined outside the main.c 
*/

#include <stdio.h>
#include "io.h"

int main(void){
  /*defines the variables*/
  int n_points =12;

  /*call to the external function*/
  print_points(n_points); 
  return 0;
}
