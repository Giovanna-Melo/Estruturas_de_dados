gnuplot <<EOF
set terminal png
set output 'grafico_td_average.png'
set title 'Tabela de dispersão - Caso esperado'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "tabela_dispersao_average.txt" with linespoints linecolor rgb 'yellow'
EOF

echo "Gráfico salvo"