gnuplot <<EOF
set terminal png
set output 'grafico_insertion_average.png'
set title 'Insertion sort - Caso esperado'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "insertion_average.txt" with linespoints linecolor rgb 'yellow'
EOF

echo "Gráfico salvo"