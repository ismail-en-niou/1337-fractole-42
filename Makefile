NAME =fracts.a
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
CYAN = \033[0;36m
RESET = \033[0m

LIBFT_DIR = ./libft
PRINTF_DIR = ./printf
SRC_DIR = ./src
INCLUDE_DIR = ./includes


SW = main.c
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRC:.c=.o)

all: fract-ol

$(NAME): $(OBJS)
	@echo "$(CYAN)Creating static library: $(NAME)$(RESET)"
	@$(AR) $(NAME) $(OBJS)

fract-ol: $(NAME) $(SW)
	@echo "$(CYAN)Compiling fract-ol...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(CC) $(FLAGS) $(SW) $(NAME) libft.a printf.a -lmlx -framework OpenGL -framework AppKit -o fract-ol
	@rm *.a
	@echo "$(GREEN)Compilation successful!$(RESET)"

%.o: %.c $(INCLUDE_DIR)/ft_printf.h $(INCLUDE_DIR)/push_swap.h
	echo "$(CYAN)Compiling: $<$(RESET)"
	@$(CC) $(FLAGS) -c $< -I$(INCLUDE_DIR) -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	@echo "$(RED)Removing all compiled files...$(RESET)"
	@$(RM) $(NAME)
	@$(RM) fract-ol
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all
	@echo "$(CYAN)Rebuilding everything...$(RESET)"

.PHONY: all clean fclean re
