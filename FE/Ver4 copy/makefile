
.PHONY: clean

CC = gcc
RM = rm -f

main : main.o draw.o err.o onfail.o ongame.o onhelp.o onstart.o onsuccess.o
	$(CC) -o main main.o draw.o err.o onfail.o ongame.o onhelp.o onstart.o onsuccess.o -lncursesw

main.o : main.c gamelib.h
	$(CC) -c main.c

draw.o : draw.c drawlib.h
	$(CC) -c draw.c

err.o : err.c errlib.h
	$(CC) -c err.c

onfail.o : onfail.c drawlib.h draw.o
	$(CC) -c onfail.c

ongame.o : ongame.c drawlib.h draw.o
	$(CC) -c ongame.c

onhelp.o : onhelp.c drawlib.h draw.o
	$(CC) -c onhelp.c

onstart.o : onstart.c drawlib.h draw.o
	$(CC) -c onstart.c

onsuccess.o : onsuccess.c drawlib.h draw.o
	$(CC) -c onsuccess.c



drawlib.h : gamelib.h

clean:
	$(RM) *.o
