#include "PreparaBase.h"
#include "PreparacaoBaseDeDeteccao.h"
#include "utilitarios.h"
#include "GeraArquivosClasse.h"
#include "IndAssReFuzzy.h"
#include "Classificacao.h"
#include "PreparacaoDaBase.h"
#include "FaseDeTreinamento.h"
#include "Guloso.h"
#include "FaseDeDeteccao.h"
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main( ) {
    
    vector<double> MM_t_R;
    vector<vector<double> > valoresRFinaisIAF;
    vector<vector<string> > descricaoRFinaisIAF;
  //  double thresholdClassificacao = 0.488, thresholdValoresBaixos = 0.02;
    double thresholdClassificacao = 0.478, thresholdValoresBaixos = 0.05;
    bool preproc = false, classifica = true, treinamento = false, abcExt = true;
    int classe = 1;
    
        
    PreparacaoDaBase pdb;
    Classificacao clas;
    FaseDeTreinamento ft;
    FaseDeDeteccao fd;
    
    
    /*
     * Pré-processamento 
     * 
     */
   // if(preproc)
       // pdb.PreProcessamento();
    
    /*
     * INICIANDO FASE DE TREINAMENTO
     * Os comandos aqui descritos devem ser executados para os dois arquivos classes
     */
    //if(treinamento)
      //  ft.Treinamento(classe);
    
    
    //INICIANDO FASE DE DETECÇÃO
    if(classifica)
        fd.FaseDeteccao(thresholdValoresBaixos, abcExt, "corrected", thresholdClassificacao);
    
    cout<<"\nFIM DA EXECUÇÃO\n";
    return 0;
}

