CC = gcc
CFLAGS = -std=c99 -fstack-protector-all

siguel: main.c circ.o reta.o retang.o texto.o lista.o fila.o pilha.o geo.o qry.o 
	$(CC) $(CFLAGS) -g -o siguel main.c circ.o reta.o retang.o texto.o lista.o fila.o pilha.o geo.o qry.o -lm

circ.o: formas/circ.c formas/circ.h
	$(CC) $(CFLAGS) -c formas/circ.c

reta.o: formas/reta.c formas/reta.h
	$(CC) $(CFLAGS) -c formas/reta.c

retang.o: formas/retang.c formas/retang.h
	$(CC) $(CFLAGS) -c formas/retang.c

texto.o: formas/texto.c formas/texto.h
	$(CC) $(CFLAGS) -c formas/texto.c

lista.o: lista/lista.c lista/lista.h
	$(CC) $(CFLAGS) -c lista/lista.c 

fila.o: fila/fila.c fila/fila.h
	$(CC) $(CFLAGS) -c fila/fila.c 

pilha.o: pilha/pilha.c pilha/pilha.h
	$(CC) $(CFLAGS) -c pilha/pilha.c

geo.o: geo/geo.c geo/geo.h
	$(CC) $(CFLAGS) -c geo/geo.c

qry.o: qry/qry.c qry/qry.h
	$(CC) $(CFLAGS) -c qry/qry.c

clean:
	rm -r -f *.o
	rm siguel