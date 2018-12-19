function Histograma()

    x=-2.9:0.2:2.9; %especifica as divisões a serem usadas
    y=randn(5000,1) %cria 5000 pontos aleatórios, com distribuição normal
    hist(y,x)       %desenha o histograma
    title('Figura 25.16: Histograma de distribuição normal')
end