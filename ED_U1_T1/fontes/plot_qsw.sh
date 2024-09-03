gnuplot <<EOF
set terminal png
set output 'grafico_quick_worst.png'
set title 'Quick sort - Pior caso'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "quick_worst.txt" with linespoints linecolor rgb 'red'
EOF

echo "Gráfico salvo"