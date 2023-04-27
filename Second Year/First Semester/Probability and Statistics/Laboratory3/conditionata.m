function prob = conditionata(nr_sim = 5000)
  
  prob_una = 0;
  prob_toate = 0;
  urna = ['r', 'r', 'r', 'r', 'r', 'a', 'a', 'a', 'v', 'v'];
  
  for i = 1:nr_sim
    vector = randsample(urna, 3, replacement = false);
    if vector(1) == 'r' || vector(2) == 'r' || vector(3) == 'r'
      prob_una++;
      if vector(1) == vector(2) && vector(1) == vector(3) 
        prob_toate++;
      endif  
    endif
  endfor
  
  prob = prob_toate / prob_una;
  
  end