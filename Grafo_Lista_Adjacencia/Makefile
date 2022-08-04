
output: teste_graf.o Grafo.o Lista_SE.o
	gcc teste_graf.o Grafo.o Lista_SE.o -o output -w

teste_graf.o: teste_graf.c
	gcc -c teste_graf.c -w

Lista_SE.o: Lista_SE.c Lista_SE.h
	gcc -c Lista_SE.c -w

Grafo.o: Grafo.c Grafo.h
	gcc -c Grafo.c -w

clean:
	rm *.o output

target: dependencies
	action