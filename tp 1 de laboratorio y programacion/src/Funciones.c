/*
 * conjuntoDeFunciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: user
 */
#include <stdio.h>
#include <stdlib.h>

int pedirDatosNumericos(char mensaje[], char error[])
{
	int numeroIngresado;

	printf("%s" ,mensaje);
	scanf("%d" ,&numeroIngresado);

	while(numeroIngresado < 0)
	{
		printf("%s" ,error);
		scanf("%d" ,&numeroIngresado);
	}
	return numeroIngresado;
}
void menuSecundario(void)
{
	printf("a) Tarjeta de debito (descuento 10%)\n");
	printf("b) Tarjeta de credito (interés 25%)\n");
	printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("d) Mostrar precio por km (precio unitario)\n");
	printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n\n");
}

void ofertas(int precio, int kilometros)
{
	//variables de descuento.
	float descuento;
	float precioFinalDescuento;
	//variables de interes.
	float interes;
	float precioFinalInteres;
	// convertibilidad de pesos a bitcoin.
	float convertor;
	//preciounitario.
	float unitario;
	//descuento del 10%
	descuento = precio * 10/100;
	precioFinalDescuento = precio - descuento;
	//interes
	interes = precio * 25/100;
	precioFinalInteres = precio + interes;
	//convertor.
	convertor = precio / 4606954.55;

	//preciounitario.
	unitario = precio / kilometros ;

	//descuento
	printf("El descuento es de: $ %f\n",precioFinalDescuento);
	//interes
	printf("El interes es de: $ %f\n",precioFinalInteres);
	//convertibilidad.
	printf("El precio en Bitcoin es de: B %f\n",convertor);
	//unitario.
	printf("El precio por kl es de: $ %f\n",unitario);
}
char pedirEmpresa(char vuelo[], char error[])
{
	char opcion;
	printf("%s" , vuelo);
	scanf("%s" ,&opcion);

	while(opcion != 'y' && opcion != 'z' && opcion != 'v')
	{
	printf("%s ", error);
	scanf("%s",&opcion);
	}
	return opcion;
}
