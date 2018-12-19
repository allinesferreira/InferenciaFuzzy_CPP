% Aquivo principal, chamando o arquivo de leitura de dados e executando %
% o algoritmo Fuzzy C-Means                                             %


function ExecutaROC ()
    
    %clear;clc;
    PadraoOuro = LerArquivo('PadraoOuro');
    Saida = LerArquivo('m_resposta_MM');
    
   %Calculando a curva ROC
   [tpr,fpr,limiar] = roc(PadraoOuro,Saida)
   
   Vpv = tpr';
   fpv = fpr';
   limiarF = limiar';


   
   
  PLOTROC(PadraoOuro,Saida)
   
end 