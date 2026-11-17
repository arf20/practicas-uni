set terminal svg
set output 'output.svg'

red = "#FF0000"; green = "#00FF00"; blue = "#0000FF";
#set yrange [0:20]
set datafile separator ","
set style data histogram
set style histogram cluster gap 1
set style fill solid
set boxwidth 0.9
#set xtics format "" rotate by 30 offset -8,-2
set grid ytics
set key left top

set title "nbody (ThinkPad X230 @ i5-3210M)"
plot "figuras.csv" using 2:xtic(1) title "clang" linecolor rgb red,   \
     "figuras.csv" using 3 title "gcc" linecolor rgb blue,   \
     "figuras.csv" using 4 title "icc" linecolor rgb green


