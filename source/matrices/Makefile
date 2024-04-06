all:
	cc matrices_a.c matrices_b.c matrices_c.c test_matrices.c -o test -lm -Wall -Wextra -Wall
	./test

norminette:
	norminette matrices_a.c matrices_b.c matrices_c.c

clean:
	rm test