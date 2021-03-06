/*
 * Solucao.h
 *
 *  Created on: 02/12/2014
 *      Author: Leo
 */

#ifndef SOLUCAO_H_
#define SOLUCAO_H_

#include "Dados.h"
#include <vector>



class Solucao {
public:

	Dados * d;
	int* demanda;// demanda dos recursos utilizado na solucao
	float custo;
	int tempo;

	vector<int> Ti;// tempo que iniciara a atividade j
	vector<int> M;// modo em que sera executada da atividade j
	vector<int> D;// o quanto durara a atividade j

	vector<bool> alocadas;// vetor que diz se a atividade j esta alocada
	vector < vector < int > > tr;// matriz de tipo de recurso k por tempo t , onde o conteúdo int é a quantidade utilizada de recurso to tipo k no tempo t.

	/* Métodos de Operações Bases */
	void alocarAtividade(int j, int ti, int mi);// aloca atividade j no tempo de inicio ti, no modo mi, ja faz toda as alteracoes na solucao


	/* Métodos de Incialização */
	void iniciarSolucaoComModosAleatorios();// inicia a solucao alocando as atividades pela ordem de precedencia, com seus modos aleatorios
	void iniciarSolucaoComMelhorMakespan();// inicia a solucao alocando as atividades pela ordem de precedencia, com os modos de menor tempo
	void iniciarSolucaoComMelhorCusto();// inicaiar solucao com menor custo sem alocar novos recursos, com modos que utilizem menos custo

	/* Métodos para Verificacao */
	int verificarTempoInicioCedo(int j);// verifica o mais cedo tempo de inicio (ti) possivel para a atividade j, pelas suas precedencias ja cadastradas
	int verificarMelhorModoPeloTempo(int j);// verifica o modo que gastará menos tempo, desconsiderando o custo do recurso
	int verificarMelhorModoPelaUtilizacao(int j);// verifica o modo que utiliza menos recursos, desconsiderando o tempo de duracao da atividade


	/* Métodos de Atualização */
	void atualizarDemanda(int ti, int tf);//atualiada o valor da demanda dos recursos verificando apenas um determinada periodo de tepo da solucao de ti ate tf.

	/* Métodos de Calculos */
	float calcular_custo();
	int calcular_tempo();

	void print();

	Solucao(Dados *d);
	virtual ~Solucao();


};


#endif /* SOLUCAO_H_ */
