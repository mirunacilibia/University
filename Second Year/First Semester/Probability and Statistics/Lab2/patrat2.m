function probabilitate = patrat2(N=500)
  %N=numarul de puncte generate
  clf;
  hold on;
  axis square;
  rectangle('Position',[0 0 1 1]);
  
  A = [0, 0];
  B = [1, 0];
  C = [0, 1];
  D = [1, 1];
  
  centru = [0.5, 0.5];
  caz_fav = 0;
  
  for i=1:N
    
    x=rand;
    y=rand;
    
    P = [x, y];
    
    distPA = pdist([A, P]);
    distPB = pdist([B, P]);
    distPC = pdist([C, P]);
    distPD = pdist([D, P]);
    distPO = pdist([centru, P]);
    
    if (distPO < distPA && distPO < distPB...
      && distPO < distPC && distPO < distPD)
        caz_fav ++;
        plot(x,y,'pr','MarkerSize',7,'MarkerFaceColor','m');
    endif
    
  endfor
  
  probabilitate = caz_fav / N;
end