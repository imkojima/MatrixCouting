all: cmatrix
CC = clang
CC+ = clang++
CFLAGS = -g -Wall

qdbmp.o: lib/qdbmp.c lib/qdbmp.h
	$(CC) -c lib/qdbmp.c

bitmap.o: lib/bitmap.cpp lib/bitmap.h
	$(CC+) -c lib/bitmap.cpp

main.o: main.cpp
	$(CC+) -c main.cpp

cmatrix: main.o bitmap.o qdbmp.o
	$(CC+) main.o qdbmp.o bitmap.o -o cmatrix

clean:
	rm main.o bitmap.o qdbmp.o cmatrix
