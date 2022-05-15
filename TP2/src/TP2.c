/*
 ============================================================================
 Name        : TP2.c
 Author      : franco emmanuel cardon // hecho con mucho orgullo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_funciones.h"
#include "InformeVueloYPasajero.h"

void CargaForzada(Passenger * list, Vuelo * vuelos);

#define QTY_PASSENGERS 25
int main(void) {
	setbuf(stdout, NULL);
	Passenger pasajeros[QTY_PASSENGERS];
	Vuelo vuelos[QTY_PASSENGERS];
	int validacionRetorno;
	int opcionMenu;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[10];
	int auxStatusFlight;
	static int id = 1;
	int respuesta = 0;
	int idAmodificar;
	int idAEliminar;
	int order;

	for (int i = 0; i < QTY_PASSENGERS; i++) {
		initPassengers(pasajeros, QTY_PASSENGERS);
	}

	do {
		menu();

		validacionRetorno = utn_getNumero(&opcionMenu,
				"\nElija una opción del menú: ", "Error", 1, 5, 3);

		if (validacionRetorno == 0) {
			switch (opcionMenu) {
			case 1:
				do {

					if (utn_getNombre(auxName, 51,
							"\nIngrese el nombre del pasajero: ", " Error. ", 3)
							== 0) {
						if (utn_getNombre(auxLastName, 51,
								"\nIngrese el apellido del pasajero: ",
								" Error. ", 3) == 0) {

							if (utn_getNumeroFlotante(&auxPrice,
									"\nIngrese el precio: ", " Error. ", 0,
									9999999, 3) == 0) {

								if (utn_getNumero(&auxTypePassenger,
										"\nIngrese el tipo de pasajero: (1 C. VIP - 2 C. EJECUTIVA - 3 C. ECONOMICA)",
										" Error.", 1, 3, 3) == 0) {

									if (utn_getNumero(&auxStatusFlight,
											"\nIngrese el estado del vuelo: (1 ACTIVO - 2 CANCELADO - 3 DEMORADO)",
											" Error.", 1, 3, 3) == 0) {

										if (utn_getDescripcion(auxFlyCode, 10,
												"\nIngrese el código de vuelo: ",
												" Error.", 3) == 0) {

											if (addPassenger(pasajeros,
											QTY_PASSENGERS, id, auxName,
													auxLastName, auxPrice,
													auxTypePassenger,
													auxFlyCode) == 0) {
												id++;
												addFlight(vuelos,
														auxStatusFlight,
														auxFlyCode,
														QTY_PASSENGERS);
											}

										}
									}
								}
							}
						}
					}

					utn_getNumero(&respuesta,
							"\n¿Desea ingresar otro pasajero? 1 para si - 2 para no: ",
							" Error.", 1, 2, 3);
				} while (respuesta == 1);

				break;
			case 2:
				if (hayAlgoCargado(pasajeros, QTY_PASSENGERS)) {
					utn_getNumero(&idAmodificar,
							"\nIngrese el ID a modificar: ", "Error", 1, 3, 3);
					modificarPasajero(pasajeros, QTY_PASSENGERS, idAmodificar);
				}

				break;

			case 3:
				if ((hayAlgoCargado(pasajeros, QTY_PASSENGERS))) {
					if (utn_getNumero(&idAEliminar,
							"\nIngrese el ID a Eliminar: ", "Error", 1, 3, 3)
							== 0) {
						removePassenger(pasajeros, QTY_PASSENGERS, idAEliminar);
					}
				}
				break;

			case 4:
				utn_getNumero(&respuesta,
						"\nElija el menú: 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’",
						" Error.", 1, 3, 3);
				switch (respuesta) {
				case 1:
					utn_getNumero(&order,
							"\nComo desea ordenarlos 1 ascendente 0 descendente.",
							"Error", 0, 1, 3);
					sortPassengers(pasajeros, QTY_PASSENGERS, order);
					printPassenger(pasajeros, QTY_PASSENGERS);
					break;
				case 2:
					promedioPassengers(pasajeros, QTY_PASSENGERS);
					break;
				case 3:
					utn_getNumero(&order,
							"\nComo desea ordenarlos 1 ascendente 0 descendente.",
							"Error", 0, 1, 3);
					sortPassengersByCode(pasajeros, QTY_PASSENGERS, order,
							vuelos);
					printPassengerByCodeYStatus(pasajeros, QTY_PASSENGERS,
							vuelos);
					break;
				}
				break;
				case 5: CargaForzada(pasajeros, vuelos);
						break;
			}

		}
	} while (opcionMenu > 0 || opcionMenu <= 5);

	return 0;
}

void CargaForzada(Passenger * list, Vuelo * vuelos)
{
	strcpy(list[0].name, "Juan");
	strcpy(list[0].lastName, "Perez");
	list[0].id = 1;
	list[0].price = 133000;
	list[0].typePassenger = 1;
	list[0].isEmpty = 0;
	strcpy(list[0].flyCode, "AAA01");
	strcpy(vuelos[0].flyCode, "AAA01");
	vuelos[0].statusFlight = 1;

	strcpy(list[1].name, "Rodrigo");
	strcpy(list[1].lastName, "Lazaro");
	list[1].id = 2;
	list[1].price = 133000;
	list[1].typePassenger = 1;
	list[1].isEmpty = 0;
	strcpy(list[1].flyCode, "AZZ02");
	strcpy(vuelos[1].flyCode, "AZZ02");
	vuelos[1].statusFlight = 1;

	strcpy(list[2].name, "Rodrigo");
	strcpy(list[2].lastName, "Lazaro");
	list[2].id = 3;
	list[2].price = 128000;
	list[2].typePassenger = 2;
	list[2].isEmpty = 0;
	strcpy(list[2].flyCode, "BFF11");
	strcpy(vuelos[2].flyCode, "BFF11");
	vuelos[2].statusFlight = 1;

	strcpy(list[3].name, "Cristina");
	strcpy(list[3].lastName, "Macri");
	list[3].id = 4;
	list[3].price = 128000;
	list[3].typePassenger = 3;
	list[3].isEmpty = 0;
	strcpy(list[3].flyCode, "CFB22");
	strcpy(vuelos[3].flyCode, "CFB22");
	vuelos[3].statusFlight = 2;

	strcpy(list[4].name, "Nisman");
	strcpy(list[4].lastName, "Larreta");
	list[4].id = 4;
	list[4].price = 128000;
	list[4].typePassenger = 2;
	list[4].isEmpty = 0;
	strcpy(list[4].flyCode, "FFF112");
	strcpy(vuelos[4].flyCode, "FFF112");
	vuelos[4].statusFlight = 3;
}
