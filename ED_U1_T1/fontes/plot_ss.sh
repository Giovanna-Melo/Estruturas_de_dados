gnuplot <<EOF
set terminal png
set output 'grafico_selection.png'
set title 'Selection sort'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "selection.txt" with linespoints linecolor rgb 'blue'
EOF

echo "Gráfico salvo"