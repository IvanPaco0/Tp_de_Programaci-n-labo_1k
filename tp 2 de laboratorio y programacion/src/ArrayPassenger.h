/*
 * Funciones.h
 *  Ivan Paco 1|k
 *  Created on: 13 may. 2022
 *      Author: user
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct
{
int id;
//nombre
char name[51];
//apellido
char lastName[51];
//precio
float price;
// codigo volador
char flycode[10];
// tipoPasajero
int typePassenger;
// esta vacio
int isEmpty;
}typedef Passenger;

///\brief retorna un numero del menu
/// @return numero del menu.
/// retorna un numero del menu
int menu(char mensaje[]);
/// @param pasajero
/// @param tam
/// Inicializa los estados en 0,
/// solo una vez comenzado a funcionar el programa.
void inicializarEstado(Passenger pasajero[], int tam);
/// @param pasajero
/// @param tam
/// @return el lugar vacio
/// retorna la ubicacion del espacio vacio.
int buscarEstado(Passenger pasajero[], int tam);
/// @param pasajero
/// @param tam
/// @param id
/// @return 1 || 0
/// 1 en caso exitoso || o en caso fallido
int alta(Passenger pasajero[],int tam, int id);
/// @param pasajero
/// @param tam
/// @return posicion de la id
/// retorna la ubicacion de la id
int buscarId(Passenger pasajero[], int tam);
/// @param pasajero
/// @param tam
/// @return 1||0
/// 1 en caso exitoso || o en caso fallido
int modificar(Passenger pasajero[], int tam);
/// @param pasajero
/// @param tam
/// @return 1 || 0
/// 1 en caso exitoso || o en caso fallido
int baja(Passenger pasajero[], int tam);
/// @param pasajero
/// @param tam
/// @return ordenamiento
/// ordenamiento de doble criterio
int ordenamiento(Passenger pasajero[],int tam);
/// @param pasajero
/// @param tam
/// Muestra total de los precio, promedio de los precios, cantidad de precios que superan el promedio
void Precios(Passenger pasajero[],int tam);
/// @param pasajero
/// @param tam
/// listado de codigo de vuelo con estado activa
void listadoCodigoVueloActivo(Passenger pasajero[], int tam);
/// @param pasajero
/// @param tam
/// muestra todo
///
void mostrarTodo(Passenger pasajero[],int tam);
/// @param pasajero
/// @param tam
/// @return 1||0
/// 1 en caso exitoso || o en caso fallido
int informar(Passenger pasajero[],int tam);


#endif /* ARRAYPASSENGER_H_ */
