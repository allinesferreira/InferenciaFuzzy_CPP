data = [0;0;0;10;100;200]
       [center,U,obj_fcn] = fcm(data,3);
       plot(data(:,1), 'o');
      hold on;
      maxU = max(U);
      % Find the data points with highest grade of membership in cluster 1
      index1 = find(U(1,:) == maxU);
      % Find the data points with highest grade of membership in cluster 2
      index2 = find(U(2,:) == maxU);
      % Find the data points with highest grade of membership in cluster 3
      index3 = find(U(3,:) == maxU);
      line(data(index1,1),data(index1,2),'marker','*','color','g');
      line(data(index2,1),data(index2,2),'marker','*','color','b');
      line(data(index3,1),data(index3,2),'marker','*','color','r');
      % Plot the cluster centers
      plot(center(1,1),'*','color','k')
      hold off;