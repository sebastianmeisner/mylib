CC = gcc
CFLAGS = -O3 -g -Wall -msse4.2


APP_OBJS = 




LIBPATH = 
INCLUDEPATH = 
LDFLAGS = 

.PHONY: clean

all: popcnt
 
popcnt: #$(APP_OBJS)
	$(CC) $(APP_OBJS) $(CFLAGS) $(LIBPATH) $(INCLUDEPATH) popcnt.c -o popcnt $(LDFLAGS)

clean:
	rm -f *.o popcnt 

install:
	true

#%.o: %.c
#	$(CC) -c $(CFLAGS) $(LIBPATH) $(INCLUDEPATH) -o $@ $<
	
