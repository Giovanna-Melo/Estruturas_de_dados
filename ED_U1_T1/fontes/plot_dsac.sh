gnuplot <<EOF
set terminal png
set output 'grafico_distribution_all.png'
set title 'Distribution sort comparartivo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "distribution_menor_k.txt" with linespoints linecolor rgb 'green' title 'Menor k', \
    "distribution_average.txt" with linespoints linecolor rgb 'yellow' title 'Caso esperado', \
    "distribution_maior_k.txt" with linespoints linecolor rgb 'red' title 'Maior k'
EOF

echo "Gráfico salvo"
