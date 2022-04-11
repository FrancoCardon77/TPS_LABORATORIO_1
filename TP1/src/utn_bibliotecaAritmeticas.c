/*
 * franBiblioteca.c
 *
 *  Created on: 10 abr. 2022
 *      Author: FRANCO
 */

#include "utn_bibliotecaAritmeticas.h"


/**
 * @author Franco
 * @param pMenuIngresado Es un puntero a la variable de opciones, nos permite navegar por el menu.
 * @return nos va a clasificar el tipo de error, en el caso que exista este a partir de número negativos.
 *
 */
int utn_funcionDeMenu(int * pMenuIngresado){
	int auxDelMenuIngresado;
	int retorno;
	retorno = -1;
//va a preguntarle al usuario sobre su opción y guardarla en una variable auxiliar para posteriormente validarla.
	printf("Elija una opción del menú: ");
	scanf("%d",&auxDelMenuIngresado);
	fflush(stdin);
// verificando que la opción ingresada sea la correcta.
	if(auxDelMenuIngresado == 5){
		*pMenuIngresado = auxDelMenuIngresado;
		retorno = 0;
	}
	else{
		while(auxDelMenuIngresado != 5){
			printf("Error elija nuevamente la opción del menú: ");
			scanf("%d",&auxDelMenuIngresado);
		}
	}
	return retorno;
}
/**
 *@author: franco
 *@param variableConPrecioDeVuelo va a permitirle al usuario insertar el precio del vuelo
 *@param descuento va a permitirle al usuario agregar por parametro el descuento a realizar.
 *@return va a darnos el resultado final con el descuento para guardarlo en una variable.
 */
float utn_precioDelVueloConDescuentoTarjetaDeDebito(float variableConPrecioDeVuelo, float descuento){
	float resultado;

	resultado = variableConPrecioDeVuelo + variableConPrecioDeVuelo - (variableConPrecioDeVuelo * descuento);

	return resultado;
}
/**
 * author: franco
 * @param variableConPrecioDeVuelo va a permitirle al usuario insertar el precio del vuelo.
 * @param interes va a permitir al usuario darle un valor de interes al primer parametro.
 * @return va a retornar nuestro resultado con el valor del interes agregado al precio con el primer parametro.
 */
float utn_precioDelVueloConTarjetaDeCredito(float variableConPrecioDeVuelo, float interes){
	float resultado;

	resultado = interes * variableConPrecioDeVuelo;

	return resultado;
}
/**
 * author: franco
 * @param variableConPrecioDeVuelo variableConPrecioDeVuelo va a permitirle al usuario insertar el precio del vuelo.
 * @param valorDelBitcoin va a permitirle al usuario ingresar la cantidad actual al día de la fecha o en tiempos anteriores el valor de la criptomoneda BITCOIN.
 * @return va a darnos el resultado mismo de la cotización paga del primer parametro precio de vuelo, pagando con BITCOINS.
 */
float utn_precioDelVueloPagandoConBitCoin(float variableConPrecioDeVuelo, float valorDelBitcoin){
	float resultado;
	resultado = variableConPrecioDeVuelo / valorDelBitcoin;

	return resultado;
}
/**
 * @author: franco
 * @param variableConKilometros va a permitirle al usuario ingresar cuantos kilometros de vuelo se le asignará para calcular el precio unitario.
 * @param variableConPrecioDeVuelo permite ingresar el precio del vuelo para luego obtener el valor unitario.
 * @return va a retornar el resultado de la operacion por valor unitario.
 */
float mostrarPrecioPorValorUnitario(int variableConKilometros, float variableConPrecioDeVuelo){
	float resultado;
	resultado =  variableConKilometros/variableConPrecioDeVuelo;

	return resultado;
}
/**
 * @author: franco
 * @param mayor el valor a obtener diferencia.
 * @param menor el valor a obtener diferencia.
 * @return va a devolver el resultado de diferencia entre las 2 operaciones
 *
 */
float laDiferenciaDePrecioEs(float mayor, float menor){
	float resultado;

	//va a intercalar la operacion para detectar primero el mayor y luego el menor y así obtener la diferencia.
	if(mayor > menor){
		resultado = mayor - menor;
	}
	else if(menor > mayor){
		resultado = menor - mayor;
	}

	return resultado;
}


