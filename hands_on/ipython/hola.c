#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  int i,n;
  n=atoi(argv[1]);
  
  for(i=0;i<n;i++){
    printf("Hola %d\n", i);
  }
  return 0;
}
