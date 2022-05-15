/*
 * informeVueloYPasajero.c
 *
 *  Created on: 14 may. 2022
 *      Author: FRANCO
 */

#include "informeVueloYPasajero.h"

/*
 * @brief ordena a los pasajeros por codigo de vuelo
 * @param Passenger * list: pide la estructura
 * @param len:pide el largo
 * @param order: de que manera desea ordenar 1 o 0
 * @param vuelos: pide la estructura interrelacionada Vuelo para ordenarlo por codigo de vuelo y estado de vuelo
 */

int sortPassengersByCode(Passenger * list, int len, int order, Vuelo * vuelos)
{
	int retorno;
    int i;
    int estaOrdenado;
    retorno = -1;

    Passenger aux;

    if (list != NULL && len > 0) {
        if (order == 0) {
            do {
                estaOrdenado = 1;
                len--;
                for (i = 0; i < len; i++) {
                    if (stricmp(list[i].flyCode, list[i + 1].flyCode) < 0) {
                        aux = list[i];
                        list[i] = list[i + 1];
                        list[i + 1] = aux;
                        estaOrdenado = 0;
                        retorno = 0;
                    } else if (stricmp(list[i].flyCode, list[i + 1].flyCode) != 0
                        && vuelos[i].statusFlight != 1 && vuelos[i + 1].statusFlight == 1) {
                        aux = list[i];
                        list[i] = list[i + 1];
                        list[i + 1] = aux;
                        estaOrdenado = 0;
                        retorno = 0;
                    }
                						  }
            } while (estaOrdenado == 0);

        } else if (order == 1) {
            do {
                estaOrdenado = 1;
                len--;
                for (i = 0; i < len; i++) {
                    if (stricmp(list[i].flyCode, list[i + 1].flyCode) > 0) {
                        aux = list[i];
                        list[i] = list[i + 1];
                        list[i + 1] = aux;
                        estaOrdenado = 0;
                        retorno = 0;
                    } else if (stricmp(list[i].flyCode, list[i + 1].flyCode)!= 1 && vuelos[i].statusFlight != 0 && vuelos[i + 1].statusFlight == 1) {
                        aux = list[i];
                        list[i] = list[i + 1];
                        list[i + 1] = aux;
                        estaOrdenado = 0;
                        retorno = 0;

                    }
                }
            } while (estaOrdenado == 0);
        }
    }

    return retorno;
}

/*
 * @brief imprime los pasajeros ordenados segun criterio de seleccion
 * @param Passenger * list: pide la estructura Passenger
 * @param len: pide el largo de la estructura
 * @param Vuelo: pide la estructura de vuelos para imprimir
 */
int printPassengerByCodeYStatus(Passenger * list,int len, Vuelo * vuelos)
{
	int retorno = -1;

	if(list != NULL && len >0)
	{	retorno = 0;
		for(int i=0; i<len;i++)
		{	if(list[i].isEmpty == 0)
			printf("\nID: %d \n nombre: %s \n apellido: %s \n precio: %.2f \n codigo de vuelo: %s \n tipo de pasajero: %d estado del vuelo: %d \n\n",
					list[i].id, list[i].name,
					list[i].lastName, list[i].price,
					list[i].flyCode, list[i].typePassenger, vuelos[i].statusFlight);

		}
	}

	return retorno;

}

