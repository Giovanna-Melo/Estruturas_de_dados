gnuplot <<EOF
set terminal png
set output 'grafico_avl_worst.png'
set title 'Árvore AVL - Pior caso'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "avl_worst.txt" with linespoints linecolor rgb 'red'
EOF

echo "Gráfico salvo"