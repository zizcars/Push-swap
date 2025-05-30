# === Colors ===
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RED = \033[0;31m
RESET = \033[0m

# === Compiler and Flags ===
CC = cc
CFLAGS = -Wall -Wextra -Werror

# === Files ===
CFILES = $(wildcard src/*.c)
BCFILES = $(wildcard src_bonus/*.c)
OFILES = $(CFILES:.c=.o)
BOFILES = $(BCFILES:.c=.o)

# === Executables and Libraries ===
NAME = push_swap
BNAME = checker
LIBNAME = libft/libft.a ft_printf/libftprintf.a

# === Rules ===
all: $(NAME)

$(NAME): $(OFILES) libs
	@echo "$(GREEN)[Compiling]$(RESET) Creating $(NAME)..."
	@$(CC) $(CFLAGS) $(OFILES) $(LIBNAME) -o $(NAME)
	@echo "$(BLUE)[Success]$(RESET) $(NAME) built!"

%.o: %.c src/push_swap.h src_bonus/checker_bonus.h
	@echo "$(YELLOW)[Compiling]$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

libs:
	@echo "$(GREEN)[Building]$(RESET) Libraries..."
	@cd libft && make && make bonus
	@cd ft_printf && make
	@echo "$(BLUE)[Done]$(RESET) Libraries ready."

bonus: $(BOFILES) libs
	@echo "$(GREEN)[Compiling]$(RESET) Creating bonus: $(BNAME)..."
	@$(CC) $(CFLAGS) $(BOFILES) $(LIBNAME) -o $(BNAME)
	@echo "$(BLUE)[Success]$(RESET) $(BNAME) built!"

clean:
	@echo "$(RED)[Cleaning]$(RESET) Object files..."
	@rm -f $(OFILES) $(BOFILES)
	@cd libft && make clean
	@cd ft_printf && make clean
	@echo "$(BLUE)[Done]$(RESET) Object files removed."

fclean: clean
	@echo "$(RED)[Cleaning]$(RESET) Executables..."
	@rm -f $(NAME) $(BNAME)
	@cd libft && make fclean
	@cd ft_printf && make fclean
	@echo "$(BLUE)[Done]$(RESET) All cleaned."

re: fclean all

.PHONY: all bonus clean fclean re libs
