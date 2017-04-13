/**
 * @file	estatisticas.cpp
 * @brief	Arquivo corpo com a implementacao das funcaes que
 *					realizam operacaoes estatisticas nos dados do arquivo
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	12/04/2017
 * @date	12/04/2017
 */


#include "estatisticas.h"


/**
 * @brief Funcao que busca o maior numero de nascimentos 
 *  			em cada ano 										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 * @return Maior numero de nascimentos em cada ano
 */
int* maior_nascimentos(Stats *municipios, int tamanho){

	int *maior = new int[21]; 

	for(int i = 0; i < 21; i++){
		maior[i] = municipios[0].nascimentos[i]; 
		for(int j = 1; j < tamanho; j++){
			if(municipios[j].nascimentos[i] > maior[i]){
				maior[i] = municipios[j].nascimentos[i];
			}
		}
	}
	return maior;
}


/**
 * @brief Funcao que busca o menor numero de nascimentos
 *  			em cada ano 										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 * @return Menor numero de nascimentos em cada ano
 */
int* menor_nascimentos(Stats *municipios, int tamanho){

	int *menor = new int[21]; 

	for(int i = 0; i < 21; i++){
		menor[i] = municipios[0].nascimentos[i]; 
		for(int j = 1; j < tamanho; j++){
			if(municipios[j].nascimentos[i] < menor[i]){
				menor[i] = municipios[j].nascimentos[i];
			}
		}
	}
	return menor;
}


/**
 * @brief Funcao que calcula a media do numero de nascimentos
 *  			em cada ano 										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 * @return Media do numero de nascimentos em cada ano
 */
float* media_nascimentos(Stats* municipios, int tamanho){

	float *media = new float[21]; 
	int soma;

	for(int i = 0; i < 21; i++){
		soma = 0;
		for(int j = 0; j < tamanho; j++){
			soma += municipios[j].nascimentos[i];
		}
		media[i] = (float)soma / tamanho;
	}
	return media;
}


/**
 * @brief Funcao que calcula o desvio padrao do numero de
 *  			nascimentos em cada ano 										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 * @return Desvio padrao do numero de nascimentos em cada ano
 */
float* desvio_padrao_nascimentos(Stats* municipios, int tamanho,  float* media){

	float *dp = new float[21]; 
	float soma;

	for(int i = 0; i < 21; i++){
		soma = 0;
		for(int j = 0; j < tamanho; j++){
			soma += pow(municipios[j].nascimentos[i] - media[i], 2);
		}
		dp[i] = sqrt((1.0/tamanho) * soma);
	}

	return dp;
}




/**
 * @brief Funcao que calcula o numero total de
 *  			nascimentos em cada ano 										
 * @param municipios Grupo de municipios
 * @param tamanho Quantidade de municipios
 * @return Desvio padrao do numero de nascimentos em cada ano
 */
int* total_nascimentos(Stats* municipios, int tamanho) {

	int *total = new int[21]; 
	int soma;

	for(int i = 0; i < 21; i++){
		soma = 0;
		for(int j = 0; j < tamanho; j++){
			soma += municipios[j].nascimentos[i];
		}
		total[i] = soma;
	}
	return total;
}