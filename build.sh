#!/bin/bash

mkdir -p build && cd build

cmake ..

cmake --build . --config Debug --

./poly2
