
CC = cc 
CFLAGS= -Wall -Wextra -Werror
CFILES= main.c \
		new_atoi.c \
		finding.c \
		rules.c \
		rules_two.c \
		move.c \
		tooles.c \
		sort.c

BCFILES=checker_bonus.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		new_atoi_bonus.c \
		rules_bonus.c \
		rules_two_bonus.c \
		create_s_bonus.c \

BOFILES=$(BCFILES:.c=.o) 
OFILES=$(CFILES:.c=.o)
NAME=push_swap 
BNAME=checker
LIBNAME=libft/libft.a ft_printf/libftprintf.a

all: $(NAME) 

$(NAME): $(OFILES) libs
	@$(CC) $(CFLAGS) $(OFILES) $(LIBNAME) -o $(NAME)

%.o:%.c push_swap.h checker_bonus.h
	$(CC) $(CFLAGS) -c $<

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