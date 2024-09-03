gnuplot <<EOF
set terminal png
set output 'grafico_worst_all.png'
set title 'Piores casos comparartivo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "selection.txt" with linespoints linecolor rgb 'blue' title 'Selection', \
    "insertion_worst.txt" with linespoints linecolor rgb 'purple' title 'Insertion', \
    "merge.txt" with linespoints linecolor rgb 'green' title 'Merge', \
    "quick_worst.txt" with linespoints linecolor rgb 'yellow' title 'Quick', \
    "distribution_maior_k.txt" with linespoints linecolor rgb 'red' title 'Distribution'
EOF

echo "Gráfico salvo"
