/* 
 * File:   PreparacaoDaBase.cpp
 * Author: allinesf
 * 
 * Created on 7 de Junho de 2015, 16:13
 */

#include "PreparacaoDaBase.h"
#include "PreparaBase.h"
#include "utilitarios.h"
#include "GeraArquivosClasse.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

PreparacaoDaBase::PreparacaoDaBase() {}

PreparacaoDaBase::PreparacaoDaBase(const PreparacaoDaBase& orig) {}

PreparacaoDaBase::~PreparacaoDaBase() {}

void PreparacaoDaBase::PreProcessamento(){
    
    int resposta;
    
    GeraArquivosClasse gac;
    PreparaBase pb;
    utilitarios ut;
    
    /*
     * PREPARAÇÃO DA BASE PARA OS TESTES
     * Fase1: Substituir a vírgula pelo espaço
     */
    
    cout<<"Gostaria de executar o bloco de comandos para preparar a base para testes?\n";
    cin>>resposta;
    if (resposta==1){
        pb.PreparaBaseParaTeste("corrected");
    }
    
    /*
     * Fase 2: 
     * É executado o algoritmo fuzzy c-means para gerar os valores de referência relativos
     * as regras linguísticas: baixo, médio, alto, para cada um das colunas numéricas
     */
    cout<<"\nGera arquivo para execução do fuzzy c-means? Digite 1 para sim."<<endl;
    cin>>resposta;
    if(resposta ==1){
        gac.GeraClassesOriginaisParaMatlab("kddcup.data_10_percent", "kddcup.data_10_percent_mt");
        cout<<"\nExecute o fuzzy c-means no programa Matlab, logo depois digite Enter para continuar\n";
        cin.get();cin.get();
    }    
    
    /*
     * Fase 3: Dividir ou subdividir o arquivo
     * O arquivo original será dividido em duas classes, devido ao fato de 
     * Associação Baseado em Classificação resvolver problema de duas classes.
     * Devido a isso, podemos dividir e subdividir o arquivo original em 2 arquivos,
     * de acordo com as classes que descrevem os tipos de conexões, que são:
     * 1 - Classe Normal: normal
     * 2 - Classe U2R: sqlattack, perl, xterm, rootkit, httptunnel, ps, 
     * buffer_overflow, loadmodule;
     * 3 - Classe R2L: ftp_write, guess_passwd, impa, phf, xsnoop, multihop, 
     * xlock, named, worm, warezmaster, snmpguess, imap;
     * 4 - Classe Probe: ipsweep, nmap, portsweep, satan, saint, mscan;
     * 5 - Classe DoS: back, land, neptune, pod, smurf, teardrop, back, apache2, 
     * land, mailbomb, processtable, udpstorm;
     * A base original será dividida e subdividida na fase de treinamento para, gerar os conjuntos de regras
     * e logo após, o arquivo para teste será dividido e subdividido para a classificação.
     */
    cout<<"\nGostaria de dividir o arquivo original para teste?\n";
    cin>>resposta;
    vector<string> nomeDaPrimeiraClasse;
    
    if(resposta ==1){
        cout<<"Escolha a classe que deseja para o primeiro arquivo:\n";
        cout<<"1 - Normal\n";
        cout<<"2 - U2R\n";
        cout<<"3 - R2L\n";
        cout<<"4 - Probe\n";
        cout<<"5 - DoS\n";
        cin>>resposta;
        
        switch (resposta){
            case 1:
                nomeDaPrimeiraClasse.push_back("normal.");
                gac.Cria2ClassesArquivos("kddcup.data_10_percent", nomeDaPrimeiraClasse);
                break;
            case 2:
                nomeDaPrimeiraClasse.push_back("sqlattack.");
                nomeDaPrimeiraClasse.push_back("perl.");
                nomeDaPrimeiraClasse.push_back("xterm.");
                nomeDaPrimeiraClasse.push_back("rootkit.");
                nomeDaPrimeiraClasse.push_back("httptunnel.");
                nomeDaPrimeiraClasse.push_back("ps.");
                nomeDaPrimeiraClasse.push_back("buffer_overflow.");
                nomeDaPrimeiraClasse.push_back("loadmodule.");
                gac.Cria2ClassesArquivos("kddcup.data_10_percent", nomeDaPrimeiraClasse);
                break;
            case 3:
                nomeDaPrimeiraClasse.push_back("ftp_write.");
                nomeDaPrimeiraClasse.push_back("guess_passwd.");
                nomeDaPrimeiraClasse.push_back("impa.");
                nomeDaPrimeiraClasse.push_back("phf.");
                nomeDaPrimeiraClasse.push_back("spy.");
                nomeDaPrimeiraClasse.push_back("xsnoop.");
                nomeDaPrimeiraClasse.push_back("multihop.");
                nomeDaPrimeiraClasse.push_back("xlock.");
                nomeDaPrimeiraClasse.push_back("named.");
                nomeDaPrimeiraClasse.push_back("worm.");
                nomeDaPrimeiraClasse.push_back("warezmaster.");
                nomeDaPrimeiraClasse.push_back("warezclient.");
                nomeDaPrimeiraClasse.push_back("snmpguess.");
                nomeDaPrimeiraClasse.push_back("imap.");
                gac.Cria2ClassesArquivos("kddcup.data_10_percent", nomeDaPrimeiraClasse);
                break;
            case 4:
                nomeDaPrimeiraClasse.push_back("ipsweep.");
                nomeDaPrimeiraClasse.push_back("nmap.");
                nomeDaPrimeiraClasse.push_back("portsweep.");
                nomeDaPrimeiraClasse.push_back("satan.");
                nomeDaPrimeiraClasse.push_back("saint.");
                nomeDaPrimeiraClasse.push_back("mscan.");
                gac.Cria2ClassesArquivos("kddcup.data_10_percent", nomeDaPrimeiraClasse);
                break;
            case 5:
                nomeDaPrimeiraClasse.push_back("back.");
                nomeDaPrimeiraClasse.push_back("land.");
                nomeDaPrimeiraClasse.push_back("neptune.");
                nomeDaPrimeiraClasse.push_back("pod.");
                nomeDaPrimeiraClasse.push_back("smurf.");
                nomeDaPrimeiraClasse.push_back("teardrop.");
                nomeDaPrimeiraClasse.push_back("apache2.");
                nomeDaPrimeiraClasse.push_back("mailbomb.");
                nomeDaPrimeiraClasse.push_back("processtable.");
                nomeDaPrimeiraClasse.push_back("udpstorm.");
                gac.Cria2ClassesArquivos("kddcup.data_10_percent", nomeDaPrimeiraClasse);
                break;
        }
        cout<<"Gerando os arquivos Originais sem etiqueta"<<endl;
        gac.GeraClassesOriginaisSemEtiquetas("ClasseA","ClasseA_ORG");
        gac.GeraClassesOriginaisSemEtiquetas("ClasseB","ClasseB_ORG");
    }
    
    /*
     * Fase 4: Necessária para todas as bases (tanto de treinamento, quanto a de detecção)
     * Transforma a base de dados em itens para aplicação das técnicas de fuzzy.
     */
    
    vector<string> pertinenciaCA;
    vector<string> pertinenciaCB;
    
    do{
        cout<<"Gostaria de executar o bloco de comandos para transformação da base em itens?\n";
        cin>>resposta;
        if(resposta ==1){
            cout<<"\nPara qual arquivo deseja realizar a transformação de itens?"<<endl;
            cout<<"1) ClasseA"<<endl;
            cout<<"2) ClasseB"<<endl;
            cin>>resposta;
        }
        switch(resposta){
            case 1:
                pertinenciaCA.push_back("UTeste1_CA");pertinenciaCA.push_back("UTeste5_CA");pertinenciaCA.push_back("UTeste6_CA");
                pertinenciaCA.push_back("UTeste8_CA");pertinenciaCA.push_back("UTeste9_CA");pertinenciaCA.push_back("UTeste10_CA");
                pertinenciaCA.push_back("UTeste11_CA");pertinenciaCA.push_back("UTeste13_CA");pertinenciaCA.push_back("UTeste16_CA");
                pertinenciaCA.push_back("UTeste17_CA");pertinenciaCA.push_back("UTeste18_CA");pertinenciaCA.push_back("UTeste19_CA");
                pertinenciaCA.push_back("UTeste23_CA");pertinenciaCA.push_back("UTeste24_CA");pertinenciaCA.push_back("UTeste25_CA");
                pertinenciaCA.push_back("UTeste26_CA");pertinenciaCA.push_back("UTeste27_CA");pertinenciaCA.push_back("UTeste28_CA");
                pertinenciaCA.push_back("UTeste29_CA");pertinenciaCA.push_back("UTeste30_CA");pertinenciaCA.push_back("UTeste31_CA");
                pertinenciaCA.push_back("UTeste32_CA");pertinenciaCA.push_back("UTeste33_CA");pertinenciaCA.push_back("UTeste34_CA");
                pertinenciaCA.push_back("UTeste35_CA");pertinenciaCA.push_back("UTeste36_CA");pertinenciaCA.push_back("UTeste37_CA");
                pertinenciaCA.push_back("UTeste38_CA");pertinenciaCA.push_back("UTeste39_CA");pertinenciaCA.push_back("UTeste40_CA");pertinenciaCA.push_back("UTeste41_CA");
                
                ut.TransformaCaracteristicaEmItem("ClasseA", pertinenciaCA);
                pertinenciaCA.clear();
                break;
            case 2:
                pertinenciaCB.push_back("UTeste1_CB");pertinenciaCB.push_back("UTeste5_CB");pertinenciaCB.push_back("UTeste6_CB");
                pertinenciaCB.push_back("UTeste8_CB");pertinenciaCB.push_back("UTeste9_CB");pertinenciaCB.push_back("UTeste10_CB");
                pertinenciaCB.push_back("UTeste11_CB");pertinenciaCB.push_back("UTeste13_CB");pertinenciaCB.push_back("UTeste16_CB");
                pertinenciaCB.push_back("UTeste17_CB");pertinenciaCB.push_back("UTeste18_CB");pertinenciaCB.push_back("UTeste19_CB");
                pertinenciaCB.push_back("UTeste23_CB");pertinenciaCB.push_back("UTeste24_CB");pertinenciaCB.push_back("UTeste25_CB");
                pertinenciaCB.push_back("UTeste26_CB");pertinenciaCB.push_back("UTeste27_CB");pertinenciaCB.push_back("UTeste28_CB");
                pertinenciaCB.push_back("UTeste29_CB");pertinenciaCB.push_back("UTeste30_CB");pertinenciaCB.push_back("UTeste31_CB");
                pertinenciaCB.push_back("UTeste32_CB");pertinenciaCB.push_back("UTeste33_CB");pertinenciaCB.push_back("UTeste34_CB");
                pertinenciaCB.push_back("UTeste35_CB");pertinenciaCB.push_back("UTeste36_CB");pertinenciaCB.push_back("UTeste37_CB");
                pertinenciaCB.push_back("UTeste38_CB");pertinenciaCB.push_back("UTeste39_CB");pertinenciaCB.push_back("UTeste40_CB");pertinenciaCB.push_back("UTeste41_CB");
                
                ut.TransformaCaracteristicaEmItem("ClasseB",pertinenciaCB);
                pertinenciaCB.clear();
                break;
        }
    }while(resposta!=0);

    /*
     * Fase 5: Execute o apriori
     */
    cout<<"\nExecute o apriori e logo depois digite Enter para continuar"<<endl;
    cin.get(); cin.get();
    
}