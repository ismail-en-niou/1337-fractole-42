NAME = printf.a
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
CYAN = \033[0;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CYAN)Creating static library: $(NAME) ... $(RESET)"
	@ar rc $(NAME) $(OBJ)
	@mv $(NAME) ../

%.o: %.c ../includes/ft_printf.h
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning the work space ... $(RESET)"
	@rm -rf *.o $(BONUS_FLAG)

fclean: clean
	@echo "$(RED)Removing all ... T_T $(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
