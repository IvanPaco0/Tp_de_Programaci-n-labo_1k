/*
 * conjuntosDeFunciones.h
 *
 *  Created on: 10 abr. 2022
 *      Author: user
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @param mensaje
/// @param error
/// @return retorna el numero validado.
int pedirDatosNumericos(char mensaje[], char error[]);

/// @param precio
/// @param precio2
void ofertas(int precio, int kilometros);

///menu secundario.
void menuSecundario();
///pedir una opcion
char pedirEmpresa(char vuelo[], char error[]);

#endif /* FUNCIONES_H_ */
