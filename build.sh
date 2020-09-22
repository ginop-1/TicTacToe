#!/bin/bash

g++ -std=c++17 -Wall src/*.cpp -o TicTacToe.out &&
echo "press enter to continue" &&
read -u 1 &&
 ./TicTacToe.out

