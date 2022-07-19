function probabilitate = patrat(N=500)
  %N=numarul de puncte generate
  clf;
  hold on;
  axis square;
  rectangle('Position',[0 0 1 1]);
  
  centru = [0.5, 0.5];
  caz_fav = 0;
  
  for i=1:N
    
    x=rand;
    y=rand;
    
    P = [x, y];
    if pdist([centru;P]) < 0.5
        caz_fav ++;
        plot(x,y,'pr','MarkerSize',7,'MarkerFaceColor','m');
    endif
    
  endfor
  
  probabilitate = caz_fav / N;
end