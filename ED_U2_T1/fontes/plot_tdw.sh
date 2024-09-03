gnuplot <<EOF
set terminal png
set output 'grafico_td_worst.png'
set title 'Tabela de dispersão - Pior caso'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "tabela_dispersao_worst.txt" with linespoints linecolor rgb 'red'
EOF

echo "Gráfico salvo"