gnuplot <<EOF
set terminal png
set output 'grafico_ab_worst.png'
set title 'Árvore binária - Pior caso'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "arvore_binaria_worst.txt" with linespoints linecolor rgb 'red'
EOF

echo "Gráfico salvo"
