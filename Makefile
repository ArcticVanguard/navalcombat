CC  = gcc
SRC = navalcombat.c
OBJ = ${SRC:.c=.o}

navalcombat: ${OBJ}
	$(CC) -o ${OBJ}
