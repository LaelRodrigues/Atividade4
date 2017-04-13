/**
 * @file	taxa.h
 * @brief	Arquivo cabecalho com os prototipos das funcaes que buscam
 *					saber quais muncipios tiveram a maior tava de queda
					e crecimento de 2013-2014
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	13/04/2017
 * @date	13/04/2017
 */

#ifndef TAXA_H
#define TAXA_H

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip> 
using std::fixed;
using std::setprecision;

#include "stats.h"

/**
 * @brief Funcao que imprimi o nome e a porcentagem
 *				do muncipio com a maior taxa de queda										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 */
void taxa_queda(Stats* municipios, int tamanho);

/**
 * @brief Funcao que imprimi o nome e a porcentagem
 *				do muncipio com a maior taxa de crecimento										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 */
 void taxa_crescimento(Stats* municipios, int tamanho);

 #endif