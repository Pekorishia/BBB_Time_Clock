#!/bin/bash

echo "Iniciando o teste time para Shell Sort"
./run.sh time_arm 3
echo "Finalizado"
sleep 3
echo "Iniciando o teste time para Quick Sort"
./run.sh time_arm 2
echo "Finalizado"
sleep 3

echo "Iniciando o teste clock para Shell Sort"
./run.sh clock_arm 3
echo "Finalizado"
sleep 3
echo "Iniciando o teste clock para Quick Sort"
./run.sh clock_arm 2
echo "Finalizado"
sleep 3

echo "Iniciando o teste clock para Bubble Sort"
./run.sh clock_arm 1
sleep 3
echo "Finalizado"

echo "Iniciando o teste time para Bubble Sort"
./run.sh time_arm 1
sleep 3
echo "Finalizado"