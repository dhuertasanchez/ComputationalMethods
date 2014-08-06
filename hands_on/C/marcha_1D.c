#include <stdio.h>
#include <stdlib.h>

int main(){
  double random;
  int i,k;
  double x=0;

  for(k=0;k<1000;k++){
    srand48(k);
    x=0;
    for(i=0;i<100000;i++){
      random = 2.0*drand48() - 1.0;
      x = x + random;
    }
    printf("%f\n", x);
  }


  return 0;
}
