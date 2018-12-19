/* 
 * File:   Guloso.cpp
 * Author: allinesf
 * 
 * Created on 17 de Fevereiro de 2015, 20:31
 */

#include "Guloso.h"
#include "FaseDeTreinamento.h"
#include "utilitarios.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <bits/stl_vector.h>

using namespace std;

Guloso::Guloso() {}

Guloso::~Guloso() {}

vector<int> Guloso::guloso(vector<vector<string> > matrizHG, int &indiceDoSubconjuntoEstrela, vector<string> &elementosDoConjunto, vector<string> &naoMembros){
        
        int harestaEscolhida, quantidadeNaoMembros=0, iteracao, contGrande=0;
        int tamanhoEstrela=41, valorNulo=0, contaHA=0, maior , indMaior=0;
        int rankSub=0, rankEstrela=0, tamanhoDoCandidato;   
        double qtdeAcessoDosNaoMembro=0;
        vector<int> guardaIVN, selecaoHAE;
        vector<int> solucao_Estrela;
        vector<int> liConjMaior, vetorValorNulo, tamanhoDasHA;
        vector<string> E_escolhida, E_escolhidaSrepeticao;
        vector< vector<int> > mHA;
                
        iteracao = matrizHG.size();
        //Informando o tamanho de cada hyperAresta
            for(int i=0;i<matrizHG.size();i++){
                tamanhoDasHA.push_back(matrizHG[i].size());
            }
            
            cout<<"Imprimindo o tamanho de cada hAresta"<<endl;
            //Informando o tamanho de cada hyperAresta
            for(int i=0;i<tamanhoDasHA.size();i++){
                cout<<tamanhoDasHA[i]<<" ";
            }cout<<endl;
            maior = tamanhoDasHA.at(0);
        do
        {
            
        do{
            
            int contaSelec=0;;
            
            //Verificando a maior aresta
            for(int i=0;i<tamanhoDasHA.size();i++){
                
                    if(tamanhoDasHA[i] >= maior){
                        if(selecaoHAE.size()==0){
                            maior = tamanhoDasHA[i];
                            indMaior = i;
                            contaSelec++;
                            
                        }else{
                            for(int k=0; k<selecaoHAE.size();k++){
                                if(i != selecaoHAE[k]){
                                    contGrande++;
                                }
                            }
                            if(contGrande == selecaoHAE.size()){
                                maior = tamanhoDasHA[i];
                                indMaior = i;
                                contaSelec++;
                            }
                            contGrande =0;
                        }
                    }
                    
            }
            int contaDif=0;
            if((contaSelec == 0)&&(selecaoHAE.size()!=tamanhoDasHA.size())){
                for(int ki=0; ki<tamanhoDasHA.size(); ki++){
                    contaDif=0;
                    for(int kk=0; kk<selecaoHAE.size();kk++){
                        if(ki!=selecaoHAE[kk])
                            contaDif++;
                    }
                    if(contaDif == selecaoHAE.size()){//significa que ele não foi selecionado
                        //Selecionar a maior hiperAresta 
                        harestaEscolhida = ki;
                        E_escolhida = matrizHG.at(ki);
                        selecaoHAE.push_back(harestaEscolhida);
                        
                    }
                }
            }else{
                //Selecionar a maior hiperAresta 
                harestaEscolhida = indMaior;
                E_escolhida = matrizHG.at(indMaior);
                selecaoHAE.push_back(harestaEscolhida);
            }
             
            
            
                /*
            int cont=0;
            if(selecaoHAE.size()==0){
                srand((unsigned)time(NULL));
                harestaEscolhida = rand()%matrizHG.size();
                E_escolhida = matrizHG.at(harestaEscolhida);
                selecaoHAE.push_back(harestaEscolhida);
                contaHA++;
            }else{
                do{
                    cont =0;
                    srand((unsigned)time(NULL));
                    harestaEscolhida = rand()%matrizHG.size();
                    for(int p=0; p<selecaoHAE.size(); p++){
                        if(harestaEscolhida == selecaoHAE.at(p))
                            cont ++;
                    } 
                }while (cont!=0);
                E_escolhida = matrizHG.at(harestaEscolhida);
                selecaoHAE.push_back(harestaEscolhida);
                contaHA++;
            }
            */
            cout<<"ElementoEscolhido "<<endl;
            for(int i=0;i<E_escolhida.size();i++){
                cout<<E_escolhida.at(i)<<" ";
            }cout<<endl;

            //Gera vertices
            mHA = RetornaVertices(E_escolhida, E_escolhidaSrepeticao);
            cout<<"Imprimindo a matriz da hiperaresta escolhida"<<endl;
            for(int i=0;i<mHA.size();i++){
                for(int ii=0;ii<mHA[i].size();ii++){
                    cout<<mHA[i][ii]<<" ";
                }cout<<endl;
            }
            
            for(int i=0;i<E_escolhidaSrepeticao.size();i++){
                cout<<E_escolhidaSrepeticao.at(i)<<" ";
            }cout<<endl;

            /*
             * Verificando se existe na matriz de hyperArestas algum não membro 
             */

            //Calculando a quantidade de arestas de cada vértice 
            vetorValorNulo.clear();
            guardaIVN.clear();
            for(int k=0; k<mHA.size(); k++){
                for(int i=0;i<mHA[k].size();i++){
                    if(mHA[k][i] ==0)
                        valorNulo++;
                }

                if(valorNulo != 0){
                    vetorValorNulo.push_back(valorNulo);
                    guardaIVN.push_back(k);
                    valorNulo=0;
                }
            }

            /*
             * Se o tamanho do vetorValorNulo for igual a zero
             * significa que não existe não membros nesse conjunto.
             * Será necessário escolher uma nova hiṕeraresta.
             */
            iteracao--;
        }while(vetorValorNulo.size() == 0);
        
        /*
         * Verificando qual(is) linha(s) do maior conjunto possuem arestas
        */
                
        for(int k=0; k<vetorValorNulo.size(); k++){
            for(int i=0;i<mHA[guardaIVN[k]].size();i++){
                if(mHA[guardaIVN[k]][i] !=0)
                    liConjMaior.push_back(i);
            }
            
            /*
             * Verificando quantos não membros a linha a ser testada possui.
             * Para ser uma estrela, seleciona-se o conjunto com maior não membros.
             */
            
            quantidadeNaoMembros = vetorValorNulo[k];
            tamanhoDoCandidato = liConjMaior.size();
            
            if(quantidadeNaoMembros > 1){
                
                /*
                * Chama a função selecionaSubconjunto para verificar se os não-membros
                * desse subconjunto, consegue acessá-lo passando no máximo uma aresta.
                * Para isso, verifa-se qual é o elemento não-membro e quais membros do subconjunto
                * consegue acessá-lo
               */
               qtdeAcessoDosNaoMembro = VerificaAcessoDosNaoMembro(liConjMaior, mHA, guardaIVN[k]);
            }
            rankSub = quantidadeNaoMembros;
            
            /*
             * Se a qtdeAcessoDosNaoMembro == 1 (ele acessa os membros passando no máximo uma aresta) 
             * e tamanhoEstrela menor que o atual, então esse é o menor subconjunto
             * que atende ao requisito.
             * Caso contrário, o algoritmo vai em busca do melhor
            */

            if((rankSub > rankEstrela)||(qtdeAcessoDosNaoMembro==1)){
                solucao_Estrela.clear();
                rankEstrela = rankSub;
                tamanhoEstrela = tamanhoDoCandidato;
                indiceDoSubconjuntoEstrela = harestaEscolhida; 
                solucao_Estrela = mHA[guardaIVN[k]];
                elementosDoConjunto = E_escolhidaSrepeticao;
                //Selecionando os não membros
                naoMembros.clear();
                for(int i=0;i<solucao_Estrela.size();i++){
                    if(solucao_Estrela[i]!= 0){
                       naoMembros.push_back(elementosDoConjunto[i]);
                    }
                }
            }
            //Limpando os vetores e variáveis para nova seleção
            quantidadeNaoMembros = 0;
            liConjMaior.clear();
            
        }
        
                
    }while(iteracao != 0);
        
        /*
         * Se após verificar toda a matriz a solucao_Estrela for igual a zero,
         * significa que todos que foram verificados não atendem a condição ou não
         * tem não membros que acessa passando no máximo 1 aresta.
         */
        if(solucao_Estrela.size()==0){

            cout<<"\n Nenhuma das hyper-arestas atendem a condição, ou os seus não membros são acessíveis passando no máximo 1 aresta."<<endl;
            cout<<"Favor executar novamente o Apriori."<<endl;
            exit(1);
        }
    //Para verificaçãp
    cout<<"Para verificacao"<<endl;
    for(int i=0; i<solucao_Estrela.size();i++){
        cout<<solucao_Estrela[i]<<" ";
    }cout<<endl;
    cout<<"rankEstrela"<<rankEstrela;
    cout<<"tamanhoEstrela"<<tamanhoEstrela<<endl;
    cout<<"indiceDoSubconjuntoEstrela"<<indiceDoSubconjuntoEstrela<<endl; 
    cout<<"SolucaoEstrela"<<endl;
    for(int i=0;i<naoMembros.size();i++){
        cout<<naoMembros[i];
    }cout<<endl;
    cout<<"elementosDoConjunto"<<endl;
    for(int i=0;i<elementosDoConjunto.size();i++){
        cout<<elementosDoConjunto[i];
    }cout<<endl;
    return solucao_Estrela;
}

int Guloso::VerificaAcessoDosNaoMembro(vector<int> linhasConjSelecao, vector< vector<int> > hyper_Arestas, int indiceColunaConjSelecao){
    
    int contaNaoMembro, contaAcesso=0, acessoPermitido=0, totalArestaNaoMembros, qtdeMembros;
    double contaArestasDoNaoMembro;
    vector<int> naoMembro, membros;
            
    /*
    * Buscando os não-membro do subconjunto.
    * Verifica em qual coluna esse não-membro se localiza
    */
    
    for(int ii=0; ii < hyper_Arestas[indiceColunaConjSelecao].size();ii++){
        if(hyper_Arestas[indiceColunaConjSelecao][ii] == 0)
                    naoMembro.push_back(ii);//Nesse momento descobri qual é o índice do item  que não é membro
        else if(hyper_Arestas[indiceColunaConjSelecao][ii] != 0)
            membros.push_back(ii);
    }
    qtdeMembros = membros.size();
    /*
    cout<<"\nImprimindo membros\n";
    for(int ii=0; ii < membros.size();ii++){
        cout<<membros.at(ii)<<" ";
        
    }cout<<endl;
    
    cout<<"\nImprimindo nao membros\n";
    for(int ii=0; ii < naoMembro.size();ii++){
        cout<<naoMembro.at(ii)<<" ";
        
    }cout<<endl;
    */
    /*
     * Para cada não membro verifica quais membros do subconjunto eles acessam,
     * de acordo com a condição do problema, cada nó não-membro do subconjunto, deve ser
     * acessível aos nós desse subconjunto, passando no máximo uma aresta. 
     */
    for(int i=0; i<naoMembro.size(); i++){
        for(int j=0; j<membros.size(); j++){
            if(hyper_Arestas[naoMembro.at(i)][membros.at(j)] != 0){
                contaAcesso++;
            }
        }
        if(contaAcesso!=0){
            contaArestasDoNaoMembro = 1/contaAcesso;//como considera validação de não membro a não membro, o valor a ser dividido pelo contaAcesso é 1, que representa o não membro a verificar
            if(contaArestasDoNaoMembro == 1)
                acessoPermitido ++;
            contaAcesso=0;
        }
        
    }
    //Realizando o cálculo
    if(acessoPermitido == naoMembro.size())
        //será igual a um pois, para cada não membro será permitido apenas um acesso
        totalArestaNaoMembros = acessoPermitido/naoMembro.size();
    else 
        totalArestaNaoMembros = 0;
    
    return totalArestaNaoMembros;
}
vector<vector<int> > Guloso::RetornaVertices(vector<string> vHEdge, vector<string> &elementosNaoRepetitivos){
    
    vector<string> elementoEscolhido, aux;
    int **valorAresta, linha, coluna;
    vector<vector<string> > matrizvHe;
    
    vHEdge.size();
    elementoEscolhido = vHEdge;
        
    //Excluindo valores repetidos
    for(int i=0;i<elementoEscolhido.size();i++){
        for(int ii=i+1;ii<elementoEscolhido.size();ii++){
            if(elementoEscolhido.at(i)==elementoEscolhido.at(ii)){
                elementoEscolhido.erase(elementoEscolhido.begin()+ii);
                ii--;
            }
        }
    }
    elementosNaoRepetitivos = elementoEscolhido; 
    linha=coluna=elementoEscolhido.size();
    vector<vector<int> > matrizEsc(linha, vector<int>(coluna,0));
    
     //Inicializando a matriz valorAresta
    valorAresta = new int*[linha];
    
    for(int i=0; i<linha; i++)
    {
        valorAresta[i] = new int[coluna];
    }
    
    //Valor inicial de valorAresta
    for(int i=0;i<linha;i++){
        for(int j=0; j<coluna;j++){
            valorAresta[i][j]=0;
        }
    }
    
    //Gerando uma matriz dos pares ligados
    for(int i=0; i<vHEdge.size(); i+=2){
        aux.push_back(vHEdge[i]);
        aux.push_back(vHEdge[i+1]);
        matrizvHe.push_back(aux);
        aux.clear();
    }
   /* 
    cout<<"matrizvHe"<<endl;
    for(int i=0;i<matrizvHe.size(); i++){
        for(int j=0; j<matrizvHe[i].size(); j++){
            cout<<matrizvHe[i][j]<<" ";
        }cout<<endl;
    }
    */
    string  x, b;
    int guardaII, guardaI;
    for(int i=0;i<matrizvHe.size(); i++){
        x = matrizvHe[i][0];
        b = matrizvHe[i][1];
        
        for(int k=0; k<elementoEscolhido.size();k++){
            if(x == elementoEscolhido.at(k))
                guardaI = k;
            if(b == elementoEscolhido.at(k))
                guardaII=k;
        }
        valorAresta[guardaI][guardaII] = 1;
    }
    
    //Incluindo uma aresta para os elementos de mesmo índice,
    //Isso significa que esse elemento faz parte da HE em questão.
    for(int i=0;i<linha; i++){
        for(int j=0;j< coluna;j++){
            if(i==j)
               valorAresta[i][j]=1;
        }
        
    }
    //Gerando a matriz
    for(int i=0;i<linha; i++){
        for(int j=0; j<coluna; j++){
            matrizEsc[i][j] = valorAresta[i][j];
        }
    } 
    /*
    cout<<"matrizEsc"<<endl;
    for(int i=0;i<matrizEsc.size(); i++){
        for(int j=0; j<matrizEsc[i].size(); j++){
            cout<<matrizEsc[i][j]<<" ";
        }cout<<endl;
    }
     */
  return matrizEsc;  
}