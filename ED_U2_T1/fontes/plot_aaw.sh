gnuplot <<EOF
set terminal png
set output 'grafico_worst_all.png'
set title 'Piores casos comparativo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "arvore_binaria_worst.txt" with linespoints linecolor rgb 'purple' title 'Árvore binária', \
    "avl_worst.txt" with linespoints linecolor rgb 'blue' title 'Árvore AVL', \
    "tabela_dispersao_worst.txt" with linespoints linecolor rgb 'yellow' title 'Tabela de dispersão'
EOF

echo "Gráfico salvo"
