
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RED = \033[0;31m
RESET = \033[0m

CC = cc 
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC =	ft_printf.c \
		ft_putchar.c \
		ft_puthex.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_putnbr.c \
		ft_putaddress.c \
		ft_uputnbr.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@echo "$(GREEN)[Compiling]$(RESET) Creating $(NAME)..."
	@ar rc $(NAME) $(OBJ)
	@echo "$(BLUE)[Success]$(RESET) $(NAME) built!"

	
%.o:%.c ft_printf.h
	@echo "$(YELLOW)[Compiling]$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)[Cleaning]$(RESET) Object files..."
	@rm -f $(OBJ)
	@echo "$(BLUE)[Done]$(RESET) Object files removed."

fclean: clean
	@echo "$(RED)[Cleaning]$(RESET) Executables..."
	@rm -f $(NAME)
	@echo "$(BLUE)[Done]$(RESET) All cleaned."

re : fclean all

.PHONY: re fclean clean all 
