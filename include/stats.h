/**
 * @file	stats.h
 * @brief	Arquivo cabecalho com a definicao de um tipo estrutura
 *					com os campos codigo, nome e numero de nascimentos
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	12/04/2017
 * @date	12/04/2017
 */


#ifndef STATS_H
#define STATS_H

#include <string>

using std::string;
using std::getline;

/**
 * @struct 	Stats status.h
 * @brief 	Tipo estrutura que agrega os dados de nascimento de um municipio
 * @details	Os dados cobrem os anos de 1994 a 2014
 */
struct Stats {
	string codigo;			/**< Codigo do municipio */
	string nome;			/**< Nome do municipio */
	int nascimentos[21];	/**< Numero de nascimento em cada ano contabilizado */
};


#endif