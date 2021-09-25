/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Calculadora.h"

int main(void) {

	setbuf(stdout, NULL);

	int num1;
	int num2;
	int suma;
	int resta;
	int division;
	int producto;
	long long int factorialA;
	long long int factorialB;
	int salida=0;
	int operacionesRealizadas =0;
	int num1Ingresado = 0;
	int num2Ingresado =0;
	int divisionValida = 0;

	do{
		system("cls");

		printf("\n\n***** ELIJA UNA OPCION *****\n\n");

		switch(desplegarMenu(num1, num2, num1Ingresado, num2Ingresado)){
			case 1:
				num1 = ingresarNumero();
				num1Ingresado = 1;
				break;

			case 2:
				num2 = ingresarNumero();
				num2Ingresado = 1;
				break;

			case 3:
				if(num1Ingresado != 0 && num2Ingresado != 0){
					suma = sumar(num1, num2);
					resta= restar(num1, num2);

					if(num2 != 0){
						division = dividir(num1, num2);
					}else{
						divisionValida = 0;
					}

					producto = multiplicar(num1, num2);
					factorialA = calcularFactorial(num1);
					factorialB = calcularFactorial(num2);

					operacionesRealizadas = 1;

					printf("Operaciones realizadas con exito! Elija la opcion 4 para mostrar todos los resultados. \n");
				}else{
					printf("Lo sentimos algo salio mal. Debe haber dos numeros ingresados para realizar las operaciones \n");
				}
				break;

			case 4:
				if(operacionesRealizadas == 1){
					mostrarResultados(suma, resta, divisionValida, division, producto, factorialA, factorialB);
				}else{
					printf("Lo sentimos algo salio mal. Debe realizar las operaciones antes de mostrar los resultados \n");
				}
				break;

			case 5:
				salida =1;
				break;

			default:
				printf("Ingrese una opcion valida");
				break;
		}

		system("pause");
	}while(salida == 0);


	return EXIT_SUCCESS;
}
