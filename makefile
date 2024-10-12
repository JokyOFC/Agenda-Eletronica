CC = gcc
CFLAGS = -Wall -g
OBJ = main.o menu/menu.o datasources/datasource.o utils/bubble_sort.o utils/clearScreen.o

SRC_DIRS = menu dependencies utils datasources entities
SRC_FILES = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)) main.c)
HEADER_FILES = $(wildcard $(addsuffix /*.h, $(SRC_DIRS)) include/*.h)

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

utils/clearScreen.o: utils/clearScreen.c utils/clearScreen.h
	$(CC) $(CFLAGS) -c utils/clearScreen.c -o utils/clearScreen.o

clean:
	rm -f *.o agenda

install-dev-dependencies:
	sudo apt-get install cppcheck clang-format

lint:
	cppcheck --enable=all $(SRC_FILES)

format:
	clang-format -i $(SRC_FILES) $(HEADER_FILES)
