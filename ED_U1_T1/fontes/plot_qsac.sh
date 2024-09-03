gnuplot <<EOF
set terminal png
set output 'grafico_quick_all.png'
set title 'Quick sort comparartivo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "quick_best.txt" with linespoints linecolor rgb 'green' title 'Melhor caso', \
    "quick_average.txt" with linespoints linecolor rgb 'yellow' title 'Caso esperado', \
    "quick_worst.txt" with linespoints linecolor rgb 'red' title 'Pior caso'
EOF

echo "Gráfico salvo"
