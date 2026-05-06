CC = gcc
FLAGS = -Wall -g

run: clean build

build:
	$(CC) forkEx.c -o forkEx
	$(CC) app1.c -o app1
	$(CC) app2.c -o app2
	$(CC) Test.c -o test
	$(CC) $(FLAGS) -o pipe mypipe.c

test:clean build
	./test
	
pipe: clean build
	./pipe

clean:
	rm -f *.o *.out pipe test forkEX app1 app2