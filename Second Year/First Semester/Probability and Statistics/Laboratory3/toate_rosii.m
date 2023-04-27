function prob = toate_rosii(nr_sim = 5000)
  
  prob = 0;
  urna = ['r', 'r', 'r', 'r', 'r', 'a', 'a', 'a', 'v', 'v'];
  
  for i = 1:nr_sim
    vector = randsample(urna, 3, replacement = false);
    if vector(1) == 'r' && vector(2) == 'r' && vector(3) == 'r'
      prob++;
    endif
  endfor
  
  prob = prob / nr_sim;
  
  end