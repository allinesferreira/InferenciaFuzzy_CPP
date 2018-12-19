% Aquivo principal, chamando o arquivo de leitura de dados e executando %
% o algoritmo Fuzzy C-Means                                             %


function ExecutaFCM ()
    
    %clear;clc;
    Transacao = LerArquivo('kddcup.data_10_percent_mt');
   % Transacao = LerArquivo('corrected_mt');
    
   %Calculando Fuzzy C-Means para cada atributo
    
     fprintf('\nExecutando para FCM para coluna 1\n\n');
     v = Transacao(1,:);
    [center_col1, U_col1, obj_fcn_col1] = fcm(v', 3);
    
    x = v';
    y = U_col1(1,:);
    z = U_col1(2,:);
    w = U_col1(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    
    fprintf('\nExecutando para FCM para coluna 5\n\n');    
    v = Transacao(2,:);
    [~, U_col5, obj_fcn_col5] = fcm(v', 3);
    
    x = v';
    y = U_col5(1,:);
    z = U_col5(2,:);
    w = U_col5(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 6\n\n'); 
    v = Transacao(3,:);
    [center_col6, U_col6, obj_fcn_col6] = fcm(v', 3);
    
    x = v';
    y = U_col6(1,:);
    z = U_col6(2,:);
    w = U_col6(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    fprintf('\nExecutando para FCM para coluna 8\n\n');    
    v = Transacao(4,:);
    [center_col8, U_col8, obj_fcn_col8] = fcm(v', 3);
    
    x = v';
    y = U_col8(1,:);
    z = U_col8(2,:);
    w = U_col8(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 9\n\n');    
    v = Transacao(5,:);
    [center_col9, U_col9, obj_fcn_col9] = fcm(v', 3);x = v';
    
    x = v';
    y = U_col9(1,:);
    z = U_col9(2,:);
    w = U_col9(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
        
       
    fprintf('\nExecutando para FCM para coluna 10\n\n');    
    v = Transacao(6,:);
    [center_col10, U_col10, obj_fcn_col10] = fcm(v', 3);
    
    x = v';
    y = U_col10(1,:);
    z = U_col10(2,:);
    w = U_col10(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 11\n\n');    
    v = Transacao(7,:);
    [center_col11, U_col11, obj_fcn_col11] = fcm(v', 3);
    
    x = v';
    y = U_col11(1,:);
    z = U_col11(2,:);
    w = U_col11(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 13\n\n');    
    v = Transacao(8,:);
    [center_col13, U_col13, obj_fcn_col13] = fcm(v', 3);
    
    x = v';
    y = U_col13(1,:);
    z = U_col13(2,:);
    w = U_col13(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 16\n\n');    
    v = Transacao(9,:);
    [center_col16, U_col16, obj_fcn_col16] = fcm(v', 3);
    
    x = v';
    y = U_col16(1,:);
    z = U_col16(2,:);
    w = U_col16(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
        
    fprintf('\nExecutando para FCM para coluna 17\n\n');
    v = Transacao(10,:);
    [center_col17, U_col17, obj_fcn_col17] = fcm(v', 3);
    
    x = v';
    y = U_col17(1,:);
    z = U_col17(2,:);
    w = U_col17(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 18\n\n');
    v1 = Transacao(11,:);
    [center_col18, U_col18, obj_fcn_col18] = fcm(v1', 3);
    
    x = v';
    y = U_col18(1,:);
    z = U_col18(2,:);
    w = U_col18(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
        
    fprintf('\nExecutando para FCM para coluna 19\n\n');
    v = Transacao(12,:);
    [center_col19, U_col19, obj_fcn_col19] = fcm(v', 3);
    
    x = v';
    y = U_col19(1,:);
    z = U_col19(2,:);
    w = U_col19(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 23\n\n');
    v = Transacao(13,:);
    [center_col23, U_col23, obj_fcn_col23] = fcm(v', 3);
    
    x = v';
    y = U_col23(1,:);
    z = U_col23(2,:);
    w = U_col23(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 24\n\n');
    v = Transacao(14,:);
    [center_col24, U_col24, obj_fcn_col24] = fcm(v', 3);
    
    x = v';
    y = U_col24(1,:);
    z = U_col24(2,:);
    w = U_col24(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 25\n\n');
    v = Transacao(15,:);
    [center_col25, U_col25, obj_fcn_col25] = fcm(v', 3);
    
    x = v';
    y = U_col25(1,:);
    z = U_col25(2,:);
    w = U_col25(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
   
    
    fprintf('\nExecutando para FCM para coluna 26\n\n');
    v = Transacao(16,:);
    [center_col26, U_col26, obj_fcn_col26] = fcm(v', 3);
    
    x = v';
    y = U_col26(1,:);
    z = U_col26(2,:);
    w = U_col26(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 27\n\n');
    v = Transacao(17,:);
    [center_col27, U_col27, obj_fcn_col27] = fcm(v', 3);
    
    x = v';
    y = U_col27(1,:);
    z = U_col27(2,:);
    w = U_col27(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 28\n\n');
    v = Transacao(18,:);
    [center_col28, U_col28, obj_fcn_col28] = fcm(v', 3);
    
    x = v';
    y = U_col28(1,:);
    z = U_col28(2,:);
    w = U_col28(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 29\n\n');
    v = Transacao(19,:);
    [center_col29, U_col29, obj_fcn_col29] = fcm(v', 3);
    
    x = v';
    y = U_col29(1,:);
    z = U_col29(2,:);
    w = U_col29(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 30\n\n');
    v = Transacao(20,:);
    [center_col30, U_col30, obj_fcn_col30] = fcm(v', 3);
    
    x = v';
    y = U_col30(1,:);
    z = U_col30(2,:);
    w = U_col30(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 31\n\n');
    v = Transacao(21,:);
    [~, U_col31, obj_fcn_col31] = fcm(v', 3);
    
    x = v';
    y = U_col31(1,:);
    z = U_col31(2,:);
    w = U_col31(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 32\n\n');
    v = Transacao(22,:);
    [center_col32, U_col32, obj_fcn_col32] = fcm(v', 3);
    
    x = v';
    y = U_col32(1,:);
    z = U_col32(2,:);
    w = U_col32(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
        
    fprintf('\nExecutando para FCM para coluna 33\n\n');
    v = Transacao(23,:);
    [center_col33, U_col33, obj_fcn_col33] = fcm(v', 3);
    
    x = v';
    y = U_col33(1,:);
    z = U_col33(2,:);
    w = U_col33(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
   
    
    fprintf('\nExecutando para FCM para coluna 34\n\n');
    v = Transacao(24,:);
    [center_col34, U_col34, obj_fcn_col34] = fcm(v', 3);
    
    x = v';
    y = U_col34(1,:);
    z = U_col34(2,:);
    w = U_col34(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 35\n\n');
    v = Transacao(25,:);
    [center_col35, U_col35, obj_fcn_col35] = fcm(v', 3);
    
    x = v';
    y = U_col35(1,:);
    z = U_col35(2,:);
    w = U_col35(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 36\n\n');
    v = Transacao(26,:);
    [center_col36, U_col36, obj_fcn_col36] = fcm(v', 3);
    
    x = v';
    y = U_col36(1,:);
    z = U_col36(2,:);
    w = U_col36(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 37\n\n');
    v = Transacao(27,:);
    [center_col37, U_col37, obj_fcn_col37] = fcm(v', 3);
    
    x = v';
    y = U_col37(1,:);
    z = U_col37(2,:);
    w = U_col37(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
   
    
    fprintf('\nExecutando para FCM para coluna 38\n\n');
    v = Transacao(28,:);
    [center_col38, U_col38, obj_fcn_col38] = fcm(v', 3);
    
    x = v';
    y = U_col38(1,:);
    z = U_col38(2,:);
    w = U_col38(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 39\n\n');
    v = Transacao(29,:);
    [center_col39, U_col39, obj_fcn_col39] = fcm(v', 3);
    
    x = v';
    y = U_col39(1,:);
    z = U_col39(2,:);
    w = U_col39(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 40\n\n');
    v = Transacao(30,:);
    [center_col40, U_col40, obj_fcn_col40] = fcm(v', 3);
    
    x = v';
    y = U_col40(1,:);
    z = U_col40(2,:);
    w = U_col40(3,:);
    
    figure
    legend('Baixo','Medio','Alto');
    %Plotando gráfico
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    fprintf('\nExecutando para FCM para coluna 41\n\n');
    v = Transacao(31,:);
    [center_col41, U_col41, obj_fcn_col41] = fcm(v', 3);
    
    x = v';
    y = U_col41(1,:);
    z = U_col41(2,:);
    w = U_col41(3,:);

    %Plotando gráfico
    figure
    legend('Baixo','Medio','Alto');
    plot(x,y,'*',x,z,'o',x,w,'+');
    
    
    
%     disp('Gerando arquivos com os graus de pertinência para cada ponto dos dados\n');
%     fprintf('\n Gerando os arquivos com as clusterizações\n');
%     fid = fopen('UTeste1_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col1);
%     fclose(fid);
%     
%     fid = fopen('UTeste5_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col5);
%     fclose(fid);
%     
%     fid = fopen('UTeste6_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col6);
%     fclose(fid);
%     
%     fid = fopen('UTeste8_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col8);
%     fclose(fid);
%     
%     fid = fopen('UTeste9_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col9);
%     fclose(fid);
%     
%     fid = fopen('UTeste10_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col10);
%     fclose(fid);
%     
%     fid = fopen('UTeste11_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col11);
%     fclose(fid);
%     
%     fid = fopen('UTeste13_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col13);
%     fclose(fid);
%     
%     fid = fopen('UTeste16_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col16);
%     fclose(fid);
%     
%     fid = fopen('UTeste17_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col17);
%     fclose(fid);
%     
%     fid = fopen('UTeste18_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col18);
%     fclose(fid);
%     
%     fid = fopen('UTeste19_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col19);
%     fclose(fid);
%     
%     fid = fopen('UTeste23_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col23);
%     fclose(fid);
%     
%     fid = fopen('UTeste24_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col24);
%     fclose(fid);
%     
%     fid = fopen('UTeste25_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col25);
%     fclose(fid);
%     
%     fid = fopen('UTeste26_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col26);
%     fclose(fid);
%     
%     fid = fopen('UTeste27_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col27);
%     fclose(fid);
%     
%     fid = fopen('UTeste28_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col28);
%     fclose(fid);
%     
%     fid = fopen('UTeste29_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col29);
%     fclose(fid);
%     
%     fid = fopen('UTeste30_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col30);
%     fclose(fid);
%     
%     fid = fopen('UTeste31_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col31);
%     fclose(fid);
%     
%     fid = fopen('UTeste32_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col32);
%     fclose(fid);
%     
%     fid = fopen('UTeste33_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col33);
%     fclose(fid);
%     
%     fid = fopen('UTeste34_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col34);
%     fclose(fid);
%     
%     fid = fopen('UTeste35_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col35);
%     fclose(fid);
%     
%     fid = fopen('UTeste36_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col36);
%     fclose(fid);
%     
%     fid = fopen('UTeste37_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col37);
%     fclose(fid);
%     
%     fid = fopen('UTeste38_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col38);
%     fclose(fid);
%     
%     fid = fopen('UTeste39_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col39);
%     fclose(fid);
%     
%     fid = fopen('UTeste40_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col40);
%     fclose(fid);
%     
%     fid = fopen('UTeste41_BD','w');
%     fprintf(fid,'%0.4f %0.4f %0.4f\n',U_col41);
%     fclose(fid);
    
end