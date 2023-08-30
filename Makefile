# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 09:55:41 by arepsa            #+#    #+#              #
#    Updated: 2023/08/29 09:39:19 by arepsa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRCS_DIR	=	srcs
OBJS_DIR	=	objs
INCLUDES	=	includes
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

SRCS			=	push_swap.c \
					check_init_errors.c \
					operations1.c \
					operations2.c \
					atol.c \
					list_utils1.c \
					list_utils2.c \
					small_sort.c \
					big_sort.c

CC			= cc
LIBFLAGS	= ar -rcs
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror -g 

OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	echo "Done compiling $(NAME)!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	echo "Creating .o files..."
	mkdir -p $(@D)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

$(LIBFT):
	echo "Making libft..."
	$(MAKE) -C $(LIBFT_DIR)
	
clean:
	$(RM) $(OBJS_DIR) 
	echo "Deleted $(NAME) $(OBJS_DIR)"
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	echo "Deleted $(NAME) files and $(LIBFT)"
	
re: fclean all

.PHONY: all clean fclean re
.SILENT: