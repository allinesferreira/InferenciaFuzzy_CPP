/* 
 * File:   FaseDeTreinamento.h
 * Author: allinesf
 *
 * Created on 9 de Junho de 2015, 14:40
 */

#ifndef FASEDETREINAMENTO_H
#define	FASEDETREINAMENTO_H

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

class FaseDeTreinamento {
public:
     typedef struct TabelaGlobal
{
    vector<string> tipo_protocolo, servico, flag, etiqueta;
    vector<string> duracao1, duracao2, duracao3,src_bytes1, src_bytes2,src_bytes3, dst_bytes1, dst_bytes2, dst_bytes3;
    vector<string> wrong_fragment1, wrong_fragment2, wrong_fragment3, urgente1, urgente2, urgente3, hot1, hot2, hot3;
    vector<string> num_faleid_logins1, num_faleid_logins2, num_faleid_logins3, num_compromised1, num_compromised2, num_compromised3;
    vector<string> num_root1, num_root2, num_root3, num_file_creatinos1, num_file_creatinos2, num_file_creatinos3, num_shells1, num_shells2, num_shells3;
    vector<string> num_access_files1, num_access_files2, num_access_files3, count1, count2, count3, srv_count1, srv_count2, srv_count3;
    vector<string> serror_rate1, serror_rate2, serror_rate3, srv_serror_rate1, srv_serror_rate2, srv_serror_rate3, rerror_rate1, rerror_rate2, rerror_rate3;
    vector<string> srv_rerror_rate1, srv_rerror_rate2, srv_rerror_rate3, same_srv_rate1, same_srv_rate2, same_srv_rate3, diff_srv_rate1,diff_srv_rate2, diff_srv_rate3;
    vector<string> srv_diff_host_rate1, srv_diff_host_rate2, srv_diff_host_rate3, dst_host_count1, dst_host_count2, dst_host_count3;
    vector<string> dst_host_srv_count1, dst_host_srv_count2, dst_host_srv_count3, dst_host_same_srv_rate1, dst_host_same_srv_rate2, dst_host_same_srv_rate3;
    vector<string> dst_host_diff_srv_rate1, dst_host_diff_srv_rate2, dst_host_diff_srv_rate3, dst_host_same_src_port_rate1, dst_host_same_src_port_rate2, dst_host_same_src_port_rate3;
    vector<string> dst_host_srv_diff_host_rate1, dst_host_srv_diff_host_rate2, dst_host_srv_diff_host_rate3, dst_host_serror_rate1, dst_host_serror_rate2, dst_host_serror_rate3;
    vector<string> dst_host_srv_serror_rate1, dst_host_srv_serror_rate2, dst_host_srv_serror_rate3, dst_host_rerror_rate1, dst_host_rerror_rate2, dst_host_rerror_rate3;
    vector<string> dst_host_srv_rerror_rate1, dst_host_srv_rerror_rate2, dst_host_srv_rerror_rate3;
    vector<string> land_Item, logged_in_Item, root_shell_Item, su_attempted_Item, num_outbound_cmds_Item, is_hot_login_Item, is_guest_login_Item;
    
};

    FaseDeTreinamento();
    FaseDeTreinamento(const FaseDeTreinamento& orig);
    virtual ~FaseDeTreinamento();
    void Treinamento(int classeEmExecucao);
    string DesmembraItem(string item, string &valorAtributo);
    vector<string >  CabecalhosSubstituir(char nomeBaseOriginal[50], vector<string> elementoFaltante, string atributo);
private:
   // vector<vector<string> > ExpandeRegra(vector<vector<int> > indRegras, vector<vector<int> > indPertRegras, vector<double> &grauCertezaRegras, vector<vector<string> > descRegras, vector<vector<int> > indItensEscolhidos, vector<vector<int> > indAtributosEscolhidos, vector<string> elementosHE, vector<string> atributosSelecionados, int classeExec, vector<vector<string> > descrAtributosRegra, vector<vector<int> > &valoresRegrasFinaisIAFExp, vector<vector<int> > &posPertinenciaRegrasFinaisExp, vector<int> pertConseqF, vector<int> indConseqF, vector<string> cabConseq, vector<int> &pertConseqExp, vector<int> &indConseqExp, vector<string> &cabConseqExp);
   void ExpandeRegra(vector<double> &grauCertezaRegras, vector<vector<string> > &descRegras, vector<string> elementosHE, vector<string> atributosSelecionados, int classeExec, vector<string> &cabConseqF, int indiceSubconjuntoSelecionado, vector<double> pertinenciaAtSelec);
   //void  GravaRegras(vector< vector< int> > indiceDasRegras, vector< vector< int> > indicesPertinenciaDasRegras, vector< vector< string> > descricoesRegras, vector<double> grauCertezaDasRegras, char nomeArquivoDR[50], char nomeArquivoIR[50], char nomeArquivoIPR[50], char nomeArquivoGCR[50], vector <int> consequentePertinenciaExp, vector <int> consequenteIndiceExp, vector <string> consequenteCabecalhoExp);
   void  GravaRegras(vector< vector< string> > descricoesRegras, vector<double> grauCertezaDasRegras, char nomeArquivoDR[50], char nomeArquivoGCR[50], vector <string> consequenteCabecalhoExp, char nomeArquivoCConseq[100]);
   TabelaGlobal GeraStruturaBaseCompleta(char nomeDaBaseOriginal[50]); 
};

#endif	/* FASEDETREINAMENTO_H */

