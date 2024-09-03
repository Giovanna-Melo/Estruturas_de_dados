gnuplot <<EOF
set terminal png
set output 'grafico_td_all.png'
set title 'Tabela de dispersão comparativo'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
set key inside
set key top
plot "tabela_dispersao_average.txt" with linespoints linecolor rgb 'yellow' title 'Caso esperado', \
    "tabela_dispersao_worst.txt" with linespoints linecolor rgb 'red' title 'Pior caso'
EOF

echo "Gráfico salvo"
