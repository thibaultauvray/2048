# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anouvel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 11:57:55 by anouvel           #+#    #+#              #
#    Updated: 2015/02/28 16:26:52 by anouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# 	LIBRARY OUTPUT

NAME	=	game_2048

# **************************************************************************** #
# 	SOURCES

DIRSRC	=	src/

SRCALG	=	$(DIRSRC)algo/
SRCTLS	=	$(DIRSRC)tools/

SRC		=	$(DIRSRC)main.c \
			$(DIRSRC)ft_init.c \
			$(SRCALG)ft_add_value.c \
			$(SRCALG)ft_movement.c \
			$(SRCALG)ft_left.c \
			$(SRCALG)ft_right.c \
			$(SRCALG)ft_up.c \
			$(SRCALG)ft_down.c \
			$(SRCTLS)ft_array_tools.c \

# **************************************************************************** #
# 	DIRECTORIES

DIROBJ	=	.obj
DIRLST	= 	src
DIRINC	=	./includes

# **************************************************************************** #
# 	COMPILATION

CC		=	gcc
OBJ		=	$(addprefix $(DIROBJ)/, $(SRC:.c=.o))
LCFLAG	=	-Wall -Wextra -Werror -Os
LDFLAG	=	-I $(DIRINC) -I libft/includes/
LIBS	=	-L libft -lft

# **************************************************************************** #

all		:	libft $(NAME)

libft:
	@$(MAKE) -C libft

$(NAME)	:	$(DIROBJ) $(OBJ)
	@printf " ---------------------------------------------------------------- "
	@printf "\e[36m\n=> $(NAME) - %-21s\t\t\t" "linking"
	@$(CC) $(LCFLAG) $(LDFLAG) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\t\e[32m[V]\e[0m\n"
	@printf " ---------------------------------------------------------------- "
	@printf "\n\e[32m=> $(NAME) - %-21s\n\e[0m" "COMPLETED"
	@printf " ---------------------------------------------------------------- "
	@printf "\n"

$(addprefix $(DIROBJ)/, %.o) : %.c
	@mkdir -p $(@D)
	@printf "=> $(NAME) - %-10s %-37s" "$(CC)" "$@"
	@$(CC) $(LCFLAG) $(LDFLAG) -o $@ -c $<
	@printf "\t\e[32m[V]\e[0m\n"

$(DIROBJ) :
	@printf "\e[33m=> $(NAME) - %-21s\t\t\t" "making sub-dirs"
	@/bin/mkdir $(DIROBJ); \
		for DIR in $(DIRLST); \
		do \
		/bin/mkdir $(DIROBJ)/$$DIR; \
		done
	@printf "\t\e[32m[V]\e[0m\n"
	@printf " ---------------------------------------------------------------- "
	@printf "\e[36m\n=> $(NAME) - building\n\e[0m"

clean	:
	@$(MAKE) -C libft $@
	@printf " ---------------------------------------------------------------- "
	@printf "\n\e[33m=> $(NAME) - %-21s\t\t\t" "removing objects"
	@/bin/rm -rf $(DIROBJ)
	@printf "\t\e[32m[V]\e[0m\n"

fclean	: clean
	@$(MAKE) -C libft $@
	@printf "\e[33m=> $(NAME) - %-21s\t\t\t" "removing executable"
	@/bin/rm -f $(NAME)
	@printf "\t\e[32m[V]\e[0m\n"

re		: fclean all
	
.PHONY:	clean fclean re libft all
