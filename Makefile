# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 18:45:30 by haarab            #+#    #+#              #
#    Updated: 2023/06/20 15:08:17 by haarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -f

src = philo.c libft.c ft_time.c check_dead.c routine_thread.c ft_print.c threads.c

OBJS = philo.o libft.o ft_time.o check_dead.o routine_thread.o ft_print.o threads.o

all: $(NAME)


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all