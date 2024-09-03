gnuplot <<EOF
set terminal png
set output 'grafico_avl_average.png'
set title 'Árvore AVL - Caso esperado'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "avl_average.txt" with linespoints linecolor rgb 'yellow'
EOF

echo "Gráfico salvo"