all:
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
run:
	./a.out
clean:
	rm a.out
