/* 
 * File:   IndAssReFuzzy.cpp
 * Author: allinesf
 * me 2015, 10:15
 */

#include "IndAssReFuzzy.h"
#include "utilitarios.h"
#include <vector>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h> 
#include <sstream>
#include <algorithm>
using namespace std;

IndAssReFuzzy::IndAssReFuzzy() {}

IndAssReFuzzy::~IndAssReFuzzy() {
}

vector<string> IndAssReFuzzy::AtributoConjSelecao(vector<string> itensSubconjunto){
    
    vector<string> item;
    string palavra1, letra;
    int cont=0;
    
    
    while(cont != itensSubconjunto.size()){
        
        palavra1 = itensSubconjunto.at(cont);
        
        for(int jj=1;jj<palavra1.size();jj++)
        {
            //O valor 44 representa o valor decimal da vírgula
            if(palavra1.at(jj)!= 44){
                letra.push_back(palavra1.at(jj));
            }else
               break;
        }
        item.push_back(letra);
        letra.clear();
        cont++;                
    }
    return item;
    
}

vector<double> IndAssReFuzzy::PertinenciaConjSelecao(vector<string> itensDoSubconjunto){
    
    vector<double> pertinencia;
    
    string palavra1, letraC;
    double valor;
    int cont=0;
    
           
    while(cont != itensDoSubconjunto.size()){
        
        palavra1 = itensDoSubconjunto.at(cont);
        
        for(int jj=0;jj<palavra1.size();jj++)
        {
            if(palavra1.at(jj) == 44){
                for(int j=jj+1;j<palavra1.size()-1;j++){
                    letraC.push_back(palavra1.at(j));
                }
                stringstream converte(letraC);
                converte >> valor;
                pertinencia.push_back(valor);
                letraC.clear();
                
            }
        }
                        
        cont++;                
    }
    return pertinencia;
    
}

vector <string> IndAssReFuzzy::DecifraItemDoSubconjunto(vector<string> v1, vector<int> subconjuntoS){
    
    vector<string> itemSelecionado;
    
    //O primeiro elemento da linha representa o atributo que liga com os demais
    //itemSelecionado.push_back(v1.at(indiceLinhanoHE));
        
    //Os próximos elementos do vetor, representa os atributos que são ligados ao primeiro
    for(int j=0;j<v1.size(); j++){
        if(subconjuntoS.at(j) != 0){
            itemSelecionado.push_back(v1.at(j));
        }
    }

    return itemSelecionado;
}

vector <string> IndAssReFuzzy::AlimentaVetoresAtributos(){
    vector<string> I;
    
    /*Inicializando o cojunto de atributos
     * Cada atributo ik é associado a um conjunto Fuzzy
     */
    I.push_back("duracao");
    I.push_back("tipo_protocolo");
    I.push_back("servico");
    I.push_back("flag");
    I.push_back("src_bytes");
    I.push_back("dst_bytes");
    I.push_back("land");
    I.push_back("wrong_fragment");
    I.push_back("urgente");
    I.push_back("hot");
    I.push_back("num_faleid_logins");
    I.push_back("logged_in");
    I.push_back("num_compromised");
    I.push_back("root_shell");
    I.push_back("su_attempted");
    I.push_back("num_root");
    I.push_back("num_file_creatinos");
    I.push_back("num_shells");
    I.push_back("num_access_files");
    I.push_back("num_outbound_cmds");
    I.push_back("is_hot_login");
    I.push_back("is_guest_login");
    I.push_back("count");
    I.push_back("srv_count");
    I.push_back("serror_rate");
    I.push_back("srv_serror_rate");
    I.push_back("rerror_rate");
    I.push_back("srv_rerror_rate");
    I.push_back("same_srv_rate");
    I.push_back("diff_srv_rate");
    I.push_back("srv_diff_host_rate");
    I.push_back("dst_host_count");
    I.push_back("dst_host_srv_count");
    I.push_back("dst_host_same_srv_rate");
    I.push_back("dst_host_diff_srv_rate");
    I.push_back("dst_host_same_src_port_rate");
    I.push_back("dst_host_srv_diff_host_rate");
    I.push_back("dst_host_serror_rate");
    I.push_back("dst_host_srv_serror_rate");
    I.push_back("dst_host_rerror_rate");
    I.push_back("dst_host_srv_rerror_rate");
    
    return I;
}

vector <string> IndAssReFuzzy::AlimentaVetoresRegrasLinguisticas(){
    
    vector<string> F_i;
    
    /* Inicializando o conjunto de regras Fuzzy 
     * As funções de pertinencia correspondem ao conjunto Fuzzy
     */
    F_i.push_back("Baixo");
    F_i.push_back("Medio");
    F_i.push_back("Alto");
    
    return F_i;
    
}

vector<string> IndAssReFuzzy::GeraCabecalho(vector<string> Fx_i, vector<string> atributoI, double pertinenciaDoSub, int &colunaPert, vector<string> valoresAtributosSubConj, vector<int> &indiceEleSubConj, int classe, int indiceParaValorAtributo){
    
    vector<string> cabecalho;
    string atributo, regraF;
    int incideDaPertinencia, valorIndice;
        
    /*
     * Montando o cabeçalho da regra de acordo com os valores das tabelas de 
     * pertinencia do subconjunto. 
     * Para guardar a localização da pertinência nas três colunas do arquivo de pertinência, será necessário
     * primeiramente, verificar qual coluna se refere aquele arquivo. Para isso verificamos pelo íncide
     * do vetor pertinenciaDoSub. Em que cada índice representa a coluna específica.
     */
    
    for(int i=0; i<indiceEleSubConj.size();i++){
        switch (indiceEleSubConj.at(i)){
            case 0:
            {
                atributo = atributoI.at(0);
                
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste1_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste1_CB", pertinenciaDoSub);
                }
                break;
            }
            case 1:{
                atributo = atributoI.at(1);
                /*
                * Quando incideDaPertinencia for igual a 4, ele representa um valor categórico
                * ou seja, não é classificada como alta, media, baixa. Ela representa o nome
                * categórico presente naquela posição
                */
                incideDaPertinencia = 4;
                break;
            }
            case 2:{
                atributo = atributoI.at(2);
                incideDaPertinencia = 4;
                break;
            }
            case 3:{
                atributo = atributoI.at(3);
                incideDaPertinencia = 4;
                break;
            }
            case 4:
            {
                atributo = atributoI.at(4);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste5_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste5_CB", pertinenciaDoSub);
                }
                break;
            }
            case 5:
            {
                atributo = atributoI.at(5);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste6_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste6_CB", pertinenciaDoSub);
                }
                break;
            }
            case 6:{
                atributo = atributoI.at(6);
                incideDaPertinencia = 4;
                break;
            }
            case 7:
            {
                atributo = atributoI.at(7); 
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste8_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste8_CB", pertinenciaDoSub);
                }
                break;
            }
            case 8:
            {
                atributo = atributoI.at(8);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste9_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste9_CB", pertinenciaDoSub);
                }
                break;
            }
            case 9:
            {
                atributo = atributoI.at(9);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste10_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste10_CB", pertinenciaDoSub);
                }
                break;
            }
            case 10:
            {
                atributo = atributoI.at(10);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste11_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste11_CB", pertinenciaDoSub);
                }
                break;
            }
            case 11:{
                atributo = atributoI.at(11);
                incideDaPertinencia = 4;
                break;
            }
            case 12:
            {
                atributo = atributoI.at(12);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste13_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste13_CB", pertinenciaDoSub);
                }
                break;
            }
            case 13:{
                atributo = atributoI.at(13);
                incideDaPertinencia = 4;
                break;
            }
            case 14:{
                atributo = atributoI.at(14);
                incideDaPertinencia = 4;
                break;
            }
            case 15:
            {
                atributo = atributoI.at(15);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste16_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste16_CB", pertinenciaDoSub);
                }
                break;
            }
            case 16:
            {
                atributo = atributoI.at(16);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste17_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste17_CB", pertinenciaDoSub);
                }
                break;
            }
            case 17:
            {
                atributo = atributoI.at(17);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste18_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste18_CB", pertinenciaDoSub);
                }
                break;
            }
            case 18:
            {
                atributo = atributoI.at(18);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste19_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste19_CB", pertinenciaDoSub);
                }
                break;
            }
            case 19:{
                atributo = atributoI.at(19);
                incideDaPertinencia = 4;
                break;
            }
            case 20:{
                atributo = atributoI.at(20);
                incideDaPertinencia = 4;
                break;   
            }
            case 21:{
                atributo = atributoI.at(21);
                incideDaPertinencia = 4;
                break;                
            }
            case 22:
            {
                atributo = atributoI.at(22);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste23_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste23_CB", pertinenciaDoSub);
                }
                break;
            }
            case 23:
            {
                atributo = atributoI.at(23);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste24_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste24_CB", pertinenciaDoSub);
                }
                break;
            }
            case 24:
            {
                atributo = atributoI.at(24);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste25_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste25_CB", pertinenciaDoSub);
                }
                break;
            }
            case 25:
            {
                atributo = atributoI.at(25);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste26_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste26_CB", pertinenciaDoSub);
                }
                break;
            }
            case 26:
            {
                atributo = atributoI.at(26);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste27_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste27_CB", pertinenciaDoSub);
                }
                break;
            }
            case 27:
            {
                atributo = atributoI.at(27);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste28_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste28_CB", pertinenciaDoSub);
                }
                break;
            }
            case 28:
            {
                atributo = atributoI.at(28);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste29_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste29_CB", pertinenciaDoSub);
                }
                break;
            }
            case 29:
            {
                atributo = atributoI.at(29);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste30_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste30_CB", pertinenciaDoSub);
                }
                break;
            }
            case 30:
            {
                atributo = atributoI.at(30);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste31_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste31_CB", pertinenciaDoSub);
                }
                break;
            }
            case 31:
            {
                atributo = atributoI.at(31);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste32_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste32_CB", pertinenciaDoSub);
                }
                break;
            }
            case 32:
            {
                atributo = atributoI.at(32);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste33_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste33_CB", pertinenciaDoSub);
                }
                break;
            }
            case 33:
            {
                atributo = atributoI.at(33);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste34_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste34_CB", pertinenciaDoSub);
                }
                break;
            }
            case 34:
            {
                atributo = atributoI.at(34);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste35_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste35_CB", pertinenciaDoSub);
                }
                break;
            }
            case 35:
            {
                atributo = atributoI.at(35);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste36_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste36_CB", pertinenciaDoSub);
                }
                break;
            }
            case 36:
            {
                atributo = atributoI.at(36);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste37_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste37_CB", pertinenciaDoSub);
                }
                break;
            }
            case 37:
            {
                atributo = atributoI.at(37);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste38_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste38_CB", pertinenciaDoSub);
                }
                break;
            }
            case 38:
            {
                atributo = atributoI.at(38);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste39_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste39_CB", pertinenciaDoSub);
                }
                break;
            }
            case 39:
            {
                atributo = atributoI.at(39);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste40_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste40_CB", pertinenciaDoSub);
                }
                break;
            }
            case 40:
            {
                atributo = atributoI.at(40);
                if(classe){
                    incideDaPertinencia = indicePertinencia("UTeste41_CA", pertinenciaDoSub);
                }else{
                    incideDaPertinencia = indicePertinencia("UTeste41_CB", pertinenciaDoSub);
                }
                break;
            }
        }
        colunaPert = incideDaPertinencia;
        switch (incideDaPertinencia){
            case 0: regraF = Fx_i.at(0); break;
            case 1: regraF = Fx_i.at(1); break;
            case 2: regraF = Fx_i.at(2); break;
            case 4: regraF= valoresAtributosSubConj.at(indiceParaValorAtributo); break;
            default: regraF= "nul"; break;
        }
        if(regraF.compare("nul")!=0)
            cabecalho.push_back("<"+atributo+","+regraF+">");
        atributo.clear();
        regraF.clear();
    }
    return cabecalho;
}

int IndAssReFuzzy::indicePertinencia(char arquivoPertinencia[50], double valorAVerificar){
    
    ifstream inputValor;        
    double valorBaixo, valorMedio, valorAlto;
    int guardaJPert =-1;
    
    inputValor.open(arquivoPertinencia, ifstream::in);
     
    //Tratamento de erro caso os arquivos não existam
    if(!inputValor.is_open()){
        printf("Erro na abertura do arquivo de pertinência para busca do indice!");
        inputValor.clear();
        exit(1);
    }
        
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(!inputValor.eof()){
        
        inputValor>>valorBaixo;
        inputValor>>valorMedio;
        inputValor>>valorAlto;
        
        if(valorAVerificar == valorBaixo){
            guardaJPert = 0;
            break;
        }else{
            if(valorAVerificar == valorMedio){
                guardaJPert = 1;
                break;
            }else{
                if(valorAVerificar == valorAlto){
                    guardaJPert = 2;
                    break;
                }
            }
        }
    }
    inputValor.close();
    return guardaJPert;
}

vector<double> IndAssReFuzzy::RetornaMatrizPertinenciaAtributos(int indiceNaTabT, int indiceColunaPertinecia, double limiarParaValoresBaixos, char nomeBaseOTeste[50], string valorSubConj, int classeAtual){
    
    int RLinguisticaColuna, colunaTabelaInd;
    double w = limiarParaValoresBaixos;
    vector<string > colunaValCateg;
    vector<double> mRetorno;
        
    utilitarios ut;
    
    colunaTabelaInd = indiceNaTabT;
    RLinguisticaColuna = indiceColunaPertinecia;

    //Chama a função criaMatrizComValoresCabecalho de acordo com a coluna na tabela transação
    switch(colunaTabelaInd){
        case 0: 
        {
                vector<vector<double> > Tpertinencia_cT1;
                if(classeAtual == 1){
                    Tpertinencia_cT1= ut.GeraMatrizPertinencia("UTeste1_CA");
                }else{
                    Tpertinencia_cT1= ut.GeraMatrizPertinencia("UTeste1_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT1, RLinguisticaColuna, w); break;
                Tpertinencia_cT1.clear();
            }
            case 1: 
                colunaValCateg = RetornaDadoCategorico(nomeBaseOTeste, colunaTabelaInd);
                mRetorno = CriaVetorComValoresVariaveisCategoricas(colunaValCateg, valorSubConj); 
                break;
            case 2: 
                colunaValCateg = RetornaDadoCategorico(nomeBaseOTeste, colunaTabelaInd);
                mRetorno = CriaVetorComValoresVariaveisCategoricas(colunaValCateg, valorSubConj); 
                break;
            case 3: 
                colunaValCateg = RetornaDadoCategorico(nomeBaseOTeste, colunaTabelaInd);
                mRetorno = CriaVetorComValoresVariaveisCategoricas(colunaValCateg, valorSubConj); 
                break;    
            case 4:{
                vector<vector<double> > Tpertinencia_cT5;
                if(classeAtual == 1){
                    Tpertinencia_cT5= ut.GeraMatrizPertinencia("UTeste5_CA");
                }else{
                    Tpertinencia_cT5= ut.GeraMatrizPertinencia("UTeste5_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT5, RLinguisticaColuna, w); break;
                Tpertinencia_cT5.clear();
            }
            case 5: 
            {
                vector<vector<double> > Tpertinencia_cT6;
                if(classeAtual == 1){
                    Tpertinencia_cT6= ut.GeraMatrizPertinencia("UTeste6_CA");
                }else{
                    Tpertinencia_cT6= ut.GeraMatrizPertinencia("UTeste6_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT6, RLinguisticaColuna, w); break;
                Tpertinencia_cT6.clear();
            }
            case 6: 
                colunaValCateg = RetornaDadoCategorico(nomeBaseOTeste, colunaTabelaInd);
                mRetorno = CriaVetorComValoresVariaveisCategoricas(colunaValCateg, valorSubConj); 
                break;
            case 7:
            {
                vector<vector<double> > Tpertinencia_cT8;
                if(classeAtual == 1){
                    Tpertinencia_cT8= ut.GeraMatrizPertinencia("UTeste8_CA");
                }else{
                    Tpertinencia_cT8= ut.GeraMatrizPertinencia("UTeste8_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT8, RLinguisticaColuna, w); break;
                Tpertinencia_cT8.clear();
            }
            case 8:
            {
                vector<vector<double> > Tpertinencia_cT9;
                if(classeAtual == 1){
                    Tpertinencia_cT9= ut.GeraMatrizPertinencia("UTeste9_CA");
                }else{
                    Tpertinencia_cT9= ut.GeraMatrizPertinencia("UTeste9_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT9, RLinguisticaColuna, w); break;
                Tpertinencia_cT9.clear();
            }
            case 9:
            {
                vector<vector<double> > Tpertinencia_cT10;
                if(classeAtual == 1){
                    Tpertinencia_cT10= ut.GeraMatrizPertinencia("UTeste10_CA");
                }else{
                    Tpertinencia_cT10= ut.GeraMatrizPertinencia("UTeste10_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT10, RLinguisticaColuna, w); break;
                Tpertinencia_cT10.clear();
            }
            case 10:
            {
                vector<vector<double> > Tpertinencia_cT11;
                if(classeAtual == 1){
                    Tpertinencia_cT11= ut.GeraMatrizPertinencia("UTeste11_CA");
                }else{
                    Tpertinencia_cT11= ut.GeraMatrizPertinencia("UTeste11_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT11, RLinguisticaColuna, w); break;
                Tpertinencia_cT11.clear();
            }
            case 11:                 
                colunaValCateg = RetornaDadoCategorico(nomeBaseOTeste, colunaTabelaInd);
                mRetorno = CriaVetorComValoresVariaveisCategoricas(colunaValCateg, valorSubConj); 
                break;
            case 12:
            {
                vector<vector<double> > Tpertinencia_cT13;
                if(classeAtual == 1){
                    Tpertinencia_cT13= ut.GeraMatrizPertinencia("UTeste13_CA");
                }else{
                    Tpertinencia_cT13= ut.GeraMatrizPertinencia("UTeste13_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT13, RLinguisticaColuna, w); break;
                Tpertinencia_cT13.clear();
            }
            case 13: 
                colunaValCateg = RetornaDadoCategorico(nomeBaseOTeste, colunaTabelaInd);
                mRetorno = CriaVetorComValoresVariaveisCategoricas(colunaValCateg, valorSubConj); 
                break;
            case 14: 
                colunaValCateg = RetornaDadoCategorico(nomeBaseOTeste, colunaTabelaInd);
                mRetorno = CriaVetorComValoresVariaveisCategoricas(colunaValCateg, valorSubConj); 
                break;
            case 15:
            {
                vector<vector<double> > Tpertinencia_cT16;
                if(classeAtual == 1){
                        Tpertinencia_cT16= ut.GeraMatrizPertinencia("UTeste16_CA");
                }else{
                        Tpertinencia_cT16= ut.GeraMatrizPertinencia("UTeste16_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT16, RLinguisticaColuna, w); break;
                Tpertinencia_cT16.clear();
            }
            case 16:
            {
                vector<vector<double> > Tpertinencia_cT17;
                if(classeAtual == 1){
                    Tpertinencia_cT17= ut.GeraMatrizPertinencia("UTeste17_CA");
                }else{
                    Tpertinencia_cT17= ut.GeraMatrizPertinencia("UTeste17_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT17, RLinguisticaColuna, w); break;
                Tpertinencia_cT17.clear();
            }
            case 17:
            {
                vector<vector<double> > Tpertinencia_cT18;
                if(classeAtual == 1){
                    Tpertinencia_cT18= ut.GeraMatrizPertinencia("UTeste18_CA");
                }else{
                    Tpertinencia_cT18= ut.GeraMatrizPertinencia("UTeste18_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT18, RLinguisticaColuna, w); break;
                Tpertinencia_cT18.clear();
            }
            case 18:
            {
                vector<vector<double> > Tpertinencia_cT19;
                if(classeAtual == 1){
                    Tpertinencia_cT19= ut.GeraMatrizPertinencia("UTeste19_CA");
                }else{
                    Tpertinencia_cT19= ut.GeraMatrizPertinencia("UTeste19_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT19, RLinguisticaColuna, w); break;
                Tpertinencia_cT19.clear();
            }
            case 19: 
                colunaValCateg = RetornaDadoCategorico(nomeBaseOTeste, colunaTabelaInd);
                mRetorno = CriaVetorComValoresVariaveisCategoricas(colunaValCateg, valorSubConj); 
                break;
            case 20: 
                colunaValCateg = RetornaDadoCategorico(nomeBaseOTeste, colunaTabelaInd);
                mRetorno = CriaVetorComValoresVariaveisCategoricas(colunaValCateg, valorSubConj); 
                break;
            case 21: 
                colunaValCateg = RetornaDadoCategorico(nomeBaseOTeste, colunaTabelaInd);
                mRetorno = CriaVetorComValoresVariaveisCategoricas(colunaValCateg, valorSubConj); 
                break;
            case 22:
            {
                vector<vector<double> > Tpertinencia_cT23;
                if(classeAtual == 1){
                    Tpertinencia_cT23= ut.GeraMatrizPertinencia("UTeste23_CA");
                }else{
                    Tpertinencia_cT23= ut.GeraMatrizPertinencia("UTeste23_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT23, RLinguisticaColuna, w); break;
                Tpertinencia_cT23.clear();
            }
            case 23:
            {
                vector<vector<double> > Tpertinencia_cT24;
                if(classeAtual == 1){
                    Tpertinencia_cT24= ut.GeraMatrizPertinencia("UTeste24_CA");
                }else{
                    Tpertinencia_cT24= ut.GeraMatrizPertinencia("UTeste24_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT24, RLinguisticaColuna, w); break;
                Tpertinencia_cT24.clear();
            }
            case 24:
            {
                vector<vector<double> > Tpertinencia_cT25;
                if(classeAtual == 1){
                    Tpertinencia_cT25= ut.GeraMatrizPertinencia("UTeste25_CA");
                }else{
                    Tpertinencia_cT25= ut.GeraMatrizPertinencia("UTeste25_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT25, RLinguisticaColuna, w); break;
                Tpertinencia_cT25.clear();
            }
            case 25:
            {
                vector<vector<double> > Tpertinencia_cT26;
                if(classeAtual == 1){
                    Tpertinencia_cT26= ut.GeraMatrizPertinencia("UTeste26_CA");
                }else{
                    Tpertinencia_cT26= ut.GeraMatrizPertinencia("UTeste26_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT26, RLinguisticaColuna, w); break;
                Tpertinencia_cT26.clear();
            }
            case 26:
            {
                vector<vector<double> > Tpertinencia_cT27;
                if(classeAtual == 1){
                    Tpertinencia_cT27= ut.GeraMatrizPertinencia("UTeste27_CA");
                }else{
                    Tpertinencia_cT27= ut.GeraMatrizPertinencia("UTeste27_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT27, RLinguisticaColuna, w); break;
                Tpertinencia_cT27.clear();
            }
            case 27:
            {
                vector<vector<double> > Tpertinencia_cT28;
                if(classeAtual == 1){
                    Tpertinencia_cT28= ut.GeraMatrizPertinencia("UTeste28_CA");
                }else{
                    Tpertinencia_cT28= ut.GeraMatrizPertinencia("UTeste28_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT28, RLinguisticaColuna, w); break;
                Tpertinencia_cT28.clear();
            }
            case 28:
            {
                vector<vector<double> > Tpertinencia_cT29;
                if(classeAtual == 1){
                    Tpertinencia_cT29= ut.GeraMatrizPertinencia("UTeste29_CA");
                }else{
                    Tpertinencia_cT29= ut.GeraMatrizPertinencia("UTeste29_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT29, RLinguisticaColuna, w); break;
                Tpertinencia_cT29.clear();
            }
            case 29: 
            {
                vector<vector<double> > Tpertinencia_cT30;
                if(classeAtual == 1){
                    Tpertinencia_cT30= ut.GeraMatrizPertinencia("UTeste30_CA");
                }else{
                    Tpertinencia_cT30= ut.GeraMatrizPertinencia("UTeste30_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT30, RLinguisticaColuna, w); break;
                Tpertinencia_cT30.clear();
            }
            case 30:
            {
                vector<vector<double> > Tpertinencia_cT31;
                if(classeAtual == 1){
                    Tpertinencia_cT31= ut.GeraMatrizPertinencia("UTeste31_CA");
                }else{
                    Tpertinencia_cT31= ut.GeraMatrizPertinencia("UTeste31_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT31, RLinguisticaColuna, w); break;
                Tpertinencia_cT31.clear();
            }
            case 31:
            {
                vector<vector<double> > Tpertinencia_cT32;
                if(classeAtual == 1){
                    Tpertinencia_cT32= ut.GeraMatrizPertinencia("UTeste32_CA");
                }else{
                    Tpertinencia_cT32= ut.GeraMatrizPertinencia("UTeste32_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT32, RLinguisticaColuna, w); break;
                Tpertinencia_cT32.clear();
            }
            case 32:
            {
                vector<vector<double> > Tpertinencia_cT33;
                if(classeAtual == 1){
                    Tpertinencia_cT33= ut.GeraMatrizPertinencia("UTeste33_CA");
                }else{
                    Tpertinencia_cT33= ut.GeraMatrizPertinencia("UTeste33_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT33, RLinguisticaColuna, w); break;
                Tpertinencia_cT33.clear();
            }
            case 33: 
            {
                vector<vector<double> > Tpertinencia_cT34;
                if(classeAtual == 1){
                    Tpertinencia_cT34= ut.GeraMatrizPertinencia("UTeste34_CA");
                }else{
                    Tpertinencia_cT34= ut.GeraMatrizPertinencia("UTeste34_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT34, RLinguisticaColuna, w); break;
                Tpertinencia_cT34.clear();
            }
            case 34:
            {
                vector<vector<double> > Tpertinencia_cT35;
                if(classeAtual == 1){
                    Tpertinencia_cT35= ut.GeraMatrizPertinencia("UTeste35_CA");
                }else{
                    Tpertinencia_cT35= ut.GeraMatrizPertinencia("UTeste35_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT35, RLinguisticaColuna, w); break;
                Tpertinencia_cT35.clear();
            }
            case 35:
            {
                vector<vector<double> > Tpertinencia_cT36;
                if(classeAtual == 1){
                    Tpertinencia_cT36= ut.GeraMatrizPertinencia("UTeste36_CA");
                }else{
                    Tpertinencia_cT36= ut.GeraMatrizPertinencia("UTeste36_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT36, RLinguisticaColuna, w); break;
                Tpertinencia_cT36.clear();
            }
            case 36:
            {
                vector<vector<double> > Tpertinencia_cT37;
                if(classeAtual == 1){
                    Tpertinencia_cT37= ut.GeraMatrizPertinencia("UTeste37_CA");
                }else{
                    Tpertinencia_cT37= ut.GeraMatrizPertinencia("UTeste37_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT37, RLinguisticaColuna, w); break;
                Tpertinencia_cT37.clear();
            }
            case 37: 
            {
                vector<vector<double> > Tpertinencia_cT38;
                if(classeAtual == 1){
                    Tpertinencia_cT38= ut.GeraMatrizPertinencia("UTeste38_CA");
                }else{
                    Tpertinencia_cT38= ut.GeraMatrizPertinencia("UTeste38_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT38, RLinguisticaColuna, w); break;
                Tpertinencia_cT38.clear();
            }
            case 38:
            {
                vector<vector<double> > Tpertinencia_cT39;
                if(classeAtual == 1){
                    Tpertinencia_cT39= ut.GeraMatrizPertinencia("UTeste39_CA");
                }else{
                    Tpertinencia_cT39= ut.GeraMatrizPertinencia("UTeste39_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT39, RLinguisticaColuna, w); break;
                Tpertinencia_cT39.clear();
            }
            case 39:
            {
                vector<vector<double> > Tpertinencia_cT40;
                if(classeAtual == 1){
                    Tpertinencia_cT40= ut.GeraMatrizPertinencia("UTeste40_CA");
                }else{
                    Tpertinencia_cT40= ut.GeraMatrizPertinencia("UTeste40_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT40, RLinguisticaColuna, w); break;
                Tpertinencia_cT40.clear();
            }
            case 40:
            {
                vector<vector<double> > Tpertinencia_cT41;
                if(classeAtual == 1){
                    Tpertinencia_cT41= ut.GeraMatrizPertinencia("UTeste41_CA");
                }else{
                    Tpertinencia_cT41= ut.GeraMatrizPertinencia("UTeste41_CB");
                }
                mRetorno = CriaMatrizComValoresCabecalhoVariaveisNum(Tpertinencia_cT41, RLinguisticaColuna, w); break;
                Tpertinencia_cT41.clear();
            }
    }
    return mRetorno;
}

vector<vector<int> > IndAssReFuzzy::RegraAssociacaoFuzzy(vector< string> tabelaAtributos, vector<double> pertinenciaDoSubconjunto, double thresholdRI, double thresholdGC, vector<vector<int> > &indiceElementosDoSubCj, char BaseOrg[50], double limiarValoresBaixos, int classeRF, vector<int> posicoesIniciaisHyperEdge, vector<vector<int> > &pertinenciaRegrasValidas, vector<double> &grauCertezaRegrasValidas, vector<vector<string> > &descricaoRegrasValidas,vector<vector<int> > &indiceLargeItem, vector<vector<int> > &indAtributoLItem, vector< vector<string> >  &descAntecedentes, vector<int> &pertConseqFinal, vector<int> &indConseqFinal, vector<string> &cabConseqFinal){
    
    double signif, auxiliar, significanciaDeUmElemento;
    int auxiliarIndice, tamanhoRI;
    int qtdeComparacao, contaComparacao=0;
    string itemCabecalho;
    vector<string> vT_I,vRegraLFuzzy,auxRegrasValidas, cabConseq, cabecalhoRegra;
    vector<int> indiceAtributoLargeItem, indiceElementoSubLargeItem, indicePositionJPertLargeItem,vPositionJPert;
    vector<int> indiceAtributoLargeItemR, indiceElementoSubLargeItemR, indicePositionJPertLargeItemR;
    vector<int> qtdeValorMaiorLimiar, auxPosPertinencia, valorIguaisEscolhidos, indiceUti;
    vector<double> grandeConjItens, contaPertinenciaRI, significanciaRegras, grandeConjItensR, contaPertinenciaRIQtdeValida;
    vector<string> cabecalhoGrandeConjItens, cabecalhoGrandeConjItensR;
    vector<vector <string> > mcabecalhoRegra;
    vector<vector <int> > mPositionJPert, matrizAntecedentes, mqtdeValorMaiorLimiar, novoIndiceElementos;
    vector< vector<double> > somatorioPertinenciasLargeItem;
    
        
    //Recebendo as regras linguísticas e atributos
    vT_I = AlimentaVetoresAtributos();
    vRegraLFuzzy = AlimentaVetoresRegrasLinguisticas();
    
    //Chamando o método que cria cabeçalho das regras linguísticas
    double valorPertinenciaAVerificar;
    vector<int> vnovoIndiceElementos;
    vector<string> vcabecalhoRegra;
    int pertinenciaJ;
    
    for(int i=0; i<indiceElementosDoSubCj.size();i++){
        for(int j=0;j<indiceElementosDoSubCj[i].size();j++){
            indiceUti.push_back(indiceElementosDoSubCj[i][j]);
            valorPertinenciaAVerificar = pertinenciaDoSubconjunto.at(i);
            cabecalhoRegra = GeraCabecalho(vRegraLFuzzy, vT_I, valorPertinenciaAVerificar, pertinenciaJ,tabelaAtributos, indiceUti, classeRF,i);
            if(cabecalhoRegra.size()!= 0 ){
                vPositionJPert.push_back(pertinenciaJ);
                vnovoIndiceElementos.push_back(indiceElementosDoSubCj[i][j]);
                for(int k=0;k<cabecalhoRegra.size();k++){
                    vcabecalhoRegra.push_back(cabecalhoRegra.at(k));
                }
            }
            //Limpando os vetores para novas inclusões
            cabecalhoRegra.clear();
            indiceUti.clear();
        }
        novoIndiceElementos.push_back(vnovoIndiceElementos);
        mcabecalhoRegra.push_back(vcabecalhoRegra);
        mPositionJPert.push_back(vPositionJPert);
        vPositionJPert.clear();
        vnovoIndiceElementos.clear();
        vcabecalhoRegra.clear();
    }
    //Atualizando o indiceElementosDoSubCj, desconsiderando os valores nulos
    indiceElementosDoSubCj.clear();
    indiceElementosDoSubCj = novoIndiceElementos;
    novoIndiceElementos.clear();
    cabecalhoRegra.clear();
    vPositionJPert.clear();
    
    //Imprimindo pertinencia
    cout<<"\n Imprimir mcabecalhoRegra\n";
    for(int i=0; i<mcabecalhoRegra.size(); i++){
        for(int j=0;j<mcabecalhoRegra[i].size();j++){
               cout<<mcabecalhoRegra[i][j]<<" ";
        }cout<<endl;
    }
    
    //Imprimindo pertinencia
    cout<<"\n Imprimir mPositionJPert\n";
    for(int i=0; i<mPositionJPert.size(); i++){
        for(int j=0;j<mPositionJPert[i].size();j++){
            cout<<mPositionJPert[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //Imprimindo indiceElementosDoSubCj
    cout<<"\n Imprimir indiceElementosDoSubCj\n";
    for(int i=0; i<indiceElementosDoSubCj.size(); i++){
        for(int j=0;j<indiceElementosDoSubCj[i].size();j++){
            cout<<indiceElementosDoSubCj[i][j]<<" ";
        }
        cout<<endl;
    }
    /*
     * O próximo passo é alimentar os vetores de acordo com a regra linguística,
     * para a partir daí realizar o cálculo de indução
     */
    
    for(int i=0; i<indiceElementosDoSubCj.size();i++){
        for(int ii=0;ii<indiceElementosDoSubCj[i].size();ii++){
            contaPertinenciaRI = RetornaMatrizPertinenciaAtributos(indiceElementosDoSubCj[i][ii], mPositionJPert[i][ii], limiarValoresBaixos, BaseOrg, tabelaAtributos[i], classeRF);
            
            tamanhoRI = contaPertinenciaRI.size();
            qtdeValorMaiorLimiar.push_back(tamanhoRI);
        }
        //Guardando o total de todas as pertinências dos elementos presentes na matriz indiceElementosDoSubCj 
        mqtdeValorMaiorLimiar.push_back(qtdeValorMaiorLimiar);
        qtdeValorMaiorLimiar.clear();
    }
    
    cout<<"Imprimindo a matriz de total de pertinência válida"<<endl;
    for(int i=0; i<mqtdeValorMaiorLimiar.size(); i++){
        for(int j=0;j<mqtdeValorMaiorLimiar[i].size();j++){
            cout<<mqtdeValorMaiorLimiar[i][j]<<" ";
        }
        cout<<endl;
    }
    int guardaMenorElementoA, guardaMenorElementoB;
    int menorEscolhido, valorCalculado, valorCalculadoAux, contaRepetido =0;
    
    /*
    * Verificando qual a quantidade de pertinências válidas que deve ser considerada
    * para a geração do LargeItemset
    */
    for(int i=0; i<mqtdeValorMaiorLimiar.size(); i++){
        for(int j=0;j<mqtdeValorMaiorLimiar[i].size();j++){
            qtdeComparacao = mqtdeValorMaiorLimiar[i][j];
            if(qtdeComparacao!=0){
                for(int jj=0; jj<mqtdeValorMaiorLimiar.size();jj++){
                    for(int k=0; k<mqtdeValorMaiorLimiar[jj].size();k++){
                        if((jj == i)&&(k!=j)||((jj!=i) && (k==j))||((jj!=i) && (k!=j))){
                            //Guardando no vetor valorIguaisEscolhidos, os valores repetidos
                            if(mqtdeValorMaiorLimiar[jj][k] == qtdeComparacao){
                                if(valorIguaisEscolhidos.size()==0){
                                    valorIguaisEscolhidos.push_back(qtdeComparacao);
                                }else{
                                        for(int kk=0; kk<valorIguaisEscolhidos.size();kk++){
                                            if(qtdeComparacao != valorIguaisEscolhidos.at(kk)){
                                                contaComparacao++;
                                            }
                                        }
                                            if(contaComparacao == valorIguaisEscolhidos.size()){
                                               valorIguaisEscolhidos.push_back(qtdeComparacao);
                                    }
                                    contaComparacao=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    for(int kk=0; kk<valorIguaisEscolhidos.size();kk++){
        cout<<valorIguaisEscolhidos.at(kk)<<" ";
    }cout<<endl;

    vector<int> valoresMenores;
    int contaVMenores=0;
    //Contar quantos grupos de valores diferentes existem, se for mais de um deve repetir todo o 
    //processo de geração de regras para cada um
    if(valorIguaisEscolhidos.size()==0){
        //Verifica-se a existencia de valores menores acima de 100
        for(int ii=0; ii< mqtdeValorMaiorLimiar.size();ii++){
            for(int ij=0; ij<mqtdeValorMaiorLimiar[ii].size();ij++){
                if(mqtdeValorMaiorLimiar[ii][ij]>100){
                    valoresMenores.push_back(mqtdeValorMaiorLimiar[ii][ij]);
                    contaVMenores++;
                }
            }
        }
        if(contaVMenores >= mqtdeValorMaiorLimiar.size()){
            guardaMenorElementoA = *min_element(valoresMenores.begin(), valoresMenores.end());
            for(int i=1; i<mqtdeValorMaiorLimiar.size(); i++){
                guardaMenorElementoB = *min_element(mqtdeValorMaiorLimiar[i].begin(), mqtdeValorMaiorLimiar[i].end());
                if((guardaMenorElementoB < guardaMenorElementoA)&&(guardaMenorElementoB>100))
                    guardaMenorElementoA = guardaMenorElementoB;
            }
            menorEscolhido = guardaMenorElementoA;
        }else{
            guardaMenorElementoA = *min_element(mqtdeValorMaiorLimiar[0].begin(), mqtdeValorMaiorLimiar[0].end());
            for(int i=1; i<mqtdeValorMaiorLimiar.size(); i++){
                guardaMenorElementoB = *min_element(mqtdeValorMaiorLimiar[i].begin(), mqtdeValorMaiorLimiar[i].end());
                if(guardaMenorElementoB < guardaMenorElementoA)
                    guardaMenorElementoA = guardaMenorElementoB;
            }
            menorEscolhido = guardaMenorElementoA;
        }
    }else{
        if(valorIguaisEscolhidos.size()>1){
            
            /*
            * Se existir algum valor maior ou igual a 100, os menores que 100 serão eliminados.
            * Isso permitirá a seleção e utilização de mais itens
            */
            bool valorMaior100 = false;
            for(int k=0; k<valorIguaisEscolhidos.size(); k++){
                if(valorIguaisEscolhidos.at(k)>= 100){
                    valorMaior100 = true;
                    break;
                }
            }

            if(valorMaior100){
                for(int k=0; k<valorIguaisEscolhidos.size(); k++){
                    if(valorIguaisEscolhidos.at(k)< 100){
                        valorIguaisEscolhidos.erase(valorIguaisEscolhidos.begin()+k);
                        k--;
                    }
                }
            }
            /*
            cout<<"\n Valores iguais\n";
            for(int k=0; k<valorIguaisEscolhidos.size(); k++){
                cout<<valorIguaisEscolhidos.at(k)<< " ";
            }
            cout<<endl;
            */
            /*
            * Verificando se o vetor valorIguaisEscolhidos possui mais de um registro
            * caso exista Selecionar o menor, caso contrário selecionar será subtraido do único registro valor igual
            * a 1000 e selecionar a quantidade de valores de pertinência
            * a serem considerados, com relação a quantidade selecionada no vetor valorIguaisEscolhidos
            */

            vector<int> valorMenorEscolhido;
            if(valorIguaisEscolhidos.size() >1){
                menorEscolhido= valorIguaisEscolhidos.at(0);
                    for(int i=1; i< valorIguaisEscolhidos.size();i++){
                        if(valorIguaisEscolhidos.at(i)< menorEscolhido){
                           menorEscolhido = valorIguaisEscolhidos.at(i);
                    }
                }
            }else{
                for(int i=0; i<mqtdeValorMaiorLimiar.size(); i++){
                    for(int j=0;j<mqtdeValorMaiorLimiar[i].size();j++){
                        if(mqtdeValorMaiorLimiar[i][j]!=0){
                            for(int jj=0; jj<mqtdeValorMaiorLimiar.size();jj++){
                                for(int k=0; k<mqtdeValorMaiorLimiar[jj].size();k++){
                                    if((jj == i)&&(k!=j)||((jj!=i) && (k==j))||((jj!=i) && (k!=j))){
                                        //Guardando no vetor valorIguaisEscolhidos, os valores repetidos
                                        if((mqtdeValorMaiorLimiar[jj][k] > mqtdeValorMaiorLimiar[i][j])&&(mqtdeValorMaiorLimiar[i][j]<valorIguaisEscolhidos.at(0))){
                                            valorMenorEscolhido.push_back(mqtdeValorMaiorLimiar[i][j]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                //Limpando valores repetidos
                for(int h=0; h< valorMenorEscolhido.size(); h++){
                    for(int hh=h+1; hh<valorMenorEscolhido.size(); h++){
                        if(valorMenorEscolhido[h]==valorMenorEscolhido[hh]){
                            valorMenorEscolhido.erase(valorMenorEscolhido.begin()+h);
                            h--;
                            break;
                        }
                    }
                }
                /*    
                cout<<"\nvalorMenorEscolhido \n";
                for(int h=0; h< valorMenorEscolhido.size(); h++){
                    cout<<valorMenorEscolhido[h]<<" ";
                }cout<<endl;
                */   
                //Selecionando o maior valor menor
                menorEscolhido= valorMenorEscolhido.at(0);
                for(int i=1; i< valorMenorEscolhido.size();i++){
                    if(valorMenorEscolhido.at(i)< menorEscolhido){
                        menorEscolhido = valorMenorEscolhido.at(i);
                    }
                }
                valorCalculado = valorMenorEscolhido.at(0)/1000;
                if(valorCalculado >=100){
                    valorCalculadoAux = valorCalculado /10;
                    menorEscolhido = valorCalculadoAux * 10000;
                }else{
                    valorCalculado =  valorCalculado * 1000;
                    menorEscolhido = valorMenorEscolhido.at(0) - valorCalculado;
                }
            }
        }else if(valorIguaisEscolhidos.size()==1){
            menorEscolhido = valorIguaisEscolhidos.at(0);
        }
    }
    menorEscolhido = 12;
    //menorEscolhido = guardaMenorElementoA;
    cout<<"\n menorEscolhido "<< menorEscolhido<<"\n";
    
    for(int i=0; i<indiceElementosDoSubCj.size();i++){
        for(int ii=0;ii<indiceElementosDoSubCj[i].size();ii++){
        contaPertinenciaRI = RetornaMatrizPertinenciaAtributos(indiceElementosDoSubCj[i][ii], mPositionJPert[i][ii], limiarValoresBaixos, BaseOrg, tabelaAtributos[i], classeRF);
            
        //Caso a quantidade de valores de votos sejam maiores que a quantidade a ser considerada no
        //cálculo de significância e grau de certeza, então é considerado apenas o limite válido.

        if(contaPertinenciaRI.size()> menorEscolhido){
            for(int k=0; k<menorEscolhido; k++){
                contaPertinenciaRIQtdeValida.push_back(contaPertinenciaRI.at(k));
            }
        }else if(contaPertinenciaRI.size()== menorEscolhido){
            contaPertinenciaRIQtdeValida = contaPertinenciaRI;
        }

        /*
        * Verificando se o elemento possui uma significância maior que o limiar,
        * caso positivo, será com certeza o primeiro elemento do LargeItemSet
        */

        significanciaDeUmElemento = SignificanciaApenasUmaColuna(contaPertinenciaRIQtdeValida);

        /*
        * Se a soma total da pertinencia do elemento é maior que a sua significância  
        * então esse elemento  pode fazer parte do LargeItemSet
        */

        if(significanciaDeUmElemento > thresholdRI){

            /*
            * Gerando o conjunto de itens com os valores dos elementos que 
            * satisfazem a primeira validação
            */
            auxiliar = pertinenciaDoSubconjunto[i];
            grandeConjItens.push_back(auxiliar);//Recebe a pertinência do candidato
            itemCabecalho = mcabecalhoRegra[i][ii];
            cabecalhoGrandeConjItens.push_back(itemCabecalho);//Recebe o cabeçalho do candidato 
            indiceAtributoLargeItem.push_back(i);
            auxiliarIndice = indiceElementosDoSubCj[i][ii];
            indiceElementoSubLargeItem.push_back(auxiliarIndice);
            auxiliarIndice = mPositionJPert[i][ii];
            indicePositionJPertLargeItem.push_back(auxiliarIndice);
            somatorioPertinenciasLargeItem.push_back(contaPertinenciaRIQtdeValida);
        }   

        contaPertinenciaRI.clear();
        contaPertinenciaRIQtdeValida.clear();
        } 
    }
    
    //Eliminando valores iguais que possuem pertinencia menor
    for(int i=0; i<indiceElementoSubLargeItem.size(); i++){
        for(int j=i+1; j<indiceElementoSubLargeItem.size();j++){
            if((indiceElementoSubLargeItem.at(i) == indiceElementoSubLargeItem.at(j)) &&(grandeConjItens.at(i) < grandeConjItens.at(j))){
                grandeConjItens.erase(grandeConjItens.begin()+i);
                cabecalhoGrandeConjItens.erase(cabecalhoGrandeConjItens.begin()+i);
                indiceAtributoLargeItem.erase(indiceAtributoLargeItem.begin()+i);
                indiceElementoSubLargeItem.erase(indiceElementoSubLargeItem.begin()+i);
                indicePositionJPertLargeItem.erase(indicePositionJPertLargeItem.begin()+i);
                somatorioPertinenciasLargeItem.erase(somatorioPertinenciasLargeItem.begin()+ i);
                i--;
                break; //Atualizar a busca com base ao valor de i
            }else{
                    if((indiceElementoSubLargeItem.at(i) == indiceElementoSubLargeItem.at(j)) &&(grandeConjItens.at(i) > grandeConjItens.at(j))){
                        grandeConjItens.erase(grandeConjItens.begin()+j);
                        cabecalhoGrandeConjItens.erase(cabecalhoGrandeConjItens.begin()+j);
                        indiceAtributoLargeItem.erase(indiceAtributoLargeItem.begin()+j);
                        indiceElementoSubLargeItem.erase(indiceElementoSubLargeItem.begin()+j);
                        indicePositionJPertLargeItem.erase(indicePositionJPertLargeItem.begin()+j);
                        somatorioPertinenciasLargeItem.erase(somatorioPertinenciasLargeItem.begin()+ j);
                        j--;
                    }
                }
        }
    }
     
    
    //Tratamento de erro   
    if(indiceElementoSubLargeItem.size() == 0){
        cout<<"\nNão existe candidatos para geração de regras\n";
        cout<<"Favor ajustar os parâmetros (Regra de Indução).\n";
        exit(1);
    }
    
    //Imprimindo grandeConjItens
    cout << "\nImprimindo grandeConjItens\n";
    for(int i=0;i<grandeConjItens.size();i++){
        cout<<grandeConjItens[i]<<" ";
    }cout<<endl;
        
    //Imprimindo cabecalhoGrandeConjItens
    cout << "\nImprimindo cabecalhoGrandeConjItens\n";
    for(int i=0;i<cabecalhoGrandeConjItens.size();i++){
        cout<<cabecalhoGrandeConjItens[i]<<" ";
    }cout<<endl;
    
    //Imprimindo indicesLargeItemsets
    cout << "\nImprimindo indiceAtributoLargeItem\n";
    for(int i=0;i<indiceAtributoLargeItem.size();i++){
        cout<<indiceAtributoLargeItem[i]<<" ";
    }cout<<endl;
    
    //Imprimindo indicesLargeItemsets
    cout << "\nImprimindo indiceElementoSubLargeItem\n";
    for(int i=0;i<indiceElementoSubLargeItem.size();i++){
        cout<<indiceElementoSubLargeItem[i]<<" ";
    }cout<<endl;
    
    //Imprimindo indicesLargeItemsets
    cout << "\nImprimindo indicePositionJPertLargeItem\n";
    for(int i=0;i<indicePositionJPertLargeItem.size();i++){
        cout<<indicePositionJPertLargeItem[i]<<" ";
    }cout<<endl;
    
    cout<<"tamanho de somatorioPertinenciasLargeItem " <<somatorioPertinenciasLargeItem.size()<<" por linha "<<somatorioPertinenciasLargeItem[0].size()<<endl;
    
    /*
    * Segundo passo da validação, realiza as combinações possíveis
    * e valida o valor da significância, a fórmula para o cálculo da significancia é:
    * significancia = somaDosVotosQueSatisfazem <X,A> / total de registros em T
    */   
    vector<vector<int> > elementosAceitos;
    vector<vector<double> > matrizAuxiliar;
    vector<vector<int> > regrasSelecionadas, posicaoPertinenciaRI, regrasSelecionadasFinais, regrasSelecionadasF;
    vector<double> vetorDeGrauCertezaRI;
    vector<int> aux, vPosPertConsequente, vIndAtrbConsequente, vIndConsequente;
    vector<vector <string> >  regrasValidasDescritas;
    
    if(indiceElementoSubLargeItem.size() == 2){
        matrizAuxiliar.push_back(somatorioPertinenciasLargeItem.at(1));
        
        //Significa que só tem um par de item, nesse caso não há como gerar outras combinações
        signif= significancia(somatorioPertinenciasLargeItem.at(0), matrizAuxiliar);
        if(signif > thresholdRI){
            //cout<<"\nSignif "<<signif<<endl;
            /*
            * Formatando os itens do conjunto selecionado para garantir que o consequente será de apenas 1 item
            * conforme definido pelo artigo.
            */

           matrizAntecedentes = matrizRegraFinal(indiceElementoSubLargeItem);

           cout<<"Imprimindo a matriz de antecedentes"<<endl;
           for(int i=0; i< matrizAntecedentes.size();i++){
               for(int j=0; j< matrizAntecedentes[i].size();j++){
                   cout<<matrizAntecedentes[i][j]<<" ";
               }
               cout<<endl;
           }

           /*
            * Nesse momento calcula o grau de certeza, que é referente à confiança no Apriori.
            * O cálculo mostrará as regras que são interessantes, no final da seleção dessas regras então expandimos aquelas em que os 
            * antecedentes e consequentes tem associação hyper-Edge
            */

           regrasSelecionadas = CalculaGrauCerteza(indiceAtributoLargeItem, matrizAntecedentes,cabecalhoGrandeConjItens, indiceElementoSubLargeItem, indicePositionJPertLargeItem, somatorioPertinenciasLargeItem, thresholdGC, vetorDeGrauCertezaRI, posicaoPertinenciaRI,regrasValidasDescritas, signif, vPosPertConsequente, vIndConsequente, cabConseq);
           
           
            //Alimentando os vetores e as matrizes de retorno
            for(int i=0; i< regrasSelecionadas.size();i++){
                regrasSelecionadasFinais.push_back(regrasSelecionadas[i]);
                grauCertezaRegrasValidas.push_back(vetorDeGrauCertezaRI.at(i));
                pertinenciaRegrasValidas.push_back(posicaoPertinenciaRI.at(i));
                descricaoRegrasValidas.push_back(regrasValidasDescritas.at(i));
                pertConseqFinal.push_back(vPosPertConsequente.at(i));
                indConseqFinal.push_back(vIndConsequente.at(i));
                cabConseqFinal.push_back(cabConseq.at(i));
            }
            indiceLargeItem.push_back(indiceElementoSubLargeItem);
            indAtributoLItem.push_back(indiceAtributoLargeItem);
            descAntecedentes.push_back(cabecalhoGrandeConjItens);
            
            //Limpando os vetores
            vPosPertConsequente.clear();
            vIndAtrbConsequente.clear();
            vIndConsequente.clear();
            cabConseq.clear();
            regrasSelecionadas.clear();
            vetorDeGrauCertezaRI.clear();
            posicaoPertinenciaRI.clear();
            regrasValidasDescritas.clear();
        }
    }else
    {
        /*
         * Significa que existe mais de um par de item, nesse caso é possível fazer combinações
         * Faz o cálculo de todas as combinações e no final, atualiza os vetores
         */
        elementosAceitos = GeraCombinacoesEValidaSignif(somatorioPertinenciasLargeItem, thresholdRI, significanciaRegras);
        
        cout<<"\nelementosAceitos"<<endl;
        for(int i=0;i<elementosAceitos.size();i++){
            for(int j=0; j<elementosAceitos[i].size();j++){
                cout<<elementosAceitos[i][j]<<" ";
            }
           cout<<endl;
        }
         
        
        /*
         * Para cada vetor do conjunto de itens, atualiza os demais vetores e realiza o cálculo
         * do grau de certeza.
         */
        
        for(int i=0; i< elementosAceitos.size() ;i++){
            
            /*
            * Formatando os itens do conjunto selecionado para garantir que o consequente será de apenas 1 item
            * conforme definido pelo artigo. Para o cálculo esses valores são os índices da matriz da soma
            * de pertinência.
            */

            matrizAntecedentes = matrizRegraFinal(elementosAceitos[i]);

            cout<<"\nmatrizAntecedentes"<<endl;
            for(int x=0;x<matrizAntecedentes.size();x++){
                for(int j=0; j<matrizAntecedentes[x].size();j++){
                    cout<<matrizAntecedentes[x][j]<<" ";
                }
                cout<<endl;
            }
            
            /*
             * Gerando os vetores com os primeiros conjuntos de itens aceitos,
             * para cálculo do grau de certeza.
             */
            for(int ii=0; ii< elementosAceitos[i].size();ii++){
                indiceElementoSubLargeItemR.push_back(indiceElementoSubLargeItem[elementosAceitos[i][ii]]);
                grandeConjItensR.push_back(grandeConjItens[elementosAceitos[i][ii]]);
                cabecalhoGrandeConjItensR.push_back(cabecalhoGrandeConjItens[elementosAceitos[i][ii]]);
                indiceAtributoLargeItemR.push_back(indiceAtributoLargeItem[elementosAceitos[i][ii]]);
                indicePositionJPertLargeItemR.push_back(indicePositionJPertLargeItem[elementosAceitos[i][ii]]);
                
            }
            
            cout<<"\nindiceElementoSubLargeItemR"<<endl;
            for(int i=0;i<indiceElementoSubLargeItemR.size();i++){
                cout<<indiceElementoSubLargeItemR[i]<<" ";
            }cout<<endl;
            
            cout<<"\ngrandeConjItensR"<<endl;
            for(int i=0;i<grandeConjItensR.size();i++){
                cout<<grandeConjItensR[i]<<" ";
            }
                
            cout<<"\ncabecalhoGrandeConjItensR"<<endl;
            for(int i=0;i<cabecalhoGrandeConjItensR.size();i++){
                cout<<cabecalhoGrandeConjItensR[i]<<" ";
            }
                
            cout<<"\nindiceAtributoLargeItemR"<<endl;
            for(int i=0;i<indiceAtributoLargeItemR.size();i++){
                cout<<indiceAtributoLargeItemR[i]<<" ";
            }
            /*    
            cout<<"\nindicePositionJPertLargeItemR"<<endl;
            for(int i=0;i<indicePositionJPertLargeItemR.size();i++){
                cout<<indicePositionJPertLargeItemR[i]<<" ";
            }cout<<endl;
            */
            /*
            * Nesse momento calcula o grau de certeza, que é referente à confiança no Apriori.
            * O cálculo mostrará as regras que são interessantes, no final da seleção dessas regras então expandimos aquelas em que os 
            * antecedentes e consequentes tem associação hyper-Edge
            */

            regrasSelecionadas = CalculaGrauCertezaMaisItens(matrizAntecedentes, cabecalhoGrandeConjItensR, indiceElementoSubLargeItem, indiceElementoSubLargeItemR, indicePositionJPertLargeItemR, somatorioPertinenciasLargeItem, thresholdGC, vetorDeGrauCertezaRI,posicaoPertinenciaRI, regrasValidasDescritas, significanciaRegras[i], vPosPertConsequente, vIndConsequente, cabConseq);
            
            if(regrasSelecionadas.size()!=0){
                /*
                * As regrasSelecionadas são índices da matriz de somatório da pertinência,
                * portanto, será necessário transformar esses índices em valores reais das colunas
                * no qual os conjuntos de itens pertencem. E esse é o próximo passo.
                */

               cout<<"\nImprimindo regrasSelecionadas "<<endl;
               for(int i=0; i<regrasSelecionadas.size(); i++){
                   for(int j=0; j< regrasSelecionadas[i].size();j++){
                       cout<<regrasSelecionadas[i][j]<<" ";
                   }
                   cout<<endl;
               }

               cout<<"\nImprimindo regrasValidasDescritas "<<endl;
               for(int i=0; i<regrasValidasDescritas.size(); i++){
                   for(int j=0; j< regrasValidasDescritas[i].size();j++){
                       cout<<regrasValidasDescritas[i][j]<<" ";
                   }
                   cout<<endl;
               }cout<<endl;

               cout<<"\n vPosPertConsequente\n";
               for(int j=0; j< vPosPertConsequente.size();j++){
                       cout<<vPosPertConsequente.at(j)<<" ";
                   }cout<<endl;
               /*
                   cout<<"\n vIndConsequente\n";
               for(int j=0; j< vIndConsequente.size();j++){
                       cout<<vIndConsequente.at(j)<<" ";
                   }cout<<endl;
               cout<<"\n cabConseq\n";
               for(int j=0; j< cabConseq.size();j++){
                       cout<<cabConseq.at(j)<<" ";
                   }cout<<endl;
                 */  
               //Alimentando a matriz de regras finais com todas as regras
               for(int k=0; k<regrasSelecionadas.size();k++){
                   aux = regrasSelecionadas[k];
                   auxRegrasValidas = regrasValidasDescritas[k];
                   auxPosPertinencia = posicaoPertinenciaRI[k];
                   regrasSelecionadasFinais.push_back(aux);
                   grauCertezaRegrasValidas.push_back(vetorDeGrauCertezaRI.at(k));
                   pertinenciaRegrasValidas.push_back(auxPosPertinencia);
                   descricaoRegrasValidas.push_back(auxRegrasValidas);
                   pertConseqFinal.push_back(vPosPertConsequente.at(k));
                   indConseqFinal.push_back(vIndConsequente.at(k));
                   cabConseqFinal.push_back(cabConseq.at(k));
                   aux.clear();
                   auxRegrasValidas.clear();
                   auxPosPertinencia.clear();                
               }

               //Alimentando os vetores e matrizes
               indiceLargeItem.push_back(indiceElementoSubLargeItemR);
               indAtributoLItem.push_back(indiceAtributoLargeItemR);
               descAntecedentes.push_back(cabecalhoGrandeConjItensR);

            }
               
            //Limpando vetores e matrizes para novas inclusões de dados
            regrasSelecionadas.clear();
            indiceElementoSubLargeItemR.clear();
            grandeConjItensR.clear();
            cabecalhoGrandeConjItensR.clear();
            indiceAtributoLargeItemR.clear();
            indicePositionJPertLargeItemR.clear();
            regrasValidasDescritas.clear();
            vetorDeGrauCertezaRI.clear();
            posicaoPertinenciaRI.clear();
            vPosPertConsequente.clear();
            vIndConsequente.clear();
            cabConseq.clear();
        }
    }
    /*                     
    cout<<"\nImpimindo regrasSelecionadasFinais "<<endl;
    for(int i=0;i<regrasSelecionadasFinais.size();i++){
        for(int j=0;j<regrasSelecionadasFinais[i].size();j++){
            cout<<regrasSelecionadasFinais[i][j]<<" ";
        }cout<<endl;
    }
  */
    //Limpando vetores e matrizes
    posicaoPertinenciaRI.clear();
    vetorDeGrauCertezaRI.clear();
    regrasValidasDescritas.clear();
    matrizAntecedentes.clear();
    indicePositionJPertLargeItem.clear();
    somatorioPertinenciasLargeItem.clear();
    grandeConjItens.clear();
    
   return regrasSelecionadasFinais;
    
}
vector<vector<int> > IndAssReFuzzy::GeraCombinacoesEValidaSignif(vector<vector<double> > matrizPertinencia, double limiarSignificancia, vector <double>  &vetorSignigicanciaDosConjuntos){
    
    vector<int> auxIndicesMaiorQueThreshold,vetorAuxiliar, vetorAuxiliarProx;
    vector<vector<int> > indicesMaiorQueThreshold, geraItem, geraItemFinal, matrizAuxiliar, geraItemPar;
    vector<vector<double> > matrizPertinenciaAux;
    double valorSignificancia;
    int contaIndicesIguais=0, indice;
    
    /*
     * Gerando combinações, de pares, a partir do vetor inicial
     */
    for(int m=0;m< matrizPertinencia.size(); m ++){
           
        for(int k=m+1;k< matrizPertinencia.size(); k ++){
           // cout<<"matrizPertinencia "<<matrizPertinencia[k].size()<<endl;
            
            matrizPertinenciaAux.push_back(matrizPertinencia.at(k));
            //Calculando a significancia dos pares
            valorSignificancia = significancia(matrizPertinencia[m], matrizPertinenciaAux);
            
            if(valorSignificancia > limiarSignificancia){
                //cout<<"valorSignificancia "<<valorSignificancia<<endl;
                auxIndicesMaiorQueThreshold.push_back(m);     
                auxIndicesMaiorQueThreshold.push_back(k);
                indicesMaiorQueThreshold.push_back(auxIndicesMaiorQueThreshold);
                auxIndicesMaiorQueThreshold.clear();
            }
            matrizPertinenciaAux.clear();
        }
    }
    /*
     * Guardando os pares válidos,
     * pois para a regra também é necessário ter pares válidos.
     */
    geraItemPar = indicesMaiorQueThreshold;
    
    /*
    cout<<"Imprimindo  indicesMaiorQueThreshold.size()"<<endl;
    for(int i=0;i<indicesMaiorQueThreshold.size();i++){
        for(int j=0; j< indicesMaiorQueThreshold[i].size();j++){
            cout<<indicesMaiorQueThreshold[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    //Garantindo que limpou completamente para próxima utilização
    matrizPertinenciaAux.clear();
    auxIndicesMaiorQueThreshold.clear();
    int indiceAtual, indiceFinal;
    
    do
    {
        contaIndicesIguais =0;
        /*
        * Matriz indicesMaiorQueThreshold possue todas as combinações de pares possíveis. 
        * Inicia-se agora as demas combinações sem validar
        */
        
        for(int i=0; i< indicesMaiorQueThreshold.size(); i++){
            
            for(int j=0; j<(indicesMaiorQueThreshold[0].size()-1);j++){
                vetorAuxiliar.push_back(indicesMaiorQueThreshold[i][j]);
            }
            indiceAtual = indicesMaiorQueThreshold[i][indicesMaiorQueThreshold[i].size()-1];
            /*
            //Imprimindo para conferencia
            cout<<"vetorAuxiliar"<<endl;
            for(int x=0;x<vetorAuxiliar.size();x++){
               cout<<vetorAuxiliar.at(x)<<endl;
            }
            cout<<endl;
            */
            /*
             * Esse for faz a comparação da linha anterior com todas as linhas
             * da matriz
             */
            for(int jj=i+1;jj<indicesMaiorQueThreshold.size();jj++){

                for(int j=0;j<(indicesMaiorQueThreshold[jj].size()-1);j++){
                    vetorAuxiliarProx.push_back(indicesMaiorQueThreshold[jj][j]);
                }

                indiceFinal = indicesMaiorQueThreshold[jj][indicesMaiorQueThreshold[jj].size()-1];
                /*
                //Imprimindo para conferencia
                cout<<"vetorAuxiliarProx"<<endl;
                for(int x=0;x<vetorAuxiliarProx.size();x++){
                   cout<<vetorAuxiliarProx.at(x);
                }
                cout<<endl;
                */
                if(vetorAuxiliarProx == vetorAuxiliar){
                    vetorAuxiliar.push_back(indiceAtual);
                    vetorAuxiliar.push_back(indiceFinal);
                    geraItem.push_back(vetorAuxiliar);
                    
                    //Excluindo o último elemento incluído para continuar a verificação
                    vetorAuxiliar.pop_back();
                    vetorAuxiliar.pop_back();
                    vetorAuxiliarProx.clear();
                   /* 
                    cout<<"Imprimindo  geraItem.size() if"<<endl;
                    for(int i=0;i<geraItem.size();i++){
                        for(int j=0; j< geraItem[i].size();j++){
                            cout<<geraItem[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    */
                }else{
                        /*
                         * Se não for igual significa que todos os pares que possuem o mesmo índice
                         * já foram validados. Não precisa continuar a conferência, nesse caso pode
                         * iniciar a combinação para os outros pares de primeiro valor diferente.
                         */
                        break;
                    }
            }
            //Limpando o vetor auxiliar, para receber novo par
            vetorAuxiliar.clear();
            vetorAuxiliarProx.clear();
        }
        
        //Garantindo a limpeza do vetorAuxiliar
        vetorAuxiliar.clear();
        vetorAuxiliarProx.clear();
        /*
        cout<<"Imprimindo  geraItem.size()"<<endl;
        for(int i=0;i<geraItem.size();i++){
            for(int j=0; j< geraItem[i].size();j++){
                cout<<geraItem[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        /*
         * Matriz geraItem possui todas as combinações
         * agora realiza a validação, caso o limiar seja válido
         * então ele fará parte do largeItemset
         */ 
        
        for(int i=0; i< geraItem.size();i++){
            for(int j=0; j<geraItem[i].size(); j++){
                indice = geraItem[i][j];
                matrizPertinenciaAux.push_back(matrizPertinencia[indice]);
            }
            //cout<<matrizPertinenciaAux.size()<<endl;
            valorSignificancia = CalculaSignificanciaLargeItens(matrizPertinenciaAux);
            cout<<valorSignificancia<<endl;
            
            if(valorSignificancia > limiarSignificancia){
                auxIndicesMaiorQueThreshold = geraItem[i];                 
                geraItemFinal.push_back(auxIndicesMaiorQueThreshold);
                /*
                * O geraItemPar tem a função de guardar todas as combinações possíveis e válidas
                * seja ela de 2, 3 ou mais membros.
                * O objetivo é retornar essa matriz possibilitando a criação de regras com 
                * várias quantidades de antecedentes
                */
                if(geraItem[i].size()< 10)
                    geraItemPar.push_back(auxIndicesMaiorQueThreshold);
                auxIndicesMaiorQueThreshold.clear();
          //      cout<<"\nvalorSignificancia da outra combinação "<<valorSignificancia<<endl;
            }
            matrizPertinenciaAux.clear();
        } 
        
        /*
         * Verifico se a matriz geraItemFinal possue elementos onde os valores fixos de cada item são diferentes.
         * Pois se existir, não dá para formar novos conjuntos de itens,
         * e esse é retornado para a função chamadora. Outro caso para retorno é se os trios não
         * possuem valores de limiar válidos. 
         * Caso contrário, as combinações
         * para novas gerações são realizadas.
         * Lembrete:
         * Matriz nova sem validação = geraItem;
         * Matriz nova com validação = geraItemFinal;
         */
        cout<<"Imprimindo  geraItemFinal"<<endl;
        for(int i=0;i<geraItemFinal.size();i++){
            for(int j=0; j< geraItemFinal[i].size();j++){
                cout<<geraItemFinal[i][j]<<" ";
            }
            cout<<endl;
        }
        if(geraItemFinal.size()==0){//Significa que nenhum trio é válido, neste caso aceita os pares válidos
           geraItemFinal = indicesMaiorQueThreshold;
        }else{
            if(geraItemFinal.size()>1){
                for(int i=0; i< geraItemFinal.size();i++){

                    for(int k=0;k<geraItemFinal[i].size()-1;k++){
                        vetorAuxiliar.push_back(geraItemFinal[i][k]);
                    }

                    for(int j=i+1; j<geraItemFinal.size(); j++){
                        for(int k=0;k<geraItemFinal[i].size()-1;k++){
                            vetorAuxiliarProx.push_back(geraItemFinal[j][k]);
                        }

                        if(vetorAuxiliar == vetorAuxiliarProx){
                            contaIndicesIguais++;
                            break;//basta ser igual uma vez
                        }
                        vetorAuxiliarProx.clear();
                    }
                }
            }
        }
        
        if(contaIndicesIguais != 0){
            indicesMaiorQueThreshold.clear();
            indicesMaiorQueThreshold = geraItemFinal;
            geraItem.clear();
            geraItemFinal.clear();
            vetorAuxiliar.clear();
            vetorAuxiliarProx.clear();
            matrizAuxiliar.clear();
            auxIndicesMaiorQueThreshold.clear();
        }
        
    }while(contaIndicesIguais != 0);
    
    /*
     * Se contaIndicesIguais == 0 significa que todas as combinações possíveis
     * foram realizadas. O geraItemPar tem todas as combinações possíveis, com 
     * quantidades de elementos distintos. Portanto, retornar-se-á a matriz geraItemPar,
     * o vetor de grau de significância e limpa os vectors
     */
    matrizPertinenciaAux.clear();
    /*
    cout<<"Imprimindo  geraItemPar"<<endl;
    for(int i=0;i<geraItemPar.size();i++){
        for(int j=0; j< geraItemPar[i].size();j++){
            cout<<geraItemPar[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=0; i<geraItemPar.size(); i++){
        for(int j=0; j<geraItemPar[i].size(); j++){
            indice = geraItemPar[i][j];
            matrizPertinenciaAux.push_back(matrizPertinencia[indice]);
        }
        valorSignificancia = CalculaSignificanciaLargeItens(matrizPertinenciaAux);
      //  cout<<"\nvalorSignificancia "<<valorSignificancia<<endl;
        vetorSignigicanciaDosConjuntos.push_back(valorSignificancia);
        matrizPertinenciaAux.clear();
    }
    
    matrizPertinenciaAux.clear();
    indicesMaiorQueThreshold.clear();
    geraItem.clear();
    geraItemFinal.clear();
    vetorAuxiliar.clear();
    vetorAuxiliarProx.clear();
    matrizPertinenciaAux.clear();
    auxIndicesMaiorQueThreshold.clear();
    
    return geraItemPar;
    
}

vector<double> IndAssReFuzzy::CriaMatrizComValoresCabecalhoVariaveisNum(vector<vector <double> > tabelaPertinencia, int posicaoColunaPertinencia, double limiarConf){
    
    vector<double> pertinenciaBaixo, pertinenciaVazia;
    vector<double> pertinenciaMedio;
    vector<double> pertinenciaAlto;
       
    if(posicaoColunaPertinencia == 0){
        for(int ii=0;ii< tabelaPertinencia.size();ii++){
            if(tabelaPertinencia[ii][0] >= limiarConf)
                pertinenciaBaixo.push_back(tabelaPertinencia[ii][0]);
        }
    }else{
        if(posicaoColunaPertinencia == 1){
            for(int ii=0;ii< tabelaPertinencia.size();ii++){
                if(tabelaPertinencia[ii][1] >= limiarConf)
                    pertinenciaMedio.push_back(tabelaPertinencia[ii][1]);
            }
        }else{
                if(posicaoColunaPertinencia == 2){
                    for(int ii=0;ii< tabelaPertinencia.size();ii++){
                        if(tabelaPertinencia[ii][2] >= limiarConf)
                            pertinenciaAlto.push_back(tabelaPertinencia[ii][2]);
                    }
                }
            }
        }

    if(pertinenciaBaixo.size()!=0){
        return pertinenciaBaixo;
    }else{
        if(pertinenciaMedio.size()!=0){
            return pertinenciaMedio;
        }else{
            if(pertinenciaAlto.size()!=0){
                return pertinenciaAlto;
            }else{
                return pertinenciaVazia;
            }
        }
    }
    
}

vector<double> IndAssReFuzzy::CriaVetorComValoresVariaveisCategoricas(vector<string> colunaEmT, string valorNaTabelaT){
    
    /*
     * Como o valor para os campos categóricos são 1, eles sempre estarão de acordo com o valor do limiar,
     * portanto, esse método tem apenas a função de verificar quantos valores categóricos iguais ao selecionado, 
     * existem na tabela de Transação. E retorna para o método que o chamou um vetor com os valores de pertinencia
     * dos campos iguais ao selelcionado.
    */
    vector<double>pertCategorica;
    for(int i=0;i<colunaEmT.size();i++){
        if(colunaEmT.at(i)== valorNaTabelaT){
            pertCategorica.push_back(1);
        }
    }
        
    return pertCategorica;
}

double IndAssReFuzzy::significancia(vector<double> retornoC1, vector<vector<double> > retornoC2){
    
    /*
     * 'X é A' é satisfeito significa que existe quantidade de registros suficientes para
     * contribuir seus votos aos pares atributo/conjunto Fuzzy. E a soma desses votos é maior que o limiar
     * w.
     */
    double significancia_XA, somatorioVotos, somatorioTotal=0;
    int tamanho = retornoC2[0].size();
    
    if(retornoC2.size()==1){
        for(int j=0; j< retornoC2[0].size(); j++){
            somatorioVotos = retornoC1[j] * retornoC2[0][j];
            somatorioTotal = somatorioTotal + somatorioVotos;
        } 
    }else{
        for(int i=0; i<tamanho; i++){

        somatorioVotos = retornoC1.at(i);
        //Multiplicando o elemento antecedente com todos os consequentes da mesma linha
            for(int j=0; j<retornoC2.size();j++){
                somatorioVotos = somatorioVotos *retornoC2[j][i];
            }
            //Após multiplicar os elementos das linhas, realiza a soma entre elas
            somatorioTotal = somatorioTotal + somatorioVotos;
        }
    }
    significancia_XA = somatorioTotal/tamanho;
    
    return significancia_XA;
}

vector<vector<int> > IndAssReFuzzy::CalculaGrauCerteza(vector<int> indiceAtributoLI, vector <vector< int> > mAntecedentes, vector <string> cabecalhoLargeItemSets, vector <int> indiceLargeItemSets, vector<int> indicePosicaoPertinencia, vector< vector<double> > somatorioPertLI, double thresholdGrauCert, vector<double> &vGrauCertezaRI,vector<vector <int> > &mPosicaoPertinencia, vector<vector <string> >  &descRegrasValidas, double valorSignificanciaZC, vector<int> &vPosPertValorDiferente, vector<int> &vIndElementoDiferente, vector<string> &vetorValorDiferente){

    double valorGrauCerteza, significanciaXA; 
    int contaRegraInteressante=0, contaValorDiferente=0;
    vector<string> vetorNomes, regrasValidas;
    vector<int> vPosicaoPertinencia,vRegrasInteressantes;
    vector<double> grauCerteza;
    vector<vector <double> > PertinenciasXA,somatorioConferencia;
    vector<vector<int> > mRegrasInteressantes;
    vector<vector<string> > descRegraInteressante;
       
    
    /*
     * Após receber a significancia do conjunto <X,A>, calcule a significancia de <Y,B>.
     * O cálculo do grau de certeza é Certainty = significancia of <Z,C> / Significancia of <X,A>.
     * 
     * Realizando o cálculo da significância de <X,A>
     * Selecionando a matriz de pertinencia conforme posição do valor da regra a ser gerada
     */
    //Alimentando a matriz de pertinencia do grande conjunto de regras
    
    int indiceCalc = 0;
    for(int i=0;i<mAntecedentes.size(); i++){
        for(int j=0; j<mAntecedentes[i].size();j++){
            for(int k=0; k<indiceLargeItemSets.size();k++){
                if(mAntecedentes[i][j] == indiceLargeItemSets[k]){
                    indiceCalc = indiceAtributoLI.at(k);
                    break;
                }
            }
        PertinenciasXA.push_back(somatorioPertLI[indiceCalc]);
        somatorioConferencia.push_back(somatorioPertLI[indiceCalc]);    
        }
        
        significanciaXA = CalculaSignificanciaLargeItens(PertinenciasXA);
        
        //Calculando o grau de certeza e guardando no vetor grauCerteza, o referente de cada regra da matrizAntecedentes
        valorGrauCerteza = valorSignificanciaZC/significanciaXA;
        grauCerteza.push_back(valorGrauCerteza);
        PertinenciasXA.clear();
    }
    /*
    for(int i=0;i<mAntecedentes.size(); i++){
        for(int j=0; j<mAntecedentes[i].size();j++){
            PertinenciasXA.push_back(somatorioPertLI[mAntecedentes[i][j]]);
            somatorioConferencia.push_back(somatorioPertLI[mAntecedentes[i][j]]);
        }
        
        significanciaXA = CalculaSignificanciaLargeItens(PertinenciasXA);
        
        //Calculando o grau de certeza e guardando no vetor grauCerteza, o referente de cada regra da matrizAntecedentes
        valorGrauCerteza = valorSignificanciaZC/significanciaXA;
        grauCerteza.push_back(valorGrauCerteza);
        PertinenciasXA.clear();
    }
    */
    
     /*
     * Verifica qual regra possue grau de certeza maior que o limiar
     */
      
    for(int i=0; i<grauCerteza.size() ;i++){
        if(grauCerteza.at(i) >= thresholdGrauCert){
            cout<<"\ngrauCerteza "<<grauCerteza.at(i)<<endl;
            contaRegraInteressante++;
            vRegrasInteressantes = mAntecedentes[i];
            vGrauCertezaRI.push_back(grauCerteza.at(i));
            
            //Alimentando a matriz de cabeçalho e posição de pertinência dos antecedentes
            for(int k=0; k<indiceLargeItemSets.size();k++){
                for(int ii=0;ii<vRegrasInteressantes.size(); ii++){
                    if(indiceLargeItemSets[k] == vRegrasInteressantes.at(ii)){
                        vetorNomes.push_back(cabecalhoLargeItemSets.at(k));
                        vPosicaoPertinencia.push_back(indicePosicaoPertinencia.at(k));
                    }else
                    {
                        contaValorDiferente++;
                    }
                }
                if(contaValorDiferente == vRegrasInteressantes.size()){
                    vetorValorDiferente.push_back(cabecalhoLargeItemSets.at(k));
                    vPosPertValorDiferente.push_back(indicePosicaoPertinencia.at(k));
                    vIndElementoDiferente.push_back(indiceLargeItemSets.at(k));
                    
                }
                contaValorDiferente=0;
            }
            /*
            //Imprimindo GrauCerteza 
            cout<<"\nImprimindo vetorNomes\n";
            for(int i=0; i<vetorNomes.size() ;i++){
                 cout<<vetorNomes.at(i)<< " ";
             }cout<<endl;
            
            cout<<"\nImprimindo vPosicaoPertinencia\n";
            for(int i=0; i<vPosicaoPertinencia.size() ;i++){
                 cout<<vPosicaoPertinencia.at(i)<< " ";
            }cout<<endl;
            */
            descRegraInteressante.push_back(vetorNomes);
            vetorNomes.clear();
            mPosicaoPertinencia.push_back(vPosicaoPertinencia);
            vPosicaoPertinencia.clear();
        }
                       
        if(contaRegraInteressante!=0){
            mRegrasInteressantes.push_back(vRegrasInteressantes);
            vRegrasInteressantes.clear();
            contaRegraInteressante=0;
        }
        
    }
    //Se não tiver nenhuma regra interessa, o método é abordado
     
        if(mRegrasInteressantes.size()==0){
            cout<<"\nNenhuma regra foi interessante.\n";
            cout<<"Favor ajustar os parâmetros\n";
            exit(1);
        }
     
    //Descrevendo as regras
    for(int i=0; i< descRegraInteressante.size();i++){
         regrasValidas.push_back("If ");
         for(int j=0; j<descRegraInteressante[i].size();j++){
            regrasValidas.push_back(descRegraInteressante[i][j]);
            if(j < (descRegraInteressante[i].size()-1)){
                regrasValidas.push_back(" and ");
            }
        }
        //regrasValidas.push_back(" então " + vetorValorDiferente.at(i));
        descRegrasValidas.push_back(regrasValidas);
        regrasValidas.clear();
    }
    /*
     cout<<"Imprimindo descrição da regra\n";
     for(int i=0; i< descRegrasValidas.size();i++){
         for(int j=0;j<descRegrasValidas[i].size();j++){
              cout<< descRegrasValidas[i][j]<<" ";
         }cout<<endl;
     }
    */
    return mRegrasInteressantes;
    
}

vector<vector<int> > IndAssReFuzzy::CalculaGrauCertezaMaisItens(vector <vector< int> > mAntecedentesAceitos, vector <string> cabecalhoLargeItemSetsAceitos, vector <int> indiceLargeItemSetsOriginal, vector <int> indiceLargeItemSetsAceitos, vector<int> indicePosicaoPertinenciaAceitos, vector< vector<double> > somatorioPertLIAceitos, double thresholdGrau, vector<double> &vGrauCertezaRISelec,vector<vector <int> > &mPosicaoPertinenciaSelec, vector<vector <string> >  &descRegrasValidasSelec, double valorSignifZC, vector<int> &vPosPertValorResto, vector<int> &vIndElementoResto, vector<string> &vetorValorDiferente){

    double valorGrauCerteza, significanciaXA; 
    int contaRegraInteressante=0, contaValorDiferente=0;
    vector<string> vetorNomes, regrasValidas;
    vector<int> vPosicaoPertinencia,vRegrasInteressantes;
    vector<double> grauCerteza;
    vector<vector <double> > PertinenciasXA;
    vector<vector<int> > mRegrasInteressantes;
    vector<vector<string> > descRegraInteressante;
       
    
    /*
     * Após receber a significancia do conjunto <X,A>, calcule a significancia de <Y,B>.
     * O cálculo do grau de certeza é Certainty = significancia of <Z,C> / Significancia of <X,A>.
     * 
     * Realizando o cálculo da significância de <X,A>
     * Selecionando a matriz de pertinencia conforme posição do valor da regra a ser gerada
     */
    //Alimentando a matriz de pertinencia do grande conjunto de regras
    for(int i=0;i<mAntecedentesAceitos.size(); i++){
        for(int j=0; j<mAntecedentesAceitos[i].size();j++){
            PertinenciasXA.push_back(somatorioPertLIAceitos[mAntecedentesAceitos[i][j]]);
        }
        
        significanciaXA = CalculaSignificanciaLargeItens(PertinenciasXA);
        
        //Calculando o grau de certeza e guardando no vetor grauCerteza, o referente de cada regra da matrizAntecedentes
        valorGrauCerteza = valorSignifZC/significanciaXA;
        //cout<<"\nvalorGrauCerteza "<<valorGrauCerteza<<endl;
        grauCerteza.push_back(valorGrauCerteza);
        PertinenciasXA.clear();
    }
    
    
     /*
     * Verifica qual regra possue grau de certeza maior que o limiar
     */
    for(int i=0; i<grauCerteza.size() ;i++){
        if(grauCerteza.at(i) >= thresholdGrau){
            contaRegraInteressante++;
            vGrauCertezaRISelec.push_back(grauCerteza.at(i));
            
            for(int ii=0;ii<mAntecedentesAceitos[i].size();ii++){
                vRegrasInteressantes.push_back(indiceLargeItemSetsOriginal[mAntecedentesAceitos[i][ii]]);
            }
            /*
            cout<<"vRegrasInteressantes "<<endl;
            for(int ii=0;ii<vRegrasInteressantes.size();ii++){
                cout<<vRegrasInteressantes.at(ii)<<" ";
            }cout<<endl;
        */
            //Alimentando a matriz de cabeçalho e posição de pertinência dos antecedentes
            for(int k=0; k<indiceLargeItemSetsAceitos.size();k++){
                for(int ii=0;ii<vRegrasInteressantes.size(); ii++){
                    if(indiceLargeItemSetsAceitos[k] == vRegrasInteressantes.at(ii)){
                        vetorNomes.push_back(cabecalhoLargeItemSetsAceitos.at(k));
                        vPosicaoPertinencia.push_back(indicePosicaoPertinenciaAceitos.at(k));
                    }else
                    {
                        contaValorDiferente++;
                    }
                }
                if(contaValorDiferente == vRegrasInteressantes.size()){
                    vetorValorDiferente.push_back(cabecalhoLargeItemSetsAceitos.at(k));
                    vPosPertValorResto.push_back(indicePosicaoPertinenciaAceitos.at(k));
                    vIndElementoResto.push_back(indiceLargeItemSetsAceitos.at(k));
                }
                contaValorDiferente=0;
            }
    
            /*
            //Imprimindo GrauCerteza 
            cout<<"\nImprimindo vetorNomes\n";
            for(int i=0; i<vetorNomes.size() ;i++){
                 cout<<vetorNomes.at(i)<< " ";
             }cout<<endl;
            
            cout<<"\nImprimindo vPosicaoPertinencia\n";
            for(int i=0; i<vPosicaoPertinencia.size() ;i++){
                 cout<<vPosicaoPertinencia.at(i)<< " ";
            }cout<<endl;
            */
            descRegraInteressante.push_back(vetorNomes);
            vetorNomes.clear();
            mPosicaoPertinenciaSelec.push_back(vPosicaoPertinencia);
            vPosicaoPertinencia.clear();
        }
                       
        if(contaRegraInteressante!=0){
            mRegrasInteressantes.push_back(vRegrasInteressantes);
            vRegrasInteressantes.clear();
            contaRegraInteressante=0;
        }
        
    }
    //Se não tiver nenhuma regra interessa, o método é abordado
     /*
        if(mRegrasInteressantes.size()==0){
            cout<<"\nNenhuma regra foi interessante.\n";
            cout<<"Favor ajustar os parâmetros\n";
            exit(1);
        }
     */
    
    //Descrevendo as regras
    if(mRegrasInteressantes.size()!=0){
        for(int i=0; i< descRegraInteressante.size();i++){
            regrasValidas.push_back("If ");
            for(int j=0; j<descRegraInteressante[i].size();j++){
               regrasValidas.push_back(descRegraInteressante[i][j]);
               if(j < (descRegraInteressante[i].size()-1)){
                   regrasValidas.push_back(" and ");
               }
           }
           //regrasValidas.push_back(" então " );
           //regrasValidas.push_back(vetorValorDiferente.at(i));
           descRegrasValidasSelec.push_back(regrasValidas);
           regrasValidas.clear();
       }
       /*
        cout<<"Imprimindo descrição da regra\n";
        for(int i=0; i< descRegrasValidas.size();i++){
            for(int j=0;j<descRegrasValidas[i].size();j++){
                 cout<< descRegrasValidas[i][j]<<" ";
            }cout<<endl;
        }
       */
    }
    return mRegrasInteressantes;
    
}

double IndAssReFuzzy::SignificanciaApenasUmaColuna(vector<double> vetorPertinenciaASerCalculada){
    
    double significanciaUnicaColuna;
    double somaUnicaColuna=0;
    int contaVoto =0;
    
    for(int i=0; i<vetorPertinenciaASerCalculada.size();i++){
        somaUnicaColuna = somaUnicaColuna + vetorPertinenciaASerCalculada.at(i);
        contaVoto++;
    }
    significanciaUnicaColuna = somaUnicaColuna/contaVoto;
        
    return significanciaUnicaColuna;
}

 vector<vector<int> >  IndAssReFuzzy::RetornaPosicaoDosElementosT(char nomeBaseOriginal[50], vector<string> atributoSCj, vector<double> pertinenciaSCj){
    
    utilitarios ut;
    utilitarios::Transacao T;
    int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0, c10=0;
    int c11=0, c12=0, c13=0, c14=0, c15=0, c16=0, c17=0, c18=0, c19=0, c20=0;
    int c21=0, c22=0, c23=0, c24=0, c25=0, c26=0, c27=0, c28=0, c29=0, c30=0;
    int c31=0, c32=0, c33=0, c34=0, c35=0, c36=0, c37=0, c38=0, c39=0, c40=0, c41=0;
        
    T= ut.GeraStruturaTransacaoItens(nomeBaseOriginal);
        
    vector<int> indicesNaoVazios,vetorAuxiliar;
    vector< vector<int> > tabelaIndices, tabelaIndicesFinal;
    
    //Verificando em qual coluna pertence o item
    for(int i=0; i<atributoSCj.size(); i++){
        
        for(int j=0; j< T.srv_serror_rate.size();j++){
            
            if((atributoSCj.at(i) == T.duracao.at(j))&&(c1 ==0)){
                indicesNaoVazios.push_back(0); 
                c1++;
            }
            if((atributoSCj.at(i) == T.protocolo.at(j))&&(c2 ==0)){
                indicesNaoVazios.push_back(1); 
                c2++;
            }
            if((atributoSCj.at(i) == T.servico.at(j))&&(c3 ==0)){
                indicesNaoVazios.push_back(2); 
                c3++;
            }
            if((atributoSCj.at(i) == T.flag.at(j))&&(c4 ==0)){
                indicesNaoVazios.push_back(3); 
                c4++;
            }
            if((atributoSCj.at(i) == T.src_bytes.at(j))&&(c5 ==0)){
                indicesNaoVazios.push_back(4); 
                c5++;
            }
            if((atributoSCj.at(i) == T.dst_bytes.at(j))&&(c6 ==0)){
                indicesNaoVazios.push_back(5); 
                c6++;
            }
            if((atributoSCj.at(i) == T.land.at(j))&&(c7 ==0)){
                indicesNaoVazios.push_back(6); 
                c7++;
            }
            if((atributoSCj.at(i) == T.wrong_fragment.at(j))&&(c8 ==0)){
                indicesNaoVazios.push_back(7); 
                c8++;
            }
            if((atributoSCj.at(i) == T.urgente.at(j))&&(c9 ==0)){
                indicesNaoVazios.push_back(8);
                c9++;
            }
            if((atributoSCj.at(i) == T.hot.at(j))&&(c10 ==0)){
                indicesNaoVazios.push_back(9); 
                c10++;
            }
            if((atributoSCj.at(i) == T.num_faleid_logins.at(j))&&(c11 ==0)){
                indicesNaoVazios.push_back(10);
                c11++;
            }
            if((atributoSCj.at(i) == T.logged_in.at(j))&&(c12 ==0)){
                indicesNaoVazios.push_back(11);
                c12++;
            }
            if((atributoSCj.at(i) == T.num_compromised.at(j))&&(c13 ==0)){
                indicesNaoVazios.push_back(12);
                c13++;
            }
            if((atributoSCj.at(i) == T.root_shell.at(j))&&(c14 ==0)){
                indicesNaoVazios.push_back(13);
                c14++;
            }
            if((atributoSCj.at(i) == T.su_attempted.at(j))&&(c15 ==0)){
                indicesNaoVazios.push_back(14);
                c15++;
            }
            if((atributoSCj.at(i) == T.num_root.at(j))&&(c16 ==0)){
                indicesNaoVazios.push_back(15);
                c16++;
            }
            if((atributoSCj.at(i) == T.num_file_creatinos.at(j))&&(c17 ==0)){
                indicesNaoVazios.push_back(16);
                c17++;
            }
            if((atributoSCj.at(i) == T.num_shells.at(j))&&(c18 ==0)){
                indicesNaoVazios.push_back(17);
                c18++;
            }
            if((atributoSCj.at(i) == T.num_access_files.at(j))&&(c19 ==0)){
                indicesNaoVazios.push_back(18);
                c19++;
            }
            if((atributoSCj.at(i) == T.num_outbound_cmds.at(j))&&(c20 ==0)){
                indicesNaoVazios.push_back(19);
                c20++;
            }
            if((atributoSCj.at(i) == T.is_hot_login.at(j))&&(c21 ==0)){
                indicesNaoVazios.push_back(20);
                c21++;
            }
            if((atributoSCj.at(i) == T.is_guest_login.at(j))&&(c22 ==0)){
                indicesNaoVazios.push_back(21);
                c22++;
            }
            if((atributoSCj.at(i) == T.count.at(j))&&(c23 ==0)){
                indicesNaoVazios.push_back(22);
                c23++;
            }
            if((atributoSCj.at(i) == T.srv_count.at(j))&&(c24 ==0)){
                indicesNaoVazios.push_back(23);
                c24++;
            }
            if((atributoSCj.at(i) == T.serror_rate.at(j))&&(c25 ==0)){
                indicesNaoVazios.push_back(24);
                c25++;
            }
            if((atributoSCj.at(i) == T.srv_serror_rate.at(j))&&(c26 ==0)){
                indicesNaoVazios.push_back(25);
                c26++;
            }
            if((atributoSCj.at(i) == T.rerror_rate.at(j))&&(c27 ==0)){
                indicesNaoVazios.push_back(26); 
                c27++;
            }
            if((atributoSCj.at(i) == T.srv_rerror_rate.at(j))&&(c28 ==0)){
                indicesNaoVazios.push_back(27); 
                c28++;
            }
            if((atributoSCj.at(i) == T.same_srv_rate.at(j))&&(c29 ==0)){
                indicesNaoVazios.push_back(28); 
                c29++;
            }
            if((atributoSCj.at(i) == T.diff_srv_rate.at(j))&&(c30 ==0)){
                indicesNaoVazios.push_back(29); 
                c30++;
            }
            if((atributoSCj.at(i) == T.srv_diff_host_rate.at(j))&&(c31 ==0)){
                indicesNaoVazios.push_back(30); 
                c31++;
            }
            if((atributoSCj.at(i) == T.dst_host_count.at(j))&&(c32 ==0)){
                indicesNaoVazios.push_back(31); 
                c32++;
            }
            if((atributoSCj.at(i) == T.dst_host_srv_count.at(j))&&(c33 ==0)){
                indicesNaoVazios.push_back(32); 
                c33++;
            }
            if((atributoSCj.at(i) == T.dst_host_same_srv_rate.at(j))&&(c34 ==0)){
                indicesNaoVazios.push_back(33); 
                c34++;
            }
            if((atributoSCj.at(i) == T.dst_host_diff_srv_rate.at(j))&&(c35 ==0)){
                indicesNaoVazios.push_back(34); 
                c35++;
            }
            if((atributoSCj.at(i) == T.dst_host_same_src_port_rate.at(j))&&(c36 ==0)){
                indicesNaoVazios.push_back(35); 
                c36++;
            }
            if((atributoSCj.at(i) == T.dst_host_srv_diff_host_rate.at(j))&&(c37 ==0)){
                indicesNaoVazios.push_back(36); 
                c37++;
            }
            if((atributoSCj.at(i) == T.dst_host_serror_rate.at(j))&&(c38 ==0)){
                indicesNaoVazios.push_back(37); 
                c38++;
            }
            if((atributoSCj.at(i) == T.dst_host_srv_serror_rate.at(j))&&(c39 ==0)){
                indicesNaoVazios.push_back(38); 
                c39++;
            }
            if((atributoSCj.at(i) == T.dst_host_rerror_rate.at(j))&&(c40 ==0)){
                indicesNaoVazios.push_back(39); 
                c40++;
            }
            if((atributoSCj.at(i) == T.dst_host_srv_rerror_rate.at(j))&&(c41 ==0)){
                indicesNaoVazios.push_back(40); 
                c41++;
            }
        }
        
        /*
         * Conferindo se há valor binário (considerado categórico) para pertinências de valores numéricos menor 1.
         * Caso haja, esse será excluído, pois para ser considerado valores categóricos, sua pertinência deve 
         * ser igual a 1.
         */ 
        for(int jj =0; jj<indicesNaoVazios.size();jj++){
            if((pertinenciaSCj.at(i)!= 1)){
                if((indicesNaoVazios.at(jj)==6)||(indicesNaoVazios.at(jj)==11)||(indicesNaoVazios.at(jj)==13)||(indicesNaoVazios.at(jj)==14)||(indicesNaoVazios.at(jj)==19)||(indicesNaoVazios.at(jj)==20)||(indicesNaoVazios.at(jj)==21)){
                    indicesNaoVazios.erase(indicesNaoVazios.begin()+jj);
                    jj--;
                }
            }
        }
        tabelaIndices.push_back(indicesNaoVazios);
        indicesNaoVazios.clear();
        c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0, c10=0;
        c11=0, c12=0, c13=0, c14=0, c15=0, c16=0, c17=0, c18=0, c19=0, c20=0;
        c21=0, c22=0, c23=0, c24=0, c25=0, c26=0, c27=0, c28=0, c29=0, c30=0;
        c31=0, c32=0, c33=0, c34=0, c35=0, c36=0, c37=0, c38=0, c39=0, c40=0, c41=0;
    }      
    /*
     * Nesse momento excluir os valores de índices repetidos
     */
    for(int k=0;k<tabelaIndices.size();k++){

        vetorAuxiliar = tabelaIndices[k];
       
        //Limpando o vetor
        for(int i=0;i<vetorAuxiliar.size();i++){
            for(int ii=i+1;ii<vetorAuxiliar.size();ii++){
                if(vetorAuxiliar.at(i)==vetorAuxiliar.at(ii)){
                    vetorAuxiliar.erase(vetorAuxiliar.begin()+ii);
                    ii--;
                }
            }
        }
        
        //Ordenando o vetor auxiliar
        sort(vetorAuxiliar.begin(), vetorAuxiliar.end());
        
        //Atribuir para a matriz final
        tabelaIndicesFinal.push_back(vetorAuxiliar);
        vetorAuxiliar.clear();
    }
    //Limpando os vectors sem uso até o momento
    indicesNaoVazios.clear();
    vetorAuxiliar.clear();
    tabelaIndices.clear();
    
    return tabelaIndicesFinal;
}

vector<string> IndAssReFuzzy::RetornaDadoCategorico(char BaseOriginal[50], int indiceNaColunaT){
    
    utilitarios ut;
    utilitarios::Transacao T;
    vector<string> colunaDoElementoCategorico;
        
    T= ut.GeraStruturaTransacaoItens(BaseOriginal);
    
    
    switch (indiceNaColunaT){
        case 1:
            colunaDoElementoCategorico = T.protocolo;
            break;
        case 2:
            colunaDoElementoCategorico = T.servico;
            break;
        case 3:
            colunaDoElementoCategorico = T.flag;
            break;
        case 6:
            colunaDoElementoCategorico = T.land;
            break;
        case 11:
            colunaDoElementoCategorico = T.logged_in;
            break;
        case 13:
            colunaDoElementoCategorico = T.root_shell;
            break;
        case 14:
            colunaDoElementoCategorico = T.su_attempted;
            break;
        case 19:
            colunaDoElementoCategorico = T.num_outbound_cmds;
            break;
        case 20:
            colunaDoElementoCategorico = T.is_hot_login;
            break;
        case 21:
            colunaDoElementoCategorico = T.is_guest_login;
            break;
    }
    //cout<<"\ncolunaDoElementoCategorico "<<colunaDoElementoCategorico.size()<<endl;
    return colunaDoElementoCategorico;
}
    
vector<vector<int> > IndAssReFuzzy::matrizRegraFinal(vector< int> indElSub){
    
    vector<vector<int> > msubConjRegrasFinal;
    vector<int> vsubConjRegrasAux;
    int guardaIndice;    
    
    for(int i=0;i<indElSub.size(); i++){
        guardaIndice = indElSub.at(i);
        
        for(int j=0; j<indElSub.size(); j++){
            if(indElSub.at(j)!= guardaIndice){
                vsubConjRegrasAux.push_back(indElSub.at(j));
            }
        }
        msubConjRegrasFinal.push_back(vsubConjRegrasAux);
        vsubConjRegrasAux.clear();
    }    
    
    return msubConjRegrasFinal;
}
double IndAssReFuzzy::CalculaSignificanciaLargeItens(vector< vector<double> > largeItens){
    
    double somatorioPertinenciaZC=1.0, significanciaZC=0.0, valorFinalSignZC;
    int linha, coluna;
    
    linha = largeItens.size();
    coluna = largeItens[0].size();
    
    for(int i=0; i< coluna; i++){
        for(int j=0;j<linha; j++){
            somatorioPertinenciaZC = somatorioPertinenciaZC *(largeItens[j][i]);
        }
        significanciaZC = significanciaZC + somatorioPertinenciaZC;
        somatorioPertinenciaZC =1.0;
    }
    //Somatorio da significancia do valor do <Z,C>
    valorFinalSignZC = significanciaZC / coluna;        
       
    return valorFinalSignZC;
}