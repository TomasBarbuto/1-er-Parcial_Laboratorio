/*
 * Informes.h
 *
 *  Created on: 12 oct. 2022
 *      Author: barbu
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int mostrarTransportesPorTipo(transporte eTransportes[], int longitudHojasDeRuta);
int mostrarHojasDeRutaPorFecha(hojaDeRuta eHojasDeRuta[], int longitudHojasDeRuta);
int importePorTransporte(hojaDeRuta eHojasDeRuta[], transporte eTransportes[], int longitudHojasDeRuta,int longitudTransportes,
		float *precioTotal);
int importePorTipoyFecha(transporte eTransportes[], hojaDeRuta eHojasDeRuta[], tipo tipos[], int longitudHojasDeRuta,
		int longitudTransportes, float* precioTotal);
int mostrarMenuInformes(transporte eTransportes[], hojaDeRuta hojasRuta[], tipo eTipos[], int longitudTransportes,
		int longitudHojasDeRutaH, int longitudTipos,float* precioPorTipo, float * precioPortransporte);

#endif /* INFORMES_H_ */
