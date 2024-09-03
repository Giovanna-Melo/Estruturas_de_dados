gnuplot <<EOF
set terminal png
set output 'grafico_distribution_menor_k.png'
set title 'Distribution sort - Menor k'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "distribution_menor_k.txt" with linespoints linecolor rgb 'green'
EOF

echo "Gráfico salvo"
