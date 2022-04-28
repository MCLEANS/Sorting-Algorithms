CC = gcc
CFLAGS = -Wall -c 
LFLAGS = -Wall 
OBJS = main.o 

all : $(OBJS)	
	$(CC) $(LFLAGS) $(OBJS) -o main

main.o : main.c
	$(CC) $(CFLAGS) main.c 

run : 
	./main 

clean :
	rm -r main *.o 