gnuplot <<EOF
set terminal png
set output 'grafico_quick_average.png'
set title 'Quick sort - Caso esperado'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "quick_average.txt" with linespoints linecolor rgb 'yellow'
EOF

echo "Gráfico salvo"