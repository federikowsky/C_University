exec: main.o albero_binario.o lista.o
	g++ -o exec main.o albero_binario.o lista.o

main.o: main.c
	g++ -c main.c

albero_binario.o: albero_binario.c	
	g++ -c albero_binario.c

lista.o: lista.c
	g++ -c lista.c

clean:
	rm -rf exec main.o albero_binario.o