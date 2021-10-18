# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 19:06:05 by mqueguin          #+#    #+#              #
#    Updated: 2021/10/07 12:21:55 by mqueguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	        =		so_long

NAME_B          =       so_long_bonus

SRCS            =       $(wildcard srcs/*.c)

SRCS_B      =       $(wildcard bonus/srcs/*.c)

INCLUDES_DIR     =       includes/

INCLUDES_DIR_B  =       bonus/includes/

LIB_DIR         =       libft/

LIBFT           =       libft/libft.a

CC              =       clang

OBJS            =       ${SRCS:.c=.o}

OBJS_B          =       ${SRCS_B:.c=.o}

MLX         =       minilibx/libmlx_Linux.a

MLX_DIR     =       minilibx/

RM          =       rm -rf

LFLAGS       =       -lm -lX11 -lXext -lbsd

FLAGS       =       -Wall -Wextra -Werror

.c.o:
					@${CC} ${FLAGS} -I${INCLUDES_DIR} -c $< -o $@
					@echo "\033[32m[ OK ]\033[0m ${<:.s=.o}"

all:			${NAME}

${NAME}:		${OBJS}
						@make -C ${MLX_DIR} 2>/dev/null
						@make -C ${LIB_DIR} 2>/dev/null
						@make -C ${LIB_DIR} bonus 2>/dev/null
						@${CC} ${FLAGS} ${LFLAGS} -I${INCLUDES_DIR} -o ${NAME} ${OBJS} ${LIBFT} ${MLX}
						@echo "\nlibft.a has been created"
						@echo "so_long has been created"

bonus:		${OBJS_B}
						@make -C ${MLX_DIR} 2>/dev/null
						@make -C ${LIB_DIR} 2>/dev/null
						@make -C ${LIB_DIR} bonus 2>/dev/null
						@${CC} ${FLAGS} ${LFLAGS} -I ${INCLUDES_DIR_B} -o ${NAME_B} ${OBJS_B} ${LIBFT} ${MLX}
						@echo "\nlibft.a has been created"
						@echo "so_long_bonus has been created"

clean:
						@make -C ${LIB_DIR} clean
						@${RM} ${OBJS} ${OBJS_B}
						@echo "\n *.o files deleted\n"

fclean:		clean
						@make -C ${LIB_DIR} fclean
						@${RM} ${NAME} ${NAME_B}
						@echo "\nPrograms The libft and so_long have been deleted\n"

re:		fclean all

.PHONY:           all     clean   fclean  re
