CC = gcc
CFLAGS = -Wall -Wextra -std=c11

valgrind: valgrind --leak-check=yes ./my-grep CC Makefile

all: my-cat my-grep my-zip my-unzip

my-cat: my-cat.c
	$(CC) $(CFLAGS) my-cat.c -o my-cat

my-grep: my-grep.c
	$(CC) $(CFLAGS) my-grep.c -o my-grep

my-zip: my-zip.c
	$(CC) $(CFLAGS) my-zip.c -o my-zip

my-unzip: my-unzip.c
	$(CC) $(CFLAGS) my-unzip.c -o my-unzip

clean:
	rm -f my-cat my-grep my-zip my-unzip
