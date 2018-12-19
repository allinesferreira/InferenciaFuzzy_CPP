/* 
 * File:   utilitarios.cpp
 * Author: allinesf
 * 
 * Created on 10 de Dezembro de 2014, 14:55
 */

#include "utilitarios.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <bits/stl_vector.h>

using namespace std;

utilitarios::utilitarios(){
    
}
double utilitarios::converteValorDouble(string str) {
    istringstream cpd(str);
    double retorno;
    
    cpd >> retorno;
    return retorno;
}

int utilitarios::converteValorInteiro(string str) {
    istringstream cpd(str);
    int retorno;
    
    cpd >> retorno;
    return retorno;
}

utilitarios::utilitarios(const utilitarios& orig) {}

utilitarios::~utilitarios() {}

vector< vector<string> > utilitarios::defineVertices(char nomeArqOut[50]){
    
    ifstream input;
    vector<string> v1;
    string palavra1Ant, palavra2Ant, palavra3Ant, palavra4Ant, simboloAnt, valorAnt;
    string palavra1Ver, palavra2Ver;
    string palavra1, palavra2, palavra3, palavra4, simbolo, valor;
    vector<vector<string> > hyperGrafo;
    int cont=0;
     
    
    input.open(nomeArqOut, ifstream::in);
        
    
    if((!input.is_open())){
        printf("Erro na abertura dos arquivos!");
        input.clear();
        exit(1);
    }
    input>>palavra1;
    input>>simbolo;
    input>>palavra2;
    input>>palavra3;
    input>>palavra4;
        
    while(input.good()){
        
        input>>palavra1Ant;
        input>>simboloAnt;
        input>>palavra2Ant;
        input>>palavra3Ant;
        input>>palavra4Ant;
        
        v1.push_back(palavra1);
        v1.push_back(palavra2);
        
        if(((palavra1 == palavra1Ant)||(palavra1 == palavra2Ant))||((palavra2 == palavra1Ant)||(palavra2 == palavra2Ant))){
            cont++;
        }
        if(cont != 0){
            //Verificando associação de hyper arestas
            palavra1 = palavra1Ant;
            palavra2 = palavra2Ant;
            cont=0;
        }else{
            //Excluindo valores repetidos
            /*
            for(int i=0;i<v1.size();i++){
                for(int ii=i+1;ii<v1.size();ii++){
                    if(v1.at(i)==v1.at(ii)){
                        v1.erase(v1.begin()+ii);
                        ii--;
                    }
                }
            }
            */
            hyperGrafo.push_back(v1);
            v1.clear();
            palavra1 = palavra1Ant;
            palavra2 = palavra2Ant;
        }
    }
    //Cheguei no fim do arquivo
    //Excluindo valores repetidos
    /*
    for(int i=0;i<v1.size();i++){
        for(int ii=i+1;ii<v1.size();ii++){
            if(v1.at(i)==v1.at(ii)){
                v1.erase(v1.begin()+ii);
                ii--;
            }
        }
    }
    */
    hyperGrafo.push_back(v1);
    v1.clear();
    
    //imprimindo
    /*
    for(int i=0;i<hyperGrafo.size();i++){
        for(int ii=0;ii<hyperGrafo[i].size();ii++){
            cout<<hyperGrafo[i][ii]<<" ";
        }cout<<endl;
    }
    */
    //Fechando arquivo
    input.close();
    return hyperGrafo;
    
}

double ** utilitarios::defineArestas(vector<string> vertice1, vector<string> vertice2, char nomeArq[50], int tamLinha, int tamColuna, vector<vector<int> > &SC, double confidencia, vector<string> &posicoesHEdge){
    
    ifstream input;
    string palavra1, palavra2, palavra3, palavra4, simbolo, palavra1A, palavra2A, palavra3A, palavra4A, simboloA;
    string valorCA, valorC, valorSA, valorS;
    double **valorAresta;
    int valorConvertidoSA, valorConvertidoS;
    vector< vector<int> > valorConfianca(tamLinha,vector<int>(tamColuna,0));
    vector<double> valoresConvertidos;
    double somatorio=0, valorConvertidoCA,valorConvertidoC;
        
    //Inicializando a matriz valorAresta
    valorAresta = new double*[tamLinha];
    
    for(int i=0; i<tamLinha; i++)
    {
        valorAresta[i] = new double[tamColuna];
    }
    
    //Valor inicial de valorAresta
    for(int i=0;i<tamLinha;i++){
        for(int j=0; j<tamColuna;j++){
            valorAresta[i][j]=0;
        }
    }
    
    input.open(nomeArq, ifstream::in);
        
    if((!input.is_open())){
        printf("Erro na abertura dos arquivos!");
        input.clear();
        exit(1);
    }
    
    input>>palavra1A;
    input>>simboloA;
    input>>palavra2A;
    input>>palavra3A;
    input>>palavra4A;
    
    while(input.good()){
        
        input>>palavra1;
        input>>simbolo;
        input>>palavra2;
        input>>palavra3;
        input>>palavra4;
    
        //Selecionando apenas os elementos que tem associação hyperEdge
        if((palavra1A == palavra2)|| (palavra2A == palavra1)){
            //if((palavra1A == palavra1)||(palavra2A == palavra2)){
                for(int i=0; i<vertice1.size();i++){
                    for(int j=0;j<vertice2.size();j++){

                        if((palavra1A == vertice1[i])&&(palavra2A==vertice2[j])){
                            //Incluindo apenas o valor da confidencia

                            for(int jj=0;jj<(palavra4A.size()-2);jj++)
                            {
                                valorCA.push_back(palavra4A[jj]);
                                valorC.push_back(palavra4[jj]);

                            }
                            valorConvertidoCA = converteValorDouble(valorCA) ;
                            valorConvertidoC = converteValorDouble(valorC);
                            valoresConvertidos.push_back(valorConvertidoCA);
                            valoresConvertidos.push_back(valorConvertidoC);

                            //Incluindo apenas o valor do suporte

                            for(int jj=1;jj<(palavra3A.size()-2);jj++)
                            {
                                valorSA.push_back(palavra3A[jj]);
                                valorS.push_back(palavra3[jj]);

                            }
                            valorConvertidoSA = converteValorInteiro(valorSA) ;
                            valorConvertidoS = converteValorInteiro(valorS);

                            /*
                            * Definindo a hyperarestas
                            * Sabemos que um item set {a,b} é considerado uma hyperarestas se a média
                            * da regra de confidencia: a->b e b-> a é maior que o threshold.
                            */

                            for(int m=0; m<valoresConvertidos.size(); m++){
                                somatorio = somatorio + valoresConvertidos.at(m);
                                if((somatorio/valoresConvertidos.size())>= confidencia){
                                    valorAresta[i][j]= (valorConvertidoSA + valorConvertidoS);
                                    valorConfianca[i][j] = 1;
                                    valorAresta[j][i]= (valorConvertidoSA + valorConvertidoS);
                                    valorConfianca[j][i] = 1;
                                    /*
                                    * Cria um vetor para guardar os índices dos elementos que contêm associação
                                    * hyper-edge
                                    */
                                    posicoesHEdge.push_back(vertice1[i]);
                                    posicoesHEdge.push_back(vertice2[j]);
                                    valorSA.clear();
                                    valorCA.clear();
                                    valorC.clear();
                                    valorS.clear();
                                }
                            }
                            somatorio =0; 
                            valoresConvertidos.clear();
                            break;

                        }
                        valorSA.clear();
                        valorCA.clear();
                        valorC.clear();
                        valorS.clear();
                    }
                }
                palavra1A = palavra1;
                simboloA = simbolo;
                palavra2A = palavra2;
                palavra3A = palavra3;
                palavra4A = palavra4;
            //}
                
            
        }else {
            palavra1A = palavra1;
            simboloA = simbolo;
            palavra2A = palavra2;
            palavra3A = palavra3;
            palavra4A = palavra4;
        }
    } 
    input.close();
    
    //A matriz SC passa a ter os mesmos valores da matriz valor confianca
    SC = valorConfianca;
   /*
    cout<<"\n Imprimindo valorAresta"<<endl;
    for(int i=0; i<tamLinha; i++){
        for(int j=0; j<tamColuna;j++){
            cout<<valorAresta[i][j]<<" ";
        }cout<<endl;
    }
    */
    return valorAresta;
}
vector<vector<double> > utilitarios::defineHyperArestas(vector<string> verti2, vector<string> verti1, char Arquivo[50], double confidencia, vector<string> &HArestas){
    int linha =  (verti1.size());
    int coluna = (verti2.size());
    double **arestas;
    vector< vector<int> > mConfidencia (linha, vector<int>(coluna,0));
    vector< vector<double> > grafo (linha, vector<double>(coluna,0));
    vector<string> indiceHyperEdge;
       
    //Inlcuindo as arestas conforme valor suporte
    arestas=  defineArestas(verti1, verti2, Arquivo,linha,coluna,mConfidencia, confidencia, indiceHyperEdge);
    HArestas = indiceHyperEdge;
    
    //Matriz como um grafo
    for(int i=0;i<linha; i++){
        for(int j=0; j<coluna; j++){
            grafo[i][j] = arestas[i][j];
        }
    }

    return grafo;
    
}


void utilitarios::TransformaCaracteristicaEmItem(char nomeDaBase[50], vector<string> nomeArqPertinencia){
    
    Tabela tab;
    Pertinencia pert;
    string palavra;
    char nome[15];
    ifstream inputNomeBase;
    ifstream inputNomeArqP1, inputNomeArqP5, inputNomeArqP6, inputNomeArqP8, inputNomeArqP9, inputNomeArqP10, inputNomeArqP11, inputNomeArqP13;
    ifstream inputNomeArqP16, inputNomeArqP17, inputNomeArqP18, inputNomeArqP19, inputNomeArqP23, inputNomeArqP24, inputNomeArqP25, inputNomeArqP26;
    ifstream inputNomeArqP27, inputNomeArqP28, inputNomeArqP29, inputNomeArqP30, inputNomeArqP31, inputNomeArqP32, inputNomeArqP33, inputNomeArqP34;
    ifstream inputNomeArqP35, inputNomeArqP36, inputNomeArqP37, inputNomeArqP38, inputNomeArqP39, inputNomeArqP40, inputNomeArqP41;
    ofstream output("BaseItem");
        
    inputNomeBase.open(nomeDaBase, ifstream::in);
    palavra = nomeArqPertinencia.at(0);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP1.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(1);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP5.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(2);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP6.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(3);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP8.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(4);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP9.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(5);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP10.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(6);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP11.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(7);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP13.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(8);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP16.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(9);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP17.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(10);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP18.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(11);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP19.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(12);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP23.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(13);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP24.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(14);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP25.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(15);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP26.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(16);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP27.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(17);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP28.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(18);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP29.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(19);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP30.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(20);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP31.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(21);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP32.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(22);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP33.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(23);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP34.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(24);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP35.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(25);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP36.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(26);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP37.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(27);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP38.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(28);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP39.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(29);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP40.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(30);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP41.open(nome, ifstream::in);
    
    //Tratamento de erro caso os arquivos não existam
    if(!inputNomeBase.is_open()){
        printf("Erro na abertura dos arquivos de base original!");
        inputNomeBase.clear();
        exit(1);
    }
    
    if((!inputNomeArqP1.is_open())||(!inputNomeArqP5.is_open())||(!inputNomeArqP6.is_open())||(!inputNomeArqP8.is_open())||(!inputNomeArqP9.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP1.clear();
        inputNomeArqP5.clear();
        inputNomeArqP6.clear();
        inputNomeArqP8.clear();
        inputNomeArqP9.clear();
        exit(1);
    }
    
    if((!inputNomeArqP10.is_open())||(!inputNomeArqP11.is_open())||(!inputNomeArqP13.is_open())||(!inputNomeArqP16.is_open())||(!inputNomeArqP17.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP10.clear();
        inputNomeArqP11.clear();
        inputNomeArqP13.clear();
        inputNomeArqP16.clear();
        inputNomeArqP17.clear();
        exit(1);
    }
    
    if((!inputNomeArqP18.is_open())||(!inputNomeArqP19.is_open())||(!inputNomeArqP23.is_open())||(!inputNomeArqP24.is_open())||(!inputNomeArqP25.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP18.clear();
        inputNomeArqP19.clear();
        inputNomeArqP23.clear();
        inputNomeArqP24.clear();
        inputNomeArqP25.clear();
        exit(1);
    }
    
    if((!inputNomeArqP26.is_open())||(!inputNomeArqP27.is_open())||(!inputNomeArqP28.is_open())||(!inputNomeArqP29.is_open())||(!inputNomeArqP30.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP26.clear();
        inputNomeArqP27.clear();
        inputNomeArqP28.clear();
        inputNomeArqP29.clear();
        inputNomeArqP30.clear();
        exit(1);
    }
    
    if((!inputNomeArqP31.is_open())||(!inputNomeArqP32.is_open())||(!inputNomeArqP33.is_open())||(!inputNomeArqP34.is_open())||(!inputNomeArqP35.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP31.clear();
        inputNomeArqP32.clear();
        inputNomeArqP33.clear();
        inputNomeArqP34.clear();
        inputNomeArqP35.clear();
        exit(1);
    }
    
    if((!inputNomeArqP36.is_open())||(!inputNomeArqP37.is_open())||(!inputNomeArqP38.is_open())||(!inputNomeArqP39.is_open())||(!inputNomeArqP40.is_open())||(!inputNomeArqP41.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP36.clear();
        inputNomeArqP37.clear();
        inputNomeArqP38.clear();
        inputNomeArqP39.clear();
        inputNomeArqP40.clear();
        inputNomeArqP41.clear();
        exit(1);
    }
    
    //Tratamento de erro para o arquivo de saída
    if((!output.is_open())){
        printf("Erro na abertura do arquivo de saída!");
        output.clear();
        exit(1);
    }
    
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(!inputNomeBase.eof()){
        
        inputNomeBase>>tab.duracao;
        inputNomeBase>>tab.tipo_protocolo;
        inputNomeBase>>tab.servico;
        inputNomeBase>>tab.flag;
        inputNomeBase>>tab.src_bytes;
        inputNomeBase>>tab.dst_bytes;
        inputNomeBase>>tab.land;
        inputNomeBase>>tab.wrong_fragment;
        inputNomeBase>>tab.urgente;
        inputNomeBase>>tab.hot;
        inputNomeBase>>tab.num_faleid_logins;
        inputNomeBase>>tab.logged_in;
        inputNomeBase>>tab.num_compromised;
        inputNomeBase>>tab.root_shell;
        inputNomeBase>>tab.su_attempted;
        inputNomeBase>>tab.num_root;
        inputNomeBase>>tab.num_file_creatinos;
        inputNomeBase>>tab.num_shells;
        inputNomeBase>>tab.num_access_files;
        inputNomeBase>>tab.num_outbound_cmds;
        inputNomeBase>>tab.is_hot_login;
        inputNomeBase>>tab.is_guest_login;
        inputNomeBase>>tab.count;
        inputNomeBase>>tab.srv_count;
        inputNomeBase>>tab.serror_rate;
        inputNomeBase>>tab.srv_serror_rate;
        inputNomeBase>>tab.rerror_rate;
        inputNomeBase>>tab.srv_rerror_rate;
        inputNomeBase>>tab.same_srv_rate;
        inputNomeBase>>tab.diff_srv_rate;
        inputNomeBase>>tab.srv_diff_host_rate;
        inputNomeBase>>tab.dst_host_count;
        inputNomeBase>>tab.dst_host_srv_count;
        inputNomeBase>>tab.dst_host_same_srv_rate;
        inputNomeBase>>tab.dst_host_diff_srv_rate;
        inputNomeBase>>tab.dst_host_same_src_port_rate;
        inputNomeBase>>tab.dst_host_srv_diff_host_rate;
        inputNomeBase>>tab.dst_host_serror_rate;
        inputNomeBase>>tab.dst_host_srv_serror_rate;
        inputNomeBase>>tab.dst_host_rerror_rate;
        inputNomeBase>>tab.dst_host_srv_rerror_rate;
        inputNomeBase>>tab.etiqueta;
        
        inputNomeArqP1>>pert.duracaoBaixa;
        inputNomeArqP1>>pert.duracaoMedia;
        inputNomeArqP1>>pert.duracaoAlta;
            
        inputNomeArqP5>>pert.src_bytesBaixa;
        inputNomeArqP5>>pert.src_bytesMedia;
        inputNomeArqP5>>pert.src_bytesAlta;
            
        inputNomeArqP6>>pert.dst_bytesBaixa;
        inputNomeArqP6>>pert.dst_bytesMedia;
        inputNomeArqP6>>pert.dst_bytesAlta;
            
        inputNomeArqP8>>pert.wrong_fragmentBaixa;
        inputNomeArqP8>>pert.wrong_fragmentMedia;
        inputNomeArqP8>>pert.wrong_fragmentAlta;
        
        inputNomeArqP9>>pert.urgenteBaixa;
        inputNomeArqP9>>pert.urgenteMedia;
        inputNomeArqP9>>pert.urgenteAlta;
                            
        inputNomeArqP10>>pert.hotBaixa;
        inputNomeArqP10>>pert.hotMedia;
        inputNomeArqP10>>pert.hotAlta;
                                
        inputNomeArqP11>>pert.num_faleid_loginsBaixa;
        inputNomeArqP11>>pert.num_faleid_loginsMedia;
        inputNomeArqP11>>pert.num_faleid_loginsAlta;
                                    
        inputNomeArqP13>>pert.num_compromisedBaixa;
        inputNomeArqP13>>pert.num_compromisedMedia;
        inputNomeArqP13>>pert.num_compromisedAlta;
                                        
        inputNomeArqP16>>pert.num_rootBaixa;
        inputNomeArqP16>>pert.num_rootMedia;
        inputNomeArqP16>>pert.num_rootAlta;

        inputNomeArqP17>>pert.num_file_creatinosBaixa;
        inputNomeArqP17>>pert.num_file_creatinosMedia;
        inputNomeArqP17>>pert.num_file_creatinosAlta; 
                                                
        inputNomeArqP18>>pert.num_shellsBaixa;
        inputNomeArqP18>>pert.num_shellsMedia;
        inputNomeArqP18>>pert.num_shellsAlta;
                                                    
        inputNomeArqP19>>pert.num_access_filesBaixa;
        inputNomeArqP19>>pert.num_access_filesMedia;
        inputNomeArqP19>>pert.num_access_filesAlta;
            
        inputNomeArqP23>>pert.countBaixa;
        inputNomeArqP23>>pert.countMedia;
        inputNomeArqP23>>pert.countAlta;
            
        inputNomeArqP24>>pert.srv_countBaixa;
        inputNomeArqP24>>pert.srv_countMedia;
        inputNomeArqP24>>pert.srv_countAlta;
            
        inputNomeArqP25>>pert.serror_rateBaixa;
        inputNomeArqP25>>pert.serror_rateMedia;
        inputNomeArqP25>>pert.serror_rateAlta;
            
        inputNomeArqP26>>pert.srv_serror_rateBaixa;
        inputNomeArqP26>>pert.srv_serror_rateMedia;
        inputNomeArqP26>>pert.srv_serror_rateAlta;
            
        inputNomeArqP27>>pert.rerror_rateBaixa;
        inputNomeArqP27>>pert.rerror_rateMedia;
        inputNomeArqP27>>pert.rerror_rateAlta;
            
        inputNomeArqP28>>pert.srv_rerror_rateBaixa;
        inputNomeArqP28>>pert.srv_rerror_rateMedia;
        inputNomeArqP28>>pert.srv_rerror_rateAlta;
            
        inputNomeArqP29>>pert.same_srv_rateBaixa;
        inputNomeArqP29>>pert.same_srv_rateMedia;
        inputNomeArqP29>>pert.same_srv_rateAlta;
            
        inputNomeArqP30>>pert.diff_srv_rateBaixa;
        inputNomeArqP30>>pert.diff_srv_rateMedia;
        inputNomeArqP30>>pert.diff_srv_rateAlta;
            
        inputNomeArqP31>>pert.srv_diff_host_rateBaixa;
        inputNomeArqP31>>pert.srv_diff_host_rateMedia;
        inputNomeArqP31>>pert.srv_diff_host_rateAlta;
                        
        inputNomeArqP32>>pert.dst_host_countBaixa;
        inputNomeArqP32>>pert.dst_host_countMedia;
        inputNomeArqP32>>pert.dst_host_countAlta;
            
        inputNomeArqP33>>pert.dst_host_srv_countBaixa;
        inputNomeArqP33>>pert.dst_host_srv_countMedia;
        inputNomeArqP33>>pert.dst_host_srv_countAlta;
            
        inputNomeArqP34>>pert.dst_host_same_srv_rateBaixa;
        inputNomeArqP34>>pert.dst_host_same_srv_rateMedia;
        inputNomeArqP34>>pert.dst_host_same_srv_rateAlta;
            
        inputNomeArqP35>>pert.dst_host_diff_srv_rateBaixa;
        inputNomeArqP35>>pert.dst_host_diff_srv_rateMedia;
        inputNomeArqP35>>pert.dst_host_diff_srv_rateAlta;
            
        inputNomeArqP36>>pert.dst_host_same_src_port_rateBaixa;
        inputNomeArqP36>>pert.dst_host_same_src_port_rateMedia;
        inputNomeArqP36>>pert.dst_host_same_src_port_rateAlta;
            
        inputNomeArqP37>>pert.dst_host_srv_diff_host_rateBaixa;
        inputNomeArqP37>>pert.dst_host_srv_diff_host_rateMedia;
        inputNomeArqP37>>pert.dst_host_srv_diff_host_rateAlta;
            
        inputNomeArqP38>>pert.dst_host_serror_rateBaixa;
        inputNomeArqP38>>pert.dst_host_serror_rateMedia;
        inputNomeArqP38>>pert.dst_host_serror_rateAlta;
        
        inputNomeArqP39>>pert.dst_host_srv_serror_rateBaixa;
        inputNomeArqP39>>pert.dst_host_srv_serror_rateMedia;
        inputNomeArqP39>>pert.dst_host_srv_serror_rateAlta;
            
        inputNomeArqP40>>pert.dst_host_rerror_rateBaixa;
        inputNomeArqP40>>pert.dst_host_rerror_rateMedia;
        inputNomeArqP40>>pert.dst_host_rerror_rateAlta;
            
        inputNomeArqP41>>pert.dst_host_srv_rerror_rateBaixa;
        inputNomeArqP41>>pert.dst_host_srv_rerror_rateMedia;
        inputNomeArqP41>>pert.dst_host_srv_rerror_rateAlta;
            
        output<<"<"<<tab.duracao<<","<<pert.duracaoBaixa<<"> ";
        output<<"<"<<tab.duracao<<","<<pert.duracaoMedia<<"> ";
        output<<"<"<<tab.duracao<<","<<pert.duracaoAlta<<"> ";
        output<<"<"<<tab.tipo_protocolo<<",1> ";
        output<<"<"<<tab.servico<<",1> ";
        output<<"<"<<tab.flag<<",1> ";
        output<<"<"<<tab.src_bytes<<","<<pert.src_bytesBaixa<<"> ";
        output<<"<"<<tab.src_bytes<<","<<pert.src_bytesMedia<<"> ";
        output<<"<"<<tab.src_bytes<<","<<pert.src_bytesAlta<<"> ";
        output<<"<"<<tab.dst_bytes<<","<<pert.dst_bytesBaixa<<"> ";
        output<<"<"<<tab.dst_bytes<<","<<pert.dst_bytesMedia<<"> ";
        output<<"<"<<tab.dst_bytes<<","<<pert.dst_bytesAlta<<"> ";
        output<<"<"<<tab.land<<",1> ";
        output<<"<"<<tab.wrong_fragment<<","<<pert.wrong_fragmentBaixa<<"> ";
        output<<"<"<<tab.wrong_fragment<<","<<pert.wrong_fragmentMedia<<"> ";
        output<<"<"<<tab.wrong_fragment<<","<<pert.wrong_fragmentAlta<<"> ";
        output<<"<"<<tab.urgente<<","<<pert.urgenteBaixa<<"> ";
        output<<"<"<<tab.urgente<<","<<pert.urgenteMedia<<"> ";
        output<<"<"<<tab.urgente<<","<<pert.urgenteAlta<<"> ";
        output<<"<"<<tab.hot<<","<<pert.hotBaixa<<"> ";
        output<<"<"<<tab.hot<<","<<pert.hotMedia<<"> ";
        output<<"<"<<tab.hot<<","<<pert.hotAlta<<"> ";
        output<<"<"<<tab.num_faleid_logins<<","<<pert.num_faleid_loginsBaixa<<"> ";
        output<<"<"<<tab.num_faleid_logins<<","<<pert.num_faleid_loginsMedia<<"> ";
        output<<"<"<<tab.num_faleid_logins<<","<<pert.num_faleid_loginsAlta<<"> ";
        output<<"<"<<tab.logged_in<<",1> ";
        output<<"<"<<tab.num_compromised<<","<<pert.num_compromisedBaixa<<"> ";
        output<<"<"<<tab.num_compromised<<","<<pert.num_compromisedMedia<<"> ";
        output<<"<"<<tab.num_compromised<<","<<pert.num_compromisedAlta<<"> ";
        output<<"<"<<tab.root_shell<<",1> ";
        output<<"<"<<tab.su_attempted<<",1> ";
        output<<"<"<<tab.num_root<<","<<pert.num_rootBaixa<<"> ";
        output<<"<"<<tab.num_root<<","<<pert.num_rootMedia<<"> ";
        output<<"<"<<tab.num_root<<","<<pert.num_rootAlta<<"> ";
        output<<"<"<<tab.num_file_creatinos<<","<<pert.num_file_creatinosBaixa<<"> ";
        output<<"<"<<tab.num_file_creatinos<<","<<pert.num_file_creatinosMedia<<"> ";
        output<<"<"<<tab.num_file_creatinos<<","<<pert.num_file_creatinosAlta<<"> ";
        output<<"<"<<tab.num_shells<<","<<pert.num_shellsBaixa<<"> ";
        output<<"<"<<tab.num_shells<<","<<pert.num_shellsMedia<<"> ";
        output<<"<"<<tab.num_shells<<","<<pert.num_shellsAlta<<"> ";
        output<<"<"<<tab.num_access_files<<","<<pert.num_access_filesBaixa<<"> ";
        output<<"<"<<tab.num_access_files<<","<<pert.num_access_filesMedia<<"> ";
        output<<"<"<<tab.num_access_files<<","<<pert.num_access_filesAlta<<"> ";
        output<<"<"<<tab.num_outbound_cmds<<",1> ";
        output<<"<"<<tab.is_hot_login<<",1> ";
        output<<"<"<<tab.is_guest_login<<",1> ";
        output<<"<"<<tab.count<<","<<pert.countBaixa<<"> ";
        output<<"<"<<tab.count<<","<<pert.countMedia<<"> ";
        output<<"<"<<tab.count<<","<<pert.countAlta<<"> ";
        output<<"<"<<tab.srv_count<<","<<pert.srv_countBaixa<<"> ";
        output<<"<"<<tab.srv_count<<","<<pert.srv_countMedia<<"> ";
        output<<"<"<<tab.srv_count<<","<<pert.srv_countAlta<<"> ";
        output<<"<"<<tab.serror_rate<<","<<pert.serror_rateBaixa<<"> ";
        output<<"<"<<tab.serror_rate<<","<<pert.serror_rateMedia<<"> ";
        output<<"<"<<tab.serror_rate<<","<<pert.serror_rateAlta<<"> ";
        output<<"<"<<tab.srv_serror_rate<<","<<pert.srv_serror_rateBaixa<<"> ";
        output<<"<"<<tab.srv_serror_rate<<","<<pert.srv_serror_rateMedia<<"> ";
        output<<"<"<<tab.srv_serror_rate<<","<<pert.srv_serror_rateAlta<<"> ";
        output<<"<"<<tab.rerror_rate<<","<<pert.rerror_rateBaixa<<"> ";
        output<<"<"<<tab.rerror_rate<<","<<pert.rerror_rateMedia<<"> ";
        output<<"<"<<tab.rerror_rate<<","<<pert.rerror_rateAlta<<"> ";
        output<<"<"<<tab.srv_rerror_rate<<","<<pert.srv_rerror_rateBaixa<<"> ";
        output<<"<"<<tab.srv_rerror_rate<<","<<pert.srv_rerror_rateMedia<<"> ";
        output<<"<"<<tab.srv_rerror_rate<<","<<pert.srv_rerror_rateAlta<<"> ";
        output<<"<"<<tab.same_srv_rate<<","<<pert.same_srv_rateBaixa<<"> ";
        output<<"<"<<tab.same_srv_rate<<","<<pert.same_srv_rateMedia<<"> ";
        output<<"<"<<tab.same_srv_rate<<","<<pert.same_srv_rateAlta<<"> ";
        output<<"<"<<tab.diff_srv_rate<<","<<pert.diff_srv_rateBaixa<<"> ";
        output<<"<"<<tab.diff_srv_rate<<","<<pert.diff_srv_rateMedia<<"> ";
        output<<"<"<<tab.diff_srv_rate<<","<<pert.diff_srv_rateAlta<<"> ";
        output<<"<"<<tab.srv_diff_host_rate<<","<<pert.srv_diff_host_rateBaixa<<"> ";
        output<<"<"<<tab.srv_diff_host_rate<<","<<pert.srv_diff_host_rateMedia<<"> ";
        output<<"<"<<tab.srv_diff_host_rate<<","<<pert.srv_diff_host_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_count<<","<<pert.dst_host_countBaixa<<"> ";
        output<<"<"<<tab.dst_host_count<<","<<pert.dst_host_countMedia<<"> ";
        output<<"<"<<tab.dst_host_count<<","<<pert.dst_host_countAlta<<"> ";
        output<<"<"<<tab.dst_host_srv_count<<","<<pert.dst_host_srv_countBaixa<<"> ";
        output<<"<"<<tab.dst_host_srv_count<<","<<pert.dst_host_srv_countMedia<<"> ";
        output<<"<"<<tab.dst_host_srv_count<<","<<pert.dst_host_srv_countAlta<<"> ";
        output<<"<"<<tab.dst_host_same_srv_rate<<","<<pert.dst_host_same_srv_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_same_srv_rate<<","<<pert.dst_host_same_srv_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_same_srv_rate<<","<<pert.dst_host_same_srv_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_diff_srv_rate<<","<<pert.dst_host_diff_srv_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_diff_srv_rate<<","<<pert.dst_host_diff_srv_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_diff_srv_rate<<","<<pert.dst_host_diff_srv_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_same_src_port_rate<<","<<pert.dst_host_same_src_port_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_same_src_port_rate<<","<<pert.dst_host_same_src_port_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_same_src_port_rate<<","<<pert.dst_host_same_src_port_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_srv_diff_host_rate<<","<<pert.dst_host_srv_diff_host_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_srv_diff_host_rate<<","<<pert.dst_host_srv_diff_host_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_srv_diff_host_rate<<","<<pert.dst_host_srv_diff_host_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_serror_rate<<","<<pert.dst_host_serror_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_serror_rate<<","<<pert.dst_host_serror_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_serror_rate<<","<<pert.dst_host_serror_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_srv_serror_rate<<","<<pert.dst_host_srv_serror_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_srv_serror_rate<<","<<pert.dst_host_srv_serror_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_srv_serror_rate<<","<<pert.dst_host_srv_serror_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_rerror_rate<<","<<pert.dst_host_rerror_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_rerror_rate<<","<<pert.dst_host_rerror_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_rerror_rate<<","<<pert.dst_host_rerror_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_srv_rerror_rate<<","<<pert.dst_host_srv_rerror_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_srv_rerror_rate<<","<<pert.dst_host_srv_rerror_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_srv_rerror_rate<<","<<pert.dst_host_srv_rerror_rateAlta<<"> "<<endl;
    }
    //Fechando os arquivos
    inputNomeBase.close();
    output.close();
    inputNomeArqP1.close(), inputNomeArqP5.close(), inputNomeArqP6.close(), inputNomeArqP8.close(), inputNomeArqP9.close(), inputNomeArqP10.close(), inputNomeArqP11.close(), inputNomeArqP13.close();
    inputNomeArqP16.close(), inputNomeArqP17.close(), inputNomeArqP18.close(), inputNomeArqP19.close(), inputNomeArqP23.close(), inputNomeArqP24.close(), inputNomeArqP25.close(), inputNomeArqP26.close();
    inputNomeArqP27.close(), inputNomeArqP28.close(), inputNomeArqP29.close(), inputNomeArqP30.close(), inputNomeArqP31.close(), inputNomeArqP32.close(), inputNomeArqP33.close(), inputNomeArqP34.close();
    inputNomeArqP35.close(), inputNomeArqP36.close(), inputNomeArqP37.close(), inputNomeArqP38.close(), inputNomeArqP39.close(), inputNomeArqP40.close(), inputNomeArqP41.close();
    
    //Excluindo o arquivo original e renomeando o arquivo atualizado
    remove(nomeDaBase);
    rename("BaseItem", nomeDaBase);
   
}

void utilitarios::TransformaCaracteristicaDeteccaoEmItem(char nomeDaBase[100], vector<string> nomeArqPertinencia){
    
    Tabela tab;
    Pertinencia pert;
    string palavra;
    char nome[15];
    int valor;
    ifstream inputNomeBase;
    ifstream inputNomeArqP1, inputNomeArqP5, inputNomeArqP6, inputNomeArqP8, inputNomeArqP9, inputNomeArqP10, inputNomeArqP11, inputNomeArqP13;
    ifstream inputNomeArqP16, inputNomeArqP17, inputNomeArqP18, inputNomeArqP19, inputNomeArqP23, inputNomeArqP24, inputNomeArqP25, inputNomeArqP26;
    ifstream inputNomeArqP27, inputNomeArqP28, inputNomeArqP29, inputNomeArqP30, inputNomeArqP31, inputNomeArqP32, inputNomeArqP33, inputNomeArqP34;
    ifstream inputNomeArqP35, inputNomeArqP36, inputNomeArqP37, inputNomeArqP38, inputNomeArqP39, inputNomeArqP40, inputNomeArqP41;
    ofstream output("BaseItem");
    
        
    inputNomeBase.open(nomeDaBase, ifstream::in);
    
    palavra = nomeArqPertinencia.at(0);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP1.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(1);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP5.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(2);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP6.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(3);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP8.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(4);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP9.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(5);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP10.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(6);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP11.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(7);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP13.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(8);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP16.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(9);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP17.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(10);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP18.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(11);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP19.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(12);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP23.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(13);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP24.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(14);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP25.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(15);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP26.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(16);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP27.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(17);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP28.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(18);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP29.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(19);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP30.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(20);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP31.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(21);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP32.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(22);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP33.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(23);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP34.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(24);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP35.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(25);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP36.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(26);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP37.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(27);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP38.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(28);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP39.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(29);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP40.open(nome, ifstream::in);
    
    palavra = nomeArqPertinencia.at(30);
    std::strcpy(nome, palavra.c_str());
    inputNomeArqP41.open(nome, ifstream::in);
    
    //Tratamento de erro caso os arquivos não existam
    if(!inputNomeBase.is_open()){
        printf("Erro na abertura dos arquivos de base original!");
        inputNomeBase.clear();
        exit(1);
    }
    
    if((!inputNomeArqP1.is_open())||(!inputNomeArqP5.is_open())||(!inputNomeArqP6.is_open())||(!inputNomeArqP8.is_open())||(!inputNomeArqP9.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP1.clear();
        inputNomeArqP5.clear();
        inputNomeArqP6.clear();
        inputNomeArqP8.clear();
        inputNomeArqP9.clear();
        exit(1);
    }
    
    if((!inputNomeArqP10.is_open())||(!inputNomeArqP11.is_open())||(!inputNomeArqP13.is_open())||(!inputNomeArqP16.is_open())||(!inputNomeArqP17.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP10.clear();
        inputNomeArqP11.clear();
        inputNomeArqP13.clear();
        inputNomeArqP16.clear();
        inputNomeArqP17.clear();
        exit(1);
    }
    
    if((!inputNomeArqP18.is_open())||(!inputNomeArqP19.is_open())||(!inputNomeArqP23.is_open())||(!inputNomeArqP24.is_open())||(!inputNomeArqP25.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP18.clear();
        inputNomeArqP19.clear();
        inputNomeArqP23.clear();
        inputNomeArqP24.clear();
        inputNomeArqP25.clear();
        exit(1);
    }
    
    if((!inputNomeArqP26.is_open())||(!inputNomeArqP27.is_open())||(!inputNomeArqP28.is_open())||(!inputNomeArqP29.is_open())||(!inputNomeArqP30.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP26.clear();
        inputNomeArqP27.clear();
        inputNomeArqP28.clear();
        inputNomeArqP29.clear();
        inputNomeArqP30.clear();
        exit(1);
    }
    
    if((!inputNomeArqP31.is_open())||(!inputNomeArqP32.is_open())||(!inputNomeArqP33.is_open())||(!inputNomeArqP34.is_open())||(!inputNomeArqP35.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP31.clear();
        inputNomeArqP32.clear();
        inputNomeArqP33.clear();
        inputNomeArqP34.clear();
        inputNomeArqP35.clear();
        exit(1);
    }
    
    if((!inputNomeArqP36.is_open())||(!inputNomeArqP37.is_open())||(!inputNomeArqP38.is_open())||(!inputNomeArqP39.is_open())||(!inputNomeArqP40.is_open())||(!inputNomeArqP41.is_open())){
        printf("Erro na abertura dos arquivos de pertinencia!");
        inputNomeArqP36.clear();
        inputNomeArqP37.clear();
        inputNomeArqP38.clear();
        inputNomeArqP39.clear();
        inputNomeArqP40.clear();
        inputNomeArqP41.clear();
        exit(1);
    }
    
    //Tratamento de erro para o arquivo de saída
    if((!output.is_open())){
        printf("Erro na abertura do arquivo de saída!");
        output.clear();
        exit(1);
    }
    
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(inputNomeBase.good()){
        
        inputNomeBase>>tab.duracao;
        inputNomeBase>>tab.tipo_protocolo;
        inputNomeBase>>tab.servico;
        inputNomeBase>>tab.flag;
        inputNomeBase>>tab.src_bytes;
        inputNomeBase>>tab.dst_bytes;
        inputNomeBase>>tab.land;
        inputNomeBase>>tab.wrong_fragment;
        inputNomeBase>>tab.urgente;
        inputNomeBase>>tab.hot;
        inputNomeBase>>tab.num_faleid_logins;
        inputNomeBase>>tab.logged_in;
        inputNomeBase>>tab.num_compromised;
        inputNomeBase>>tab.root_shell;
        inputNomeBase>>tab.su_attempted;
        inputNomeBase>>tab.num_root;
        inputNomeBase>>tab.num_file_creatinos;
        inputNomeBase>>tab.num_shells;
        inputNomeBase>>tab.num_access_files;
        inputNomeBase>>tab.num_outbound_cmds;
        inputNomeBase>>tab.is_hot_login;
        inputNomeBase>>tab.is_guest_login;
        inputNomeBase>>tab.count;
        inputNomeBase>>tab.srv_count;
        inputNomeBase>>tab.serror_rate;
        inputNomeBase>>tab.srv_serror_rate;
        inputNomeBase>>tab.rerror_rate;
        inputNomeBase>>tab.srv_rerror_rate;
        inputNomeBase>>tab.same_srv_rate;
        inputNomeBase>>tab.diff_srv_rate;
        inputNomeBase>>tab.srv_diff_host_rate;
        inputNomeBase>>tab.dst_host_count;
        inputNomeBase>>tab.dst_host_srv_count;
        inputNomeBase>>tab.dst_host_same_srv_rate;
        inputNomeBase>>tab.dst_host_diff_srv_rate;
        inputNomeBase>>tab.dst_host_same_src_port_rate;
        inputNomeBase>>tab.dst_host_srv_diff_host_rate;
        inputNomeBase>>tab.dst_host_serror_rate;
        inputNomeBase>>tab.dst_host_srv_serror_rate;
        inputNomeBase>>tab.dst_host_rerror_rate;
        inputNomeBase>>tab.dst_host_srv_rerror_rate;
                
        inputNomeArqP1>>pert.duracaoBaixa;
        inputNomeArqP1>>pert.duracaoMedia;
        inputNomeArqP1>>pert.duracaoAlta;
            
        inputNomeArqP5>>pert.src_bytesBaixa;
        inputNomeArqP5>>pert.src_bytesMedia;
        inputNomeArqP5>>pert.src_bytesAlta;
            
        inputNomeArqP6>>pert.dst_bytesBaixa;
        inputNomeArqP6>>pert.dst_bytesMedia;
        inputNomeArqP6>>pert.dst_bytesAlta;
            
        inputNomeArqP8>>pert.wrong_fragmentBaixa;
        inputNomeArqP8>>pert.wrong_fragmentMedia;
        inputNomeArqP8>>pert.wrong_fragmentAlta;
        
        inputNomeArqP9>>pert.urgenteBaixa;
        inputNomeArqP9>>pert.urgenteMedia;
        inputNomeArqP9>>pert.urgenteAlta;
                            
        inputNomeArqP10>>pert.hotBaixa;
        inputNomeArqP10>>pert.hotMedia;
        inputNomeArqP10>>pert.hotAlta;
                                
        inputNomeArqP11>>pert.num_faleid_loginsBaixa;
        inputNomeArqP11>>pert.num_faleid_loginsMedia;
        inputNomeArqP11>>pert.num_faleid_loginsAlta;
                                    
        inputNomeArqP13>>pert.num_compromisedBaixa;
        inputNomeArqP13>>pert.num_compromisedMedia;
        inputNomeArqP13>>pert.num_compromisedAlta;
                                        
        inputNomeArqP16>>pert.num_rootBaixa;
        inputNomeArqP16>>pert.num_rootMedia;
        inputNomeArqP16>>pert.num_rootAlta;

        inputNomeArqP17>>pert.num_file_creatinosBaixa;
        inputNomeArqP17>>pert.num_file_creatinosMedia;
        inputNomeArqP17>>pert.num_file_creatinosAlta; 
                                                
        inputNomeArqP18>>pert.num_shellsBaixa;
        inputNomeArqP18>>pert.num_shellsMedia;
        inputNomeArqP18>>pert.num_shellsAlta;
                                                    
        inputNomeArqP19>>pert.num_access_filesBaixa;
        inputNomeArqP19>>pert.num_access_filesMedia;
        inputNomeArqP19>>pert.num_access_filesAlta;
            
        inputNomeArqP23>>pert.countBaixa;
        inputNomeArqP23>>pert.countMedia;
        inputNomeArqP23>>pert.countAlta;
            
        inputNomeArqP24>>pert.srv_countBaixa;
        inputNomeArqP24>>pert.srv_countMedia;
        inputNomeArqP24>>pert.srv_countAlta;
            
        inputNomeArqP25>>pert.serror_rateBaixa;
        inputNomeArqP25>>pert.serror_rateMedia;
        inputNomeArqP25>>pert.serror_rateAlta;
            
        inputNomeArqP26>>pert.srv_serror_rateBaixa;
        inputNomeArqP26>>pert.srv_serror_rateMedia;
        inputNomeArqP26>>pert.srv_serror_rateAlta;
            
        inputNomeArqP27>>pert.rerror_rateBaixa;
        inputNomeArqP27>>pert.rerror_rateMedia;
        inputNomeArqP27>>pert.rerror_rateAlta;
            
        inputNomeArqP28>>pert.srv_rerror_rateBaixa;
        inputNomeArqP28>>pert.srv_rerror_rateMedia;
        inputNomeArqP28>>pert.srv_rerror_rateAlta;
            
        inputNomeArqP29>>pert.same_srv_rateBaixa;
        inputNomeArqP29>>pert.same_srv_rateMedia;
        inputNomeArqP29>>pert.same_srv_rateAlta;
            
        inputNomeArqP30>>pert.diff_srv_rateBaixa;
        inputNomeArqP30>>pert.diff_srv_rateMedia;
        inputNomeArqP30>>pert.diff_srv_rateAlta;
            
        inputNomeArqP31>>pert.srv_diff_host_rateBaixa;
        inputNomeArqP31>>pert.srv_diff_host_rateMedia;
        inputNomeArqP31>>pert.srv_diff_host_rateAlta;
                        
        inputNomeArqP32>>pert.dst_host_countBaixa;
        inputNomeArqP32>>pert.dst_host_countMedia;
        inputNomeArqP32>>pert.dst_host_countAlta;
            
        inputNomeArqP33>>pert.dst_host_srv_countBaixa;
        inputNomeArqP33>>pert.dst_host_srv_countMedia;
        inputNomeArqP33>>pert.dst_host_srv_countAlta;
            
        inputNomeArqP34>>pert.dst_host_same_srv_rateBaixa;
        inputNomeArqP34>>pert.dst_host_same_srv_rateMedia;
        inputNomeArqP34>>pert.dst_host_same_srv_rateAlta;
            
        inputNomeArqP35>>pert.dst_host_diff_srv_rateBaixa;
        inputNomeArqP35>>pert.dst_host_diff_srv_rateMedia;
        inputNomeArqP35>>pert.dst_host_diff_srv_rateAlta;
            
        inputNomeArqP36>>pert.dst_host_same_src_port_rateBaixa;
        inputNomeArqP36>>pert.dst_host_same_src_port_rateMedia;
        inputNomeArqP36>>pert.dst_host_same_src_port_rateAlta;
            
        inputNomeArqP37>>pert.dst_host_srv_diff_host_rateBaixa;
        inputNomeArqP37>>pert.dst_host_srv_diff_host_rateMedia;
        inputNomeArqP37>>pert.dst_host_srv_diff_host_rateAlta;
            
        inputNomeArqP38>>pert.dst_host_serror_rateBaixa;
        inputNomeArqP38>>pert.dst_host_serror_rateMedia;
        inputNomeArqP38>>pert.dst_host_serror_rateAlta;
        
        inputNomeArqP39>>pert.dst_host_srv_serror_rateBaixa;
        inputNomeArqP39>>pert.dst_host_srv_serror_rateMedia;
        inputNomeArqP39>>pert.dst_host_srv_serror_rateAlta;
            
        inputNomeArqP40>>pert.dst_host_rerror_rateBaixa;
        inputNomeArqP40>>pert.dst_host_rerror_rateMedia;
        inputNomeArqP40>>pert.dst_host_rerror_rateAlta;
            
        inputNomeArqP41>>pert.dst_host_srv_rerror_rateBaixa;
        inputNomeArqP41>>pert.dst_host_srv_rerror_rateMedia;
        inputNomeArqP41>>pert.dst_host_srv_rerror_rateAlta;
        
        
        /*
         * A forma de gerar novo arquivo depende se o processamento é treinamento 
         * ou detecção.
         */
        
        if(inputNomeBase.eof()) break;
        
        output<<"<"<<tab.duracao<<","<<pert.duracaoBaixa<<"> ";
        output<<"<"<<tab.duracao<<","<<pert.duracaoMedia<<"> ";
        output<<"<"<<tab.duracao<<","<<pert.duracaoAlta<<"> ";
        output<<"<tipo_protocolo"<<","<<tab.tipo_protocolo<<"> ";
        output<<"<servico"<<","<<tab.servico<<"> ";
        output<<"<flag"<<","<<tab.flag<<"> ";
        output<<"<"<<tab.src_bytes<<","<<pert.src_bytesBaixa<<"> ";
        output<<"<"<<tab.src_bytes<<","<<pert.src_bytesMedia<<"> ";
        output<<"<"<<tab.src_bytes<<","<<pert.src_bytesAlta<<"> ";
        output<<"<"<<tab.dst_bytes<<","<<pert.dst_bytesBaixa<<"> ";
        output<<"<"<<tab.dst_bytes<<","<<pert.dst_bytesMedia<<"> ";
        output<<"<"<<tab.dst_bytes<<","<<pert.dst_bytesAlta<<"> ";
        output<<"<land"<<","<<tab.land<<"> ";
        output<<"<"<<tab.wrong_fragment<<","<<pert.wrong_fragmentBaixa<<"> ";
        output<<"<"<<tab.wrong_fragment<<","<<pert.wrong_fragmentMedia<<"> ";
        output<<"<"<<tab.wrong_fragment<<","<<pert.wrong_fragmentAlta<<"> ";
        output<<"<"<<tab.urgente<<","<<pert.urgenteBaixa<<"> ";
        output<<"<"<<tab.urgente<<","<<pert.urgenteMedia<<"> ";
        output<<"<"<<tab.urgente<<","<<pert.urgenteAlta<<"> ";
        output<<"<"<<tab.hot<<","<<pert.hotBaixa<<"> ";
        output<<"<"<<tab.hot<<","<<pert.hotMedia<<"> ";
        output<<"<"<<tab.hot<<","<<pert.hotAlta<<"> ";
        output<<"<"<<tab.num_faleid_logins<<","<<pert.num_faleid_loginsBaixa<<"> ";
        output<<"<"<<tab.num_faleid_logins<<","<<pert.num_faleid_loginsMedia<<"> ";
        output<<"<"<<tab.num_faleid_logins<<","<<pert.num_faleid_loginsAlta<<"> ";
        output<<"<logged_in"<<","<<tab.logged_in<<"> ";
        output<<"<"<<tab.num_compromised<<","<<pert.num_compromisedBaixa<<"> ";
        output<<"<"<<tab.num_compromised<<","<<pert.num_compromisedMedia<<"> ";
        output<<"<"<<tab.num_compromised<<","<<pert.num_compromisedAlta<<"> ";
        output<<"<root_shell"<<","<<tab.root_shell<<"> ";
        output<<"<su_attempted"<<","<<tab.su_attempted<<"> ";
        output<<"<"<<tab.num_root<<","<<pert.num_rootBaixa<<"> ";
        output<<"<"<<tab.num_root<<","<<pert.num_rootMedia<<"> ";
        output<<"<"<<tab.num_root<<","<<pert.num_rootAlta<<"> ";
        output<<"<"<<tab.num_file_creatinos<<","<<pert.num_file_creatinosBaixa<<"> ";
        output<<"<"<<tab.num_file_creatinos<<","<<pert.num_file_creatinosMedia<<"> ";
        output<<"<"<<tab.num_file_creatinos<<","<<pert.num_file_creatinosAlta<<"> ";
        output<<"<"<<tab.num_shells<<","<<pert.num_shellsBaixa<<"> ";
        output<<"<"<<tab.num_shells<<","<<pert.num_shellsMedia<<"> ";
        output<<"<"<<tab.num_shells<<","<<pert.num_shellsAlta<<"> ";
        output<<"<"<<tab.num_access_files<<","<<pert.num_access_filesBaixa<<"> ";
        output<<"<"<<tab.num_access_files<<","<<pert.num_access_filesMedia<<"> ";
        output<<"<"<<tab.num_access_files<<","<<pert.num_access_filesAlta<<"> ";
        output<<"<num_outbound_cmds"<<","<<tab.num_outbound_cmds<<"> ";
        output<<"<is_hot_login"<<","<<tab.is_hot_login<<"> ";
        output<<"<is_guest_login"<<","<<tab.is_guest_login<<"> ";
        output<<"<"<<tab.count<<","<<pert.countBaixa<<"> ";
        output<<"<"<<tab.count<<","<<pert.countMedia<<"> ";
        output<<"<"<<tab.count<<","<<pert.countAlta<<"> ";
        output<<"<"<<tab.srv_count<<","<<pert.srv_countBaixa<<"> ";
        output<<"<"<<tab.srv_count<<","<<pert.srv_countMedia<<"> ";
        output<<"<"<<tab.srv_count<<","<<pert.srv_countAlta<<"> ";
        output<<"<"<<tab.serror_rate<<","<<pert.serror_rateBaixa<<"> ";
        output<<"<"<<tab.serror_rate<<","<<pert.serror_rateMedia<<"> ";
        output<<"<"<<tab.serror_rate<<","<<pert.serror_rateAlta<<"> ";
        output<<"<"<<tab.srv_serror_rate<<","<<pert.srv_serror_rateBaixa<<"> ";
        output<<"<"<<tab.srv_serror_rate<<","<<pert.srv_serror_rateMedia<<"> ";
        output<<"<"<<tab.srv_serror_rate<<","<<pert.srv_serror_rateAlta<<"> ";
        output<<"<"<<tab.rerror_rate<<","<<pert.rerror_rateBaixa<<"> ";
        output<<"<"<<tab.rerror_rate<<","<<pert.rerror_rateMedia<<"> ";
        output<<"<"<<tab.rerror_rate<<","<<pert.rerror_rateAlta<<"> ";
        output<<"<"<<tab.srv_rerror_rate<<","<<pert.srv_rerror_rateBaixa<<"> ";
        output<<"<"<<tab.srv_rerror_rate<<","<<pert.srv_rerror_rateMedia<<"> ";
        output<<"<"<<tab.srv_rerror_rate<<","<<pert.srv_rerror_rateAlta<<"> ";
        output<<"<"<<tab.same_srv_rate<<","<<pert.same_srv_rateBaixa<<"> ";
        output<<"<"<<tab.same_srv_rate<<","<<pert.same_srv_rateMedia<<"> ";
        output<<"<"<<tab.same_srv_rate<<","<<pert.same_srv_rateAlta<<"> ";
        output<<"<"<<tab.diff_srv_rate<<","<<pert.diff_srv_rateBaixa<<"> ";
        output<<"<"<<tab.diff_srv_rate<<","<<pert.diff_srv_rateMedia<<"> ";
        output<<"<"<<tab.diff_srv_rate<<","<<pert.diff_srv_rateAlta<<"> ";
        output<<"<"<<tab.srv_diff_host_rate<<","<<pert.srv_diff_host_rateBaixa<<"> ";
        output<<"<"<<tab.srv_diff_host_rate<<","<<pert.srv_diff_host_rateMedia<<"> ";
        output<<"<"<<tab.srv_diff_host_rate<<","<<pert.srv_diff_host_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_count<<","<<pert.dst_host_countBaixa<<"> ";
        output<<"<"<<tab.dst_host_count<<","<<pert.dst_host_countMedia<<"> ";
        output<<"<"<<tab.dst_host_count<<","<<pert.dst_host_countAlta<<"> ";
        output<<"<"<<tab.dst_host_srv_count<<","<<pert.dst_host_srv_countBaixa<<"> ";
        output<<"<"<<tab.dst_host_srv_count<<","<<pert.dst_host_srv_countMedia<<"> ";
        output<<"<"<<tab.dst_host_srv_count<<","<<pert.dst_host_srv_countAlta<<"> ";
        output<<"<"<<tab.dst_host_same_srv_rate<<","<<pert.dst_host_same_srv_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_same_srv_rate<<","<<pert.dst_host_same_srv_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_same_srv_rate<<","<<pert.dst_host_same_srv_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_diff_srv_rate<<","<<pert.dst_host_diff_srv_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_diff_srv_rate<<","<<pert.dst_host_diff_srv_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_diff_srv_rate<<","<<pert.dst_host_diff_srv_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_same_src_port_rate<<","<<pert.dst_host_same_src_port_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_same_src_port_rate<<","<<pert.dst_host_same_src_port_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_same_src_port_rate<<","<<pert.dst_host_same_src_port_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_srv_diff_host_rate<<","<<pert.dst_host_srv_diff_host_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_srv_diff_host_rate<<","<<pert.dst_host_srv_diff_host_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_srv_diff_host_rate<<","<<pert.dst_host_srv_diff_host_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_serror_rate<<","<<pert.dst_host_serror_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_serror_rate<<","<<pert.dst_host_serror_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_serror_rate<<","<<pert.dst_host_serror_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_srv_serror_rate<<","<<pert.dst_host_srv_serror_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_srv_serror_rate<<","<<pert.dst_host_srv_serror_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_srv_serror_rate<<","<<pert.dst_host_srv_serror_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_rerror_rate<<","<<pert.dst_host_rerror_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_rerror_rate<<","<<pert.dst_host_rerror_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_rerror_rate<<","<<pert.dst_host_rerror_rateAlta<<"> ";
        output<<"<"<<tab.dst_host_srv_rerror_rate<<","<<pert.dst_host_srv_rerror_rateBaixa<<"> ";
        output<<"<"<<tab.dst_host_srv_rerror_rate<<","<<pert.dst_host_srv_rerror_rateMedia<<"> ";
        output<<"<"<<tab.dst_host_srv_rerror_rate<<","<<pert.dst_host_srv_rerror_rateAlta<<">"<<endl;
        
    }
    //Fechando os arquivos
    inputNomeBase.close();
    output.close();
    inputNomeArqP1.close(), inputNomeArqP5.close(), inputNomeArqP6.close(), inputNomeArqP8.close(), inputNomeArqP9.close(), inputNomeArqP10.close(), inputNomeArqP11.close(), inputNomeArqP13.close();
    inputNomeArqP16.close(), inputNomeArqP17.close(), inputNomeArqP18.close(), inputNomeArqP19.close(), inputNomeArqP23.close(), inputNomeArqP24.close(), inputNomeArqP25.close(), inputNomeArqP26.close();
    inputNomeArqP27.close(), inputNomeArqP28.close(), inputNomeArqP29.close(), inputNomeArqP30.close(), inputNomeArqP31.close(), inputNomeArqP32.close(), inputNomeArqP33.close(), inputNomeArqP34.close();
    inputNomeArqP35.close(), inputNomeArqP36.close(), inputNomeArqP37.close(), inputNomeArqP38.close(), inputNomeArqP39.close(), inputNomeArqP40.close(), inputNomeArqP41.close();
    
    //Excluindo o arquivo original e renomeando o arquivo atualizado
    remove(nomeDaBase);
    rename("BaseItem", nomeDaBase);
   
}

utilitarios::Transacao utilitarios::GeraStruturaTransacaoItens(char nomeDaBaseOriginal[50]){
    
    Transacao t;
    ifstream inputNomeBase;
    
    inputNomeBase.open(nomeDaBaseOriginal, ifstream::in);
     
    //Tratamento de erro caso os arquivos não existam
    if(!inputNomeBase.is_open()){
        printf("Erro na abertura dos arquivos!");
        inputNomeBase.clear();
        exit(1);
    }
    
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(!inputNomeBase.eof()){
        
        //Alimentando a estrutura de Transação
        
        string dur;
        inputNomeBase>>dur;
        t.duracao.push_back(dur);
        string prot;
        inputNomeBase>>prot;
        t.protocolo.push_back(prot);
        string serv;
        inputNomeBase>>serv;
        t.servico.push_back(serv);
        string fla;
        inputNomeBase>>fla;
        t.flag.push_back(fla);
        string src;
        inputNomeBase>>src;
        t.src_bytes.push_back(src);
        string dst;
        inputNomeBase>>dst;
        t.dst_bytes.push_back(dst);
        string la;
        inputNomeBase>>la;
        t.land.push_back(la);
        string wrof;
        inputNomeBase>>wrof;
        t.wrong_fragment.push_back(wrof);
        string urg;
        inputNomeBase>>urg;
        t.urgente.push_back(urg);
        string h;
        inputNomeBase>>h;
        t.hot.push_back(h);
        string numFL;
        inputNomeBase>>numFL;
        t.num_faleid_logins.push_back(numFL);
        string logIn;
        inputNomeBase>>logIn;
        t.logged_in.push_back(logIn);
        string numC;
        inputNomeBase>>numC;
        t.num_compromised.push_back(numC);
        string rShell;
        inputNomeBase>>rShell;
        t.root_shell.push_back(rShell);
        string su;
        inputNomeBase>>su;
        t.su_attempted.push_back(su);
        string nRoot;
        inputNomeBase>>nRoot;
        t.num_root.push_back(nRoot);
        string nFC;
        inputNomeBase>>nFC;
        t.num_file_creatinos.push_back(nFC);
        string nShells;
        inputNomeBase>>nShells;
        t.num_shells.push_back(nShells);
        string nAF;
        inputNomeBase>>nAF;
        t.num_access_files.push_back(nAF);
        string nOut;
        inputNomeBase>>nOut;
        t.num_outbound_cmds.push_back(nOut);
        string hotL;
        inputNomeBase>>hotL;
        t.is_hot_login.push_back(hotL);
        string guestL;
        inputNomeBase>>guestL;
        t.is_guest_login.push_back(guestL);
        string cou;
        inputNomeBase>>cou;
        t.count.push_back(cou);
        string srvC;
        inputNomeBase>>srvC;
        t.srv_count.push_back(srvC);
        string sRate;
        inputNomeBase>>sRate;
        t.serror_rate.push_back(sRate);
        string srvSR;
        inputNomeBase>>srvSR;
        t.srv_serror_rate.push_back(srvSR);
        string rRate;
        inputNomeBase>>rRate;
        t.rerror_rate.push_back(rRate);
        string srvRR;
        inputNomeBase>>srvRR;
        t.srv_rerror_rate.push_back(srvRR);
        string sameSR;
        inputNomeBase>>sameSR;
        t.same_srv_rate.push_back(sameSR);
        string diffSR;
        inputNomeBase>>diffSR;
        t.diff_srv_rate.push_back(diffSR);
        string srvDHR;
        inputNomeBase>>srvDHR;
        t.srv_diff_host_rate.push_back(srvDHR);
        string dstHC;
        inputNomeBase>>dstHC;
        t.dst_host_count.push_back(dstHC);
        string dstHSC;
        inputNomeBase>>dstHSC;
        t.dst_host_srv_count.push_back(dstHSC);
        string dstHSameSR;
        inputNomeBase>>dstHSameSR;
        t.dst_host_same_srv_rate.push_back(dstHSameSR);
        string dstHDSR;
        inputNomeBase>>dstHDSR;
        t.dst_host_diff_srv_rate.push_back(dstHDSR);
        string dstHSSPR;
        inputNomeBase>>dstHSSPR;
        t.dst_host_same_src_port_rate.push_back(dstHSSPR);
        string dstHSDHR;
        inputNomeBase>>dstHSDHR;
        t.dst_host_srv_diff_host_rate.push_back(dstHSDHR);
        string dstHSR;
        inputNomeBase>>dstHSR;
        t.dst_host_serror_rate.push_back(dstHSR);
        string dstHSSR;
        inputNomeBase>>dstHSSR;
        t.dst_host_srv_serror_rate.push_back(dstHSSR);
        string dstHRR;
        inputNomeBase>>dstHRR;
        t.dst_host_rerror_rate.push_back(dstHRR);
        string dstHSRR;
        inputNomeBase>>dstHSRR;
        t.dst_host_srv_rerror_rate.push_back(dstHSRR);
        /*
        string et;
        inputNomeBase>>et;
        t.etiqueta.push_back(et);
        */
    }
    //Fechando os arquivos
    inputNomeBase.close();
    
    return t;
}

vector<vector<double> > utilitarios::GeraMatrizPertinencia(char nomeDoArqPertinencia[50]){
    
    vector<double> alto;
    vector<double> medio;
    vector<double> baixo;
    int tam, contaLido=0;
    double vAlto, vMedio,vBaixo;
    
    ifstream inputNomeBase;
    
    inputNomeBase.open(nomeDoArqPertinencia, ifstream::in);
     
    //Tratamento de erro caso os arquivos não existam
    if(!inputNomeBase.is_open()){
        printf("Erro na abertura dos arquivos de pertinência!");
        inputNomeBase.clear();
        exit(1);
    }
        
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(!inputNomeBase.eof()){
        
        //Alimentando a estrutura de Transação
        inputNomeBase>>vBaixo;
        baixo.push_back(vBaixo);
        inputNomeBase>>vMedio;
        medio.push_back(vMedio);
        inputNomeBase>>vAlto;
        alto.push_back(vAlto);
        contaLido++;
    }
    //Fechando os arquivos
    inputNomeBase.close();
    /*    
    //Deletando a linha duplicada
    //Até corrigir o erro de leitura
    baixo.pop_back();
    medio.pop_back();
    alto.pop_back();
      */ 
    //Inicializando a matriz de pertinencia
    tam = alto.size();
    vector< vector<double> > mPertinencia(tam, vector<double>(3,0));
    
    for(int i=0; i<tam;i++){
        mPertinencia[i][0]= baixo[i];
        mPertinencia[i][1]= medio[i];
        mPertinencia[i][2]= alto[i];
    }
        
    return mPertinencia;
}

