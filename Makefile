CC=gcc
CFLAGS=-Wall -lX11 -g -lm
VPATH=./src

WM_OBJS= atoms.o events.o tree.o commands.o responses.o util.o window.o lookup.o foo-wm.o
CLI_OBJS= client.o

all: foo-wm foo-wm-c

src/config.h:
	cp src/config.def.h src/config.h

foo-wm: src/config.h $(WM_OBJS)
	$(CC) $(CFLAGS) $(WM_OBJS) -o foo-wm

foo-wm-c: $(CLI_OBJS)
	$(CC) $(CFLAGS) $(CLI_OBJS) -o foo-wm-c

clean:
	rm -rf foo-wm foo-wm-c *.o
