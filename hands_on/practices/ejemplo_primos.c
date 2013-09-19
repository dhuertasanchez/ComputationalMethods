/*
 * MateoRestrepo_primos.c
 *
 *  Created on: Aug 19, 2013
 *      Author: Mateo Restrepo
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

// Tamaño del arreglo de enteros.
#define LIMITE 1000000

// Tamaño del arreglo de primos.
#define PRIMOS 78498

int  main (int argc, char *argv[]){
	
	//Condicion que revisa si el usuario ingreso un parametro en la consola.
	if(argc!=2 ){
		printf("Se necesitan al menos dos parametros para ejecutar el programa!\nSALIR!\n");
		exit(1);

	}
	
	// Definición de las variables.
	int numero;

	int factores[1000];    
	int i_factores=0;      

	int *array_numeros;
	int *array_primos;

	array_numeros = malloc(LIMITE * sizeof(int));
	array_primos = malloc(PRIMOS* sizeof(int));

	int i;
	int j;

	numero = atoi(argv[1]);

	//Llenamos el areglo de naturales con todos los numeros hasta 1000000.
	for(i=0 ; i<= LIMITE; i++){
		array_numeros[i]=i+2;
	}
	

	//Seleccionamos los primos del arreglo de naturales.
	for (i=0;i<LIMITE;i++){
		if (array_numeros[i]!=-1){
			for (j=2*array_numeros[i]-2;j<LIMITE;j+=array_numeros[i])
				array_numeros[j]=-1;
		}
	}

	// Transferimos los primos a su propio arreglo
	j = 0;
	for (i=0;i<LIMITE && j<PRIMOS;i++)
		if (array_numeros[i]!=-1) 
			array_primos[j++] = array_numeros[i];


	//Condición que revisa si el número ingresado es negativo o mayor a 1000000.
	if(numero<0 || numero>LIMITE){
		printf("El número ingresado es negativo o mayor a 1000000!\nNo puedo proceder\n");
		exit(1);

	}
	
	//Condición que revisa si el número ingresado es 0 o 1
	if(numero==0 || numero==1){
		if(numero==0){
		printf("El 0 no es una entrada valida\n");
		exit(1);
		}
		else{
		printf("El 1 no se puede descomponer como la multiplicación de dos factores primos\n");
		exit(1);
		}
	}

	//Condición que revisa si el número ingresado es Primo, es decir no se puede descomponer.
	for(i=0; i<PRIMOS; i++){
		if(numero==array_primos[i]){
			printf("El %d es primo, no se puede factorizar!\n", numero);
			exit(1);
		}
	}
	
	//Ciclo que llena el array de factores con 0 en todas las posiciones
	for(i=0; i<1000; i++){
		factores[i]=0;	
	}

	//ciclo que incluye los factores del numero 
	int numeroaux=numero;
	i=2;
	while(i<=numeroaux){
	    //a%b=0, implica que b es factor de a.
	    if((numeroaux%i)==0)  
	    {
	    factores[i_factores]=i;  
	    numeroaux=numeroaux/i;        
	    i_factores++;            
	    continue;
	    }   
	  i++;  
	  }
	
	int contador=0;
	if(factores[2]==0){
		printf("El %d se puede descomponer como la multiplicación de:\n%d y %d\n ",numero, factores[0], factores[1]);
	}else{
		printf("El %d no se puede descomponer como la multiplicación de dos factores primos\n", numero);
	}
	
	return 0;
}















