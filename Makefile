# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarbour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 18:04:51 by abarbour          #+#    #+#              #
#    Updated: 2022/01/09 19:40:14 by abarbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror 

NAME = philo

SRCS =	philo.c\
		tools.c

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
