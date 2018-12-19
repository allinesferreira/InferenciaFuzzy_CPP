/* 
 * File:   IndAssReFuzzy.h
 * Author: allinesf
 *
 * Created on 3 de Maio de 2015, 10:15
 */

#ifndef INDASSREFUZZY_H
#define	INDASSREFUZZY_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h> 
#include <sstream>
using namespace std;

class IndAssReFuzzy {
public:
    IndAssReFuzzy();
    virtual ~IndAssReFuzzy();
    vector<string> AtributoConjSelecao(vector<string> itensSubconjunto);
    vector<double> PertinenciaConjSelecao(vector<string> itensDoSubconjunto);
    vector <string> DecifraItemDoSubconjunto(vector<string> v1, vector<int> subconjuntoS);
    //vector <string> DecifraItemDoSubconjunto(vector<string> v1, vector<int> subconjuntoS, int indiceLinhanoHE);
    //vector<vector<int> > RegraAssociacaoFuzzy(vector< string> tabelaAtributos, vector<double> pertinenciaDoSubconjunto, double thresholdRI, double thresholdGC, vector<vector<int> > indiceElementosDoSubCj, char BaseOrg[50], double limiarValoresBaixos, int classeRF, vector<int> posicoesIniciaisHyperEdge, vector<vector<int> > &pertinenciaRegrasValidas, vector<double> &grauCertezaRegrasValidas, vector<vector<string> > &descricaoRegrasValidas,vector<vector<int> > &indiceLargeItem, vector<vector<int> > &indAtributoLItem, vector< vector<string> >  &descAntecedentes);
    vector<vector<int> > RegraAssociacaoFuzzy(vector< string> tabelaAtributos, vector<double> pertinenciaDoSubconjunto, double thresholdRI, double thresholdGC, vector<vector<int> > &indiceElementosDoSubCj, char BaseOrg[50], double limiarValoresBaixos, int classeRF, vector<int> posicoesIniciaisHyperEdge, vector<vector<int> > &pertinenciaRegrasValidas, vector<double> &grauCertezaRegrasValidas, vector<vector<string> > &descricaoRegrasValidas,vector<vector<int> > &indiceLargeItem, vector<vector<int> > &indAtributoLItem, vector< vector<string> >  &descAntecedentes, vector<int> &pertConseqFinal, vector<int> &indConseqFinal, vector<string> &cabConseqFinal);
    vector<vector<int> > RetornaPosicaoDosElementosT(char nomeBaseOriginal[50], vector<string> atributoSCj, vector<double> pertinenciaSCj);
    vector <string> AlimentaVetoresRegrasLinguisticas();
    vector <string> AlimentaVetoresAtributos();
    vector<string> GeraCabecalho(vector<string> Fx_i, vector<string> atributoI, double pertinenciaDoSub, int &colunaPert, vector<string> valoresAtributosSubConj, vector<int> &indiceEleSubConj, int classe, int indiceParaValorAtributo);
    vector<double> RetornaMatrizPertinenciaAtributos(int indiceNaTabT, int indiceColunaPertinecia, double limiarParaValoresBaixos, char nomeBaseOTeste[50], string valorSubConj, int classeAtual);
    double significancia(vector<double> retornoC1, vector<vector<double> > retornoC2);
    double CalculaSignificanciaLargeItens(vector< vector<double> > largeItens);
    
private:
    vector<vector<double> > AlimentaVetoresPertNumerica(char nomeArqP[50]);
    vector<int> AlimentaVetoresPertCategorica(int tamanhoVetor);
    vector<double> CriaMatrizComValoresCabecalhoVariaveisNum(vector<vector <double> > tabelaPertinencia, int posicaoColunaPertinencia, double limiarConf);
    vector<double> CriaVetorComValoresVariaveisCategoricas(vector<string> colunaEmT, string valorNaTabelaT);
    //vector<vector<int> > CalculaGrauCerteza(vector <vector< int> > mAntecedentes, vector <string> cabecalhoLargeItemSets, vector <int> indiceLargeItemSets, vector<int> indicePosicaoPertinencia, vector< vector<double> > somatorioPertLI, double thresholdGrauCert, vector<double> &vGrauCertezaRI,vector<vector <int> > &mPosicaoPertinencia, vector<vector <string> >  &descRegrasValidas, double valorSignificanciaZC);
    vector<vector<int> > CalculaGrauCerteza(vector<int> indiceAtributoLI,vector <vector< int> > mAntecedentes, vector <string> cabecalhoLargeItemSets, vector <int> indiceLargeItemSets, vector<int> indicePosicaoPertinencia, vector< vector<double> > somatorioPertLI, double thresholdGrauCert, vector<double> &vGrauCertezaRI,vector<vector <int> > &mPosicaoPertinencia, vector<vector <string> >  &descRegrasValidas, double valorSignificanciaZC, vector<int> &vPosPertValorDiferente, vector<int> &vIndElementoDiferente, vector<string> &vetorValorDiferente);
    //vector<vector<int> > CalculaGrauCertezaMaisItens(vector <vector< int> > mAntecedentesAceitos, vector <string> cabecalhoLargeItemSetsAceitos, vector <int> indiceLargeItemSetsOriginal, vector <int> indiceLargeItemSetsAceitos, vector<int> indicePosicaoPertinenciaAceitos, vector< vector<double> > somatorioPertLIAceitos, double thresholdGrau, vector<double> &vGrauCertezaRISelec,vector<vector <int> > &mPosicaoPertinenciaSelec, vector<vector <string> >  &descRegrasValidasSelec, double valorSignifZC);
    vector<vector<int> > CalculaGrauCertezaMaisItens(vector <vector< int> > mAntecedentesAceitos, vector <string> cabecalhoLargeItemSetsAceitos, vector <int> indiceLargeItemSetsOriginal, vector <int> indiceLargeItemSetsAceitos, vector<int> indicePosicaoPertinenciaAceitos, vector< vector<double> > somatorioPertLIAceitos, double thresholdGrau, vector<double> &vGrauCertezaRISelec,vector<vector <int> > &mPosicaoPertinenciaSelec, vector<vector <string> >  &descRegrasValidasSelec, double valorSignifZC, vector<int> &vPosPertValorResto, vector<int> &vIndElementoResto, vector<string> &vetorValorDiferente);
    double SignificanciaApenasUmaColuna(vector<double> vetorPertinenciaASerCalculada);
    vector<string> RetornaDadoCategorico(char BaseOriginal[50], int indiceNaColunaT);
    int indicePertinencia(char arquivoPertinencia[50], double valorAVerificar);
    vector<vector<int> >  DesmembraGrandeConjuntoItens(vector< int> indiceReal);
    vector<vector<int> > matrizRegraFinal(vector< int> indElSub);
    vector<vector <string> >  GeraCabecalhoDaRegra(vector <string> cabecalhoLargeItemSets, vector<int> indiceLargeItemSets, vector<int> vRegrasInteressantes);
    //double CalculaSignificanciaLargeItens(vector< vector<double> > largeItens);
    vector<vector<int> > GeraCombinacoesEValidaSignif(vector<vector<double> > matrizPertinencia, double limiarSignificancia, vector <double>  &vetorSignigicanciaDosConjuntos);
};

#endif	/* INDASSREFUZZY_H */

