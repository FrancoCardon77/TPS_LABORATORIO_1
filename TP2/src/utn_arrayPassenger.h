/*
 * utn_arrayPassenger.h
 *
 *  Created on: 28 abr. 2022
 *      Author: FRANCO
 */

#ifndef UTN_ARRAYPASSENGER_H_
#define UTN_ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_funciones.h"

#endif /* UTN_ARRAYPASSENGER_H_ */

struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int isEmpty;
}typedef Passenger;


int initPassengers(Passenger *list, int len);
int addPassenger(Passenger *list, int len, int id, char name[], char lastName[],
float price, int typePassenger, char flycode[]);
int findPassengerById(Passenger *list, int len, int id);
int removePassenger(Passenger *list, int len, int id);
int hayAlgoCargado(Passenger *list, int len);
int modificarPasajero(Passenger *list, int id, int len);
int sortPassengers(Passenger *list, int len, int order);
void menu();
int promedioPassengers(Passenger *list, int len);
int printPassenger(Passenger * list, int len);

