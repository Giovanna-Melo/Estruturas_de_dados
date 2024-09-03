gnuplot <<EOF
set terminal png
set output 'grafico_ab_average.png'
set title 'Árvore binária - Caso esperado'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "arvore_binaria_average.txt" with linespoints linecolor rgb 'yellow'
EOF

echo "Gráfico salvo"