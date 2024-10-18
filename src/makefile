default: mandelbrotGen

all: clean mandelbrotGen

mandelbrotGen: main.o bitmapLib.o coordinateDivider.o mandelbrot.o memMap.o
	gcc main.o bitmapLib.o coordinateDivider.o mandelbrot.o memMap.o -o mandelbrotGen

main.o: main.c main.h
	gcc -c main.c

bitmapLib.o: bitmapLib.c bitmapLib.h
	gcc -c bitmapLib.c

coordinateDivider.o: coordinateDivider.c coordinateDivider.h
	gcc -c coordinateDivider.c

mandelbrot.o: mandelbrot.c mandelbrot.h
	gcc -c mandelbrot.c

memMap.o: memMap.c memMap.h
	gcc -c memMap.c

clean:
	rm -f *.o mandelbrotGen