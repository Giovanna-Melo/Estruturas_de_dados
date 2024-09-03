gnuplot <<EOF
set terminal png
set output 'grafico_insertion_worst.png'
set title 'Insertion sort - Pior caso'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "insertion_worst.txt" with linespoints linecolor rgb 'red'
EOF

echo "Gráfico salvo"