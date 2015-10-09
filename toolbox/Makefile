objects = toolbox.o exists.o

all: toolbox

toolbox: $(objects)
	gcc $(objects) -o toolbox

toolbox.o: toolbox.c tools.h
	gcc -c toolbox.c

exists.o : exists.c
	gcc -c exists.c

.PHONY: clean
clean:
	rm -rf toolbox $(objects)
