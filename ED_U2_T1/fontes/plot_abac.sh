gnuplot <<EOF
set terminal png
set output 'grafico_ab_all.png'
set title 'Árvore binária comparativo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "arvore_binaria_average.txt" with linespoints linecolor rgb 'yellow' title 'Caso esperado', \
    "arvore_binaria_worst.txt" with linespoints linecolor rgb 'red' title 'Pior caso', 

EOF

echo "Gráfico salvo"
