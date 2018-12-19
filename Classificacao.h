/* 
 * File:   Classificacao.h
 * Author: allinesf
 *
 * Created on 23 de Maio de 2015, 16:17
 */

#ifndef CLASSIFICACAO_H
#define	CLASSIFICACAO_H

#include "IndAssReFuzzy.h"
#include <vector>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h> 

using namespace std;

class Classificacao {
public:
    Classificacao();
    Classificacao(const Classificacao& orig);
    virtual ~Classificacao();
    //vector<vector<double> > LerArquivoDeteccao(char nomeArqDeteccao[100], double limiarVlrBaixos, bool ABCextendida);
    void LerArquivoDeteccao(char nomeArqDeteccao[100], double limiarVlrBaixos, bool ABCextendida);
    void EstimativaABC_Extendida(vector<string> tipoDeConexao, vector<string> label, char nomeArqPrincipal[100], char arqFP[100], char arqFN[100]);
    void EstimativaABC(vector<string> tipoDeConexao, vector<string> label, char nomeArq[100], char arqFalsoP[100], char arqFalsoN[100]);
    vector <string> LerEtiqueta(char rotulos[50]);
    double MetodoMamdani(double fst, double valorConsequente, double grauCertezaRegra, double limiteValorPermitido);
    
    
private:
    
    typedef struct Dados{
        int indAntecedente, indConsequente, indPerAntecedente, indPerConsequente;
        double grauCerteza;
    }Dados;
    //double RealizaCalculos(vector<vector<string> > cabecalhoAR, vector<string> vetorLido, vector <double> grau, vector<double> valoresConsequente, double limiar);
    double RealizaCalculos(vector<vector<string> > cabecalhoAR, vector<string> vetorLido, vector <double> grau, vector<double> valoresConsequente, double limiar, double &resposta_MM_Mamdani);
    double RI(double GrauCertezaDaRegras, double fs);
    double mm_trp(double pertVlrRefConsequente, double limiarMinimo);
    double firingStrength (vector<double> pertDosVlrsRefAntecedente, double limiarMinimo);
    vector<string> SelecionaCamposAValidar(vector<string> cabecalhoDaRegra, vector<string> vetorLido);
    double ABC (vector<double> RegraInducao, vector<double> _mm);
    double ABC_Mamdani(vector<double> grauCertezaRegra, vector<double> mmLinha);
    vector<vector <int> > LerArquivoIAntecedente(char indiceAntecedentes[50]);
    vector<vector <int> > LerArquivoIPAntecedente(char posicaoPertAntecedentes[50]);
    vector <int> LerArquivoIConsequente(char indiceConsequente[50]);
    vector <int> LerArquivoIPConsequente(char pertinenciaConseq[50]);
    vector <double> LerArquivoGrauCerteza(char grauCertezaRegra[50]);
    vector <vector<string> > LerCabecalhoAntecedente(char cabecalhoAntecendente[50]);
    vector <string> LerCabecalhoPertinencia(char cabecalhoPertinencia[50]);
    vector<double> PertinenciaValores(vector<string> itensDoSubconjunto);
    
};

#endif	/* CLASSIFICACAO_H */

