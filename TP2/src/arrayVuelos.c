/*
 * arrayVuelos.c
 *
 *  Created on: 14 may. 2022
 *      Author: FRANCO
 */

#include "arrayVuelos.h"
#include "utn_funciones.h"


/*
 * @brief cuando se carga un pasajero se asigna un vuelo
 * @param Vuelo * vuelos: estructura de vuelo que se interrelaciona por el flyCode como un ID con la estructura Passenger
 * @param statusFlight: el estado del vuelo
 * @param flyCode: codigo de vuelo a asignar
 * @param len: largo de la estructura
 */
int addFlight(Vuelo * vuelos,int statusFlight, char flyCode[],int len) {
	int retorno;
	retorno = -1;
	int flagRelacion = 0;
	static int j = 0;

	if (vuelos != NULL && statusFlight >= 0 && flyCode != NULL) {
		for (int i = 0; i < len; i++) {
			if (stricmp(flyCode, vuelos[i].flyCode) == 0) {
				retorno = 0;
				flagRelacion = 1;
				vuelos[i].statusFlight = statusFlight;
				break;
			}

		}
		if (flagRelacion == 0) {
			strcpy(vuelos[j].flyCode, flyCode);
			vuelos[j].statusFlight = statusFlight;
			j++;
			retorno = 0;
		}

	}

	return retorno;

}
