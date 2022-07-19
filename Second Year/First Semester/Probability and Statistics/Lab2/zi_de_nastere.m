function out = zi_de_nastere(nr_simulari)
  
  suprapuneri = 0;
  
  for i=1:nr_simulari
    birthdays = unique(randi(366, 1, 50));
    if length(birthdays) < 23
      suprapuneri = suprapuneri + 1;
    endif
  endfor
  
  out = suprapuneri/nr_simulari;
  
  end