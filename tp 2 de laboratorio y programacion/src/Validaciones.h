/*
 * Validaciones.h
 *Ivan Paco 1|k
 *  Created on: 13 may. 2022
 *      Author: user
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
//funcion sin uso
/// @param mensaje
/// @return caracteres como nombre o descripcion.
int pedirCaracter(char mensaje[]);
/// @param mensaje
/// @return retorna numero sea -0 o +0
int pedirNumero(char mensaje[]);
/// @param mensaje
/// @param error
/// @return retorna edad entre 0 a 120 años
int pedirEdad(char mensaje[], char error[]);
/// @param mensaje
/// @param error
/// @return numero +0
int numeroP(char mensaje[],char error[]);
/// @param mensaje
/// @param error
/// @param limite
/// @return dia,mes,año
int fecha(char mensaje[],char error[],int limite);
/// @param mensaje
/// @param error
/// @return precio en Float
int precio(char mensaje[],char error[]);



#endif /* VALIDACIONES_H_ */
