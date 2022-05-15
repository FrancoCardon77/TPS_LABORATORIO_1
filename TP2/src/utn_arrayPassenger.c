/*
 * utn_arrayPassenger.c
 *
 *  Created on: 28 abr. 2022
 *      Author: FRANCO
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn_arrayPassenger.h"
#include "utn_funciones.h"
/*@brief ordena de manera ascendente y descendete por apellido y tipo de pasajero
 * @param Passenger * list: es el primer parametro que pide la estructura
 * @param len: pide el largo del arreglo de estructuras creadas
 * @param order: 1 o 0 para ordenar de forma descendente o ascendete.
 */
int sortPassengers(Passenger *list, int len, int order) {
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
	                    if (stricmp(list[i].lastName, list[i + 1].lastName) < 0) {
	                        aux = list[i];
	                        list[i] = list[i + 1];
	                        list[i + 1] = aux;
	                        estaOrdenado = 0;
	                        retorno = 0;
	                    } else if (stricmp(list[i].lastName, list[i + 1].lastName)
	                            == 0
	                            && list[i].typePassenger
	                                    < list[i + 1].typePassenger) {
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
	                    if (stricmp(list[i].lastName, list[i + 1].lastName) > 0) {
	                        aux = list[i];
	                        list[i] = list[i + 1];
	                        list[i + 1] = aux;
	                        estaOrdenado = 0;
	                        retorno = 0;
	                    } else if (stricmp(list[i].lastName, list[i + 1].lastName)== 0 && list[i].typePassenger > list[i + 1].typePassenger) {
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
 * @brief verifica que haya un pasajero cargado en algun indice de las estructuras
 * @param Passenger * list: pide la estructura
 * @param len: pide el largo del arreglo de estructuras creadas
 */
int hayAlgoCargado(Passenger *list, int len) {
	int retorno = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				retorno = 1;
			}
		}
	}

	return retorno;
}

/*
 * @brief elimina una estructura creada por ID.
 * @param Passenger * list: pide la estructura
 * @param len: pide el largo del arreglo de estructuras creadas
 * @param id: pide el id para matchear buscando por indice e eliminarlo
 */
int removePassenger(Passenger *list, int len, int id) {
	int retorno = -1;
	int index;
	int respuesta;

	index = findPassengerById(list, len, id);

	if (utn_getNumero(&respuesta,
			"\nDesea eliminar el pasajero? 1 para si - 2 para no", "Error", 1,
			2, 3) == 0) {
		if (respuesta == 1) {
			retorno = 0;
			list[index].isEmpty = 1;
			printf("\nSe ha eliminado el pasajero.");
		} else if (respuesta == 2) {
			retorno = 0;
			list[index].isEmpty = 0;
		}
	}

	return retorno;
}

/*
 * @brief: modifica una estructura
 * @param len: pide el largo del arreglo de estructuras creadas
 * @param id: busca por ID para modificar
 */
int modificarPasajero(Passenger *list, int len, int id) {
	int retorno = -1;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	int auxTypePassenger;
	int respuesta;
	int respuestaDeModificacion;
	char auxFlyCode[10];
	int flagModificacion = 0;
	int k;


	if (list != NULL && id >= 0 && len > 0) {
		retorno = 1;
		for (int i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == 0) {
				printf("\nEste es el pasajero a modificar. nombre: %s \n apellido: %s \n precio: %.2f \n tipo de pasajero: %d \n codigo de vuelo: %s \n",list[i].name, list[i].lastName, list[i].price,list[i].typePassenger, list[i].flyCode);
				utn_getNumero(&respuesta,
						"¿Desea modificarlo? 1 para si 2 para no: ", "Error", 1,
						2, 3);
				k = i;
				if (respuesta == 1) {
					do {
						utn_getNumero(&respuestaDeModificacion,
								"\n 1 para modificar el nombre - 2 para modificar el apellido - 3 para modificar el precio - 4 para modificar el tipo de pasajero - 5 para modificar el codigo de vuelo 6 - CANCELAR",
								"Error", 1, 6, 3);
						switch (respuestaDeModificacion) {
						case 1:
							utn_getNombre(auxName, 51,
									"\nElija el nuevo nombre: ",
									"\nError ingrese nuevamente el nombre: ",
									3);
							strcpy(list[i].name, auxName);
							flagModificacion = 1;
							break;
						case 2:
							utn_getNombre(auxLastName, 51,
									"\nElija el nuevo apellido: ",
									"\nError ingrese nuevamente el apellido: ",
									3);
							strcpy(list[i].name, auxLastName);
							flagModificacion = 1;
							break;
						case 3:
							utn_getNumeroFlotante(&auxPrice,
									"\nIngrese el nuevo precio: ",
									"\nError ingrese nuevamente el precio", 0,
									9999999, 3);
							list[i].price = auxPrice;
							flagModificacion = 1;
							break;
						case 4:
							utn_getNumero(&auxTypePassenger,
									"\nIngrese el nuevo tipo de pasajero: ",
									"Error ingrese nuevamente el tipo de pasajero",
									3, 1, 3);
							list[i].typePassenger = auxTypePassenger;
							flagModificacion = 1;
							break;
						case 5:
							if (utn_getDescripcion(auxFlyCode, 10,
									"\nIngrese el código de vuelo: ",
									"\nError ingrese nuevamente el codigo de vuelo: ",
									3) == 0) {

								strcpy(list[i].flyCode, auxFlyCode);
								flagModificacion = 1;
							}
							break;
						case 6:
							flagModificacion = 0;
							break;

						}
						if (flagModificacion == 1) {
							utn_getNumero(&respuesta,
									"\n¿Desea modificar otro dato? 1 para si 2 para no: ",
									"\n Error", 1, 2, 3);
						} else {
							respuesta = 0;
						}
					} while (respuesta == 1);
				} else if (flagModificacion == 0) {
					printf("\n No se hicieron cambios");
				}

			}
		}
		printf(
				"\nID: %d \nnombre: %s \napellido: %s \nprecio: %.2f \ncodigo de vuelo: %s \ntipo de pasajero: %d",
				list[k].id, list[k].name, list[k].lastName, list[k].price,
				list[k].flyCode, list[k].typePassenger);

	} else {
		printf("\nNo se encontro el id a modificar");
		retorno = -1;
	}

	return retorno;
}

/*
 * @brief encuentra un pasajero por ID
 * @param Passenger * list: pide la estructura
 * @param len: pide el largo de la estructura
 * @param id: pide el ID a buscar
 */
int findPassengerById(Passenger *list, int len, int id) {
	int retorno = -1;
	int index;

	if (list != NULL && len > 0 && id >= 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].id == id) {
				index = i;
				retorno = index;
				break;
			}
		}

	}
	return retorno;
}

/*
 * @brief habilita la creacion de pasajeros, dejando el isEmpty en 1(TRUE) para ocupar.
 * @param Passenger * list: pide la estructura
 * @param len: pide el largo de la estructura
 *
 */

int initPassengers(Passenger *list, int len) {

	for (int i = 0; i < len; i++) {
		list[i].isEmpty = 1;
	}

	return 0;
}

/*
 * @brief Pide todos los datos para crear una variable de tipo estructura(pasajero)
 * @param Passenger * list: una vez lleno todos los datos carga una estructura por referencia.
 * @param len: pide el largo de sus indices de la estructura
 * @param id: se auto asigna un id de forma incremental
 * @param name: pide el nombre
 * @param lastname: pide el subnombre
 * @param price: pide el precio
 * @param typePassenger: pide asignar la importancia del pasajero 1 C. VIP - 2 C. EJECUTIVA - 3 C. ECONOMICA
 * @param flyCode: pide un codigo alfanumerico para asignar el pasajero a un codigo de vuelo en la estructura vuelo
 */
int addPassenger(Passenger *list, int len, int id, char name[51],
		char lastName[51], float price, int typePassenger, char flycode[10]) {

	int retorno = -1;

	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty == 1 && list != NULL && len > 0) {

			if (name != NULL && lastName != NULL && price > 0
					&& typePassenger > 0) {
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strcpy(list[i].flyCode, flycode);
				list[i].id = id;
				list[i].isEmpty = 0;
				retorno = 0;
				break;
			}

		}

	}

	return retorno;
}

/*
 * @brief: crea el menu
 */
void menu() {
	printf("1. ALTAS\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. INFORMAR: \n");
	printf("5. CARGAFORZADA");
}

/*
 * @brief obtiene el promedio de las estructuras creadas por addPassenger, por su precio
 * @param Passenger * list: pide la estructura
 * @param len: pide el largo de la estructura
 */
int promedioPassengers(Passenger *list, int len) {
    int retorno = -1;
    float totalPrecio = 0;
    int contadorPasajes = 0;
    float promedioPrecio = 0;
    int superanPromedio = 0;

    if (list != NULL && len > 0) {
        for (int i = 0; i < len; i++) {
            if (list[i].isEmpty == 0) {
                totalPrecio += list[i].price;
                contadorPasajes++;
            }
        }

        promedioPrecio = totalPrecio / contadorPasajes;

        for (int i = 0; i < len; i++) {
            if (list[i].price > promedioPrecio && list[i].isEmpty == 0) {
                superanPromedio++;
            }
        }

        printf(
                "El precio total de los pasajes es: %.2f    El promedio de los precios es: %.2f La cantidad de pasajeros que superan el promedio es: %i\n",
                totalPrecio, promedioPrecio, superanPromedio);
        retorno = 0;
    }

    return retorno;
}
/*
 * @brief imprime todos los pasajeros creados.
 * @param Passenger *list: pide la estructura
 * @param len: pide el largo de la estructura
 */
int printPassenger(Passenger * list, int len)
{
	int retorno = -1;

	if(list != NULL && len >0)
	{	retorno = 0;
		for(int i=0; i<len;i++)
		{	if(list[i].isEmpty == 0){
			printf("\nID: %d \n nombre: %s \n apellido: %s \n precio: %.2f \n codigo de vuelo: %s \n tipo de pasajero: %d \n\n",
					list[i].id, list[i].name,
					list[i].lastName, list[i].price,
					list[i].flyCode, list[i].typePassenger);
		}
		}
	}

	return retorno;
}


