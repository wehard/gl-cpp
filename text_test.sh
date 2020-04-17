#!/bin/sh
make -C engine
clang -g -std=c++17 -lstdc++ -o test text_test.cpp -I include -I engine/include -Lengine -lwengine -lglfw -lGL -lGLEW -lm -ldl -lXrandr -lXi -lX11 -lXxf86vm -lpthread
./test