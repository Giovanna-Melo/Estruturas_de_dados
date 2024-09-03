gnuplot <<EOF
set terminal png
set output 'grafico_distribution_average.png'
set title 'Distribution sort - Caso esperado'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "distribution_average.txt" with linespoints linecolor rgb 'yellow'
EOF

echo "Gráfico salvo"