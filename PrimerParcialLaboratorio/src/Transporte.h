
#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_

typedef struct{

	int idTransporte;
	char descripcion[1024];
	int pesoCarga;
	int cantidadBultos;
	int tipoId;
	int isEmpty;

}transporte;


int idTransportes();
int inicializarTransporte(transporte eTransportes[], int longitud);
int buscarVacioTransporte(transporte eTransportes[], int longitud);
int darAltaTransporte(transporte eTransportes[], int longitud);
int buscarIdDeTransporte(transporte eTransportes[], int longitud, int id);
int darBajaTransporte(transporte eTransportes[], int longitud);
int mostrarDatos(transporte eTransportes[], int longitud);
void mostrarDato(transporte eTransportes);
int listarTransportes(transporte eTransportes[], int longitud);
int modificarTransporte(transporte eTransportes[], int longitud);
int ordenarTransportesPorID(transporte eTransportes[], int longitud);
int ordenarTransportesPorDescripcion(transporte eTransportes[], int longitud);
int buscarEspacio(transporte eTransportes[], int longitud);
int buscarIdTransporte(transporte eTransportes[], int longitud, int id);


#endif /* TRANSPORTE_H_ */
