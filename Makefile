
CC = cc 
CFLAGS= -Wall -Wextra -Werror
CFILES = $(wildcard src/*.c)

BCFILES = $(wildcard src_bonus/*.c)

BOFILES=$(BCFILES:.c=.o) 
OFILES=$(CFILES:.c=.o)
NAME=push_swap 
BNAME=checker
LIBNAME=libft/libft.a ft_printf/libftprintf.a

all: $(NAME) 

$(NAME): $(OFILES) libs
	@$(CC) $(CFLAGS) $(OFILES) $(LIBNAME) -o $(NAME)

%.o:%.c src/push_swap.h src_bonus/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

libs:
	@cd libft && make && make bonus
	@cd ft_printf && make

bonus: $(BOFILES) libs
	@$(CC) $(CFLAGS) $(BOFILES) $(LIBNAME) -o $(BNAME)


clean:
	@rm -f $(OFILES) $(BOFILES)
	@cd libft && make clean
	@cd ft_printf && make clean

fclean: clean
	@rm -f $(NAME) $(BNAME)
	@cd libft && make fclean
	@cd ft_printf && make fclean 

re: fclean all

.PHONY: clean libs
