CC = gcc
CFLAGS = -Wall -g -Wextra
PROGRAMS = td2.out tp2.out tdtp3.out td4.out

all : $(PROGRAMS)

td2 : td2.c
	$(CC) $(CFLAGS) td2.c -o td2.out
tp2 : tp2.c
	$(CC) $(CFLAGS) tp2.c -o tp2.out
tdtp3 : tdtp3.c tdtp3.h
	$(CC) $(CFLAGS) tdtp3.c tdtp3.h -o tdtp3.out
td4 : td4.c
	$(CC) $(CFLAGS) td4.c -o td4.out

clean:
	rm -fv $(PROGRAMS)
