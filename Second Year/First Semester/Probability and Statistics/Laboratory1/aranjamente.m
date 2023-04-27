function A = aranjamente(v, k)
  C = nchoosek(v, k);
  A = [];
  for i = 1 : size(v, k)
      B = perms(C(i, :));
      A = [A; B];
  endfor
  
end
