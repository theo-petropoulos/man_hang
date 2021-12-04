SRC-MAIN = main.c header.h
SRC-MAIN-ARG = main.c
OUT-MAIN = main.o
FLAGS = -Wall -Wextra
EXEC = man_hang
METHOD-OUT = gcc $(OUT-MAIN) -o $(EXEC)
METHOD-SRC-MAIN = gcc -c -g $(SRC-MAIN-ARG) $(FLAGS) -o $(OUT-MAIN)

$(EXEC): $(OUT-MAIN)
	$(METHOD-OUT)

$(OUT-MAIN): $(SRC-MAIN)
	$(METHOD-SRC-MAIN)

clean:
	rm -rf *.o

fclean:
	make clean
	rm -rf $(EXEC)
