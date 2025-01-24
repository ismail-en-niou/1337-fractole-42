NAME = fract-ol
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

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
SW_bonus = main_bonus.c
SRC = $(filter-out $(SRC_DIR)/handelers_bonus.c, $(wildcard $(SRC_DIR)/*.c))
BONUS_SRC = $(filter-out $(SRC_DIR)/handelers.c, $(wildcard $(SRC_DIR)/*.c))
OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(SW)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(CC) $(FLAGS) $(SW) $(OBJS) libft.a printf.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)Compilation successful!$(RESET)"

bonus: $(BONUS_OBJS) $(SW_bonus)
	@echo "$(CYAN)Compiling bonus target...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(CC) $(FLAGS) $(SW_bonus) $(BONUS_OBJS) libft.a printf.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)Bonus compilation successful!$(RESET)"

%.o: %.c $(INCLUDE_DIR)/fract_ol.h
	@$(CC) $(FLAGS) -c $< -I$(INCLUDE_DIR) -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	@echo "$(RED)Removing all compiled files...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all
	@echo "$(CYAN)Rebuilding everything...$(RESET)"

.PHONY: all clean fclean re bonus
