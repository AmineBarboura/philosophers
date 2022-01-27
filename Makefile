# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarbour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 21:36:36 by abarbour          #+#    #+#              #
#    Updated: 2022/01/27 23:24:45 by abarbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror 

NAME = philo

SRCS =	philo.c \
		philo_routine.c \
		tools.c \
		ft_itoa.c \
		philo_tools.c 

OBJECT = $(SRCS:.c=.o)

.c.o :
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): ${OBJECT}
	$(CC) $(FLAGS) -o $(NAME) ${OBJECT}

all: $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean : clean 
	@rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean all bonus
