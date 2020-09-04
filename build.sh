#!/bin/bash

{ 

	g++ tris.cpp -o tris >> log.txt &&
	./tris
} || {

	echo 'problem while executing the command, check log for help'
}
