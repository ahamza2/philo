# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 18:45:30 by haarab            #+#    #+#              #
#    Updated: 2023/05/21 17:36:29 by haarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -f

src = philo.c

OBJS = philo.o

all: $(NAME)


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all