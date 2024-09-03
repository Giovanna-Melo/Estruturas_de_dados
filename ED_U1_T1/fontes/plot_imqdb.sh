gnuplot <<EOF
set terminal png
set output 'grafico_best_imqd.png'
set title 'Melhores casos comparartivo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "insertion_best.txt" with linespoints linecolor rgb 'purple' title 'Insertion', \
    "merge.txt" with linespoints linecolor rgb 'green' title 'Merge', \
    "quick_best.txt" with linespoints linecolor rgb 'yellow' title 'Quick', \
    "distribution_menor_k.txt" with linespoints linecolor rgb 'red' title 'Distribution'
EOF

echo "Gráfico salvo"
