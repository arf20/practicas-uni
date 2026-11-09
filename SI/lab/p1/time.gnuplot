set datafile separator ','
set ylabel "N Reinas"
set xlabel 'Time (s)'
plot "time.csv" using 1:2 with lines
