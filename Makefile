CC = gcc
CFLAGS = -Wall -g -Wextra
PROGRAMS = td2 tp2 tdtp3

all : $(PROGRAMS)

td2 : td2.c
	$(CC) $(CFLAGS) td2.c -o td2
tp2 : tp2.c
	$(CC) $(CFLAGS) tp2.c -o tp2
tdtp3 : tdtp3.c tdtp3.h
	$(CC) $(CFLAGS) tdtp3.c tdtp3.h -o tdtp3

clean:
	rm -fv $(PROGRAMS)
