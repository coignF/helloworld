PREFIX=${HOME}
DEBUG_FLAGS=-Wall -Wextra -g
CC=gcc
CCFLAGS=
ifeq (${DEBUG},1)
   CCFLAGS=${DEBUG_FLAGS}
endif

.PHONY: all
all : helloworld

.PHONY: install
install: all
	mkdir -pv ${PREFIX}/bin
	install -v -m 755 helloworld ${PREFIX}/bin

.PHONY: clean
clean:
	rm -rfv helloworld
	rm -rfv a.out *.o *~ 

helloworld : helloworld.o 
	 ${CC} -o helloworld helloworld.o 
helloworld.o : helloworld.c
	 ${CC} ${CCFLAGS} -c helloworld.c

