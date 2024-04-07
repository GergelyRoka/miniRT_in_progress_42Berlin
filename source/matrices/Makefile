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
	transformations_b.c \
	../tuples/tuples_a.c \
	test_transformations.c \
	-o test_transformations \
	-lm -Wall -Wextra -Wall
	./test_transformations

clock:
	cc \
	matrices_a.c matrices_b.c matrices_c.c \
	transformations_a.c transformations_b.c \
	../tuples/tuples_a.c ../tuples/tuples_b.c \
	../canvas/canvas.c ../canvas/canvas_to_ppm.c \
	test_clock.c \
	-o test_clock \
	-lm -Wall -Wextra -Wall
	./test_clock

norminette:
	norminette matrices_a.c matrices_b.c matrices_c.c transformations_a.c transformations_b.c

clean:
	rm test_matrices
	rm test_transformations
	rm test_clock