run: list
	./list
	
list: list.c
	gcc -Wall -std=c11 list.c -o list

build: list
