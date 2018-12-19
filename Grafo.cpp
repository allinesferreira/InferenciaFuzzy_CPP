/* 
 * File:   Grafo.cpp
 * Author: allinesf
 * 
 * Created on 10 de Julho de 2015, 15:06
 */

#include "Grafo.h"
#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>//função find
using namespace std;


Grafo::Grafo(int V){
    this ->V = V; //atribui o número de vértices
    adj = new list<int>[V];//cada vertice tem uma lista com seus vizinho, cria as listas
}

void Grafo::adicionarAresta(int v1, int v2){
    //adiciona vertice v2 à lista de vertices adjacentes de v1
    adj[v1].push_back(v2);
}

void Grafo:: descricaoAntecedente_v1(int qtdeAntecedente, int indiceAtributo, int indiceElemento, int indicePosicaoPertinencia, string cabecalho, vector<double> valoresPertinencia){
 
    vector<string> cabecalhoAntecedente;
    vector<int> indicePosicaoPertinenciaAntecedente, indiceAtributoAntecedente, indiceElementoAntecedente, totalElementosAntecedente; 
    vector<vector <double> > pertinenciaDoGrupoAtencedente;
       
    ofstream outputQtdeElementosAntecedente;
    ofstream outputCabecalho;
    ofstream outputIndAtributo;
    ofstream outputIndElemAntecedente;
    ofstream outputIndPosicaoPertAntecedente;
    ofstream outputPertDoGrupoAtencedente;
    
    outputQtdeElementosAntecedente.open("TotalElementosAntecedente",ios::app);
    outputCabecalho.open("CabecalhoAntecedentes",ios::app);
    outputIndAtributo.open("IndAtributoAntecedentes",ios::app);
    outputIndElemAntecedente.open("IndElementoAntecedentes",ios::app);
    outputIndPosicaoPertAntecedente.open("IndicePosicaoPertinenciaAntecedente",ios::app);
    outputPertDoGrupoAtencedente.open("PertinenciaDoGrupoAtencedente",ios::app);
    
    //Alimentando a descrição dos vértices
    totalElementosAntecedente.push_back(qtdeAntecedente);
    cabecalhoAntecedente.push_back(cabecalho);
    indiceAtributoAntecedente.push_back(indiceAtributo);
    indiceElementoAntecedente.push_back(indiceElemento);
    indicePosicaoPertinenciaAntecedente.push_back(indicePosicaoPertinencia);
    pertinenciaDoGrupoAtencedente.push_back(valoresPertinencia);
    
    //Tratamento de erro para o arquivo de saída
    if(!outputQtdeElementosAntecedente.is_open()){
        printf("Erro na abertura dos arquivos de TotalElementosAntecedente!");
        outputQtdeElementosAntecedente.clear();
        exit(1);
    }
        
    if(!outputCabecalho.is_open()){
        printf("Erro na abertura dos arquivos de CabecalhoAntecedentes!");
        outputCabecalho.clear();
        exit(1);
    }

    if(!outputIndAtributo.is_open()){
        printf("Erro na abertura dos arquivos de IndAtributoAntecedentes!");
        outputIndAtributo.clear();
        exit(1);
    }

    if(!outputIndElemAntecedente.is_open()){
        printf("Erro na abertura dos arquivos de IndElementoAntecedentes!");
        outputIndElemAntecedente.clear();
        exit(1);
    }

    if(!outputIndPosicaoPertAntecedente.is_open()){
        printf("Erro na abertura dos arquivos de IndicePosicaoPertinenciaAntecedente!");
        outputIndPosicaoPertAntecedente.clear();
        exit(1);
    }

    if(!outputPertDoGrupoAtencedente.is_open()){
        printf("Erro na abertura dos arquivos de PertinenciaDoGrupoAtencedente!");
        outputPertDoGrupoAtencedente.clear();
        exit(1);
    }
    
    //Gravando os arquivos
    for(int i=0; i< totalElementosAntecedente.size();i++){
        outputQtdeElementosAntecedente<<totalElementosAntecedente.at(i)<<endl;
    }
        
    for(int i=0; i< cabecalhoAntecedente.size();i++){
        outputCabecalho<<cabecalhoAntecedente.at(i)<<endl;
    }
        
    for(int i=0; i< indiceAtributoAntecedente.size();i++){
        outputIndAtributo<<indiceAtributoAntecedente.at(i)<<endl;
    }
                
    for(int i=0; i< indiceElementoAntecedente.size();i++){
        outputIndElemAntecedente<<indiceElementoAntecedente.at(i)<<endl;
    }
        
    for(int i=0; i< indicePosicaoPertinenciaAntecedente.size();i++){
        outputIndPosicaoPertAntecedente<<indicePosicaoPertinenciaAntecedente.at(i)<<endl;
    }
        
    for(int i=0; i< pertinenciaDoGrupoAtencedente.size();i++){
        for(int j=0; j< pertinenciaDoGrupoAtencedente[i].size(); j++){
            outputPertDoGrupoAtencedente<<pertinenciaDoGrupoAtencedente[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //Fechando os arquivos
    outputQtdeElementosAntecedente.close();
    outputCabecalho.close();
    outputIndAtributo.close();
    outputIndElemAntecedente.close();
    outputIndPosicaoPertAntecedente.close();
    outputPertDoGrupoAtencedente.close();
    
}

void Grafo:: descricaoConsequente_v2(int qtdeConsequente, int indiceAtributoConsequente, int indiceElementoConseq, int indicePosicaoPertinenciaConseq, string cabecalhoConsequente, vector<double> valoresPertinenciaConsequente){
 
    vector<string> cabecalhoConseq;
    vector<int> indicePosicaoPertinenciaConsequente, indiceAtributoConseq, indiceElementoConsequente, totalElementosConsequente; 
    vector<vector <double> > pertinenciaDoGrupoConsequente;
    
    //Alimentando a descrição dos vértices
    totalElementosConsequente.push_back(qtdeConsequente);
    cabecalhoConseq.push_back(cabecalhoConsequente);
    indiceAtributoConseq.push_back(indiceAtributoConsequente);
    indiceElementoConsequente.push_back(indiceElementoConseq);
    indicePosicaoPertinenciaConsequente.push_back(indicePosicaoPertinenciaConseq);
    pertinenciaDoGrupoConsequente.push_back(valoresPertinenciaConsequente);
    
    ofstream outputQtdeElementosConsequente;
    ofstream outputCabecalho;
    ofstream outputIndAtributo;
    ofstream outputIndElemConsequente;
    ofstream outputIndPosicaoPertConsequente;
    ofstream outputPertDoGrupoConsequente;
    
    outputQtdeElementosConsequente.open("TotalElementosConsequente",ios::app);
    outputCabecalho.open("CabecalhoConsequente",ios::app);
    outputIndAtributo.open("IndAtributoConsequente",ios::app);
    outputIndElemConsequente.open("IndElementoConsequente",ios::app);
    outputIndPosicaoPertConsequente.open("IndicePosicaoPertinenciaConsequente",ios::app);
    outputPertDoGrupoConsequente.open("PertinenciaDoGrupoConsequente",ios::app);
    
    //Tratamento de erro para o arquivo de saída
    if(!outputQtdeElementosConsequente.is_open()){
        printf("Erro na abertura dos arquivos de TotalElementosConsequente!");
        outputQtdeElementosConsequente.clear();
        exit(1);
    }
        
    if(!outputCabecalho.is_open()){
        printf("Erro na abertura dos arquivos de CabecalhoConsequente!");
        outputCabecalho.clear();
        exit(1);
    }

    if(!outputIndAtributo.is_open()){
        printf("Erro na abertura dos arquivos de IndAtributoConsequente!");
        outputIndAtributo.clear();
        exit(1);
    }

    if(!outputIndElemConsequente.is_open()){
        printf("Erro na abertura dos arquivos de IndElementoConsequente!");
        outputIndElemConsequente.clear();
        exit(1);
    }

    if(!outputIndPosicaoPertConsequente.is_open()){
        printf("Erro na abertura dos arquivos de IndicePosicaoPertinenciaConsequente!");
        outputIndPosicaoPertConsequente.clear();
        exit(1);
    }

    if(!outputPertDoGrupoConsequente.is_open()){
        printf("Erro na abertura dos arquivos de PertinenciaDoGrupoConsequente!");
        outputPertDoGrupoConsequente.clear();
        exit(1);
    }
    
    //Gravando os arquivos
    for(int i=0; i< totalElementosConsequente.size();i++){
        outputQtdeElementosConsequente<<totalElementosConsequente.at(i)<<endl;
    }
        
    for(int i=0; i< cabecalhoConsequente.size();i++){
        outputCabecalho<<cabecalhoConsequente.at(i)<<endl;
    }
        
    for(int i=0; i< indiceAtributoConseq.size();i++){
        outputIndAtributo<<indiceAtributoConseq.at(i)<<endl;
    }
                
    for(int i=0; i< indiceElementoConsequente.size();i++){
        outputIndElemConsequente<<indiceElementoConsequente.at(i)<<endl;
    }
        
    for(int i=0; i< indicePosicaoPertinenciaConsequente.size();i++){
        outputIndPosicaoPertConsequente<<indicePosicaoPertinenciaConsequente.at(i)<<endl;
    }
        
    for(int i=0; i< pertinenciaDoGrupoConsequente.size();i++){
        for(int j=0; j< pertinenciaDoGrupoConsequente[i].size(); j++){
            outputPertDoGrupoConsequente<<pertinenciaDoGrupoConsequente[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //Fechando os arquivos
    outputQtdeElementosConsequente.close();
    outputCabecalho.close();
    outputIndAtributo.close();
    outputIndElemConsequente.close();
    outputIndPosicaoPertConsequente.close();
    outputPertDoGrupoConsequente.close();

}

bool Grafo::existeVizinho(int v1, int v2){
    //busca na lista de v1, do início de v1 até o final, busca por v2
    //se find for diferente de adj quer dizer que achou, quer dizer que v2 está na lista de v1
    if(find(adj[v1].begin(), adj[v1].end(), v2)!= adj[v1].end())
        return true;
    return false;
}

