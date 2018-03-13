PROGRAM = main
CC      = gcc
CFLAGS  = -g -Wall -I/usr/X11R6/include -I/usr/pkg/include -I/usr/include/FTGL -I/usr/include/freetype2
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglfw -lglut -lGLU -lGL -lm -lftgl

$(PROGRAM): main.o camera.o keyboard.o room.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) $^ $(LDLIBS)
	
main.o: sources/main.c
	$(CC) $(CFLAGS) -c sources/main.c $(LDLIBS)

room.o: sources/room.c headers/room.h
	$(CC) $(CFLAGS) -c sources/room.c $(LDLIBS)
	
keyboard.o: sources/keyboard.c headers/keyboard.h headers/camera.h
	$(CC) $(CFLAGS) -c sources/keyboard.c $(LDLIBS)

camera.o: sources/camera.c headers/camera.h
	$(CC) $(CFLAGS) -c sources/camera.c $(LDLIBS)

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)
