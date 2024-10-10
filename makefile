CC = gcc
CFLAGS = -Wall -g
OBJ = main.o menu/menu.o datasources/datasource.o utils/bubble_sort.o

all: agenda

agenda: $(OBJ)
	$(CC) $(CFLAGS) -o agenda $(OBJ)

main.o: main.c menu/menu.h datasources/datasource.h entities/entitie.h
	$(CC) $(CFLAGS) -c main.c

menu/menu.o: menu/menu.c menu/menu.h entities/entitie.h
	$(CC) $(CFLAGS) -c menu/menu.c -o menu/menu.o

datasources/datasources.o: datasources/datasource.c datasources/datasource.h entities/entitie.h
	$(CC) $(CFLAGS) -c datasources/datasource.c -o datasources/datasource.o

utils/bubble_sort.o: utils/bubble_sort.c utils/bubble_sort.h entities/entitie.h
	$(CC) $(CFLAGS) -c utils/bubble_sort.c -o utils/bubble_sort.o

clean:
	rm -f *.o agenda
