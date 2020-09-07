#!/bin/bash

if g++ -Wall tris.cpp -o tris; then
  ./tris
else
  echo "something went wrong, i can feel it "
fi
