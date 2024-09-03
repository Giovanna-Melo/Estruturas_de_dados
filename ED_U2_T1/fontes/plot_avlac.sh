gnuplot <<EOF
set terminal png
set output 'grafico_avl_all.png'
set title 'Árvore AVL comparativo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "avl_average.txt" with linespoints linecolor rgb 'yellow' title 'Caso esperado', \
    "avl_worst.txt" with linespoints linecolor rgb 'red' title 'Pior caso'
EOF

echo "Gráfico salvo"
