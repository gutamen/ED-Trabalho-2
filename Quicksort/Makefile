
run: quick
	./quick
	make clean

quick: quicksort.o quickf.o
	gcc quicksort.o quickf.o -o quick

quicksort.o: quicksort.c
	gcc -c quicksort.c

quickf.o: quickf.c quickf.h
	gcc -c quickf.c	

clean:
	rm *.o quick