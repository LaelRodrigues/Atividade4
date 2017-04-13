/**
 * @file	arquivos.h
 * @brief	Arquivo cabecalho com os protipos das funcaes que
 *					realizam leitura e escrita em arquivos
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	12/04/2017
 * @date	12/04/2017
 */


#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <iostream>
using std::endl;
using std::cout;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstdlib>

using std::atoi;

#include "stats.h"

/**
 * @brief Funcao que realiza a leitura de dados de um arquivo
 *				e armazena em uma varialvel do tipo estrutura que contem
 *				os campos codigo e nome do municipio e o campo nascimento
 *				com o numero de nascimento a cada ano de 1994 a 2014 
 * @param	entrada	Variavel que referencia o arquivo de entrada
 * @param	municipios Grupo de municipios 
 * @param   tamanho	Quantidade de municipios
 */
void lerDados(ifstream &entrada, Stats* municipios, int tamanho);


/**
 * @brief	Funcao que imprime em um arquivo os dados referentes ao ano e suas 
 *					respectivas estatisticas em relacao ao numero de nascimentos 
 * @param saida Variavel que referencia o arquivo de saida
 * @param maior Maior numero de nascimentos em cada ano
 * @param menor Menor numero de nascimentos em cada ano
 * @param media Media do numero de nascimentos
 * @param dp Desvio padrao do numero de nascimentos
 * @param total Numero total de nascimentos
 */
void imprimirDadosEstatisticos(ofstream &saida, int *maior, int *menor, float *media, float *dp, int *total);


/**
 * @brief Funcao que imprime em um arquivo os dados referente ao ano
 *					e o numero total de nascimentos nesse ano  
 * @param saida	Variavel que referencia o arquivo de saida
 * @param total Numero total de nascimentos
 */
void imprimirDadosTotais(ofstream &saida, int *total);

#endif