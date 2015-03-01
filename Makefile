# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anouvel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 11:57:55 by anouvel           #+#    #+#              #
#    Updated: 2015/03/01 16:23:54 by anouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# 	LIBRARY OUTPUT

NAME	=	game_2048

# **************************************************************************** #
# 	SOURCES

DIRSRC	=	src/

SRCALG	=	$(DIRSRC)algo/
SRCMOV	=	$(SRCALG)movements/
SRCPRT	=	$(DIRSRC)print/
SRCTLS	=	$(DIRSRC)tools/

SRC		=	$(DIRSRC)ft_game.c \
			$(SRCALG)ft_a_add_value.c \
			$(SRCALG)ft_a_blocked.c \
			$(SRCMOV)ft_m_select.c \
			$(SRCMOV)ft_m_max.c \
			$(SRCMOV)ft_m_move_left.c \
			$(SRCMOV)ft_m_move_right.c \
			$(SRCMOV)ft_m_move_down.c \
			$(SRCMOV)ft_m_move_up.c \
			$(SRCMOV)ft_m_push_left.c \
			$(SRCMOV)ft_m_push_right.c \
			$(SRCMOV)ft_m_push_down.c \
			$(SRCMOV)ft_m_push_up.c \
			$(SRCPRT)ft_p_print.c \
			$(SRCPRT)ft_p_error.c \
			$(SRCTLS)ft_t_array_tools.c \

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
LIBS	=	-L libft -lft -lncurses

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
