APP_NAME = chessviz
CC = gcc
CFLAGS = -Wall -Werror
OBJ = main.o

all: $(OBJ)
	$(CC) $^ -o $(APP_NAME)

main.o: main.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean: 
	$(RM) $(OBJ) $(APP_NAME)

.clang-format:
	wget -O $@ -c "https://csc-software-development.readthedocs.io/ru/2021/_static/.clang-format"

format: .clang-format
	find . -name "*.[ch]" | xargs clang-format -i
	@echo Done!

.PHONY: all clean format
