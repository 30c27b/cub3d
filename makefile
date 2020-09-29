# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 08:24:04 by ancoulon          #+#    #+#              #
#    Updated: 2020/09/29 14:18:48 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ************************************************************************** ##
##                                                                            ##
##                                             ______      __   _____ ____    ##
##                                            / ____/_  __/ /_ |__  // __ \   ##
##                                           / /   / / / / __ \ /_ </ / / /   ##
##                                          / /___/ /_/ / /_/ /__/ / /_/ /    ##
## Cub3D                                    \____/\__,_/_.___/____/_____/     ##
## 2020 Antoine Coulon @ s19                                                  ##
## ************************************************************************** ##

NAME		= Cub3D

CC			= gcc

RM			= rm -f

MAKE		= make -j$(nproc)

LFTDIR		= ./libraries/libft

MLXDIR		= ./libraries/mlx

MLX			= libmlx.dylib

CFLAGS		= -Wall -Wextra -Werror -I. -I./includes

LIBS		= -L$(LFTDIR) -lft -L. -lmlx -framework OpenGL             \
			  -framework AppKit -lm

SRCDIR		= ./sources

SRCS		= $(wildcard sources/*.c)                                          \
			  $(wildcard sources/*/*.c)                                        \
			  $(wildcard sources/*/*/*.c)

OBJS		= $(SRCS:.c=.o)

CL_GREY		= \033[38;2;128;128;128m

CL_GREEN	= \033[38;2;0;153;0m

CL_RESET	= \033[0m

.c.o:
			@${CC} ${CFLAGS} -c $^ -o $@

# $(MLX):
# 			make -C $(MLXDIR)
# 			mv $(MLXDIR)/$(MLX) .

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(CL_GREEN)-> COMPILING LIBFT$(CL_RESET)"
			@echo "$(CL_GREY)"
			@$(MAKE) -C $(LFTDIR)
			@echo "$(CL_RESET)"
			@echo "$(CL_GREEN)-> COMPILING MLX$(CL_RESET)"
			@echo "$(CL_GREY)"
			@make -C $(MLXDIR)
			@mv $(MLXDIR)/$(MLX) .
			@echo "$(CL_RESET)"
			@echo "$(CL_GREEN)-> COMPILING CUB3D$(CL_RESET)"
			@echo "$(CL_GREY)"
			$(CC) -o $(NAME) $(OBJS) $(LIBS)
			@echo "$(CL_RESET)"

clean:
			@echo "$(CL_GREEN)-> CLEAN$(CL_RESET)"
			@echo "$(CL_GREY)"
			@$(MAKE) -C $(LFTDIR) clean
			@$(MAKE) -C $(MLXDIR) clean
			$(RM) $(OBJS)
			@echo "$(CL_RESET)"

fclean:		clean
			@echo "$(CL_GREEN)-> FCLEAN$(CL_RESET)"
			@echo "$(CL_GREY)"
			@$(MAKE) -C $(LFTDIR) fclean
			$(RM) $(NAME)
			$(RM) $(MLX)
			@echo "$(CL_RESET)"

re:			fclean all

mclean:		all clean

.PHONY:		all clean fclean re
