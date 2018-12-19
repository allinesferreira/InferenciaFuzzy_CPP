/* 
 * File:   Guloso.h
 * Author: allinesf
 *
 * Created on 17 de Fevereiro de 2015, 20:31
 */

#ifndef GULOSO_H
#define	GULOSO_H
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Guloso {
public:
    Guloso();
    virtual ~Guloso();
    //vector<int> guloso(vector<string> vertice1, vector<vector<double> > hyperArestas, int &indiceDoSubconjuntoEstrela);
    vector<int> guloso(vector<vector<string> > matrizHG, int &indiceDoSubconjuntoEstrela, vector<string> &elementosDoConjunto, vector<string> &naoMembros);
    vector<vector<int> >  RetornaVertices(vector<string> vHEdge, vector<string> &elementosNaoRepetitivos);
    int VerificaAcessoDosNaoMembro(vector<int> linhasConjSelecao, vector< vector<int> > hyper_Arestas, int indiceColunaConjSelecao);
    
private:

};

#endif	/* GULOSO_H */

