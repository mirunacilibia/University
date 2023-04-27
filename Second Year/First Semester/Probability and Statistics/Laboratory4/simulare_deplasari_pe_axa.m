function simulari_deplasari_pe_axa(nr_simulari, nr_pasi, probabilitate)
  
  pozitii_finale = zeros(1, nr_simulari);
  nr_pasi_dreapta = zeros(1, nr_simulari); 
  
  for i = 1 : nr_simulari
    [v, contor] = deplasare_punct(nr_pasi, probabilitate);
    pozitii_finale(i) = v(end); 
    nr_pasi_dreapta(i) = contor; 
  endfor
  
  N=histc(pozitii_finale, -nr_pasi : nr_pasi);
  bar(-nr_pasi : nr_pasi, N / nr_simulari, 'hist', 'FaceColor', 'b');
  set(gca, 'XTick', -nr_pasi : nr_pasi);
  grid on;
  xlim([-nr_pasi-1 nr_pasi+1]);
  
  fprintf('Poz. finale cele mai frecvente: %d.\n', find(N==max(N))-nr_pasi-1);
  fprintf('Media nr de pasi la dreapta este %f.\n', mean(nr_pasi_dreapta));
  
  pozitii_finale
  endfunction