/*
 * Employee.c
 *
 *  Created on: 16 oct. 2021
 *      Author: caroo
 */


#include "Employee.h"
#include "UTN.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializarEmpleado(eEmployee pArray[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			pArray[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
int buscaLibre(eEmployee pArray[], int cantidadDeArray)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(pArray[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}
int altaEmployee(eEmployee aEmployee[], int cantidadDeArray, int* contadorId)
{
	int retorno = -1;
	eEmployee aAuxiliar;
	int posicion;
	if(aEmployee!=NULL && cantidadDeArray>0 && contadorId!=NULL)
	{
		posicion=buscaLibre(aEmployee, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if((utn_getApellido(aAuxiliar.lastName, "Ingrese Apellido", "Error\n", 3, 51)==0)&&
			(utn_getApellido(aAuxiliar.name, "Ingrese Nombre", "Error\n", 3, 51)==0)&&
			(utn_getNumeroFlotante(&aAuxiliar.salary,"Ingrese salario","Error, ingrese salario entre 10000-60000\n",10000,60000,3)==0)&&
			(utn_getNumero(&aAuxiliar.sector, "Ingrese sector","Error, ingrese sector de 1 a 3\n", 1, 3, 3)==0))
			{
				aAuxiliar.idEmployee=0;
				printf("Estos son los datos, desea continuar:");
				imprimir1Employee(aAuxiliar);
				if(utn_getCaracterSN()==0)
				{
				   (*contadorId)++;
				   aAuxiliar.idEmployee=*contadorId;
				   aAuxiliar.isEmpty=0;
				   aEmployee[posicion]=aAuxiliar;
				   imprimir1Employee(aEmployee[posicion]);
				   retorno=0;
				}
			}
		}
	}
		return retorno;
}
void imprimir1Employee(eEmployee aEmpleado)
{
	printf("\n %-5d  %-10s %-10s %-5d %-5.2f ", aEmpleado.idEmployee, aEmpleado.lastName, aEmpleado.name, aEmpleado.sector, aEmpleado.salary);
}
int imprimirEmployees(eEmployee aEmpleado[], int cantidadDeArray)
{
	int i;
	int retorno = -1;

	//CABECERA
	puts("\n\t> LISTADO Empleados");
	printf("%5s %10s %10s %8s %5s\n", "ID","APELLIDO","NOMBRE","SECTOR","SUELDO");
	if (aEmpleado != NULL && cantidadDeArray> 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (aEmpleado[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				imprimir1Employee(aEmpleado[i]);
				retorno=0;
			}
		}
	}
	return retorno;
}
int buscaEmployeeById(eEmployee aAuxiliar[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	int aID;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("Ingrese ID");
		scanf("%d", &aID);
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].idEmployee==aID && aAuxiliar[i].isEmpty==0)
			{
				retorno = i;
				break;
			}
		}
		if(retorno==-1)
		{
			printf("El numero de ID %d no existe", aID);
		}
	}
	return retorno;
}
int bajaEmployee(eEmployee aAuxiliar[], int posicion)
{
	int retorno = -1;
	char respuesta;
	if(aAuxiliar!=NULL && posicion!=-1)
	{
		imprimir1Employee(aAuxiliar[posicion]);
		printf("\nDesea borrar ese empleado, ingrese 's'");
		fflush(stdin);
		scanf("%c", &respuesta);
		if(respuesta=='s')
		{
			aAuxiliar[posicion].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}
int ordenarEmployees(eEmployee aEmpleado[], int cantidadDeArray, int criterio)
{
		int i;
		int flagNoEstaOrdenado=1;
		eEmployee aux;
		int retorno=-1;

		if(aEmpleado!=NULL && cantidadDeArray>0)
		{
			do {
				flagNoEstaOrdenado=0;
				for (i = 0; i < cantidadDeArray-1; i++)
				{
					if(criterio == 1)
					{
							if(strcmp(aEmpleado[i].lastName,aEmpleado[i+1].lastName)>0)
							{
								aux=aEmpleado[i];
								aEmpleado[i]=aEmpleado[i+1];
								aEmpleado[i+1]=aux;
								flagNoEstaOrdenado=1;
							}
							else
							{
									if(strcmp(aEmpleado[i].lastName,aEmpleado[i+1].lastName)==0 && aEmpleado[i].sector > aEmpleado[i+1].sector)
									{
										aux=aEmpleado[i];
										aEmpleado[i]=aEmpleado[i+1];
										aEmpleado[i+1]=aux;
										flagNoEstaOrdenado=1;
									}
							}
						}
						else
						{
							if(criterio == 0)
							{
								if(strcmp(aEmpleado[i+1].lastName,aEmpleado[i].lastName)>0)
								{
									aux=aEmpleado[i];
									aEmpleado[i]=aEmpleado[i+1];
									aEmpleado[i+1]=aux;
									flagNoEstaOrdenado=1;
								}
								else
								{
									if(strcmp(aEmpleado[i].lastName,aEmpleado[i+1].lastName)==0 && aEmpleado[i+1].sector > aEmpleado[i].sector)
									{
										aux=aEmpleado[i];
										aEmpleado[i]=aEmpleado[i+1];
										aEmpleado[i+1]=aux;
										flagNoEstaOrdenado=1;
									}
								}
							}
						}
					}
				} while (flagNoEstaOrdenado==1);
				retorno=0;
		}
		return retorno;
}

int modifica1Employee(eEmployee aAuxiliar[], int posicion)
{
	int retorno = -1;
	int respuesta;
	if(aAuxiliar!=NULL && posicion!=-1)
	{
				imprimir1Employee(aAuxiliar[posicion]);
				printf("\n?Desea modificar este empleado?");
				if(utn_getCaracterSN()==0)
				{
					printf("\nDesea modificar \n1. Apellido\n2.Nombre\n3.Salario\n4.Sector");
					scanf("%d", &respuesta);
					while(respuesta>4 || respuesta<1)
					{
						printf("\nDesea modificar \n1. Apellido\n2.Nombre\n3.Salario\n4.Sector");
						scanf("%d", &respuesta);
					}
					switch(respuesta)
					{
						case 1:
							utn_getApellido(aAuxiliar[posicion].lastName, "Ingrese Apellido", "Error\n", 2, 51);
							printf("Exito, los nuevos datos son: ");
							imprimir1Employee(aAuxiliar[posicion]);
							break;
						case 2:
							utn_getApellido(aAuxiliar[posicion].name, "Ingrese Nombre", "Error\n", 2, 51);
							printf("Exito, los nuevos datos son: ");
							imprimir1Employee(aAuxiliar[posicion]);
							break;
						case 3:
							utn_getNumeroFlotante(&aAuxiliar[posicion].salary,"Ingrese salario","Error, ingrese salario entre 10000-60000",10000,60000,2);
							printf("Exito, los nuevos datos son: ");
							imprimir1Employee(aAuxiliar[posicion]);
							break;
						case 4:
							utn_getNumero(&aAuxiliar[posicion].sector, "Ingrese sector: 1.ADMISION, 2.SEGURIDAD, 3.ADMINISTRACION",
									"Error, ingrese: 1.Admision, 2.Seguridad, 3.Administracion", 1, 3, 2);
							printf("Exito, los nuevos datos son: ");
							imprimir1Employee(aAuxiliar[posicion]);
							break;
					}
					retorno = 0;
				}
		}
	return retorno;
}
int eEmployeePromSalario(float* pPromedioResultado, eEmployee array[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	int acumulador=0;
	int contador=0;

	if(pPromedioResultado != NULL && array!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(array[i].isEmpty==0)
			{
				acumulador=acumulador+array[i].salary;
				contador++;
			}
		}
		*pPromedioResultado = (float)acumulador/contador;
		printf("El Total de salario es: %d\n", acumulador);
		printf("El salario promedio es: %.2f\n", *pPromedioResultado);
		retorno = 0;
	}
	return retorno;
}
int eEmployeesListaSalario(eEmployee array[], int cantidadDeArray, float salary, int* cantidad)
{
	int retorno=-1;
	int i;

	if(array!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(array[i].isEmpty==0 && array[i].salary>=salary)
			{
				(*cantidad)++;
				imprimir1Employee(array[i]);
			}
		}
//		for(i=0; i<cantidadDeArray; i++)
//		{
//			if(array[i].isEmpty==0 && array[i].salary>=salary)
//			{
//				imprimir1Employee(array[i]);
//			}
//		}
	}

	return retorno;
}
