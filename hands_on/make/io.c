#include <stdio.h>
#include "geometry.h"

void print_points(n_points){
  int i;
  float radius;
  float volume;
  float surface;
  
  /*initialization*/
  radius = 0.0;
  volume = 0.0;
  surface = 0.0;

  printf("Radius Surface Volume\n");
  /*loop over n_points different values for the radius*/
  for(i=0; i<n_points; i++){
    radius = 1.0*i;

    surface = get_surface(radius); /*call to the function radius*/
    volume = get_volume(radius);  /*call to the function volume*/

    /*output the values to the screen*/
    printf("%f %f %f\n", radius, surface, volume);
  }  
}
