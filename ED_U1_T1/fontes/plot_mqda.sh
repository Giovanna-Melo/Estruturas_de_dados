gnuplot <<EOF
set terminal png
set output 'grafico_average_mqd.png'
set title 'Casos esperados comparartivo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "merge.txt" with linespoints linecolor rgb 'green' title 'Merge', \
    "quick_average.txt" with linespoints linecolor rgb 'yellow' title 'Quick', \
    "distribution_average.txt" with linespoints linecolor rgb 'red' title 'Distribution'
EOF

echo "Gráfico salvo"
