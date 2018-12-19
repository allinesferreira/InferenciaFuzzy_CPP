/* 
 * File:   PreparaBaseDeteccaoSAtaquesDesconhecidos.cpp
 * Author: allinesf
 * 
 * Created on 15 de Janeiro de 2016, 16:27
 */

#include "PreparaBaseDeteccaoSAtaquesDesconhecidos.h"
#include "PreparacaoBaseDeteccaoSAtaqueConhecido.h"
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


PreparaBaseDeteccaoSAtaquesDesconhecidos::PreparaBaseDeteccaoSAtaquesDesconhecidos() {
}

PreparaBaseDeteccaoSAtaquesDesconhecidos::PreparaBaseDeteccaoSAtaquesDesconhecidos(const PreparaBaseDeteccaoSAtaquesDesconhecidos& orig) {
}

PreparaBaseDeteccaoSAtaquesDesconhecidos::~PreparaBaseDeteccaoSAtaquesDesconhecidos() {
}

void  PreparaBaseDeteccaoSAtaquesDesconhecidos::PreProcessamentoAtaquesDesconhecidos(char nomeArquivoDeteccao[50]){
    
    int resposta;
    vector<string> etiquetaT;
        
    GeraArquivosClasse gac;
    PreparaBase pb;
    utilitarios ut;
    
    /*
     * PREPARAÇÃO DA BASE PARA OS TESTES
     * Fase1: Gera arquivo somente com ataques conhecidos
     */
    
    gac.GeraArquivoAtaquesConhecidos(nomeArquivoDeteccao, "Etiquetas","kddcup.data_10_percent");
    
    
    /*
    * Fase 2: Gerando uma base de dados sem a etiqueta
    * Retornando o vetor etiquetas.
    */
    
    gac.RetornaVetorDeEtiquetasGerArqSemEtiqueta("AtaquesConhecidos", "AtaquesConhecidos_SEtiqueta");
    
    /*
     * Fase 3: Necessária para todas as bases (tanto de treinamento, quanto a de detecção)
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
                
    ut.TransformaCaracteristicaDeteccaoEmItem("AtaquesConhecidos_SEtiqueta", pertinencia);
    pertinencia.clear();
    
    cout<<"\nFim da preparação de base de detecção.\n"<<endl;
}
