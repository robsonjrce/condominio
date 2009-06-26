CC=+g++
CPPFLAGS=-lglut
EXEC=condominio

all:
	$(CC) $(CPPFLAGS) -c predio.cpp codigo.cpp
	$(CC) $(CPPFLAGS) -o $(EXEC) predio.o codigo.o main.cpp
	
exec:
	$(CC) $(CPPFLAGS) -c predio.cpp codigo.cpp
	$(CC) $(CPPFLAGS) -o $(EXEC) predio.o codigo.o main.cpp
	./$(EXEC)

clean:
	rm -f *~
	rm -f *.o
	rm -f $(EXEC)
