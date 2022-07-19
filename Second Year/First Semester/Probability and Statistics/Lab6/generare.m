% normrnd - pt a genera ne aleatoare
% conform distribuitei normale

% m = val medie
% s - sigma, deviatia standard
% l = nr de linii
% c = nr de coloane

clf;hold on;

nr_bare = 10;
x = normrnd(165, 10, 1, 1000);
[nn, xx] = hist(x, nr_bare);
hist(x, xx, nr_bare / (max(x) - min(x)))

diviziune = linspace(min(x), max(x), 1000);
val = normpdf(diviziune, 165, 10);

plot(diviziune, val, '-r', 'linewidth', 3)