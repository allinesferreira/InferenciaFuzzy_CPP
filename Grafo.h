#ifndef GRAFO_H
#define	GRAFO_H
#include "Grafo.h"
#include <vector>
#include <string.h>
#include <iostream>
#include <list>
#include <algorithm>//função find

using namespace std;

class Grafo
{
    int V; //quantidade de vertices
    list<int> *adj; //ponteiro para um array contendo as listas de adjacencias, vizinhos
public:
    Grafo(int V);//construtor passando o número de vertices
    void adicionarAresta(int v1, int v2);// uma aresta saindo de v1 e chegando em v2
    bool existeVizinho(int v1, int v2);//Verifica se v2 é vizinho de v1
    void descricaoConsequente_v2(int qtdeConsequente, int indiceAtributoConsequente, int indiceElementoConseq, int indicePosicaoPertinenciaConseq, string cabecalhoConsequente, vector<double> valoresPertinenciaConsequente);
    void descricaoAntecedente_v1(int qtdeAntecedente, int indiceAtributo, int indiceElemento, int indicePosicaoPertinencia, string cabecalho, vector<double> valoresPertinencia);
    
};

#endif	/* GRAFO_H */

