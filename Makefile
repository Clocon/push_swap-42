# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 13:19:05 by lumorale          #+#    #+#              #
#    Updated: 2023/03/30 13:34:49 by lumorale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
LIBFT			=	./libft/libft.a
PRINTF			=	./ft_printf/libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f
AR				=	ar -rcs

SRCS			=	src/main.c \
					src/args_checker.c \
					src/move_arr.c \
					src/swap.c \
					src/push.c \
					src/rotate.c \
					src/reverse_rotate.c \
					src/radix.c \
					src/few_arguments.c \
					src/game.c \
					src/utils.c \
					

#		COLORS		#
CYELLOW			=\033[1;33m
CGREEN			=\033[0;32m
CRED			=\033[0;91m
CRESET			=\033[0m

OBJS			=	$(SRCS:.c=.o)

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME) $(LIBFT) $(PRINTF)

$(LIBFT):
				@make -C ./libft

$(PRINTF):
				@make -C ./ft_printf

$(NAME):		$(LIBFT) $(OBJS) | $(PRINTF) $(OBJS)
				@$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(OBJS)   -o $(NAME)
				@echo "\n$(CYELLOW)$(NAME) -> $(CGREEN) compiled$(CRESET)"

clean:
				@$(RM) $(OBJS)  
				@make -C ./libft clean
				@make -C ./ft_printf clean
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} objects files were deleted.${CRESET}"

fclean:			clean
				@$(RM) $(NAME)
				@make -C ./libft fclean
				@make -C ./ft_printf fclean
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} was deleted.${CRESET}"

re:				fclean all

.PHONY:			all clean fclean re