exec: albero_binario.o lista.o main.o
	g++ -o $@ $^

albero_binario.o: albero_binario.c
	g++ -c albero_binario.c

lista.o: lista.c
	g++ -c lista.c

main.o:	main.c
	g++ -c main.c

clean:
	rm -rf *.o exec