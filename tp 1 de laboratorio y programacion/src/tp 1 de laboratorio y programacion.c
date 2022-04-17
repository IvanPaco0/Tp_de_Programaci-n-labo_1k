/*
 ============================================================================
 Name        : tp.c
 Author      : Ivan Paco
 Version     :	TP 1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//Al ingresar una letra donde se pide numero el programa de rompe
//estoy buscando algunas soluciones para ello.

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void)
{
	setbuf(stdout, NULL);

	int menu;
	int ingresoKilometros;
	int precioDeVuelosAerolineas;
	int precioDeVuelosLatam;
	int salir=0;
	int i=0;
	char opcion;
	int diferencia;

	do{
	printf("\n 1-Ingresar Kilometros: \n ");
	printf("2-Ingresar Precio de Vuelos: \n ");
	printf("3-Calcular todos los costos: \n ");
	printf("4-Informar Resultados \n ");
	printf("5-Carga forzada de datos \n ");
	printf("6-Salir \n \n");

	menu = pedirDatosNumericos("Ingrese una opcion: " , "No es un numero valido");


	switch(menu)
	{
	case 1:
		ingresoKilometros  = pedirDatosNumericos("Ingrese los kilometros: " , "Error, reingrese los kilometros: ");
		i = 1;
		break;
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 2:

		if(i==1 || i == 2 || i == 3 || i == 4){
			i=2;
			opcion=pedirEmpresa("Ingresa \n y - Aerolineas \n z - Latam\n v - Ambas \n","Error, ingresa \n y - Aerolineas \n z - Latam\n v - Ambas \n");
			//switch(opcion)
			switch(opcion)
			{
			case 'y':
				precioDeVuelosAerolineas = pedirDatosNumericos("Ingrese el precio del vuelo de Aerolineas: " , "Error, reingrese el precio: ");
				break;
			case 'z':
				precioDeVuelosLatam = pedirDatosNumericos("Ingrese el precio del vuelo de Latam: " , "Error, reingrese el precio: ");
				break;
			case 'v':
				precioDeVuelosAerolineas = pedirDatosNumericos("Ingrese el precio del vuelo de Aerolineas: " , "Error, reingrese el precio: ");
				precioDeVuelosLatam = pedirDatosNumericos("Ingrese el precio del vuelo de Latam: " , "Error, reingrese el precio: ");
				break;
			}
			}
		else {printf(" No se pudo acceder a la opcion, recuenda que se ingresa en orden de menor a mayor\n");}
		break;
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 3:
		if(i == 2 || i == 3 || i == 4)
		{i = 3;
		menuSecundario();
		opcion=pedirEmpresa("Ingresa la opcion a calcular.  \n y - Aerolineas \n z - Latam\n v - Ambas \n","Error, ingresa \n y - Aerolineas \n z - Latam\n v - Ambas \n");}
		else{printf(" No se pudo acceder a la opcion, recuenda que se ingresa en orden de menor a mayor\n");}
		break;
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 4:
		if(i == 3 || i == 4)
		{i=4;
			switch(opcion)
			{
			case 'y':
				printf("\nAerolineas\n");
				ofertas(precioDeVuelosAerolineas, ingresoKilometros);
				break;
			case 'z':
				printf("\n Latam \n");
				ofertas(precioDeVuelosLatam, ingresoKilometros);
				break;
			case 'v':
				printf("\n Aerolineas\n");
				ofertas(precioDeVuelosAerolineas, ingresoKilometros);
				printf("\n Latam\n");
				ofertas(precioDeVuelosLatam, ingresoKilometros);
				break;
			}
			if(precioDeVuelosAerolineas >  precioDeVuelosLatam)
			{
				diferencia = precioDeVuelosAerolineas - precioDeVuelosLatam;
				printf("La diferencia de precios es: %d\n", diferencia);}
			else if(precioDeVuelosAerolineas <  precioDeVuelosLatam)
			{
				diferencia = precioDeVuelosLatam - precioDeVuelosAerolineas;
				printf("\nLa diferencia es de: $%d\n", diferencia);}
		}
		else{printf(" No se pudo acceder a la opcion, recuenda que se ingresa en orden de menor a mayor\n");}
		break;
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 5:
		ingresoKilometros=7090;
		precioDeVuelosAerolineas=162965;
		precioDeVuelosLatam=159339;
		i=3;
		break;
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 6:
		printf("Saliste del menu");
		salir=6;
		break;
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	default:
		printf("\nOpcion no existente\n");
		break;
	}
	}while(salir == 0);
	return EXIT_SUCCESS;
}
