# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 08:24:04 by ancoulon          #+#    #+#              #
#    Updated: 2021/01/12 20:03:11 by ancoulon         ###   ########.fr        #
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

CC			= clang

RM			= rm -f

MAKE		= make

LFTDIR		= ./libraries/libft

MLXDIR		= ./libraries/mlx

MLX			= libmlx.dylib

CFLAGS		= -Wall -Wextra -Werror -I. -I./includes

LIBS		= -lm -L$(LFTDIR) -lft -L. -lmlx \
			  -framework AppKit -framework OpenGL

SRCDIR		= ./sources

SRCS		= \
			sources/classes/t_display/display_free.c \
			sources/classes/t_display/display_init.c \
			sources/classes/t_file/file_free.c \
			sources/classes/t_file/file_init.c \
			sources/classes/t_frame/frame_draw_sprites.c \
			sources/classes/t_frame/frame_free.c \
			sources/classes/t_frame/frame_init.c \
			sources/classes/t_frame/frame_push.c \
			sources/classes/t_frame/frame_put_pixel.c \
			sources/classes/t_frame/frame_render.c \
			sources/classes/t_frame/frame_save.c \
			sources/classes/t_fvect/fvect_add.c \
			sources/classes/t_fvect/fvect_addv.c \
			sources/classes/t_fvect/fvect_addx.c \
			sources/classes/t_fvect/fvect_addy.c \
			sources/classes/t_fvect/fvect_init.c \
			sources/classes/t_fvect/fvect_mult.c \
			sources/classes/t_fvect/fvect_multv.c \
			sources/classes/t_game/game_free.c \
			sources/classes/t_game/game_init.c \
			sources/classes/t_game/game_start.c \
			sources/classes/t_map/map_enclosing.c \
			sources/classes/t_map/map_free.c \
			sources/classes/t_map/map_init.c \
			sources/classes/t_map/map_isfloor.c \
			sources/classes/t_map/map_parse_content.c \
			sources/classes/t_map/map_parse_meta.c \
			sources/classes/t_map/map_parsers1.c \
			sources/classes/t_map/map_parsers2.c \
			sources/classes/t_map/map_process_tex.c \
			sources/classes/t_ray/ray_dda.c \
			sources/classes/t_ray/ray_draw.c \
			sources/classes/t_ray/ray_free.c \
			sources/classes/t_ray/ray_init.c \
			sources/classes/t_rgb/rgb_from_int.c \
			sources/classes/t_rgb/rgb_init.c \
			sources/classes/t_rgb/rgb_to_int.c \
			sources/classes/t_sprite/sprite_free.c \
			sources/classes/t_sprite/sprite_init.c \
			sources/classes/t_texture/texture_free.c \
			sources/classes/t_texture/texture_get_pixel.c \
			sources/classes/t_texture/texture_init.c \
			sources/classes/t_texture/texture_process.c \
			sources/classes/t_vect/vect_add.c \
			sources/classes/t_vect/vect_addv.c \
			sources/classes/t_vect/vect_fromf.c \
			sources/classes/t_vect/vect_init.c \
			sources/classes/t_vect/vect_mult.c \
			sources/classes/t_vect/vect_multv.c \
			sources/classes/t_view/view_free.c \
			sources/classes/t_view/view_init.c \
			sources/handlers/err_exit.c \
			sources/handlers/hooks/hook_exit.c \
			sources/handlers/hooks/hook_keypress.c \
			sources/handlers/hooks/hook_keyrelease.c \
			sources/handlers/hooks/hook_loop.c \
			sources/main.c


OBJS		= $(SRCS:.c=.o)

CL_GREY		= \033[38;2;128;128;128m

CL_GREEN	= \033[38;2;0;153;0m

CL_RESET	= \033[0m

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
			$(CC) ${CFLAGS} -o $(NAME) $(OBJS) $(LIBS)
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

norm:
			@echo "$(CL_GREY)"
			@$(NORMINETTE) $(SRCS)
			@echo "$(CL_RESET)"

.PHONY:		all clean fclean re
