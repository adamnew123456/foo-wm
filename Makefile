CC=gcc
CFLAGS=-Wall -lX11 -g
VPATH=./src

all:fifo-wm
fifo-wm: events.o tree.o commands.o util.o window.o client.o

clean:
	rm -rf fifo-wm *.o