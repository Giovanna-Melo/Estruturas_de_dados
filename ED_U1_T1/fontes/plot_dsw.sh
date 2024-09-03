gnuplot <<EOF
set terminal png
set output 'grafico_distribution_maior_k.png'
set title 'Distribution sort - Maior k'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "distribution_maior_k.txt" with linespoints linecolor rgb 'red'
EOF

echo "Gráfico salvo"
