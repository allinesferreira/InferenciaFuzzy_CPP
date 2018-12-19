/* 
 * File:   FaseDeDeteccao.cpp
 * Author: allinesf
 * 
 * Created on 4 de Novembro de 2015, 12:13
 */

#include "FaseDeDeteccao.h"
#include "PreparacaoBaseDeDeteccao.h"
#include "utilitarios.h"
#include "IndAssReFuzzy.h"
#include "Classificacao.h"
#include "PreparacaoBaseDeteccaoSAtaqueConhecido.h"
#include "PreparaBaseDeteccaoSAtaquesDesconhecidos.h"
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <bits/stl_vector.h>

using namespace std;

FaseDeDeteccao::FaseDeDeteccao(){}

FaseDeDeteccao::FaseDeDeteccao(const FaseDeDeteccao& orig) {}

FaseDeDeteccao::~FaseDeDeteccao() {}

void FaseDeDeteccao::FaseDeteccao(double limiarPBaixa, bool ABC_Extendida, char nomeADeteccao[50], double limiarClassificacao) {
    
    
    PreparacaoBaseDeDeteccao pbd;
    Classificacao clas;
    PreparacaoBaseDeteccaoSAtaqueConhecido pbdsac;
    PreparaBaseDeteccaoSAtaquesDesconhecidos pbdsad;
    /*
     * Preparando a base de detecção para execução
     */
    //pbd.PreProcessamentoBaseDeteccao(nomeADeteccao);
    //pbdsac.PreProcessamentoAtaquesConhecidos(nomeADeteccao);
    //pbdsad.PreProcessamentoAtaquesDesconhecidos(nomeADeteccao);
    
    /*
     * Iniciando a Detecção
     */
    //clas.LerArquivoDeteccao("corrected_SEtiqueta", limiarPBaixa, ABC_Extendida);
    //clas.LerArquivoDeteccao("AtaquesConhecidos_SEtiqueta", limiarPBaixa, ABC_Extendida);
//    clas.LerArquivoDeteccao("AtaquesDesconhecidos_SEtiqueta", limiarPBaixa, ABC_Extendida);
    
    //Analisando respostas
    CalculaEstimativa("m_resposta_MM", ABC_Extendida, limiarClassificacao);
    CalculaEstimativaMamdani("MM_Mamdani", ABC_Extendida, limiarClassificacao);
    
    
}

void FaseDeDeteccao::CalculaEstimativa(char nomeArqResultado[50], bool tipoDetec_E, double limiarClas){
    
    ifstream ler;
    vector<double> resultados;
    int valor, indiceMenorValor;
    char dado;
    string resp;
    double respD, elementoMinimo;
    vector<string> rotulo, tipoConexao;
    
    Classificacao classif;
    
    ler.open(nomeArqResultado, ifstream::in);
    
    rotulo = classif.LerEtiqueta("Etiquetas");
    
    //Tratamento de erro caso os arquivos não existam
    if(!ler.is_open()){
        printf("O arquivo de resultados não existe!");
        ler.clear();
        exit(1);
    }
    
    while(true){
        
        valor=ler.tellg();
        ler.get(dado);
        
        if (ler.eof()) break;
        
        if(dado != 10){
            ler.seekg(valor);
            ler>>resp;
            stringstream converte(resp);
            converte >> respD;
            resultados.push_back(respD);
        }else{
            
            if(!tipoDetec_E){

                /*
                 * O menor valor nas seguintes posições significa:
                 *  0 - a conexão é normal;
                 *  1 - a conexão é ataque do tipo DoS;
                 *  2 - a conexão é ataque do tipo Probe;
                 *  3 - a conexão é ataque do tipo R2L;
                 *  4 - a conexão é ataque do tipo U2R. 
                 */

                vector<double> diferenteZero;
                vector<int> indiceDZero;
                /*
                for(int i=0; i< resultados.size();i++){
                    if(resultados.at(i)!=0){
                        diferenteZero.push_back(resultados.at(i));
                        indiceDZero.push_back(i);
                    }
                }
                
                if(diferenteZero.size()!= 0){
                 
                    elementoMinimo= *min_element(diferenteZero.begin(), diferenteZero.end());
                    for(int i=0; i<diferenteZero.size();i++){
                        if(elementoMinimo == diferenteZero.at(i))
                            indiceMenorValor = indiceDZero.at(i);
                    }
                 */
                elementoMinimo= *min_element(resultados.begin(), resultados.end());
                //Procurando em qual posição encontra o valor mínimo
                for(int i=0; i<resultados.size();i++){
                    if(elementoMinimo == resultados.at(i))
                        indiceMenorValor = i;
                }
                //Verificando qual tipo de conexão
                switch (indiceMenorValor)
                {
                    case 0: tipoConexao.push_back("normal."); break;
                    case 1: tipoConexao.push_back("Dos"); break;
                    case 2: tipoConexao.push_back("Probe"); break;
                    case 3: tipoConexao.push_back("R2L"); break;
                    case 4: tipoConexao.push_back("U2R"); break;
                    case 5: tipoConexao.push_back("naoIdentifica"); break;
                }
                
                resultados.clear();
               // diferenteZero.clear();
                //indiceDZero.clear();
            }else{

                /*
                 * De acordo com o artigo se o elemento mínimo for maior que o threshold então 
                 * a amostra será considerada como uma classe de conexões normais. Caso contrário será
                 * considerado uma classe de conexões anormais.
                 */
              
                
                if(resultados.at(0) >= limiarClas){
                    tipoConexao.push_back("anormal.");
                }else{
                        tipoConexao.push_back("normal.");
                    }
                resultados.clear();
                
            }
        }
    }

    //Após verificar todos os resultados, realiza-se o cálculo dos falsos positivos e negativos
    if(tipoDetec_E)
        classif.EstimativaABC_Extendida(tipoConexao, rotulo, "EstimativaABC_E", "Falso_Positivo_ABCE", "Falso_Negativo_ABCE");
    else
        classif.EstimativaABC(tipoConexao, rotulo, "EstimativaABC", "Falso_Positivo_ABC", "Falso_Negativo_ABC");
}

void FaseDeDeteccao::CalculaEstimativaMamdani(char nomeArqResultado[50], bool tipoDetec_E, double limiarClas){
    
    ifstream ler;
    vector<double> resultados;
    int valor, indiceMaiorValor;
    char dado;
    string resp;
    double respD, elementoMaximo;
    vector<double> diferenteZero;
    vector<int> indiceDZero;
    vector<string> rotulo, tipoConexao;
   // vector<vector<double> > mresultados;
    
    Classificacao classif;
    
    ler.open(nomeArqResultado, ifstream::in);
    
    rotulo = classif.LerEtiqueta("Etiquetas");
    
    //Tratamento de erro caso os arquivos não existam
    if(!ler.is_open()){
        printf("O arquivo de resultados não existe!");
        ler.clear();
        exit(1);
    }
    while(true){
        
        valor=ler.tellg();
        ler.get(dado);
        
        if (ler.eof()) break;
        
        if(dado != 10){
            ler.seekg(valor);
            ler>>resp;
            stringstream converte(resp);
            converte >> respD;
            resultados.push_back(respD);
        }else{
            //Verificando a matriz de resultados
            if(!tipoDetec_E){

                /*
                 * O menor valor nas seguintes posições significa:
                 *  0 - a conexão é normal;
                 *  1 - a conexão é ataque do tipo DoS;
                 *  2 - a conexão é ataque do tipo Probe;
                 *  3 - a conexão é ataque do tipo R2L;
                 *  4 - a conexão é ataque do tipo U2R. 
                 */
                vector<double> diferenteZero;
                vector<int> indiceDZero;
                /*
                for(int i=0; i< resultados.size();i++){
                    if(resultados.at(i)!=0){
                        diferenteZero.push_back(resultados.at(i));
                        indiceDZero.push_back(i);
                    }
                }
                */
                elementoMaximo= *max_element(resultados.begin(), resultados.end());
                for(int i=0; i<resultados.size();i++){
                    if(elementoMaximo == resultados.at(i))
                        indiceMaiorValor = i;
                }
                
               //Verificando qual tipo de conexão
                switch (indiceMaiorValor)
                {
                    case 0: tipoConexao.push_back("normal."); break;
                    case 1: tipoConexao.push_back("Dos"); break;
                    case 2: tipoConexao.push_back("Probe"); break;
                    case 3: tipoConexao.push_back("R2L"); break;
                    case 4: tipoConexao.push_back("U2R"); break;
                    case 5: tipoConexao.push_back("naoIdentifica"); break;
                }
                
                resultados.clear();
                //diferenteZero.clear();
                //indiceDZero.clear();
                
            }else{

                /*
                 * De acordo com o artigo se o elemento mínimo for maior que o threshold então 
                 * a amostra será considerada como uma classe de conexões normais. Caso contrário será
                 * considerado uma classe de conexões anormais.
                 */
                resultados.size();
                if(resultados.at(0) >= limiarClas){
                    tipoConexao.push_back("anormal.");
                }else{
                    tipoConexao.push_back("normal.");
                }   
            }
        }
    }
    
    //Fechando o arquivo
    ler.close();

    
    //Após verificar todos os resultados, realiza-se o cálculo dos falsos positivos e negativos
    if(tipoDetec_E)
        classif.EstimativaABC_Extendida(tipoConexao, rotulo, "EstimativaMamdani_E", "Falso_Positivo_M_E", "Falso_Negativo_M_E");
    else
        classif.EstimativaABC(tipoConexao, rotulo, "EstimativaMamdaniABC", "Falso_Positivo_MamdaniABC", "Falso_Negativo_MamdaniABC");
}
