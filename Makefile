NAME		=	push_swap
SRCS_DIR	=	srcs
OBJS_DIR	=	objs
INCLUDES	=	includes
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

SRCS			=	push_swap.c \
					check_init_errors.c \
					ps_utils.c \
					operations.c

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
#.SILENT: