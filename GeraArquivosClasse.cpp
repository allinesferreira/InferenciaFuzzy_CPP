/* 
 * File:   manipulaArquivo.cpp
 * Author: allinesf
 * Ler o arquivo kddcup.data_10_percent_corrected.txt e criar grupos de acordo 
 * com sua classificação, que são elas: 
 * 1 - Classe U2R: sqlattack, perl, xterm, rootkit, httptunnel, ps, 
 * buffer_overflow, loadmodule;
 * 2 - Classe R2L: ftp_write, guess_passwd, impa, phf, xsnoop, multihop, 
 * xlock, named, worm, warezmaster, snmpguess, imap, warezclient;
 * 3 - Classe Probe: ipsweep, nmap, portsweep, satan, saint, mscan;
 * 4 - Classe DoS: back, land, neptune, pod, smurf, teardrop, back, apache2, 
 * mailbomb, processtable, udpstorm;
 * 5 - Classe Normal: não aplicado
 *
 */
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
#include <bits/stl_vector.h>

using namespace std;

GeraArquivosClasse::GeraArquivosClasse(){
}
void GeraArquivosClasse::CriaArquivosClasse(char nomeDaBase[30]){
    
    long posicao;
    char letra;
    Tab tab;
    FILE *arq, *arqDoS, *arqU2R, *arqR2L, *arqProbe, *arqNormal;
    arq = fopen(nomeDaBase, "rt+");
    arqDoS = fopen("arqDoS.txt","at");
    arqU2R = fopen("arqU2R.txt","at");
    arqR2L = fopen("arqR2L.txt","at");
    arqProbe = fopen("arqProbe.txt","at");
    arqNormal = fopen("arqNormal.txt","at");
    
    
    //Verificando se os arquivos foram abertos corretamente
    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    
    if(arqDoS == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    
    if(arqU2R == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    
    if(arqR2L == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    
    if(arqProbe == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    
    if(arqNormal == NULL)
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
    
    //Capturando as informações e gerando os arquivos para cada classe
    while(!feof(arq)){
        fscanf(arq,"%i",&tab.duracao);
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
                
        if(strcmp(tab.etiqueta, "normal.")==0)
        { 
            fprintf(arqNormal,"%i",tab.duracao);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%s",tab.tipo_protocolo);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%s",tab.servico);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%s",tab.flag);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.src_bytes);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.dst_bytes);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.land);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.wrong_fragment);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.urgente);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.hot);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.num_faleid_logins);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.logged_in);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.num_compromised);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.root_shell);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.su_attempted);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.num_root);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.num_file_creatinos);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.num_shells);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.num_access_files);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.num_outbound_cmds);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.is_hot_login);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.is_guest_login);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.count);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.srv_count);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.serror_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.srv_serror_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.rerror_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.srv_rerror_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.same_srv_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.diff_srv_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.srv_diff_host_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.dst_host_count);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%d",tab.dst_host_srv_count);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.dst_host_same_srv_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.dst_host_diff_srv_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.dst_host_same_src_port_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.dst_host_srv_diff_host_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.dst_host_serror_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.dst_host_srv_serror_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f",tab.dst_host_rerror_rate);
            fprintf(arqNormal,"%c",tab.lixo);
            fprintf(arqNormal,"%0.2f\n",tab.dst_host_srv_rerror_rate);
            //fprintf(arqNormal,"%c\n",tab.lixo);
            //fprintf(arqNormal,"%s\n",tab.etiqueta);
            //fseek(arqNormal, posicao, SEEK_SET);
        }else
        {
            if((strcmp(tab.etiqueta,"sqlattack.")==0)||(strcmp(tab.etiqueta,"perl.")==0)||(strcmp(tab.etiqueta,"xterm.")==0)||(strcmp(tab.etiqueta,"rootkit.")==0)||(strcmp(tab.etiqueta,"httptunnel.")==0)||(strcmp(tab.etiqueta,"ps.")==0)||(strcmp(tab.etiqueta,"buffer_overflow.")==0)||(strcmp(tab.etiqueta,"loadmodule.")==0))
            {
                
                fprintf(arqU2R,"%i",tab.duracao);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%s",tab.tipo_protocolo);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%s",tab.servico);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%s",tab.flag);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.src_bytes);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.dst_bytes);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.land);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.wrong_fragment);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.urgente);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.hot);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.num_faleid_logins);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.logged_in);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.num_compromised);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.root_shell);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.su_attempted);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.num_root);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.num_file_creatinos);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.num_shells);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.num_access_files);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.num_outbound_cmds);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.is_hot_login);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.is_guest_login);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.count);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.srv_count);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.serror_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.srv_serror_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.rerror_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.srv_rerror_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.same_srv_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.diff_srv_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.srv_diff_host_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.dst_host_count);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%d",tab.dst_host_srv_count);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.dst_host_same_srv_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.dst_host_diff_srv_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.dst_host_same_src_port_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.dst_host_srv_diff_host_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.dst_host_serror_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.dst_host_srv_serror_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f",tab.dst_host_rerror_rate);
                fprintf(arqU2R,"%c",tab.lixo);
                fprintf(arqU2R,"%0.2f\n",tab.dst_host_srv_rerror_rate);
                //fprintf(arqU2R,"%c\n",tab.lixo);
                //fprintf(arqU2R,"%s\n",tab.etiqueta);
                //fseek(arqU2R, posicao, SEEK_SET);
            
            }else
            {
                if((strcmp(tab.etiqueta,"ftp_write.")==0)||(strcmp(tab.etiqueta,"guess_passwd.")==0)||(strcmp(tab.etiqueta,"impa.")==0)||(strcmp(tab.etiqueta,"phf.")==0)||(strcmp(tab.etiqueta,"xsnoop.")==0)||(strcmp(tab.etiqueta,"xlock.")==0)||(strcmp(tab.etiqueta,"named.")==0)||(strcmp(tab.etiqueta,"worm.")==0)||(strcmp(tab.etiqueta,"warezmaster.")==0)||(strcmp(tab.etiqueta,"snmpguess.")==0)||(strcmp(tab.etiqueta,"imap.")==0)||(strcmp(tab.etiqueta,"multihop.")==0)||(strcmp(tab.etiqueta,"warezclient.")==0))
                {
                    
                    fprintf(arqR2L,"%i",tab.duracao);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%s",tab.tipo_protocolo);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%s",tab.servico);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%s",tab.flag);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.src_bytes);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.dst_bytes);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.land);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.wrong_fragment);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.urgente);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.hot);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.num_faleid_logins);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.logged_in);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.num_compromised);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.root_shell);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.su_attempted);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.num_root);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.num_file_creatinos);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.num_shells);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.num_access_files);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.num_outbound_cmds);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.is_hot_login);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.is_guest_login);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.count);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.srv_count);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.serror_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.srv_serror_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.rerror_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.srv_rerror_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.same_srv_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.diff_srv_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.srv_diff_host_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.dst_host_count);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%d",tab.dst_host_srv_count);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.dst_host_same_srv_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.dst_host_diff_srv_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.dst_host_same_src_port_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.dst_host_srv_diff_host_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.dst_host_serror_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.dst_host_srv_serror_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f",tab.dst_host_rerror_rate);
                    fprintf(arqR2L,"%c",tab.lixo);
                    fprintf(arqR2L,"%0.2f\n",tab.dst_host_srv_rerror_rate);
                    //fprintf(arqR2L,"%c\n",tab.lixo);
                   // fprintf(arqR2L,"%s\n",tab.etiqueta);
                    //fseek(arqR2L, posicao, SEEK_SET);
                    
                }else
                {
                    if((strcmp(tab.etiqueta,"ipsweep.")==0)||(strcmp(tab.etiqueta,"nmap.")==0)||(strcmp(tab.etiqueta,"portsweep.")==0)||(strcmp(tab.etiqueta,"satan.")==0)||(strcmp(tab.etiqueta,"saint.")==0)||(strcmp(tab.etiqueta,"mscan.")==0))
                    {
                       
                        fprintf(arqProbe,"%i",tab.duracao);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%s",tab.tipo_protocolo);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%s",tab.servico);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%s",tab.flag);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.src_bytes);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.dst_bytes);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.land);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.wrong_fragment);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.urgente);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.hot);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.num_faleid_logins);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.logged_in);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.num_compromised);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.root_shell);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.su_attempted);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.num_root);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.num_file_creatinos);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.num_shells);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.num_access_files);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.num_outbound_cmds);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.is_hot_login);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.is_guest_login);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.count);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.srv_count);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.serror_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.srv_serror_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.rerror_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.srv_rerror_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.same_srv_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.diff_srv_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.srv_diff_host_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.dst_host_count);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%d",tab.dst_host_srv_count);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.dst_host_same_srv_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.dst_host_diff_srv_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.dst_host_same_src_port_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.dst_host_srv_diff_host_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.dst_host_serror_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.dst_host_srv_serror_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f",tab.dst_host_rerror_rate);
                        fprintf(arqProbe,"%c",tab.lixo);
                        fprintf(arqProbe,"%0.2f\n",tab.dst_host_srv_rerror_rate);
                        //fprintf(arqProbe,"%c\n",tab.lixo);
                        //fprintf(arqProbe,"%s\n",tab.etiqueta);
                        //fseek(arqProbe, posicao, SEEK_SET);
                    
                    }else
                    {
                        if((strcmp(tab.etiqueta,"back.")==0)||(strcmp(tab.etiqueta,"land.")==0)||(strcmp(tab.etiqueta,"neptune.")==0)||(strcmp(tab.etiqueta,"pod.")==0)||(strcmp(tab.etiqueta,"smurf.")==0)||(strcmp(tab.etiqueta,"teardrop.")==0)||(strcmp(tab.etiqueta,"back.")==0)||(strcmp(tab.etiqueta,"apache2.")==0)||(strcmp(tab.etiqueta,"land.")==0)||(strcmp(tab.etiqueta,"mailbomb.")==0)||(strcmp(tab.etiqueta,"processtable.")==0)||(strcmp(tab.etiqueta,"udpstorm.")==0))
                        {
                          
                            fprintf(arqDoS,"%i",tab.duracao);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%s",tab.tipo_protocolo);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%s",tab.servico);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%s",tab.flag);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.src_bytes);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.dst_bytes);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.land);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.wrong_fragment);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.urgente);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.hot);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.num_faleid_logins);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.logged_in);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.num_compromised);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.root_shell);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.su_attempted);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.num_root);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.num_file_creatinos);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.num_shells);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.num_access_files);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.num_outbound_cmds);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.is_hot_login);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.is_guest_login);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.count);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.srv_count);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.serror_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.srv_serror_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.rerror_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.srv_rerror_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.same_srv_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.diff_srv_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.srv_diff_host_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.dst_host_count);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%d",tab.dst_host_srv_count);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.dst_host_same_srv_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.dst_host_diff_srv_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.dst_host_same_src_port_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.dst_host_srv_diff_host_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.dst_host_serror_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.dst_host_srv_serror_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f",tab.dst_host_rerror_rate);
                            fprintf(arqDoS,"%c",tab.lixo);
                            fprintf(arqDoS,"%0.2f\n",tab.dst_host_srv_rerror_rate);
                            //fprintf(arqDoS,"%c\n",tab.lixo);
                           // fprintf(arqDoS,"%s\n",tab.etiqueta);
                            //fseek(arqDoS, posicao, SEEK_SET);
                        
                        }
                        
                    }
                    
                }
            }
        }
    }
    
    //Fechando os arquivos
    fclose(arq);
    fclose(arqNormal);
    fclose(arqU2R);
    fclose(arqR2L);
    fclose(arqProbe);
    fclose(arqDoS);
       
}
void GeraArquivosClasse::Cria2ClassesArquivos(char nomeDaBase[50], vector<string> nomeClasseA){
    
    /*
     * Esse método gera duas classes a partir da classe A,
     * ou seja, o primeiro arquivo será a classeA e o segundo arquivo todo os demais.
     */
    utilitarios::Pertinencia pert;
    
    Tab tab;
    int contVerdadeiros=0, contaPresente=0;
    vector<string> nome;
    ifstream inputNomeBase;
    ifstream inputPert1,inputPert5, inputPert6, inputPert8, inputPert9, inputPert10, inputPert11, inputPert13, inputPert16, inputPert17;
    ifstream inputPert18, inputPert19, inputPert23, inputPert24, inputPert25, inputPert26, inputPert27, inputPert28, inputPert29, inputPert30;
    ifstream inputPert31, inputPert32, inputPert33, inputPert34, inputPert35, inputPert36, inputPert37, inputPert38, inputPert39, inputPert40, inputPert41;
    ofstream outputCA("ClasseA");
    ofstream outputCB("ClasseB");
    ofstream outputP1CA("UTeste1_CA"), outputP5CA("UTeste5_CA"), outputP6CA("UTeste6_CA"), outputP8CA("UTeste8_CA"), outputP9CA("UTeste9_CA");
    ofstream outputP10CA("UTeste10_CA"), outputP11CA("UTeste11_CA"), outputP13CA("UTeste13_CA"), outputP16CA("UTeste16_CA"), outputP17CA("UTeste17_CA");
    ofstream outputP18CA("UTeste18_CA"), outputP19CA("UTeste19_CA"), outputP23CA("UTeste23_CA"), outputP24CA("UTeste24_CA"), outputP25CA("UTeste25_CA"), outputP26CA("UTeste26_CA");
    ofstream outputP27CA("UTeste27_CA"), outputP28CA("UTeste28_CA"), outputP29CA("UTeste29_CA"), outputP30CA("UTeste30_CA"), outputP31CA("UTeste31_CA");
    ofstream outputP32CA("UTeste32_CA"), outputP33CA("UTeste33_CA"), outputP34CA("UTeste34_CA"), outputP35CA("UTeste35_CA"), outputP36CA("UTeste36_CA");
    ofstream outputP37CA("UTeste37_CA"), outputP38CA("UTeste38_CA"), outputP39CA("UTeste39_CA"), outputP40CA("UTeste40_CA"), outputP41CA("UTeste41_CA");
    ofstream outputP1CB("UTeste1_CB"), outputP5CB("UTeste5_CB"), outputP6CB("UTeste6_CB"), outputP8CB("UTeste8_CB"), outputP9CB("UTeste9_CB");
    ofstream outputP10CB("UTeste10_CB"), outputP11CB("UTeste11_CB"), outputP13CB("UTeste13_CB"), outputP16CB("UTeste16_CB"), outputP17CB("UTeste17_CB");
    ofstream outputP18CB("UTeste18_CB"), outputP19CB("UTeste19_CB"), outputP23CB("UTeste23_CB"), outputP24CB("UTeste24_CB"), outputP25CB("UTeste25_CB"), outputP26CB("UTeste26_CB");
    ofstream outputP27CB("UTeste27_CB"), outputP28CB("UTeste28_CB"), outputP29CB("UTeste29_CB"), outputP30CB("UTeste30_CB"), outputP31CB("UTeste31_CB");
    ofstream outputP32CB("UTeste32_CB"), outputP33CB("UTeste33_CB"), outputP34CB("UTeste34_CB"), outputP35CB("UTeste35_CB"), outputP36CB("UTeste36_CB");
    ofstream outputP37CB("UTeste37_CB"), outputP38CB("UTeste38_CB"), outputP39CB("UTeste39_CB"), outputP40CB("UTeste40_CB"), outputP41CB("UTeste41_CB");
    
    
    inputNomeBase.open(nomeDaBase, ifstream::in);
    inputPert1.open("UTeste1",ifstream::in);
    inputPert5.open("UTeste5",ifstream::in);
    inputPert6.open("UTeste6",ifstream::in);
    inputPert8.open("UTeste8",ifstream::in);
    inputPert9.open("UTeste9",ifstream::in);
    inputPert10.open("UTeste10",ifstream::in);
    inputPert11.open("UTeste11",ifstream::in);
    inputPert13.open("UTeste13",ifstream::in);
    inputPert16.open("UTeste16",ifstream::in);
    inputPert17.open("UTeste17",ifstream::in);
    inputPert18.open("UTeste18",ifstream::in);
    inputPert19.open("UTeste19",ifstream::in);
    inputPert23.open("UTeste23",ifstream::in);
    inputPert24.open("UTeste24",ifstream::in);
    inputPert25.open("UTeste25",ifstream::in);
    inputPert26.open("UTeste26",ifstream::in);
    inputPert27.open("UTeste27",ifstream::in);
    inputPert28.open("UTeste28",ifstream::in);
    inputPert29.open("UTeste29",ifstream::in);
    inputPert30.open("UTeste30",ifstream::in);
    inputPert31.open("UTeste31",ifstream::in);
    inputPert32.open("UTeste32",ifstream::in);
    inputPert33.open("UTeste33",ifstream::in);
    inputPert34.open("UTeste34",ifstream::in);
    inputPert35.open("UTeste35",ifstream::in);
    inputPert36.open("UTeste36",ifstream::in);
    inputPert37.open("UTeste37",ifstream::in);
    inputPert38.open("UTeste38",ifstream::in);
    inputPert39.open("UTeste39",ifstream::in);
    inputPert40.open("UTeste40",ifstream::in);
    inputPert41.open("UTeste41",ifstream::in);
    
    nome = nomeClasseA;
    cout<<"Imprimindo ClasseA"<<endl;
    for(int i=0; i<nome.size();i++){
        cout<<nome.at(i)<<endl;
               
    }
 
    //Tratamento de erro caso os arquivos não existam
    if(!inputNomeBase.is_open()){
        printf("Erro na abertura dos arquivos!");
        inputNomeBase.clear();
        exit(1);
    }
    
    if((!inputPert1.is_open())||(!inputPert5.is_open())||(!inputPert6.is_open())||(!inputPert8.is_open())||(!inputPert9.is_open())||(!inputPert10.is_open())||(!inputPert11.is_open())){
        printf("Erro na abertura dos arquivos!");
        inputPert1.clear();
        inputPert5.clear();
        inputPert6.clear();
        inputPert8.clear();
        inputPert9.clear();
        inputPert10.clear();
        inputPert11.clear();
        exit(1);
    }
    
    if((!inputPert13.is_open())||(!inputPert16.is_open())||(!inputPert17.is_open())||(!inputPert18.is_open())||(!inputPert19.is_open())||(!inputPert23.is_open())||(!inputPert24.is_open())){
        printf("Erro na abertura dos arquivos!");
        inputPert13.clear();
        inputPert16.clear();
        inputPert17.clear();
        inputPert18.clear();
        inputPert19.clear();
        inputPert23.clear();
        inputPert24.clear();
        exit(1);
    }
    
    if((!inputPert25.is_open())||(!inputPert26.is_open())||(!inputPert27.is_open())||(!inputPert28.is_open())||(!inputPert29.is_open())||(!inputPert30.is_open())||(!inputPert31.is_open())){
        printf("Erro na abertura dos arquivos!");
        inputPert25.clear();
        inputPert26.clear();
        inputPert27.clear();
        inputPert28.clear();
        inputPert29.clear();
        inputPert30.clear();
        inputPert31.clear();
        exit(1);
    }
    if((!inputPert32.is_open())||(!inputPert33.is_open())||(!inputPert34.is_open())||(!inputPert35.is_open())||(!inputPert36.is_open())||(!inputPert37.is_open())||(!inputPert38.is_open())){
        printf("Erro na abertura dos arquivos!");
        inputPert32.clear();
        inputPert33.clear();
        inputPert34.clear();
        inputPert35.clear();
        inputPert36.clear();
        inputPert37.clear();
        inputPert38.clear();
        exit(1);        
    }
    if((!inputPert39.is_open())||(!inputPert40.is_open())||(!inputPert41.is_open())){
        printf("Erro na abertura dos arquivos!");
        inputPert39.clear();
        inputPert40.clear();
        inputPert41.clear();
        exit(1);
    }
    //Tratamento de erro para o arquivo de saída
    if((!outputCA.is_open())||(!outputCB.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputCA.clear();
        outputCB.clear();
        exit(1);
    }
    if((!outputP1CA.is_open())||(!outputP5CA.is_open())||(!outputP6CA.is_open())||(!outputP8CA.is_open())||(!outputP9CA.is_open())||(!outputP10CA.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputP1CA.clear();
        outputP5CA.clear();
        outputP6CA.clear();
        outputP8CA.clear();
        outputP9CA.clear();
        outputP10CA.clear();
        exit(1);
    }
    if((!outputP11CA.is_open())||(!outputP13CA.is_open())||(!outputP16CA.is_open())||(!outputP17CA.is_open())||(!outputP18CA.is_open())||(!outputP19CA.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputP11CA.clear();
        outputP13CA.clear();
        outputP16CA.clear();
        outputP17CA.clear();
        outputP18CA.clear();
        outputP19CA.clear();
        exit(1);
    }
    if((!outputP23CA.is_open())||(!outputP24CA.is_open())||(!outputP25CA.is_open())||(!outputP26CA.is_open())||(!outputP27CA.is_open())||(!outputP28CA.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputP23CA.clear();
        outputP24CA.clear();
        outputP25CA.clear();
        outputP26CA.clear();
        outputP27CA.clear();
        outputP28CA.clear();
        exit(1);
    }
    if((!outputP29CA.is_open())||(!outputP30CA.is_open())||(!outputP31CA.is_open())||(!outputP32CA.is_open())||(!outputP33CA.is_open())||(!outputP34CA.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputP29CA.clear();
        outputP30CA.clear();
        outputP31CA.clear();
        outputP32CA.clear();
        outputP33CA.clear();
        outputP34CA.clear();
        exit(1);
    }
    if((!outputP35CA.is_open())||(!outputP36CA.is_open())||(!outputP37CA.is_open())||(!outputP38CA.is_open())||(!outputP39CA.is_open())||(!outputP40CA.is_open())||(!outputP41CA.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputP35CA.clear();
        outputP36CA.clear();
        outputP37CA.clear();
        outputP38CA.clear();
        outputP39CA.clear();
        outputP40CA.clear();
        outputP41CA.clear();
        exit(1);
    }
    
    if((!outputP1CB.is_open())||(!outputP5CB.is_open())||(!outputP6CB.is_open())||(!outputP8CB.is_open())||(!outputP9CB.is_open())||(!outputP10CB.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputP1CB.clear();
        outputP5CB.clear();
        outputP6CB.clear();
        outputP8CB.clear();
        outputP9CB.clear();
        outputP10CB.clear();
        exit(1);
    }
    if((!outputP11CB.is_open())||(!outputP13CB.is_open())||(!outputP16CB.is_open())||(!outputP17CB.is_open())||(!outputP18CB.is_open())||(!outputP19CB.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputP11CB.clear();
        outputP13CB.clear();
        outputP16CB.clear();
        outputP17CB.clear();
        outputP18CB.clear();
        outputP19CB.clear();
        exit(1);
    }
    if((!outputP23CB.is_open())||(!outputP24CB.is_open())||(!outputP25CB.is_open())||(!outputP26CB.is_open())||(!outputP27CB.is_open())||(!outputP28CB.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputP23CB.clear();
        outputP24CB.clear();
        outputP25CB.clear();
        outputP26CB.clear();
        outputP27CB.clear();
        outputP28CB.clear();
        exit(1);
    }
    if((!outputP29CB.is_open())||(!outputP30CB.is_open())||(!outputP31CB.is_open())||(!outputP32CB.is_open())||(!outputP33CB.is_open())||(!outputP34CB.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputP29CB.clear();
        outputP30CB.clear();
        outputP31CB.clear();
        outputP32CB.clear();
        outputP33CB.clear();
        outputP34CB.clear();
        exit(1);
    }
    if((!outputP35CB.is_open())||(!outputP36CB.is_open())||(!outputP37CB.is_open())||(!outputP38CB.is_open())||(!outputP39CB.is_open())||(!outputP40CB.is_open())||(!outputP41CB.is_open())){
        printf("Erro na abertura dos arquivos!");
        outputP35CB.clear();
        outputP36CB.clear();
        outputP37CB.clear();
        outputP38CB.clear();
        outputP39CB.clear();
        outputP40CB.clear();
        outputP41CB.clear();
        exit(1);
    }
    
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(true){
        
        inputNomeBase>>tab.duracao;
        inputNomeBase>>tab.tipo_protocolo;
        inputNomeBase>>tab.servico;
        inputNomeBase>>tab.flag;
        inputNomeBase>>tab.src_bytes;
        inputNomeBase>>tab.dst_bytes;
        inputNomeBase>>tab.land;
        inputNomeBase>>tab.wrong_fragment;
        inputNomeBase>>tab.urgente;
        inputNomeBase>>tab.hot;
        inputNomeBase>>tab.num_faleid_logins;
        inputNomeBase>>tab.logged_in;
        inputNomeBase>>tab.num_compromised;
        inputNomeBase>>tab.root_shell;
        inputNomeBase>>tab.su_attempted;
        inputNomeBase>>tab.num_root;
        inputNomeBase>>tab.num_file_creatinos;
        inputNomeBase>>tab.num_shells;
        inputNomeBase>>tab.num_access_files;
        inputNomeBase>>tab.num_outbound_cmds;
        inputNomeBase>>tab.is_hot_login;
        inputNomeBase>>tab.is_guest_login;
        inputNomeBase>>tab.count;
        inputNomeBase>>tab.srv_count;
        inputNomeBase>>tab.serror_rate;
        inputNomeBase>>tab.srv_serror_rate;
        inputNomeBase>>tab.rerror_rate;
        inputNomeBase>>tab.srv_rerror_rate;
        inputNomeBase>>tab.same_srv_rate;
        inputNomeBase>>tab.diff_srv_rate;
        inputNomeBase>>tab.srv_diff_host_rate;
        inputNomeBase>>tab.dst_host_count;
        inputNomeBase>>tab.dst_host_srv_count;
        inputNomeBase>>tab.dst_host_same_srv_rate;
        inputNomeBase>>tab.dst_host_diff_srv_rate;
        inputNomeBase>>tab.dst_host_same_src_port_rate;
        inputNomeBase>>tab.dst_host_srv_diff_host_rate;
        inputNomeBase>>tab.dst_host_serror_rate;
        inputNomeBase>>tab.dst_host_srv_serror_rate;
        inputNomeBase>>tab.dst_host_rerror_rate;
        inputNomeBase>>tab.dst_host_srv_rerror_rate;
        inputNomeBase>>tab.etiqueta;
        inputPert1>>pert.duracaoBaixa;
        inputPert1>>pert.duracaoMedia;
        inputPert1>>pert.duracaoAlta;
        inputPert5>>pert.src_bytesBaixa;
        inputPert5>>pert.src_bytesMedia;
        inputPert5>>pert.src_bytesAlta;
        inputPert6>>pert.dst_bytesBaixa;
        inputPert6>>pert.dst_bytesMedia;
        inputPert6>>pert.dst_bytesAlta;
        inputPert8>>pert.wrong_fragmentBaixa;
        inputPert8>>pert.wrong_fragmentMedia;
        inputPert8>>pert.wrong_fragmentAlta;
        inputPert9>>pert.urgenteBaixa;
        inputPert9>>pert.urgenteMedia;
        inputPert9>>pert.urgenteAlta;
        inputPert10>>pert.hotBaixa;
        inputPert10>>pert.hotMedia;
        inputPert10>>pert.hotAlta;
        inputPert11>>pert.num_faleid_loginsBaixa;
        inputPert11>>pert.num_faleid_loginsMedia;
        inputPert11>>pert.num_faleid_loginsAlta;
        inputPert13>>pert.num_compromisedBaixa;
        inputPert13>>pert.num_compromisedMedia;
        inputPert13>>pert.num_compromisedAlta;
        inputPert16>>pert.num_rootBaixa;
        inputPert16>>pert.num_rootMedia;
        inputPert16>>pert.num_rootAlta;
        inputPert17>>pert.num_file_creatinosBaixa;
        inputPert17>>pert.num_file_creatinosMedia;
        inputPert17>>pert.num_file_creatinosAlta;
        inputPert18>>pert.num_shellsBaixa;
        inputPert18>>pert.num_shellsMedia;
        inputPert18>>pert.num_shellsAlta;
        inputPert19>>pert.num_access_filesBaixa;
        inputPert19>>pert.num_access_filesMedia;
        inputPert19>>pert.num_access_filesAlta;
        inputPert23>>pert.countBaixa;
        inputPert23>>pert.countMedia;
        inputPert23>>pert.countAlta;
        inputPert24>>pert.srv_countBaixa;
        inputPert24>>pert.srv_countMedia;
        inputPert24>>pert.srv_countAlta;
        inputPert25>>pert.serror_rateBaixa;
        inputPert25>>pert.serror_rateMedia;
        inputPert25>>pert.serror_rateAlta;
        inputPert26>>pert.srv_serror_rateBaixa;
        inputPert26>>pert.srv_serror_rateMedia;
        inputPert26>>pert.srv_serror_rateAlta;
        inputPert27>>pert.rerror_rateBaixa;
        inputPert27>>pert.rerror_rateMedia;
        inputPert27>>pert.rerror_rateAlta;
        inputPert28>>pert.srv_rerror_rateBaixa;
        inputPert28>>pert.srv_rerror_rateMedia;
        inputPert28>>pert.srv_rerror_rateAlta;
        inputPert29>>pert.same_srv_rateBaixa;
        inputPert29>>pert.same_srv_rateMedia;
        inputPert29>>pert.same_srv_rateAlta;
        inputPert30>>pert.diff_srv_rateBaixa;
        inputPert30>>pert.diff_srv_rateMedia;
        inputPert30>>pert.diff_srv_rateAlta;
        inputPert31>>pert.srv_diff_host_rateBaixa;
        inputPert31>>pert.srv_diff_host_rateMedia;
        inputPert31>>pert.srv_diff_host_rateAlta;
        inputPert32>>pert.dst_host_countBaixa;
        inputPert32>>pert.dst_host_countMedia;
        inputPert32>>pert.dst_host_countAlta;
        inputPert33>>pert.dst_host_srv_countBaixa;
        inputPert33>>pert.dst_host_srv_countMedia;
        inputPert33>>pert.dst_host_srv_countAlta;
        inputPert34>>pert.dst_host_same_srv_rateBaixa;
        inputPert34>>pert.dst_host_same_srv_rateMedia;
        inputPert34>>pert.dst_host_same_srv_rateAlta;
        inputPert35>>pert.dst_host_diff_srv_rateBaixa;
        inputPert35>>pert.dst_host_diff_srv_rateMedia;
        inputPert35>>pert.dst_host_diff_srv_rateAlta;
        inputPert36>>pert.dst_host_same_src_port_rateBaixa;
        inputPert36>>pert.dst_host_same_src_port_rateMedia;
        inputPert36>>pert.dst_host_same_src_port_rateAlta;
        inputPert37>>pert.dst_host_srv_diff_host_rateBaixa;
        inputPert37>>pert.dst_host_srv_diff_host_rateMedia;
        inputPert37>>pert.dst_host_srv_diff_host_rateAlta;
        inputPert38>>pert.dst_host_serror_rateBaixa;
        inputPert38>>pert.dst_host_serror_rateMedia;
        inputPert38>>pert.dst_host_serror_rateAlta;
        inputPert39>>pert.dst_host_srv_serror_rateBaixa;
        inputPert39>>pert.dst_host_srv_serror_rateMedia;
        inputPert39>>pert.dst_host_srv_serror_rateAlta;
        inputPert40>>pert.dst_host_rerror_rateBaixa;
        inputPert40>>pert.dst_host_rerror_rateMedia;
        inputPert40>>pert.dst_host_rerror_rateAlta;
        inputPert41>>pert.dst_host_srv_rerror_rateBaixa;
        inputPert41>>pert.dst_host_srv_rerror_rateMedia;
        inputPert41>>pert.dst_host_srv_rerror_rateAlta;
        
        if(inputNomeBase.eof()) break;
        
        //Grava registro
        for(int i=0; i<nome.size();i++){
            if(nome.at(i) == tab.etiqueta){
                contaPresente++;
            }
        }
        //Se contaPresente for diferente de zero ele pertence ao conjunto de nomes da classe de ataque
        if(contaPresente!=0){
            outputCA<<tab.duracao<<" ";
            outputCA<<tab.tipo_protocolo<<" ";
            outputCA<<tab.servico<<" ";
            outputCA<<tab.flag<<" ";
            outputCA<<tab.src_bytes<<" ";
            outputCA<<tab.dst_bytes<<" ";
            outputCA<<tab.land<<" ";
            outputCA<<tab.wrong_fragment<<" ";
            outputCA<<tab.urgente<<" ";
            outputCA<<tab.hot<<" ";
            outputCA<<tab.num_faleid_logins<<" ";
            outputCA<<tab.logged_in<<" ";
            outputCA<<tab.num_compromised<<" ";
            outputCA<<tab.root_shell<<" ";
            outputCA<<tab.su_attempted<<" ";
            outputCA<<tab.num_root<<" ";
            outputCA<<tab.num_file_creatinos<<" ";
            outputCA<<tab.num_shells<<" ";
            outputCA<<tab.num_access_files<<" ";
            outputCA<<tab.num_outbound_cmds<<" ";
            outputCA<<tab.is_hot_login<<" ";
            outputCA<<tab.is_guest_login<<" ";
            outputCA<<tab.count<<" ";
            outputCA<<tab.srv_count<<" ";
            outputCA<<tab.serror_rate<<" ";
            outputCA<<tab.srv_serror_rate<<" ";
            outputCA<<tab.rerror_rate<<" ";
            outputCA<<tab.srv_rerror_rate<<" ";
            outputCA<<tab.same_srv_rate<<" ";
            outputCA<<tab.diff_srv_rate<<" ";
            outputCA<<tab.srv_diff_host_rate<<" ";
            outputCA<<tab.dst_host_count<<" ";
            outputCA<<tab.dst_host_srv_count<<" ";
            outputCA<<tab.dst_host_same_srv_rate<<" ";
            outputCA<<tab.dst_host_diff_srv_rate<<" ";
            outputCA<<tab.dst_host_same_src_port_rate<<" ";
            outputCA<<tab.dst_host_srv_diff_host_rate<<" ";
            outputCA<<tab.dst_host_serror_rate<<" ";
            outputCA<<tab.dst_host_srv_serror_rate<<" ";
            outputCA<<tab.dst_host_rerror_rate<<" ";
            outputCA<<tab.dst_host_srv_rerror_rate<<" ";
            outputCA<<tab.etiqueta<<endl;        

            outputP1CA<<pert.duracaoBaixa<<" ";
            outputP1CA<<pert.duracaoMedia<<" ";
            outputP1CA<<pert.duracaoAlta<<endl;
            outputP5CA<<pert.src_bytesBaixa<<" ";
            outputP5CA<<pert.src_bytesMedia<<" ";
            outputP5CA<<pert.src_bytesAlta<<endl;
            outputP6CA<<pert.dst_bytesBaixa<<" ";
            outputP6CA<<pert.dst_bytesMedia<<" ";
            outputP6CA<<pert.dst_bytesAlta<<endl;
            outputP8CA<<pert.wrong_fragmentBaixa<<" ";
            outputP8CA<<pert.wrong_fragmentMedia<<" ";
            outputP8CA<<pert.wrong_fragmentAlta<<endl;
            outputP9CA<<pert.urgenteBaixa<<" ";
            outputP9CA<<pert.urgenteMedia<<" ";
            outputP9CA<<pert.urgenteAlta<<endl;
            outputP10CA<<pert.hotBaixa<<" ";
            outputP10CA<<pert.hotMedia<<" ";
            outputP10CA<<pert.hotAlta<<endl;
            outputP11CA<<pert.num_faleid_loginsBaixa<<" ";
            outputP11CA<<pert.num_faleid_loginsMedia<<" ";
            outputP11CA<<pert.num_faleid_loginsAlta<<endl;
            outputP13CA<<pert.num_compromisedBaixa<<" ";
            outputP13CA<<pert.num_compromisedMedia<<" ";
            outputP13CA<<pert.num_compromisedAlta<<endl;
            outputP16CA<<pert.num_rootBaixa<<" ";
            outputP16CA<<pert.num_rootMedia<<" ";
            outputP16CA<<pert.num_rootAlta<<endl;
            outputP17CA<<pert.num_file_creatinosBaixa<<" ";
            outputP17CA<<pert.num_file_creatinosMedia<<" ";
            outputP17CA<<pert.num_file_creatinosAlta<<endl;
            outputP18CA<<pert.num_shellsBaixa<<" ";
            outputP18CA<<pert.num_shellsMedia<<" ";
            outputP18CA<<pert.num_shellsAlta<<endl;
            outputP19CA<<pert.num_access_filesBaixa<<" ";
            outputP19CA<<pert.num_access_filesMedia<<" ";
            outputP19CA<<pert.num_access_filesAlta<<endl;
            outputP23CA<<pert.countBaixa<<" ";
            outputP23CA<<pert.countMedia<<" ";
            outputP23CA<<pert.countAlta<<endl;
            outputP24CA<<pert.srv_countBaixa<<" ";
            outputP24CA<<pert.srv_countMedia<<" ";
            outputP24CA<<pert.srv_countAlta<<endl;
            outputP25CA<<pert.serror_rateBaixa<<" ";
            outputP25CA<<pert.serror_rateMedia<<" ";
            outputP25CA<<pert.serror_rateAlta<<endl;
            outputP26CA<<pert.srv_serror_rateBaixa<<" ";
            outputP26CA<<pert.srv_serror_rateMedia<<" ";
            outputP26CA<<pert.srv_serror_rateAlta<<endl;
            outputP27CA<<pert.rerror_rateBaixa<<" ";
            outputP27CA<<pert.rerror_rateMedia<<" ";
            outputP27CA<<pert.rerror_rateAlta<<endl;
            outputP28CA<<pert.srv_rerror_rateBaixa<<" ";
            outputP28CA<<pert.srv_rerror_rateMedia<<" ";
            outputP28CA<<pert.srv_rerror_rateAlta<<endl;
            outputP29CA<<pert.same_srv_rateBaixa<<" ";
            outputP29CA<<pert.same_srv_rateMedia<<" ";
            outputP29CA<<pert.same_srv_rateAlta<<endl;
            outputP30CA<<pert.diff_srv_rateBaixa<<" ";
            outputP30CA<<pert.diff_srv_rateMedia<<" ";
            outputP30CA<<pert.diff_srv_rateAlta<<endl;
            outputP31CA<<pert.srv_diff_host_rateBaixa<<" ";
            outputP31CA<<pert.srv_diff_host_rateMedia<<" ";
            outputP31CA<<pert.srv_diff_host_rateAlta<<endl;
            outputP32CA<<pert.dst_host_countBaixa<<" ";
            outputP32CA<<pert.dst_host_countMedia<<" ";
            outputP32CA<<pert.dst_host_countAlta<<endl;
            outputP33CA<<pert.dst_host_srv_countBaixa<<" ";
            outputP33CA<<pert.dst_host_srv_countMedia<<" ";
            outputP33CA<<pert.dst_host_srv_countAlta<<endl;
            outputP34CA<<pert.dst_host_same_srv_rateBaixa<<" ";
            outputP34CA<<pert.dst_host_same_srv_rateMedia<<" ";
            outputP34CA<<pert.dst_host_same_srv_rateAlta<<endl;
            outputP35CA<<pert.dst_host_diff_srv_rateBaixa<<" ";
            outputP35CA<<pert.dst_host_diff_srv_rateMedia<<" ";
            outputP35CA<<pert.dst_host_diff_srv_rateAlta<<endl;
            outputP36CA<<pert.dst_host_same_src_port_rateBaixa<<" ";
            outputP36CA<<pert.dst_host_same_src_port_rateMedia<<" ";
            outputP36CA<<pert.dst_host_same_src_port_rateAlta<<endl;
            outputP37CA<<pert.dst_host_srv_diff_host_rateBaixa<<" ";
            outputP37CA<<pert.dst_host_srv_diff_host_rateMedia<<" ";
            outputP37CA<<pert.dst_host_srv_diff_host_rateAlta<<endl;
            outputP38CA<<pert.dst_host_serror_rateBaixa<<" ";
            outputP38CA<<pert.dst_host_serror_rateMedia<<" ";
            outputP38CA<<pert.dst_host_serror_rateAlta<<endl;
            outputP39CA<<pert.dst_host_srv_serror_rateBaixa<<" ";
            outputP39CA<<pert.dst_host_srv_serror_rateMedia<<" ";
            outputP39CA<<pert.dst_host_srv_serror_rateAlta<<endl;
            outputP40CA<<pert.dst_host_rerror_rateBaixa<<" ";
            outputP40CA<<pert.dst_host_rerror_rateMedia<<" ";
            outputP40CA<<pert.dst_host_rerror_rateAlta<<endl;
            outputP41CA<<pert.dst_host_srv_rerror_rateBaixa<<" ";
            outputP41CA<<pert.dst_host_srv_rerror_rateMedia<<" ";
            outputP41CA<<pert.dst_host_srv_rerror_rateAlta<<endl;
        }else{
            outputCB<<tab.duracao<<" ";
            outputCB<<tab.tipo_protocolo<<" ";
            outputCB<<tab.servico<<" ";
            outputCB<<tab.flag<<" ";
            outputCB<<tab.src_bytes<<" ";
            outputCB<<tab.dst_bytes<<" ";
            outputCB<<tab.land<<" ";
            outputCB<<tab.wrong_fragment<<" ";
            outputCB<<tab.urgente<<" ";
            outputCB<<tab.hot<<" ";
            outputCB<<tab.num_faleid_logins<<" ";
            outputCB<<tab.logged_in<<" ";
            outputCB<<tab.num_compromised<<" ";
            outputCB<<tab.root_shell<<" ";
            outputCB<<tab.su_attempted<<" ";
            outputCB<<tab.num_root<<" ";
            outputCB<<tab.num_file_creatinos<<" ";
            outputCB<<tab.num_shells<<" ";
            outputCB<<tab.num_access_files<<" ";
            outputCB<<tab.num_outbound_cmds<<" ";
            outputCB<<tab.is_hot_login<<" ";
            outputCB<<tab.is_guest_login<<" ";
            outputCB<<tab.count<<" ";
            outputCB<<tab.srv_count<<" ";
            outputCB<<tab.serror_rate<<" ";
            outputCB<<tab.srv_serror_rate<<" ";
            outputCB<<tab.rerror_rate<<" ";
            outputCB<<tab.srv_rerror_rate<<" ";
            outputCB<<tab.same_srv_rate<<" ";
            outputCB<<tab.diff_srv_rate<<" ";
            outputCB<<tab.srv_diff_host_rate<<" ";
            outputCB<<tab.dst_host_count<<" ";
            outputCB<<tab.dst_host_srv_count<<" ";
            outputCB<<tab.dst_host_same_srv_rate<<" ";
            outputCB<<tab.dst_host_diff_srv_rate<<" ";
            outputCB<<tab.dst_host_same_src_port_rate<<" ";
            outputCB<<tab.dst_host_srv_diff_host_rate<<" ";
            outputCB<<tab.dst_host_serror_rate<<" ";
            outputCB<<tab.dst_host_srv_serror_rate<<" ";
            outputCB<<tab.dst_host_rerror_rate<<" ";
            outputCB<<tab.dst_host_srv_rerror_rate<<" ";
            outputCB<<tab.etiqueta<<endl;     

            outputP1CB<<pert.duracaoBaixa<<" ";
            outputP1CB<<pert.duracaoMedia<<" ";
            outputP1CB<<pert.duracaoAlta<<endl;
            outputP5CB<<pert.src_bytesBaixa<<" ";
            outputP5CB<<pert.src_bytesMedia<<" ";
            outputP5CB<<pert.src_bytesAlta<<endl;
            outputP6CB<<pert.dst_bytesBaixa<<" ";
            outputP6CB<<pert.dst_bytesMedia<<" ";
            outputP6CB<<pert.dst_bytesAlta<<endl;
            outputP8CB<<pert.wrong_fragmentBaixa<<" ";
            outputP8CB<<pert.wrong_fragmentMedia<<" ";
            outputP8CB<<pert.wrong_fragmentAlta<<endl;
            outputP9CB<<pert.urgenteBaixa<<" ";
            outputP9CB<<pert.urgenteMedia<<" ";
            outputP9CB<<pert.urgenteAlta<<endl;
            outputP10CB<<pert.hotBaixa<<" ";
            outputP10CB<<pert.hotMedia<<" ";
            outputP10CB<<pert.hotAlta<<endl;
            outputP11CB<<pert.num_faleid_loginsBaixa<<" ";
            outputP11CB<<pert.num_faleid_loginsMedia<<" ";
            outputP11CB<<pert.num_faleid_loginsAlta<<endl;
            outputP13CB<<pert.num_compromisedBaixa<<" ";
            outputP13CB<<pert.num_compromisedMedia<<" ";
            outputP13CB<<pert.num_compromisedAlta<<endl;
            outputP16CB<<pert.num_rootBaixa<<" ";
            outputP16CB<<pert.num_rootMedia<<" ";
            outputP16CB<<pert.num_rootAlta<<endl;
            outputP17CB<<pert.num_file_creatinosBaixa<<" ";
            outputP17CB<<pert.num_file_creatinosMedia<<" ";
            outputP17CB<<pert.num_file_creatinosAlta<<endl;
            outputP18CB<<pert.num_shellsBaixa<<" ";
            outputP18CB<<pert.num_shellsMedia<<" ";
            outputP18CB<<pert.num_shellsAlta<<endl;
            outputP19CB<<pert.num_access_filesBaixa<<" ";
            outputP19CB<<pert.num_access_filesMedia<<" ";
            outputP19CB<<pert.num_access_filesAlta<<endl;
            outputP23CB<<pert.countBaixa<<" ";
            outputP23CB<<pert.countMedia<<" ";
            outputP23CB<<pert.countAlta<<endl;
            outputP24CB<<pert.srv_countBaixa<<" ";
            outputP24CB<<pert.srv_countMedia<<" ";
            outputP24CB<<pert.srv_countAlta<<endl;
            outputP25CB<<pert.serror_rateBaixa<<" ";
            outputP25CB<<pert.serror_rateMedia<<" ";
            outputP25CB<<pert.serror_rateAlta<<endl;
            outputP26CB<<pert.srv_serror_rateBaixa<<" ";
            outputP26CB<<pert.srv_serror_rateMedia<<" ";
            outputP26CB<<pert.srv_serror_rateAlta<<endl;
            outputP27CB<<pert.rerror_rateBaixa<<" ";
            outputP27CB<<pert.rerror_rateMedia<<" ";
            outputP27CB<<pert.rerror_rateAlta<<endl;
            outputP28CB<<pert.srv_rerror_rateBaixa<<" ";
            outputP28CB<<pert.srv_rerror_rateMedia<<" ";
            outputP28CB<<pert.srv_rerror_rateAlta<<endl;
            outputP29CB<<pert.same_srv_rateBaixa<<" ";
            outputP29CB<<pert.same_srv_rateMedia<<" ";
            outputP29CB<<pert.same_srv_rateAlta<<endl;
            outputP30CB<<pert.diff_srv_rateBaixa<<" ";
            outputP30CB<<pert.diff_srv_rateMedia<<" ";
            outputP30CB<<pert.diff_srv_rateAlta<<endl;
            outputP31CB<<pert.srv_diff_host_rateBaixa<<" ";
            outputP31CB<<pert.srv_diff_host_rateMedia<<" ";
            outputP31CB<<pert.srv_diff_host_rateAlta<<endl;
            outputP32CB<<pert.dst_host_countBaixa<<" ";
            outputP32CB<<pert.dst_host_countMedia<<" ";
            outputP32CB<<pert.dst_host_countAlta<<endl;
            outputP33CB<<pert.dst_host_srv_countBaixa<<" ";
            outputP33CB<<pert.dst_host_srv_countMedia<<" ";
            outputP33CB<<pert.dst_host_srv_countAlta<<endl;
            outputP34CB<<pert.dst_host_same_srv_rateBaixa<<" ";
            outputP34CB<<pert.dst_host_same_srv_rateMedia<<" ";
            outputP34CB<<pert.dst_host_same_srv_rateAlta<<endl;
            outputP35CB<<pert.dst_host_diff_srv_rateBaixa<<" ";
            outputP35CB<<pert.dst_host_diff_srv_rateMedia<<" ";
            outputP35CB<<pert.dst_host_diff_srv_rateAlta<<endl;
            outputP36CB<<pert.dst_host_same_src_port_rateBaixa<<" ";
            outputP36CB<<pert.dst_host_same_src_port_rateMedia<<" ";
            outputP36CB<<pert.dst_host_same_src_port_rateAlta<<endl;
            outputP37CB<<pert.dst_host_srv_diff_host_rateBaixa<<" ";
            outputP37CB<<pert.dst_host_srv_diff_host_rateMedia<<" ";
            outputP37CB<<pert.dst_host_srv_diff_host_rateAlta<<endl;
            outputP38CB<<pert.dst_host_serror_rateBaixa<<" ";
            outputP38CB<<pert.dst_host_serror_rateMedia<<" ";
            outputP38CB<<pert.dst_host_serror_rateAlta<<endl;
            outputP39CB<<pert.dst_host_srv_serror_rateBaixa<<" ";
            outputP39CB<<pert.dst_host_srv_serror_rateMedia<<" ";
            outputP39CB<<pert.dst_host_srv_serror_rateAlta<<endl;
            outputP40CB<<pert.dst_host_rerror_rateBaixa<<" ";
            outputP40CB<<pert.dst_host_rerror_rateMedia<<" ";
            outputP40CB<<pert.dst_host_rerror_rateAlta<<endl;
            outputP41CB<<pert.dst_host_srv_rerror_rateBaixa<<" ";
            outputP41CB<<pert.dst_host_srv_rerror_rateMedia<<" ";
            outputP41CB<<pert.dst_host_srv_rerror_rateAlta<<endl;
        }
        contaPresente=0; 
    }
    
    //Fechando os arquivos
    nome.clear();
    inputNomeBase.close();
    outputCA.close();
    outputCB.close();
    inputPert1.close();
    inputPert5.close();
    inputPert6.close();
    inputPert8.close();
    inputPert9.close();
    inputPert10.close();
    inputPert11.close();
    inputPert13.close();
    inputPert16.close();
    inputPert17.close();
    inputPert18.close();
    inputPert19.close();
    inputPert23.close();
    inputPert24.close();
    inputPert25.close();
    inputPert26.close();
    inputPert27.close();
    inputPert28.close();
    inputPert29.close();
    inputPert30.close();
    inputPert31.close();
    inputPert32.close();
    inputPert33.close();
    inputPert34.close();
    inputPert35.close();
    inputPert36.close();
    inputPert37.close();
    inputPert38.close();
    inputPert39.close();
    inputPert40.close();
    inputPert41.close();
    outputP1CA.close();
    outputP5CA.close();
    outputP6CA.close();
    outputP8CA.close();
    outputP9CA.close();
    outputP10CA.close();
    outputP11CA.close();
    outputP13CA.close();
    outputP16CA.close();
    outputP17CA.close();
    outputP18CA.close();
    outputP19CA.close();
    outputP23CA.close();
    outputP24CA.close();
    outputP25CA.close();
    outputP26CA.close();
    outputP27CA.close();
    outputP28CA.close();
    outputP29CA.close();
    outputP30CA.close();
    outputP31CA.close();
    outputP32CA.close();
    outputP33CA.close();
    outputP34CA.close();
    outputP35CA.close();
    outputP36CA.close();
    outputP37CA.close();
    outputP38CA.close();
    outputP39CA.close();
    outputP40CA.close();
    outputP41CA.close();
    outputP1CB.close();
    outputP5CB.close();
    outputP6CB.close();
    outputP8CB.close();
    outputP9CB.close();
    outputP10CB.close();
    outputP11CB.close();
    outputP13CB.close();
    outputP16CB.close();
    outputP17CB.close();
    outputP18CB.close();
    outputP19CB.close();
    outputP23CB.close();
    outputP24CB.close();
    outputP25CB.close();
    outputP26CB.close();
    outputP27CB.close();
    outputP28CB.close();
    outputP29CB.close();
    outputP30CB.close();
    outputP31CB.close();
    outputP32CB.close();
    outputP33CB.close();
    outputP34CB.close();
    outputP35CB.close();
    outputP36CB.close();
    outputP37CB.close();
    outputP38CB.close();
    outputP39CB.close();
    outputP40CB.close();
    outputP41CB.close();
    
}
void GeraArquivosClasse::LimpaBase(char nomeBaseASerLimpa[50], char nomeParaBaseLimpa[50]){
    
    utilitarios ut;
    utilitarios::Transacao T;
        
    T= ut.GeraStruturaTransacaoItens(nomeBaseASerLimpa);
    
    cout<<"\nImprimindo o tamanho dos vetores antes da limpeza"<<endl;
    ImprimirParaConferencia(T);
    
    //Limpando os dados da estrutura
    AtualizaEstrutura(T.duracao,T);
    cout<<"\nTerminei duracao"<<endl;
    AtualizaEstrutura(T.src_bytes,T);
    cout<<"\nTerminei src_bytes"<<endl;
    AtualizaEstrutura(T.dst_bytes,T);
    cout<<"\nTerminei dst_bytes"<<endl;
    AtualizaEstrutura(T.wrong_fragment,T);
    cout<<"\nTerminei wrong_fragment"<<endl;
    AtualizaEstrutura(T.urgente,T);
    cout<<"\nTerminei urgente"<<endl;
    AtualizaEstrutura(T.hot,T);
    cout<<"\nTerminei hot"<<endl;
    AtualizaEstrutura(T.num_faleid_logins,T);
    cout<<"\nTerminei num_faleid_logins"<<endl;
    AtualizaEstrutura(T.num_compromised,T);
    cout<<"\nTerminei num_compromised"<<endl;
    AtualizaEstrutura(T.num_root,T);
    cout<<"\nTerminei num_root"<<endl;
    AtualizaEstrutura(T.num_file_creatinos,T);
    cout<<"\nTerminei num_file_creatinos"<<endl;
    AtualizaEstrutura(T.num_shells,T);
    cout<<"\nTerminei num_shells"<<endl;
    AtualizaEstrutura(T.num_access_files,T);
    cout<<"\nTerminei num_access_files"<<endl;
    AtualizaEstrutura(T.serror_rate,T);
    cout<<"\nTerminei serror_rate"<<endl;
    AtualizaEstrutura(T.srv_serror_rate,T);
    cout<<"\nTerminei srv_serror_rate"<<endl;
    AtualizaEstrutura(T.rerror_rate,T);
    cout<<"\nTerminei rerror_rate"<<endl;
    AtualizaEstrutura(T.srv_rerror_rate,T);
    cout<<"\nTerminei srv_rerror_rate"<<endl;
    AtualizaEstrutura(T.diff_srv_rate,T);
    cout<<"\nTerminei diff_srv_rate"<<endl;
    AtualizaEstrutura(T.srv_diff_host_rate,T);
    cout<<"\nTerminei srv_diff_host_rate"<<endl;
    AtualizaEstrutura(T.dst_host_count,T);
    cout<<"\nTerminei dst_host_count"<<endl;
    AtualizaEstrutura(T.dst_host_diff_srv_rate,T);
    cout<<"\nTerminei dst_host_diff_srv_rate"<<endl;
    AtualizaEstrutura(T.dst_host_srv_diff_host_rate,T);
    cout<<"\nTerminei dst_host_srv_diff_host_rate"<<endl;
    AtualizaEstrutura(T.dst_host_serror_rate,T);
    cout<<"\nTerminei dst_host_serror_rate"<<endl;
    AtualizaEstrutura(T.dst_host_srv_serror_rate,T);
    cout<<"\nTerminei dst_host_srv_serror_rate"<<endl;
    AtualizaEstrutura(T.dst_host_rerror_rate,T);
    cout<<"\nTerminei dst_host_rerror_rate"<<endl;
    AtualizaEstrutura(T.dst_host_srv_rerror_rate,T);
    cout<<"\nTerminei dst_host_srv_rerror_rate"<<endl;
    
    //Gerando base limpa
    cout<<"Tamanho da duracao "<<T.dst_host_srv_rerror_rate.size()<<endl;
    GravaRegistroLimpo(T, nomeParaBaseLimpa);
    GravaArquivoParaMatlab(T, "ClasseA_mat");
}
void GeraArquivosClasse::AtualizaEstrutura(vector<string> &vetorAAtualizar, utilitarios::Transacao &t){
    
    int qtdeMinimaNaoPermitida = 10;
    string valorIgual;
    vector<int> posicaoIniValoresIguais, totalIguaisCadaValor;
    vector<string> valorExistenteNoVetor;
    
    /*
     * Limpando dados na coluna 
     * Atribuindo o primeiro valor
     */
    valorIgual = vetorAAtualizar.at(0);
    posicaoIniValoresIguais = BuscaValoresIguais(vetorAAtualizar, valorIgual,totalIguaisCadaValor, valorExistenteNoVetor);
    
    //Excluindo os valores menores que a qtdeMinimaNaoPermitida
   // for(int i= 0;i<valorExistenteNoVetor.size();i++){
    for(int i=totalIguaisCadaValor.size()-1;i>=0;i--){
        if(totalIguaisCadaValor.at(i)<=qtdeMinimaNaoPermitida){
        //if((valorExistenteNoVetor.at(i)=="0")||(valorExistenteNoVetor.at(i)=="0.00")){
            ExcluiDados(t, posicaoIniValoresIguais, i, totalIguaisCadaValor);
        }
    }
    
    cout<<"\nImprimindo o tamanho após exclusao em AtualizaEstrutura"<<endl;
    ImprimirParaConferencia(t);
}
void GeraArquivosClasse::ExcluiDados(utilitarios::Transacao &tt, vector<int> &posicoesParaExclusao, int posicao, vector<int> &totaisDeCadaValor){
    
    tt.duracao.erase(tt.duracao.begin()+posicoesParaExclusao.at(posicao));
    tt.protocolo.erase(tt.protocolo.begin()+posicoesParaExclusao.at(posicao));
    tt.servico.erase(tt.servico.begin()+posicoesParaExclusao.at(posicao));
    tt.flag.erase(tt.flag.begin()+posicoesParaExclusao.at(posicao));
    tt.src_bytes.erase(tt.src_bytes.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_bytes.erase(tt.dst_bytes.begin()+posicoesParaExclusao.at(posicao));
    tt.land.erase(tt.land.begin()+posicoesParaExclusao.at(posicao));
    tt.wrong_fragment.erase(tt.wrong_fragment.begin()+posicoesParaExclusao.at(posicao));
    tt.urgente.erase(tt.urgente.begin()+posicoesParaExclusao.at(posicao));
    tt.hot.erase(tt.hot.begin()+posicoesParaExclusao.at(posicao));
    tt.num_faleid_logins.erase(tt.num_faleid_logins.begin()+posicoesParaExclusao.at(posicao));
    tt.logged_in.erase(tt.logged_in.begin()+posicoesParaExclusao.at(posicao));
    tt.num_compromised.erase(tt.num_compromised.begin()+posicoesParaExclusao.at(posicao));
    tt.root_shell.erase(tt.root_shell.begin()+posicoesParaExclusao.at(posicao));
    tt.su_attempted.erase(tt.su_attempted.begin()+posicoesParaExclusao.at(posicao));
    tt.num_root.erase(tt.num_root.begin()+posicoesParaExclusao.at(posicao));
    tt.num_file_creatinos.erase(tt.num_file_creatinos.begin()+posicoesParaExclusao.at(posicao));
    tt.num_shells.erase(tt.num_shells.begin()+posicoesParaExclusao.at(posicao));
    tt.num_access_files.erase(tt.num_access_files.begin()+posicoesParaExclusao.at(posicao));
    tt.num_outbound_cmds.erase(tt.num_outbound_cmds.begin()+posicoesParaExclusao.at(posicao));
    tt.is_hot_login.erase(tt.is_hot_login.begin()+posicoesParaExclusao.at(posicao));
    tt.is_guest_login.erase(tt.is_guest_login.begin()+posicoesParaExclusao.at(posicao));
    tt.count.erase(tt.count.begin()+posicoesParaExclusao.at(posicao));
    tt.srv_count.erase(tt.srv_count.begin()+posicoesParaExclusao.at(posicao));
    tt.serror_rate.erase(tt.serror_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.srv_serror_rate.erase(tt.srv_serror_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.rerror_rate.erase(tt.rerror_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.srv_rerror_rate.erase(tt.srv_rerror_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.same_srv_rate.erase(tt.same_srv_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.diff_srv_rate.erase(tt.diff_srv_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.srv_diff_host_rate.erase(tt.srv_diff_host_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_host_count.erase(tt.dst_host_count.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_host_srv_count.erase(tt.dst_host_srv_count.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_host_same_srv_rate.erase(tt.dst_host_same_srv_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_host_diff_srv_rate.erase(tt.dst_host_diff_srv_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_host_same_src_port_rate.erase(tt.dst_host_same_src_port_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_host_srv_diff_host_rate.erase(tt.dst_host_srv_diff_host_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_host_serror_rate.erase(tt.dst_host_serror_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_host_srv_serror_rate.erase(tt.dst_host_srv_serror_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_host_rerror_rate.erase(tt.dst_host_rerror_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.dst_host_srv_rerror_rate.erase(tt.dst_host_srv_rerror_rate.begin()+posicoesParaExclusao.at(posicao));
    tt.etiqueta.erase(tt.etiqueta.begin()+posicoesParaExclusao.at(posicao));
    
    totaisDeCadaValor.erase(totaisDeCadaValor.begin()+posicao);
    posicoesParaExclusao.erase(posicoesParaExclusao.begin()+posicao);
    /*
    //Para conferencia, imprime vetor posicao e qtde
    cout<<"\nposicaoIniValIguais\n";
    for(int i=0;i<posicoesParaExclusao.size();i++){
        cout<<posicoesParaExclusao.at(i)<<" ";
    }cout<<endl;
    
    cout<<"\nqtdeCadaValor\n";
    for(int i=0;i<totaisDeCadaValor.size();i++){
        cout<<totaisDeCadaValor.at(i)<<" ";
    }cout<<endl;
    */
}
vector<int> GeraArquivosClasse::BuscaValoresIguais(vector<string> &vetorAVerificar, string valor, vector<int> &qtdeCadaValor, vector<string> &valoresNoVetor){
    
    string valorComum = valor;
    int contaIguais=1, cont=0;
    vector<string> valoresDiferentes;//vetor para guardar os valores existentes no vetor de busca
    vector<string> valorAnterior;//Os valores já pesquisados
    vector<int> posicaoIniValDiferentes;//vetor para guardar o índice inicial dos valores existentes no vetor de busca
    
    //Iniciando vetores
    valoresDiferentes.push_back(valorComum);
    posicaoIniValDiferentes.push_back(0);
    
    for(int i=1;i<vetorAVerificar.size(); i++){
        if(valorComum == vetorAVerificar.at(i)){
            contaIguais++;
        }
    } 
    qtdeCadaValor.push_back(contaIguais);
    contaIguais=0;
    
    //Verificando quais os valores no campo duração que é único
    for(int i=0;i<vetorAVerificar.size();i++){
        for(int j=0; j<valoresDiferentes.size(); j++){
            if(vetorAVerificar.at(i)!= valoresDiferentes.at(j)){
                cont++;
            }           
        } 
        if(cont == valoresDiferentes.size()){    
            valorComum = vetorAVerificar.at(i);
            valoresDiferentes.push_back(valorComum);
            posicaoIniValDiferentes.push_back(i);
            //Verificando quantas vezes o elemento aparece no vetor
            for(int k=0;k<vetorAVerificar.size();k++){
                if(valorComum == vetorAVerificar.at(k)){
                    contaIguais++;
                }
            }
            qtdeCadaValor.push_back(contaIguais);
            contaIguais=0;
            cont = 0;
        }else{
            cont =0;
        }  
    }            
    
    /*
     * Imprimindo as colunas que são correlacionadas da seguinte forma:
     * valoresIguais - guarda todos os valores presentes na coluna
     * posicaoIniValoresIguais - guarda o índice em que os valores do vetor anterior apareceram pela 1a vez
     * totalIguaisCadaValor - guarda a quantidade de vezes que cada valor aparece 
    */
    /*
    cout<<"\nvaloresDiferentes\n";
    for(int i=0;i<valoresDiferentes.size();i++){
        cout<<valoresDiferentes.at(i)<<" ";
    }cout<<endl;
    
    cout<<"\nposicaoIniValIguais\n";
    for(int i=0;i<posicaoIniValDiferentes.size();i++){
        cout<<posicaoIniValDiferentes.at(i)<<" ";
    }cout<<endl;
    
    cout<<"\nqtdeCadaValor\n";
    for(int i=0;i<qtdeCadaValor.size();i++){
        cout<<qtdeCadaValor.at(i)<<" ";
    }cout<<endl;
    */
    valoresNoVetor = valoresDiferentes;
    
    //Limpando todos os vectors
    valoresDiferentes.clear();
    
    return posicaoIniValDiferentes;
}
void GeraArquivosClasse::GravaRegistroLimpo(utilitarios::Transacao &amostra, char nomeDoArqLimpo[50]){
    
    ofstream output(nomeDoArqLimpo);
    int tamanhoDeT;
    cout<<"\nImprimindo o tamanho dos vetores após a limpeza"<<endl;
    ImprimirParaConferencia(amostra);
    
    //Executa até tamanho de T
    tamanhoDeT = amostra.duracao.size();
    
    //Tratamento de erro para o arquivo de saída
    if(!output.is_open()){
        printf("Erro na abertura dos arquivos!");
        output.clear();
        exit(1);
    }
    
    //Realizando a leitura dos dois arquivos e gravação dos itens
    for(int i=0; i<tamanhoDeT; i++){
        output<<amostra.duracao.at(i)<<" ";
        output<<amostra.protocolo.at(i)<<" ";
        output<<amostra.servico.at(i)<<" ";
        output<<amostra.flag.at(i)<<" ";
        output<<amostra.src_bytes.at(i)<<" ";
        output<<amostra.dst_bytes.at(i)<<" ";
        output<<amostra.land.at(i)<<" ";
        output<<amostra.wrong_fragment.at(i)<<" ";
        output<<amostra.urgente.at(i)<<" ";
        output<<amostra.hot.at(i)<<" ";
        output<<amostra.num_faleid_logins.at(i)<<" ";
        output<<amostra.logged_in.at(i)<<" ";
        output<<amostra.num_compromised.at(i)<<" ";
        output<<amostra.root_shell.at(i)<<" ";
        output<<amostra.su_attempted.at(i)<<" ";
        output<<amostra.num_root.at(i)<<" ";
        output<<amostra.num_file_creatinos.at(i)<<" ";
        output<<amostra.num_shells.at(i)<<" ";
        output<<amostra.num_access_files.at(i)<<" ";
        output<<amostra.num_outbound_cmds.at(i)<<" ";
        output<<amostra.is_hot_login.at(i)<<" ";
        output<<amostra.is_guest_login.at(i)<<" ";
        output<<amostra.count.at(i)<<" ";
        output<<amostra.srv_count.at(i)<<" ";
        output<<amostra.serror_rate.at(i)<<" ";
        output<<amostra.srv_serror_rate.at(i)<<" ";
        output<<amostra.rerror_rate.at(i)<<" ";
        output<<amostra.srv_rerror_rate.at(i)<<" ";
        output<<amostra.same_srv_rate.at(i)<<" ";
        output<<amostra.diff_srv_rate.at(i)<<" ";
        output<<amostra.srv_diff_host_rate.at(i)<<" ";
        output<<amostra.dst_host_count.at(i)<<" ";
        output<<amostra.dst_host_srv_count.at(i)<<" ";
        output<<amostra.dst_host_same_srv_rate.at(i)<<" ";
        output<<amostra.dst_host_diff_srv_rate.at(i)<<" ";
        output<<amostra.dst_host_same_src_port_rate.at(i)<<" ";
        output<<amostra.dst_host_srv_diff_host_rate.at(i)<<" ";
        output<<amostra.dst_host_serror_rate.at(i)<<" ";
        output<<amostra.dst_host_srv_serror_rate.at(i)<<" ";
        output<<amostra.dst_host_rerror_rate.at(i)<<" ";
        output<<amostra.dst_host_srv_rerror_rate.at(i)<<" ";
        output<<amostra.etiqueta.at(i)<<endl;
        
    }
    output.close();          
}
void GeraArquivosClasse::GravaArquivoParaMatlab(utilitarios::Transacao &base, char nomeDoArqMat[50]){
    ofstream output(nomeDoArqMat);
    int tamanhoDeT;
    
    //Tratamento de erro para o arquivo de saída
    if(!output.is_open()){
        printf("Erro na abertura dos arquivos!");
        output.clear();
        exit(1);
    }
    
    tamanhoDeT = base.duracao.size();
    
    //Realizando a leitura dos dois arquivos e gravação dos itens
    for(int i=0; i<tamanhoDeT; i++){
        output<<base.duracao.at(i)<<" ";
        output<<base.src_bytes.at(i)<<" ";
        output<<base.dst_bytes.at(i)<<" ";
        output<<base.wrong_fragment.at(i)<<" ";
        output<<base.urgente.at(i)<<" ";
        output<<base.hot.at(i)<<" ";
        output<<base.num_faleid_logins.at(i)<<" ";
        output<<base.num_compromised.at(i)<<" ";
        output<<base.num_root.at(i)<<" ";
        output<<base.num_file_creatinos.at(i)<<" ";
        output<<base.num_shells.at(i)<<" ";
        output<<base.num_access_files.at(i)<<" ";
        output<<base.count.at(i)<<" ";
        output<<base.srv_count.at(i)<<" ";
        output<<base.serror_rate.at(i)<<" ";
        output<<base.srv_serror_rate.at(i)<<" ";
        output<<base.rerror_rate.at(i)<<" ";
        output<<base.srv_rerror_rate.at(i)<<" ";
        output<<base.same_srv_rate.at(i)<<" ";
        output<<base.diff_srv_rate.at(i)<<" ";
        output<<base.srv_diff_host_rate.at(i)<<" ";
        output<<base.dst_host_count.at(i)<<" ";
        output<<base.dst_host_srv_count.at(i)<<" ";
        output<<base.dst_host_same_srv_rate.at(i)<<" ";
        output<<base.dst_host_diff_srv_rate.at(i)<<" ";
        output<<base.dst_host_same_src_port_rate.at(i)<<" ";
        output<<base.dst_host_srv_diff_host_rate.at(i)<<" ";
        output<<base.dst_host_serror_rate.at(i)<<" ";
        output<<base.dst_host_srv_serror_rate.at(i)<<" ";
        output<<base.dst_host_rerror_rate.at(i)<<" ";
        output<<base.dst_host_srv_rerror_rate.at(i)<<endl;
        //output<<base.etiqueta.at(i)<<endl;
    }
    output.close();         
}
void GeraArquivosClasse::ImprimirParaConferencia(utilitarios::Transacao &a){
    
    cout<<"\nSó para conferencia \n"<<endl;
    cout<<"duracao "<<a.duracao.size()<<endl;
    cout<<"protocolo "<<a.protocolo.size()<<endl;
    cout<<"servico "<<a.servico.size()<<endl;
    cout<<"flag "<<a.flag.size()<<endl;
    cout<<"src_bytes "<<a.src_bytes.size()<<endl;
    cout<<"dst_bytes "<<a.dst_bytes.size()<<endl;
    cout<<"land "<<a.land.size()<<endl;
    cout<<"wrong_fragment "<<a.wrong_fragment.size()<<endl;
    cout<<"urgente "<<a.urgente.size()<<endl;
    cout<<"hot "<<a.hot.size()<<endl;
    cout<<"num_faleid_logins "<<a.num_faleid_logins.size()<<endl;
    cout<<"logged_in "<<a.logged_in.size()<<endl;
    cout<<"num_compromised "<<a.num_compromised.size()<<endl;
    cout<<"root_shell "<<a.root_shell.size()<<endl;
    cout<<"su_attempted "<<a.su_attempted.size()<<endl;
    cout<<"num_root "<<a.num_root.size()<<endl;
    cout<<"num_file_creatinos "<<a.num_file_creatinos.size()<<endl;
    cout<<"num_shells "<<a.num_shells.size()<<endl;
    cout<<"num_access_files "<<a.num_access_files.size()<<endl;
    cout<<"num_outbound_cmds "<<a.num_outbound_cmds.size()<<endl;
    cout<<"is_hot_login "<<a.is_hot_login.size()<<endl;
    cout<<"is_guest_login "<<a.is_guest_login.size()<<endl;
    cout<<"count "<<a.count.size()<<endl;
    cout<<"srv_count "<<a.srv_count.size()<<endl;
    cout<<"serror_rate "<<a.serror_rate.size()<<endl;
    cout<<"srv_serror_rate "<<a.srv_serror_rate.size()<<endl;
    cout<<"rerror_rate "<<a.rerror_rate.size()<<endl;
    cout<<"srv_rerror_rate "<<a.srv_rerror_rate.size()<<endl;
    cout<<"same_srv_rate "<<a.same_srv_rate.size()<<endl;
    cout<<"diff_srv_rate "<<a.diff_srv_rate.size()<<endl;
    cout<<"srv_diff_host_rate "<<a.srv_diff_host_rate.size()<<endl;
    cout<<"dst_host_count "<<a.dst_host_count.size()<<endl;
    cout<<"dst_host_srv_count "<<a.dst_host_srv_count.size()<<endl;
    cout<<"dst_host_same_srv_rate "<<a.dst_host_same_srv_rate.size()<<endl;
    cout<<"dst_host_diff_srv_rate "<<a.dst_host_diff_srv_rate.size()<<endl;
    cout<<"dst_host_same_src_port_rate "<<a.dst_host_same_src_port_rate.size()<<endl;
    cout<<"dst_host_srv_diff_host_rate "<<a.dst_host_srv_diff_host_rate.size()<<endl;
    cout<<"dst_host_serror_rate "<<a.dst_host_serror_rate.size()<<endl;
    cout<<"dst_host_srv_serror_rate "<<a.dst_host_srv_serror_rate.size()<<endl;
    cout<<"dst_host_rerror_rate "<<a.dst_host_rerror_rate.size()<<endl;
    cout<<"dst_host_srv_rerror_rate "<<a.dst_host_srv_rerror_rate.size()<<endl;
    cout<<"etiqueta "<<a.etiqueta.size()<<endl;
}
void GeraArquivosClasse::GeraClassesOriginaisParaMatlab(char nomeDaBase[50], char nomeClasseOriginal[50]){
    
    Tab tab;
    ifstream inputNomeBase;
    ofstream output(nomeClasseOriginal);
        
    inputNomeBase.open(nomeDaBase, ifstream::in);
    
    //Tratamento de erro caso os arquivos não existam
    if(!inputNomeBase.is_open()){
        printf("Erro na abertura dos arquivos!");
        inputNomeBase.clear();
        exit(1);
    }
    
    //Tratamento de erro para o arquivo de saída
    if(!output.is_open()){
        printf("Erro na abertura dos arquivos!");
        output.clear();
        exit(1);
    }
    
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(true){
        inputNomeBase>>tab.duracao;
        inputNomeBase>>tab.tipo_protocolo;
        inputNomeBase>>tab.servico;
        inputNomeBase>>tab.flag;
        inputNomeBase>>tab.src_bytes;
        inputNomeBase>>tab.dst_bytes;
        inputNomeBase>>tab.land;
        inputNomeBase>>tab.wrong_fragment;
        inputNomeBase>>tab.urgente;
        inputNomeBase>>tab.hot;
        inputNomeBase>>tab.num_faleid_logins;
        inputNomeBase>>tab.logged_in;
        inputNomeBase>>tab.num_compromised;
        inputNomeBase>>tab.root_shell;
        inputNomeBase>>tab.su_attempted;
        inputNomeBase>>tab.num_root;
        inputNomeBase>>tab.num_file_creatinos;
        inputNomeBase>>tab.num_shells;
        inputNomeBase>>tab.num_access_files;
        inputNomeBase>>tab.num_outbound_cmds;
        inputNomeBase>>tab.is_hot_login;
        inputNomeBase>>tab.is_guest_login;
        inputNomeBase>>tab.count;
        inputNomeBase>>tab.srv_count;
        inputNomeBase>>tab.serror_rate;
        inputNomeBase>>tab.srv_serror_rate;
        inputNomeBase>>tab.rerror_rate;
        inputNomeBase>>tab.srv_rerror_rate;
        inputNomeBase>>tab.same_srv_rate;
        inputNomeBase>>tab.diff_srv_rate;
        inputNomeBase>>tab.srv_diff_host_rate;
        inputNomeBase>>tab.dst_host_count;
        inputNomeBase>>tab.dst_host_srv_count;
        inputNomeBase>>tab.dst_host_same_srv_rate;
        inputNomeBase>>tab.dst_host_diff_srv_rate;
        inputNomeBase>>tab.dst_host_same_src_port_rate;
        inputNomeBase>>tab.dst_host_srv_diff_host_rate;
        inputNomeBase>>tab.dst_host_serror_rate;
        inputNomeBase>>tab.dst_host_srv_serror_rate;
        inputNomeBase>>tab.dst_host_rerror_rate;
        inputNomeBase>>tab.dst_host_srv_rerror_rate;
        inputNomeBase>>tab.etiqueta;
            
        if(inputNomeBase.eof()) break;
        
        output<<tab.duracao<<" ";
        output<<tab.src_bytes<<" ";
        output<<tab.dst_bytes<<" ";
        output<<tab.wrong_fragment<<" ";
        output<<tab.urgente<<" ";
        output<<tab.hot<<" ";
        output<<tab.num_faleid_logins<<" ";
        output<<tab.num_compromised<<" ";
        output<<tab.num_root<<" ";
        output<<tab.num_file_creatinos<<" ";
        output<<tab.num_shells<<" ";
        output<<tab.num_access_files<<" ";
        output<<tab.count<<" ";
        output<<tab.srv_count<<" ";
        output<<tab.serror_rate<<" ";
        output<<tab.srv_serror_rate<<" ";
        output<<tab.rerror_rate<<" ";
        output<<tab.srv_rerror_rate<<" ";
        output<<tab.same_srv_rate<<" ";
        output<<tab.diff_srv_rate<<" ";
        output<<tab.srv_diff_host_rate<<" ";
        output<<tab.dst_host_count<<" ";
        output<<tab.dst_host_srv_count<<" ";
        output<<tab.dst_host_same_srv_rate<<" ";
        output<<tab.dst_host_diff_srv_rate<<" ";
        output<<tab.dst_host_same_src_port_rate<<" ";
        output<<tab.dst_host_srv_diff_host_rate<<" ";
        output<<tab.dst_host_serror_rate<<" ";
        output<<tab.dst_host_srv_serror_rate<<" ";
        output<<tab.dst_host_rerror_rate<<" ";
        output<<tab.dst_host_srv_rerror_rate<<endl;
    }
    //Fechando os arquivos
    inputNomeBase.close();
    output.close();
}
void GeraArquivosClasse::GeraClassesOriginaisSemEtiquetas(char nomeClasseOriginal[50], char nomeArquivoSemEtiqueta[50]){
    
    Tab tab;
    ifstream input;
    ofstream output(nomeArquivoSemEtiqueta);
        
    input.open(nomeClasseOriginal, ifstream::in);
    
    //Tratamento de erro caso os arquivos não existam
    if(!input.is_open()){
        printf("Erro na abertura dos arquivos!");
        input.clear();
        exit(1);
    }
    
    //Tratamento de erro para o arquivo de saída
    if(!output.is_open()){
        printf("Erro na abertura dos arquivos!");
        output.clear();
        exit(1);
    }
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(true){
    
        input>>tab.duracao;
        input>>tab.tipo_protocolo;
        input>>tab.servico;
        input>>tab.flag;
        input>>tab.src_bytes;
        input>>tab.dst_bytes;
        input>>tab.land;
        input>>tab.wrong_fragment;
        input>>tab.urgente;
        input>>tab.hot;
        input>>tab.num_faleid_logins;
        input>>tab.logged_in;
        input>>tab.num_compromised;
        input>>tab.root_shell;
        input>>tab.su_attempted;
        input>>tab.num_root;
        input>>tab.num_file_creatinos;
        input>>tab.num_shells;
        input>>tab.num_access_files;
        input>>tab.num_outbound_cmds;
        input>>tab.is_hot_login;
        input>>tab.is_guest_login;
        input>>tab.count;
        input>>tab.srv_count;
        input>>tab.serror_rate;
        input>>tab.srv_serror_rate;
        input>>tab.rerror_rate;
        input>>tab.srv_rerror_rate;
        input>>tab.same_srv_rate;
        input>>tab.diff_srv_rate;
        input>>tab.srv_diff_host_rate;
        input>>tab.dst_host_count;
        input>>tab.dst_host_srv_count;
        input>>tab.dst_host_same_srv_rate;
        input>>tab.dst_host_diff_srv_rate;
        input>>tab.dst_host_same_src_port_rate;
        input>>tab.dst_host_srv_diff_host_rate;
        input>>tab.dst_host_serror_rate;
        input>>tab.dst_host_srv_serror_rate;
        input>>tab.dst_host_rerror_rate;
        input>>tab.dst_host_srv_rerror_rate;
        input>>tab.etiqueta;
        
        if(input.eof()) break;
        
        output<<tab.duracao<<" ";
        output<<tab.tipo_protocolo<<" ";
        output<<tab.servico<<" ";
        output<<tab.flag<<" ";
        output<<tab.src_bytes<<" ";
        output<<tab.dst_bytes<<" ";
        output<<tab.land<<" ";
        output<<tab.wrong_fragment<<" ";
        output<<tab.urgente<<" ";
        output<<tab.hot<<" ";
        output<<tab.num_faleid_logins<<" ";
        output<<tab.logged_in<<" ";
        output<<tab.num_compromised<<" ";
        output<<tab.root_shell<<" ";
        output<<tab.su_attempted<<" ";
        output<<tab.num_root<<" ";
        output<<tab.num_file_creatinos<<" ";
        output<<tab.num_shells<<" ";
        output<<tab.num_access_files<<" ";
        output<<tab.num_outbound_cmds<<" ";
        output<<tab.is_hot_login<<" ";
        output<<tab.is_guest_login<<" ";
        output<<tab.count<<" ";
        output<<tab.srv_count<<" ";
        output<<tab.serror_rate<<" ";
        output<<tab.srv_serror_rate<<" ";
        output<<tab.rerror_rate<<" ";
        output<<tab.srv_rerror_rate<<" ";
        output<<tab.same_srv_rate<<" ";
        output<<tab.diff_srv_rate<<" ";
        output<<tab.srv_diff_host_rate<<" ";
        output<<tab.dst_host_count<<" ";
        output<<tab.dst_host_srv_count<<" ";
        output<<tab.dst_host_same_srv_rate<<" ";
        output<<tab.dst_host_diff_srv_rate<<" ";
        output<<tab.dst_host_same_src_port_rate<<" ";
        output<<tab.dst_host_srv_diff_host_rate<<" ";
        output<<tab.dst_host_serror_rate<<" ";
        output<<tab.dst_host_srv_serror_rate<<" ";
        output<<tab.dst_host_rerror_rate<<" ";
        output<<tab.dst_host_srv_rerror_rate<<endl;
        
    }
    //Fechando os arquivos
    input.close();
    output.close();
}

void GeraArquivosClasse::RetornaVetorDeEtiquetasGerArqSemEtiqueta(char nomeClasseOriginal[50], char nomeArquivoSemEtiqueta[50]){
    
    Tab tab;
    ifstream input;
    ofstream output(nomeArquivoSemEtiqueta);
    ofstream outputE("Etiquetas");
            
    input.open(nomeClasseOriginal, ifstream::in);
    
    //Tratamento de erro caso os arquivos não existam
    if(!input.is_open()){
        printf("Erro na abertura do arquivo original!");
        input.clear();
        exit(1);
    }
    
    //Tratamento de erro para o arquivo de saída
    if((!output.is_open())||(!outputE.is_open())){
        printf("Erro na abertura do arquivo sem etiqueta e arquivo de etiquetas!");
        output.clear();
        exit(1);
    }
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(true){
    
        input>>tab.duracao;
        input>>tab.tipo_protocolo;
        input>>tab.servico;
        input>>tab.flag;
        input>>tab.src_bytes;
        input>>tab.dst_bytes;
        input>>tab.land;
        input>>tab.wrong_fragment;
        input>>tab.urgente;
        input>>tab.hot;
        input>>tab.num_faleid_logins;
        input>>tab.logged_in;
        input>>tab.num_compromised;
        input>>tab.root_shell;
        input>>tab.su_attempted;
        input>>tab.num_root;
        input>>tab.num_file_creatinos;
        input>>tab.num_shells;
        input>>tab.num_access_files;
        input>>tab.num_outbound_cmds;
        input>>tab.is_hot_login;
        input>>tab.is_guest_login;
        input>>tab.count;
        input>>tab.srv_count;
        input>>tab.serror_rate;
        input>>tab.srv_serror_rate;
        input>>tab.rerror_rate;
        input>>tab.srv_rerror_rate;
        input>>tab.same_srv_rate;
        input>>tab.diff_srv_rate;
        input>>tab.srv_diff_host_rate;
        input>>tab.dst_host_count;
        input>>tab.dst_host_srv_count;
        input>>tab.dst_host_same_srv_rate;
        input>>tab.dst_host_diff_srv_rate;
        input>>tab.dst_host_same_src_port_rate;
        input>>tab.dst_host_srv_diff_host_rate;
        input>>tab.dst_host_serror_rate;
        input>>tab.dst_host_srv_serror_rate;
        input>>tab.dst_host_rerror_rate;
        input>>tab.dst_host_srv_rerror_rate;
        input>>tab.etiqueta;
        
        if(input.eof()) break;
        
        output<<tab.duracao<<" ";
        output<<tab.tipo_protocolo<<" ";
        output<<tab.servico<<" ";
        output<<tab.flag<<" ";
        output<<tab.src_bytes<<" ";
        output<<tab.dst_bytes<<" ";
        output<<tab.land<<" ";
        output<<tab.wrong_fragment<<" ";
        output<<tab.urgente<<" ";
        output<<tab.hot<<" ";
        output<<tab.num_faleid_logins<<" ";
        output<<tab.logged_in<<" ";
        output<<tab.num_compromised<<" ";
        output<<tab.root_shell<<" ";
        output<<tab.su_attempted<<" ";
        output<<tab.num_root<<" ";
        output<<tab.num_file_creatinos<<" ";
        output<<tab.num_shells<<" ";
        output<<tab.num_access_files<<" ";
        output<<tab.num_outbound_cmds<<" ";
        output<<tab.is_hot_login<<" ";
        output<<tab.is_guest_login<<" ";
        output<<tab.count<<" ";
        output<<tab.srv_count<<" ";
        output<<tab.serror_rate<<" ";
        output<<tab.srv_serror_rate<<" ";
        output<<tab.rerror_rate<<" ";
        output<<tab.srv_rerror_rate<<" ";
        output<<tab.same_srv_rate<<" ";
        output<<tab.diff_srv_rate<<" ";
        output<<tab.srv_diff_host_rate<<" ";
        output<<tab.dst_host_count<<" ";
        output<<tab.dst_host_srv_count<<" ";
        output<<tab.dst_host_same_srv_rate<<" ";
        output<<tab.dst_host_diff_srv_rate<<" ";
        output<<tab.dst_host_same_src_port_rate<<" ";
        output<<tab.dst_host_srv_diff_host_rate<<" ";
        output<<tab.dst_host_serror_rate<<" ";
        output<<tab.dst_host_srv_serror_rate<<" ";
        output<<tab.dst_host_rerror_rate<<" ";
        output<<tab.dst_host_srv_rerror_rate<<endl;
        outputE<<tab.etiqueta<<endl;
        
    }
    //Fechando os arquivos
    input.close();
    output.close();
    outputE.close();
}

vector<string> GeraArquivosClasse::RetornaVetorDeEtiquetas(char nomeClasseOriginal[50]){
    
    Tab tab;
    ifstream input;
    vector<string> etiquetas;
            
    input.open(nomeClasseOriginal, ifstream::in);
    
    //Tratamento de erro caso os arquivos não existam
    if(!input.is_open()){
        printf("Erro na abertura do arquivo original!");
        input.clear();
        exit(1);
    }
    
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(true){
    
        input>>tab.duracao;
        input>>tab.tipo_protocolo;
        input>>tab.servico;
        input>>tab.flag;
        input>>tab.src_bytes;
        input>>tab.dst_bytes;
        input>>tab.land;
        input>>tab.wrong_fragment;
        input>>tab.urgente;
        input>>tab.hot;
        input>>tab.num_faleid_logins;
        input>>tab.logged_in;
        input>>tab.num_compromised;
        input>>tab.root_shell;
        input>>tab.su_attempted;
        input>>tab.num_root;
        input>>tab.num_file_creatinos;
        input>>tab.num_shells;
        input>>tab.num_access_files;
        input>>tab.num_outbound_cmds;
        input>>tab.is_hot_login;
        input>>tab.is_guest_login;
        input>>tab.count;
        input>>tab.srv_count;
        input>>tab.serror_rate;
        input>>tab.srv_serror_rate;
        input>>tab.rerror_rate;
        input>>tab.srv_rerror_rate;
        input>>tab.same_srv_rate;
        input>>tab.diff_srv_rate;
        input>>tab.srv_diff_host_rate;
        input>>tab.dst_host_count;
        input>>tab.dst_host_srv_count;
        input>>tab.dst_host_same_srv_rate;
        input>>tab.dst_host_diff_srv_rate;
        input>>tab.dst_host_same_src_port_rate;
        input>>tab.dst_host_srv_diff_host_rate;
        input>>tab.dst_host_serror_rate;
        input>>tab.dst_host_srv_serror_rate;
        input>>tab.dst_host_rerror_rate;
        input>>tab.dst_host_srv_rerror_rate;
        input>>tab.etiqueta;
        
        if(input.eof()) break;
        
        etiquetas.push_back(tab.etiqueta);
        
    }
    //Fechando os arquivos
    input.close();
    
    //Limpando os valores repetidos
    for(int i=0;i<etiquetas.size();i++){
        for(int ii=i+1;ii<etiquetas.size();ii++){
            if(etiquetas.at(i)==etiquetas.at(ii)){
                etiquetas.erase(etiquetas.begin()+ii);
                ii--;
            }
        }
    }
    //Imprimindo para verificação
    for(int i=0;i<etiquetas.size();i++){
        cout<<etiquetas.at(i)<<endl;
    }
    return etiquetas;
}
vector<string> GeraArquivosClasse::SelecionaAtaqueDesconhecido(char nomeArquivoEtiqueta[50], char ArquivoOriginal[50]){
    
    string ataque;
    ifstream ler;
    int contDif=0;
    vector<string> nomesAtaques, ataquesDesconhecidos;
    
    //Vetor de ataques conhecidos
    //nomesAtaques = RetornaVetorDeEtiquetas(ArquivoOriginal);
    nomesAtaques.push_back("back.");
    nomesAtaques.push_back("land.");
    nomesAtaques.push_back("neptune.");
    nomesAtaques.push_back("pod.");
    nomesAtaques.push_back("smurf.");
    nomesAtaques.push_back("teardrop.");
    nomesAtaques.push_back("ipsweep.");
    nomesAtaques.push_back("nmap.");
    nomesAtaques.push_back("portsweep.");
    nomesAtaques.push_back("satan.");
    nomesAtaques.push_back("ftp_write.");
    nomesAtaques.push_back("guess_passwd.");
    nomesAtaques.push_back("phf.");
    nomesAtaques.push_back("spy.");
    nomesAtaques.push_back("warezmaster.");
    nomesAtaques.push_back("imap.");
    nomesAtaques.push_back("multihop.");
    nomesAtaques.push_back("warezclient.");
    nomesAtaques.push_back("perl.");
    nomesAtaques.push_back("rootkit.");
    nomesAtaques.push_back("buffer_overflow.");
    nomesAtaques.push_back("loadmodule.");
    nomesAtaques.push_back("normal.");
    
    ler.open(nomeArquivoEtiqueta, ifstream::in);
    
    //Tratamento de erro caso os arquivos não existam
    if(!ler.is_open()){
        printf("Erro na abertura do arquivo de etiquetas!");
        ler.clear();
        exit(1);
    }
    
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(true){
    
        ler>>ataque;
        
        if(ler.eof()) break;
        
        for(int i=0; i<nomesAtaques.size();i++){
            if(ataque.compare(nomesAtaques[i])==0)
                contDif++;
        }
        if(contDif ==0)
        {
            ataquesDesconhecidos.push_back(ataque);
        }
        contDif=0;
        ataque.clear();
    }
    
    ler.close();
    
    //Limpando os valores repetidos
    for(int i=0;i<ataquesDesconhecidos.size();i++){
        for(int ii=i+1;ii<ataquesDesconhecidos.size();ii++){
            if(ataquesDesconhecidos.at(i)==ataquesDesconhecidos.at(ii)){
                ataquesDesconhecidos.erase(ataquesDesconhecidos.begin()+ii);
                ii--;
            }
        }
    }
    
    return ataquesDesconhecidos;
    
}

void GeraArquivosClasse::GeraArquivoAtaquesConhecidos(char nomeArquivoMatriz[50], char nomeArqEtiqueta[50], char nomeArquiTreine[50]){
    
    Tab tab;
    ifstream input;
    ofstream output("AtaquesConhecidos");
    int contaPresente=0;
    
    vector<string> ataquesDesc;
    
    //Recebendo o vetor de ataques desconhecidos
    ataquesDesc = SelecionaAtaqueDesconhecido(nomeArqEtiqueta, nomeArquiTreine);
   // ataquesDesc.push_back("normal.");
    input.open(nomeArquivoMatriz, ifstream::in);
    
    //Tratamento de erro caso os arquivos não existam
    if(!input.is_open()){
        printf("Erro na abertura do arquivo original!");
        input.clear();
        exit(1);
    }
    
    //Tratamento de erro para o arquivo de saída
    if(!output.is_open()){
        printf("Erro na abertura do arquivo Ataques Conhecidos!");
        output.clear();
        exit(1);
    }
    
    for(int i=0; i<ataquesDesc.size();i++){
        cout<< ataquesDesc[i]<<endl;
        }
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(true){
    
        input>>tab.duracao;
        input>>tab.tipo_protocolo;
        input>>tab.servico;
        input>>tab.flag;
        input>>tab.src_bytes;
        input>>tab.dst_bytes;
        input>>tab.land;
        input>>tab.wrong_fragment;
        input>>tab.urgente;
        input>>tab.hot;
        input>>tab.num_faleid_logins;
        input>>tab.logged_in;
        input>>tab.num_compromised;
        input>>tab.root_shell;
        input>>tab.su_attempted;
        input>>tab.num_root;
        input>>tab.num_file_creatinos;
        input>>tab.num_shells;
        input>>tab.num_access_files;
        input>>tab.num_outbound_cmds;
        input>>tab.is_hot_login;
        input>>tab.is_guest_login;
        input>>tab.count;
        input>>tab.srv_count;
        input>>tab.serror_rate;
        input>>tab.srv_serror_rate;
        input>>tab.rerror_rate;
        input>>tab.srv_rerror_rate;
        input>>tab.same_srv_rate;
        input>>tab.diff_srv_rate;
        input>>tab.srv_diff_host_rate;
        input>>tab.dst_host_count;
        input>>tab.dst_host_srv_count;
        input>>tab.dst_host_same_srv_rate;
        input>>tab.dst_host_diff_srv_rate;
        input>>tab.dst_host_same_src_port_rate;
        input>>tab.dst_host_srv_diff_host_rate;
        input>>tab.dst_host_serror_rate;
        input>>tab.dst_host_srv_serror_rate;
        input>>tab.dst_host_rerror_rate;
        input>>tab.dst_host_srv_rerror_rate;
        input>>tab.etiqueta;
        
        if(input.eof()) break;
        
        //Grava registro
        for(int i=0; i<ataquesDesc.size();i++){
            if(tab.etiqueta == ataquesDesc[i]){
                contaPresente++;
            }
        }
        //Se contaPresente for igual a zero, significa que a conexão não faz parte do ataque desconhecidos
        if(contaPresente==0){
            output<<tab.duracao<<" ";
            output<<tab.tipo_protocolo<<" ";
            output<<tab.servico<<" ";
            output<<tab.flag<<" ";
            output<<tab.src_bytes<<" ";
            output<<tab.dst_bytes<<" ";
            output<<tab.land<<" ";
            output<<tab.wrong_fragment<<" ";
            output<<tab.urgente<<" ";
            output<<tab.hot<<" ";
            output<<tab.num_faleid_logins<<" ";
            output<<tab.logged_in<<" ";
            output<<tab.num_compromised<<" ";
            output<<tab.root_shell<<" ";
            output<<tab.su_attempted<<" ";
            output<<tab.num_root<<" ";
            output<<tab.num_file_creatinos<<" ";
            output<<tab.num_shells<<" ";
            output<<tab.num_access_files<<" ";
            output<<tab.num_outbound_cmds<<" ";
            output<<tab.is_hot_login<<" ";
            output<<tab.is_guest_login<<" ";
            output<<tab.count<<" ";
            output<<tab.srv_count<<" ";
            output<<tab.serror_rate<<" ";
            output<<tab.srv_serror_rate<<" ";
            output<<tab.rerror_rate<<" ";
            output<<tab.srv_rerror_rate<<" ";
            output<<tab.same_srv_rate<<" ";
            output<<tab.diff_srv_rate<<" ";
            output<<tab.srv_diff_host_rate<<" ";
            output<<tab.dst_host_count<<" ";
            output<<tab.dst_host_srv_count<<" ";
            output<<tab.dst_host_same_srv_rate<<" ";
            output<<tab.dst_host_diff_srv_rate<<" ";
            output<<tab.dst_host_same_src_port_rate<<" ";
            output<<tab.dst_host_srv_diff_host_rate<<" ";
            output<<tab.dst_host_serror_rate<<" ";
            output<<tab.dst_host_srv_serror_rate<<" ";
            output<<tab.dst_host_rerror_rate<<" ";
            output<<tab.dst_host_srv_rerror_rate<<" ";
            output<<tab.etiqueta<<endl;
        }
        contaPresente=0;
    }
    //Fechando os arquivos
    input.close();
    output.close();
    
}

void GeraArquivosClasse::GeraArquivoAtaquesDesconhecidos(char nomeArquivoMatriz[50], char nomeArqEtiqueta[50], char nomeArquiTreine[50]){
    
    Tab tab;
    ifstream input;
    ofstream output("AtaquesDesconhecidos");
    int contaPresente=0;
    
    vector<string> ataquesDesc;
    
    //Recebendo o vetor de ataques desconhecidos
    ataquesDesc = SelecionaAtaqueDesconhecido(nomeArqEtiqueta, nomeArquiTreine);
    ataquesDesc.push_back("normal.");
    for(int i=0; i< ataquesDesc.size(); i++){
        cout<<ataquesDesc.at(i)<<endl;
    }
    
    input.open(nomeArquivoMatriz, ifstream::in);
    
    //Tratamento de erro caso os arquivos não existam
    if(!input.is_open()){
        printf("Erro na abertura do arquivo original!");
        input.clear();
        exit(1);
    }
    
    //Tratamento de erro para o arquivo de saída
    if(!output.is_open()){
        printf("Erro na abertura do arquivo Ataques Conhecidos!");
        output.clear();
        exit(1);
    }
    //Realizando a leitura dos dois arquivos e gravação dos itens
    while(true){
    
        input>>tab.duracao;
        input>>tab.tipo_protocolo;
        input>>tab.servico;
        input>>tab.flag;
        input>>tab.src_bytes;
        input>>tab.dst_bytes;
        input>>tab.land;
        input>>tab.wrong_fragment;
        input>>tab.urgente;
        input>>tab.hot;
        input>>tab.num_faleid_logins;
        input>>tab.logged_in;
        input>>tab.num_compromised;
        input>>tab.root_shell;
        input>>tab.su_attempted;
        input>>tab.num_root;
        input>>tab.num_file_creatinos;
        input>>tab.num_shells;
        input>>tab.num_access_files;
        input>>tab.num_outbound_cmds;
        input>>tab.is_hot_login;
        input>>tab.is_guest_login;
        input>>tab.count;
        input>>tab.srv_count;
        input>>tab.serror_rate;
        input>>tab.srv_serror_rate;
        input>>tab.rerror_rate;
        input>>tab.srv_rerror_rate;
        input>>tab.same_srv_rate;
        input>>tab.diff_srv_rate;
        input>>tab.srv_diff_host_rate;
        input>>tab.dst_host_count;
        input>>tab.dst_host_srv_count;
        input>>tab.dst_host_same_srv_rate;
        input>>tab.dst_host_diff_srv_rate;
        input>>tab.dst_host_same_src_port_rate;
        input>>tab.dst_host_srv_diff_host_rate;
        input>>tab.dst_host_serror_rate;
        input>>tab.dst_host_srv_serror_rate;
        input>>tab.dst_host_rerror_rate;
        input>>tab.dst_host_srv_rerror_rate;
        input>>tab.etiqueta;
        
        if(input.eof()) break;
        
        //Grava registro
        for(int i=0; i<ataquesDesc.size();i++){
            if(tab.etiqueta == ataquesDesc[i]){
                contaPresente++;
            }
        }
        //Se contaPresente for diferente de zero, significa que a conexão faz parte do ataque desconhecidos
        if(contaPresente!=0){
            output<<tab.duracao<<" ";
            output<<tab.tipo_protocolo<<" ";
            output<<tab.servico<<" ";
            output<<tab.flag<<" ";
            output<<tab.src_bytes<<" ";
            output<<tab.dst_bytes<<" ";
            output<<tab.land<<" ";
            output<<tab.wrong_fragment<<" ";
            output<<tab.urgente<<" ";
            output<<tab.hot<<" ";
            output<<tab.num_faleid_logins<<" ";
            output<<tab.logged_in<<" ";
            output<<tab.num_compromised<<" ";
            output<<tab.root_shell<<" ";
            output<<tab.su_attempted<<" ";
            output<<tab.num_root<<" ";
            output<<tab.num_file_creatinos<<" ";
            output<<tab.num_shells<<" ";
            output<<tab.num_access_files<<" ";
            output<<tab.num_outbound_cmds<<" ";
            output<<tab.is_hot_login<<" ";
            output<<tab.is_guest_login<<" ";
            output<<tab.count<<" ";
            output<<tab.srv_count<<" ";
            output<<tab.serror_rate<<" ";
            output<<tab.srv_serror_rate<<" ";
            output<<tab.rerror_rate<<" ";
            output<<tab.srv_rerror_rate<<" ";
            output<<tab.same_srv_rate<<" ";
            output<<tab.diff_srv_rate<<" ";
            output<<tab.srv_diff_host_rate<<" ";
            output<<tab.dst_host_count<<" ";
            output<<tab.dst_host_srv_count<<" ";
            output<<tab.dst_host_same_srv_rate<<" ";
            output<<tab.dst_host_diff_srv_rate<<" ";
            output<<tab.dst_host_same_src_port_rate<<" ";
            output<<tab.dst_host_srv_diff_host_rate<<" ";
            output<<tab.dst_host_serror_rate<<" ";
            output<<tab.dst_host_srv_serror_rate<<" ";
            output<<tab.dst_host_rerror_rate<<" ";
            output<<tab.dst_host_srv_rerror_rate<<" ";
            output<<tab.etiqueta<<endl;
        }
        contaPresente=0;
    }
    //Fechando os arquivos
    input.close();
    output.close();
    
}