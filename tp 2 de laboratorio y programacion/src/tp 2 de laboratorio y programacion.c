/*
 ============================================================================
 Name        : tp.c
 Author      : Ivan Paco
 Version     :Ivan Paco 1|k
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayPassenger.h"
#define tam 2000

int main(void) {
	setbuf(stdout, NULL);
	int opcion,a1;
	int x=0;
	int id=1000;
	Passenger pasajero[tam];
	inicializarEstado(pasajero,tam);
	do{
		opcion=menu("\n--- Menu ---\n1-Alta\n2-Modificar\n3-Baja\n4-Informar\n6-Salir\n...");
		switch(opcion)
		{
		case 1:
			id++;
			a1=alta(pasajero,tam,id);
			if(a1==1)
			{printf("\nLa carga fue exitosa");
			x=1;}
			break;
		case 2:
			if(x==1)
			{
				a1=0;
				a1=modificar(pasajero,tam);
				if(a1==1)
				{printf("\nLa modificacion fue exitosa");}
			}
			else{printf("\nPrimero realiza una carga!!");}
				break;
		case 3:
			if(x==1)
			{
				a1=0;
				a1=baja(pasajero,tam);
				if(a1==1)
				{printf("\nLa baja fue exitosa");}
			}
			else{printf("\nPrimero realiza una carga!!");}
				break;
		case 4:
			if(x==1)
			{
				a1=0;
				a1=informar(pasajero,tam);
				if(a1==1)
				{printf("\nEl listado fue exitoso");}
			}
			else{printf("\nPrimero realiza una carga!!");}
				break;
		case 6:
			printf("\nSaliste del menu");
				break;
		default:
			printf("\nOpcion incorrecta!!!");
			break;

		}
	}while(opcion!=6);
	return EXIT_SUCCESS;
}
