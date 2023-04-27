function patrat_i(N=500)
  %N=numarul de puncte generate
  clf;
  hold on;
  axis square;
  rectangle('Position',[0 0 1 1]);
  for i=1:N
    x=rand;
    y=rand;
    plot(x,y,'pr','MarkerSize',7,'MarkerFaceColor','m');
  endfor
end