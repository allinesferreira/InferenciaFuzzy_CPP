%          Lendo o arquivo de dados                                      %
%          Código criado por Alline Santos Ferreira - data: 06/03/2015   %
%          Abrindo arquivo através do comando textscan, e os dados serão %
%          salvos em uma matriz T com 41 colunas de 311079 dados (ou do  %
%          tamanho do arquivo de dados.                                  %

function T =  LerArquivo(nomeArquivo)
      
    if(exist(nomeArquivo))
        fid = fopen(nomeArquivo,'r');
       
        %Capturando as informações e gerando os arquivos para cada classe
        while ~feof(fid)
            
            T = fscanf(fid,'%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f\n',[31 494100]);
            
        end
        
        fclose(fid);
        
    else
       % Informar ao usuário qual arquivo foi ignorado, uma vez que não existia no disco.
       disp('O arquivo nao existe ou o caminho é invalido.');
    end 
    
       
    
end
        
               
        
        