CC = gcc
OBJS = Countries.o HashTable.o LinkedList.o keyValuePair.o main.o
EXEC = Atlas
DEBUG_FLAG = -g
COMP_FLAG = -c
CLEAN = clean
$(EXEC):$(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@
LinkedList.o:LinkedList.c LinkedList.h Defs.h
	$(CC) $(COMP_FLAG) $*.c
keyValuePair.o:keyValuePair.c keyValuePair.h Defs.h
	$(CC) $(COMP_FLAG) $*.c
HashTable.o:HashTable.c HashTable.h keyValuePair.h LinkedList.h Defs.h
	$(CC) $(COMP_FLAG) $*.c
Countries.o:Countries.c Countries.h Defs.h
	$(CC) $(COMP_FLAG) $*.c
main.o:main.c Countries.h HashTable.h Defs.h
	$(CC) $(COMP_FLAG) $*.c
clean:
	rm -f $(OBJS) $(EXEC)
