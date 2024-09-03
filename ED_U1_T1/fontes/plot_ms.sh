gnuplot <<EOF
set terminal png
set output 'grafico_merge.png'
set title 'Merge sort'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "merge.txt" with linespoints linecolor rgb 'blue'
EOF

echo "Gráfico salvo"
