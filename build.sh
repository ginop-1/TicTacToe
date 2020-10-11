#!/bin/bash

g++ -std=c++17 -Wall src/*.cpp -o exec.out &&
echo "press enter to continue" &&
read -u 1 &&
 ./exec.out

