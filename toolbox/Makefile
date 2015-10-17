CC = gcc
CFLAGS =

objects = \
	exists.o \
	umount.o \
	clear.o \
	stop.o \
	start.o \
	df.o \
	dmesg.o \
	toolbox.o

all: toolbox

toolbox: $(objects) tools.h
	$(CC) $(objects) -o toolbox

$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf toolbox $(objects)
