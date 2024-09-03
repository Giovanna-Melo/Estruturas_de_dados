gnuplot <<EOF
set terminal png
set output 'grafico_quick_best.png'
set title 'Quick sort - Melhor caso'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "quick_best.txt" with linespoints linecolor rgb 'green'
EOF

echo "Gráfico salvo"