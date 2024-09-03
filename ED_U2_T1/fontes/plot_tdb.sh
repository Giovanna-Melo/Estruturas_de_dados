gnuplot <<EOF
set terminal png
set output 'grafico_td_best.png'
set title 'Tabela de dispersão - Melhor caso'
set xlabel 'Tamanho (n)'
set ylabel 'Tempo (ns)'
plot "tabela_dispersao_best.txt" with linespoints linecolor rgb 'green'
EOF

echo "Gráfico salvo"