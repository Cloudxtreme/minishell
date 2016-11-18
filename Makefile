# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 19:11:26 by kyork             #+#    #+#              #
#    Updated: 2016/11/16 17:28:43 by kyork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

FILENAMES	+= builtins.c exec.c loop.c

OBJS		= $(addprefix build/, $(FILENAMES:.c=.o))
LIBS		= libft/libft.a

CFLAGS		+= -Wall -Wextra -Wmissing-prototypes
#CFLAGS		= -Wall -Wextra -Wfloat-equal -Wundef -Wint-to-pointer-cast -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wcast-qual -Wmissing-prototypes -Wstrict-overflow=5 -Wwrite-strings -Wconversion --pedantic-errors
CFLAGS		+= -I includes/
LDFLAGS		+= -Wall -Wextra

ifndef NO_WERROR
	CFLAGS += -Werror
	LDFLAGS += -Werror
endif

ifdef DBUG
	CFLAGS += -fsanitize=address -g
	LDFLAGS += -fsanitize=address -g
endif

ifdef RELEASE
	CFLAGS += -O2
	LDFLAGS += -O2
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) -L libft -lft
	@printf "\e[32m\e[1m[OK]\e[m $(NAME)\n"

install: $(NAME)
	cp $(NAME) $(HOME)/bin/$(NAME)

libft/libft.a:
	$(MAKE) -C libft libft.a

clean:
	rm -rf build
	$(MAKE) -C libft clean
	@printf "\e[33m\e[1m[CLEAN]\e[m $$(basename $$(pwd))\n"

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	@printf "\e[33m\e[1m[FCLEAN]\e[m $$(basename $$(pwd))\n"

re: fclean
	$(MAKE) all

build:
	mkdir -p build

build/%.o: srcs/%.c srcs/*.h | build
	$(CC) $(CFLAGS) -c -o $@ $<
