gnuplot <<EOF
set terminal png
set output 'grafico_insertion_best.png'
set title 'Insertion sort - Melhor caso'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "insertion_best.txt" with linespoints linecolor rgb 'green'
EOF

echo "Gráfico salvo"