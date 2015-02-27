# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anouvel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 11:57:55 by anouvel           #+#    #+#              #
#    Updated: 2015/02/22 17:48:42 by anouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# 	LIBRARY OUTPUT

NAME	=	libft.a

# **************************************************************************** #
# 	SOURCES

DIRSRC	=	src/

SRC		=	$(DIRSRC)ft_memset.c \
			$(DIRSRC)ft_bzero.c \
			$(DIRSRC)ft_memcpy.c \
			$(DIRSRC)ft_memccpy.c \
			$(DIRSRC)ft_memmove.c \
			$(DIRSRC)ft_memchr.c \
			$(DIRSRC)ft_memcmp.c \
			$(DIRSRC)ft_strlen.c \
			$(DIRSRC)ft_strdup.c \
			$(DIRSRC)ft_strcpy.c \
			$(DIRSRC)ft_strncpy.c \
			$(DIRSRC)ft_strcat.c \
			$(DIRSRC)ft_strncat.c \
			$(DIRSRC)ft_strlcat.c \
			$(DIRSRC)ft_strchr.c \
			$(DIRSRC)ft_strrchr.c \
			$(DIRSRC)ft_strstr.c \
			$(DIRSRC)ft_strnstr.c \
			$(DIRSRC)ft_strcmp.c \
			$(DIRSRC)ft_strncmp.c \
			$(DIRSRC)ft_atoi.c \
			$(DIRSRC)ft_isalpha.c \
			$(DIRSRC)ft_isdigit.c \
			$(DIRSRC)ft_isalnum.c \
			$(DIRSRC)ft_isascii.c \
			$(DIRSRC)ft_isprint.c \
			$(DIRSRC)ft_tolower.c \
			$(DIRSRC)ft_toupper.c \
			$(DIRSRC)ft_memalloc.c \
			$(DIRSRC)ft_memdel.c \
			$(DIRSRC)ft_strnew.c \
			$(DIRSRC)ft_strdel.c \
			$(DIRSRC)ft_strclr.c \
			$(DIRSRC)ft_striter.c \
			$(DIRSRC)ft_striteri.c \
			$(DIRSRC)ft_strmap.c \
			$(DIRSRC)ft_strmapi.c \
			$(DIRSRC)ft_strequ.c \
			$(DIRSRC)ft_strnequ.c \
			$(DIRSRC)ft_strsub.c \
			$(DIRSRC)ft_strjoin.c \
			$(DIRSRC)ft_strtrim.c \
			$(DIRSRC)ft_strsplit.c \
			$(DIRSRC)ft_itoa.c \
			$(DIRSRC)ft_putchar.c \
			$(DIRSRC)ft_putstr.c \
			$(DIRSRC)ft_putendl.c \
			$(DIRSRC)ft_putnbr.c \
			$(DIRSRC)ft_putchar_fd.c \
			$(DIRSRC)ft_putstr_fd.c \
			$(DIRSRC)ft_putendl_fd.c \
			$(DIRSRC)ft_putnbr_fd.c \
			$(DIRSRC)ft_lstnew.c \
			$(DIRSRC)ft_lstdelone.c \
			$(DIRSRC)ft_lstdel.c \
			$(DIRSRC)ft_lstadd.c \
			$(DIRSRC)ft_lstiter.c \
			$(DIRSRC)ft_lstmap.c \
			$(DIRSRC)ft_strdel_ar.c \
			$(DIRSRC)ft_strlen_ar.c \
			$(DIRSRC)ft_strjoin_c.c \
			$(DIRSRC)ft_strjoin_ins.c \
			$(DIRSRC)ft_dexec.c \

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
LDFLAG	=	-I $(DIRINC)

# **************************************************************************** #

all		:	$(NAME)

$(NAME)	:	$(DIROBJ) $(OBJ)
	@printf " ---------------------------------------------------------------- "
	@printf "\e[36m\n=> $(NAME) - %-21s\t\t\t" "linking"
	@ar rc $(NAME) $(OBJ)
	@printf "\t\e[32m[V]\e[0m\n"
	@printf "\e[36m=> $(NAME) - %-21s\t\t\t" "indexing"
	@ranlib $(NAME)
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
	@printf " ---------------------------------------------------------------- "
	@printf "\n\e[33m=> $(NAME) - %-21s\t\t\t" "removing objects"
	@/bin/rm -rf $(DIROBJ)
	@printf "\t\e[32m[V]\e[0m\n"

fclean	: clean
	@printf "\e[33m=> $(NAME) - %-21s\t\t\t" "removing library"
	@/bin/rm -f $(NAME)
	@printf "\t\e[32m[V]\e[0m\n"

re		: fclean all
