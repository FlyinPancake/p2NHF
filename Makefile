OBJS	= vonat.o kocsi.o main.o palya.o
SOURCE	= vonat.cpp kocsi.cpp main.cpp palya.cpp
HEADER	= vonat.hpp allomas.hpp palya.hpp jegy.hpp
OUT	= vonat
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

vonat.o: vonat.cpp
	$(CC) $(FLAGS) vonat.cpp 

kocsi.o: kocsi.cpp
	$(CC) $(FLAGS) kocsi.cpp 

palya.o: palya.cpp
	$(CC) $(FLAGS) palya.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

cnall: clean all


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)