# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealves <ealves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 15:58:52 by ealves            #+#    #+#              #
#    Updated: 2023/08/10 23:02:42 by ealves           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

# NAME_BONUS		=	pipex_bonus

LIBFT			=	includes/libft/libft.a

PRINTF			=	includes/ft_printf/libftprintf.a

GNL				=	includes/get_next_line/get_next_line.c includes/get_next_line/get_next_line_utils.c

SRCS			=	main.c child.c \
					fork.c error.c\
					utils.c

# SRCS_BONUS 		=	bonus/main_bonus.c bonus/child_bonus.c \
# 					bonus/close_bonus.c bonus/fork_bonus.c \
# 					bonus/utils_bonus.c

OBJS			=	${SRCS:.c=.o}

# OBJS_BONUS		= 	${SRCS_BONUS:.c=.o}

HEAD			=	-Iincludes

CFLAGS			=	-Wall -Werror -Wextra -D BENCH=0 -g

all				:	${NAME}

.c.o	:
		@cc  ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	make --no-print-directory -C includes/libft
	make --no-print-directory -C includes/ft_printf
	cc $(OBJS) ${LIBFT} ${PRINTF} -o $(NAME)


# $(NAME_BONUS) : $(OBJS_BONUS)
# 	make --no-print-directory -C includes/libft
# 	make --no-print-directory -C includes/ft_printf
# 	cc $(OBJS_BONUS) ${GNL} ${LIBFT} ${PRINTF} -o $(NAME_BONUS)

# bonus: ${NAME_BONUS}

clean			:
					make clean -C includes/libft/
					make clean -C includes/ft_printf/
					rm -rf ${OBJS}
					# rm -rf ${OBJS_BONUS}

fclean			:	clean
					make fclean -C includes/libft/
					make fclean -C includes/ft_printf/
					rm -rf ${LIBFT}
					rm -rf ${PRINTF}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
