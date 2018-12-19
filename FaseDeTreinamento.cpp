
/* 
 * File:   FaseDeTreinamento.cpp
 * Author: allinesf
 * 
 * Created on 9 de Junho de 2015, 14:40
 * Algumas observações:
 * O limiar de valor baixo define a quantidade de valores de pertinência iguais em
 * colunas distintas. Quanto mais colunas possuírem valores de pertinência iguais,
 * maior será a quantidade de atributos a serem avaliados nas regras.
 * Limiar de suporte e confiança do Apriori - definem a quantidade de elementos frequentes
 * na base de dados, quanto maior esses limiares, menor a quantidade de hyperarestas, isso
 * faz com que as regras a serem duplicadas também sejam menores. 
 * Limiar de hyperarestas definem a porcentagem aceita como um elemento hyperEdge, quanto maior essa
 * porcentagem menor a quantidade de elementos hyperEdge
 * thresholdRegraInducao é o valor mínimo referente ao grau de significância quanto maior esse valor
 * maior será a filtragem dos conjuntos de itens aceitos para a geração das regras. Ele representa
 * o suporte para o fuzzy
 * thresholdGrauCerteza esse limiar filtra as regras aceitas, quanto maior o limiar, menor será
 * a quantidade de regras aceitas. Esse limiar representa a confiança para o fuzzy.
 * 
 */

#include "FaseDeTreinamento.h"
#include "PreparaBase.h"
#include "utilitarios.h"
#include "GeraArquivosClasse.h"
#include "IndAssReFuzzy.h"
#include "Classificacao.h"
#include "PreparacaoDaBase.h"
#include "Guloso.h"
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

FaseDeTreinamento::FaseDeTreinamento() {
}

FaseDeTreinamento::FaseDeTreinamento(const FaseDeTreinamento& orig) {
}

FaseDeTreinamento::~FaseDeTreinamento() {
}

void FaseDeTreinamento::Treinamento(int classeEmExecucao){
    vector<string> vetorSemRepeticao;
    vector<int> suconjuntoPRInducao, indicesDosHyperEdge, consequentePosPert, consequenteInd;
    vector<int> consequentePosPertE, consequenteIndE;
    vector<double> pertinenciaSub, MM_t_R, grauCertezaRegrasFinais;
    vector<string> atributoSub, nomesHEdge, consequenteCab, consequenteCabE;
    vector<string> itemSubEncontrado, elementosSubConjunto, itensSubConj;
    vector<vector<string> > descricaoRegrasFinaisIAF, mElementosArestas, descricaoAntecedentesR, hyperGrafoFinal, associacaoHESRepeticao;
    vector<vector<int> > indAtribGrandeCjSelec, indiceGrandeGonjSelecionado, indicesElementosSubSelec, valoresRegrasFinaisIAF, posPertinenciaRegrasFinais,indiceRegrasExpandidas, indicePertRegrasExpandidas;
    double thresholdSuporte = 0.70, thresholdRegraInducao = 0.40, thresholdValoresBaixos = 0.02, thresholdGrauCerteza = 0.60;
    //double thresholdC = 0.90, limiarDeHiperArestas = 90;
    int  tamanho, linhaSubCjSelec, contaNulos=0, indiceSubconjunto;
    string palavraAux;
    
    utilitarios ut;
    Guloso gu; 
    IndAssReFuzzy rf;
    
    cout<<"\nIniciando fase treinamento..."<<endl;
    
    //Criando os vértices
    hyperGrafoFinal = ut.defineVertices("ClasseA_IF.out");
    //imprimindo
    for(int i=0;i<hyperGrafoFinal.size();i++){
        for(int ii=0;ii<hyperGrafoFinal[i].size();ii++){
            cout<<hyperGrafoFinal[i][ii]<<" ";
        }cout<<endl;
    }
    
    /*
     * A função gulosa irá escolher o menor nó que possui o maior peso e que liga aos demais não-membros de seu subconjunto
     * passando no máximo uma aresta.
     */
    
    suconjuntoPRInducao= gu.guloso(hyperGrafoFinal,indiceSubconjunto, itensSubConj,nomesHEdge);
     
    cout<<"\nsuconjuntoPRInducao"<<endl;
    for(int i=0;i<suconjuntoPRInducao.size();i++){
        cout<<suconjuntoPRInducao.at(i)<<endl;
    }
    
    cout<<"\nnomesHEdge"<<endl;
    for(int i=0;i<nomesHEdge.size();i++){
        cout<<nomesHEdge.at(i)<<endl;
    }

    //Selecionando as associações sem repetição
    string p1, p2, p3, p4,auxiliar;
    
    for(int i=0; i<hyperGrafoFinal[indiceSubconjunto].size();i+=2){
        auxiliar = hyperGrafoFinal[indiceSubconjunto][i];
        vetorSemRepeticao.push_back(auxiliar);
        auxiliar = hyperGrafoFinal[indiceSubconjunto][i+1];
        vetorSemRepeticao.push_back(auxiliar);
        mElementosArestas.push_back(vetorSemRepeticao);
        vetorSemRepeticao.clear();
    }
    cout<<"Imprimir antes da exclusao mElementosArestas"<<endl;
    for(int i=0; i<mElementosArestas.size();i++){
        for(int j=0; j<mElementosArestas[i].size();j++){
            cout<<mElementosArestas[i][j]<" ";
        }cout<<endl;
    }
    
    for(int i=0; i<mElementosArestas.size();i++){
        for(int j=1; j<mElementosArestas.size();j++){
            p1 = mElementosArestas[i][0];
            p2 = mElementosArestas[i][1];
            p3 = mElementosArestas[j][0];
            p4 = mElementosArestas[j][1];
            if((p1 == p4)&&(p2 == p3)){
                mElementosArestas.erase(mElementosArestas.begin()+j);
                j--;
            }else{
                if((p1 != p4)&&(p2 != p3)){
                   p1 = p3;
                   p2 = p4;
                }
            }
        }
    }
    
    cout<<"Imprimir após da exclusao mElementosArestas"<<endl;
    for(int i=0; i<mElementosArestas.size();i++){
        for(int j=0; j<mElementosArestas[i].size();j++){
            cout<<mElementosArestas[i][j]<" ";
        }cout<<endl;
    }
    
    for(int i=0; i<mElementosArestas.size();i++){
        for(int j=0; j<mElementosArestas[i].size();j++){
            vetorSemRepeticao.push_back(mElementosArestas[i][j]);
        }
    }
    
    cout<<"Associação sem repeticao "<<endl;
    for(int i=0;i<vetorSemRepeticao.size();i++){
        cout<<vetorSemRepeticao.at(i)<<endl;
    }

    /*
     * Desmembrando o item em valores de atributo/ pertinencia.
     * O objetivo desse desmembramento é encontrar em qual F_i aquele valor pertence
     * e a partir daí realizar duas etapas:
     * 1) Criar o cabeçalho <atributo/F_i>;
     * 2) Realizar o primeiro passo da associação de regra Fuzzy 
     */
    
    
    itemSubEncontrado = rf.DecifraItemDoSubconjunto(itensSubConj,suconjuntoPRInducao);
    
    cout<<"\nitemSubEncontrado"<<endl;
    for(int i=0;i<itemSubEncontrado.size();i++){
        cout<<itemSubEncontrado.at(i)<<endl;
    }
        
    atributoSub = rf.AtributoConjSelecao(itemSubEncontrado);
    
    elementosSubConjunto = atributoSub;
    
    pertinenciaSub = rf.PertinenciaConjSelecao(itemSubEncontrado);
       
    
    /*
     * A descretização do item foi realizada nos seguintes passos:
     * 1) Descobriu quais são os itens fortes retornados pelo método guloso;
     * 2) Separou em atributos e pertinência;
     * Os próximos passos são:
     *  -Descartar aquele item que é menor que um limiar de pertinência definido pelo usuário 
     *  -Descobriu em quais colunas na base de dados os itens restantes se localizam;
     * 
     */
    /*
    for(int i=0; i<pertinenciaSub.size();i++){
        if(pertinenciaSub.at(i) < thresholdValoresBaixos){
            pertinenciaSub.erase(pertinenciaSub.begin()+i);
            atributoSub.erase(atributoSub.begin()+i);
        }
    }cout<<endl;
    */
    
    cout<<"\natributoSub\n";
    for(int i=0; i<atributoSub.size();i++){
        cout<<atributoSub.at(i)<<endl;
    }cout<<endl;
    
    cout<<"\npertinenciaSub\n";
    for(int i=0; i<pertinenciaSub.size();i++){
        cout<<pertinenciaSub.at(i)<<" ";
    }cout<<endl;
    
    indicesElementosSubSelec = rf.RetornaPosicaoDosElementosT("ClasseA_ORG", atributoSub, pertinenciaSub);
    
    cout<<"\nindicesElementosSubSelec\n";
    for(int i=0; i<indicesElementosSubSelec.size();i++){
        for(int j=0;j<indicesElementosSubSelec[i].size();j++){
            cout<<indicesElementosSubSelec[i][j]<<" ";
        }cout<<endl;
    }
    
    valoresRegrasFinaisIAF = rf.RegraAssociacaoFuzzy(atributoSub, pertinenciaSub, thresholdRegraInducao, thresholdGrauCerteza, indicesElementosSubSelec, "ClasseA_ORG", thresholdValoresBaixos, classeEmExecucao, indicesDosHyperEdge, posPertinenciaRegrasFinais, grauCertezaRegrasFinais, descricaoRegrasFinaisIAF, indiceGrandeGonjSelecionado, indAtribGrandeCjSelec, descricaoAntecedentesR, consequentePosPert, consequenteInd, consequenteCab);
      /*                                                                                                                                                
    if(descricaoRegrasFinaisIAF.size() !=0){
        
        cout<<"\nImpimindo indAtribGrandeCjSelec"<<endl;
        for(int i=0;i<indAtribGrandeCjSelec.size();i++){
            for(int ii=0;ii<indAtribGrandeCjSelec[i].size();ii++){
                cout<<indAtribGrandeCjSelec[i][ii]<<" ";
            }
        }cout<<endl;

        cout<<"\nImpimindo indiceGrandeGonjSelecionado"<<endl;
        for(int i=0;i<indiceGrandeGonjSelecionado.size();i++){
            for(int ii=0;ii<indAtribGrandeCjSelec[i].size();ii++){
                cout<<indiceGrandeGonjSelecionado[i][ii]<<" ";
            }
        }cout<<endl;

        cout<<"\n Impressão no método FaseDeTreinamento\n";
        cout<<"\nImpimindo valoresRegrasFinaisIAF"<<endl;
        for(int i=0;i<valoresRegrasFinaisIAF.size();i++){
            for(int j=0;j<valoresRegrasFinaisIAF[i].size();j++){
                cout<<valoresRegrasFinaisIAF[i][j]<<" ";
            }cout<<endl;
        }

        cout<<"\nImpimindo posPertinenciaRegrasFinais"<<endl;
        for(int i=0;i<posPertinenciaRegrasFinais.size();i++){
            for(int j=0;j<posPertinenciaRegrasFinais[i].size();j++){
                cout<<posPertinenciaRegrasFinais[i][j]<<" ";
            }cout<<endl;
        }

        cout<<"\nImpimindo descricaoRegrasFinaisIAF"<<endl;
        for(int i=0;i<descricaoRegrasFinaisIAF.size();i++){
            for(int j=0;j<descricaoRegrasFinaisIAF[i].size();j++){
                cout<<descricaoRegrasFinaisIAF[i][j]<<" ";
            }cout<<endl;
        }

        cout<<"\nImpimindo grauCertezaRegrasFinais"<<endl;
        for(int i=0;i<grauCertezaRegrasFinais.size();i++){
            cout<<grauCertezaRegrasFinais[i]<<" ";
        }cout<<endl;
        
        cout<< "\n Imprimindo consequentePosPert"<<endl;
        for(int i=0;i<consequentePosPert.size();i++){
            cout<<consequentePosPert[i]<<" ";
        }cout<<endl;
        
        cout<< "\n Imprimindo consequenteInd"<<endl;
        for(int i=0;i<consequenteInd.size();i++){
            cout<<consequenteInd[i]<<" ";
        }cout<<endl;
        
        cout<< "\n Imprimindo consequenteCab"<<endl;
        for(int i=0;i<consequenteCab.size();i++){
            cout<<consequenteCab[i]<<" ";
        }cout<<endl;
    }
    */
    if(grauCertezaRegrasFinais.size()==0){
        cout<<"Não existe conjunto de regras válidas. Favor ajustar os parâmetros. "<<endl;
        exit(1);
    }
    
    ExpandeRegra(grauCertezaRegrasFinais, descricaoRegrasFinaisIAF, vetorSemRepeticao, elementosSubConjunto, classeEmExecucao, consequenteCab, indiceSubconjunto,pertinenciaSub);
    
    GravaRegras(descricaoRegrasFinaisIAF, grauCertezaRegrasFinais, "ClasseADoS","GrauCDoS", consequenteCab, "Cabecalho_ConsequenteDoS");
}

void FaseDeTreinamento::ExpandeRegra(vector<double> &grauCertezaRegras, vector<vector<string> > &descRegras, vector<string> elementosHE, vector<string> atributosSelecionados, int classeExec, vector<string> &cabConseqF, int indiceSubconjuntoSelecionado, vector<double> pertinenciaAtSelec){
 
    vector<double> GCFinaisExp, valorAVerificar, pertinenciaHE, pertinenciaSubconj,vetorPAux;
    
    vector<string> atributosHEdge;
    vector<vector<string> > descricaoRegrasFinaisExp, elementosCAHE, mElementosHEdge;
    vector<vector<double> > mPertHE, mPetPresentes;
    int  contaAusente=0, contaParAusente=0, iter =1, contaItemAntec=0;
    double pertPresente, pertAusente;
    string valorAusente, valorParAusente, valorPresente;
    vector<string> vetorAuxiliar, descricaoConseqFinaisExp, paresAVerificar, cabecalhoDoAtributoAusente;
    vector<string> cabecalhoDoAtributoPresente, nomeAVerificar;
    vector<int> verificaAusente;
                     
                
    IndAssReFuzzy fuzzy;
    
    //Atribuindo valores iniciais
    GCFinaisExp = grauCertezaRegras;
    descricaoConseqFinaisExp = cabConseqF;
    descricaoRegrasFinaisExp = descRegras;
    
    //Para as hiper-arestas
    atributosHEdge = fuzzy.AtributoConjSelecao(elementosHE);
    pertinenciaHE = fuzzy.PertinenciaConjSelecao(elementosHE);
    pertinenciaSubconj = pertinenciaAtSelec;
    
    //Imprimindo os vetores retornados
    cout<<"\natributosHEdge "<<endl;
    for(int i=0; i<atributosHEdge.size();i++){
        cout<<atributosHEdge.at(i)<< " ";
    }cout<<endl;
    
    cout<<"\nelementosHE "<<endl;
    for(int i=0; i<elementosHE.size();i++){
        cout<<elementosHE.at(i)<< " ";
    }cout<<endl;
    
    cout<<"\npertinenciaHE"<<endl;
    for(int i=0; i<pertinenciaHE.size();i++){
        cout<<pertinenciaHE.at(i)<< " ";
    }cout<<endl;
    
    //Gerando a matriz com as associações
    for(int i=0; i<atributosHEdge.size();i+=2){
        //somente o valor do atributo
        vetorAuxiliar.push_back(atributosHEdge.at(i));
        vetorAuxiliar.push_back(atributosHEdge.at(i+1));
        elementosCAHE.push_back(vetorAuxiliar);
        vetorAuxiliar.clear();
        //Pertinencia do atributo
        vetorPAux.push_back(pertinenciaHE.at(i));
        vetorPAux.push_back(pertinenciaHE.at(i+1));
        mPertHE.push_back(vetorPAux);
        vetorPAux.clear();
        //Representação do Item
        vetorAuxiliar.push_back(elementosHE.at(i));
        vetorAuxiliar.push_back(elementosHE.at(i+1));
        mElementosHEdge.push_back(vetorAuxiliar);
        vetorAuxiliar.clear();
        
    }
    
    
    
    //Repeti o processo para incluir todas as hiperArestas
   // while(iter<2){
        
        //Verificando qual item não foi selecionado
        for(int w=0; w<elementosCAHE.size();w++){
            valorAusente = elementosCAHE[w][0];
            pertAusente = mPertHE[w][0];
            valorParAusente = elementosCAHE[w][1];
            pertPresente = mPertHE[w][1];

            /*
             * Verifica qual item do par é ausente na regra gerada, 
             * caso os dois contadores sejam valores >=1 significa que nenhum 
             * está ausente na regra.
             */
            contaAusente =0;
            contaParAusente =0;
            for(int j=0;j<atributosSelecionados.size();j++){
                if((valorAusente == atributosSelecionados.at(j))&&(pertAusente = pertinenciaSubconj.at(j))){
                    contaAusente++;
                }
                if((valorParAusente == atributosSelecionados.at(j))&&(pertPresente = pertinenciaSubconj.at(j))){
                    contaParAusente++;
                }
            }
            //Só seleciona os atributos em que possue um item não selecionado na regra.
            paresAVerificar.clear();
            verificaAusente.clear();
            if(((contaAusente>=1)&& (contaParAusente<1))||((contaAusente<1)&& (contaParAusente>=1))){
                verificaAusente.push_back(contaAusente);
                verificaAusente.push_back(contaParAusente);
                paresAVerificar.push_back(valorAusente);
                paresAVerificar.push_back(valorParAusente);
            }     

            /*
            * Se a matriz de paresVerificados tiver tamanho igual a 0 significa que 
            * o elemento selecionado ainda não será utilizado para uma possível expansão.
            * 
            * Caso o valor seja maior que um esse elemento poderá ser utilizado para expansão.
            */
            vetorAuxiliar.clear();
            if(verificaAusente.size()!=0){
                if(verificaAusente.at(0)== 1){
                    cabecalhoDoAtributoAusente.clear();
                    valorPresente = paresAVerificar.at(0);
                    valorAusente = paresAVerificar.at(1);
                    nomeAVerificar.push_back(mElementosHEdge[w][1]);
                    cabecalhoDoAtributoAusente = CabecalhosSubstituir("ClasseA", nomeAVerificar, valorAusente);

                    cout<<"\ncabecalhoDoAtributoAusente"<<endl;
                    for(int s=0;s <cabecalhoDoAtributoAusente.size();s++){
                        cout<<cabecalhoDoAtributoAusente.at(s)<<endl;
                    }cout<<endl;

                    nomeAVerificar.clear();
                    cabecalhoDoAtributoPresente.clear();
                    nomeAVerificar.push_back(mElementosHEdge[w][0]);
                    cabecalhoDoAtributoPresente = CabecalhosSubstituir("ClasseA", nomeAVerificar, valorPresente);

                    cout<<"\ncabecalhoDoAtributoPresente"<<endl;
                    for(int s=0;s <cabecalhoDoAtributoPresente.size();s++){
                        cout<<cabecalhoDoAtributoPresente.at(s)<<endl;
                    }cout<<endl;
                    nomeAVerificar.clear();

                }else{
                    nomeAVerificar.clear();
                    cabecalhoDoAtributoAusente.clear();

                    valorPresente = paresAVerificar.at(1);
                    valorAusente = paresAVerificar.at(0);
                    nomeAVerificar.push_back(mElementosHEdge[w][0]);
                    cabecalhoDoAtributoAusente = CabecalhosSubstituir("ClasseA", nomeAVerificar, valorAusente);

                    cout<<"\ncabecalhoDoAtributoAusente"<<endl;
                    for(int s=0;s <cabecalhoDoAtributoAusente.size();s++){
                        cout<<cabecalhoDoAtributoAusente.at(s)<<endl;
                    }cout<<endl;

                    nomeAVerificar.clear();
                    cabecalhoDoAtributoPresente.clear();
                    nomeAVerificar.push_back(mElementosHEdge[w][1]);
                    cabecalhoDoAtributoPresente = CabecalhosSubstituir("ClasseA", nomeAVerificar, valorPresente);
                }
                /*
                 * Realizando a troca.
                 * Cada valor encontrado será substituido por UM valor faltante
                 */
                for(int k=0; k<cabecalhoDoAtributoPresente.size();k++){
                    //Verificando na parte antecedente da regra
                    for(int p=0; p< descRegras.size();p++){
                        vetorAuxiliar = descRegras[p];
                        contaAusente =0;
                        contaItemAntec=0;
                        for(int pp=0; pp<vetorAuxiliar.size();pp++){

                            if((vetorAuxiliar[pp].compare("If ")!=0)&&(vetorAuxiliar[pp].compare(" and ")!=0)){
                                
                                contaItemAntec++;
                                if(vetorAuxiliar[pp].compare(cabecalhoDoAtributoPresente.at(k))==0){
                                    /*
                                     * Significa que está na parte antecedente
                                     * então copia o Grau de certeza, a parte consequente 
                                     * e duplica a antecedente substituindo pelos elementos faltantes.
                                     */
                                    for(int kk=0; kk<cabecalhoDoAtributoAusente.size();kk++){
                                        vetorAuxiliar[pp] = cabecalhoDoAtributoAusente.at(kk);
                                        GCFinaisExp.push_back(grauCertezaRegras.at(p));
                                        descricaoConseqFinaisExp.push_back(cabConseqF[p]);
                                        descricaoRegrasFinaisExp.push_back(vetorAuxiliar);
                                        //Voltando a condição original do vetor A
                                        vetorAuxiliar.clear();
                                        vetorAuxiliar = descRegras[p];

                                    }
                                }else{
                                    contaAusente++;
                                }
                            }
                        }
                        /*
                        * Se a quantidade de contaAusente for igual ao tamanho do vetorAuxiliar
                        * significa que o elemento está na parte antecedente
                        */
                        if(contaAusente == contaItemAntec){
                            if(cabConseqF[p].compare(cabecalhoDoAtributoPresente.at(k))==0){
                                for(int kk=0; kk<cabecalhoDoAtributoAusente.size();kk++){
                                    GCFinaisExp.push_back(grauCertezaRegras.at(p));
                                    descricaoRegrasFinaisExp.push_back(vetorAuxiliar);
                                    descricaoConseqFinaisExp.push_back(cabecalhoDoAtributoAusente[kk]);
                                }
                            }
                        }
                        //Limpando o vetorAuxiliar
                        vetorAuxiliar.clear();
                    }
                }    
            }
        }
        
        //Atualizando matrizes e vetores
        grauCertezaRegras.clear();
        cabConseqF.clear();
        descRegras.clear();
        grauCertezaRegras = GCFinaisExp;
        cabConseqF = descricaoConseqFinaisExp;
        descRegras = descricaoRegrasFinaisExp;
     //   iter++;
    //}
    //Limpando os vetores
    GCFinaisExp.clear();
    descricaoConseqFinaisExp.clear();
    descricaoRegrasFinaisExp.clear();
}


void  FaseDeTreinamento::GravaRegras(vector< vector< string> > descricoesRegras, vector<double> grauCertezaDasRegras, char nomeArquivoDR[50], char nomeArquivoGCR[50], vector <string> consequenteCabecalhoExp, char nomeArquivoCConseq[100]){
    
    ofstream outputDescR;
    ofstream outputGrauCR;
    ofstream outputCabConsqR;
    
    outputDescR.open(nomeArquivoDR);
    outputGrauCR.open(nomeArquivoGCR);
    outputCabConsqR.open(nomeArquivoCConseq);
    
    //Tratamento de erro para o arquivo de saída
    if(!outputDescR.is_open()){
        printf("Erro na abertura dos arquivos de outputDescR!");
        outputDescR.clear();
        exit(1);
    }

    if(!outputGrauCR.is_open()){
        printf("Erro na abertura dos arquivos de outputGrauCR!");
        outputGrauCR.clear();
        exit(1);
    }
    
    if(!outputCabConsqR.is_open()){
        printf("Erro na abertura dos arquivos de outputCabConsqR!");
        outputCabConsqR.clear();
        exit(1);
    }
    
    //Gravando os arquivos
    for(int i=0; i< descricoesRegras.size();i++){
        for(int j=0; j<descricoesRegras[i].size();j++){
            if(j < (descricoesRegras[i].size()-1))
                outputDescR<<descricoesRegras[i][j]<<" ";
            else
                outputDescR<<descricoesRegras[i][j];
        }
        outputDescR<<endl;
    }
                
    for(int i=0; i< grauCertezaDasRegras.size();i++){
        outputGrauCR<<grauCertezaDasRegras.at(i)<<endl;
    }
    
    for(int i=0; i< consequenteCabecalhoExp.size();i++){
        outputCabConsqR<<consequenteCabecalhoExp.at(i)<<endl;
    }
    //Fechando os arquivos
    outputDescR.close();
    outputGrauCR.close();
    outputCabConsqR.close();
    
}

string FaseDeTreinamento::DesmembraItem(string item, string &valorAtributo){
    
    string palavra1, atributo;
    int guardaPosicao;
    
    palavra1 = item;
        
    //Selecionando o atributo
    for(int jj=1;jj<palavra1.size();jj++)
    {
        //O valor 44 representa o valor decimal da vírgula
        if(palavra1.at(jj)!= 44){
            atributo.push_back(palavra1.at(jj));
        }else
            {
                guardaPosicao = jj;
                break;
            }
    }
    //Selecionando o valor do atributo
    for(int jj=guardaPosicao+1;jj<palavra1.size()-1;jj++)
    {
        valorAtributo.push_back(palavra1.at(jj));
    }
    return atributo;
}

vector<string >  FaseDeTreinamento::CabecalhosSubstituir(char nomeBaseOriginal[50], vector<string> elementoFaltante, string atributo){
    
    FaseDeTreinamento::TabelaGlobal T;
        
    T= GeraStruturaBaseCompleta(nomeBaseOriginal);
        
    vector<string> cabecalhoF;
    
    //Verificando em qual coluna pertence o item
    /*
     * 1 = Baixa
     * 2 = Media
     * 3 = Alta
     */
    for(int i=0; i<elementoFaltante.size(); i++){
        for(int j=0; j< T.count1.size();j++){
            if(elementoFaltante.at(i) == T.duracao1.at(j)){
                cabecalhoF.push_back("<duracao,Baixo>");
            }else if(elementoFaltante.at(i) == T.duracao2.at(j)){
                cabecalhoF.push_back("<duracao,Medio>");
            }else if(elementoFaltante.at(i) == T.duracao3.at(j)){
                cabecalhoF.push_back("<duracao,Alto>");
            }
            if(elementoFaltante.at(i) == T.tipo_protocolo.at(j)){
                cabecalhoF.push_back("<tipo_protocolo,"+atributo+">"); 
            }
            if(elementoFaltante.at(i) == T.servico.at(j)){
                cabecalhoF.push_back("<servico,"+atributo+">");
            }
            if(elementoFaltante.at(i) == T.flag.at(j)){
                cabecalhoF.push_back("<flag,"+atributo+">");
            }
            if(elementoFaltante.at(i) == T.src_bytes1.at(j)){
                cabecalhoF.push_back("<src_bytes,Baixo>"); 
            }else if(elementoFaltante.at(i) == T.src_bytes2.at(j)){
                cabecalhoF.push_back("<src_bytes,Medio>");
            }else if (elementoFaltante.at(i) == T.src_bytes3.at(j)){
                cabecalhoF.push_back("<src_bytes,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_bytes1.at(j)){
                cabecalhoF.push_back("<dst_bytes,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_bytes2.at(j)){
                cabecalhoF.push_back("<dst_bytes,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_bytes3.at(j)){
                cabecalhoF.push_back("<dst_bytes,Alto>");
            }
            if(elementoFaltante.at(i) == T.land_Item.at(j)){
                cabecalhoF.push_back("<land,"+atributo+">");
            }
            if(elementoFaltante.at(i) == T.wrong_fragment1.at(j)){
                cabecalhoF.push_back("<wrong_fragment,Baixo>");
            }else if(elementoFaltante.at(i) == T.wrong_fragment2.at(j)){
                cabecalhoF.push_back("<wrong_fragment,Medio>");
            }else if(elementoFaltante.at(i) == T.wrong_fragment3.at(j)){
                cabecalhoF.push_back("<wrong_fragment,Alto>");
            }    
            if(elementoFaltante.at(i) == T.urgente1.at(j)){
                cabecalhoF.push_back("<urgente,Baixo>");
            }else if(elementoFaltante.at(i) == T.urgente2.at(j)){
                cabecalhoF.push_back("<urgente,Medio>");
            }else if(elementoFaltante.at(i) == T.urgente3.at(j)){
                cabecalhoF.push_back("<urgente,Alto>");
            }
            if(elementoFaltante.at(i) == T.hot1.at(j)){
                cabecalhoF.push_back("<hot,Baixo>");
            }else if(elementoFaltante.at(i) == T.hot2.at(j)){
                cabecalhoF.push_back("<hot,Medio>");
            }else if(elementoFaltante.at(i) == T.hot3.at(j)){
                cabecalhoF.push_back("<hot,Alto>");
            }
            if(elementoFaltante.at(i) == T.num_faleid_logins1.at(j)){
                cabecalhoF.push_back("<num_faleid_logins,Baixo>");
            }else if(elementoFaltante.at(i) == T.num_faleid_logins2.at(j)){
                cabecalhoF.push_back("<num_faleid_logins,Medio>");
            }else if(elementoFaltante.at(i) == T.num_faleid_logins3.at(j)){
                cabecalhoF.push_back("<num_faleid_logins,Alto>");
            }
            if(elementoFaltante.at(i) == T.logged_in_Item.at(j)){
                cabecalhoF.push_back("<logged_in,"+atributo+">");
            }
            if(elementoFaltante.at(i) == T.num_compromised1.at(j)){
                cabecalhoF.push_back("<num_compromised,Baixo>");
            }else if(elementoFaltante.at(i) == T.num_compromised2.at(j)){
                cabecalhoF.push_back("<num_compromised,Medio>");
            }else if(elementoFaltante.at(i) == T.num_compromised3.at(j)){
                cabecalhoF.push_back("<num_compromised,Alto>");
            }
            if(elementoFaltante.at(i) == T.root_shell_Item.at(j)){
                cabecalhoF.push_back("<root_shell,"+atributo+">");
            } 
            if(elementoFaltante.at(i) == T.su_attempted_Item.at(j)){
                cabecalhoF.push_back("<su_attempted,"+atributo+">");
            }
            if(elementoFaltante.at(i) == T.num_root1.at(j)){
                cabecalhoF.push_back("<num_root,Baixo>");
            }else if(elementoFaltante.at(i) == T.num_root2.at(j)){
                cabecalhoF.push_back("<num_root,Medio>");
            }else if(elementoFaltante.at(i) == T.num_root3.at(j)){
                cabecalhoF.push_back("<num_root,Alto>");
            }
            if(elementoFaltante.at(i) == T.num_file_creatinos1.at(j)){
                cabecalhoF.push_back("<num_file_creatinos,Baixo>");
            }else if(elementoFaltante.at(i) == T.num_file_creatinos2.at(j)){
                cabecalhoF.push_back("<num_file_creatinos,Medio>");
            }else if(elementoFaltante.at(i) == T.num_file_creatinos3.at(j)){
                cabecalhoF.push_back("<num_file_creatinos,Alto>");
            }
            if(elementoFaltante.at(i) == T.num_shells1.at(j)){
                cabecalhoF.push_back("<num_shells,Baixo>");
            }else if(elementoFaltante.at(i) == T.num_shells2.at(j)){
                cabecalhoF.push_back("<num_shells,Medio>");
            }else if(elementoFaltante.at(i) == T.num_shells3.at(j)){
                cabecalhoF.push_back("<num_shells,Alto>");
            }
            if(elementoFaltante.at(i) == T.num_access_files1.at(j)){
                cabecalhoF.push_back("<num_access_files,Baixo>");
            }else if(elementoFaltante.at(i) == T.num_access_files2.at(j)){
                cabecalhoF.push_back("<num_access_files,Medio>");
            }else if(elementoFaltante.at(i) == T.num_access_files3.at(j)){
                cabecalhoF.push_back("<num_access_files,Alto>");
            }
            if(elementoFaltante.at(i) == T.num_outbound_cmds_Item.at(j)){
                cabecalhoF.push_back("<num_outbound_cmds,"+atributo+">");
            }
            if(elementoFaltante.at(i) == T.is_hot_login_Item.at(j)){
                cabecalhoF.push_back("<is_hot_login,"+atributo+">");
            }
            if(elementoFaltante.at(i) == T.is_guest_login_Item.at(j)){
                cabecalhoF.push_back("<is_guest_login,"+atributo+">");
            }
            if(elementoFaltante.at(i) == T.count1.at(j)){
                cabecalhoF.push_back("<count,Baixo>");
            }else if(elementoFaltante.at(i) == T.count2.at(j)){
                cabecalhoF.push_back("<count,Medio>");
            }else if(elementoFaltante.at(i) == T.count3.at(j)){
                cabecalhoF.push_back("<count,Alto>");
            }
            if(elementoFaltante.at(i) == T.srv_count1.at(j)){
                cabecalhoF.push_back("<srv_count,Baixo>");
            }else if(elementoFaltante.at(i) == T.srv_count2.at(j)){
                cabecalhoF.push_back("<srv_count,Medio>");
            }else if(elementoFaltante.at(i) == T.srv_count3.at(j)){
                cabecalhoF.push_back("<srv_count,Alto>");
            }
            if(elementoFaltante.at(i) == T.serror_rate1.at(j)){
                cabecalhoF.push_back("<serror_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.serror_rate2.at(j)){
                cabecalhoF.push_back("<serror_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.serror_rate3.at(j)){
                cabecalhoF.push_back("<serror_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.srv_serror_rate1.at(j)){
                cabecalhoF.push_back("<srv_serror_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.srv_serror_rate2.at(j)){
                cabecalhoF.push_back("<srv_serror_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.srv_serror_rate3.at(j)){
                cabecalhoF.push_back("<srv_serror_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.rerror_rate1.at(j)){
                cabecalhoF.push_back("<rerror_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.rerror_rate2.at(j)){
                cabecalhoF.push_back("<rerror_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.rerror_rate3.at(j)){
                cabecalhoF.push_back("<rerror_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.srv_rerror_rate1.at(j)){
                cabecalhoF.push_back("<srv_rerror_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.srv_rerror_rate2.at(j)){
                cabecalhoF.push_back("<srv_rerror_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.srv_rerror_rate3.at(j)){
                cabecalhoF.push_back("<srv_rerror_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.same_srv_rate1.at(j)){
                cabecalhoF.push_back("<same_srv_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.same_srv_rate2.at(j)){
                cabecalhoF.push_back("<same_srv_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.same_srv_rate3.at(j)){
                cabecalhoF.push_back("<same_srv_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.diff_srv_rate1.at(j)){
                cabecalhoF.push_back("<diff_srv_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.diff_srv_rate2.at(j)){
                cabecalhoF.push_back("<diff_srv_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.diff_srv_rate3.at(j)){
                cabecalhoF.push_back("<diff_srv_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.srv_diff_host_rate1.at(j)){
                cabecalhoF.push_back("<srv_diff_host_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.srv_diff_host_rate2.at(j)){
                cabecalhoF.push_back("<srv_diff_host_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.srv_diff_host_rate3.at(j)){
                cabecalhoF.push_back("<srv_diff_host_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_host_count1.at(j)){
                cabecalhoF.push_back("<dst_host_count,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_host_count2.at(j)){
                cabecalhoF.push_back("<dst_host_count,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_host_count3.at(j)){
                cabecalhoF.push_back("<dst_host_count,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_host_srv_count1.at(j)){
                cabecalhoF.push_back("<dst_host_srv_count,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_host_srv_count2.at(j)){
                cabecalhoF.push_back("<dst_host_srv_count,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_host_srv_count3.at(j)){
                cabecalhoF.push_back("<dst_host_srv_count,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_host_same_srv_rate1.at(j)){
                cabecalhoF.push_back("<dst_host_same_srv_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_host_same_srv_rate2.at(j)){
                cabecalhoF.push_back("<dst_host_same_srv_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_host_same_srv_rate3.at(j)){
                cabecalhoF.push_back("<dst_host_same_srv_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_host_diff_srv_rate1.at(j)){
                cabecalhoF.push_back("<dst_host_diff_srv_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_host_diff_srv_rate2.at(j)){
                cabecalhoF.push_back("<dst_host_diff_srv_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_host_diff_srv_rate3.at(j)){
                cabecalhoF.push_back("<dst_host_diff_srv_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_host_same_src_port_rate1.at(j)){
                cabecalhoF.push_back("<dst_host_same_src_port_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_host_same_src_port_rate2.at(j)){
                cabecalhoF.push_back("<dst_host_same_src_port_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_host_same_src_port_rate3.at(j)){
                cabecalhoF.push_back("<dst_host_same_src_port_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_host_srv_diff_host_rate1.at(j)){
                cabecalhoF.push_back("<dst_host_srv_diff_host_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_host_srv_diff_host_rate2.at(j)){
                cabecalhoF.push_back("<dst_host_srv_diff_host_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_host_srv_diff_host_rate3.at(j)){
                cabecalhoF.push_back("<dst_host_srv_diff_host_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_host_serror_rate1.at(j)){
                cabecalhoF.push_back("<dst_host_serror_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_host_serror_rate2.at(j)){
                cabecalhoF.push_back("<dst_host_serror_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_host_serror_rate3.at(j)){
                cabecalhoF.push_back("<dst_host_serror_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_host_srv_serror_rate1.at(j)){
                cabecalhoF.push_back("<dst_host_srv_serror_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_host_srv_serror_rate2.at(j)){
                cabecalhoF.push_back("<dst_host_srv_serror_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_host_srv_serror_rate3.at(j)){
                cabecalhoF.push_back("<dst_host_srv_serror_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_host_rerror_rate1.at(j)){
                cabecalhoF.push_back("<dst_host_rerror_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_host_rerror_rate2.at(j)){
                cabecalhoF.push_back("<dst_host_rerror_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_host_rerror_rate3.at(j)){
                cabecalhoF.push_back("<dst_host_rerror_rate,Alto>");
            }
            if(elementoFaltante.at(i) == T.dst_host_srv_rerror_rate1.at(j)){
                cabecalhoF.push_back("<dst_host_srv_rerror_rate,Baixo>");
            }else if(elementoFaltante.at(i) == T.dst_host_srv_rerror_rate2.at(j)){
                cabecalhoF.push_back("<dst_host_srv_rerror_rate,Medio>");
            }else if(elementoFaltante.at(i) == T.dst_host_srv_rerror_rate3.at(j)){
                cabecalhoF.push_back("<dst_host_srv_rerror_rate,Alto>");
            }
        }
    }
    
    /*
     * Nesse momento excluir os valores de índices repetidos
     */
    //Limpando o vetor
    for(int i=0;i<cabecalhoF.size();i++){
        for(int ii=i+1;ii<cabecalhoF.size();ii++){
            if(cabecalhoF.at(i)==cabecalhoF.at(ii)){
                cabecalhoF.erase(cabecalhoF.begin()+ii);
                ii--;
            }
        }
    }
    
    return cabecalhoF;
}

FaseDeTreinamento::TabelaGlobal FaseDeTreinamento::GeraStruturaBaseCompleta(char nomeDaBaseOriginal[50]){
    
    TabelaGlobal t;
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
        t.duracao1.push_back(dur);
        inputNomeBase>>dur;
        t.duracao2.push_back(dur);
        inputNomeBase>>dur;
        t.duracao3.push_back(dur);
        
        string prot;
        inputNomeBase>>prot;
        t.tipo_protocolo.push_back(prot);
        
        string serv;
        inputNomeBase>>serv;
        t.servico.push_back(serv);
        
        string fla;
        inputNomeBase>>fla;
        t.flag.push_back(fla);
        
        string src;
        inputNomeBase>>src;
        t.src_bytes1.push_back(src);
        inputNomeBase>>src;
        t.src_bytes2.push_back(src);
        inputNomeBase>>src;
        t.src_bytes3.push_back(src);
        
        string dst;
        inputNomeBase>>dst;
        t.dst_bytes1.push_back(dst);
        inputNomeBase>>dst;
        t.dst_bytes2.push_back(dst);
        inputNomeBase>>dst;
        t.dst_bytes3.push_back(dst);
        
        string la;
        inputNomeBase>>la;
        t.land_Item.push_back(la);
        
        string wrof;
        inputNomeBase>>wrof;
        t.wrong_fragment1.push_back(wrof);
        inputNomeBase>>wrof;
        t.wrong_fragment2.push_back(wrof);
        inputNomeBase>>wrof;
        t.wrong_fragment3.push_back(wrof);
        
        string urg;
        inputNomeBase>>urg;
        t.urgente1.push_back(urg);
        inputNomeBase>>urg;
        t.urgente2.push_back(urg);
        inputNomeBase>>urg;
        t.urgente3.push_back(urg);
        
        string h;
        inputNomeBase>>h;
        t.hot1.push_back(h);
        inputNomeBase>>h;
        t.hot2.push_back(h);
        inputNomeBase>>h;
        t.hot3.push_back(h);
        
        string numFL;
        inputNomeBase>>numFL;
        t.num_faleid_logins1.push_back(numFL);
        inputNomeBase>>numFL;
        t.num_faleid_logins2.push_back(numFL);
        inputNomeBase>>numFL;
        t.num_faleid_logins3.push_back(numFL);
        
        string logIn;
        inputNomeBase>>logIn;
        t.logged_in_Item.push_back(logIn);
        
        string numC;
        inputNomeBase>>numC;
        t.num_compromised1.push_back(numC);
        inputNomeBase>>numC;
        t.num_compromised2.push_back(numC);
        inputNomeBase>>numC;
        t.num_compromised3.push_back(numC);
        
        string rShell;
        inputNomeBase>>rShell;
        t.root_shell_Item.push_back(rShell);
                
        string su;
        inputNomeBase>>su;
        t.su_attempted_Item.push_back(su);
        
        string nRoot;
        inputNomeBase>>nRoot;
        t.num_root1.push_back(nRoot);
        inputNomeBase>>nRoot;
        t.num_root2.push_back(nRoot);
        inputNomeBase>>nRoot;
        t.num_root3.push_back(nRoot);
        
        string nFC;
        inputNomeBase>>nFC;
        t.num_file_creatinos1.push_back(nFC);
        inputNomeBase>>nFC;
        t.num_file_creatinos2.push_back(nFC);
        inputNomeBase>>nFC;
        t.num_file_creatinos3.push_back(nFC);
        
        string nShells;
        inputNomeBase>>nShells;
        t.num_shells1.push_back(nShells);
        inputNomeBase>>nShells;
        t.num_shells2.push_back(nShells);
        inputNomeBase>>nShells;
        t.num_shells3.push_back(nShells);
        
        string nAF;
        inputNomeBase>>nAF;
        t.num_access_files1.push_back(nAF);
        inputNomeBase>>nAF;
        t.num_access_files2.push_back(nAF);
        inputNomeBase>>nAF;
        t.num_access_files3.push_back(nAF);
        
        string nOut;
        inputNomeBase>>nOut;
        t.num_outbound_cmds_Item.push_back(nOut);
        
        string hotL;
        inputNomeBase>>hotL;
        t.is_hot_login_Item.push_back(hotL);
        
        string guestL;
        inputNomeBase>>guestL;
        t.is_guest_login_Item.push_back(guestL);
        
        string cou;
        inputNomeBase>>cou;
        t.count1.push_back(cou);
        inputNomeBase>>cou;
        t.count2.push_back(cou);
        inputNomeBase>>cou;
        t.count3.push_back(cou);
        
        string srvC;
        inputNomeBase>>srvC;
        t.srv_count1.push_back(srvC);
        inputNomeBase>>srvC;
        t.srv_count2.push_back(srvC);
        inputNomeBase>>srvC;
        t.srv_count3.push_back(srvC);
        
        string sRate;
        inputNomeBase>>sRate;
        t.serror_rate1.push_back(sRate);
        inputNomeBase>>sRate;
        t.serror_rate2.push_back(sRate);
        inputNomeBase>>sRate;
        t.serror_rate3.push_back(sRate);
        
        string srvSR;
        inputNomeBase>>srvSR;
        t.srv_serror_rate1.push_back(srvSR);
        inputNomeBase>>srvSR;
        t.srv_serror_rate2.push_back(srvSR);
        inputNomeBase>>srvSR;
        t.srv_serror_rate3.push_back(srvSR);
        
        string rRate;
        inputNomeBase>>rRate;
        t.rerror_rate1.push_back(rRate);
        inputNomeBase>>rRate;
        t.rerror_rate2.push_back(rRate);
        inputNomeBase>>rRate;
        t.rerror_rate3.push_back(rRate);
        
        string srvRR;
        inputNomeBase>>srvRR;
        t.srv_rerror_rate1.push_back(srvRR);
        inputNomeBase>>srvRR;
        t.srv_rerror_rate2.push_back(srvRR);
        inputNomeBase>>srvRR;
        t.srv_rerror_rate3.push_back(srvRR);
        
        string sameSR;
        inputNomeBase>>sameSR;
        t.same_srv_rate1.push_back(sameSR);
        inputNomeBase>>sameSR;
        t.same_srv_rate2.push_back(sameSR);
        inputNomeBase>>sameSR;
        t.same_srv_rate3.push_back(sameSR);
        
        string diffSR;
        inputNomeBase>>diffSR;
        t.diff_srv_rate1.push_back(diffSR);
        inputNomeBase>>diffSR;
        t.diff_srv_rate2.push_back(diffSR);
        inputNomeBase>>diffSR;
        t.diff_srv_rate3.push_back(diffSR);
        
        string srvDHR;
        inputNomeBase>>srvDHR;
        t.srv_diff_host_rate1.push_back(srvDHR);
        inputNomeBase>>srvDHR;
        t.srv_diff_host_rate2.push_back(srvDHR);
        inputNomeBase>>srvDHR;
        t.srv_diff_host_rate3.push_back(srvDHR);
        
        string dstHC;
        inputNomeBase>>dstHC;
        t.dst_host_count1.push_back(dstHC);
        inputNomeBase>>dstHC;
        t.dst_host_count2.push_back(dstHC);
        inputNomeBase>>dstHC;
        t.dst_host_count3.push_back(dstHC);
        
        string dstHSC;
        inputNomeBase>>dstHSC;
        t.dst_host_srv_count1.push_back(dstHSC);
        inputNomeBase>>dstHSC;
        t.dst_host_srv_count2.push_back(dstHSC);
        inputNomeBase>>dstHSC;
        t.dst_host_srv_count3.push_back(dstHSC);
        
        string dstHSameSR;
        inputNomeBase>>dstHSameSR;
        t.dst_host_same_srv_rate1.push_back(dstHSameSR);
        inputNomeBase>>dstHSameSR;
        t.dst_host_same_srv_rate2.push_back(dstHSameSR);
        inputNomeBase>>dstHSameSR;
        t.dst_host_same_srv_rate3.push_back(dstHSameSR);
        
        string dstHDSR;
        inputNomeBase>>dstHDSR;
        t.dst_host_diff_srv_rate1.push_back(dstHDSR);
        inputNomeBase>>dstHDSR;
        t.dst_host_diff_srv_rate2.push_back(dstHDSR);
        inputNomeBase>>dstHDSR;
        t.dst_host_diff_srv_rate3.push_back(dstHDSR);
        
        string dstHSSPR;
        inputNomeBase>>dstHSSPR;
        t.dst_host_same_src_port_rate1.push_back(dstHSSPR);
        inputNomeBase>>dstHSSPR;
        t.dst_host_same_src_port_rate2.push_back(dstHSSPR);
        inputNomeBase>>dstHSSPR;
        t.dst_host_same_src_port_rate3.push_back(dstHSSPR);
        
        string dstHSDHR;
        inputNomeBase>>dstHSDHR;
        t.dst_host_srv_diff_host_rate1.push_back(dstHSDHR);
        inputNomeBase>>dstHSDHR;
        t.dst_host_srv_diff_host_rate2.push_back(dstHSDHR);
        inputNomeBase>>dstHSDHR;
        t.dst_host_srv_diff_host_rate3.push_back(dstHSDHR);
        
        string dstHSR;
        inputNomeBase>>dstHSR;
        t.dst_host_serror_rate1.push_back(dstHSR);
        inputNomeBase>>dstHSR;
        t.dst_host_serror_rate2.push_back(dstHSR);
        inputNomeBase>>dstHSR;
        t.dst_host_serror_rate3.push_back(dstHSR);
        
        string dstHSSR;
        inputNomeBase>>dstHSSR;
        t.dst_host_srv_serror_rate1.push_back(dstHSSR);
        inputNomeBase>>dstHSSR;
        t.dst_host_srv_serror_rate2.push_back(dstHSSR);
        inputNomeBase>>dstHSSR;
        t.dst_host_srv_serror_rate3.push_back(dstHSSR);
        
        string dstHRR;
        inputNomeBase>>dstHRR;
        t.dst_host_rerror_rate1.push_back(dstHRR);
        inputNomeBase>>dstHRR;
        t.dst_host_rerror_rate2.push_back(dstHRR);
        inputNomeBase>>dstHRR;
        t.dst_host_rerror_rate3.push_back(dstHRR);
        
        string dstHSRR;
        inputNomeBase>>dstHSRR;
        t.dst_host_srv_rerror_rate1.push_back(dstHSRR);
        inputNomeBase>>dstHSRR;
        t.dst_host_srv_rerror_rate2.push_back(dstHSRR);
        inputNomeBase>>dstHSRR;
        t.dst_host_srv_rerror_rate3.push_back(dstHSRR);
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