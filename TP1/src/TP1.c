/*
 ============================================================================
 Name        : TP1.c
 Author      : franco cardon
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "franBiblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	int km;
	float precioVueloAerolineas;
	float precioVueloLatam;
	float bitCoin;
	int opcionMenu;
	int validarDato;
	float AerolineasPrecioConDebito;
	float AerolineasPrecioConCredito;
	float AerolineasPagandoConBitCoin;
	float AerolineasPrecioUnitario;
	float LatamPrecioConDebito;
	float LatamPrecioConCredito;
	float LatamPagandoConBitCoin;
	float LatamPrecioUnitario;
	float diferenciaDePrecio;

	km = 7090;
	precioVueloAerolineas = 162965;
	precioVueloLatam = 159339;
	bitCoin = 4606954.55;

	do{
		printf("1)Ingresar Kilómetros:%d\n\n",km);
		printf("2)Ingresar Precio de Vuelos: \n-Precio vuelo Aerolineas: %.1f\n-Precio vuelo Latam: %.2f \n\n",precioVueloAerolineas,precioVueloLatam);
		printf("3)Calcular todos los costos: \n a)Tarjeta de débito -descuento 10 \n b)Tarjeta de crédito -25 \n c)Bitcoin -1Btc \n d)Mostrar precio por km \n e)Mostrar diferencia de precio ingresada Latam - Aerolineas\n\n");
		printf("4)Informar Resultados:\nLatam:\na)Precio con tarjeta de débito:\nb)Precio con tarjeta de crédito:\nc)Precio pagando con bitcoin:\nd)Precio unitario:\n\n");
		printf("Aerolíneas:\na)Precio con tarjeta de débito:\nb)Precio con tarjeta de crédito:\nc)Precio pagando con bitcoin:\nd)Precio unitario:\nLadiferencia de precio es:\n\n");
		printf("5)Cargar datos.\n\n");
		printf("6)SALIR.\n");

		validarDato = utn_funcionDeMenu(&opcionMenu);

		if(validarDato == 0){
			switch(opcionMenu){
			case 5: printf("\n1)Kilometros Ingresados:%d\n\n",km);
					printf("Precio Aerolineas:$%.2f\n",precioVueloAerolineas);
					AerolineasPrecioConDebito = utn_precioDelVueloConDescuentoTarjetaDeDebito(precioVueloAerolineas, 1.1);
					AerolineasPrecioConCredito = utn_precioDelVueloConTarjetaDeCredito(precioVueloAerolineas, 1.25);
					AerolineasPagandoConBitCoin = utn_precioDelVueloPagandoConBitCoin(precioVueloAerolineas, bitCoin);
					AerolineasPrecioUnitario = mostrarPrecioPorValorUnitario(precioVueloAerolineas, km);
					printf("a) Precio con tarjeta de debito: $ %.2f\n",AerolineasPrecioConDebito);
					printf("b) Precio con tarjeta de credito: $ %.2f\n",AerolineasPrecioConCredito);
					printf("c) Precio pagando con bitcoin: %f\n",AerolineasPagandoConBitCoin);
					printf("d) Mostrar precio unitario: $ %.2f\n\n",AerolineasPrecioUnitario);

					printf("Precio Aerolineas:$%.2f\n",precioVueloLatam);
					LatamPrecioConDebito = utn_precioDelVueloConDescuentoTarjetaDeDebito(precioVueloLatam, 1.1);
					LatamPrecioConCredito = utn_precioDelVueloConTarjetaDeCredito(precioVueloLatam, 1.25);
					LatamPagandoConBitCoin = utn_precioDelVueloPagandoConBitCoin(precioVueloLatam, bitCoin);
					LatamPrecioUnitario = mostrarPrecioPorValorUnitario(precioVueloLatam, km);
					diferenciaDePrecio = laDiferenciaDePrecioEs(precioVueloLatam, precioVueloAerolineas);
					printf("a) Precio con tarjeta de debito: $ %.2f\n",LatamPrecioConDebito);
					printf("b) Precio con tarjeta de credito: $ %.2f\n",LatamPrecioConCredito);
					printf("c) Precio pagando con bitcoin: %f\n",LatamPagandoConBitCoin);
					printf("d) Mostrar precio unitario: $ %.2f\n\n",LatamPrecioUnitario);
					printf("La diferencia de precio es: $ %.2f",diferenciaDePrecio);
			}
		}
	  }while(opcionMenu != 5);

	return 0;
}


