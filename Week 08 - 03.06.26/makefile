CC = gcc
FLAGS = -Wall -g

run: clean build
	./shell

build:
	$(CC) shell.c -o shell
	
leak:
	valgrind --leak-check=full ./shell

clean:
	rm -f *.o *.out shell