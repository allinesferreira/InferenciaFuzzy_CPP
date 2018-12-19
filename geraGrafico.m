function geraGrafico()

%Leitura do arquivo de dados 
Transacao = LerArquivo('kddcup.data_10_percent_mt');

%leitura do arquivo de pertinência
Pertinencia = LerAqPertinencia('UTeste24_completo');

%Gerar os vetores para o gráfico
x = Transacao(14,:);
y = Pertinencia(1,:);
z = Pertinencia(2,:);
w = Pertinencia(3,:);

%Plotando gráfico
plot(x,y,'*',x,z,'--',x,w,'+')

end
