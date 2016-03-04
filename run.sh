#!/bin/bash
# -- Parametro 1: arquivo a ser executado medido em time
# -- Parametro 2: algoritmo a ser executado: 1 BS, 2 QS, 3 SS
tamanho=5000
mkdir -p "saidas"

if [ -f saidas/"$1_$2".txt ]; then
	rm saidas/"$1_$2".txt
fi

echo "Teste $1 $2 entradas algoritmo $3" >> saidas/"$1_$2".txt
until [ $tamanho = "505000" ];
do
	"./$1" $tamanho $2 >> saidas/"$1_$2".txt
	#echo $tamanho
	((tamanho+=5000))
done