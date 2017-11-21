#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 22:19:25 by jbulant           #+#    #+#              #
#    Updated: 2017/11/21 02:46:35 by jbulant          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

LIBFT = libft.a

SRCS = main.c reader.c pieces_mgr.c erroc.c displaytab.c backtrack.c

OBJ = $(SRC=.c:.o)

INCLUDEPATH = libft/

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCLUDEPATH) $(INCLUDEPATH)$(LIBFT) $(SRCS) -o $(NAME)

$(LIBFT):
	@cd libft && make

clean:
	@cd libft && make clean

fclean:
	@cd libft && make fclean
	@rm -f $(NAME)

re: fclean all
