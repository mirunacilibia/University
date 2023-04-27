function simulari_deplasari_pe_cerc(nr_simulari, nr_pasi, probabilitate, nr_noduri)
  
  pozitii_finale = zeros(1, nr_simulari);
  
  for i = 1 : nr_simulari
    v = deplasare_punct(nr_pasi, probabilitate);
    pozitii_finale(i) = mod(v(end), nr_noduri); 
  endfor
  
  N=histc(pozitii_finale, 0 : nr_noduri);
  bar(0 : nr_noduri, N / nr_simulari, 'hist', 'FaceColor', 'b');
  set(gca, 'XTick', -nr_noduri : nr_noduri);
  grid on;
  xlim([-1 nr_noduri]);
  
  fprintf('Poz. finale cele mai frecvente: %d.\n', find(N==max(N))-1);

  endfunction