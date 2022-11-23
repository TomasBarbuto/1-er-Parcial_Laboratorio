#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concesionaria.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"
#include "Controller.h"
#include "Menu.h"



int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int ultimoId;
	int flagLinkedList = 0;

	LinkedList* ventaConcesionaria = ll_newLinkedList();

	do{
		menuPrincipal();
		if(utn_getNumero(&opcion, "Opcion: ", "\nValor no valido Reingrese...\n", 1, 8, 5)){

			switch(opcion){

			case 1: 	//cargar archivo
				if(flagLinkedList == 0){

					if(controller_cargarArchivoVentasDesdeTexto("Ventas.csv", ventaConcesionaria)){

						printf("Los archivos se cargaron correctamente\n");
						flagLinkedList = 1;
					}else{

						printf("Ocurrio un ERROR, llame a sistemas\n");
					}
				}else{

					printf("Los archivos ya se encuentrar cargados...\n");
				}
				system("pause");
				break;

			case 2:	//alta
				if(flagLinkedList == 1){

					if(controller_CargarUnaVenta(ventaConcesionaria)){

						printf("Se dio de alta la venta correctamente\n");
					}else{

						printf("Ocurrio un ERROR, llame a sistemas\n");
					}
				}else{

					printf("No existe un archivo donde escribir una nueva venta\n");
				}
				system("pause");
				break;

			case 3://baja
				if(flagLinkedList == 1){

					if(controller_removerVenta(ventaConcesionaria)){

						printf("Se dio de BAJA la venta correctamente\n");
					}
				}else{

					printf("No existe un archivo donde escribir una nueva venta\n");
				}
				system("pause");
				break;

			case 4:
				if(flagLinkedList == 1){

					if(controller_modificarUnaVenta(ventaConcesionaria)){

						printf("Se modifico Correctamente\n");
					}

				}else{

					printf("No existe un archivo donde escribir una nueva venta\n");
				}
				system("pause");
				break;

			case 5:	//guardar binario
				if(flagLinkedList == 1){

					if(controller_guardarVentasModoBinario("Ventas.bin", ventaConcesionaria)){

						printf("Los datos se Guardaron correctamente\n");
					}else{

						printf("Ocurrio un error y no se pudieron guardar los datos\n");
					}
				}else{


				}
				break;

			case 6://guarda texto
				if(flagLinkedList == 1){

					ultimoId = buscarIdMaximo(ventaConcesionaria);

					if(controller_guardarVentasModoTexto("Ventas.csv", ventaConcesionaria)
					&& controller_guardarIdAutoincremental("ID.csv", ultimoId)){

						printf("Los datos se Guardaron correctamente\n");
					}else{

						printf("Ocurrio un error y no se pudieron guardar los datos\n");
					}
				}else{


				}
				break;

			case 7://informes
				if(controller_guardarInformeATexto("Informe.txt", ventaConcesionaria)){

					printf("\nSe creo el archivo con los informes correctamente\n");

				}else{

					printf("\nERROR al crear el archivo\n");
				}
				break;

			case 8:		//salir
				break;
			}
		}

	}while(opcion != 8);

	return 0;
}
