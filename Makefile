CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99 -g
CC = gcc $(CFLAGS)


.PHONY		: all
	all	:	sorting

sorting	:	sorting.o
	$(CC) sorting.o -o sorting

sorting.o		:	sorting.c	minSort.c	bubbleSort.c insertionSort.c quickSort.c mergeSort.c
	$(CC) -c sorting.c

.PHONY		:	clean
clean	:
	rm -f sorting sorting.o
