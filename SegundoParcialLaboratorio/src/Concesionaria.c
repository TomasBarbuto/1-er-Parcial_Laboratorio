#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Menu.h"
#include "concesionaria.h"
#include "Controller.h"
#include "Validaciones.h"

Venta* newVenta(){

	Venta *nuevaVenta = NULL;
	nuevaVenta = (Venta *) malloc(sizeof(Venta));

	if (nuevaVenta != NULL){

		setIdVenta(nuevaVenta, 0);
		setDiaVenta(nuevaVenta, 0);
		setMesVenta(nuevaVenta, 0);
		setAnioVenta(nuevaVenta, 0);
		setModeloDeAuto(nuevaVenta, " ");
		setCantidadDeVentas(nuevaVenta, 0);
		setPrecioDeAuto(nuevaVenta, 0);
		setTarjetaDeCredito(nuevaVenta, " ");

	}
	return nuevaVenta;
}

/**
 * \brief Reserva espacio en memoria para un tipo de datos Jugador, cargando los datos en los campos.
 * \param 6 punteros a char.
 * \return puntero a jugador.
**/
Venta* nuevaVentaParametros(char* idVenta, char* dia, char* mes, char* anio, char* modeloDeAuto,
							char* cantidadDeVentas, char* precioDeAuto, char* tarjetaDeCredito){

	Venta *nuevaVenta = newVenta();

	if(nuevaVenta != NULL){

		if(!(setIdVenta(nuevaVenta, atoi(idVenta)) && setDiaVenta(nuevaVenta, atoi(dia)) && setMesVenta(nuevaVenta, atoi(mes))
		&& setAnioVenta(nuevaVenta, atoi(anio)) && setModeloDeAuto(nuevaVenta, modeloDeAuto)
		&& setCantidadDeVentas(nuevaVenta, atoi(cantidadDeVentas))&& setPrecioDeAuto(nuevaVenta, atof(precioDeAuto))
		&& setTarjetaDeCredito(nuevaVenta, tarjetaDeCredito))){

		  deleteVenta(nuevaVenta);
		  nuevaVenta = NULL;	//INDICA FUNCION NO ANDUVO BIEN.

		}
	}
	  return nuevaVenta;
}

/**
 * \brief libera espacio en memoria de un tipo de dato Jugador.
 * \param puntero a jugador.
 * \return VOID
**/
void deleteVenta(Venta *this){

	free(this);
}

/**
 * \brief Carga un dato de tipo int en el campo id de jugador.
 * \param puntero a jugador, int
 * \return int 1 Bien, 0 ERROR.
**/
int setIdVenta(Venta* this, int id){

	int retorno = 0;

	if(this != NULL && id > 0){

		this->id = id;
		retorno = 1;
	}

	return retorno;
}

/**
 * \brief obtiene un dato cargado en el campo jugador.
 * \param puntero a jugador, puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int getIdVenta(Venta* this, int* id){

	int retorno = 0;

	if (this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int setDiaVenta(Venta* this, int dia){

	int retorno = 0;

	if (this != NULL){

		this->fechaDeVenta.dia = dia;
		retorno = 1;

	}
	return retorno;
}

int getDiaVenta(Venta* this, int* dia){

	int retorno = 0;

	if (this != NULL && dia != NULL){

		*dia = this->fechaDeVenta.dia;
		retorno = 1;

	}
	return retorno;
}

int setMesVenta(Venta* this, int mes){

	int retorno = 0;

	if (this != NULL){

		this->fechaDeVenta.mes = mes;
		retorno = 1;

	}
	return retorno;
}

int getMesVenta(Venta* this, int* mes){

	int retorno = 0;

	if (this != NULL && mes != NULL){

		*mes = this->fechaDeVenta.mes;
		retorno = 1;

	}
	return retorno;
}

int setAnioVenta(Venta* this, int anio){

	int retorno = 0;

	if (this != NULL){

		this->fechaDeVenta.anio = anio;
		retorno = 1;

	}
	return retorno;
}

int getAnioVenta(Venta* this, int* anio){

	int retorno = 0;

	if (this != NULL && anio != NULL){

		*anio = this->fechaDeVenta.anio;
		retorno = 1;

	}
	return retorno;
}

int setCantidadDeVentas(Venta* this, int cantidadDeVentas){

	int retorno = 0;

	if (this != NULL){

		this->cantidadDeVentas = cantidadDeVentas;
		retorno = 1;

	}

	return retorno;
}
int getCantidadDeVentas(Venta* this, int* cantidadDeVentas){

	int retorno = 0;

	if (this != NULL && cantidadDeVentas != NULL){

		*cantidadDeVentas = this->cantidadDeVentas;
		retorno = 1;

	}

	return retorno;
}

int setPrecioDeAuto(Venta* this, float PrecioDeAuto){

	int retorno = 0;

	if (this != NULL){

		this->precioDeAuto = PrecioDeAuto;
		retorno = 1;

	}

	return retorno;
}

int getPrecioDeAuto(Venta* this, float* precioDeAuto){

	int retorno = 0;

	if (this != NULL && precioDeAuto != NULL){

		*precioDeAuto = this->precioDeAuto;
		retorno = 1;

	}

	return retorno;
}
int setModeloDeAuto(Venta* this, char* modeloDeAuto){

	int retorno = 0;

	if (this != NULL && modeloDeAuto != NULL){

		strncpy(this->modeloDeAuto, modeloDeAuto,  200);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}

int getModeloDeAuto(Venta* this, char* modeloDeAuto){

	int retorno = 0;

	if (this != NULL && modeloDeAuto != NULL){

		strncpy(modeloDeAuto, this->modeloDeAuto, 200);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}

int setTarjetaDeCredito(Venta* this, char* tarjetaDeCredito){

	int retorno = 0;

	if (this != NULL && tarjetaDeCredito != NULL){

		strncpy(this->tarjetaDeCredito, tarjetaDeCredito, 17);
		retorno = 1;

	}

	return retorno;
}

int getTarjetaDeCredito(Venta* this, char* tarjetaDeCredito){

	int retorno = 0;

	if (this != NULL && tarjetaDeCredito != NULL){

		strncpy(tarjetaDeCredito, this->tarjetaDeCredito, 17);
		retorno = 1;

	}

	return retorno;
}



int elegirModelo(char pModeloElegido[]){

	int retorno = 0;
	int opcion;

	if(pModeloElegido != NULL){

		menuElegirModelo();
		if(utn_getNumero(&opcion, "Opcion: ", "\nERROR opcion no validar\nReingrese\n", 1, 9, 5)){

			switch(opcion){

			case 1:
				strncpy(pModeloElegido, "Volskwagen FOX", 200);
				break;

			case 2:
				strncpy(pModeloElegido, "Volskwagen GOL", 200);
				break;

			case 3:
				strncpy(pModeloElegido, "Volskwagen BORA", 200);
				break;

			case 4:
				strncpy(pModeloElegido, "Chevrolet CORSA", 200);
				break;

			case 5:
				strncpy(pModeloElegido, "Chevrolet ONIX", 200);
				break;

			case 6:
				strncpy(pModeloElegido, "Chevrolet CRUZE", 200);
				break;

			case 7:
				strncpy(pModeloElegido, "FIAT CRONOS", 200);
				break;

			case 8:
				strncpy(pModeloElegido, "FIAT ARGO", 200);
				break;

			case 9:
				strncpy(pModeloElegido, "FIAT 147", 200);
				break;
			}
			retorno = 1;

		}else{

			retorno = 0;
		}

	}
	return retorno;
}

int idAutoincremental(){

	static int idJugador;
	char auxId[1000];
	static int flag = 0;

	if(flag == 0){

		if(controller_cargarIdAutoincremental("ID.csv", auxId)){

			flag = 1;
			idJugador = atoi(auxId);
		}
	}

	idJugador++;

	return idJugador;
}
///////////////////////////
///
///
int ventasMayorASieteMillones(void* pElement){

	int retorno = 0;
	float auxPrecio;
	int auxCantidadDeVentas;
	Venta* auxVenta = pElement;

	if(auxVenta != NULL){

		if(getPrecioDeAuto(auxVenta, &auxPrecio)
		&& getCantidadDeVentas(auxVenta, &auxCantidadDeVentas)){

			auxPrecio *= auxCantidadDeVentas;
			if(auxPrecio > 7000000){

				retorno = 1;
			}
		}
	}
	return retorno;
}


int ventasMayorAVeinteMillones(void* pElement){

	int retorno = 0;
	float auxPrecio;
	int auxCantidadDeVentas;
	Venta* auxVenta = pElement;

	if(auxVenta != NULL){

		if(getPrecioDeAuto(auxVenta, &auxPrecio)
		&& getCantidadDeVentas(auxVenta, &auxCantidadDeVentas)){

			auxPrecio *= auxCantidadDeVentas;

			if(auxPrecio > 20000000){

				retorno = 1;
			}
		}
	}
	return retorno;
}


int ventasDeUnidadesTotales(void* pElement){

	int retorno = 0;
	int auxCantidadDeVentas;
	Venta* auxVenta = pElement;

	if(auxVenta != NULL){

		if(getCantidadDeVentas(auxVenta, &auxCantidadDeVentas)){

			if(auxCantidadDeVentas > 0){

				retorno = auxCantidadDeVentas;
			}
		}
	}
	return retorno;
}


int ventasPorModeloQSiete(void* pElement){

	int retorno = 0;
	int auxCantidad;
	char modeloDeAuto[200] = "Q7";
	char auxModelo[200];
	Venta* auxVenta = pElement;

	if(auxVenta != NULL){

		if(getModeloDeAuto(auxVenta, auxModelo)){

			if(strncmp(modeloDeAuto, auxModelo, 200) == 0){

				if(getCantidadDeVentas(auxVenta, &auxCantidad)){

					retorno = auxCantidad;
				}
			}
		}
	}
	return retorno;
}
