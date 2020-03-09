# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 08:24:04 by ancoulon          #+#    #+#              #
#    Updated: 2020/03/09 15:25:01 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ************************************************************************** ##
## Cub3D                                                                      ##
## Copyright (c) 2020 Antoine Coulon                                          ##
## ************************************************************************** ##

NAME		= Cub3D

CC			= gcc

RM			= rm -f

LFTDIR		= ./libraries/libft

MLXDIR		= ./libraries/mlx

CFLAGS		= -Wall -Wextra -Werror -I. -I./includes

LIBS		= -L$(LFTDIR) -lft -L$(MLXDIR) -lmlx -framework OpenGL             \
			  -framework AppKit -lm

SRCDIR		= ./sources

SRCS		= main.c classes/t_rgb/rgb_init.c classes/t_rgb/rgb_to_int.c       \
    	      classes/t_win/win_init.c classes/t_inst/inst_init.c              \
			  classes/t_inst/inst_close_win.c classes/t_map/map_init.c         \
			  err_exit.c

OBJS		= $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

CL_GREY		= \033[38;5;247m

CL_BLUE		= \033[38;34m

CL_RESET	= \033[0m

.c.o:
			@${CC} ${CFLAGS} -c $^ -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(CL_BLUE)-> COMPILING LIBFT$(CL_RESET)"
			@echo "$(CL_GREY)"
			@$(MAKE) -C $(LFTDIR)
			@echo "$(CL_RESET)"
			@echo "$(CL_BLUE)-> COMPILING MLX$(CL_RESET)"
			@echo "$(CL_GREY)"
			@$(MAKE) -C $(MLXDIR)
			@echo "$(CL_RESET)"
			@echo "$(CL_BLUE)-> COMPILING CUB3D$(CL_RESET)"
			@echo "$(CL_GREY)"
			$(CC) -o $(NAME) $(OBJS) $(LIBS)
			@echo "$(CL_RESET)"

clean:
			@echo "$(CL_BLUE)-> CLEAN$(CL_RESET)"
			@echo "$(CL_GREY)"
			@$(MAKE) -C $(LFTDIR) clean
			@$(MAKE) -C $(MLXDIR) clean
			$(RM) $(OBJS)
			@echo "$(CL_RESET)"

fclean:		clean
			@echo "$(CL_BLUE)-> FCLEAN$(CL_RESET)"
			@echo "$(CL_GREY)"
			@$(MAKE) -C $(LFTDIR) fclean
			$(RM) $(NAME)
			@echo "$(CL_RESET)"

re:			fclean all

.PHONY:		all clean fclean re