/** 
 * @file	main.cpp
 * @brief   Codigo fonte de teste das funcoes que realizam operacoes
 * 					estatisticas com o dados do arquivo 
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	13/04/2017
 * @date	13/04/2017
*/

#include "estatisticas.h"
#include "arquivos.h"
#include "taxa.h"

/**
 * @brief Funcao principal
 */
int main(int argc, char* argv[]) {

	
	if(argc != 2){
		cout << "Parametros invalidos!!" << endl;
	}

	//arquivo de entrada para leitura de dados
	ifstream entrada(argv[1]);
	if(!entrada){
		cout << "Erro ao abrir o arquivo!!" << endl;
		cout << "Programa finalizado." << endl;
		return 0;
	}

	//leitura do arquivo para indentificar a quantidade de muncipios
	int contMunicipios = 0;
	string numLinha;
	while(getline(entrada, numLinha)){
		contMunicipios++;
	}

	//vetor do tipo estrutura para representar os dados dos municipios
	Stats *municipios = new Stats[contMunicipios];
	if(!municipios){
		cout << "Erro. Memoria nao alocada!!" << endl;
		cout << "Programa finalizado" << endl;
		return 0;
	}

	entrada.clear();
	entrada.seekg(0, entrada.beg);
	contMunicipios -= 2; //operacao realizada para que a primeira e ultima linha sejam descartadas 

	//leitura dos dados do arquivo
	lerDados(entrada, municipios, contMunicipios);

	//vetores utilizados para representar os dados estatisticos
	int *maior = new int[21];
	if(!maior){
		cout << "Erro. Memoria nao alocada!!" << endl;
		cout << "Programa finalizado" << endl;
		return 0;
	}
	int *menor = new int[21];
	if(!menor){
		cout << "Erro. Memoria nao alocada!!" << endl;
		cout << "Programa finalizado" << endl;
		return 0;
	}
	float *media = new float[21];
	if(!media){
		cout << "Erro. Memoria nao alocada!!" << endl;
		cout << "Programa finalizado" << endl;
		return 0;
	}
	float *desvio_padrao = new float[21];
	if(!desvio_padrao){
		cout << "Erro. Memoria nao alocada!!" << endl;
		cout << "Programa finalizado" << endl;
		return 0;
	}
	int *total = new int[21];
	if(!total){
		cout << "Erro. Memoria nao alocada!!" << endl;
		cout << "Programa finalizado" << endl;
		return 0;
	}

	maior = maior_nascimentos(municipios, contMunicipios);
	menor = menor_nascimentos(municipios, contMunicipios);
	media = media_nascimentos(municipios, contMunicipios);
	desvio_padrao = desvio_padrao_nascimentos(municipios, contMunicipios, media);
	total = total_nascimentos(municipios, contMunicipios);


    //arquivo de saida para escrita de dados 
	ofstream saida1("../data/estatisticas.csv");
	if(!saida1) {
		cout << "Erro ao abrir o arquivo!!" << endl;
		cout << "Programa finalizado." << endl;
		return 0;
	}
	//gravacao dos dados estatisticos
	imprimirDadosEstatisticos(saida1, maior, menor, media, desvio_padrao, total);

	delete[] maior;
	delete[] menor;
	delete[] media;
	delete[] desvio_padrao;
	//arquivo de saida para escrita de dados
	ofstream saida2("../data/totais.dat");
	if(!saida2) {
		cout << "Erro ao abrir o arquivo!!" << endl;
		cout << "Programa finalizado." << endl;
		return 0;
	}

	//gravacao dos dados com o total de nascimentos em cada ano
	imprimirDadosTotais(saida2, total);

	delete[] total;

	cout << "...Arquivo estatisticas.csv gerado" << endl;
	cout << "...Arquivo totais.dat gerado" << endl;
	cout << endl;
	taxa_queda(municipios, contMunicipios);
	taxa_crescimento(municipios, contMunicipios);

	delete[] municipios;

	return 0;
}