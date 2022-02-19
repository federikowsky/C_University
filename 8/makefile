exec: insf_scl.o main.o
	g++ -o exec insf_scl.o main.o

insf_scl.o: insf_scl.c
	g++ -c insf_scl.c

main.o: main.c
	g++ -c main.c

clean:
	rm -rf main.o insf_scl.o exec