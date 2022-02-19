exec: main.o lista.o
	g++ -o exec lista.o main.o

main.o: main.c
	g++ -c main.c

lista.o: lista.c
	g++ -c lista.c

clean:
	rm -rf lista.o main.o exec