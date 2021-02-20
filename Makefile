all: main.c
	gcc -Wall -Werror -o main main.c

clean: 
	$(RM) main
