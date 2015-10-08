all: toolbox

toolbox: toolbox.o exists.o
	gcc toolbox.o exists.o -o toolbox

toolbox.o: toolbox.c
	gcc -c toolbox.c -o toolbox.o

exists.o : exists.c
	gcc -c exists.c -o exists.o

clean:
	rm -rf toolbox *.out *.dSYM *.o
