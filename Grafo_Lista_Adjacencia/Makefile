
output: teste_graf.o Grafo.o Lista_SE.o Grafo_iterativo.o
	gcc teste_graf.o Grafo.o Lista_SE.o -std=c11 -o output -w ; ./output >> teste.txt ; gcc Grafo_iterativo.o Grafo.o Lista_SE.o -std=c11 -o MenuIteracao.x -w

teste_graf.o: teste_graf.c
	gcc -c teste_graf.c -w

Lista_SE.o: Lista_SE.c Lista_SE.h
	gcc -c Lista_SE.c -w

Grafo.o: Grafo.c Grafo.h
	gcc -c Grafo.c -w

Grafo_iterativo.o: Grafo_iterativo.c
	gcc -c Grafo_iterativo.c -w	

clean:
	rm *.o output ; rm teste.txt ; rm MenuIteracao.x

target: dependencies
	action