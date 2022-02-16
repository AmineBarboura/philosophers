# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarbour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 21:36:36 by abarbour          #+#    #+#              #
#    Updated: 2022/02/17 00:25:14 by abarbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror -fsanitize=thread

NAME = philo

SRCS =	philo.c \
		philo_routine.c \
		philo_actions.c \
		philo_tools.c \
		philo_dr_protection.c \
		tools.c \
		ft_putnbr.c

OBJECT = $(SRCS:.c=.o)

.c.o :
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): ${OBJECT}
	$(CC) $(FLAGS) -pthread -o $(NAME) ${OBJECT}

all: $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean : clean 
	@rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean all bonus
