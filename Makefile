# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osamoile <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 16:43:13 by osamoile          #+#    #+#              #
#    Updated: 2019/06/13 16:43:14 by osamoile         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_retro
CC =	clang++
CFLAGS = -Wall -Werror -Wextra
CLASS =	Plane \
		Engine \
		Container
IFACE =	IItem
HPP =	$(addprefix include/, $(addsuffix .hpp, $(CLASS) $(IFACE)))
OBJ =	$(addprefix obj/, $(addsuffix .o, $(CLASS) main))

all: $(NAME)

obj/%.o: src/%.cpp $(HPP)
	$(CC) -c $< -o $@ $(CFLAGS) -I ./include

$(NAME): obj $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

obj:
	mkdir obj

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all
