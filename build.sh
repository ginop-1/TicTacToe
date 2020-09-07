#!/bin/bash

{ 

	g++ tris.cpp -o tris
	./tris
} || {
	echo 'problem while executing the command, maybe missing dependencies?'
}
