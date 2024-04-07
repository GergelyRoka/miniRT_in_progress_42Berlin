# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groka <groka@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 13:00:31 by groka             #+#    #+#              #
#    Updated: 2024/04/07 17:31:06 by groka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ls *.c | tr ' ' '\n' | xclip -sel clip
# ls */*.c | tr ' ' '\n' | xclip -sel clip


NAME	:= miniRT
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

CC		:= cc

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a
SRCS	:=	source/main.c \
			source/tuples/tuples_a.c \
			source/tuples/tuples_b.c \
			source/tuples/tuples_c.c \
			source/colors/colors_a.c \
			source/colors/colors_b.c \
			source/canvas/canvas.c \
			source/matrices/matrices_a.c \
			source/matrices/matrices_b.c \
			source/matrices/matrices_c.c \
			source/matrices/transformations_a.c \
			source/matrices/transformations_b.c \

OBJS	:= ${SRCS:.c=.o}
DEPS	:=	./include/minirt.h \
			./include/tuples.h \
			./include/colors.h \
			./include/canvas.h \
			./include/matrices.h \

%.o: %.c $(DEPS) #-fsanitize=address -g
	@$(CC) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)


$(NAME): $(OBJS)  #-fsanitize=address -static-libsan
	@$(CC)  $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: clean all

.PHONY: all, clean, fclean, re, libmlx