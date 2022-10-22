CC=gcc 
 
CFLAGS=-c -Wall -fPIC
 
SOURCES=library_iterative.c 
OBJECTS=$(SOURCES:.c=.o)
 
.c.o:
	$(CC) $(CFLAGS) $< -o $@ 
 
lib: $(OBJECTS)
	$(CC) -shared -fPIC -o lib.so $(OBJECTS)
 
clean:
	rm *.o *.so
