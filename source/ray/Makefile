ray:
	cc \
	ray.c test_ray.c intersect_sphere.c \
	../tuples/tuples_a.c ../tuples/tuples_b.c ../tuples/tuples_c.c \
	-o test_ray \
	-lm -Wall -Wextra -Wall
	./test_ray

norminette:
	norminette ray.c

clean:
	rm test_ray