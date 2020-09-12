#!/bin/bash

if [ ! -d "output/" ] 
then
	mkdir output
fi
g++ src/*.cpp -Wall -Weffc++ -Wextra -Wsign-conversion -o output/tris
