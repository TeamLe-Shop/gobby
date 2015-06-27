CC=clang
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/*c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=gobby

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

