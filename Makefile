CFLAGS = -std=gnu17 -Wall -O0 -pipe -fno-plt -fPIC

default: kth_largest

kth_largest.o: kth_largest.c
	$(CC) $(CFLAGS) -c kth_largest.c -o kth_largest.o

kth_largest: kth_largest.o
	$(CC) $(CFLAGS) kth_largest.o -o kth_largest

.PHONY: clean
clean:
	rm -f kth_largest
	rm -f kth_largest.o
