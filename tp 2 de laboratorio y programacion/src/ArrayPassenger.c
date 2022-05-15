/*
 * Funciones.c
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

int menu(char mensaje[])
{
	int retorno;
	retorno=pedirNumero(mensaje);
	return retorno;
}
//   initPassengers
void inicializarEstado(Passenger pasajero[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		pasajero[i].isEmpty=0;
	}
}
int buscarEstado(Passenger pasajero[], int tam)
{
	int retorno=-1,i;

	for(i=0;i<tam;i++)
	{
		if(pasajero[i].isEmpty==0)
		{
			retorno=i;
			break;
		}

	}

	return retorno;
}
int alta(Passenger pasajero[],int tam, int id)
{
	int retorno;
	int indice;
	indice=buscarEstado(pasajero, tam);
	if(indice!=-1)
	{
		pasajero[indice].id=id;
		//pasajero[indice].name[51]=pedirCaracter("\nIngrese el Nombre: ");
		printf("\nIngrese el Nombre: ");
		scanf("%s",pasajero[indice].name);
		//pasajero[indice].lastName[51]=pedirCaracter("\nIngrese el/los Apellido/s: ");
		printf("\nIngrese el Apellido: ");
		scanf("%s",pasajero[indice].lastName);
		pasajero[indice].price=precio("\nIngrese el precio: ","Error, reingrese el precio: ");
		//pasajero[indice].flycode[10]=pedirCaracter("\nIngrese el codigo de vuelo: ");
		printf("\nIngrese el codigo de vuelo: ");
		scanf("%s",pasajero[indice].flycode);
		pasajero[indice].typePassenger=numeroP("\nIngrese el tipo de pasajero: ([1-Primera clase]/[2-Clase turistica]/[3-Ejecutiva])","\nError, ingrese el tipo de pasajero: ([1-Primera clase]/[2-Clase turistica]/[3-Ejecutiva])");
		pasajero[indice].isEmpty=1;
		retorno=1;
		printf("\nID: %d" ,pasajero[indice].id);
	}
	else
	{
		retorno=0;
	}

	return retorno;
}
int buscarId(Passenger pasajero[], int tam)
{
	int i, retorno=-1,idBuscada;

	idBuscada=numeroP("\nIngrese la Id: ","\nError, Ingrese la id: ");
	for(i=0;i<tam;i++)
	{
		if(pasajero[i].id==idBuscada&&pasajero[i].isEmpty==1)
		{
			retorno=i;
			break;
		}
	}

	return retorno;
}
int modificar(Passenger pasajero[], int tam)
{
	int retorno,m,opcion;

	m=buscarId(pasajero,tam);
	if(m!=-1)
	{
		opcion=pedirNumero("\n1-Nombre\n2-Apellido\n3-precio\n4-Tipo de pasajero\n5-Codigo de vuelo\n6-Salir");
		switch(opcion)
		{
		case 1:
			printf("\nIngrese el Nombre: ");
			fflush(stdin);
			scanf("%s",pasajero[m].name);
			retorno=1;
			break;
		case 2:
			printf("\nIngrese el Apellido: ");
			fflush(stdin);
			scanf("%s",pasajero[m].lastName);
			retorno=1;
					break;
		case 3:
			pasajero[m].price=precio("\nIngrese el precio: ","Error, reingrese el precio: ");
			retorno=1;
					break;
		case 4:
			pasajero[m].typePassenger=numeroP("\nIngrese el tipo de pasajero: ([1-Primera clase]/[2-Clase turistica]/[3-Ejecutiva])","\nError, ingrese el tipo de 	pasajero: ([1-Primera clase]/[2-Clase turistica]/[3-Ejecutiva])");
			retorno=1;
					break;
		case 5:
			printf("\nIngrese el codigo de vuelo: ");
			fflush(stdin);
			scanf("%s",pasajero[m].flycode);
			retorno=1;
					break;
		case 6:
			printf("\nSaliste de modificar!!!");
					break;
		default:
			break;
		}
	}
	else{printf("\nNo se encontro la ID");
	retorno=0;}
	return retorno;
}
int baja(Passenger pasajero[], int tam)
{
	int retorno=0,idBuscada;
	int opcion;

	idBuscada=buscarId(pasajero, tam);
	if(idBuscada!=-1){
		printf("\nNombre: %s\nApellido: %s",pasajero[idBuscada].name,pasajero[idBuscada].lastName);
		printf("\nPrecio: %f\nCodigo de vuelo: %s\nTipo pasajero: %d",pasajero[idBuscada].price,pasajero[idBuscada].flycode,pasajero[idBuscada].typePassenger);
	opcion=numeroP("\nDesea dar de baja? [1-si][2-no]: ","\nError, Desea dar de baja? [1-si][2-no]: ");
	if(opcion==1){
		if(idBuscada!=-1)
		{
			pasajero[idBuscada].isEmpty=0;
			retorno=1;
		}
	}
	else{printf("\nNo se dio de baja");}
	}
	else{printf("\nLa id no existe!!!");}
	return retorno;
}
int ordenamiento(Passenger pasajero[],int tam)
{
	int retorno=0,i,j;
	Passenger aux;
	for(i=0;i<tam;i++)
	{
		for(j=i+1;j<tam;j++)
		{
			if((stricmp(pasajero[i].lastName,pasajero[j].lastName)>0)||(pasajero[i].typePassenger>pasajero[j].typePassenger))
			{
				aux=pasajero[i];
				pasajero[i]=pasajero[j];
				pasajero[j]=aux;
				retorno=1;
			}
		}
	}

	return retorno;
}
void Precios(Passenger pasajero[],int tam)
{
	int i,x=0,z=0;
	float total=0,promedio;
	for(i=0;i<tam;i++)
	{
		if(pasajero[i].isEmpty==1){
			total=total+pasajero[i].price;
			x++;
		}
	}
	promedio=total/x;
	for(i=0;i<tam;i++)
	{
		if(pasajero[i].price>promedio&&pasajero[i].isEmpty==1)
		{
			z++;
		}
	}
	printf("\nEl total de los precio es: %f\nEl promedio de los precios es: %f\nCantidad de precios que superan el promedio: %d",total,promedio,z);
}
void listadoCodigoVueloActivo(Passenger pasajero[], int tam)
{
	int i,j;
	Passenger aux;
	printf("\nCodigos de vuelos: \n");

	for(i=0;i<tam;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				if((stricmp(pasajero[i].flycode,pasajero[j].flycode)>0))
				{
					aux=pasajero[i];
					pasajero[i]=pasajero[j];
					pasajero[j]=aux;
				}
			}
		}

	for(i=0;i<tam;i++)
	{
		if(pasajero[i].isEmpty==1)
		{
			printf("\n[ %s ]",pasajero[i].flycode);
		}
	}


}
void mostrarTodo(Passenger pasajero[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(pasajero[i].isEmpty==1){printf("\nNombre: %s\nApellido: %s",pasajero[i].name,pasajero[i].lastName);
		printf("\nPrecio: %f\nCodigo de vuelo: %s\nTipo pasajero: %d\n",pasajero[i].price,pasajero[i].flycode,pasajero[i].typePassenger);
		}
	}
}
int informar(Passenger pasajero[],int tam)
{
	int retorno=0;
	int x;
	int opcion;

	opcion=pedirNumero("\n1-Ordenar por apellido y tipo de pasajero\n2-Precios/promedio\n3-Listado por codigo de vuelo y estado activo\n6-Salir");
	switch(opcion)
	{
	case 1:
		x=ordenamiento(pasajero,tam);
		if(x==1)
		{printf("\nOrdenamiento exitoso");
		mostrarTodo(pasajero,tam);}
		retorno=1;
		break;
	case 2:
		Precios(pasajero,tam);
		retorno=1;
			break;
	case 3:
		listadoCodigoVueloActivo(pasajero,tam);
		retorno=1;
			break;
	case 6:
		printf("\nSaliste del sub menu");
		break;
	default:
		printf("\nOpcion incorrecta!!!");
		break;
	}


	return retorno;
}

