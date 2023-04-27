function valori_rezultate = generare_aleatoare(numar_simulari, valori, probabilitati)
   
   sume = cumsum(probabilitati);
   
   for j = 1 : numar_simulari
      u = rand;
      i = 1;
      while u > sume(i)
        i++;
      endwhile    
      valori_rezultate(j) = valori(i);      
   endfor
   
   