/*
 * franBiblioteca.h
 *
 *  Created on: 10 abr. 2022
 *      Author: FRANCO
 */

#ifndef FRANBIBLIOTECA_H_
#define FRANBIBLIOTECA_H_

#include <stdio.h>
#include <stdlib.h>

int utn_funcionDeMenu(int * pMenuIngresado);
float utn_precioDelVueloConDescuentoTarjetaDeDebito(float variableConPrecioDeVuelo, float descuento);
float utn_precioDelVueloConTarjetaDeCredito(float variableConPrecioDeVuelo, float interes);
float utn_precioDelVueloPagandoConBitCoin(float variableConPrecioDeVuelo, float valorDelBitcoin);
float mostrarPrecioPorValorUnitario(int variableConKilometros, float variableConPrecioDeVuelo);
float laDiferenciaDePrecioEs(float mayor, float menor);

#endif /* FRANBIBLIOTECA_H_ */
