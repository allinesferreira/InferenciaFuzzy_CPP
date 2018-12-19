
#ifndef GERAARQUIVOSCLASSE_H
#define	GERAARQUIVOSCLASSE_H

#include "GeraArquivosClasse.h"
#include "utilitarios.h"
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

class GeraArquivosClasse
{
private:
 typedef struct Tabela
 {
    int duracao, src_bytes, dst_bytes, land, wrong_fragment, urgente, hot;
    int num_faleid_logins, logged_in, num_compromised, root_shell, su_attempted, num_root;
    int num_file_creatinos, num_shells, num_access_files, num_outbound_cmds, is_hot_login;
    int is_guest_login, count, srv_count, dst_host_count, dst_host_srv_count;
    int etiquetaAlt, tipo_protocoloAlt, servicoAlt, flagAlt;
    double serror_rate, srv_serror_rate, rerror_rate, srv_rerror_rate, same_srv_rate, diff_srv_rate, srv_diff_host_rate;
    double dst_host_same_srv_rate, dst_host_diff_srv_rate, dst_host_same_src_port_rate, dst_host_srv_diff_host_rate;
    double dst_host_serror_rate, dst_host_srv_serror_rate, dst_host_rerror_rate, dst_host_srv_rerror_rate;
    char tipo_protocolo[20], servico[20], flag[20], etiqueta[20], lixo;
    
    
}Tab;

public:   
    GeraArquivosClasse();
    void CriaArquivosClasse(char nomeDaBase[30]);   
    void Cria2ClassesArquivos(char nomeDaBase[50], vector<string> nomeClasseA);
    void LimpaBase(char nomeBaseASerLimpa[50], char nomeParaBaseLimpa[50]);
    void GravaArquivoParaMatlab(utilitarios::Transacao &base, char nomeDoArqMat[50]);
    void GeraClassesOriginaisParaMatlab(char nomeDaBase[50], char nomeClasseOriginal[50]);
    void GeraClassesOriginaisSemEtiquetas(char nomeClasseOriginal[50], char nomeArquivoSemEtiqueta[50]);
    void RetornaVetorDeEtiquetasGerArqSemEtiqueta(char nomeClasseOriginal[50], char nomeArquivoSemEtiqueta[50]);
    void GeraArquivoAtaquesConhecidos(char nomeArquivoMatriz[50], char nomeArqEtiqueta[50], char nomeArquiTreine[50]);
    void GeraArquivoAtaquesDesconhecidos(char nomeArquivoMatriz[50], char nomeArqEtiqueta[50], char nomeArquiTreine[50]);
    vector<string> RetornaVetorDeEtiquetas(char nomeClasseOriginal[50]);
    
private:
    vector<string> SelecionaAtaqueDesconhecido(char nomeArquivoEtiqueta[50], char ArquivoOriginal[50]);
    void ExcluiDados(utilitarios::Transacao &tt, vector<int> &posicoesParaExclusao, int posicao, vector<int> &totaisDeCadaValor);
    vector<int> BuscaValoresIguais(vector<string> &vetorAVerificar, string valor, vector<int> &qtdeCadaValor, vector<string> &valoresNoVetor);
    void GravaRegistroLimpo(utilitarios::Transacao &amostra, char nomeDoArqLimpo[50]);
    void ImprimirParaConferencia(utilitarios::Transacao &a);
    void AtualizaEstrutura(vector<string> &vetorAAtualizar, utilitarios::Transacao &t);
};


#endif	/* GERAARQUIVOSCLASSE_H */

