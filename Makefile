run: lin
	./lin

lin: lin.c
	gcc -Wall -std=c11 lin.c -o lin

build: lin
