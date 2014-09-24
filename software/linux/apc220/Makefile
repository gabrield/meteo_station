CC=gcc
CFLAGS=-c -Wall -std=gnu99  -Iinclude/ -I../libxively/src/libxively/

LDFLAGS=
#SOURCES=apc220_reader.c serial_lib.c
SOURCES=meteo_feeder.c serial_lib.c
OBJECTS=$(SOURCES:.c=.o)
#EXECUTABLE=apc220_reader
EXECUTABLE=meteo_feeder

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) ../libxively/obj/libxively.a -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm $(OBJECTS)
