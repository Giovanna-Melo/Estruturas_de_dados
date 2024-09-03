gnuplot <<EOF
set terminal png
set output 'grafico_insertion_all.png'
set title 'Insertion sort comparartivo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "insertion_best.txt" with linespoints linecolor rgb 'green' title 'Melhor caso', \
    "insertion_average.txt" with linespoints linecolor rgb 'yellow' title 'Caso esperado', \
    "insertion_worst.txt" with linespoints linecolor rgb 'red' title 'Pior caso'
EOF

echo "Gráfico salvo"
