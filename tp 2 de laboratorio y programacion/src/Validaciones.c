/*
 * Validaciones.c
 *Ivan Paco 1|k
 *  Created on: 13 may. 2022
 *      Author: user
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayPassenger.h"
//funcion sin uso
int pedirCaracter(char mensaje[])
{
	setbuf(stdout, NULL);
	char caracter;

	printf(mensaje);
	scanf("%s",&caracter);

	return caracter;
}
int pedirNumero(char mensaje[])
{
	int numero;
	printf(mensaje);
	scanf("%d",&numero);

	return numero;
}
int pedirEdad(char mensaje[], char error[])
{
	int edad;
	printf(mensaje);
	scanf("%d",&edad);
	while(edad < 0 || edad > 120 )
	{
		printf(error);
		scanf("%d",&edad);
	}
	return edad;
}
int numeroP(char mensaje[],char error[])
{
	int precio;
	printf(mensaje);
	scanf("%d",&precio);
	while(precio<0)
	{
		printf(error);
		scanf("%d",&precio);
	}

	return precio;
}
int fecha(char mensaje[],char error[],int limite)
{
	int dia;
	printf(mensaje);
	scanf("%d",&dia);
	while(dia<0||dia>limite)
	{
		printf(error);
		scanf("%d",&dia);
	}

	return dia;
}
int precio(char mensaje[],char error[])
{
	float precio;
	printf(mensaje);
	scanf("%f",&precio);
	while(precio<0)
	{
		printf(error);
		scanf("%f",&precio);
	}

	return precio;
}

