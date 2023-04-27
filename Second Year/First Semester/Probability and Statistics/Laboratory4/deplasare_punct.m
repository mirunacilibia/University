function [pozitii, contor] = deplasare_punct(nr_pasi, p) 
  
  pozitii = zeros(1, nr_pasi + 1);
  
  numar = 0;
  contor = 0;
  
  for i = 1:nr_pasi
##    numar = binornd(1, p);
##    if numar == 0
##        pozitii(i + 1) = pozitii(i) - 1;
##    else
##        pozitii(i + 1) = pozitii(i) + 1; 
##    endif
    numar = rand();
    if numar > p
        pozitii(i + 1) = pozitii(i) - 1;
        contor++;
    else
        pozitii(i + 1) = pozitii(i) + 1; 
    endif
  endfor
endfunction