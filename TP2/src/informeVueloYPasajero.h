/*
 * informeVueloYPasajero.h
 *
 *  Created on: 14 may. 2022
 *      Author: FRANCO
 */

#ifndef INFORMEVUELOYPASAJERO_H_
#define INFORMEVUELOYPASAJERO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_funciones.h"
#include "arrayVuelos.h"
#include "utn_arrayPassenger.h"

int sortPassengersByCode(Passenger * list, int len, int order, Vuelo * vuelos);
int printPassengerByCodeYStatus(Passenger * list,int tlen, Vuelo * vuelos);


#endif /* INFORMEVUELOYPASAJERO_H_ */
