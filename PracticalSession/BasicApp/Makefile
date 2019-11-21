CC=gcc
C2=g++
CFLAGS=-Wall -Wextra -Wno-unused -pedantic -O3

normalization: imageTransform.cpp iio.o
	$(C2) $(CFLAGS) -o imageTransform imageTransform.cpp iio.o  -lpng -ljpeg -ltiff

iio.o: iio.c
	$(CC) -std=c99 $(CFLAGS) -DNDEBUG -D_GNU_SOURCE -c iio.c

clean:
	rm -f imageTransform iio.o
