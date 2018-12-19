/* 
 * File:   Classificacao.cpp
 * Author: allinesf
 * 
 * Created on 23 de Maio de 2015, 16:17
 */

#include "Classificacao.h"
#include "IndAssReFuzzy.h"
#include "utilitarios.h"
#include <vector>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h> 

using namespace std;

Classificacao::Classificacao() {
}

Classificacao::Classificacao(const Classificacao& orig) {
}

Classificacao::~Classificacao() {
}

vector<vector <int> > Classificacao::LerArquivoIAntecedente(char indiceAntecedentes[50]) {

    ifstream inputIndiceAntece;
    int iAnt;
    vector<int> indiceA;
    vector<vector<int> > mIA;
    int valor;
    char dado;

    inputIndiceAntece.open(indiceAntecedentes, ifstream::in);


    //Tratamento de erro caso os arquivos não existam
    if (!inputIndiceAntece.is_open()) {
        printf("O arquivo de índice dos antecedentes não existe!");
        inputIndiceAntece.clear();
        exit(1);
    }

    while (true) {

        valor = inputIndiceAntece.tellg();
        inputIndiceAntece.get(dado);

        if (inputIndiceAntece.eof()) break;

        if (dado != 10) {
            inputIndiceAntece.seekg(valor);
            inputIndiceAntece>>iAnt;
            indiceA.push_back(iAnt);

        } else {
            mIA.push_back(indiceA);
            indiceA.clear();
        }
    }

    //Fechando os arquivos
    inputIndiceAntece.close();

    return mIA;
}

vector<vector <int> > Classificacao::LerArquivoIPAntecedente(char posicaoPertAntecedentes[50]) {

    ifstream inputIndicePAntece;
    int iPAnt;
    vector<int> indicePA;
    vector<vector<int> > mIPA;
    int valor;
    char dado;

    inputIndicePAntece.open(posicaoPertAntecedentes, ifstream::in);


    //Tratamento de erro caso os arquivos não existam
    if (!inputIndicePAntece.is_open()) {
        printf("O arquivo de índice de pertinencia dos antecedentes não existe!");
        inputIndicePAntece.clear();
        exit(1);
    }

    while (true) {

        valor = inputIndicePAntece.tellg();
        inputIndicePAntece.get(dado);

        if (inputIndicePAntece.eof()) break;

        if (dado != 10) {
            inputIndicePAntece.seekg(valor);
            inputIndicePAntece>>iPAnt;
            indicePA.push_back(iPAnt);

        } else {
            mIPA.push_back(indicePA);
            indicePA.clear();
        }
    }

    //Fechando os arquivos
    inputIndicePAntece.close();

    return mIPA;
}

vector <int> Classificacao::LerArquivoIConsequente(char indiceConsequente[50]) {

    ifstream inputIndiceConseq;
    int iCon;
    vector<int> indiceC;

    inputIndiceConseq.open(indiceConsequente, ifstream::in);


    //Tratamento de erro caso os arquivos não existam
    if (!inputIndiceConseq.is_open()) {
        printf("O arquivo de índice dos consequentes não existe!");
        inputIndiceConseq.clear();
        exit(1);
    }

    while (true) {

        if (inputIndiceConseq.eof()) break;

        inputIndiceConseq>>iCon;
        indiceC.push_back(iCon);
    }

    //Fechando os arquivos
    inputIndiceConseq.close();

    return indiceC;
}

vector <int> Classificacao::LerArquivoIPConsequente(char pertinenciaConseq[50]) {

    ifstream inputIndicePConseq;
    int iPCon;
    vector<int> indicePC;

    inputIndicePConseq.open(pertinenciaConseq, ifstream::in);


    //Tratamento de erro caso os arquivos não existam
    if (!inputIndicePConseq.is_open()) {
        printf("O arquivo de índice de pertinencia dos consequentes não existe!");
        inputIndicePConseq.clear();
        exit(1);
    }

    while (true) {

        if (inputIndicePConseq.eof()) break;

        inputIndicePConseq>>iPCon;
        indicePC.push_back(iPCon);
    }

    //Fechando os arquivos
    inputIndicePConseq.close();

    return indicePC;
}

vector <double> Classificacao::LerArquivoGrauCerteza(char grauCertezaRegra[50]) {

    ifstream inputGrauCR;
    double gC;
    vector<double> grauC;

    inputGrauCR.open(grauCertezaRegra, ifstream::in);


    //Tratamento de erro caso os arquivos não existam
    if (!inputGrauCR.is_open()) {
        printf("O arquivo de grau de certeza da regra não existe!");
        inputGrauCR.clear();
        exit(1);
    }

    while (true) {

        inputGrauCR>>gC;

        if (inputGrauCR.eof()) break;

        grauC.push_back(gC);
    }

    //Fechando os arquivos
    inputGrauCR.close();

    return grauC;
}

vector <vector<string> > Classificacao::LerCabecalhoAntecedente(char cabecalhoAntecendente[50]) {

    ifstream inputCA;
    string cA, letra1, letra2, letra3;
    vector<string> vCA;
    vector<vector<string> > mCA;
    int valor;
    char dado;

    letra1 = "If";
    letra2 = "and";
    inputCA.open(cabecalhoAntecendente, ifstream::in);


    //Tratamento de erro caso os arquivos não existam
    if (!inputCA.is_open()) {
        printf("O arquivo de cabeçalho dos antecedentes não existe!");
        inputCA.clear();
        exit(1);
    }

    while (true) {

        inputCA>>cA;

        if ((cA.compare(letra1) != 0)&&(cA.compare(letra2) != 0)) {
            vCA.push_back(cA);
        }

        valor = inputCA.tellg();
        inputCA.get(dado);

        if (inputCA.eof()) break;

        if (dado == 10) {
            mCA.push_back(vCA);
            vCA.clear();

        } else {
            inputCA.seekg(valor);
        }
    }

    //Fechando os arquivos
    inputCA.close();

    return mCA;
}

vector <string> Classificacao::LerCabecalhoPertinencia(char cabecalhoPertinencia[50]) {

    ifstream inputCP;
    string cP;
    vector<string> vCP;

    inputCP.open(cabecalhoPertinencia, ifstream::in);


    //Tratamento de erro caso os arquivos não existam
    if (!inputCP.is_open()) {
        printf("O arquivo de cabeçalho dos pertinentes não existe!");
        inputCP.clear();
        exit(1);
    }

    while (true) {

        inputCP>>cP;

        if (inputCP.eof()) break;


        vCP.push_back(cP);

    }


    //Fechando os arquivos
    inputCP.close();

    return vCP;
}

vector <string> Classificacao::LerEtiqueta(char rotulos[50]) {

    ifstream inputE;
    string etiqueta;
    vector<string> vEtiquetas;

    inputE.open(rotulos, ifstream::in);


    //Tratamento de erro caso os arquivos não existam
    if (!inputE.is_open()) {
        printf("O arquivo de etiquetas não existe!");
        inputE.clear();
        exit(1);
    }

    while (true) {

        inputE>>etiqueta;

        if (inputE.eof()) break;


        vEtiquetas.push_back(etiqueta);
    }

    //Fechando os arquivos
    inputE.close();

    return vEtiquetas;
}

void Classificacao::LerArquivoDeteccao(char nomeArqDeteccao[100], double limiarVlrBaixos, bool ABCextendida) {

    ifstream inputAD;
    ofstream outMResp, outMRespMamdani;
    string aD;
    vector<vector<string> > cabAN, cabAD, cabAP, cabAR, cabAU;
    vector<string> vAD;
    vector<string> cabCN, cabCD, cabCP, cabCR, cabCU;
    vector<string> cabecalhoCAvaliarN, cabecalhoCAvaliarD, cabecalhoCAvaliarP, cabecalhoCAvaliarR, cabecalhoCAvaliarU;
    vector<double> grauCRN, grauCRD, grauCRP, grauCRR, grauCRU, vresposta_MM, vresposta_MM_Mamdani;
    vector<double> valoresCAvaliarN, valoresCAvaliarD, valoresCAvaliarP, valoresCAvaliarR, valoresCAvaliarU;
    int valor, cont = 1;
    char dado;
    double valor_MM, _MM_Mamdani;

    IndAssReFuzzy iaf;

    inputAD.open(nomeArqDeteccao, ifstream::in);
    outMResp.open("m_resposta_MM");
    outMRespMamdani.open("MM_Mamdani");


    //Tratamento de erro caso os arquivos não existam
    if (!inputAD.is_open()) {
        printf("O arquivo de detecção não existe!");
        inputAD.clear();
        exit(1);
    }

    if (!outMResp.is_open()) {
        printf("O arquivo de resultados da detecção não existe!");
        outMResp.clear();
        exit(1);
    }

    if (!outMRespMamdani.is_open()) {
        printf("O arquivo de resultados do método Mamdani não existe!");
        outMRespMamdani.clear();
        exit(1);
    }

    /*
     * Lendo os arquivos de Treinamento de cada classe
     * e alimentando os vetores e matrizes.
     */
    if (ABCextendida) {
        cabAN = LerCabecalhoAntecedente("ClasseANormal");
        cabCN = LerCabecalhoPertinencia("Cabecalho_ConsequenteNormal");
        grauCRN = LerArquivoGrauCerteza("GrauCNormal");
    } else {


        cabAN = LerCabecalhoAntecedente("ClasseANormal");
        cabCN = LerCabecalhoPertinencia("Cabecalho_ConsequenteNormal");
        grauCRN = LerArquivoGrauCerteza("GrauCNormal");

        cabAD = LerCabecalhoAntecedente("ClasseADoS");
        cabCD = LerCabecalhoPertinencia("Cabecalho_ConsequenteDoS");
        grauCRD = LerArquivoGrauCerteza("GrauCDoS");

        cabAP = LerCabecalhoAntecedente("ClasseAProbe");
        cabCP = LerCabecalhoPertinencia("Cabecalho_ConsequenteProbe");
        grauCRP = LerArquivoGrauCerteza("GrauCProbe");

        cabAR = LerCabecalhoAntecedente("ClasseAR2L");
        cabCR = LerCabecalhoPertinencia("Cabecalho_ConsequenteR2L");
        grauCRR = LerArquivoGrauCerteza("GrauCR2L");

        cabAU = LerCabecalhoAntecedente("ClasseAU2R");
        cabCU = LerCabecalhoPertinencia("Cabecalho_ConsequenteU2R");
        grauCRU = LerArquivoGrauCerteza("GrauCU2R");
    }

    while (true) {

        valor = inputAD.tellg();
        inputAD.get(dado);

        if (inputAD.eof()) break;

        if (dado != 10) {
            inputAD.seekg(valor);
            inputAD>>aD;
            vAD.push_back(aD);

        } else {
            if (ABCextendida) {
                /*
                 * Cada consequencia refere-se a uma linha da matriz antecedente
                 * Deve considerar apenas um item do vetor para uma regra
                 */

                cabecalhoCAvaliarN = SelecionaCamposAValidar(cabCN, vAD);
                valoresCAvaliarN = PertinenciaValores(cabecalhoCAvaliarN);

                //Conexão normal 
                valor_MM = RealizaCalculos(cabAN, vAD, grauCRN, valoresCAvaliarN, limiarVlrBaixos, _MM_Mamdani);
                vresposta_MM.push_back(valor_MM);
                vresposta_MM_Mamdani.push_back(_MM_Mamdani);
                _MM_Mamdani = 0;

                //Alimentando o arquivo de resposta e posição de leitura
                for (int yy = 0; yy < vresposta_MM.size(); yy++) {
                    outMResp << vresposta_MM.at(yy) << endl;
                }

                for (int yy = 0; yy < vresposta_MM_Mamdani.size(); yy++) {
                    outMRespMamdani << vresposta_MM_Mamdani.at(yy) << endl;
                }
                //Gravando o último ponteiro lido do arquivo
                //outPont<<valor<<endl;
                cout << "\nGravou a linha " << cont << endl;
                cont++;

                //Limpando vetores
                vresposta_MM.clear();
                vresposta_MM_Mamdani.clear();
                valoresCAvaliarN.clear();
                //Limpando o vetor para receber novos valores
                vAD.clear();

            } else {

                /*
                 * Cada consequencia refere-se a uma linha da matriz antecedente
                 * Deve considerar apenas um item do vetor para uma regra
                 */

                cabecalhoCAvaliarN = SelecionaCamposAValidar(cabCN, vAD);
                valoresCAvaliarN = PertinenciaValores(cabecalhoCAvaliarN);
                cabecalhoCAvaliarN.clear();

                cabecalhoCAvaliarD = SelecionaCamposAValidar(cabCD, vAD);
                valoresCAvaliarD = PertinenciaValores(cabecalhoCAvaliarD);
                cabecalhoCAvaliarD.clear();

                cabecalhoCAvaliarP = SelecionaCamposAValidar(cabCP, vAD);
                valoresCAvaliarP = PertinenciaValores(cabecalhoCAvaliarP);
                cabecalhoCAvaliarP.clear();

                cabecalhoCAvaliarR = SelecionaCamposAValidar(cabCR, vAD);
                valoresCAvaliarR = PertinenciaValores(cabecalhoCAvaliarR);
                cabecalhoCAvaliarR.clear();

                cabecalhoCAvaliarU = SelecionaCamposAValidar(cabCU, vAD);
                valoresCAvaliarU = PertinenciaValores(cabecalhoCAvaliarU);
                cabecalhoCAvaliarU.clear();


                //Conexão normal
                valor_MM = RealizaCalculos(cabAN, vAD, grauCRN, valoresCAvaliarN, limiarVlrBaixos, _MM_Mamdani);
                vresposta_MM.push_back(valor_MM);
                vresposta_MM_Mamdani.push_back(_MM_Mamdani);
                _MM_Mamdani = 0;
                valor_MM = 0;


                //Conexão DoS
                valor_MM = RealizaCalculos(cabAD, vAD, grauCRD, valoresCAvaliarD, limiarVlrBaixos, _MM_Mamdani);
                vresposta_MM.push_back(valor_MM);
                vresposta_MM_Mamdani.push_back(_MM_Mamdani);
                _MM_Mamdani = 0;
                valor_MM = 0;

                //Conexão Probe
                valor_MM = RealizaCalculos(cabAP, vAD, grauCRP, valoresCAvaliarP, limiarVlrBaixos, _MM_Mamdani);
                vresposta_MM.push_back(valor_MM);
                vresposta_MM_Mamdani.push_back(_MM_Mamdani);
                _MM_Mamdani = 0;
                valor_MM = 0;

                //Conexão R2L
                valor_MM = RealizaCalculos(cabAR, vAD, grauCRR, valoresCAvaliarR, limiarVlrBaixos, _MM_Mamdani);
                vresposta_MM.push_back(valor_MM);
                vresposta_MM_Mamdani.push_back(_MM_Mamdani);
                _MM_Mamdani = 0;
                valor_MM = 0;

                //Conexão U2R
                valor_MM = RealizaCalculos(cabAU, vAD, grauCRU, valoresCAvaliarU, limiarVlrBaixos, _MM_Mamdani);
                vresposta_MM.push_back(valor_MM);
                vresposta_MM_Mamdani.push_back(_MM_Mamdani);
                _MM_Mamdani = 0;
                valor_MM = 0;

                //Alimentando o arquivo de resposta e posição de leitura
                for (int yy = 0; yy < vresposta_MM_Mamdani.size(); yy++) {
                    if (yy < 4) {
                        //  if(yy< 1){
                        outMRespMamdani << vresposta_MM_Mamdani.at(yy) << " ";
                        outMResp << vresposta_MM.at(yy) << " ";
                    } else {
                        outMRespMamdani << vresposta_MM_Mamdani.at(yy) << "\n";
                        outMResp << vresposta_MM.at(yy) << "\n";
                    }
                }

                cout << "\nGravou a linha " << cont << endl;
                cont++;

                //Limpando vetores
                vresposta_MM.clear();
                vresposta_MM_Mamdani.clear();
                valoresCAvaliarN.clear();
                valoresCAvaliarD.clear();
                valoresCAvaliarP.clear();
                valoresCAvaliarR.clear();
                valoresCAvaliarU.clear();
            }

            //Limpando o vetor para receber novos valores
            vAD.clear();
        }
    }

    //Fechando os arquivos e limpando vetores
    inputAD.close();
    outMResp.close();
    outMRespMamdani.close();
    cabAN.clear();
    cabAD.clear();
    cabAP.clear();
    cabAR.clear();
    cabAU.clear();
    grauCRN.clear();
    grauCRD.clear();
    grauCRP.clear();
    grauCRR.clear();
    grauCRU.clear();
    vresposta_MM.clear();
    cabCN.clear();
    cabCD.clear();
    cabCP.clear();
    cabCR.clear();
    cabCU.clear();
    vAD.clear();
}

double Classificacao::RealizaCalculos(vector<vector<string> > cabecalhoAR, vector<string> vetorLido, vector <double> grau, vector<double> valoresConsequente, double limiar, double &resposta_MM_Mamdani) {

    vector<string> cabecalhoAAvaliar;
    vector<double> valoresAAvaliar, vrespostaRI, vresposta_mm, vresposta_mm_Mamdani;
    double respostaRI, respostaFS, resposta_mm, resposta_MM, mm_Mamdani, valor_MM_Mamdani;

    //Inicia o for lendo toda a matriz de cabeçalho de antecedente
    for (int i = 0; i < cabecalhoAR.size(); i++) {

        /* Selecionar os itens que possuem cabeçalhos compatíveis com as regras
         * Retorna o valor considerando a linha da matriz de antecendente de regras
         */
        cabecalhoAAvaliar = SelecionaCamposAValidar(cabecalhoAR[i], vetorLido);

        /* Desmembrar as pertinências desses itens
         * Refere - se a pertinência de apenas um R_i do conjunto de regras
         */
        valoresAAvaliar = PertinenciaValores(cabecalhoAAvaliar);
        /*
        for(int z=0;z<valoresAAvaliar.size();z++){
            cout<<valoresAAvaliar.at(z)<<" ";
        }cout<<endl;
         */
        //Iniciando os cálculos
        respostaFS = firingStrength(valoresAAvaliar, limiar);
        respostaRI = RI(grau[i], respostaFS);
        resposta_mm = mm_trp(valoresConsequente[i], limiar);

        mm_Mamdani = MetodoMamdani(respostaFS, valoresConsequente[i], grau[i], limiar);

        //Alimentando os vetores para o cálculo final
        vrespostaRI.push_back(respostaRI);
        vresposta_mm.push_back(resposta_mm);
        vresposta_mm_Mamdani.push_back(mm_Mamdani);

        //Limpando as variáveis para novos cálculos
        cabecalhoAAvaliar.clear();
        valoresAAvaliar.clear();

        respostaFS = 0;
        respostaRI = 0;
        resposta_mm = 0;
        mm_Mamdani = 0;
    }
    /*
     * Nesse momento é feito o cálculo final e enviado 
     * o vetor de todos os valores de todos os cálculos finais de cada 
     * conjunto de regras, para interpretação da detecção.
     */
    resposta_MM = ABC(vrespostaRI, vresposta_mm);
    valor_MM_Mamdani = ABC_Mamdani(grau, vresposta_mm_Mamdani);
    resposta_MM_Mamdani = valor_MM_Mamdani;


    return resposta_MM;
}

vector<string> Classificacao::SelecionaCamposAValidar(vector<string> cabecalhoDaRegra, vector<string> vetorLido) {

    vector<string> descConsiderar, palavraADesmembrar, palavraDesmembrada;
    string palavra;

    IndAssReFuzzy iarf;

    for (int ii = 0; ii < cabecalhoDaRegra.size(); ii++) {
        if (cabecalhoDaRegra[ii].compare("<duracao,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(0));
        else if (cabecalhoDaRegra[ii].compare("<duracao,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(1));
        else if (cabecalhoDaRegra[ii].compare("<duracao,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(2));
        else if (cabecalhoDaRegra[ii].compare("<src_bytes,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(6));
        else if (cabecalhoDaRegra[ii].compare("<src_bytes,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(7));
        else if (cabecalhoDaRegra[ii].compare("<src_bytes,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(8));
        else if (cabecalhoDaRegra[ii].compare("<dst_bytes,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(9));
        else if (cabecalhoDaRegra[ii].compare("<dst_bytes,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(10));
        else if (cabecalhoDaRegra[ii].compare("<dst_bytes,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(11));
        else if (cabecalhoDaRegra[ii].compare("<wrong_fragment,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(13));
        else if (cabecalhoDaRegra[ii].compare("<wrong_fragment,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(14));
        else if (cabecalhoDaRegra[ii].compare("<wrong_fragment,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(15));
        else if (cabecalhoDaRegra[ii].compare("<urgente,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(16));
        else if (cabecalhoDaRegra[ii].compare("<urgente,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(17));
        else if (cabecalhoDaRegra[ii].compare("<urgente,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(18));
        else if (cabecalhoDaRegra[ii].compare("<hot,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(19));
        else if (cabecalhoDaRegra[ii].compare("<hot,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(20));
        else if (cabecalhoDaRegra[ii].compare("<hot,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(21));
        else if (cabecalhoDaRegra[ii].compare("<num_faleid_logins,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(22));
        else if (cabecalhoDaRegra[ii].compare("<num_faleid_logins,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(23));
        else if (cabecalhoDaRegra[ii].compare("<num_faleid_logins,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(24));
        else if (cabecalhoDaRegra[ii].compare("<num_compromised,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(26));
        else if (cabecalhoDaRegra[ii].compare("<num_compromised,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(27));
        else if (cabecalhoDaRegra[ii].compare("<num_compromised,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(28));
        else if (cabecalhoDaRegra[ii].compare("<num_root,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(31));
        else if (cabecalhoDaRegra[ii].compare("<num_root,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(32));
        else if (cabecalhoDaRegra[ii].compare("<num_root,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(33));
        else if (cabecalhoDaRegra[ii].compare("<num_file_creatinos,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(34));
        else if (cabecalhoDaRegra[ii].compare("<num_file_creatinos,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(35));
        else if (cabecalhoDaRegra[ii].compare("<num_file_creatinos,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(36));
        else if (cabecalhoDaRegra[ii].compare("<num_shells,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(37));
        else if (cabecalhoDaRegra[ii].compare("<num_shells,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(38));
        else if (cabecalhoDaRegra[ii].compare("<num_shells,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(39));
        else if (cabecalhoDaRegra[ii].compare("<num_access_files,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(40));
        else if (cabecalhoDaRegra[ii].compare("<num_access_files,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(41));
        else if (cabecalhoDaRegra[ii].compare("<num_access_files,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(42));
        else if (cabecalhoDaRegra[ii].compare("<count,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(46));
        else if (cabecalhoDaRegra[ii].compare("<count,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(47));
        else if (cabecalhoDaRegra[ii].compare("<count,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(48));
        else if (cabecalhoDaRegra[ii].compare("<srv_count,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(49));
        else if (cabecalhoDaRegra[ii].compare("<srv_count,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(50));
        else if (cabecalhoDaRegra[ii].compare("<srv_count,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(51));
        else if (cabecalhoDaRegra[ii].compare("<serror_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(52));
        else if (cabecalhoDaRegra[ii].compare("<serror_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(53));
        else if (cabecalhoDaRegra[ii].compare("<serror_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(54));
        else if (cabecalhoDaRegra[ii].compare("<srv_serror_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(55));
        else if (cabecalhoDaRegra[ii].compare("<srv_serror_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(56));
        else if (cabecalhoDaRegra[ii].compare("<srv_serror_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(57));
        else if (cabecalhoDaRegra[ii].compare("<rerror_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(58));
        else if (cabecalhoDaRegra[ii].compare("<rerror_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(59));
        else if (cabecalhoDaRegra[ii].compare("<rerror_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(60));
        else if (cabecalhoDaRegra[ii].compare("<srv_rerror_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(61));
        else if (cabecalhoDaRegra[ii].compare("<srv_rerror_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(62));
        else if (cabecalhoDaRegra[ii].compare("<srv_rerror_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(63));
        else if (cabecalhoDaRegra[ii].compare("<same_srv_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(64));
        else if (cabecalhoDaRegra[ii].compare("<same_srv_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(65));
        else if (cabecalhoDaRegra[ii].compare("<same_srv_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(66));
        else if (cabecalhoDaRegra[ii].compare("<diff_srv_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(67));
        else if (cabecalhoDaRegra[ii].compare("<diff_srv_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(68));
        else if (cabecalhoDaRegra[ii].compare("<diff_srv_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(69));
        else if (cabecalhoDaRegra[ii].compare("<srv_diff_host_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(70));
        else if (cabecalhoDaRegra[ii].compare("<srv_diff_host_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(71));
        else if (cabecalhoDaRegra[ii].compare("<srv_diff_host_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(72));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_count,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(73));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_count,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(74));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_count,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(75));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_count,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(76));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_count,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(77));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_count,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(78));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_same_srv_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(79));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_same_srv_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(80));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_same_srv_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(81));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_diff_srv_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(82));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_diff_srv_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(83));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_diff_srv_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(84));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_same_src_port_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(85));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_same_src_port_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(86));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_same_src_port_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(87));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_diff_host_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(88));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_diff_host_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(89));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_diff_host_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(90));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_serror_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(91));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_serror_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(92));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_serror_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(93));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_serror_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(94));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_serror_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(95));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_serror_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(96));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_rerror_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(97));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_rerror_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(98));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_rerror_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(99));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_rerror_rate,Baixo>") == 0)
            descConsiderar.push_back(vetorLido.at(100));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_rerror_rate,Medio>") == 0)
            descConsiderar.push_back(vetorLido.at(101));
        else if (cabecalhoDaRegra[ii].compare("<dst_host_srv_rerror_rate,Alto>") == 0)
            descConsiderar.push_back(vetorLido.at(102));
        else {
            palavraADesmembrar.push_back(cabecalhoDaRegra[ii]);
            palavraDesmembrada = iarf.AtributoConjSelecao(palavraADesmembrar);
            palavra = palavraDesmembrada.at(0);
            for (int k = 1; k < palavraDesmembrada.size(); k++)
                palavra = palavra + palavraDesmembrada.at(k);
            if (palavra.compare("tipo_protocolo") == 0)
                if (cabecalhoDaRegra[ii] == vetorLido.at(3))
                    descConsiderar.push_back(vetorLido.at(3));
                else descConsiderar.push_back("null");
            else if (palavra.compare("servico") == 0)
                if (cabecalhoDaRegra[ii] == vetorLido.at(4))
                    descConsiderar.push_back(vetorLido.at(4));
                else descConsiderar.push_back("null");
            else if (palavra.compare("flag") == 0)
                if (cabecalhoDaRegra[ii] == vetorLido.at(5))
                    descConsiderar.push_back(vetorLido.at(5));
                else descConsiderar.push_back("null");
            else if (palavra.compare("land") == 0)
                if (cabecalhoDaRegra[ii] == vetorLido.at(12))
                    descConsiderar.push_back(vetorLido.at(12));
                else descConsiderar.push_back("null");
            else if (palavra.compare("logged_in") == 0)
                if (cabecalhoDaRegra[ii] == vetorLido.at(25))
                    descConsiderar.push_back(vetorLido.at(25));
                else descConsiderar.push_back("null");
            else if (palavra.compare("root_shell") == 0)
                if (cabecalhoDaRegra[ii] == vetorLido.at(29))
                    descConsiderar.push_back(vetorLido.at(29));
                else descConsiderar.push_back("null");
            else if (palavra.compare("su_attempted") == 0)
                if (cabecalhoDaRegra[ii] == vetorLido.at(30))
                    descConsiderar.push_back(vetorLido.at(30));
                else descConsiderar.push_back("null");
            else if (palavra.compare("num_outbound_cmds") == 0)
                if (cabecalhoDaRegra[ii] == vetorLido.at(43))
                    descConsiderar.push_back(vetorLido.at(43));
                else descConsiderar.push_back("null");
            else if (palavra.compare("is_hot_login") == 0)
                if (cabecalhoDaRegra[ii] == vetorLido.at(44))
                    descConsiderar.push_back(vetorLido.at(44));
                else descConsiderar.push_back("null");
            else if (palavra.compare("is_guest_login") == 0)
                if (cabecalhoDaRegra[ii] == vetorLido.at(45))
                    descConsiderar.push_back(vetorLido.at(45));
                else descConsiderar.push_back("null");

            palavra.clear();
            palavraADesmembrar.clear();
            palavraDesmembrada.clear();
        }
    }
    return descConsiderar;
}

double Classificacao::RI(double GrauCertezaDaRegras, double fs) {

    /*
     * RI_<t,rp> é um peso que determina a influência do rateio da medida correspondente
     * da p_ésima regra no cálculo final da medida correspondente. Sua fórmula é:
     * RI_<t,rp> = fs_<t,rp> x cp
     * Onde:
     * fs_<t,rp> é um conceito fuzzy denominado como firing strength, é usado para medir o 
     * grau de satisfação do antecedente da regra da transação ou amostra. Sua fórmula é:
     * fs_<t,rp> = mulj=1 até np alta apj(t[xpj]);
     * cp é o grau de certeza da regra rp
     */

    double RI_t_rp, cp;

    cp = GrauCertezaDaRegras;

    RI_t_rp = fs * cp;

    return RI_t_rp;
}

double Classificacao::mm_trp(double pertVlrRefConsequente, double limiarMinimo) {

    /*
     * mm_<t,rp> é uma medida de estimativa de quão bom a amostra t é com relação
     * a regra rp. Ela representa o desvio da amostra t com o consequente da regra.
     * Sua fórmula é:
     * mm_<t,rp> = 1 - alfa bp(t[yp])
     */

    double mm_t_rp;

    if (pertVlrRefConsequente >= limiarMinimo)
        mm_t_rp = 1 - pertVlrRefConsequente;
    else
        mm_t_rp = 1 - 0;

    return mm_t_rp;
}

double Classificacao::firingStrength(vector<double> pertDosVlrsRefAntecedente, double limiarMinimo) {

    double fs_t_rp = 1, limiarNaoPermitido = 0;

    for (int i = 0; i < pertDosVlrsRefAntecedente.size(); i++) {
        if (pertDosVlrsRefAntecedente.at(i) >= limiarMinimo)
            fs_t_rp = fs_t_rp * pertDosVlrsRefAntecedente.at(i);
        else
            fs_t_rp = fs_t_rp * limiarNaoPermitido;
    }

    return fs_t_rp;
}

double Classificacao::ABC(vector<double> RegraInducao, vector<double> _mm) {

    double MM_t_rp = 0, somatorioRI = 0, somatorioRI_mm = 0;
    /*
    for(int k=0; k<RegraInducao.size();k++){
        cout<<RegraInducao.at(k)<<" ";
        
    }cout<<endl;
     */
    for (int i = 0; i < RegraInducao.size(); i++) {
        somatorioRI = somatorioRI + RegraInducao.at(i);
        somatorioRI_mm = somatorioRI_mm + (RegraInducao.at(i) * _mm.at(i));
    }
    if (somatorioRI != 0)
        MM_t_rp = somatorioRI_mm / somatorioRI;
    else
        MM_t_rp = 0;

    return MM_t_rp;

}

double Classificacao::ABC_Mamdani(vector<double> grauCertezaRegra, vector<double> mmLinha) {

    double MM_t_R = 0, somatorioGC = 0, multiplicaGC_mm = 0;

    for (int i = 0; i < grauCertezaRegra.size(); i++) {
        somatorioGC = somatorioGC + grauCertezaRegra.at(i);
        multiplicaGC_mm = multiplicaGC_mm + (grauCertezaRegra.at(i) * mmLinha.at(i));
    }
    MM_t_R = multiplicaGC_mm / somatorioGC;

    return MM_t_R;
}

void Classificacao::EstimativaABC_Extendida(vector<string> tipoDeConexao, vector<string> label, char nomeArqPrincipal[100], char arqFP[100], char arqFN[100]) {

    /*
     * Nesse momento é declarado dois conceitos, são eles:
     * Falso Negativo: quando uma conexão é identificada como ataque, mas ela é 
     * uma conexão normal.
     * Falso positivo: quando uma conexão é identificada como normal, mas ela é 
     * uma conexão de ataque.
     */

    double falsoNegativo = 0, falsoPositivo = 0, totalConexaoNormal = 0, totalConexaoAtaque = 0;
    double taxaFalsoPositivo, taxaDeteccao, taxaFalsoNegativo, naoIdentificado = 0;
    double vp = 0, vn = 0;
    string palavra = "normal.";
    ofstream outExtABC_E(nomeArqPrincipal);
    ofstream outFP(arqFP);
    ofstream outFN(arqFN);

    //Tratamento de erro para o arquivo de saída
    if (!outExtABC_E.is_open()) {
        printf("Erro na abertura do arquivo de estimativa!");
        outExtABC_E.clear();
        exit(1);
    }

    if (!outFP.is_open()) {
        printf("Erro na abertura do arquivo de falso positivo!");
        outFP.clear();
        exit(1);
    }

    if (!outFN.is_open()) {
        printf("Erro na abertura do arquivo de falso negativo!");
        outFN.clear();
        exit(1);
    }

    if (tipoDeConexao.size() == label.size()) {

        for (int i = 0; i < label.size(); i++) {
            
            
            
            //Verdadeiro positivo
            if((tipoDeConexao[i].compare(palavra)!=0)&&(label[i].compare(palavra)!=0)){
                 vp++;
             }else{
                //Verdadeiro negativo
                if((tipoDeConexao[i].compare(palavra)==0)&&(label[i].compare(palavra)==0)){
                    vn++;
                }else{
                    /*
                    * Falso positivo = falsamente uma intrusão
                    * Significa que foi detectato como ataque e não é
                    */

                   if ((label[i].compare(palavra) == 0)&&(tipoDeConexao[i].compare(palavra) != 0)) {
                       falsoPositivo++;
                       outFP << "Falso Positivo (linha: " << i << "): Tipo detectaco - " << tipoDeConexao[i] << ", rótulo - " << label[i] << endl;
                   }
                       /*
                        * Falso negativo = falsamente a ausência de uma intrusão
                        * Significa que foi detectato como normal e não é
                        */
                   else if ((tipoDeConexao[i].compare(palavra) == 0)&&(label[i].compare(palavra) != 0)) {
                       falsoNegativo++;
                       outFN << "Falso Negativo (linha: " << i << "): Tipo detectaco - " << tipoDeConexao[i] << ", rótulo - " << label[i] << endl;
                   }

                }
             }

            if (label[i].compare(palavra) != 0) {
                totalConexaoAtaque++;
            } else if (label[i].compare(palavra) == 0) {
                totalConexaoNormal++;
            }

        }
    }

    //Realizando o cáculo
    taxaFalsoPositivo = (falsoPositivo / totalConexaoNormal);
    taxaDeteccao = 1 - (falsoNegativo / totalConexaoAtaque);
    taxaFalsoNegativo = (falsoNegativo / totalConexaoAtaque);

    //Gerando o arquivo com os resultados
    outExtABC_E << "\nEstimativa para ABC_Extendida:" << endl;
    outExtABC_E << "TP: " << vp << endl;
    outExtABC_E << "TN: " << vn << endl;
    outExtABC_E << "FP: " << falsoPositivo << endl;
    outExtABC_E << "FN: " << falsoNegativo << endl;
    outExtABC_E << "Valor total de conexões normais: " << totalConexaoNormal << endl;
    outExtABC_E << "Valor total de conexões de ataques: " << totalConexaoAtaque << endl<< endl;
    
    outExtABC_E << "MAtriz de confusão " << endl;
    outExtABC_E << "Accuracia: " << (vp + vn)/(totalConexaoNormal+totalConexaoAtaque) << endl;
    outExtABC_E << "Má classificação: " << (falsoPositivo + falsoNegativo)/(totalConexaoNormal+totalConexaoAtaque) << endl;
    outExtABC_E << "Taxa VP: " << vp/(falsoNegativo+vp) << endl;
    outExtABC_E << "Taxa FP: " << falsoPositivo/(vn+falsoPositivo) << endl;
    outExtABC_E << "Especificidade: " << vn/(vn+falsoPositivo) << endl;
    outExtABC_E << "Precisão: " << vp/(falsoPositivo+vp) << endl;
    outExtABC_E << "Prevalência: " << (falsoNegativo+vp)/(totalConexaoNormal+totalConexaoAtaque) << endl;
    
    
    
    /*
    outExtABC_E << "Valor total de falso positivo: " << falsoPositivo << endl;
    outExtABC_E << "Valor total de falso negativo: " << falsoNegativo << endl;
    outExtABC_E << "Valor total de conexões normais: " << totalConexaoNormal << endl;
    outExtABC_E << "Valor total de conexões de ataques: " << totalConexaoAtaque << endl;
    outExtABC_E << "Valor da taxa de falso positivo: " << (taxaFalsoPositivo * 100) << endl;
    outExtABC_E << "Valor da taxa de falso negativo: " << (taxaFalsoNegativo * 100) << endl;
    outExtABC_E << "Valor da taxa de detecção: " << (taxaDeteccao * 100) << endl;
    //outExtABC_E<<"Total de não identificado: "<<naoIdentificado<<endl;
    
    outExtABC_E<<"Total de verdadeiros positivos: "<<vp<<endl;
    outExtABC_E<<"Total de verdadeiros negativos: "<<vn<<endl;
    outExtABC_E<<"Total de positivos: "<<(vp+taxaFalsoNegativo)<<endl;
    outExtABC_E<<"Total de S_E: "<<(vp/(vp+taxaFalsoNegativo))<<endl<<endl;
    outExtABC_E<<"Total de negativos: "<<(taxaFalsoPositivo+vn)<<endl;
    outExtABC_E<<"Total de E_s: "<<(vn/(taxaFalsoPositivo+vn))<<endl;
     */
    //Fechando o arquivo
    outExtABC_E.close();
    outFP.close();
    outFN.close();
}

void Classificacao::EstimativaABC(vector<string> tipoDeConexao, vector<string> label, char nomeArq[100], char arqFalsoP[100], char arqFalsoN[100]) {

    /*
     * Nesse momento é declarado dois conceitos, são eles:
     * Falso Negativo: quando uma conexão é identificada como ataque, mas ela é 
     * uma conexão normal.
     * Falso positivo: quando uma conexão é identificada como normal, mas ela é 
     * uma conexão de ataque.
     */
    int contDetU = 0, contDetD = 0, contDetR = 0, contDetP = 0;
    double falsoNegativo = 0, falsoPositivo = 0, totalConexaoAtaque = 0, totalConexaoNormal = 0, vn, vp;
    double taxaFalsoPositivo, taxaDeteccao, taxaFalsoNegativo, naoIdentificado = 0;
    double taxaDoS, taxaProbe, taxaR2L, taxaU2R;
    double contaTaxaDoS = 0, contaTaxaProbe = 0, contaTaxaR2L = 0, contaTaxaU2R = 0;
    double TotalDoS = 0, TotalProbe = 0, TotalR2L = 0, TotalU2R = 0;
    string palavra = "normal.";
    vector<string> ataquesDoS, ataquesProbe, ataquesR2L, ataquesU2R;
    vector<string> ataquesDoSC, ataquesProbeC, ataquesR2LC, ataquesU2RC;
    ofstream outExtABC(nomeArq);
    ofstream outFP(arqFalsoP);
    ofstream outFN(arqFalsoN);
    ofstream outPE("Probe_errado");
    ofstream outDE("DoS_errado");
    ofstream outUE("U2R_errado");
    ofstream outRE("R2L_errado");

    //Alimentando os vetores
    /*
     * Os ataques comentados são aqueles que não existem 
     * na base de treinamento. Portanto, foram classificados como
     * ataques desconhecidos.
     */

    ataquesDoS.push_back("back.");
    ataquesDoS.push_back("land.");
    ataquesDoS.push_back("neptune.");
    ataquesDoS.push_back("pod.");
    ataquesDoS.push_back("smurf.");
    ataquesDoS.push_back("teardrop.");

    ataquesDoSC = ataquesDoS;
    /*
      ataquesDoS.push_back("apache2.");
      ataquesDoS.push_back("mailbomb.");
      ataquesDoS.push_back("processtable.");
      ataquesDoS.push_back("udpstorm.");
      ataquesDoSC = ataquesDoS;
     */

    ataquesProbe.push_back("ipsweep.");
    ataquesProbe.push_back("nmap.");
    ataquesProbe.push_back("portsweep.");
    ataquesProbe.push_back("satan.");
    ataquesProbeC = ataquesDoS;


    ataquesR2L.push_back("ftp_write.");
    ataquesR2L.push_back("guess_passwd.");
    ataquesR2L.push_back("phf.");
    ataquesR2L.push_back("spy.");
    ataquesR2L.push_back("warezmaster.");
    ataquesR2L.push_back("imap.");
    ataquesR2L.push_back("multihop.");
    ataquesR2L.push_back("warezclient.");

    ataquesR2LC = ataquesR2L;
    /*
    ataquesR2L.push_back("impa.");
    ataquesR2L.push_back("xlock.");
    ataquesR2L.push_back("xsnoop.");
    ataquesR2L.push_back("named.");
    ataquesR2L.push_back("worm.");
    ataquesR2L.push_back("snmpguess.");
    ataquesR2LC = ataquesR2L;
     */
    ataquesU2R.push_back("perl.");
    ataquesU2R.push_back("rootkit.");
    ataquesU2R.push_back("buffer_overflow.");
    ataquesU2R.push_back("loadmodule.");
    ataquesU2RC = ataquesU2R;
    /*
    ataquesU2R.push_back("sqlattack.");
    ataquesU2R.push_back("xterm.");
    ataquesU2R.push_back("httptunnel.");
    ataquesU2R.push_back("ps.");
    ataquesU2RC = ataquesU2R;
     */

    //Tratamento de erro para o arquivo de saída
    if (!outExtABC.is_open()) {
        printf("Erro na abertura do arquivo de estimativa!");
        outExtABC.clear();
        exit(1);
    }

    if (!outFP.is_open()) {
        printf("Erro na abertura do arquivo de falso positivo!");
        outFP.clear();
        exit(1);
    }

    if (!outFN.is_open()) {
        printf("Erro na abertura do arquivo de falso negativo!");
        outFN.clear();
        exit(1);
    }

    if (tipoDeConexao.size() == label.size()) {

        for (int i = 0; i < label.size(); i++) {
            contDetU = 0;
            contDetD = 0, contDetR = 0, contDetP = 0;

            //Calculando a porcentagem de ataques
            if (label[i].compare(palavra) != 0) {

                //Verificando o total de ataques
                totalConexaoAtaque++;

                //Verificando o total de ataques do tipo DoS
                for (int k = 0; k < ataquesDoSC.size(); k++) {
                    if (label[i].compare(ataquesDoSC[k]) == 0) {
                        TotalDoS++;
                        break;
                    }
                }

                //Verificando o total de ataques do tipo Probe
                for (int k = 0; k < ataquesProbeC.size(); k++) {
                    if (label[i].compare(ataquesProbeC[k]) == 0) {
                        TotalProbe++;
                        break;
                    }
                }

                //Verificando o total de ataques do tipo R2L
                for (int k = 0; k < ataquesR2LC.size(); k++) {
                    if (label[i].compare(ataquesR2LC[k]) == 0) {
                        TotalR2L++;
                        break;
                    }
                }

                //Verificando o total de ataques do tipo R2L
                for (int k = 0; k < ataquesU2RC.size(); k++) {
                    if (label[i].compare(ataquesU2RC[k]) == 0) {
                        TotalU2R++;
                        break;
                    }
                }

            }//Verificando a quantidade de conexões normais
            else totalConexaoNormal++;

            if (tipoDeConexao[i].compare("naoIdentifica") != 0) {

                //Alimentando o vetor de ataque conforme o grupo pertencente
                for (int k = 0; k < ataquesDoS.size(); k++) {
                    if ((label[i].compare(ataquesDoS[k]) == 0)&&(tipoDeConexao[i].compare("Dos") == 0)) {
                        contaTaxaDoS++;
                        contDetD = 1;
                        break;
                    }
                }
                if ((contDetD != 1)&&(tipoDeConexao[i].compare("Dos") == 0)) {
                    outDE << tipoDeConexao[i] << ", rótulo - " << label[i] << endl;
                }

                for (int k = 0; k < ataquesProbe.size(); k++) {
                    if ((label[i].compare(ataquesProbe[k]) == 0)&&(tipoDeConexao[i].compare("Probe") == 0)) {
                        contaTaxaProbe++;
                        contDetP = 1;
                        break;
                    }
                }
                if ((contDetP != 1)&&(tipoDeConexao[i].compare("Probe") == 0)) {
                    outPE << tipoDeConexao[i] << ", rótulo - " << label[i] << endl;
                }

                for (int k = 0; k < ataquesR2L.size(); k++) {
                    if ((label[i].compare(ataquesR2L[k]) == 0)&&(tipoDeConexao[i].compare("R2L") == 0)) {
                        contaTaxaR2L++;
                        contDetR = 1;
                        break;
                    }
                }
                if ((contDetR != 1)&&(tipoDeConexao[i].compare("R2L") == 0)) {
                    outRE << tipoDeConexao[i] << ", rótulo - " << label[i] << endl;
                }
                for (int k = 0; k < ataquesU2R.size(); k++) {
                    if ((label[i].compare(ataquesU2R[k]) == 0)&&(tipoDeConexao[i].compare("U2R") == 0)) {
                        contaTaxaU2R++;
                        contDetU = 1;
                        break;
                    }
                }
                if ((contDetU != 1)&&(tipoDeConexao[i].compare("U2R") == 0)) {
                    outUE << tipoDeConexao[i] << ", rótulo - " << label[i] << endl;
                    contDetU = 0;
                }
                
                //Verdadeiro positivo
                if((tipoDeConexao[i].compare(palavra)!=0)&&(label[i].compare(palavra)!=0)){
                     vp++;
                 }else{
                    //Verdadeiro negativo
                    if((tipoDeConexao[i].compare(palavra)==0)&&(label[i].compare(palavra)==0)){
                        vn++;
                    }else{
                        /*
                        * Falso positivo = falsamente uma intrusão
                        * Significa que foi detectato como ataque e não é
                        */

                       if ((label[i].compare(palavra) == 0)&&(tipoDeConexao[i].compare(palavra) != 0)) {
                           falsoPositivo++;
                           outFP << "Falso Positivo (linha: " << i << "): Tipo detectaco - " << tipoDeConexao[i] << ", rótulo - " << label[i] << endl;
                       }
                           /*
                            * Falso negativo = falsamente a ausência de uma intrusão
                            * Significa que foi detectato como normal e não é
                            */
                       else if ((tipoDeConexao[i].compare(palavra) == 0)&&(label[i].compare(palavra) != 0)) {
                           falsoNegativo++;
                           outFN << "Falso Negativo (linha: " << i << "): Tipo detectaco - " << tipoDeConexao[i] << ", rótulo - " << label[i] << endl;
                       }

                    }
                 }
            } else
                naoIdentificado++;
        }
    } else {
        cout << "A quantidade de elementos a validar não é a mesma do arquivo de etiqueta\n";
        exit(1);
    }

    //Realizando o cáculo
    if (totalConexaoNormal != 0)
        taxaFalsoPositivo = (falsoPositivo / totalConexaoNormal);
    if (totalConexaoAtaque != 0) {
        taxaDeteccao = 1 - (falsoNegativo / totalConexaoAtaque);
        taxaFalsoNegativo = (falsoNegativo / totalConexaoAtaque);
        taxaDoS = (contaTaxaDoS / TotalDoS);
        taxaProbe = (contaTaxaProbe / TotalProbe);
        taxaR2L = (contaTaxaR2L / TotalR2L);
        taxaU2R = (contaTaxaU2R / TotalU2R);
    }

    //Gerando o arquivo com os resultados
    outExtABC << "\nEstimativa para ABC:" << endl;
    outExtABC << "TP: " << vp << endl;
    outExtABC << "TN: " << vn << endl;
    outExtABC << "FP: " << falsoPositivo << endl;
    outExtABC << "FN: " << falsoNegativo << endl;
    
    outExtABC << "Valor total de conexões normais: " << totalConexaoNormal << endl;
    outExtABC << "Valor total de conexões de ataques: " << totalConexaoAtaque << endl<< endl;
    
    outExtABC << "MAtriz de confusão " << endl;
    outExtABC << "Accuracia: " << (vp + vn)/(totalConexaoNormal+totalConexaoAtaque) << endl;
    outExtABC << "Má classificação: " << (falsoPositivo + falsoNegativo)/(totalConexaoNormal+totalConexaoAtaque) << endl;
    outExtABC << "Taxa VP: " << vp/(falsoNegativo+vp) << endl;
    outExtABC << "Taxa FP: " << falsoPositivo/(vn+falsoPositivo) << endl;
    outExtABC << "Especificidade: " << vn/(vn+falsoPositivo) << endl;
    outExtABC << "Precisão: " << vp/(falsoPositivo+vp) << endl;
    outExtABC << "Prevalência: " << (falsoNegativo+vp)/(totalConexaoNormal+totalConexaoAtaque) << endl;
    /*
    outExtABC << "Valor total de falso positivo: " << falsoPositivo << endl;
    outExtABC << "Valor total de falso negativo: " << falsoNegativo << endl;
    outExtABC << "Valor total de conexões normais: " << totalConexaoNormal << endl;
    outExtABC << "Valor total de conexões de ataques: " << totalConexaoAtaque << endl;
    outExtABC << "Valor da taxa de falso positivo: " << (taxaFalsoPositivo * 100) << endl;
    outExtABC << "Valor da taxa de falso negativo: " << (taxaFalsoNegativo * 100) << endl;
    outExtABC << "Valor da taxa de detecção: " << (taxaDeteccao * 100) << endl;
    outExtABC << "Total de não identificado: " << naoIdentificado << endl;
    */
    outExtABC << endl << " POR ATAQUE " << endl;
    outExtABC << "Valor da taxa de DoS: " << taxaDoS << endl;
    outExtABC << "Valor da taxa de Probe: " << taxaProbe << endl;
    outExtABC << "Valor da taxa de R2L: " << taxaR2L << endl;
    outExtABC << "Valor da taxa de U2R: " << taxaU2R << endl;

    //Fechando o arquivo
    outExtABC.close();
    outFP.close();
    outFN.close();
    outDE.close();
    outPE.close();
    outRE.close();
    outUE.close();
}

vector<double> Classificacao::PertinenciaValores(vector<string> itensDoSubconjunto) {

    vector<double> pertinencia;

    string palavra1, letraC, palavra2;
    double valor;
    int cont = 0;
    char letra;


    while (cont != itensDoSubconjunto.size()) {

        palavra1 = itensDoSubconjunto.at(cont);
        //cout<< palavra1<<endl;
        if (palavra1.compare("null") == 0) {
            pertinencia.push_back(0);

        } else {
            for (int jj = 0; jj < palavra1.size(); jj++) {
                letra = palavra1.at(jj);
                palavra2.push_back(letra);

                if (palavra1.at(jj) == 44) {
                    if ((palavra2.compare("<tipo_protocolo,") == 0) || (palavra2.compare("<servico,") == 0) || (palavra2.compare("<flag,") == 0) || (palavra2.compare("<land,") == 0) || (palavra2.compare("<logged_in,") == 0) || (palavra2.compare("<root_shell,") == 0) || (palavra2.compare("<su_attempted,") == 0) || (palavra2.compare("<<num_outbound_cmds,") == 0) || (palavra2.compare("<is_hot_login,") == 0) || (palavra2.compare("<is_guest_login,") == 0))
                        pertinencia.push_back(1);
                    else {
                        for (int j = jj + 1; j < palavra1.size() - 1; j++) {
                            letraC.push_back(palavra1.at(j));
                        }
                        stringstream converte(letraC);
                        converte >> valor;
                        pertinencia.push_back(valor);
                        letraC.clear();
                        palavra2.clear();
                    }
                }
            }
            palavra2.clear();
        }

        cont++;
    }
    return pertinencia;

}

double Classificacao::MetodoMamdani(double fst, double valorConsequente, double grauCertezaRegra, double limiteValorPermitido) {

    double v_antecedente, v_consequente = 0, resposta;

    v_antecedente = fst;

    if (valorConsequente >= limiteValorPermitido)
        v_consequente = valorConsequente;
    else
        v_consequente = 0;

    if (v_antecedente <= v_consequente)
        resposta = v_antecedente;
    else if (v_consequente <= v_antecedente)
        resposta = v_consequente;

    return resposta;

}