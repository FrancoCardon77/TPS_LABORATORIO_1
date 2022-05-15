/*
 * arrayVuelos.h
 *
 *  Created on: 14 may. 2022
 *      Author: FRANCO
 */

#ifndef ARRAYVUELOS_H_
#define ARRAYVUELOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
	char flyCode[10];
	int statusFlight;
}typedef Vuelo;

#endif /* ARRAYVUELOS_H_ */

int addFlight(Vuelo *vuelos, int statusFlight, char flyCode[], int len);

