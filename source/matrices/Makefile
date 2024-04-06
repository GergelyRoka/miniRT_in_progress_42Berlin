matrix:
	cc \
	matrices_a.c matrices_b.c matrices_c.c \
	test_matrices.c \
	-o test_matrices \
	-lm -Wall -Wextra -Wall
	./test_matrices

trans:
	cc matrices_a.c matrices_b.c matrices_c.c \
	transformations_a.c \
	../tuples/tuples_a.c \
	test_transformations.c \
	-o test_transformations \
	-lm -Wall -Wextra -Wall
	./test_transformations

norminette:
	norminette matrices_a.c matrices_b.c matrices_c.c transformations_a.c

clean:
	rm test_matrices
	rm test_transformations