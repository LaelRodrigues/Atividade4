/**
 * @file	estatisticas.h
 * @brief	Arquivo cabecalho com os prototipos das funcaes que 
 *					realizam operacaoes estatisticas nos dados do arquivo
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	13/04/2017
 * @date	13/04/2017
 */

#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include <iostream>
using std::endl;
using std::cout;

#include <cmath>
using std::pow;
using std::sqrt;

#include "stats.h"


/**
 * @brief Funcao que busca o maior numero de nascimentos 
 *  				em cada ano 										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 * @return Maior numero de nascimentos em cada ano
 */
int* maior_nascimentos(Stats *municipios, int tamanho);


/**
 * @brief Funcao que busca o menor numero de nascimentos
 *  				em cada ano 										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 * @return Menor numero de nascimentos em cada ano
 */
int* menor_nascimentos(Stats *municipios, int tamanho);


/**
 * @brief Funcao que calcula a media do numero de nascimentos
 *  				em cada ano 										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 * @return Media do numero de nascimentos em cada ano
 */
float* media_nascimentos(Stats* municipios, int tamanho);


/**
 * @brief Funcao que calcula o desvio padrao do numero de
 *  				nascimentos em cada ano 										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 * @return Desvio padrao do numero de nascimentos em cada ano
 */
float* desvio_padrao_nascimentos(Stats* municipios, int tamanho,  float* media);


/**
 * @brief Funcao que calcula o numero total de
 *  				nascimentos em cada ano 										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 * @return Desvio padrao do numero de nascimentos em cada ano
 */
int* total_nascimentos(Stats* municipios, int tamanho);

#endif