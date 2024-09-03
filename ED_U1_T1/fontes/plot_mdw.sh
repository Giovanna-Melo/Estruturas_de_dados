gnuplot <<EOF
set terminal png
set output 'grafico_worst_md.png'
set title 'Piores casos comparartivo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "merge.txt" with linespoints linecolor rgb 'green' title 'Merge', \
    "distribution_maior_k.txt" with linespoints linecolor rgb 'red' title 'Distribution'
EOF

echo "Gráfico salvo"
