/**
 * @file	taxa.cpp
 * @brief	Arquivo corpo com a implementacao das funcaes que buscam
 *					saber quais muncipios tiveram a maior tava de queda
					e crecimento de 2013-2014
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	13/04/2017
 * @date	13/04/2017
 */


#include "taxa.h"

/**
 * @brief Funcao que imprimi o nome e a porcentagem
 *				do muncipio com a maior taxa de queda										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 */
void taxa_queda(Stats* municipios, int tamanho){
	
	float tc;
	float menorTc = (float)municipios[0].nascimentos[20]/municipios[0].nascimentos[19];
	string cidade = municipios[0].nome;

	for(int i = 1; i < tamanho; i++) {
		tc = (float)municipios[i].nascimentos[20]/municipios[i].nascimentos[19];
		if(tc < menorTc){
			menorTc = tc;
			cidade = municipios[i].nome;
		}
	}
	float p = 100.0 * (menorTc - 1);
	cout << fixed;
	cout << "Muncipio com maior taxa de queda 2013-2014: " << cidade << " (" << setprecision(2)
	<< p << "%)"<< endl;
}

/**
 * @brief Funcao que imprimi o nome e a porcentagem
 *				do muncipio com a maior taxa de crecimento										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 */
 void taxa_crescimento(Stats* municipios, int tamanho){
	
	float tc;
	float maiorTc = (float)municipios[0].nascimentos[20]/municipios[0].nascimentos[19];
	string cidade = municipios[0].nome;

	for(int i = 1; i < tamanho; i++) {
		tc = (float)municipios[i].nascimentos[20]/municipios[i].nascimentos[19];
		if(tc > maiorTc){
			maiorTc = tc;
			cidade = municipios[i].nome;
		}
	}
	float p = 100.0 * (maiorTc - 1);
	cout << fixed;
	cout << "Muncipio com maior taxa de crescimento 2013-2014: " << cidade << " (+" << setprecision(2)
	<< p << "%)"<< endl;
}