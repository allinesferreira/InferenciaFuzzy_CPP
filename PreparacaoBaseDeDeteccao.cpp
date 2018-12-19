/* 
 * File:   PreparacaoBaseDeDeteccao.cpp
 * Author: allinesf
 * 
 * Created on 2 de Novembro de 2015, 05:54
 */

#include "PreparacaoBaseDeDeteccao.h"
#include "PreparacaoDaBase.h"
#include "PreparaBase.h"
#include "utilitarios.h"
#include "GeraArquivosClasse.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

PreparacaoBaseDeDeteccao::PreparacaoBaseDeDeteccao() {
}

PreparacaoBaseDeDeteccao::PreparacaoBaseDeDeteccao(const PreparacaoBaseDeDeteccao& orig) {
}

PreparacaoBaseDeDeteccao::~PreparacaoBaseDeDeteccao() {
}

void  PreparacaoBaseDeDeteccao::PreProcessamentoBaseDeteccao(char nomeArquivoDeteccao[50]){
    
    int resposta;
    vector<string> etiquetaT;
        
    GeraArquivosClasse gac;
    PreparaBase pb;
    utilitarios ut;
        
    /*
     * PREPARAÇÃO DA BASE PARA OS TESTES
     * Fase1: Substituir a vírgula pelo espaço
     */
    
    cout<<"Deseja substituir as vírgulas por espaço na base de dados?\n";
    cin>>resposta;
    if (resposta==1){
        pb.PreparaBaseParaTeste(nomeArquivoDeteccao);
    }
    
    /*
     * Fase 2: 
     * É executado o algoritmo fuzzy c-means para gerar os valores de referência relativos
     * as regras linguísticas: baixo, médio, alto, para cada um das colunas numéricas
     */
    
    cout<<"\nGera arquivo para execução do fuzzy c-means? Digite 1 para sim."<<endl;
    cin>>resposta;
    if(resposta ==1){
        gac.GeraClassesOriginaisParaMatlab(nomeArquivoDeteccao, "corrected_mt");
        cout<<"\nExecute o fuzzy c-means no programa Matlab, logo depois digite Enter para continuar\n";
        cin.get();cin.get();
    }    
    
    /*
     * Fase 3: Gerando uma base de dados sem a etiqueta
     * Retornando o vetor etiquetas.
     */
    
    gac.RetornaVetorDeEtiquetasGerArqSemEtiqueta(nomeArquivoDeteccao, "corrected_SEtiqueta");
    
    /*
     * Fase 4: Necessária para todas as bases (tanto de treinamento, quanto a de detecção)
     * Transforma a base de dados em itens para aplicação das técnicas de fuzzy.
     */
    
    vector<string> pertinencia;
    
    cout<<"Executando o bloco de comandos para transformação da base em itens.\n";
    pertinencia.push_back("UTeste1");pertinencia.push_back("UTeste5");pertinencia.push_back("UTeste6");
    pertinencia.push_back("UTeste8");pertinencia.push_back("UTeste9");pertinencia.push_back("UTeste10");
    pertinencia.push_back("UTeste11");pertinencia.push_back("UTeste13");pertinencia.push_back("UTeste16");
    pertinencia.push_back("UTeste17");pertinencia.push_back("UTeste18");pertinencia.push_back("UTeste19");
    pertinencia.push_back("UTeste23");pertinencia.push_back("UTeste24");pertinencia.push_back("UTeste25");
    pertinencia.push_back("UTeste26");pertinencia.push_back("UTeste27");pertinencia.push_back("UTeste28");
    pertinencia.push_back("UTeste29");pertinencia.push_back("UTeste30");pertinencia.push_back("UTeste31");
    pertinencia.push_back("UTeste32");pertinencia.push_back("UTeste33");pertinencia.push_back("UTeste34");
    pertinencia.push_back("UTeste35");pertinencia.push_back("UTeste36");pertinencia.push_back("UTeste37");
    pertinencia.push_back("UTeste38");pertinencia.push_back("UTeste39");pertinencia.push_back("UTeste40");pertinencia.push_back("UTeste41");
                
    ut.TransformaCaracteristicaDeteccaoEmItem("corrected_SEtiqueta", pertinencia);
    pertinencia.clear();
    
    cout<<"\nFim da preparação de base de detecção.\n"<<endl;
}
