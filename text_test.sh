#!/bin/sh
make -C wgl
clang -g -std=c++17 -lstdc++ -o test text_test.cpp -I include -I wgl/include -Lwgl -lwgl -lglfw -lGL -lGLEW -lm -ldl -lXrandr -lXi -lX11 -lXxf86vm -lpthread
./test