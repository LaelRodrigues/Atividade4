/**
 * @file	arquivos.cpp
 * @brief	Arquivo corpo com a implementacao das funcaes que
 *					realizam leitura e escrita em arquivos
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	12/04/2017
 * @date	12/04/2017
 */


#include "arquivos.h"


/**
 * @brief Funcao que realiza a leitura de dados de um arquivo
 *				e armazena em uma varialvel do tipo estrutura que contem
 *				os campos codigo e nome do municipio e o campo nascimento
 *				com o numero de nascimento a cada ano de 1994 a 2014 
 * @param entrada Variavel que referencia o arquivo de entrada
 * @param municipios Grupo de municipios 
 * @param tamanho Quantidade de municipios
 */
void lerDados(ifstream &entrada, Stats* municipios, int tamanho) {
			
	string linha1;           // variavel utilizada para que a primeira linha seja descatada
	string ultimaCol;        // varial utilzada para que a ultima coluna seja sempre descatada
	string nasc; 		     // Varialvel para ler o numero de nascimentos

	getline(entrada, linha1);

	for(int i = 0; i < tamanho; i++){
		entrada.ignore();
		getline(entrada, municipios[i].codigo, ' ');
		getline(entrada, municipios[i].nome, '"');
		entrada.ignore();
		for(int j = 0; j < 21; j++){
			getline(entrada, nasc, ';');
			municipios[i].nascimentos[j] = atoi(nasc.c_str());
		}
		getline(entrada, ultimaCol);
	}
}

/**
 * @brief Funcao que imprime em um arquivo os dados referentes ao ano e suas 
 *				respectivas estatisticas em relacao ao numero de nascimentos 
 * @param saida Variavel que referencia o arquivo de saida
 * @param maior Maior numero de nascimentos em cada ano
 * @param menor Menor numero de nascimentos em cada ano
 * @param media Media do numero de nascimentos
 * @param dp Desvio padrao do numero de nascimentos
 * @param total Numero total de nascimentos
 */
void imprimirDadosEstatisticos(ofstream &saida, int *maior, int *menor, float *media, float *dp, int *total){

	int ano = 1994;

	for(int i = 0; i < 21; i++) {
		saida << ano << ";" << maior[i] << ";" << menor[i] << ";"
		<< media[i] << ";" << dp[i] << ";" << total[i] << endl; 
		ano++;
	}
}


/**
 * @brief Funcao que imprime em um arquivo os dados referente ao ano
 *				e o numero total de nascimentos nesse ano  
 * @param saida	Variavel que referencia o arquivo de saida
 * @param total Numero total de nascimentos
 */
void imprimirDadosTotais(ofstream &saida, int *total){

	int ano = 1994;

	for(int i = 0; i < 21; i++){
		saida << ano << " " << total[i] << endl;
		ano++;
	}
}