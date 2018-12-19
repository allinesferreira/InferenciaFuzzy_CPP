/* 
 * File:   manipulaArquivo.cpp
 * Author: allinesf
 * Ler o arquivo kddcup.data_10_percent_corrected.txt e criar grupos de acordo 
 * com sua classificação, que são elas: 
 * 1 - Classe U2R: sqlattack, perl, xterm, rootkit, httptunnel, ps, 
 * buffer_overflow, loadmodule;
 * 2 - Classe R2L: ftp_write, guess_passwd, impa, phf, xsnoop, multihop, 
 * xlock, named, worm, warezmaster, snmpguess, imap;
 * 3 - Classe Probe: ipsweep, nmap, portsweep, satan, saint, mscan;
 * 4 - Classe DoS: back, land, neptune, pod, smurf, teardrop, back, apache2, 
 * land, mailbomb, processtable, udpstorm;
 * 5 - Classe Normal: não aplicado
 *
 */
#include "PreparaBase.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

PreparaBase::PreparaBase(){
}
    
void PreparaBase::PreparaBaseParaTeste(char nomeDaBase[20]){
    
    Tabela tab;
    long posicao;
    char letra;
    FILE *arq, *arqAlt;
    arq = fopen(nomeDaBase, "rt+");
    arqAlt = fopen("novoArq","at");
    
    //Verificando se os arquivos foram abertos corretamente
    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    
    if(arqAlt == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
       exit(1);
    }
    
    //Substituindo as vírgulas por espaço
    while(!feof(arq)){
        posicao = ftell(arq);
        letra = fgetc(arq);
        if(letra == ','){
            letra = ' ';
            fseek(arq, posicao, SEEK_SET);
            fprintf(arq,"%c",letra);
        }
            
    }
    
    //Reposicionando no início do arquivo
    rewind(arq);
  
    //Capturando as informações, excluindo o campo Etiqueta na base
    
    while(!feof(arq)){
        fscanf(arq,"%i", &tab.duracao);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%s",tab.tipo_protocolo);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%s",tab.servico);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%s",tab.flag );
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.src_bytes);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.dst_bytes);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.land);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.wrong_fragment);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.urgente);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.hot);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.num_faleid_logins);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.logged_in);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.num_compromised);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.root_shell);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.su_attempted);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.num_root);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.num_file_creatinos);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.num_shells);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.num_access_files);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.num_outbound_cmds);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.is_hot_login);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.is_guest_login);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.count);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.srv_count);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.serror_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.srv_serror_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.rerror_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.srv_rerror_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.same_srv_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.diff_srv_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.srv_diff_host_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.dst_host_count);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%d",&tab.dst_host_srv_count);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.dst_host_same_srv_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.dst_host_diff_srv_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.dst_host_same_src_port_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.dst_host_srv_diff_host_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.dst_host_serror_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.dst_host_srv_serror_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.dst_host_rerror_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%lf",&tab.dst_host_srv_rerror_rate);
        fscanf(arq,"%c",&tab.lixo);
        fscanf(arq,"%s", tab.etiqueta);

        fprintf(arqAlt,"%i",tab.duracao);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%s",tab.tipo_protocolo);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%s",tab.servico);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%s",tab.flag);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.src_bytes);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.dst_bytes);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.land);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.wrong_fragment);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.urgente);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.hot);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.num_faleid_logins);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.logged_in);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.num_compromised);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.root_shell);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.su_attempted);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.num_root);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.num_file_creatinos);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.num_shells);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.num_access_files);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.num_outbound_cmds);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.is_hot_login);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.is_guest_login);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.count);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.srv_count);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.serror_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.srv_serror_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.rerror_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.srv_rerror_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.same_srv_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.diff_srv_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.srv_diff_host_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.dst_host_count);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%d",tab.dst_host_srv_count);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.dst_host_same_srv_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.dst_host_diff_srv_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.dst_host_same_src_port_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.dst_host_srv_diff_host_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.dst_host_serror_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.dst_host_srv_serror_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.dst_host_rerror_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%0.2f",tab.dst_host_srv_rerror_rate);
        fprintf(arqAlt,"%c",tab.lixo);
        fprintf(arqAlt,"%s\n", tab.etiqueta);
    }
    
    //Fechando os arquivos
    fclose(arq);
    fclose(arqAlt);
    
    //Excluindo o arquivo original e renomeando o arquivo atualizado
    remove(nomeDaBase);
    rename("novoArq", nomeDaBase);
    
}
