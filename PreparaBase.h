
#ifndef PREPARABASE_H
#define	PREPARABASE_H
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class PreparaBase{
    
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
    
    
}Tabela;

public:
    
    PreparaBase();
    void PreparaBaseParaTeste(char nome[20]);
    
};
 
#endif	

