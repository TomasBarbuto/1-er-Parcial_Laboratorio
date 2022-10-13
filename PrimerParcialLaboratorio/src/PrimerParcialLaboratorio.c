#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Tipo.h"
#include "Transporte.h"
#include "HojaDeRuta.h"
#include "Informes.h"

#define CANT_TRANSPORTE 5
#define CANT_HOJADERUTA 10

int main(void) {
	setbuf(stdout, NULL);

	int opcion; //variable de control del menu.
	int cantidadTransportes = 0;
	float precioPortransporte;
	float precioPorTipo;
	int flagListarTransportes = 0;
	int flagHojaDeRuta = 0;

	//declaramos las struct.
	transporte eTransportes[CANT_TRANSPORTE];
	tipo eTipos[4]; //son 4 siempre no varia.
	hojaDeRuta eHojasDeRuta[CANT_HOJADERUTA];

	//inicializamos todas las struct.
	if(inicializarTransporte(eTransportes, CANT_TRANSPORTE) && iniciarTipos(eTipos) &&
	   inicializarHojaDeRuta(eHojasDeRuta, CANT_HOJADERUTA)){

		printf("\t\t********* Se crearon las herramientas correspondientes para ejecutar el programa **********\n\n"
				"\t\t     _____________________________________________________________________________\n");
	}else{
		printf("Ocurrio un error, llame al departamento de sistemas\n");
	}

	system("pause");
	do {

		if(getNumber(&opcion, "\n\tBienvenido al Menu de transporte \n\n"
				"¿Que accion desea realizar?\n\n"
				"1-DAR DE ALTA\n"
				"2-MODIFICAR\n"
				"3-DAR DE BAJA\n"
				"4-LISTAR Transportes\n"
				"5-LISTAR Tipos\n"
				"6-DAR DE ALTA HOJA DE RUTA\n"
				"7-LISTAR HOJAS DE RUTA\n"
				"8-INFORMES\n"
				"9-SALIR\n\nIngrese una opcion: ", "Opcion no valida\n", 1, 9)){

			switch (opcion) {

			case 1:
				if (!buscarEspacio(eTransportes, CANT_TRANSPORTE)) {

					printf("\nYa no hay espacios para mas Transportes\n");

				}else{

					if(darAltaTransporte(eTransportes, CANT_TRANSPORTE)){

						printf("\nSe dio de alta correctamente\n\n");
						flagListarTransportes = 1;
						cantidadTransportes ++;

					}else{
						printf("Ocurrio un ERROR, reitente darlo de alta\n\n");
					}
					system("pause");
				}
				system("pause");
				break;
			case 2:
				if (flagListarTransportes == 1) {

					if(modificarTransporte(eTransportes, CANT_TRANSPORTE)){

						printf("\nSe modifico correctamente\n\n");

					}else{
						printf("Ocurrio un error, reintente\n");

					}
					system("pause");

				}else{

					printf("Todavia no se cargaron datos\n\n");
				}
				system("pause");
				break;

			case 3:
				if (flagListarTransportes == 1) {

					if(darBajaTransporte(eTransportes, CANT_TRANSPORTE) == 0){

						printf("Se dio de Baja exitosamente\n\n");
						cantidadTransportes--;
							if(cantidadTransportes == 0){

								flagListarTransportes = 0;
							}
					}else{

						printf("Ocurrio un error, reintente\n");
					}
					system("pause");

				} else {

					printf("Todavia no se cargaron datos\n");
				}
				system("pause");
				break;

			case 4:
				if (flagListarTransportes == 1) {

					if(ordenarTransportesPorID(eTransportes, CANT_TRANSPORTE) &&
					   ordenarTransportesPorDescripcion(eTransportes, CANT_TRANSPORTE) &&
					   mostrarDatos(eTransportes, CANT_TRANSPORTE)){

						printf("\nSe ordeno correctamente\n");

					}else{

						printf("Ocurrio un error, reintente\n");
					}
					system("pause");

				}else{

					printf("Todavia no se cargaron datos\n");
				}
				system("pause");
				break;

			case 5:
				if(listarTipos(eTipos, 4)){

				}else{
					printf("Ocurrio un error, llame al departamento de sistemas\n");
				}
				system("pause");
				break;

			case 6:
				if (flagListarTransportes == 1) {

						if(buscarEspacioHojaDeRuta(eHojasDeRuta, CANT_HOJADERUTA)){

							darAltaHojaDeRuta(eHojasDeRuta, eTransportes, CANT_HOJADERUTA, CANT_TRANSPORTE);
							flagHojaDeRuta = 1;
					}else{
						printf("\nYa no hay espacio para cargar Hoja de Ruta\n");
					}
					system("pause");
				} else {
					printf("Todavia no se cargaron Transportes para asignar\n");
				}
				system("pause");
				break;

			case 7:
				if (flagHojaDeRuta == 1) {

					if(mostrarHojaDeRuta(eHojasDeRuta, CANT_HOJADERUTA)){

					}else{
						printf("Todavia no se cargaron Transportes para asignar\n");
					}
					system("pause");

				}else{
					printf("Todavia no se cargaron datos\n");
				}
				system("pause");
				break;

			case 8:
				if(flagHojaDeRuta == 1 && flagListarTransportes == 1){

					if(mostrarMenuInformes(eTransportes, eHojasDeRuta, eTipos, CANT_TRANSPORTE, CANT_HOJADERUTA, 4,
							&precioPorTipo, &precioPortransporte)){
					}else{
						printf("Ocurrio un error, llame al departamento de sistemas\n");
					}
					system("pause");

				}else{
					printf("No hay informes que mostrar aun\nComplete los campos anteriores\n");
				}
				system("pause");
				break;

			case 9:
				getNumber(&opcion,
						"\nEsta seguro que desea salir del menu?\n\nReingrese 9 para confirmar...\n"
								"Ingrese 0 para continuar...\nOPCION: ",
						"Opcion no valida\n", 0, 9);
				printf("Usted a salido del MENU\nPrograma Finalizado.");
				break;
			}
		}
	} while (opcion != 9);

	return EXIT_SUCCESS;
}
