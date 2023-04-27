function X = nr_aleator_exp(lambda, N)
  
  u = rand(1, N);
  X = -1/lambda * log(1 - u);
  