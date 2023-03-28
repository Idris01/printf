all:
	gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
run:
	./a.out
clean:
	rm a.out
