main = main_f

ifeq ($(main),main_f)
exec: funzioni.o main_f.o 
	g++ -o exec main_f.o funzioni.o
endif 

ifeq ($(main),main_s)
exec: funzioni.o main_s.o 
	g++ -o exec main_s.o funzioni.o
endif 

funzioni.o: funzioni.c
	g++ -c funzioni.c

main_f.o: main_f.c
	g++ -c main_f.c

main_s.o: main_s.c
	g++ -c main_s.c

clean:
	rm main_f.o main_s.o funzioni.o exec