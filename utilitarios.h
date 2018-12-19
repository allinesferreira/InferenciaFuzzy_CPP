
#ifndef UTILITARIOS_H
#define	UTILITARIOS_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>

using namespace std;


class utilitarios {
public:
    
    struct Transacao
    {
        vector<string> duracao,src_bytes, dst_bytes, wrong_fragment, urgente;
        vector<string> hot, num_faleid_logins, num_compromised, num_file_creatinos; 
        vector<string> num_root, num_shells, num_access_files, count, srv_count;
        vector<string> dst_host_count,dst_host_srv_count, etiqueta;
        vector<string> protocolo, servico, flag, land, logged_in, root_shell; 
        vector<string> su_attempted, num_outbound_cmds, is_hot_login,is_guest_login;
        vector<string> serror_rate, srv_serror_rate, rerror_rate, srv_rerror_rate;
        vector<string> same_srv_rate, diff_srv_rate, srv_diff_host_rate;
        vector<string> dst_host_same_srv_rate, dst_host_diff_srv_rate;
        vector<string> dst_host_same_src_port_rate, dst_host_srv_diff_host_rate;
        vector<string> dst_host_serror_rate, dst_host_srv_serror_rate;
        vector<string> dst_host_rerror_rate, dst_host_srv_rerror_rate;
    };
    
    typedef struct Pertinencia
    {
        double duracaoAlta, duracaoMedia, duracaoBaixa, src_bytesAlta, src_bytesMedia, src_bytesBaixa;
        double dst_bytesAlta, dst_bytesMedia, dst_bytesBaixa, wrong_fragmentAlta, wrong_fragmentMedia, wrong_fragmentBaixa;
        double urgenteAlta, urgenteMedia, urgenteBaixa, hotAlta, hotMedia, hotBaixa, num_faleid_loginsAlta, num_faleid_loginsMedia;
        double num_faleid_loginsBaixa, num_rootAlta, num_rootMedia,num_rootBaixa, num_compromisedAlta, num_compromisedMedia;
        double num_compromisedBaixa, num_file_creatinosAlta, num_file_creatinosMedia, num_file_creatinosBaixa, num_shellsAlta;
        double num_shellsMedia, num_shellsBaixa, num_access_filesAlta, num_access_filesMedia, num_access_filesBaixa, countAlta;
        double countMedia, countBaixa, srv_countAlta, srv_countMedia, srv_countBaixa, dst_host_countAlta, dst_host_countMedia;
        double dst_host_countBaixa, dst_host_srv_countAlta, dst_host_srv_countMedia, dst_host_srv_countBaixa, serror_rateAlta;
        double serror_rateMedia, serror_rateBaixa, srv_serror_rateAlta, srv_serror_rateMedia, srv_serror_rateBaixa, rerror_rateAlta;
        double rerror_rateMedia, rerror_rateBaixa, srv_rerror_rateAlta, srv_rerror_rateMedia, srv_rerror_rateBaixa, same_srv_rateAlta;
        double same_srv_rateMedia, same_srv_rateBaixa, diff_srv_rateAlta, diff_srv_rateMedia, diff_srv_rateBaixa, srv_diff_host_rateAlta;
        double srv_diff_host_rateMedia, srv_diff_host_rateBaixa,dst_host_same_srv_rateAlta, dst_host_same_srv_rateMedia, dst_host_same_srv_rateBaixa;
        double dst_host_diff_srv_rateAlta, dst_host_diff_srv_rateMedia, dst_host_diff_srv_rateBaixa, dst_host_same_src_port_rateAlta;
        double dst_host_same_src_port_rateMedia, dst_host_same_src_port_rateBaixa, dst_host_srv_diff_host_rateAlta, dst_host_srv_diff_host_rateMedia;
        double dst_host_srv_diff_host_rateBaixa, dst_host_serror_rateAlta, dst_host_serror_rateMedia, dst_host_serror_rateBaixa;
        double dst_host_srv_serror_rateAlta, dst_host_srv_serror_rateMedia, dst_host_srv_serror_rateBaixa, dst_host_rerror_rateAlta;
        double dst_host_rerror_rateMedia, dst_host_rerror_rateBaixa, dst_host_srv_rerror_rateAlta, dst_host_srv_rerror_rateMedia, dst_host_srv_rerror_rateBaixa;

        double logged_in, tipo_protocolo, servico, flag, land, is_host_login, is_guest_login, root_shell, su_attempted,num_outbound_cmds;

    }Pertinencia;
   
    utilitarios();
    utilitarios(const utilitarios& orig);
    virtual ~utilitarios();
    double converteValorDouble(string str);
    vector< vector<string> > defineVertices(char nomeArqOut[50]);
    double ** defineArestas(vector<string> vertice1, vector<string> vertice2, char nomeArq[50], int tamLinha, int tamColuna, vector<vector<int> > &SC, double confidencia, vector<string> &posicoesHEdge);
    int converteValorInteiro(string str);
    vector<vector<double> > defineHyperArestas(vector<string> verti2,vector<string> verti1, char Arquivo[50], double confidencia, vector<string> &HArestas);
    void TransformaCaracteristicaEmItem(char nomeDaBase[50], vector<string> nomeArqPertinencia);
    void TransformaCaracteristicaDeteccaoEmItem(char nomeDaBase[100], vector<string> nomeArqPertinencia);
    Transacao GeraStruturaTransacaoItens(char nomeDaBaseOriginal[50]);
    vector<vector<double> > GeraMatrizPertinencia(char nomeDoArqPertinencia[50]);
  
private:
    
         typedef struct Tabela
    {
        int duracao, src_bytes, dst_bytes, land, wrong_fragment, urgente, hot;
        int num_faleid_logins, logged_in, num_compromised, root_shell, su_attempted, num_root;
        int num_file_creatinos, num_shells, num_access_files, num_outbound_cmds, is_hot_login;
        int is_guest_login, count, srv_count, dst_host_count, dst_host_srv_count;
        int tipo_protocoloAlt, servicoAlt, flagAlt, tipo_protocoloZero, servicoAltZero, flagAltZero;
        double serror_rate, srv_serror_rate, rerror_rate, srv_rerror_rate, same_srv_rate, diff_srv_rate, srv_diff_host_rate;
        double dst_host_same_srv_rate, dst_host_diff_srv_rate, dst_host_same_src_port_rate, dst_host_srv_diff_host_rate;
        double dst_host_serror_rate, dst_host_srv_serror_rate, dst_host_rerror_rate, dst_host_srv_rerror_rate;
        string tipo_protocolo, servico, flag, etiqueta;
        string duracao1, duracao2, duracao3,src_bytes1, src_bytes2,src_bytes3, dst_bytes1, dst_bytes2, dst_bytes3;
        string wrong_fragment1, wrong_fragment2, wrong_fragment3, urgente1, urgente2, urgente3, hot1, hot2, hot3;
        string num_faleid_logins1, num_faleid_logins2, num_faleid_logins3, num_compromised1, num_compromised2, num_compromised3;
        string num_root1, num_root2, num_root3, num_file_creatinos1, num_file_creatinos2, num_file_creatinos3, num_shells1, num_shells2, num_shells3;
        string num_access_files1, num_access_files2, num_access_files3, count1, count2, count3, srv_count1, srv_count2, srv_count3;
        string serror_rate1, serror_rate2, serror_rate3, srv_serror_rate1, srv_serror_rate2, srv_serror_rate3, rerror_rate1, rerror_rate2, rerror_rate3;
        string srv_rerror_rate1, srv_rerror_rate2, srv_rerror_rate3, same_srv_rate1, same_srv_rate2, same_srv_rate3, diff_srv_rate1,diff_srv_rate2, diff_srv_rate3;
        string srv_diff_host_rate1, srv_diff_host_rate2, srv_diff_host_rate3, dst_host_count1, dst_host_count2, dst_host_count3;
        string dst_host_srv_count1, dst_host_srv_count2, dst_host_srv_count3, dst_host_same_srv_rate1, dst_host_same_srv_rate2, dst_host_same_srv_rate3;
        string dst_host_diff_srv_rate1, dst_host_diff_srv_rate2, dst_host_diff_srv_rate3, dst_host_same_src_port_rate1, dst_host_same_src_port_rate2, dst_host_same_src_port_rate3;
        string dst_host_srv_diff_host_rate1, dst_host_srv_diff_host_rate2, dst_host_srv_diff_host_rate3, dst_host_serror_rate1, dst_host_serror_rate2, dst_host_serror_rate3;
        string dst_host_srv_serror_rate1, dst_host_srv_serror_rate2, dst_host_srv_serror_rate3, dst_host_rerror_rate1, dst_host_rerror_rate2, dst_host_rerror_rate3;
        string dst_host_srv_rerror_rate1, dst_host_srv_rerror_rate2, dst_host_srv_rerror_rate3;
        string land_Item, logged_in_Item, root_shell_Item, su_attempted_Item, num_outbound_cmds_Item, is_hot_login_Item, is_guest_login_Item;

    }Tabela;
};
#endif